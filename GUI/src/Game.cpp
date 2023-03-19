#include "Game.h"
#include "./ui_Game.h"
#include <qpixmap.h>

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
    , m_ticTacToe{ TicTacToe::ITicTacToe::Produce(TicTacToe::EGameType::PvP) }
    , m_listener{ std::make_shared<GraphicViewListener>() }
{
    ui->setupUi(this);
    QPixmap pix((std::string(RESOURCE_DIR) + "/board.png").data());
    ui->board->setPixmap(pix.scaled(450, 450));

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
    ui->field_00->setText(QString(m_ticTacToe->GetValue(0, 0) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_01_clicked()
{
    m_ticTacToe->MakeMove(0, 1);
    ui->field_01->setText(QString(m_ticTacToe->GetValue(0, 1) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_02_clicked()
{
    m_ticTacToe->MakeMove(0, 2);
    ui->field_02->setText(QString(m_ticTacToe->GetValue(0, 2) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_10_clicked()
{
    m_ticTacToe->MakeMove(1, 0);
    ui->field_10->setText(QString(m_ticTacToe->GetValue(1, 0) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_11_clicked()
{
    m_ticTacToe->MakeMove(1, 1);
    ui->field_11->setText(QString(m_ticTacToe->GetValue(1, 1) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_12_clicked()
{
    m_ticTacToe->MakeMove(1, 2);
    ui->field_12->setText(QString(m_ticTacToe->GetValue(1, 2) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_20_clicked()
{
    m_ticTacToe->MakeMove(2, 0);
    ui->field_20->setText(QString(m_ticTacToe->GetValue(2, 0) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_21_clicked()
{
    m_ticTacToe->MakeMove(2, 1);
    ui->field_21->setText(QString(m_ticTacToe->GetValue(2, 1) == TicTacToe::ECellType::X ? 'x' : '0'));
}

void Game::on_field_22_clicked()
{
    m_ticTacToe->MakeMove(2, 2);
    ui->field_22->setText(QString(m_ticTacToe->GetValue(2, 2) == TicTacToe::ECellType::X ? 'x' : '0'));

}

