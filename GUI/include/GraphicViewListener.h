#pragma once

#include <ITicTacToeListener.h>
#include <ITicTacToe.h>

class GraphicViewListener : public TicTacToe::ITicTacToeListener
{
public:
    void OnMove(const TicTacToe::ITicTacToe *ticTacToe, const uint8_t i, const uint8_t j) override;

    void OnFinish(const TicTacToe::ITicTacToe *ticTacToe, const uint8_t i, const uint8_t j) const override;
};