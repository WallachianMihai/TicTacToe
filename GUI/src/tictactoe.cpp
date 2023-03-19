#include "tictactoe.h"
#include "./ui_tictactoe.h"
#include <qpixmap.h>

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    QPixmap pix("C:/TicTacToe.git/board");
    ui->board->setPixmap(pix.scaled(450, 450));
}

TicTacToe::~TicTacToe()
{
    delete ui;
}
/*void on_field_00_clicked()
{
    
}
void on_field_01_clicked()
{

}
void on_field_02_clicked()
{

}
void on_field_10_clicked()
{

}
void on_field_11_clicked()
{

}
void on_field_12_clicked()
{

}
void on_field_20_clicked()
{

}
void on_field_21_clicked()
{

}
void on_field_22_clicked()
{

}*/
