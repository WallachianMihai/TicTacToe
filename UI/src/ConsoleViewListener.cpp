#include <ConsoleViewListener.h>
#include <iostream>

void ConsoleViewListener::OnMove(const TicTacToe::ITicTacToe* ticTacToe) const
{
    for (uint8_t i = 0; i < ticTacToe->GetBoardSize(); ++i)
    {
        for (uint8_t j = 0; j < ticTacToe->GetBoardSize(); ++j)
        {
            switch (ticTacToe->GetValue(i, j))
            {
                case TicTacToe::ECellType::X:
                    std::cout << 'x' << " ";
                    break;
                case TicTacToe::ECellType::ZERO:
                    std::cout << '0' << " ";
                    break;
                case TicTacToe::ECellType::EMPTY:
                    std::cout << '-' << " ";
                default:
                    break;
            }
        }
        std::cout << std::endl;
    }

}

void ConsoleViewListener::OnFinish(const TicTacToe::EGameState state, const TicTacToe::IPlayer* winner) const
{
    switch(state)
    {
        case TicTacToe::EGameState::Tie:
            std::cout << "Tie! No one wins..." << std::endl;
            break;
        case TicTacToe::EGameState::FirstPlayerWon:
            if(winner)
            {
                std::cout << winner->GetName() << " wins!" << std::endl;
            }
            else
            {
                std::cout << "X wins!" << std::endl;
            }
            break;
        case TicTacToe::EGameState::SecondPlayerWon:
            if(winner)
            {
                std::cout << winner->GetName() << " wins!" << std::endl;
            }
            else
            {
                std::cout << "Zero wins!" << std::endl;
            }
            break;
    }
}

