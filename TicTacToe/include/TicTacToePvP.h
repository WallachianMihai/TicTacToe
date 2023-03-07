#ifndef PROIECT1_TICTACTOEPVP_H
#define PROIECT1_TICTACTOEPVP_H

#include <ITicTacToe.h>
#include <vector>

namespace TicTacToe {

class TicTacToePvP : public ITicTacToe
{
public:
    TicTacToePvP();

    void AddTicTacToeListener(ITicTacToeListener *listener) override;
    void RemoveTicTacToeListener(ITicTacToeListener *listener) override;

    bool IsWin() const override;
    bool Isfinished() const override;

    void ProcessNextMove() override;

private:
    std::vector<ITicTacToeListener*> m_listeners;

};

} //namespace TicTacToe

#endif //PROIECT1_TICTACTOEPVP_H
