#pragma once

#include <QMainWindow>
#include <GraphicViewListener.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_field_00_clicked();
    void on_field_01_clicked();
    void on_field_02_clicked();
    void on_field_10_clicked();
    void on_field_11_clicked();
    void on_field_12_clicked();
    void on_field_20_clicked();
    void on_field_21_clicked();
    void on_field_22_clicked();
    void on_difficultyButton_clicked();

private:
    void UpdateLabels();

private:
    Ui::Game *ui;
    TicTacToe::ITicTacToePtr m_ticTacToe;
    TicTacToe::ITicTacToeListenerPtr m_listener;

};

