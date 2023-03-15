#include <Mocks.h>
#include <TicTacToePvP.h>

namespace TicTacToeTests
{
    using ::testing::Return;

    class TicTacToePvPTests : public ::testing::Test
    {
    public:
        TicTacToePvPTests()
            : playerX{ new IPlayerMock }
            , playerZero{ new IPlayerMock }
        {
            instance = new TicTacToe::TicTacToePvP{ playerX, playerZero };
        }

        ~TicTacToePvPTests()
        {
            delete instance;
        }

    protected:
        TicTacToe::TicTacToePvP* instance;
        IPlayerMock* playerX;
        IPlayerMock* playerZero;
    };


    TEST_F(TicTacToePvPTests, TestMakeMove)
    {
        EXPECT_TRUE(instance->MakeMove(0,0));
        EXPECT_FALSE(instance->MakeMove(0,0));
    }

    TEST_F(TicTacToePvPTests, TestGameIsTie)
    {
        //no move made
        EXPECT_EQ(instance->GetState(), TicTacToe::EGameState::Ongoing);

        //board is filled, no one wins
        EXPECT_TRUE(instance->MakeMove(1, 2));
        EXPECT_TRUE(instance->MakeMove(1, 1));
        EXPECT_TRUE(instance->MakeMove(0, 0));
        EXPECT_TRUE(instance->MakeMove(2, 0));
        EXPECT_TRUE(instance->MakeMove(2, 1));
        EXPECT_TRUE(instance->MakeMove(0, 1));
        EXPECT_TRUE(instance->MakeMove(1, 0));
        EXPECT_TRUE(instance->MakeMove(2, 2));
        EXPECT_TRUE(instance->MakeMove(0, 2));

        EXPECT_EQ(instance->GetState(), TicTacToe::EGameState::Tie);
    }

    TEST_F(TicTacToePvPTests, TestWinOnMainDiagonal)
    {
        // x wins on main diagonal
        EXPECT_TRUE(instance->MakeMove(0, 0));
        EXPECT_TRUE(instance->MakeMove(0, 1));
        EXPECT_TRUE(instance->MakeMove(1, 1));
        EXPECT_TRUE(instance->MakeMove(1, 2));
        EXPECT_TRUE(instance->MakeMove(2, 2));

        EXPECT_EQ(instance->GetState(), TicTacToe::EGameState::FirstPlayerWon);
    }

    TEST_F(TicTacToePvPTests, TestWinOnSecondaryDiagonal)
    {
        // Zero wins on second diagonal
        EXPECT_TRUE(instance->MakeMove(0, 0));
        EXPECT_TRUE(instance->MakeMove(2, 0));
        EXPECT_TRUE(instance->MakeMove(0, 1));
        EXPECT_TRUE(instance->MakeMove(1, 1));
        EXPECT_TRUE(instance->MakeMove(2, 1));
        EXPECT_TRUE(instance->MakeMove(0, 2));

        EXPECT_EQ(instance->GetState(), TicTacToe::EGameState::SecondPlayerWon);
    }
} //namespace TicTacToeTests