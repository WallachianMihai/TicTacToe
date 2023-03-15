#ifndef PROIECT1_IPLAYER_H
#define PROIECT1_IPLAYER_H

#include <string>

namespace TicTacToe
{
    class IPlayer
    {
    public:
        virtual std::string GetName() const = 0;

        virtual ~IPlayer() = default;
    };
} // namespace TicTacToe

#endif //PROIECT1_IPLAYER_H
