#ifndef TICTACTOEGAME_MOCKS_H
#define TICTACTOEGAME_MOCKS_H

#include <IPlayer.h>
#include <ITicTacToeListener.h>
#include <gmock/gmock.h>

namespace TicTacToeTests
{
    class IPlayerMock : public TicTacToe::IPlayer
    {
    public:
        IPlayerMock() = default;

        MOCK_CONST_METHOD0(GetName, std::string());
    };

    class ITicTacToeListenerMock : public TicTacToe::ITicTacToeListener
    {
    public:
        MOCK_CONST_METHOD1(OnMove, void(const TicTacToe::ITicTacToe*));
        MOCK_CONST_METHOD2(OnFinish, void(const TicTacToe::EGameState state, const TicTacToe::IPlayer*));
    };
} // namespace TicTacToeTests
#endif //TICTACTOEGAME_MOCKS_H
