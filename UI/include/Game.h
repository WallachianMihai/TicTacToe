#pragma once

#include <ITicTacToe.h>
#include <ConsoleViewListener.h>

class Game
{
public:
    explicit Game(TicTacToe::EGameType type, const std::string& playerX, const std::string& playerZero);
    ~Game();

    void Start() const;

private:
    void Init() const;

private:
    TicTacToe::IPlayerPtr m_playerX;
    TicTacToe::IPlayerPtr m_playerZero;
    TicTacToe::ITicTacToeListenerPtr m_listener;
    TicTacToe::ITicTacToePtr m_ticTacToe;
};