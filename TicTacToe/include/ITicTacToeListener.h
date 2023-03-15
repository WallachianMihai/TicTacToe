#ifndef PROIECT1_ITICTACTOELISTENER_H
#define PROIECT1_ITICTACTOELISTENER_H

namespace TicTacToe
{
    class ITicTacToeListener
    {
    public:
        virtual void OnMove() = 0;
        virtual void OnFinish() = 0;

        virtual ~ITicTacToeListener();
    };
} // namespace TicTacToe

#endif //PROIECT1_ITICTACTOELISTENER_H
