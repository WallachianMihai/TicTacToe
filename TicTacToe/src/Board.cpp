#include <iostream>
#include <Board.h>

namespace TicTacToe {

Board::Board() : m_board({'-'})
{
}

char Board::operator()(const uint8_t line, const uint8_t column) const
{
    return m_board[line + column];
}

char Board::ElementAt(const uint8_t index) const
{
    return m_board[index];
}

bool Board::IsFull() const
{
    for (const auto elem: m_board)
    {
        if (elem == '-')
        {
            return false;
        }
    }
    return true;
}

void Board::Sketch(const uint8_t index, const char toSketch)
{
    m_board[index] = toSketch;
}

} // namespace TicTacToe