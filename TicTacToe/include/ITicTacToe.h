#ifndef PROIECT1_ITICTACTOE_H
#define PROIECT1_ITICTACTOE_H

#include <string>
#include <memory>
#include <ITicTacToeListener.h>
#include <IPlayer.h>
#include <ECellType.h>

namespace TicTacToe
{
    enum class EGameType
    {
        PvP
    };

    enum class EGameState
    {
        Ongoing,
        FirstPlayerWon,
        SecondPlayerWon,
        Tie
    };

    using ITicTacToePtr = std::shared_ptr<class ITicTacToe>;

    class ITicTacToe
    {
    public:
        static ITicTacToePtr Produce(const EGameType type, const IPlayerPtr& p1 = nullptr, const IPlayerPtr& p2 = nullptr);

        virtual void AddListener(ITicTacToeListenerPtr listener) = 0;
        virtual void RemoveListener(ITicTacToeListener *listener) = 0;

        virtual EGameState GetState() const = 0;

        virtual ECellType GetValue(const uint8_t i, const uint8_t j) const = 0;

        virtual IPlayer* GetCurrentPlayer() const = 0;

        virtual void Reset() = 0;

        virtual uint8_t GetBoardSize() const = 0;

        virtual bool MakeMove(const uint8_t i, const uint8_t j) = 0;

        virtual ~ITicTacToe() = default;
    };

} //namespace TicTacToe

#endif //PROIECT1_ITICTACTOE_H
