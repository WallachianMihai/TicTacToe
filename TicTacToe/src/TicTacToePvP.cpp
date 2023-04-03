#include "TicTacToePvP.h"
#include <algorithm>
#include <iostream>

namespace TicTacToe
{
    TicTacToePvP::TicTacToePvP(const IPlayerPtr& playerX,
                               const IPlayerPtr& playerZero,
                               const EGameDifficulty difficulty)
        : m_listeners{}
        , m_players{ playerX, playerZero }
        , m_state { EGameState::Ongoing }
        , m_round{ 0 }
        , m_board{}
    {
        m_strategy = ITicTacToeStrategy::MakeStrategy(difficulty);
    }

    void TicTacToePvP::AddListener(ITicTacToeListenerPtr listener)
    {
        m_listeners.emplace_back(listener);
    }

    void TicTacToePvP::RemoveListener(ITicTacToeListener *listener)
    {
       for (auto it = m_listeners.begin(); it != m_listeners.end(); )
       {
           if (auto ptr = it->lock())
           {
               if (ptr.get() == listener)
                   it = m_listeners.erase(it);
               else
                   ++it;
           }
           else
               it = m_listeners.erase(it);
       }
    }

    void TicTacToePvP::CheckState()
    {
        for (uint8_t i = 0; i < m_board.GetSize(); ++i)
        {
            if (m_board(i, 0) ==
                m_board(i, 1) &&
                m_board(i, 1) ==
                m_board(i, 2) &&
                m_board(i, 0) != ECellType::EMPTY)
            {
                if(m_board(i, 0) == ECellType::X)
                {
                    m_state = EGameState::FirstPlayerWon;
                    return;
                }
                else
                {
                    m_state = EGameState::SecondPlayerWon;
                    return;
                }

            }

            if (m_board(0, i) ==
                m_board(1, i) &&
                m_board(1, i) ==
                m_board(2, i) &&
                m_board(0, i) != ECellType::EMPTY)
            {
                if(m_board(0, i) == ECellType::X)
                {

                    m_state = EGameState::FirstPlayerWon;
                    return;
                }
                else
                {
                    m_state = EGameState::SecondPlayerWon;
                    return;
                }
            }
        }

        if(m_board[0] ==
           m_board[m_board.GetSize() + 1] &&
           m_board[m_board.GetSize() + 1] ==
           m_board[m_board.GetSize() * m_board.GetSize() - 1] &&
           m_board[0] != ECellType::EMPTY)
        {
            if(m_board[0] == ECellType::X)
            {
                m_state = EGameState::FirstPlayerWon;
                return;
            }
            else
            {
                m_state = EGameState::SecondPlayerWon;
                return;
            }
        }

        if(m_board[m_board.GetSize() - 1] ==
           m_board[m_board.GetSize() + 1] &&
           m_board[m_board.GetSize() + 1] ==
           m_board[m_board.GetSize() + 3] &&
           m_board[m_board.GetSize() + 3] != ECellType::EMPTY)
        {
            if(m_board[m_board.GetSize() - 1] == ECellType::X)
            {
                m_state = EGameState::FirstPlayerWon;
                return;
            }
            else
            {
                m_state = EGameState::SecondPlayerWon;
                return;
            }
        }

        if(m_board.IsFull())
        {
            m_state = EGameState::Tie;
            return;
        }
    }

    bool TicTacToePvP::MakeMove(const uint8_t i, const uint8_t j)
    {
        if(!m_strategy)
        {
            if(m_state == EGameState::Ongoing)
                return Move(i, j);
        }
        else
        {
            if(m_state == EGameState::Ongoing)
            {
                MakeMovePvM(i, j);
                return MakeMovePvM(i, j);
            }
        }
        return false;
    }

    bool TicTacToePvP::Move(const uint8_t i, const uint8_t j)
    {
        if (i >= m_board.GetSize() ||
            j >= m_board.GetSize() ||
            GetValue(i, j) != ECellType::EMPTY)
        {
            return false;
        }

        if (m_round % 2 == 0)
        {
            m_board.Sketch(i * m_board.GetSize() + j, ECellType::X);
            CheckState();

            for (const auto& listener : m_listeners)
            {
                if (auto ptr = listener.lock())
                {
                    ptr->OnMove(this, i, j);
                }
            }

            if (GetState() != EGameState::Ongoing)
            {
                for (const auto& listener : m_listeners)
                {
                    if (auto ptr = listener.lock())
                    {
                        ptr->OnFinish(this, i, j);
                    }
                }
            }
            ++m_round;
            return true;
        }
        else
        {
            m_board.Sketch(i * m_board.GetSize() + j, ECellType::ZERO);
            CheckState();

            for (const auto& listener : m_listeners)
            {
                if (auto ptr = listener.lock())
                {
                    ptr->OnMove(this, i, j);
                }
            }

            if (GetState() != EGameState::Ongoing)
            {
                for (const auto& listener : m_listeners)
                {
                    if (auto ptr = listener.lock())
                    {
                        ptr->OnFinish(this, i, j);
                    }
                }
            }

            ++m_round;
            return true;
        }
    }

    bool TicTacToePvP::MakeMovePvM(const uint8_t i, const uint8_t j)
    {
        if(m_players.first.lock())
        {
            if(m_state == EGameState::Ongoing)
            {
                if (m_round % 2 == 0)
                {
                    const auto [k, l] = m_strategy->Move(m_board,
                                                         ECellType::X); // k and l together is the position where the machine decided to move
                    Move(k, l);
                }
                else
                {
                    Move(i, j);
                }
            }
        }
        else
        {
            if(m_state == EGameState::Ongoing)
            {
                if (m_round % 2 == 0)
                {
                    Move(i, j);
                } else
                {
                    const auto [k, l] = m_strategy->Move(m_board,
                                                         ECellType::ZERO); // k and l together is the position where the machine decided to move
                    Move(k, l);
                }
            }
        }
    }

    void TicTacToePvP::PrintBoard() const
    {
        std::cout << m_board;
    }

    EGameState TicTacToePvP::GetState() const
    {
        return m_state;
    }

    ECellType TicTacToePvP::GetValue(const uint8_t i, const uint8_t j) const
    {
        return m_board(i, j);
    }

    IPlayer* TicTacToePvP::GetCurrentPlayer() const
    {
        return m_round % 2 == 0 ? m_players.first.lock().get() : m_players.second.lock().get();
    }

    void TicTacToePvP::SetDificulty(EGameDifficulty difficulty)
    {
        m_strategy = ITicTacToeStrategy::MakeStrategy(difficulty);
    }

    uint8_t TicTacToePvP::GetBoardSize() const
    {
        return m_board.GetSize();
    }

} // namespace TicTacToe