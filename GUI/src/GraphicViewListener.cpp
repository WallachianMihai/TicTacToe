#include <GraphicViewListener.h>
#include <QMessageBox>

void GraphicViewListener::OnMove(const TicTacToe::ITicTacToe *ticTacToe, const uint8_t i, const uint8_t j)
{
    QMessageBox messageBox;
    if(ticTacToe->GetCurrentPlayer())
    {
        messageBox.setText((ticTacToe->GetCurrentPlayer()->GetName() + " draws at " + std::to_string(i) + ", " + std::to_string(j)).data());
    }
    else
    {
        std::string toSkecth = ticTacToe->GetValue(i, j) == TicTacToe::ECellType::X ? "X" : "0";
        messageBox.setText((toSkecth + " draws at " + std::to_string(i) + ", " + std::to_string(j)).data());
    }
    messageBox.exec();
}

void GraphicViewListener::OnFinish(const TicTacToe::ITicTacToe *ticTacToe, const uint8_t i, const uint8_t j) const
{
    QMessageBox messageBox;
    switch(ticTacToe->GetState())
    {
        case TicTacToe::EGameState::Tie:
            messageBox.setText("Tie! No one wins");
            messageBox.exec();
            break;
        case TicTacToe::EGameState::FirstPlayerWon:
            if(ticTacToe->GetCurrentPlayer())
            {
                messageBox.setText((ticTacToe->GetCurrentPlayer()->GetName() + " wins! ").data());
                messageBox.exec();
            }
            else
            {
                messageBox.setText("X wins!");
                messageBox.exec();
            }
            break;
        case TicTacToe::EGameState::SecondPlayerWon:
            if(ticTacToe->GetCurrentPlayer())
            {
                messageBox.setText((ticTacToe->GetCurrentPlayer()->GetName() + " wins! ").data());
                messageBox.exec();
            }
            else
            {
                messageBox.setText("Zero wins!");
                messageBox.exec();
            }
            break;
        default:
            break;
    }
}

