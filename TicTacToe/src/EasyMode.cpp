#include <EasyMode.h>
#include <vector>
#include <cstdlib>

namespace TicTacToe
{
    std::pair<uint8_t, uint8_t> EasyMode::Move(const Board &board, const ECellType cellType)
    {
        std::vector<std::pair<uint8_t, uint8_t>> emptyPositions;
        for (int i = 0; i < board.GetSize(); ++i)
        {
            for (int j = 0; j < board.GetSize(); ++j)
            {
                if (board(i, j) == ECellType::EMPTY)
                {
                    emptyPositions.emplace_back(i, j);
                }
            }
        }
        srand((unsigned)time(nullptr));
        return emptyPositions[rand() % emptyPositions.size()];
    }
} //namespace TicTacToe
