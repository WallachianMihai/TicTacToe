#ifndef PROIECT1_ITICTACTOE_H
#define PROIECT1_ITICTACTOE_H

#include <string>
#include <memory>
#include <ITicTacToeListener.h>
#include <IPlayer.h>
#include <ECellType.h>
#include <EDifficultyType.h>

namespace TicTacToe
{
    enum class EGameType
    {
        PvP
    };

    enum class EGameState
    {
        Ongoing,
        FirstPlayerWon,
        SecondPlayerWon,
        Tie
    };

    using ITicTacToePtr = std::shared_ptr<class ITicTacToe>;

    class ITicTacToe
    {
    public:
        /**
         * @brief Constructs a pointer to the specified implementation of this interface
         * @param type The type of the desired implementation
         * @param p1 A pointer towards the first player
         * @param p2 A pointer towards the second player
         * @return A shared pointer towards an implementation of the specified type
         */
        static ITicTacToePtr Produce(const EGameType type,
                                     const IPlayerPtr& p1 = nullptr,
                                     const IPlayerPtr& p2 = nullptr,
                                     EGameDifficulty difficulty = EGameDifficulty::None);


        /**
         * @brief Adds a listener to the list of observers
         * @param listener A shared pointer towards the listener to add
         */
        virtual void AddListener(ITicTacToeListenerPtr listener) = 0;

        /**
         * @brief Removes a listener from the list of observers
         * @param listener A pointer towards the listener to remove
         */
        virtual void RemoveListener(ITicTacToeListener *listener) = 0;

        /**
         * @brief A getter for the current state of the game. The state of the game can be: Ongoing, FirstPlayerWon, SecondPlayerWon or Tie
         * @return The current state of the game
         */
        virtual EGameState GetState() const = 0;

        /**
         * @brief Takes 2 indexes and calculates the value at that specific position. It can be: Empty, X or Zero
         * @param i The row index
         * @param j The column index
         * @return The value positioned at the row i and column j
         */
        virtual ECellType GetValue(const uint8_t i, const uint8_t j) const = 0;

        /**
         * @brief A getter for the current player
         * @return The current player who has to draw
         */
        virtual IPlayer* GetCurrentPlayer() const = 0;

        /**
         * @brief A getter for the board size
         * @return The size N of the current board NxN
         */
        virtual uint8_t GetBoardSize() const = 0;

        /**
         * Takes 2 indexes and draws at that specific position X or Zero, depending on who's turn it is. Then calculates the state of the game
         * @param i The row index
         * @param j The column index
         * @return True if the move has been done successfully, false otherwise
         */
        virtual bool MakeMove(const uint8_t i, const uint8_t j) = 0;

        /**
         * @brief Sets the difficulty of the game
         * @param difficulty the desired difficulty
         */
        virtual void SetDificulty(EGameDifficulty difficulty) = 0;

        virtual ~ITicTacToe() = default;
    };

} //namespace TicTacToe

#endif //PROIECT1_ITICTACTOE_H
