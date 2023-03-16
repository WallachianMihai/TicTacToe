#include <TicTacToePvP.h>

namespace TicTacToe
{
    ITicTacToePtr ITicTacToe::Produce(const EGameType type, const IPlayerPtr& p1, const IPlayerPtr& p2)
    {
        switch (type)
        {
            case EGameType::PvP:
                return std::make_shared<TicTacToePvP>(p1, p2);
            default:
                return nullptr;
        }
    }
}