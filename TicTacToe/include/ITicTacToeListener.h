#ifndef PROIECT1_ITICTACTOELISTENER_H
#define PROIECT1_ITICTACTOELISTENER_H

namespace TicTacToe {

class ITicTacToeListener
{
public:
    virtual void OnSketch() = 0;
    virtual void OnWin() = 0;
};

} // namespace TicTacToe

#endif //PROIECT1_ITICTACTOELISTENER_H
