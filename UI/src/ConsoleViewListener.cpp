#include <ConsoleViewListener.h>
#include <iostream>

void ConsoleViewListener::OnMove(const TicTacToe::ITicTacToe* ticTacToe, const uint8_t i, const uint8_t j)
{
    for (uint8_t k = 0; k < ticTacToe->GetBoardSize(); ++k)
    {
        for (uint8_t l = 0; l < ticTacToe->GetBoardSize(); ++l)
        {
            switch (ticTacToe->GetValue(k, l))
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

void ConsoleViewListener::OnFinish(const TicTacToe::ITicTacToe* ticTacToe, const uint8_t i, const uint8_t j) const
{
    switch(ticTacToe->GetState())
    {
        case TicTacToe::EGameState::Tie:
            std::cout << "Tie! No one wins..." << std::endl;
            break;
        case TicTacToe::EGameState::FirstPlayerWon:
            if(ticTacToe->GetCurrentPlayer())
            {
                std::cout << ticTacToe->GetCurrentPlayer()->GetName() << " wins!" << std::endl;
            }
            else
            {
                std::cout << "X wins!" << std::endl;
            }
            break;
        case TicTacToe::EGameState::SecondPlayerWon:
            if(ticTacToe->GetCurrentPlayer())
            {
                std::cout << ticTacToe->GetCurrentPlayer()->GetName() << " wins!" << std::endl;
            }
            else
            {
                std::cout << "Zero wins!" << std::endl;
            }
            break;
    }
}

