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
        /**
         * @brief Takes a pointer to a game TicTacToe and will perform a specific action whenever the game makes a new move
         * @param ticTacToe A pointer towards the desired game to listen to
         */
        virtual void OnMove(const class ITicTacToe* ticTacToe) const = 0;
        /**
         * @brief Takes a pointer to a game TicTacToe and will perform a specific action when the game is over
         * @param state
         * @param winner
         */
        virtual void OnFinish(const EGameState state, const IPlayer* winner) const = 0;

        virtual ~ITicTacToeListener() = default;
    };

    using ITicTacToeListenerPtr = std::shared_ptr<ITicTacToeListener>;
    using ITicTacToeListenerWeakPtr = std::weak_ptr<ITicTacToeListener>;
} // namespace TicTacToe

#endif //PROIECT1_ITICTACTOELISTENER_H
