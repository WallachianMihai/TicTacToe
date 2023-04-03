#include "Game.h"
#include "./ui_Game.h"
#include <qpixmap.h>
#include <QInputDialog>

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
    , m_listener{ std::make_shared<GraphicViewListener>() }
{
    ui->setupUi(this);
    QPixmap pix((std::string(RESOURCE_DIR) + "/board.png").data());
    ui->board->setPixmap(pix.scaled(450, 450));

    int choice = QInputDialog::getInt(this, "Game Type", "Enter 1 for PvP or 2 to play against the computer");

    if(choice == 1)
    {
        m_ticTacToe = TicTacToe::ITicTacToe::Produce(TicTacToe::EGameType::PvP);
        ui->difficultyButton->setHidden(true);
    }
    else
    {
        ui->difficultyButton->setEnabled(true);
        int difficulty = QInputDialog::getInt(this, "Difficulty", "Enter 1 for easy difficulty or 2 for hard difficulty");
        if(difficulty == 1)
        {
            m_ticTacToe = TicTacToe::ITicTacToe::Produce(TicTacToe::EGameType::PvP,
                                                         nullptr,
                                                         TicTacToe::IPlayer::Produce(TicTacToe::EPlayerType::Human,
                                                                                     ""),
                                                         TicTacToe::EGameDifficulty::Easy);
        }
        else
        {
            m_ticTacToe = TicTacToe::ITicTacToe::Produce(TicTacToe::EGameType::PvP,
                                                         nullptr,
                                                         TicTacToe::IPlayer::Produce(TicTacToe::EPlayerType::Human,
                                                                                     ""),
                                                         TicTacToe::EGameDifficulty::Hard);
        }
    }


    m_ticTacToe->AddListener(m_listener);
}

Game::~Game()
{
    m_ticTacToe->RemoveListener(m_listener.get());
    delete ui;
}

void Game::on_field_00_clicked()
{
    m_ticTacToe->MakeMove(0, 0);
    UpdateLabels();
  //  ui->field_00->setText(QString(m_ticTacToe->GetValue(0, 0) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_01_clicked()
{
    m_ticTacToe->MakeMove(0, 1);
    UpdateLabels();
   // ui->field_01->setText(QString(m_ticTacToe->GetValue(0, 1) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_02_clicked()
{
    m_ticTacToe->MakeMove(0, 2);
    UpdateLabels();
 //   ui->field_02->setText(QString(m_ticTacToe->GetValue(0, 2) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_10_clicked()
{
    m_ticTacToe->MakeMove(1, 0);
    UpdateLabels();
  //  ui->field_10->setText(QString(m_ticTacToe->GetValue(1, 0) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_11_clicked()
{
    m_ticTacToe->MakeMove(1, 1);
    UpdateLabels();
   // ui->field_11->setText(QString(m_ticTacToe->GetValue(1, 1) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_12_clicked()
{
    m_ticTacToe->MakeMove(1, 2);
    UpdateLabels();
   // ui->field_12->setText(QString(m_ticTacToe->GetValue(1, 2) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_20_clicked()
{
    m_ticTacToe->MakeMove(2, 0);
    UpdateLabels();
  //  ui->field_20->setText(QString(m_ticTacToe->GetValue(2, 0) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_21_clicked()
{
    m_ticTacToe->MakeMove(2, 1);
   // ui->field_21->setText(QString(m_ticTacToe->GetValue(2, 1) == TicTacToe::ECellType::X ? 'x' : '0'));
    UpdateLabels();
}

void Game::on_field_22_clicked()
{
    m_ticTacToe->MakeMove(2, 2);
    //ui->field_22->setText(QString(m_ticTacToe->GetValue(2, 2) == TicTacToe::ECellType::X ? 'x' : '0'));
    UpdateLabels();
}

void Game::UpdateLabels()
{
    std::array<QPushButton*, 9> labels = {
            ui->field_00, ui->field_01, ui->field_02, ui->field_10, ui->field_11,
            ui->field_12, ui->field_20, ui->field_21, ui->field_22
    };
    for (int i = 0; i < m_ticTacToe->GetBoardSize(); ++i)
    {
        for (int j = 0; j < m_ticTacToe->GetBoardSize(); ++j)
        {
            char value = m_ticTacToe->GetValue(i, j) == TicTacToe::ECellType::EMPTY ? '~' :
                         m_ticTacToe->GetValue(i, j) == TicTacToe::ECellType::X ? 'x' : '0';
            labels[i * m_ticTacToe->GetBoardSize() + j]->setText(QString(value));
        }
    }
}

void Game::on_difficultyButton_clicked()
{
    int difficulty = QInputDialog::getInt(this, "Difficulty", "Enter 1 for easy difficulty or 2 for hard difficulty");
    m_ticTacToe->SetDificulty(difficulty == 1 ? TicTacToe::EGameDifficulty::Easy : TicTacToe::EGameDifficulty::Hard);
}

