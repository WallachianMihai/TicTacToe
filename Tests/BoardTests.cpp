#include <Board.h>
#include <gtest/gtest.h>

namespace TicTacToeTests
{
    class BoardTests : public ::testing::Test
    {
    protected:
        TicTacToe::Board boardInstance;
    };

    TEST_F(BoardTests, TestSketch)
    {
        EXPECT_EQ(boardInstance[0], TicTacToe::ECellType::EMPTY);
        boardInstance.Sketch(0, TicTacToe::ECellType::ZERO);
        EXPECT_EQ(boardInstance[0], TicTacToe::ECellType::ZERO);
    }

    TEST_F(BoardTests, TestIsFull)
    {
        EXPECT_FALSE(boardInstance.IsFull());

        boardInstance.Sketch(0, TicTacToe::ECellType::X);
        boardInstance.Sketch(1, TicTacToe::ECellType::X);
        boardInstance.Sketch(2, TicTacToe::ECellType::X);
        boardInstance.Sketch(3, TicTacToe::ECellType::X);
        boardInstance.Sketch(4, TicTacToe::ECellType::X);
        boardInstance.Sketch(5, TicTacToe::ECellType::X);
        boardInstance.Sketch(6, TicTacToe::ECellType::X);
        boardInstance.Sketch(7, TicTacToe::ECellType::X);
        boardInstance.Sketch(8, TicTacToe::ECellType::X);

        EXPECT_TRUE(boardInstance.IsFull());
    }

    TEST_F(BoardTests, TestClearBoard)
    {
        boardInstance.Sketch(0, TicTacToe::ECellType::ZERO);
        EXPECT_EQ(boardInstance[0], TicTacToe::ECellType::ZERO);

        boardInstance.ClearBoard();
        EXPECT_EQ(boardInstance[0], TicTacToe::ECellType::EMPTY);
    }
} //namespace TicTacToeTest