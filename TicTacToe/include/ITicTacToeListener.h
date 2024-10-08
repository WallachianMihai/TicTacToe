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
         * @param i The row index selected
         * @param j The column index selected
         */
        virtual void OnMove(const class ITicTacToe* ticTacToe, const uint8_t i, const uint8_t j) = 0;

        /**
         * @brief Takes a pointer to a game TicTacToe and will perform a specific action when the game is over
         * @param ticTacToe A pointer towards the desired game to listen to
         * @param i The row index selected
         * @param j The column index selected
         */
        virtual void OnFinish(const class ITicTacToe* ticTacToe, const uint8_t i, const uint8_t j) const = 0;

        virtual ~ITicTacToeListener() = default;
    };

    using ITicTacToeListenerPtr = std::shared_ptr<ITicTacToeListener>;
    using ITicTacToeListenerWeakPtr = std::weak_ptr<ITicTacToeListener>;
} // namespace TicTacToe

#endif //PROIECT1_ITICTACTOELISTENER_H
