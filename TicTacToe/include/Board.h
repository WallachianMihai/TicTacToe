#ifndef PROIECT1_BOARD_H
#define PROIECT1_BOARD_H

#include <array>
#include <cstdint>
#include <ostream>
#include <ECellType.h>

namespace TicTacToe
{
    class Board
    {
    public:
        Board();
        Board& operator=(const Board& other);

        bool IsFull() const;
        void Sketch(const uint8_t index, const ECellType toSketch);

        ECellType operator[](const uint8_t index) const;
        ECellType operator()(const uint8_t line, const uint8_t column) const;
        void ClearBoard();
        uint8_t GetSize() const;

        friend std::ostream& operator<<(std::ostream& os, const Board& board);

    private:
        std::array<std::string, 9> m_board;
        const uint8_t SIZE = 3;
    };
} // namespace TicTacToe

#endif //PROIECT1_BOARD_H
