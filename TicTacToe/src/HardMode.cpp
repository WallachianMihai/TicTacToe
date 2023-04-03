#include <HardMode.h>
#include <vector>

namespace TicTacToe
{
    std::pair<uint8_t, uint8_t> HardMode::Move(const Board &board, const ECellType cellType)
    {
        std::vector<std::pair<uint8_t, uint8_t>> availablePositions;
        for (uint8_t i = 0; i < board.GetSize(); ++i)
        {
            for (int j = 0; j < board.GetSize(); ++j)
            {
                if(board(i, j) == ECellType::EMPTY)
                    availablePositions.emplace_back(i, j);
            }
        }

        uint8_t emptyRow, emptyCol;
        for (const auto& position : availablePositions)
        {
            Board boardCopy = board;
            const auto[i, j] = position;
            boardCopy.Sketch(i * board.GetSize() + j, cellType);

            if(CheckState(boardCopy) == cellType)
            {
                return {i, j};
            }

            boardCopy = board;
            boardCopy.Sketch(i * board.GetSize() + j, (ECellType::X == cellType ? ECellType::ZERO : ECellType::X));
            if (CheckState(boardCopy) == (ECellType::X == cellType ? ECellType::ZERO : ECellType::X))
            {
                return {i, j};
            }

            if(CheckState(boardCopy) == ECellType::EMPTY)
            {
                emptyRow = i;
                emptyCol = j;
            }
        }
        return {emptyRow, emptyCol};
    }

    ECellType HardMode::CheckState(const Board& board)
    {
        for (uint8_t i = 0; i < board.GetSize(); ++i)
        {
            if (board(i, 0) ==
                board(i, 1) &&
                board(i, 1) ==
                board(i, 2) &&
                board(i, 0) != ECellType::EMPTY)
            {
                if(board(i, 0) == ECellType::X)
                {
                    return ECellType::X;
                }
                else
                {
                    return ECellType::ZERO;
                }
            }

            if (board(0, i) ==
                board(1, i) &&
                board(1, i) ==
                board(2, i) &&
                board(0, i) != ECellType::EMPTY)
            {
                if(board(0, i) == ECellType::X)
                {
                    return ECellType::X;
                }
                else
                {
                    return ECellType::ZERO;
                }
            }
        }

        if(board[0] ==
           board[board.GetSize() + 1] &&
           board[board.GetSize() + 1] ==
           board[board.GetSize() * board.GetSize() - 1] &&
           board[0] != ECellType::EMPTY)
        {
            if(board[0] == ECellType::X)
            {
                return ECellType::X;
            }
            else
            {
                return ECellType::ZERO;
            }
        }

        if(board[board.GetSize() - 1] ==
           board[board.GetSize() + 1] &&
           board[board.GetSize() + 1] ==
           board[board.GetSize() + 3] &&
           board[board.GetSize() + 3] != ECellType::EMPTY)
        {
            if(board[board.GetSize() - 1] == ECellType::X)
            {
                return ECellType::X;
            }
            else
            {
                return ECellType::ZERO;
            }
        }

        return ECellType::EMPTY;
    }
}