#pragma once

#include <ITicTacToeStrategy.h>

namespace TicTacToe
{
    class EasyMode : public ITicTacToeStrategy
    {
    public:
        std::pair<uint8_t, uint8_t> Move(const Board& board, const ECellType cellType) override;
    };
} // namespace TicTacToe