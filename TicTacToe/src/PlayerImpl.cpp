//
// Created by mihai on 11.03.2023.
//

#include "PlayerImpl.h"

namespace TicTacToe
{
    IPlayerPtr IPlayer::Produce(EPlayerType type, const std::string& name)
    {
        switch (type)
        {
            case EPlayerType::Human:
                return std::make_shared<PlayerImpl>(name);
            default:
                return {};
        }
    }

    PlayerImpl::PlayerImpl(const std::string &name)
        : m_name{ name }
    {}

    std::string PlayerImpl::GetName() const
    {
        return m_name;
    }

} // namespace TicTacToe