#include <Mocks.h>
#include <TicTacToePvP.h>

namespace TicTacToeTests
{
    using ::testing::_;

    class TicTacToePvPTests : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            Test::SetUp();
            listener = std::make_shared<ITicTacToeListenerMock>();
            instance = TicTacToe::ITicTacToe::Produce(TicTacToe::EGameType::PvP);
            instance->AddListener(listener);
        }

        virtual void TearDown()
        {
            instance->RemoveListener(listener.get());
        }

    protected:
        TicTacToe::ITicTacToePtr instance;
        std::shared_ptr<ITicTacToeListenerMock> listener;
    };


    TEST_F(TicTacToePvPTests, TestMakeMove)
    {
        EXPECT_CALL(*listener.get(), OnMove(instance.get(), _, _))
            .Times(1);

        EXPECT_TRUE(instance->MakeMove(0,0));
        EXPECT_FALSE(instance->MakeMove(0,0));
    }

    TEST_F(TicTacToePvPTests, TestGameIsTie)
    {
        //no move made
        EXPECT_EQ(instance->GetState(), TicTacToe::EGameState::Ongoing);

        EXPECT_CALL(*listener.get(), OnMove(instance.get(), _, _))
            .Times(9);

        EXPECT_CALL(*listener.get(), OnFinish(instance.get(), _, _));

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
        EXPECT_CALL(*listener.get(), OnMove(instance.get(), _, _))
            .Times(5);

        EXPECT_CALL(*listener.get(), OnFinish(instance.get(), _, _));

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
        EXPECT_CALL(*listener.get(), OnMove(instance.get(), _, _))
            .Times(6);

        EXPECT_CALL(*listener.get(), OnFinish(instance.get(), _, _));

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