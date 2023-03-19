#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private:
    Ui::TicTacToe *ui;
    
/*private slots:
    void on_field_00_clicked();
    void on_field_01_clicked();
    void on_field_02_clicked();
    void on_field_10_clicked();
    void on_field_11_clicked();
    void on_field_12_clicked();
    void on_field_20_clicked();
    void on_field_21_clicked();
    void on_field_22_clicked();
    */
};
#endif // TICTACTOE_H
