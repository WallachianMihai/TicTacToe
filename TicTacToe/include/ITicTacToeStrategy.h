#pragma once

#include <Board.h>
#include <memory>
#include <EDifficultyType.h>

namespace TicTacToe
{
    using ITicTacToeStrategyPtr = std::shared_ptr<class ITicTacToeStrategy>;
    class ITicTacToeStrategy
    {
    public:
        static ITicTacToeStrategyPtr MakeStrategy(EGameDifficulty difficulty);

        /***
         * @brief Generates a position on the board where the computer will sketch
         * @param board the board on which to calculate the position
         * @param cellType the type of cell the computer plays with
         * @return the generated position
         */
        virtual std::pair<uint8_t, uint8_t> Move(const Board& board, const ECellType cellType) = 0;
        
        virtual ~ITicTacToeStrategy() = default;
    };


} // namespace TicTacToe
