#include <iostream>
#include <Game.h>

int main()
{
   Game game(TicTacToe::EGameType::PvP, "Hitlar", "Adolfiu");
   game.Start();

   return 0;
}