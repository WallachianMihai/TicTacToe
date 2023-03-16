#ifndef PROIECT1_ITICTACTOELISTENER_H
#define PROIECT1_ITICTACTOELISTENER_H

#include <memory>

namespace TicTacToe
{
    enum class EGameState;
    class IPlayer;

    class ITicTacToeListener
    {
    public:
        virtual void OnMove(const class ITicTacToe* ticTacToe) const = 0;
        virtual void OnFinish(const EGameState state, const IPlayer* winner) const = 0;

        virtual ~ITicTacToeListener() = default;
    };

    using ITicTacToeListenerPtr = std::shared_ptr<ITicTacToeListener>;
    using ITicTacToeListenerWeakPtr = std::weak_ptr<ITicTacToeListener>;
} // namespace TicTacToe

#endif //PROIECT1_ITICTACTOELISTENER_H
