#ifndef PROIECT1_TICTACTOEPVP_H
#define PROIECT1_TICTACTOEPVP_H

#include <ITicTacToe.h>
#include <IPlayer.h>
#include <Board.h>
#include <vector>

namespace TicTacToe
{
    class TicTacToePvP : public ITicTacToe
    {
    public:
        explicit TicTacToePvP(const IPlayerPtr& playerX = nullptr, const IPlayerPtr& playerZero = nullptr);

        void AddListener(ITicTacToeListenerPtr listener) override;
        void RemoveListener(ITicTacToeListener* listener) override;

        void CheckState();

        void PrintBoard() const;

        uint8_t GetBoardSize() const override;

        EGameState GetState() const override;

        ECellType GetValue(const uint8_t i, const uint8_t j) const override;

        IPlayer* GetCurrentPlayer() const override;

        bool MakeMove(const uint8_t i, const uint8_t j) override;

        void Reset() override;

    private:
        std::vector<ITicTacToeListenerWeakPtr> m_listeners;
        std::pair<IPlayerWeakPtr, IPlayerWeakPtr> m_players;
        EGameState m_state;
        uint8_t m_round;
        Board m_board;

    };
} //namespace TicTacToe

#endif //PROIECT1_TICTACTOEPVP_H
