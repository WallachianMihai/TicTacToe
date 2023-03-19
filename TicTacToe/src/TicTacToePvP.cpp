#include "TicTacToePvP.h"
#include <algorithm>
#include <iostream>

namespace TicTacToe
{
    TicTacToePvP::TicTacToePvP(const IPlayerPtr& playerX, const IPlayerPtr& playerZero)
        : m_listeners{}
        , m_players{ playerX, playerZero }
        , m_state { EGameState::Ongoing }
        , m_round{ 0 }
        , m_board{}
    {
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

    uint8_t TicTacToePvP::GetBoardSize() const
    {
        return m_board.GetSize();
    }

} // namespace TicTacToe