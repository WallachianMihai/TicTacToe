#ifndef TICTACTOEGAME_MOCKS_H
#define TICTACTOEGAME_MOCKS_H

#include <IPlayer.h>
#include <ITicTacToeListener.h>
#include <gmock/gmock.h>
#include <type_traits>
#include <gmock/internal/gmock-internal-utils.h>
#include <gtest/internal/gtest-internal.h>

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
        ITicTacToeListenerMock() = default;

        MOCK_METHOD3(OnMove, void(const TicTacToe::ITicTacToe*, const uint8_t i, const uint8_t j));
        MOCK_CONST_METHOD3(OnFinish, void(const TicTacToe::ITicTacToe*, const uint8_t i, const uint8_t j));
    };
} // namespace TicTacToeTests
#endif //TICTACTOEGAME_MOCKS_H
