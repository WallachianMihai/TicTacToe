#ifndef PROIECT1_ITICTACTOE_H
#define PROIECT1_ITICTACTOE_H

#include <string>
#include <memory>
#include <ITicTacToeListener.h>

namespace TicTacToe {

using ITicTacToePtr = std::shared_ptr<class ITicTacToe>;

class ITicTacToe {
public:
    static ITicTacToePtr Produce();

    virtual void AddTicTacToeListener(ITicTacToeListener *listener) = 0;
    virtual void RemoveTicTacToeListener(ITicTacToeListener *listener) = 0;

    virtual bool IsWin() const = 0;
    virtual bool Isfinished() const = 0;

    virtual void ProcessNextMove() = 0;

    virtual ~ITicTacToe() = default;
};

} //namespace TicTacToe

#endif //PROIECT1_ITICTACTOE_H
