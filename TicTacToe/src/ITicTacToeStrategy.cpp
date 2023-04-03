#include <EasyMode.h>
#include <HardMode.h>
#include "ITicTacToeStrategy.h"


namespace TicTacToe
{
    ITicTacToeStrategyPtr ITicTacToeStrategy::MakeStrategy(EGameDifficulty difficulty)
    {
        switch (difficulty)
        {
            case EGameDifficulty::Easy:
                return std::make_shared<EasyMode>();
            case EGameDifficulty::Hard:
                return std::make_shared<HardMode>();
            default:
                return nullptr;
        }
    }
}