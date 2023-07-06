#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "player.h"
#include "card.h"
#include <iostream>
#include <QVector>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();
    void showcard();
    QIcon idx_to_icon(int idx);
    void ifhu(int nowplayer);
    void mopai();
    void enable_discard();
    void disable_discard();
    void player2_peng();
    void player3_peng();
    void player2_action();
    void player3_action();
    void player2_action_peng();
    void player3_action_peng();
    void ifpeng(int nowplayer);
    void tiaoshi();
    void ifbei();
    void hidemingpai();
    void countbaopai();
    void showaicard();

private slots:
    void on_shoupai1_clicked();

    void on_shoupai2_clicked();

    void on_shoupai10_clicked();

    void on_shoupai11_clicked();

    void on_shoupai12_clicked();

    void on_shoupai13_clicked();

    void on_shoupai14_clicked();

    void on_shoupai3_clicked();

    void on_shoupai4_clicked();

    void on_shoupai5_clicked();

    void on_shoupai6_clicked();

    void on_shoupai7_clicked();

    void on_shoupai8_clicked();

    void on_shoupai9_clicked();

    void on_mingpai1_clicked();

    void on_mingpai2_clicked();

    void on_skip_clicked();

    void on_mingpai3_clicked();

    void on_mingpai4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
