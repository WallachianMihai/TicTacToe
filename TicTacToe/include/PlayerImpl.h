#ifndef TICTACTOEGAME_PLAYERIMPL_H
#define TICTACTOEGAME_PLAYERIMPL_H

#include <IPlayer.h>

namespace TicTacToe
{
    class PlayerImpl : public IPlayer
    {
    public:
        explicit PlayerImpl(const std::string &name);

        std::string GetName() const override;

    private:
        std::string m_name;
        bool m_winner;
    };
} // namespace TicTacToe


#endif //TICTACTOEGAME_PLAYERIMPL_H
