#pragma once

#include <ITicTacToeStrategy.h>

namespace TicTacToe
{
    class HardMode : public ITicTacToeStrategy
    {
    public:
        std::pair<uint8_t, uint8_t> Move(const Board &board, const ECellType cellType) override;

    private:
        static ECellType CheckState(const Board& board) ;
    };
}