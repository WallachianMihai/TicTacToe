//
// Created by mihai on 11.03.2023.
//

#include "PlayerImpl.h"

namespace TicTacToe
{
    PlayerImpl::PlayerImpl(const std::string &name)
        : m_name{ name }
    {}

    std::string PlayerImpl::GetName() const
    {
        return m_name;
    }

} // namespace TicTacToe