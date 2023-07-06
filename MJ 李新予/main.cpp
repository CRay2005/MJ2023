#include "mainwindow.h"
#include "player.h"
#include "rule.h"
#include "card.h"
#include "player.h"
#include "paixing.h"
#include <iostream>
#include <string>

#include <QVector>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.init();
    w.mopai();
//    w.tiaoshi();
    return a.exec();
}
