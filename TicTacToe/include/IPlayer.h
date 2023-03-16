#ifndef PROIECT1_IPLAYER_H
#define PROIECT1_IPLAYER_H

#include <string>
#include <memory>

namespace TicTacToe
{
    enum class EPlayerType
    {
        Human
    };

    using IPlayerPtr = std::shared_ptr<class IPlayer>;
    using IPlayerWeakPtr = std::weak_ptr<class IPlayer>;

    class IPlayer
    {
    public:
        static IPlayerPtr Produce(EPlayerType type, const std::string& name);

        virtual std::string GetName() const = 0;

        virtual ~IPlayer() = default;
    };


} // namespace TicTacToe

#endif //PROIECT1_IPLAYER_H
