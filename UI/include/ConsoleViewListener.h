#pragma once

#include <ITicTacToeListener.h>
#include <ITicTacToe.h>

class ConsoleViewListener : public TicTacToe::ITicTacToeListener
{
public:
    void OnMove(const TicTacToe::ITicTacToe* ticTacToe) const override;

    void OnFinish(const TicTacToe::EGameState state, const TicTacToe::IPlayer* winner) const override;
};