#ifndef PROIECT1_BOARD_H
#define PROIECT1_BOARD_H

#include <array>
#include <cstdint>

namespace TicTacToe {

class Board
{
public:
    Board();

    bool IsFull() const;
    void Sketch(const uint8_t index, const char toSketch);

    char ElementAt(const uint8_t index) const;
    char operator()(const uint8_t line, const uint8_t column) const;

private:
    std::array<char, 9> m_board;
};

} // namespace TicTacToe

#endif //PROIECT1_BOARD_H
