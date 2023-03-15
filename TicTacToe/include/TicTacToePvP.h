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
        TicTacToePvP(IPlayer* playerX, IPlayer* playerZero);

        void AddListener(ITicTacToeListener* listener) override;
        void RemoveListener(ITicTacToeListener* listener) override;

        void CheckState();

        void PrintBoard() const;

        EGameState GetState() const override;

        ECellType GetValue(const uint8_t i, const uint8_t j) const override;

        uint8_t GetCurrentPlayer() const override;

        bool MakeMove(const uint8_t i, const uint8_t j) override;

        void Reset() override;

    private:
        std::vector<ITicTacToeListener*> m_listeners;
        std::pair<std::shared_ptr<IPlayer>, std::shared_ptr<IPlayer>> m_players;
        EGameState m_state;
        uint8_t m_round;
        Board m_board;

    };
} //namespace TicTacToe

#endif //PROIECT1_TICTACTOEPVP_H
