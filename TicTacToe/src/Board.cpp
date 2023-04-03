#include <iostream>
#include <Board.h>

namespace TicTacToe
{
    Board::Board()
    {
        m_board.fill("-");
    }

    ECellType Board::operator()(const uint8_t line, const uint8_t column) const
    {
        if(m_board[line * SIZE + column] == "x") return ECellType::X;
        if(m_board[line * SIZE + column] == "0") return ECellType::ZERO;
        else return ECellType::EMPTY;
    }

    ECellType Board::operator[](const uint8_t index) const
    {
        if(m_board[index] == "x") return ECellType::X;
        if(m_board[index] == "0") return ECellType::ZERO;
        else return ECellType::EMPTY;
    }

    bool Board::IsFull() const
    {
        for (const auto& elem: m_board)
        {
            if (elem == "-")
            {
                return false;
            }
        }
        return true;
    }

    void Board::Sketch(const uint8_t index, const ECellType toSketch)
    {
        switch (toSketch)
        {
            case ECellType::X:
                m_board[index] = "x";
                return;
            case ECellType::ZERO:
                m_board[index] = "0";
                return;
            default:
                return;
        }
    }

    void Board::ClearBoard()
    {
        m_board.fill("-");
    }

    uint8_t Board::GetSize() const
    {
        return SIZE;
    }
    std::ostream &operator<<(std::ostream& os, const Board& board)
    {
        for (uint8_t i = 0; i < board.SIZE; ++i)
        {
            for (uint8_t j = 0; j < board.SIZE; ++j)
            {
                os << (board(i, j) == ECellType::X ? 'x' : board(i, j) == ECellType::ZERO ? '0' : '-')  << " ";
            }
            os << "\n";
        }
        return os;
    }

    Board &Board::operator=(const Board &other)
    {
        this->m_board = other.m_board;
    }

} // namespace TicTacToe