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
        /**
        * @brief Constructs a pointer to the specified implementation of this interface
        * @param type The type of the desired player
        * @param name The name of the player
        * @return A shared pointer towards a player of the specified type
        */
        static IPlayerPtr Produce(EPlayerType type, const std::string& name);

        /**
         * @brief A getter for the name of the player
         * @return Returns the name of the player
         */
        virtual std::string GetName() const = 0;

        virtual ~IPlayer() = default;
    };


} // namespace TicTacToe

#endif //PROIECT1_IPLAYER_H
