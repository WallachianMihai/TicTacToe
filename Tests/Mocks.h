#ifndef TICTACTOEGAME_MOCKS_H
#define TICTACTOEGAME_MOCKS_H

#include <IPlayer.h>
#include <gmock/gmock.h>

namespace TicTacToeTests
{
    class IPlayerMock : public TicTacToe::IPlayer
    {
    public:
        IPlayerMock() = default;

        MOCK_CONST_METHOD0(GetName, std::string());
    };
} // namespace TicTacToeTests
#endif //TICTACTOEGAME_MOCKS_H
