#pragma execution_character_set("utf-8")

#include<windows.h>

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "iconhelper.h"

#include<list>
using std::list;

#include <vector>
using std::vector;

#include <algorithm>
using std::stable_partition;
using std::sort;

#include<cstring>
#include <iostream>
#include <string>

#include <list>
using std::list;

#include <string>
using std::string;

#include<time.h>

#include <set>
using std::set;

#include <unordered_map>
using std::pair;
using std::unordered_map;

#include <unordered_set>
using std::unordered_set;

#include<map>
using std::map;

#include<stack>
using std::stack;

#include<string.h>//memset

#include<QDataStream>

#include<QStringList>


#include<QTimer>


//窗口构造函数
UIMainWindows::UIMainWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIMainWindows)
{
    ui->setupUi(this);
    //实现交互
    this->initForm();
    //主界面的左边框
    this->initLeftMain();
    //系统设置的左边框
    this->initLeftConfig();
    //设置左端图标
    QPixmap mainlogo_pixmap(":/image/main_logo.png");
//  mainlogo_pixmap = mainlogo_pixmap.scaled(ui->labIco->width(), ui->labIco->height(),
//                                        Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//设置图片大小和label的长宽一致)
    mainlogo_pixmap = mainlogo_pixmap.scaled(50, 50,
                                        Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//设置图片大小和label的长宽一致)
                                        //    tianqi_pixmap = tianqi_pixmap.scaled(ui->labIco->width(), ui->labIco->height(),
//                                         Qt::KeepAspectRatio);//设置图片大小和label的长宽一致)
    ui->labIco->setPixmap(mainlogo_pixmap);

    //初始化托盘
    initTray();

     //初始化游戏界面（选庄、测试）
     initGamePanel();

     //安装事件过滤器
     initInstallEventFilter();

     //初始化规则设置界面
     initConfig();
     initUselessConfig();
     setScoreTxt();
     setbglabel();


      QWidget* hide[] = {ui->label_24,ui->label_25,
                         ui->sendServerButton,ui->sendStatusLineEdit,ui->connectButton,
                         ui->startGameButton,ui->tbtnConfig3,ui->tbtnConfig6,
                         ui->dataStatusLabel
                         };
      for(int i = 0; i < sizeof(hide)/sizeof(QWidget*); i++)
           hide[i]->setVisible(false);

      loadWidgetList();
}

//为了后续简化处理，将窗体中的额组件装载到数组中
void UIMainWindows::loadWidgetList()
{
    //方位 按钮
    bankerlist[0] = ui->bankerNan;
    bankerlist[1] = ui->bankerDong;
    bankerlist[2] = ui->bankerBei;
    bankerlist[3] = ui->bankerXi;
    //开局 按钮
    dirbeginlist[0] = ui->southbeginButton;
    dirbeginlist[1] = ui->eastbeginButton;
    dirbeginlist[2] = ui->northbeginButton;
    dirbeginlist[3] = ui->westbeginButton;
    //南 抓牌墙
    drawSouthlist1[0] =  ui->drawSouth1_1;
    drawSouthlist1[1] =  ui->drawSouth1_2;
    drawSouthlist1[2] =  ui->drawSouth1_3;
    drawSouthlist1[3] =  ui->drawSouth1_4;
    drawSouthlist1[4] =  ui->drawSouth1_5;
    drawSouthlist1[5] =  ui->drawSouth1_6;
    drawSouthlist1[6] =  ui->drawSouth1_7;
    drawSouthlist1[7] =  ui->drawSouth1_8;
    drawSouthlist1[8] =  ui->drawSouth1_9;
    drawSouthlist1[9] =  ui->drawSouth1_10;
    drawSouthlist1[10] =  ui->drawSouth1_11;
    drawSouthlist1[11] =  ui->drawSouth1_12;
    drawSouthlist1[12] =  ui->drawSouth1_13;
    drawSouthlist1[13] =  ui->drawSouth1_14;
    drawSouthlist1[14] =  ui->drawSouth1_15;
    drawSouthlist1[15] =  ui->drawSouth1_16;
    drawSouthlist1[16] =  ui->drawSouth1_17;

    drawSouthlist2[0] =  ui->drawSouth2_1;
    drawSouthlist2[1] =  ui->drawSouth2_2;
    drawSouthlist2[2] =  ui->drawSouth2_3;
    drawSouthlist2[3] =  ui->drawSouth2_4;
    drawSouthlist2[4] =  ui->drawSouth2_5;
    drawSouthlist2[5] =  ui->drawSouth2_6;
    drawSouthlist2[6] =  ui->drawSouth2_7;
    drawSouthlist2[7] =  ui->drawSouth2_8;
    drawSouthlist2[8] =  ui->drawSouth2_9;
    drawSouthlist2[9] =  ui->drawSouth2_10;
    drawSouthlist2[10] =  ui->drawSouth2_11;
    drawSouthlist2[11] =  ui->drawSouth2_12;
    drawSouthlist2[12] =  ui->drawSouth2_13;
    drawSouthlist2[13] =  ui->drawSouth2_14;
    drawSouthlist2[14] =  ui->drawSouth2_15;
    drawSouthlist2[15] =  ui->drawSouth2_16;
    drawSouthlist2[16] =  ui->drawSouth2_17;
    //东 抓牌墙
    drawEastlist1[0] =  ui->drawEast1_1;
    drawEastlist1[1] =  ui->drawEast1_2;
    drawEastlist1[2] =  ui->drawEast1_3;
    drawEastlist1[3] =  ui->drawEast1_4;
    drawEastlist1[4] =  ui->drawEast1_5;
    drawEastlist1[5] =  ui->drawEast1_6;
    drawEastlist1[6] =  ui->drawEast1_7;
    drawEastlist1[7] =  ui->drawEast1_8;
    drawEastlist1[8] =  ui->drawEast1_9;
    drawEastlist1[9] =  ui->drawEast1_10;
    drawEastlist1[10] =  ui->drawEast1_11;
    drawEastlist1[11] =  ui->drawEast1_12;
    drawEastlist1[12] =  ui->drawEast1_13;
    drawEastlist1[13] =  ui->drawEast1_14;
    drawEastlist1[14] =  ui->drawEast1_15;
    drawEastlist1[15] =  ui->drawEast1_16;
    drawEastlist1[16] =  ui->drawEast1_17;

    drawEastlist2[0] =  ui->drawEast2_1;
    drawEastlist2[1] =  ui->drawEast2_2;
    drawEastlist2[2] =  ui->drawEast2_3;
    drawEastlist2[3] =  ui->drawEast2_4;
    drawEastlist2[4] =  ui->drawEast2_5;
    drawEastlist2[5] =  ui->drawEast2_6;
    drawEastlist2[6] =  ui->drawEast2_7;
    drawEastlist2[7] =  ui->drawEast2_8;
    drawEastlist2[8] =  ui->drawEast2_9;
    drawEastlist2[9] =  ui->drawEast2_10;
    drawEastlist2[10] =  ui->drawEast2_11;
    drawEastlist2[11] =  ui->drawEast2_12;
    drawEastlist2[12] =  ui->drawEast2_13;
    drawEastlist2[13] =  ui->drawEast2_14;
    drawEastlist2[14] =  ui->drawEast2_15;
    drawEastlist2[15] =  ui->drawEast2_16;
    drawEastlist2[16] =  ui->drawEast2_17;
    //北 抓牌墙
    drawNorthlist1[0] =  ui->drawNorth1_1;
    drawNorthlist1[1] =  ui->drawNorth1_2;
    drawNorthlist1[2] =  ui->drawNorth1_3;
    drawNorthlist1[3] =  ui->drawNorth1_4;
    drawNorthlist1[4] =  ui->drawNorth1_5;
    drawNorthlist1[5] =  ui->drawNorth1_6;
    drawNorthlist1[6] =  ui->drawNorth1_7;
    drawNorthlist1[7] =  ui->drawNorth1_8;
    drawNorthlist1[8] =  ui->drawNorth1_9;
    drawNorthlist1[9] =  ui->drawNorth1_10;
    drawNorthlist1[10] =  ui->drawNorth1_11;
    drawNorthlist1[11] =  ui->drawNorth1_12;
    drawNorthlist1[12] =  ui->drawNorth1_13;
    drawNorthlist1[13] =  ui->drawNorth1_14;
    drawNorthlist1[14] =  ui->drawNorth1_15;
    drawNorthlist1[15] =  ui->drawNorth1_16;
    drawNorthlist1[16] =  ui->drawNorth1_17;

    drawNorthlist2[0] =  ui->drawNorth2_1;
    drawNorthlist2[1] =  ui->drawNorth2_2;
    drawNorthlist2[2] =  ui->drawNorth2_3;
    drawNorthlist2[3] =  ui->drawNorth2_4;
    drawNorthlist2[4] =  ui->drawNorth2_5;
    drawNorthlist2[5] =  ui->drawNorth2_6;
    drawNorthlist2[6] =  ui->drawNorth2_7;
    drawNorthlist2[7] =  ui->drawNorth2_8;
    drawNorthlist2[8] =  ui->drawNorth2_9;
    drawNorthlist2[9] =  ui->drawNorth2_10;
    drawNorthlist2[10] =  ui->drawNorth2_11;
    drawNorthlist2[11] =  ui->drawNorth2_12;
    drawNorthlist2[12] =  ui->drawNorth2_13;
    drawNorthlist2[13] =  ui->drawNorth2_14;
    drawNorthlist2[14] =  ui->drawNorth2_15;
    drawNorthlist2[15] =  ui->drawNorth2_16;
    drawNorthlist2[16] =  ui->drawNorth2_17;
    //西 抓牌墙
    drawWestlist1[0] =  ui->drawWest1_1;
    drawWestlist1[1] =  ui->drawWest1_2;
    drawWestlist1[2] =  ui->drawWest1_3;
    drawWestlist1[3] =  ui->drawWest1_4;
    drawWestlist1[4] =  ui->drawWest1_5;
    drawWestlist1[5] =  ui->drawWest1_6;
    drawWestlist1[6] =  ui->drawWest1_7;
    drawWestlist1[7] =  ui->drawWest1_8;
    drawWestlist1[8] =  ui->drawWest1_9;
    drawWestlist1[9] =  ui->drawWest1_10;
    drawWestlist1[10] =  ui->drawWest1_11;
    drawWestlist1[11] =  ui->drawWest1_12;
    drawWestlist1[12] =  ui->drawWest1_13;
    drawWestlist1[13] =  ui->drawWest1_14;
    drawWestlist1[14] =  ui->drawWest1_15;
    drawWestlist1[15] =  ui->drawWest1_16;
    drawWestlist1[16] =  ui->drawWest1_17;

    drawWestlist2[0] =  ui->drawWest2_1;
    drawWestlist2[1] =  ui->drawWest2_2;
    drawWestlist2[2] =  ui->drawWest2_3;
    drawWestlist2[3] =  ui->drawWest2_4;
    drawWestlist2[4] =  ui->drawWest2_5;
    drawWestlist2[5] =  ui->drawWest2_6;
    drawWestlist2[6] =  ui->drawWest2_7;
    drawWestlist2[7] =  ui->drawWest2_8;
    drawWestlist2[8] =  ui->drawWest2_9;
    drawWestlist2[9] =  ui->drawWest2_10;
    drawWestlist2[10] =  ui->drawWest2_11;
    drawWestlist2[11] =  ui->drawWest2_12;
    drawWestlist2[12] =  ui->drawWest2_13;
    drawWestlist2[13] =  ui->drawWest2_14;
    drawWestlist2[14] =  ui->drawWest2_15;
    drawWestlist2[15] =  ui->drawWest2_16;
    drawWestlist2[16] =  ui->drawWest2_17;
    //南 手牌
    handSouthlist[0] = ui->handSouth1;
    handSouthlist[1] = ui->handSouth2;
    handSouthlist[2] = ui->handSouth3;
    handSouthlist[3] = ui->handSouth4;
    handSouthlist[4] = ui->handSouth5;
    handSouthlist[5] = ui->handSouth6;
    handSouthlist[6] = ui->handSouth7;
    handSouthlist[7] = ui->handSouth8;
    handSouthlist[8] = ui->handSouth9;
    handSouthlist[9] = ui->handSouth10;
    handSouthlist[10] = ui->handSouth11;
    handSouthlist[11] = ui->handSouth12;
    handSouthlist[12] = ui->handSouth13;
    handSouthlist[13] = ui->handSouth14;
    handSouthlist[14] = ui->handSouth15;
    handSouthlist[15] = ui->handSouth16;
    handSouthlist[16] = ui->handSouth17;
    handSouthlist[17] = ui->handSouth18;
    //东 手牌
    handEastlist[0] = ui->handEast1;
    handEastlist[1] = ui->handEast2;
    handEastlist[2] = ui->handEast3;
    handEastlist[3] = ui->handEast4;
    handEastlist[4] = ui->handEast5;
    handEastlist[5] = ui->handEast6;
    handEastlist[6] = ui->handEast7;
    handEastlist[7] = ui->handEast8;
    handEastlist[8] = ui->handEast9;
    handEastlist[9] = ui->handEast10;
    handEastlist[10] = ui->handEast11;
    handEastlist[11] = ui->handEast12;
    handEastlist[12] = ui->handEast13;
    handEastlist[13] = ui->handEast14;
    handEastlist[14] = ui->handEast15;
    handEastlist[15] = ui->handEast16;
    handEastlist[16] = ui->handEast17;
    handEastlist[17] = ui->handEast18;
    //北 手牌
    handNorthlist[0] = ui->handNorth1;
    handNorthlist[1] = ui->handNorth2;
    handNorthlist[2] = ui->handNorth3;
    handNorthlist[3] = ui->handNorth4;
    handNorthlist[4] = ui->handNorth5;
    handNorthlist[5] = ui->handNorth6;
    handNorthlist[6] = ui->handNorth7;
    handNorthlist[7] = ui->handNorth8;
    handNorthlist[8] = ui->handNorth9;
    handNorthlist[9] = ui->handNorth10;
    handNorthlist[10] = ui->handNorth11;
    handNorthlist[11] = ui->handNorth12;
    handNorthlist[12] = ui->handNorth13;
    handNorthlist[13] = ui->handNorth14;
    handNorthlist[14] = ui->handNorth15;
    handNorthlist[15] = ui->handNorth16;
    handNorthlist[16] = ui->handNorth17;
    handNorthlist[17] = ui->handNorth18;
    //西 手牌
    handWestlist[0] = ui->handWest1;
    handWestlist[1] = ui->handWest2;
    handWestlist[2] = ui->handWest3;
    handWestlist[3] = ui->handWest4;
    handWestlist[4] = ui->handWest5;
    handWestlist[5] = ui->handWest6;
    handWestlist[6] = ui->handWest7;
    handWestlist[7] = ui->handWest8;
    handWestlist[8] = ui->handWest9;
    handWestlist[9] = ui->handWest10;
    handWestlist[10] = ui->handWest11;
    handWestlist[11] = ui->handWest12;
    handWestlist[12] = ui->handWest13;
    handWestlist[13] = ui->handWest14;
    handWestlist[14] = ui->handWest15;
    handWestlist[15] = ui->handWest16;
    handWestlist[16] = ui->handWest17;
    handWestlist[17] = ui->handWest18;
    //南 提示符号
    handPromptSouthlist[0] = ui->handPromptSouth1;
    handPromptSouthlist[1] = ui->handPromptSouth2;
    handPromptSouthlist[2] = ui->handPromptSouth3;
    handPromptSouthlist[3] = ui->handPromptSouth4;
    handPromptSouthlist[4] = ui->handPromptSouth5;
    handPromptSouthlist[5] = ui->handPromptSouth6;
    handPromptSouthlist[6] = ui->handPromptSouth7;
    handPromptSouthlist[7] = ui->handPromptSouth8;
    handPromptSouthlist[8] = ui->handPromptSouth9;
    handPromptSouthlist[9] = ui->handPromptSouth10;
    handPromptSouthlist[10] = ui->handPromptSouth11;
    handPromptSouthlist[11] = ui->handPromptSouth12;
    handPromptSouthlist[12] = ui->handPromptSouth13;
    handPromptSouthlist[13] = ui->handPromptSouth14;
    handPromptSouthlist[14] = ui->handPromptSouth15;
    handPromptSouthlist[15] = ui->handPromptSouth16;
    handPromptSouthlist[16] = ui->handPromptSouth17;
    handPromptSouthlist[17] = ui->handPromptSouth18;
    //东 提示符号
    handPromptEastlist[0] = ui->handPromptEast1;
    handPromptEastlist[1] = ui->handPromptEast2;
    handPromptEastlist[2] = ui->handPromptEast3;
    handPromptEastlist[3] = ui->handPromptEast4;
    handPromptEastlist[4] = ui->handPromptEast5;
    handPromptEastlist[5] = ui->handPromptEast6;
    handPromptEastlist[6] = ui->handPromptEast7;
    handPromptEastlist[7] = ui->handPromptEast8;
    handPromptEastlist[8] = ui->handPromptEast9;
    handPromptEastlist[9] = ui->handPromptEast10;
    handPromptEastlist[10] = ui->handPromptEast11;
    handPromptEastlist[11] = ui->handPromptEast12;
    handPromptEastlist[12] = ui->handPromptEast13;
    handPromptEastlist[13] = ui->handPromptEast14;
    handPromptEastlist[14] = ui->handPromptEast15;
    handPromptEastlist[15] = ui->handPromptEast16;
    handPromptEastlist[16] = ui->handPromptEast17;
    handPromptEastlist[17] = ui->handPromptEast18;
    //北 提示符号
    handPromptNorthlist[0] = ui->handPromptNorth1;
    handPromptNorthlist[1] = ui->handPromptNorth2;
    handPromptNorthlist[2] = ui->handPromptNorth3;
    handPromptNorthlist[3] = ui->handPromptNorth4;
    handPromptNorthlist[4] = ui->handPromptNorth5;
    handPromptNorthlist[5] = ui->handPromptNorth6;
    handPromptNorthlist[6] = ui->handPromptNorth7;
    handPromptNorthlist[7] = ui->handPromptNorth8;
    handPromptNorthlist[8] = ui->handPromptNorth9;
    handPromptNorthlist[9] = ui->handPromptNorth10;
    handPromptNorthlist[10] = ui->handPromptNorth11;
    handPromptNorthlist[11] = ui->handPromptNorth12;
    handPromptNorthlist[12] = ui->handPromptNorth13;
    handPromptNorthlist[13] = ui->handPromptNorth14;
    handPromptNorthlist[14] = ui->handPromptNorth15;
    handPromptNorthlist[15] = ui->handPromptNorth16;
    handPromptNorthlist[16] = ui->handPromptNorth17;
    handPromptNorthlist[17] = ui->handPromptNorth18;
    //西 提示符号
    handPromptWestlist[0] = ui->handPromptWest1;
    handPromptWestlist[1] = ui->handPromptWest2;
    handPromptWestlist[2] = ui->handPromptWest3;
    handPromptWestlist[3] = ui->handPromptWest4;
    handPromptWestlist[4] = ui->handPromptWest5;
    handPromptWestlist[5] = ui->handPromptWest6;
    handPromptWestlist[6] = ui->handPromptWest7;
    handPromptWestlist[7] = ui->handPromptWest8;
    handPromptWestlist[8] = ui->handPromptWest9;
    handPromptWestlist[9] = ui->handPromptWest10;
    handPromptWestlist[10] = ui->handPromptWest11;
    handPromptWestlist[11] = ui->handPromptWest12;
    handPromptWestlist[12] = ui->handPromptWest13;
    handPromptWestlist[13] = ui->handPromptWest14;
    handPromptWestlist[14] = ui->handPromptWest15;
    handPromptWestlist[15] = ui->handPromptWest16;
    handPromptWestlist[16] = ui->handPromptWest17;
    handPromptWestlist[17] = ui->handPromptWest18;
}

UIMainWindows::~UIMainWindows()
{
    delete ui;
}


void UIMainWindows::on_showMainAction()
{
    this->show();
}

void UIMainWindows::on_exitAppAction()
{
    exit(0);
}
//根据设置页面总设置的麻将桌背景图案，设置麻将桌背景
void UIMainWindows::setbglabel()
{
    int i=0;
    if (ui->bgcheckBox_1->isChecked())
        i=1;
    if (ui->bgcheckBox_2->isChecked())
        i=2;
    if (ui->bgcheckBox_3->isChecked())
        i=3;
    if (ui->bgcheckBox_4->isChecked())
        i=4;
    if (i==0) {
        ui->bglabel->clear();
        return;
    }
    QString res = QString::number(i);
    res=":/image/bg"+res+".png";

    QPixmap pixmap(res);
    pixmap.scaled(ui->bglabel->size(), Qt::IgnoreAspectRatio);
    ui->bglabel->setScaledContents(true);
    ui->bglabel->setPixmap(pixmap);
    ui->bglabel->lower();
}

//初始化窗体布局
void UIMainWindows::initForm()
{   
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    //:/image/main_logo.png

    IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf073), 30);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf096));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));

    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");
    ui->labTitle->setText("麻将2023");
    this->setWindowTitle(ui->labTitle->text());

    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }

    ui->btnMain->click();

    ui->widgetLeftMain->setProperty("flag", "left");
    ui->widgetLeftConfig->setProperty("flag", "left");
    ui->page1->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(60));
    ui->page2->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(20));

}

void UIMainWindows::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        if (btn == b) {
            btn->setChecked(true);
        } else {
            btn->setChecked(false);
        }
    }

    //切换界面
    if (name == "游戏界面") {
        ui->stackedWidget->setCurrentIndex(0);
        setbglabel();
    } else if (name == "系统设置") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "役种列表") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "使用帮助") {
        ui->stackedWidget->setCurrentIndex(3);
    } else if (name == "退出游戏") {
        //exit(0);
        emit logoutdialogShow();//发出返回登陆界面信号
        emit accountShow();
        emit onPlayBackgroundMusic();
        this->close();

    }
}

void UIMainWindows::initLeftMain()
{
    pixCharMain << 0xf030 << 0xf03e << 0xf247;
    btnsMain << ui->tbtnMain1 << ui->tbtnMain2 << ui->tbtnMain3;

    int count = btnsMain.count();
    for (int i = 0; i < count; i++) {
        btnsMain.at(i)->setCheckable(true);
        btnsMain.at(i)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btnsMain.at(i), SIGNAL(clicked(bool)), this, SLOT(leftMainClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftMain, btnsMain, pixCharMain, 15, 35, 25, "left", 4);

    ui->tbtnMain3->click();
}

void UIMainWindows::initLeftConfig()
{
    pixCharConfig << 0xf031  << 0xf249 << 0xf055 << 0xf05a << 0xf249;
    btnsConfig << ui->tbtnConfig1 << ui->tbtnConfig3 << ui->tbtnConfig4 << ui->tbtnConfig5 << ui->tbtnConfig6;

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        btnsConfig.at(i)->setCheckable(true);
        btnsConfig.at(i)->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btnsConfig.at(i), SIGNAL(clicked(bool)), this, SLOT(leftConfigClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftConfig, btnsConfig, pixCharConfig, 10, 20, 15, "left", 5);

    ui->tbtnConfig4->click();
}

//主界面
void UIMainWindows::leftMainClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsMain.count();
    for (int i = 0; i < count; i++) {
        if (btnsMain.at(i) == b) {
            btnsMain.at(i)->setChecked(true);
            btnsMain.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsMain.at(i), false)));
        } else {
            btnsMain.at(i)->setChecked(false);
            btnsMain.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsMain.at(i), true)));
        }
    }

    //界面切换
    if(name  == "开局"){
        //控制游戏界面
        ui->mainStackedWidget->setCurrentIndex(0);
    }else if(name == "停止"){
         ui->mainStackedWidget->setCurrentIndex(1);
    }else if(name == "保存"){
         ui->mainStackedWidget->setCurrentIndex(2);
    }else if(name == "加载"){
        ui->mainStackedWidget->setCurrentIndex(3);
    }

}
//设置界面
void UIMainWindows::leftConfigClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        if (btnsConfig.at(i) == b) {
            btnsConfig.at(i)->setChecked(true);
            btnsConfig.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsConfig.at(i), false)));
        } else {
            btnsConfig.at(i)->setChecked(false);
            btnsConfig.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsConfig.at(i), true)));
        }
    }
    //设置界面
    if(name == "用户"){
        ui->settingStackedWidget->setCurrentIndex(0);
    }else if(name == "设备"){
        ui->settingStackedWidget->setCurrentIndex(1);
    }else if(name == "规则"){
        ui->settingStackedWidget->setCurrentIndex(2);
    }else if(name == "主题"){
         ui->settingStackedWidget->setCurrentIndex(3);
    }else if(name == "其他"){
          ui->settingStackedWidget->setCurrentIndex(4);
    }

}

void UIMainWindows::initTrayIcon()
{
    //判断系统是否支持托盘图标显示
    if(!QSystemTrayIcon::isSystemTrayAvailable())
     {
            return;
     }
    //实例化托盘图标控件
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/image/main_menu.png"));  //设置托盘图标显示
    trayIcon->setToolTip("Calculator"); //显示提示信息

    //创建托盘菜单
    trayShowMainAction = new QAction(tr("显示主界面"),this);
    trayExitAppAction = new QAction(tr("退出"),this);
    trayMenu = new QMenu(this);
    trayMenu ->addAction(trayShowMainAction);//添加事件
    trayMenu ->addSeparator();//添加分割线
    trayMenu ->addAction(trayExitAppAction);
    trayIcon->setContextMenu(trayMenu );//托盘添加菜单

}

void UIMainWindows::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
        switch (reason)
        {
        case QSystemTrayIcon::Trigger:
            trayIcon->showMessage(tr("麻将2023"),
                                      tr("欢迎使用此程序！"),
                                      QSystemTrayIcon::Information,
                                      700);
            break;
        case QSystemTrayIcon::DoubleClick:
            this->show();
            break;
        default:
            break;
        }
}

//最小化按钮
void UIMainWindows::on_btnMenu_Min_clicked()
{
    this->hide();
    trayIcon->show();
    trayIcon->showMessage("通知", "软件已隐藏到菜单栏！", QSystemTrayIcon::Information, 700);//最后一个参数为提示时长，默认10000，即10s
}

//最大化按钮
void UIMainWindows::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
       // ui->label000->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        //ui->label000->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void UIMainWindows::on_btnMenu_Close_clicked()
{
    close();
}

//显示 南 牌墙
void UIMainWindows::initSouthDrawDisplay(const vector<Mj>& mjs, int zhangshu) const
{
    QString imgPath = ":/image/";
    QString imgFile = ".png";
    int cnt = 0;
    int ceng = zhangshu/2;

    int cntNumber = 0;
    for(;cntNumber < ceng; cntNumber++){
        if(cntNumber == 0){
            ui->drawSouthNumber1_1->setText(tr("1"));
        }else if(cntNumber == 1){
            ui->drawSouthNumber1_2->setText(tr("2"));
        }else if(cntNumber == 2){
            ui->drawSouthNumber1_3->setText(tr("3"));
        }else if(cntNumber == 3){
            ui->drawSouthNumber1_4->setText(tr("4"));
        }else if(cntNumber == 4){
            ui->drawSouthNumber1_5->setText(tr("5"));
        }else if(cntNumber == 5){
            ui->drawSouthNumber1_6->setText(tr("6"));
        }else if(cntNumber == 6){
            ui->drawSouthNumber1_7->setText(tr("7"));
        }else if(cntNumber == 7){
            ui->drawSouthNumber1_8->setText(tr("8"));
        }else if(cntNumber == 8){
            ui->drawSouthNumber1_9->setText(tr("9"));
        }else if(cntNumber == 9){
            ui->drawSouthNumber1_10->setText(tr("10"));
        }else if(cntNumber == 10){
            ui->drawSouthNumber1_11->setText(tr("11"));
        }else if(cntNumber == 11){
            ui->drawSouthNumber1_12->setText(tr("12"));
        }else if(cntNumber == 12){
            ui->drawSouthNumber1_13->setText(tr("13"));
        }else if(cntNumber == 13){
            ui->drawSouthNumber1_14->setText(tr("14"));
        }else if(cntNumber == 14){
            ui->drawSouthNumber1_15->setText(tr("15"));
        }else if(cntNumber == 15){
            ui->drawSouthNumber1_16->setText(tr("16"));
        }else if(cntNumber == 16){
            ui->drawSouthNumber1_17->setText(tr("17"));
        }
    }

    for(auto i: mjs){
        int number = i.getResult();
        QString res = QString::number(number);
        if (systemConfig.isPrediction==false)
            //ccccc设置牌背面
            res="0";

        if(cnt % ceng == 0){
            if(cnt < ceng){
                QPixmap drawSouthMj1_1(imgPath + res + imgFile);
                 drawSouthMj1_1.scaled(ui->drawSouth1_1->size(), Qt::IgnoreAspectRatio);
                  ui->drawSouth1_1->setScaledContents(true);
                  ui->drawSouth1_1->setPixmap(drawSouthMj1_1);
            }else{
                QPixmap drawSouthMj2_1(imgPath + res + imgFile);
                drawSouthMj2_1.scaled(ui->drawSouth2_1->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_1->setScaledContents(true);
                ui->drawSouth2_1->setPixmap(drawSouthMj2_1);
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                QPixmap drawSouthMj1_2(imgPath + res + imgFile);
                drawSouthMj1_2.scaled(ui->drawSouth1_2->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_2->setScaledContents(true);
                ui->drawSouth1_2->setPixmap(drawSouthMj1_2);
            }else{
                QPixmap drawSouthMj2_2(imgPath + res + imgFile);
                drawSouthMj2_2.scaled(ui->drawSouth2_2->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_2->setScaledContents(true);
                ui->drawSouth2_2->setPixmap(drawSouthMj2_2);
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                QPixmap drawSouthMj1_3(imgPath + res + imgFile);
                drawSouthMj1_3.scaled(ui->drawSouth1_3->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_3->setScaledContents(true);
                ui->drawSouth1_3->setPixmap(drawSouthMj1_3);
            }else{
                QPixmap drawSouthMj2_3(imgPath + res + imgFile);
                drawSouthMj2_3.scaled(ui->drawSouth2_3->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_3->setScaledContents(true);
                ui->drawSouth2_3->setPixmap(drawSouthMj2_3);
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                QPixmap drawSouthMj1_4(imgPath + res + imgFile);
                drawSouthMj1_4.scaled(ui->drawSouth1_4->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_4->setScaledContents(true);
                ui->drawSouth1_4->setPixmap(drawSouthMj1_4);
            }else{
                QPixmap drawSouthMj2_4(imgPath + res + imgFile);
                drawSouthMj2_4.scaled(ui->drawSouth2_4->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_4->setScaledContents(true);
                ui->drawSouth2_4->setPixmap(drawSouthMj2_4);
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                QPixmap drawSouthMj1_5(imgPath + res + imgFile);
                drawSouthMj1_5.scaled(ui->drawSouth1_5->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_5->setScaledContents(true);
                ui->drawSouth1_5->setPixmap(drawSouthMj1_5);
            }else{
                QPixmap drawSouthMj2_5(imgPath + res + imgFile);
                drawSouthMj2_5.scaled(ui->drawSouth2_5->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_5->setScaledContents(true);
                ui->drawSouth2_5->setPixmap(drawSouthMj2_5);
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                QPixmap drawSouthMj1_6(imgPath + res + imgFile);
                drawSouthMj1_6.scaled(ui->drawSouth1_6->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_6->setScaledContents(true);
                ui->drawSouth1_6->setPixmap(drawSouthMj1_6);
            }else{
                QPixmap drawSouthMj2_6(imgPath + res + imgFile);
                drawSouthMj2_6.scaled(ui->drawSouth2_6->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_6->setScaledContents(true);
                ui->drawSouth2_6->setPixmap(drawSouthMj2_6);
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                QPixmap drawSouthMj1_7(imgPath + res + imgFile);
                drawSouthMj1_7.scaled(ui->drawSouth1_7->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_7->setScaledContents(true);
                ui->drawSouth1_7->setPixmap(drawSouthMj1_7);
            }else{
                QPixmap drawSouthMj2_7(imgPath + res + imgFile);
                drawSouthMj2_7.scaled(ui->drawSouth2_7->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_7->setScaledContents(true);
                ui->drawSouth2_7->setPixmap(drawSouthMj2_7);
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                QPixmap drawSouthMj1_8(imgPath + res + imgFile);
                drawSouthMj1_8.scaled(ui->drawSouth1_8->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_8->setScaledContents(true);
                ui->drawSouth1_8->setPixmap(drawSouthMj1_8);
            }else{
                QPixmap drawSouthMj2_8(imgPath + res + imgFile);
                drawSouthMj2_8.scaled(ui->drawSouth2_8->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_8->setScaledContents(true);
                ui->drawSouth2_8->setPixmap(drawSouthMj2_8);
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                QPixmap drawSouthMj1_9(imgPath + res + imgFile);
                drawSouthMj1_9.scaled(ui->drawSouth1_9->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_9->setScaledContents(true);
                ui->drawSouth1_9->setPixmap(drawSouthMj1_9);
            }else{
                QPixmap drawSouthMj2_9(imgPath + res + imgFile);
                drawSouthMj2_9.scaled(ui->drawSouth2_9->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_9->setScaledContents(true);
                ui->drawSouth2_9->setPixmap(drawSouthMj2_9);
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                QPixmap drawSouthMj1_10(imgPath + res + imgFile);
                drawSouthMj1_10.scaled(ui->drawSouth1_10->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_10->setScaledContents(true);
                ui->drawSouth1_10->setPixmap(drawSouthMj1_10);
            }else{
                QPixmap drawSouthMj2_10(imgPath + res + imgFile);
                drawSouthMj2_10.scaled(ui->drawSouth2_10->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_10->setScaledContents(true);
                ui->drawSouth2_10->setPixmap(drawSouthMj2_10);
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                QPixmap drawSouthMj1_11(imgPath + res + imgFile);
                drawSouthMj1_11.scaled(ui->drawSouth1_11->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_11->setScaledContents(true);
                ui->drawSouth1_11->setPixmap(drawSouthMj1_11);
            }else{
                QPixmap drawSouthMj2_11(imgPath + res + imgFile);
                drawSouthMj2_11.scaled(ui->drawSouth2_11->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_11->setScaledContents(true);
                ui->drawSouth2_11->setPixmap(drawSouthMj2_11);
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                QPixmap drawSouthMj1_12(imgPath + res + imgFile);
                drawSouthMj1_12.scaled(ui->drawSouth1_12->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_12->setScaledContents(true);
                ui->drawSouth1_12->setPixmap(drawSouthMj1_12);
            }else{
                QPixmap drawSouthMj2_12(imgPath + res + imgFile);
                drawSouthMj2_12.scaled(ui->drawSouth2_12->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_12->setScaledContents(true);
                ui->drawSouth2_12->setPixmap(drawSouthMj2_12);
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                QPixmap drawSouthMj1_13(imgPath + res + imgFile);
                drawSouthMj1_13.scaled(ui->drawSouth1_13->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_13->setScaledContents(true);
                ui->drawSouth1_13->setPixmap(drawSouthMj1_13);
            }else{
                QPixmap drawSouthMj2_13(imgPath + res + imgFile);
                drawSouthMj2_13.scaled(ui->drawSouth2_13->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_13->setScaledContents(true);
                ui->drawSouth2_13->setPixmap(drawSouthMj2_13);
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                QPixmap drawSouthMj1_14(imgPath + res + imgFile);
                drawSouthMj1_14.scaled(ui->drawSouth1_14->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_14->setScaledContents(true);
                ui->drawSouth1_14->setPixmap(drawSouthMj1_14);
            }else{
                QPixmap drawSouthMj2_14(imgPath + res + imgFile);
                drawSouthMj2_14.scaled(ui->drawSouth2_14->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_14->setScaledContents(true);
                ui->drawSouth2_14->setPixmap(drawSouthMj2_14);
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                QPixmap drawSouthMj1_15(imgPath + res + imgFile);
                drawSouthMj1_15.scaled(ui->drawSouth1_15->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_15->setScaledContents(true);
                ui->drawSouth1_15->setPixmap(drawSouthMj1_15);
            }else{
                QPixmap drawSouthMj2_15(imgPath + res + imgFile);
                drawSouthMj2_15.scaled(ui->drawSouth2_15->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_15->setScaledContents(true);
                ui->drawSouth2_15->setPixmap(drawSouthMj2_15);
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                QPixmap drawSouthMj1_16(imgPath + res + imgFile);
                drawSouthMj1_16.scaled(ui->drawSouth1_16->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_16->setScaledContents(true);
                ui->drawSouth1_16->setPixmap(drawSouthMj1_16);
            }else{
                QPixmap drawSouthMj2_16(imgPath + res + imgFile);
                drawSouthMj2_16.scaled(ui->drawSouth2_16->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_16->setScaledContents(true);
                ui->drawSouth2_16->setPixmap(drawSouthMj2_16);
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                QPixmap drawSouthMj1_17(imgPath + res + imgFile);
                drawSouthMj1_17.scaled(ui->drawSouth1_17->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth1_17->setScaledContents(true);
                ui->drawSouth1_17->setPixmap(drawSouthMj1_17);
            }else{
                QPixmap drawSouthMj2_17(imgPath + res + imgFile);
                drawSouthMj2_17.scaled(ui->drawSouth2_17->size(), Qt::IgnoreAspectRatio);
                ui->drawSouth2_17->setScaledContents(true);
                ui->drawSouth2_17->setPixmap(drawSouthMj2_17);
            }
        }
        cnt++;
    }

}
//显示 西 牌墙
void UIMainWindows::initWestDrawDisplay(const vector<Mj>& mjs, int zhangshu ) const
{
    QString imgPath = ":/image/l";
    QString imgFile = ".png";
    int cnt = 0;
    int ceng = zhangshu/2;

    int cntNumber = 0;
    for(;cntNumber < ceng; cntNumber++){
        if(cntNumber == 0){
            ui->drawWestNumber1->setText(tr("1"));
        }else if(cntNumber == 1){
            ui->drawWestNumber2->setText(tr("2"));
        }else if(cntNumber == 2){
            ui->drawWestNumber3->setText(tr("3"));
        }else if(cntNumber == 3){
            ui->drawWestNumber4->setText(tr("4"));
        }else if(cntNumber == 4){
            ui->drawWestNumber5->setText(tr("5"));
        }else if(cntNumber == 5){
            ui->drawWestNumber6->setText(tr("6"));
        }else if(cntNumber == 6){
            ui->drawWestNumber7->setText(tr("7"));
        }else if(cntNumber == 7){
            ui->drawWestNumber8->setText(tr("8"));
        }else if(cntNumber == 8){
            ui->drawWestNumber9->setText(tr("9"));
        }else if(cntNumber == 9){
            ui->drawWestNumber10->setText(tr("10"));
        }else if(cntNumber == 10){
            ui->drawWestNumber11->setText(tr("11"));
        }else if(cntNumber == 11){
            ui->drawWestNumber12->setText(tr("12"));
        }else if(cntNumber == 12){
            ui->drawWestNumber13->setText(tr("13"));
        }else if(cntNumber == 13){
            ui->drawWestNumber14->setText(tr("14"));
        }else if(cntNumber == 14){
            ui->drawWestNumber15->setText(tr("15"));
        }else if(cntNumber == 15){
            ui->drawWestNumber16->setText(tr("16"));
        }else if(cntNumber == 16){
            ui->drawWestNumber17->setText(tr("17"));
        }
    }

    for(auto i: mjs){
        int number = i.getResult();
        QString res = QString::number(number);
        if (systemConfig.isPrediction==false)
            res="0";


        if(cnt % ceng == 0){
            if(cnt < ceng){
                QPixmap drawWestMj1_1(imgPath + res + imgFile);
                drawWestMj1_1.scaled(ui->drawWest1_1->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_1->setScaledContents(true);
                ui->drawWest1_1->setPixmap(drawWestMj1_1);
            }else{
                QPixmap drawWestMj2_1(imgPath + res + imgFile);
                drawWestMj2_1.scaled(ui->drawWest2_1->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_1->setScaledContents(true);
                ui->drawWest2_1->setPixmap(drawWestMj2_1);
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                QPixmap drawWestMj1_2(imgPath + res + imgFile);
                drawWestMj1_2.scaled(ui->drawWest1_2->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_2->setScaledContents(true);
                ui->drawWest1_2->setPixmap(drawWestMj1_2);
            }else{
                QPixmap drawWestMj2_2(imgPath + res + imgFile);
                drawWestMj2_2.scaled(ui->drawWest2_2->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_2->setScaledContents(true);
                ui->drawWest2_2->setPixmap(drawWestMj2_2);
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                QPixmap drawWestMj1_3(imgPath + res + imgFile);
                drawWestMj1_3.scaled(ui->drawWest1_3->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_3->setScaledContents(true);
                ui->drawWest1_3->setPixmap(drawWestMj1_3);
            }else{
                QPixmap drawWestMj2_3(imgPath + res + imgFile);
                drawWestMj2_3.scaled(ui->drawWest2_3->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_3->setScaledContents(true);
                ui->drawWest2_3->setPixmap(drawWestMj2_3);
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                QPixmap drawWestMj1_4(imgPath + res + imgFile);
                drawWestMj1_4.scaled(ui->drawWest1_4->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_4->setScaledContents(true);
                ui->drawWest1_4->setPixmap(drawWestMj1_4);
            }else{
                QPixmap drawWestMj2_4(imgPath + res + imgFile);
                drawWestMj2_4.scaled(ui->drawWest2_4->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_4->setScaledContents(true);
                ui->drawWest2_4->setPixmap(drawWestMj2_4);
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                QPixmap drawWestMj1_5(imgPath + res + imgFile);
                drawWestMj1_5.scaled(ui->drawWest1_5->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_5->setScaledContents(true);
                ui->drawWest1_5->setPixmap(drawWestMj1_5);
            }else{
                QPixmap drawWestMj2_5(imgPath + res + imgFile);
                drawWestMj2_5.scaled(ui->drawWest2_5->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_5->setScaledContents(true);
                ui->drawWest2_5->setPixmap(drawWestMj2_5);
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                QPixmap drawWestMj1_6(imgPath + res + imgFile);
                drawWestMj1_6.scaled(ui->drawWest1_6->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_6->setScaledContents(true);
                ui->drawWest1_6->setPixmap(drawWestMj1_6);
            }else{
                QPixmap drawWestMj2_6(imgPath + res + imgFile);
                drawWestMj2_6.scaled(ui->drawWest2_6->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_6->setScaledContents(true);
                ui->drawWest2_6->setPixmap(drawWestMj2_6);
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                QPixmap drawWestMj1_7(imgPath + res + imgFile);
                drawWestMj1_7.scaled(ui->drawWest1_7->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_7->setScaledContents(true);
                ui->drawWest1_7->setPixmap(drawWestMj1_7);
            }else{
                QPixmap drawWestMj2_7(imgPath + res + imgFile);
                drawWestMj2_7.scaled(ui->drawWest2_7->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_7->setScaledContents(true);
                ui->drawWest2_7->setPixmap(drawWestMj2_7);
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                QPixmap drawWestMj1_8(imgPath + res + imgFile);
                drawWestMj1_8.scaled(ui->drawWest1_8->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_8->setScaledContents(true);
                ui->drawWest1_8->setPixmap(drawWestMj1_8);
            }else{
                QPixmap drawWestMj2_8(imgPath + res + imgFile);
                drawWestMj2_8.scaled(ui->drawWest2_8->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_8->setScaledContents(true);
                ui->drawWest2_8->setPixmap(drawWestMj2_8);
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                QPixmap drawWestMj1_9(imgPath + res + imgFile);
                drawWestMj1_9.scaled(ui->drawWest1_9->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_9->setScaledContents(true);
                ui->drawWest1_9->setPixmap(drawWestMj1_9);
            }else{
                QPixmap drawWestMj2_9(imgPath + res + imgFile);
                drawWestMj2_9.scaled(ui->drawWest2_9->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_9->setScaledContents(true);
                ui->drawWest2_9->setPixmap(drawWestMj2_9);
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                QPixmap drawWestMj1_10(imgPath + res + imgFile);
                drawWestMj1_10.scaled(ui->drawWest1_10->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_10->setScaledContents(true);
                ui->drawWest1_10->setPixmap(drawWestMj1_10);
            }else{
                QPixmap drawWestMj2_10(imgPath + res + imgFile);
                drawWestMj2_10.scaled(ui->drawWest2_10->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_10->setScaledContents(true);
                ui->drawWest2_10->setPixmap(drawWestMj2_10);
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                QPixmap drawWestMj1_11(imgPath + res + imgFile);
                drawWestMj1_11.scaled(ui->drawWest1_11->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_11->setScaledContents(true);
                ui->drawWest1_11->setPixmap(drawWestMj1_11);
            }else{
                QPixmap drawWestMj2_11(imgPath + res + imgFile);
                drawWestMj2_11.scaled(ui->drawWest2_11->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_11->setScaledContents(true);
                ui->drawWest2_11->setPixmap(drawWestMj2_11);
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                QPixmap drawWestMj1_12(imgPath + res + imgFile);
                drawWestMj1_12.scaled(ui->drawWest1_12->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_12->setScaledContents(true);
                ui->drawWest1_12->setPixmap(drawWestMj1_12);
            }else{
                QPixmap drawWestMj2_12(imgPath + res + imgFile);
                drawWestMj2_12.scaled(ui->drawWest2_12->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_12->setScaledContents(true);
                ui->drawWest2_12->setPixmap(drawWestMj2_12);
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                QPixmap drawWestMj1_13(imgPath + res + imgFile);
                drawWestMj1_13.scaled(ui->drawWest1_13->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_13->setScaledContents(true);
                ui->drawWest1_13->setPixmap(drawWestMj1_13);
            }else{
                QPixmap drawWestMj2_13(imgPath + res + imgFile);
                drawWestMj2_13.scaled(ui->drawWest2_13->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_13->setScaledContents(true);
                ui->drawWest2_13->setPixmap(drawWestMj2_13);
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                QPixmap drawWestMj1_14(imgPath + res + imgFile);
                drawWestMj1_14.scaled(ui->drawWest1_14->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_14->setScaledContents(true);
                ui->drawWest1_14->setPixmap(drawWestMj1_14);
            }else{
                QPixmap drawWestMj2_14(imgPath + res + imgFile);
                drawWestMj2_14.scaled(ui->drawWest2_14->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_14->setScaledContents(true);
                ui->drawWest2_14->setPixmap(drawWestMj2_14);
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                QPixmap drawWestMj1_15(imgPath + res + imgFile);
                drawWestMj1_15.scaled(ui->drawWest1_15->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_15->setScaledContents(true);
                ui->drawWest1_15->setPixmap(drawWestMj1_15);
            }else{
                QPixmap drawWestMj2_15(imgPath + res + imgFile);
                drawWestMj2_15.scaled(ui->drawWest2_15->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_15->setScaledContents(true);
                ui->drawWest2_15->setPixmap(drawWestMj2_15);
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                QPixmap drawWestMj1_16(imgPath + res + imgFile);
                drawWestMj1_16.scaled(ui->drawWest1_16->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_16->setScaledContents(true);
                ui->drawWest1_16->setPixmap(drawWestMj1_16);
            }else{
                QPixmap drawWestMj2_16(imgPath + res + imgFile);
                drawWestMj2_16.scaled(ui->drawWest2_16->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_16->setScaledContents(true);
                ui->drawWest2_16->setPixmap(drawWestMj2_16);
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                QPixmap drawWestMj1_17(imgPath + res + imgFile);
                drawWestMj1_17.scaled(ui->drawWest1_17->size(), Qt::IgnoreAspectRatio);
                ui->drawWest1_17->setScaledContents(true);
                ui->drawWest1_17->setPixmap(drawWestMj1_17);
            }else{
                QPixmap drawWestMj2_17(imgPath + res + imgFile);
                drawWestMj2_17.scaled(ui->drawWest2_17->size(), Qt::IgnoreAspectRatio);
                ui->drawWest2_17->setScaledContents(true);
                ui->drawWest2_17->setPixmap(drawWestMj2_17);
            }
        }
            cnt++;
    }

}
//显示 北 牌墙
void UIMainWindows::initNorthDrawDisplay(const vector<Mj>& mjs, int zhangshu ) const
{
    QString imgPath = ":/image/";
    QString imgFile = ".png";
    int cnt = 0;
    int ceng = zhangshu/2;

    int cntNumber = 0;
    for(;cntNumber < ceng; cntNumber++){
        if(cntNumber == 0){
            ui->drawNorthNumber1_1->setText(tr("1"));
        }else if(cntNumber == 1){
            ui->drawNorthNumber1_2->setText(tr("2"));
        }else if(cntNumber == 2){
            ui->drawNorthNumber1_3->setText(tr("3"));
        }else if(cntNumber == 3){
            ui->drawNorthNumber1_4->setText(tr("4"));
        }else if(cntNumber == 4){
            ui->drawNorthNumber1_5->setText(tr("5"));
        }else if(cntNumber == 5){
            ui->drawNorthNumber1_6->setText(tr("6"));
        }else if(cntNumber == 6){
            ui->drawNorthNumber1_7->setText(tr("7"));
        }else if(cntNumber == 7){
            ui->drawNorthNumber1_8->setText(tr("8"));
        }else if(cntNumber == 8){
            ui->drawNorthNumber1_9->setText(tr("9"));
        }else if(cntNumber == 9){
            ui->drawNorthNumber1_10->setText(tr("10"));
        }else if(cntNumber == 10){
            ui->drawNorthNumber1_11->setText(tr("11"));
        }else if(cntNumber == 11){
            ui->drawNorthNumber1_12->setText(tr("12"));
        }else if(cntNumber == 12){
            ui->drawNorthNumber1_13->setText(tr("13"));
        }else if(cntNumber == 13){
            ui->drawNorthNumber1_14->setText(tr("14"));
        }else if(cntNumber == 14){
            ui->drawNorthNumber1_15->setText(tr("15"));
        }else if(cntNumber == 15){
            ui->drawNorthNumber1_16->setText(tr("16"));
        }else if(cntNumber == 16){
            ui->drawNorthNumber1_17->setText(tr("17"));
        }
    }

    for(auto i: mjs){
        int number = i.getResult();
        QString res = QString::number(number);
        if (systemConfig.isPrediction==false)
            res="0";

        if(cnt % ceng == 0){
            if(cnt < ceng){
                QPixmap drawNorthMj1_1(imgPath + res + imgFile);
                 drawNorthMj1_1.scaled(ui->drawNorth1_1->size(), Qt::IgnoreAspectRatio);
                 ui->drawNorth1_1->setScaledContents(true);
                 ui->drawNorth1_1->setPixmap(drawNorthMj1_1);
            }else{
                QPixmap drawNorthMj2_1(imgPath + res + imgFile);
                drawNorthMj2_1.scaled(ui->drawNorth2_1->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_1->setScaledContents(true);
                ui->drawNorth2_1->setPixmap(drawNorthMj2_1);
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                QPixmap drawNorthMj1_2(imgPath + res + imgFile);
                 drawNorthMj1_2.scaled(ui->drawNorth1_2->size(), Qt::IgnoreAspectRatio);
                 ui->drawNorth1_2->setScaledContents(true);
                 ui->drawNorth1_2->setPixmap(drawNorthMj1_2);
            }else{
                QPixmap drawNorthMj2_2(imgPath + res + imgFile);
                drawNorthMj2_2.scaled(ui->drawNorth2_2->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_2->setScaledContents(true);
                ui->drawNorth2_2->setPixmap(drawNorthMj2_2);
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                QPixmap drawNorthMj1_3(imgPath + res + imgFile);
                drawNorthMj1_3.scaled(ui->drawNorth1_3->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_3->setScaledContents(true);
                ui->drawNorth1_3->setPixmap(drawNorthMj1_3);
            }else{
                QPixmap drawNorthMj2_3(imgPath + res + imgFile);
                drawNorthMj2_3.scaled(ui->drawNorth2_3->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_3->setScaledContents(true);
                ui->drawNorth2_3->setPixmap(drawNorthMj2_3);
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                QPixmap drawNorthMj1_4(imgPath + res + imgFile);
                drawNorthMj1_4.scaled(ui->drawNorth1_4->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_4->setScaledContents(true);
                ui->drawNorth1_4->setPixmap(drawNorthMj1_4);
            }else{
                QPixmap drawNorthMj2_4(imgPath + res + imgFile);
                drawNorthMj2_4.scaled(ui->drawNorth2_4->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_4->setScaledContents(true);
                ui->drawNorth2_4->setPixmap(drawNorthMj2_4);
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                QPixmap drawNorthMj1_5(imgPath + res + imgFile);
                  drawNorthMj1_5.scaled(ui->drawNorth1_5->size(), Qt::IgnoreAspectRatio);
                  ui->drawNorth1_5->setScaledContents(true);
                  ui->drawNorth1_5->setPixmap(drawNorthMj1_5);
            }else{
                QPixmap drawNorthMj2_5(imgPath + res + imgFile);
                drawNorthMj2_5.scaled(ui->drawNorth2_5->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_5->setScaledContents(true);
                ui->drawNorth2_5->setPixmap(drawNorthMj2_5);
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                QPixmap drawNorthMj1_6(imgPath + res + imgFile);
                 drawNorthMj1_6.scaled(ui->drawNorth1_6->size(), Qt::IgnoreAspectRatio);
                 ui->drawNorth1_6->setScaledContents(true);
                 ui->drawNorth1_6->setPixmap(drawNorthMj1_6);
            }else{
                QPixmap drawNorthMj2_6(imgPath + res + imgFile);
                drawNorthMj2_6.scaled(ui->drawNorth2_6->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_6->setScaledContents(true);
                ui->drawNorth2_6->setPixmap(drawNorthMj2_6);
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                QPixmap drawNorthMj1_7(imgPath + res + imgFile);
                drawNorthMj1_7.scaled(ui->drawNorth1_7->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_7->setScaledContents(true);
                ui->drawNorth1_7->setPixmap(drawNorthMj1_7);
            }else{
                QPixmap drawNorthMj2_7(imgPath + res + imgFile);
                drawNorthMj2_7.scaled(ui->drawNorth2_7->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_7->setScaledContents(true);
                ui->drawNorth2_7->setPixmap(drawNorthMj2_7);
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                QPixmap drawNorthMj1_8(imgPath + res + imgFile);
                drawNorthMj1_8.scaled(ui->drawNorth1_8->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_8->setScaledContents(true);
                ui->drawNorth1_8->setPixmap(drawNorthMj1_8);
            }else{
                QPixmap drawNorthMj2_8(imgPath + res + imgFile);
                  drawNorthMj2_8.scaled(ui->drawNorth2_8->size(), Qt::IgnoreAspectRatio);
                  ui->drawNorth2_8->setScaledContents(true);
                  ui->drawNorth2_8->setPixmap(drawNorthMj2_8);
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                QPixmap drawNorthMj1_9(imgPath + res + imgFile);
                drawNorthMj1_9.scaled(ui->drawNorth1_9->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_9->setScaledContents(true);
                ui->drawNorth1_9->setPixmap(drawNorthMj1_9);
            }else{
                QPixmap drawNorthMj2_9(imgPath + res + imgFile);
                drawNorthMj2_9.scaled(ui->drawNorth2_9->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_9->setScaledContents(true);
                ui->drawNorth2_9->setPixmap(drawNorthMj2_9);
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                QPixmap drawNorthMj1_10(imgPath + res + imgFile);
                drawNorthMj1_10.scaled(ui->drawNorth1_10->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_10->setScaledContents(true);
                ui->drawNorth1_10->setPixmap(drawNorthMj1_10);
            }else{
                QPixmap drawNorthMj2_10(imgPath + res + imgFile);
                drawNorthMj2_10.scaled(ui->drawNorth2_10->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_10->setScaledContents(true);
                ui->drawNorth2_10->setPixmap(drawNorthMj2_10);
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                QPixmap drawNorthMj1_11(imgPath + res + imgFile);
                drawNorthMj1_11.scaled(ui->drawNorth1_11->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_11->setScaledContents(true);
                ui->drawNorth1_11->setPixmap(drawNorthMj1_11);
            }else{
                QPixmap drawNorthMj2_11(imgPath + res + imgFile);
                    drawNorthMj2_11.scaled(ui->drawNorth2_11->size(), Qt::IgnoreAspectRatio);
                    ui->drawNorth2_11->setScaledContents(true);
                    ui->drawNorth2_11->setPixmap(drawNorthMj2_11);
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                QPixmap drawNorthMj1_12(imgPath + res + imgFile);
                drawNorthMj1_12.scaled(ui->drawNorth1_12->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_12->setScaledContents(true);
                ui->drawNorth1_12->setPixmap(drawNorthMj1_12);
            }else{
                QPixmap drawNorthMj2_12(imgPath + res + imgFile);
                drawNorthMj2_12.scaled(ui->drawNorth2_12->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_12->setScaledContents(true);
                ui->drawNorth2_12->setPixmap(drawNorthMj2_12);
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                QPixmap drawNorthMj1_13(imgPath + res + imgFile);
                drawNorthMj1_13.scaled(ui->drawNorth1_13->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_13->setScaledContents(true);
                ui->drawNorth1_13->setPixmap(drawNorthMj1_13);
            }else{
                QPixmap drawNorthMj2_13(imgPath + res + imgFile);
                drawNorthMj2_13.scaled(ui->drawNorth2_13->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_13->setScaledContents(true);
                ui->drawNorth2_13->setPixmap(drawNorthMj2_13);
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                QPixmap drawNorthMj1_14(imgPath + res + imgFile);
                drawNorthMj1_14.scaled(ui->drawNorth1_14->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_14->setScaledContents(true);
                ui->drawNorth1_14->setPixmap(drawNorthMj1_14);
            }else{
                QPixmap drawNorthMj2_14(imgPath + res + imgFile);
                drawNorthMj2_14.scaled(ui->drawNorth2_14->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_14->setScaledContents(true);
                ui->drawNorth2_14->setPixmap(drawNorthMj2_14);
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                QPixmap drawNorthMj1_15(imgPath + res + imgFile);
                drawNorthMj1_15.scaled(ui->drawNorth1_15->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_15->setScaledContents(true);
                ui->drawNorth1_15->setPixmap(drawNorthMj1_15);
            }else{
                QPixmap drawNorthMj2_15(imgPath + res + imgFile);
                drawNorthMj2_15.scaled(ui->drawNorth2_15->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_15->setScaledContents(true);
                ui->drawNorth2_15->setPixmap(drawNorthMj2_15);
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                QPixmap drawNorthMj1_16(imgPath + res + imgFile);
                drawNorthMj1_16.scaled(ui->drawNorth1_16->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_16->setScaledContents(true);
                ui->drawNorth1_16->setPixmap(drawNorthMj1_16);
            }else{
                QPixmap drawNorthMj2_16(imgPath + res + imgFile);
                drawNorthMj2_16.scaled(ui->drawNorth2_16->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_16->setScaledContents(true);
                ui->drawNorth2_16->setPixmap(drawNorthMj2_16);
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                QPixmap drawNorthMj1_17(imgPath + res + imgFile);
                drawNorthMj1_17.scaled(ui->drawNorth1_17->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth1_17->setScaledContents(true);
                ui->drawNorth1_17->setPixmap(drawNorthMj1_17);
            }else{
                QPixmap drawNorthMj2_17(imgPath + res + imgFile);
                drawNorthMj2_17.scaled(ui->drawNorth2_17->size(), Qt::IgnoreAspectRatio);
                ui->drawNorth2_17->setScaledContents(true);
                ui->drawNorth2_17->setPixmap(drawNorthMj2_17);
            }
        }

        cnt++;
    }

}
//显示 东 牌墙
void UIMainWindows::initEastDrawDisplay(const vector<Mj>& mjs, int zhangshu) const
{


    QString imgPath = ":/image/r";
    QString imgFile = ".png";
    int cnt = 0;
    int ceng = zhangshu/2;
    //显示文字
    int cntNumber = 0;
    for(;cntNumber < ceng; cntNumber++){
        if(cntNumber == 0){
            ui->drawEastNumber1_1->setText(tr("1"));
        }else if(cntNumber == 1){
            ui->drawEastNumber1_2->setText(tr("2"));
        }else if(cntNumber == 2){
            ui->drawEastNumber1_3->setText(tr("3"));
        }else if(cntNumber == 3){
            ui->drawEastNumber1_4->setText(tr("4"));
        }else if(cntNumber == 4){
            ui->drawEastNumber1_5->setText(tr("5"));
        }else if(cntNumber == 5){
            ui->drawEastNumber1_6->setText(tr("6"));
        }else if(cntNumber == 6){
            ui->drawEastNumber1_7->setText(tr("7"));
        }else if(cntNumber == 7){
            ui->drawEastNumber1_8->setText(tr("8"));
        }else if(cntNumber == 8){
            ui->drawEastNumber1_9->setText(tr("9"));
        }else if(cntNumber == 9){
            ui->drawEastNumber1_10->setText(tr("10"));
        }else if(cntNumber == 10){
            ui->drawEastNumber1_11->setText(tr("11"));
        }else if(cntNumber == 11){
            ui->drawEastNumber1_12->setText(tr("12"));
        }else if(cntNumber == 12){
            ui->drawEastNumber1_13->setText(tr("13"));
        }else if(cntNumber == 13){
            ui->drawEastNumber1_14->setText(tr("14"));
        }else if(cntNumber == 14){
            ui->drawEastNumber1_15->setText(tr("15"));
        }else if(cntNumber == 15){
            ui->drawEastNumber1_16->setText(tr("16"));
        }else if(cntNumber == 16){
            ui->drawEastNumber1_17->setText(tr("17"));
        }
    }

    for(auto i: mjs){
        int number = i.getResult();
        QString res = QString::number(number);
        if (systemConfig.isPrediction==false)
            res="0";

        if(cnt % ceng == 0){
            if(cnt < ceng){
                QPixmap drawNEastMj1_1(imgPath + res + imgFile);
                 drawNEastMj1_1.scaled(ui->drawEast1_1->size(), Qt::IgnoreAspectRatio);
                 ui->drawEast1_1->setScaledContents(true);
                 ui->drawEast1_1->setPixmap(drawNEastMj1_1);
            }else{
                QPixmap drawNEastMj2_1(imgPath + res + imgFile);
                 drawNEastMj2_1.scaled(ui->drawEast2_1->size(), Qt::IgnoreAspectRatio);
                 ui->drawEast2_1->setScaledContents(true);
                 ui->drawEast2_1->setPixmap(drawNEastMj2_1);
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                QPixmap drawNEastMj1_2(imgPath + res + imgFile);
                drawNEastMj1_2.scaled(ui->drawEast1_2->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_2->setScaledContents(true);
                ui->drawEast1_2->setPixmap(drawNEastMj1_2);
            }else{
                QPixmap drawNEastMj2_2(imgPath + res + imgFile);
                drawNEastMj2_2.scaled(ui->drawEast2_2->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_2->setScaledContents(true);
                ui->drawEast2_2->setPixmap(drawNEastMj2_2);
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                QPixmap drawNEastMj1_3(imgPath + res + imgFile);
                drawNEastMj1_3.scaled(ui->drawEast1_3->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_3->setScaledContents(true);
                ui->drawEast1_3->setPixmap(drawNEastMj1_3);
            }else{
                QPixmap drawNEastMj2_3(imgPath + res + imgFile);
                drawNEastMj2_3.scaled(ui->drawEast2_3->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_3->setScaledContents(true);
                ui->drawEast2_3->setPixmap(drawNEastMj2_3);
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                QPixmap drawNEastMj1_4(imgPath + res + imgFile);
                drawNEastMj1_4.scaled(ui->drawEast1_4->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_4->setScaledContents(true);
                ui->drawEast1_4->setPixmap(drawNEastMj1_4);
            }else{
                QPixmap drawNEastMj2_4(imgPath + res + imgFile);
                drawNEastMj2_4.scaled(ui->drawEast2_4->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_4->setScaledContents(true);
                ui->drawEast2_4->setPixmap(drawNEastMj2_4);
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                QPixmap drawNEastMj1_5(imgPath + res + imgFile);
                drawNEastMj1_5.scaled(ui->drawEast1_5->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_5->setScaledContents(true);
                ui->drawEast1_5->setPixmap(drawNEastMj1_5);
            }else{
                QPixmap drawNEastMj2_5(imgPath + res + imgFile);
                drawNEastMj2_5.scaled(ui->drawEast2_5->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_5->setScaledContents(true);
                ui->drawEast2_5->setPixmap(drawNEastMj2_5);
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                QPixmap drawNEastMj1_6(imgPath + res + imgFile);
                drawNEastMj1_6.scaled(ui->drawEast1_6->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_6->setScaledContents(true);
                ui->drawEast1_6->setPixmap(drawNEastMj1_6);
            }else{
                QPixmap drawNEastMj2_6(imgPath + res + imgFile);
                drawNEastMj2_6.scaled(ui->drawEast2_6->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_6->setScaledContents(true);
                ui->drawEast2_6->setPixmap(drawNEastMj2_6);
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                QPixmap drawNEastMj1_7(imgPath + res + imgFile);
                drawNEastMj1_7.scaled(ui->drawEast1_7->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_7->setScaledContents(true);
                ui->drawEast1_7->setPixmap(drawNEastMj1_7);
            }else{
                QPixmap drawNEastMj2_7(imgPath + res + imgFile);
                drawNEastMj2_7.scaled(ui->drawEast2_7->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_7->setScaledContents(true);
                ui->drawEast2_7->setPixmap(drawNEastMj2_7);
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                QPixmap drawNEastMj1_8(imgPath + res + imgFile);
                drawNEastMj1_8.scaled(ui->drawEast1_8->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_8->setScaledContents(true);
                ui->drawEast1_8->setPixmap(drawNEastMj1_8);
            }else{
                QPixmap drawNEastMj2_8(imgPath + res + imgFile);
                drawNEastMj2_8.scaled(ui->drawEast2_8->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_8->setScaledContents(true);
                ui->drawEast2_8->setPixmap(drawNEastMj2_8);
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                QPixmap drawNEastMj1_9(imgPath + res + imgFile);
                 drawNEastMj1_9.scaled(ui->drawEast1_9->size(), Qt::IgnoreAspectRatio);
                 ui->drawEast1_9->setScaledContents(true);
                 ui->drawEast1_9->setPixmap(drawNEastMj1_9);
            }else{
                QPixmap drawNEastMj2_9(imgPath + res + imgFile);
                drawNEastMj2_9.scaled(ui->drawEast2_9->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_9->setScaledContents(true);
                ui->drawEast2_9->setPixmap(drawNEastMj2_9);
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                QPixmap drawNEastMj1_10(imgPath + res + imgFile);
                drawNEastMj1_10.scaled(ui->drawEast1_10->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_10->setScaledContents(true);
                ui->drawEast1_10->setPixmap(drawNEastMj1_10);
            }else{
                QPixmap drawNEastMj2_10(imgPath + res + imgFile);
                drawNEastMj2_10.scaled(ui->drawEast2_10->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_10->setScaledContents(true);
                ui->drawEast2_10->setPixmap(drawNEastMj2_10);
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                QPixmap drawNEastMj1_11(imgPath + res + imgFile);
                drawNEastMj1_11.scaled(ui->drawEast1_11->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_11->setScaledContents(true);
                ui->drawEast1_11->setPixmap(drawNEastMj1_11);
            }else{
                QPixmap drawNEastMj2_11(imgPath + res + imgFile);
                drawNEastMj2_11.scaled(ui->drawEast2_11->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_11->setScaledContents(true);
                ui->drawEast2_11->setPixmap(drawNEastMj2_11);
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                QPixmap drawNEastMj1_12(imgPath + res + imgFile);
                drawNEastMj1_12.scaled(ui->drawEast1_12->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_12->setScaledContents(true);
                ui->drawEast1_12->setPixmap(drawNEastMj1_12);
            }else{
                QPixmap drawNEastMj2_12(imgPath + res + imgFile);
                drawNEastMj2_12.scaled(ui->drawEast2_12->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_12->setScaledContents(true);
                ui->drawEast2_12->setPixmap(drawNEastMj2_12);
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                QPixmap drawNEastMj1_13(imgPath + res + imgFile);
                drawNEastMj1_13.scaled(ui->drawEast1_13->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_13->setScaledContents(true);
                ui->drawEast1_13->setPixmap(drawNEastMj1_13);
            }else{
                QPixmap drawNEastMj2_13(imgPath + res + imgFile);
                drawNEastMj2_13.scaled(ui->drawEast2_13->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_13->setScaledContents(true);
                ui->drawEast2_13->setPixmap(drawNEastMj2_13);
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                QPixmap drawNEastMj1_14(imgPath + res + imgFile);
                drawNEastMj1_14.scaled(ui->drawEast1_14->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_14->setScaledContents(true);
                ui->drawEast1_14->setPixmap(drawNEastMj1_14);
            }else{
                QPixmap drawNEastMj2_14(imgPath + res + imgFile);
                drawNEastMj2_14.scaled(ui->drawEast2_14->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_14->setScaledContents(true);
                ui->drawEast2_14->setPixmap(drawNEastMj2_14);
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                QPixmap drawNEastMj1_15(imgPath + res + imgFile);
                drawNEastMj1_15.scaled(ui->drawEast1_15->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_15->setScaledContents(true);
                ui->drawEast1_15->setPixmap(drawNEastMj1_15);
            }else{
                QPixmap drawNEastMj2_15(imgPath + res + imgFile);
                drawNEastMj2_15.scaled(ui->drawEast2_15->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_15->setScaledContents(true);
                ui->drawEast2_15->setPixmap(drawNEastMj2_15);
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                QPixmap drawNEastMj1_16(imgPath + res + imgFile);
                drawNEastMj1_16.scaled(ui->drawEast1_16->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_16->setScaledContents(true);
                ui->drawEast1_16->setPixmap(drawNEastMj1_16);
            }else{
                QPixmap drawNEastMj2_16(imgPath + res + imgFile);
                drawNEastMj2_16.scaled(ui->drawEast2_16->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_16->setScaledContents(true);
                ui->drawEast2_16->setPixmap(drawNEastMj2_16);
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                QPixmap drawNEastMj1_17(imgPath + res + imgFile);
                drawNEastMj1_17.scaled(ui->drawEast1_17->size(), Qt::IgnoreAspectRatio);
                ui->drawEast1_17->setScaledContents(true);
                ui->drawEast1_17->setPixmap(drawNEastMj1_17);
            }else{
                QPixmap drawNEastMj2_17(imgPath + res + imgFile);
                drawNEastMj2_17.scaled(ui->drawEast2_17->size(), Qt::IgnoreAspectRatio);
                ui->drawEast2_17->setScaledContents(true);
                ui->drawEast2_17->setPixmap(drawNEastMj2_17);
            }
        }
            cnt++;
    }

}
//清除 南 牌墙
void UIMainWindows::clearSouthDrawDisplay(int cnt)
{
    int ceng = zhangshuSouth/2;

    for(auto i: drawSouthMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt % ceng == 0){
            if(cnt < ceng){
                ui->drawSouth1_1->clear();
            }else{
                ui->drawSouth2_1->clear();
                ui->drawSouthNumber1_1->clear();
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                ui->drawSouth1_2->clear();
            }else{
                ui->drawSouth2_2->clear();
                ui->drawSouthNumber1_2->clear();
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                ui->drawSouth1_3->clear();
            }else{
                ui->drawSouth2_3->clear();
                ui->drawSouthNumber1_3->clear();
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                ui->drawSouth1_4->clear();
            }else{
                ui->drawSouth2_4->clear();
                ui->drawSouthNumber1_4->clear();
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                ui->drawSouth1_5->clear();
            }else{
                ui->drawSouth2_5->clear();
                ui->drawSouthNumber1_5->clear();
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                ui->drawSouth1_6->clear();
            }else{
                ui->drawSouth2_6->clear();
                ui->drawSouthNumber1_6->clear();
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                ui->drawSouth1_7->clear();
            }else{
                ui->drawSouth2_7->clear();
                ui->drawSouthNumber1_7->clear();
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                ui->drawSouth1_8->clear();
            }else{
                ui->drawSouth2_8->clear();
                ui->drawSouthNumber1_8->clear();
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                ui->drawSouth1_9->clear();
            }else{
                ui->drawSouth2_9->clear();
                ui->drawSouthNumber1_9->clear();
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                ui->drawSouth1_10->clear();
            }else{
                ui->drawSouth2_10->clear();
                ui->drawSouthNumber1_10->clear();
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                ui->drawSouth1_11->clear();
            }else{
                ui->drawSouth2_11->clear();
                ui->drawSouthNumber1_11->clear();
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                ui->drawSouth1_12->clear();
            }else{
                ui->drawSouth2_12->clear();
                ui->drawSouthNumber1_12->clear();
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                ui->drawSouth1_13->clear();
            }else{
                ui->drawSouth2_13->clear();
                ui->drawSouthNumber1_13->clear();
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                ui->drawSouth1_14->clear();
            }else{
                ui->drawSouth2_14->clear();
                ui->drawSouthNumber1_14->clear();
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                ui->drawSouth1_15->clear();
            }else{
                ui->drawSouth2_15->clear();
                ui->drawSouthNumber1_15->clear();
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                ui->drawSouth1_16->clear();
            }else{
                ui->drawSouth2_16->clear();
                ui->drawSouthNumber1_16->clear();
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                ui->drawSouth1_17->clear();
            }else{
                ui->drawSouth2_17->clear();
                ui->drawSouthNumber1_17->clear();
            }
        }

    }

}
//清除 东 牌墙
void UIMainWindows::clearEastDrawDisplay(int cnt)
{
    int ceng = zhangshuEast/2;

    for(auto i: drawEastMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt % ceng == 0){
            if(cnt < ceng){
                 ui->drawEast1_1->clear();
            }else{
                 ui->drawEast2_1->clear();
                 ui->drawEastNumber1_1->clear();
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                ui->drawEast1_2->clear();
            }else{
                ui->drawEast2_2->clear();
                ui->drawEastNumber1_2->clear();
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                ui->drawEast1_3->clear();
            }else{
                ui->drawEast2_3->clear();
                ui->drawEastNumber1_3->clear();
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                ui->drawEast1_4->clear();
            }else{
                ui->drawEast2_4->clear();
                ui->drawEastNumber1_4->clear();
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                ui->drawEast1_5->clear();
            }else{
                ui->drawEast2_5->clear();
                ui->drawEastNumber1_5->clear();
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                ui->drawEast1_6->clear();
            }else{
                ui->drawEast2_6->clear();
                ui->drawEastNumber1_6->clear();
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                ui->drawEast1_7->clear();
            }else{
                ui->drawEast2_7->clear();
                ui->drawEastNumber1_7->clear();
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                ui->drawEast1_8->clear();
            }else{
                ui->drawEast2_8->clear();
                ui->drawEastNumber1_8->clear();
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                 ui->drawEast1_9->clear();
            }else{
                ui->drawEast2_9->clear();
                ui->drawEastNumber1_9->clear();
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                ui->drawEast1_10->clear();
            }else{
                ui->drawEast2_10->clear();
                ui->drawEastNumber1_10->clear();
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                ui->drawEast1_11->clear();
            }else{
                ui->drawEast2_11->clear();
                ui->drawEastNumber1_11->clear();
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                ui->drawEast1_12->clear();
            }else{
                ui->drawEast2_12->clear();
                ui->drawEastNumber1_12->clear();
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                ui->drawEast1_13->clear();
            }else{
                ui->drawEast2_13->clear();
                ui->drawEastNumber1_13->clear();
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                ui->drawEast1_14->clear();
            }else{
                ui->drawEast2_14->clear();
                ui->drawEastNumber1_14->clear();
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                ui->drawEast1_15->clear();
            }else{
                ui->drawEast2_15->clear();
                ui->drawEastNumber1_15->clear();
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                ui->drawEast1_16->clear();
            }else{
                ui->drawEast2_16->clear();
                ui->drawEastNumber1_16->clear();
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                ui->drawEast1_17->clear();
            }else{
                ui->drawEast2_17->clear();
                ui->drawEastNumber1_17->clear();
            }
        }

    }

}
//清除 北 牌墙
void UIMainWindows::clearNorthDrawDisplay(int cnt)
{
    int ceng = zhangshuNorth/2;
    for(auto i: drawNorthMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt % ceng == 0){
            if(cnt < ceng){
                 ui->drawNorth1_1->clear();
            }else{
                ui->drawNorth2_1->clear();
                ui->drawNorthNumber1_1->clear();
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                 ui->drawNorth1_2->clear();
            }else{
                ui->drawNorth2_2->clear();
                ui->drawNorthNumber1_2->clear();
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                ui->drawNorth1_3->clear();
            }else{
                ui->drawNorth2_3->clear();
                ui->drawNorthNumber1_3->clear();
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                ui->drawNorth1_4->clear();
            }else{
                ui->drawNorth2_4->clear();
                ui->drawNorthNumber1_4->clear();
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                  ui->drawNorth1_5->clear();
            }else{
                ui->drawNorth2_5->clear();
                ui->drawNorthNumber1_5->clear();
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                 ui->drawNorth1_6->clear();
            }else{
                ui->drawNorth2_6->clear();
                ui->drawNorthNumber1_6->clear();
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                ui->drawNorth1_7->clear();
            }else{
                ui->drawNorth2_7->clear();
                ui->drawNorthNumber1_7->clear();
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                ui->drawNorth1_8->clear();
            }else{
                  ui->drawNorth2_8->clear();
                  ui->drawNorthNumber1_8->clear();
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                ui->drawNorth1_9->clear();
            }else{
                ui->drawNorth2_9->clear();
                ui->drawNorthNumber1_9->clear();
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                ui->drawNorth1_10->clear();
            }else{
                ui->drawNorth2_10->clear();
                ui->drawNorthNumber1_10->clear();
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                ui->drawNorth1_11->clear();
            }else{
                ui->drawNorth2_11->clear();
                ui->drawNorthNumber1_11->clear();
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                ui->drawNorth1_12->clear();
            }else{
                ui->drawNorth2_12->clear();
                ui->drawNorthNumber1_12->clear();
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                ui->drawNorth1_13->clear();
            }else{
                ui->drawNorth2_13->clear();
                ui->drawNorthNumber1_13->clear();
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                ui->drawNorth1_14->clear();
            }else{
                ui->drawNorth2_14->clear();
                ui->drawNorthNumber1_14->clear();
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                ui->drawNorth1_15->clear();
            }else{
                ui->drawNorth2_15->clear();
                ui->drawNorthNumber1_15->clear();
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                ui->drawNorth1_16->clear();
            }else{
                ui->drawNorth2_16->clear();
                ui->drawNorthNumber1_16->clear();
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                ui->drawNorth1_17->clear();
            }else{
                ui->drawNorth2_17->clear();
                ui->drawNorthNumber1_17->clear();
            }
        }

    }

}
//清除 西 牌墙
void UIMainWindows::clearWestDrawDisplay(int cnt)
{
    int ceng = zhangshuWest/2;
    for(auto i: drawWestMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt % ceng == 0){
            if(cnt < ceng){
                ui->drawWest1_1->clear();
            }else{
                ui->drawWest2_1->clear();
                ui->drawWestNumber1->clear();
            }
        }else if(cnt % ceng == 1){
            if(cnt < ceng){
                ui->drawWest1_2->clear();
            }else{
                ui->drawWest2_2->clear();
                ui->drawWestNumber2->clear();
            }
        }else if(cnt % ceng == 2){
            if(cnt < ceng){
                ui->drawWest1_3->clear();
            }else{
                ui->drawWest2_3->clear();
                ui->drawWestNumber3->clear();
            }
        }else if(cnt % ceng == 3){
            if(cnt < ceng){
                ui->drawWest1_4->clear();
            }else{
                ui->drawWest2_4->clear();
                ui->drawWestNumber4->clear();
            }
        }else if(cnt % ceng == 4){
            if(cnt < ceng){
                ui->drawWest1_5->clear();
            }else{
                ui->drawWest2_5->clear();
                ui->drawWestNumber5->clear();
            }
        }else if(cnt % ceng == 5){
            if(cnt < ceng){
                ui->drawWest1_6->clear();
            }else{
                ui->drawWest2_6->clear();
                ui->drawWestNumber6->clear();
            }
        }else if(cnt % ceng == 6){
            if(cnt < ceng){
                ui->drawWest1_7->clear();
            }else{
                ui->drawWest2_7->clear();
                ui->drawWestNumber7->clear();
            }
        }else if(cnt % ceng == 7){
            if(cnt < ceng){
                ui->drawWest1_8->clear();
            }else{
                ui->drawWest2_8->clear();
                ui->drawWestNumber8->clear();
            }
        }else if(cnt % ceng == 8){
            if(cnt < ceng){
                ui->drawWest1_9->clear();
            }else{
                ui->drawWest2_9->clear();
                ui->drawWestNumber9->clear();
            }
        }else if(cnt % ceng == 9){
            if(cnt < ceng){
                ui->drawWest1_10->clear();
            }else{
                ui->drawWest2_10->clear();
                ui->drawWestNumber10->clear();
            }
        }else if(cnt % ceng == 10){
            if(cnt < ceng){
                ui->drawWest1_11->clear();
            }else{
                ui->drawWest2_11->clear();
                ui->drawWestNumber11->clear();
            }
        }else if(cnt % ceng == 11){
            if(cnt < ceng){
                ui->drawWest1_12->clear();
            }else{
                ui->drawWest2_12->clear();
                ui->drawWestNumber12->clear();
            }
        }else if(cnt % ceng == 12){
            if(cnt < ceng){
                ui->drawWest1_13->clear();
            }else{
                ui->drawWest2_13->clear();
                ui->drawWestNumber13->clear();
            }
        }else if(cnt % ceng == 13){
            if(cnt < ceng){
                ui->drawWest1_14->clear();
            }else{
                ui->drawWest2_14->clear();
                ui->drawWestNumber14->clear();
            }
        }else if(cnt % ceng == 14){
            if(cnt < ceng){
                ui->drawWest1_15->clear();
            }else{
                ui->drawWest2_15->clear();
                ui->drawWestNumber15->clear();
            }
        }else if(cnt % ceng == 15){
            if(cnt < ceng){
                ui->drawWest1_16->clear();
            }else{
                ui->drawWest2_16->clear();
                ui->drawWestNumber16->clear();
            }
        }else if(cnt % ceng == 16){
            if(cnt < ceng){
                ui->drawWest1_17->clear();
            }else{
                ui->drawWest2_17->clear();
                ui->drawWestNumber17->clear();
            }
        }

    }

}
//清除牌墙
void UIMainWindows::clearDrawDisplay()
{
    if(mopaiDirection == 0){
        clearSouthDrawDisplay(mopaiPos + mopaiCeng * (zhangshuSouth/2));
    }else if(mopaiDirection == 1){
        clearEastDrawDisplay(mopaiPos + mopaiCeng * (zhangshuEast/2));
    }else if(mopaiDirection == 2){
        clearNorthDrawDisplay(mopaiPos + mopaiCeng * (zhangshuNorth/2));
    }else if(mopaiDirection == 3){
        clearWestDrawDisplay(mopaiPos + mopaiCeng * (zhangshuWest/2));
    }
}

//麻将手牌排序
bool cmpHandMjs(const Mj& x, const Mj& y){
    if(x.getIsque() == true && y.getIsque() == true){
        if(x.getPaizhuangtai() == y.getPaizhuangtai()){
                return x.getResult() < y.getResult();//按照点数从小到大
        }else{
            return x.getPaizhuangtai() > y.getPaizhuangtai();//按照状态从大到小
        }
    }else if(x.getIsque() == false && y.getIsque() == false){
        if(x.getPaizhuangtai() == y.getPaizhuangtai()){
                return x.getResult() < y.getResult();//按照点数从小到大
        }else{
            return x.getPaizhuangtai() > y.getPaizhuangtai();//按照状态从大到小
        }
    }else if(x.getIsque() == true && y.getIsque() == false){
        return false;//交换顺序，x排后，y排前
    }else{
        return true;
    }

}

//显示手牌
void UIMainWindows::southHandDisplay(std::list<Mj> &handSouthMjs)
{    
    //清空之前的手牌数据数据
    for (int i=0;i<18;i++)
        handSouthlist[i]->clear();
    //提示箭头
    for (int i=0;i<18;i++)
        handPromptSouthlist[i]->clear();

    //改牌
    if(changeSouthPai == true){
        vector<Mj> tempMjs;
        for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
            tempMjs.push_back(*iter);
        }

        tempMjs[0].setResult(1);
        tempMjs[1].setResult(1);
        tempMjs[2].setResult(5);
        tempMjs[3].setResult(8);
        tempMjs[4].setResult(18);
        tempMjs[5].setResult(18);
        tempMjs[6].setResult(12);
        tempMjs[7].setResult(11);
        tempMjs[8].setResult(13);
        tempMjs[9].setResult(16);
        tempMjs[10].setResult(19);
        tempMjs[11].setResult(22);
        tempMjs[12].setResult(22);

        handSouthMjs.clear();
        for(vector<Mj>::iterator iter = tempMjs.begin();iter != tempMjs.end() ;iter++){
            handSouthMjs.push_back(*iter);
        }

        changeSouthPai = false;
    }

    if(systemConfig.queyimen == 1){//加缺（用于自摸胡判断）
        //清空其他玩家的缺门信息
        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                iter->setIsque(false);
        }
        //设置自己牌的缺门信息
        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
            if(iter->getResult() > southQue && iter->getResult() < southQue + 10){
                iter->setIsque(true);
            }
        }
    }

    bool isLast = false;
    //排序
    if(handSouthMjs.size() == 13){//刚开局的时候
        handSouthMjs.sort(cmpHandMjs);//排序
    }else if(isDraw == true){
        list<Mj>::iterator iter = handSouthMjs.end();
        iter--;
        Mj mjTail = *iter;//找到最后一张

        handSouthMjs.erase(iter);//删除最后一张

        handSouthMjs.sort(cmpHandMjs);//排序
        handSouthMjs.push_back(mjTail);//重新加入最后一张
    }else if(isDraw == false && handSouthMjs.size() > 13){
        Mj mjTail;
        for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
            if(iter->isLast() == true){
                mjTail = *iter;
                handSouthMjs.erase(iter);
                isLast = true;
                break;                
            }
        }
        if(isLast == true){
            handSouthMjs.sort(cmpHandMjs);//排序
            handSouthMjs.push_back(mjTail);//重新加入最后一张
        }
    }
    if(isDraw == false && handSouthMjs.size() > 13 && isLast == false){
        handSouthMjs.sort(cmpHandMjs);//排序
    }
    //吃碰杠的个数
    int offset = 0;
    //刚摸起牌的偏移
    int disX = 0;
    int disY = 0;

    for(auto i:handSouthMjs){
        if(i.getPaizhuangtai() != 0){
            offset++;
        }
    }

    offset = (offset > 0) ?(offset * 15 - 40): 0;//有吃碰杠的牌，正常的手牌就向右偏移（40），否则就正常显示

    if(isDraw == true || isLast == true){
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(255, 0, 0, 100%);"));

    }

    //显示新的手牌
    QString imgPath = ":/image/";
    QString imgStatus = "z";
    QString imgFile = ".png";
    QString imgQue = "q";

    int cnt = 0;
    for(auto i: handSouthMjs){
        int number = i.getResult();
        int status = i.getPaizhuangtai();
        bool isQue = i.getIsque();
        QString res = QString::number(number);
        bool getLast = i.isLast();
        bool getHu = i.isHu();
        if ((systemConfig.isAIshow==false)&&(zhuangjia != 0)&&(status == 0 && getHu == false))
            res="0";

        //handSouthlist、handPromptSouthlist
        if(status == 0 && getHu == false){
            if(isQue == false){
                QPixmap handSouthMjPix(imgPath + res + imgFile);
                handSouthMjPix.scaled(handSouthlist[cnt]->size(), Qt::IgnoreAspectRatio);
                handSouthlist[cnt]->setScaledContents(true);//0000000
                handSouthlist[cnt]->setPixmap(handSouthMjPix);//0000000
                if (cnt>=13){
                    if((cnt == static_cast<int>(handSouthMjs.size()) - 1 && isDraw == true ) || getLast == true){
                        disX = 15;
                        disY = - 2;
                        ui->justTakenLabel->setGeometry(260+35*cnt - offset + disX + disY, 608 + disY * 2, 39, 59);
                    }
                    handSouthlist[cnt]->setGeometry(260+35*cnt - offset+ disX, 608+ disY, 35, 55);
                }else
                    handSouthlist[cnt]->setGeometry(260+35*cnt - offset, 608, 35, 55);//0000000  cnt=1:295
            }else{
                QPixmap handSouthMjPix(imgPath + imgQue + res + imgFile);
                handSouthMjPix.scaled(handSouthlist[cnt]->size(), Qt::IgnoreAspectRatio);//0000000
                handSouthlist[cnt]->setScaledContents(true);//0000000
                handSouthlist[cnt]->setPixmap(handSouthMjPix);//0000000

                if (cnt>=13)
                    if((cnt == static_cast<int>(handSouthMjs.size()) - 1 && isDraw == true ) || getLast == true){
                        disX = 15;
                        disY = - 2;
                        ui->justTakenLabel->setGeometry(260+35*cnt - offset + disX + disY, 608 + disY * 2, 39, 59);
                    }

                handSouthlist[cnt]->setGeometry(260+35*cnt - offset, 608, 35, 55);//0000000 cnt=1:295
            }

            bool getChow = false;
            bool getPong = false;
            bool getKong = false;
            QPixmap handPrompt;
            //吃判断
            if(systemConfig.chipai == 1){
                if(isChow2(0, number) == true){
                    getChow = true;
                    handPrompt = QPixmap(QString(":/image/chowEast.png"));
                }
            }
            //碰判断
            if(systemConfig.pongpai == 1){
                if(isPong2(0, number) != -1){
                    getPong = true;
                     if(isPong2(0, number) == 1){
                         handPrompt = QPixmap(QString(":/image/pongEast.png"));
                     }else if(isPong2(0, number) == 2){
                          handPrompt = QPixmap(QString(":/image/pongNorth.png"));
                     }else if(isPong2(0, number) == 3){
                          handPrompt = QPixmap(QString(":/image/pongWest.png"));
                     }
                }
            }
            //杠判断
            if(systemConfig.minggang == 1){
                if(isKong2(0, number) != -1){
                    getKong = true;
                     if(isPong2(0, number) == 1){
                         handPrompt = QPixmap(QString(":/image/kongEast.png"));
                     }else if(isPong2(0, number) == 2){
                          handPrompt = QPixmap(QString(":/image/kongNorth.png"));
                     }else if(isPong2(0, number) == 3){
                          handPrompt = QPixmap(QString(":/image/kongWest.png"));
                     }
                }
            }
            //胡牌判断
           if(systemConfig.zhixianzimo == 0){
                list<Mj> handMjs;
                Mj mj;

                handMjs = handWestMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs, westQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huWest.png"));
                }
                handMjs = handNorthMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,northQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huNorth.png"));
                }
                handMjs = handEastMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,eastQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huEast.png"));
                }
            }
            //显示图片
            if(getChow == true || getPong == true || getKong == true){
                handPromptSouthlist[cnt]->setScaledContents(true);//00000
                handPromptSouthlist[cnt]->setPixmap(handPrompt);//00000
                handPromptSouthlist[cnt]->setGeometry(handSouthlist[cnt]->x(), 588, 35, 20);//00000
            }

        }else {
            QPixmap handSouthMjPix(imgPath + imgStatus + res + imgFile);
            handSouthMjPix.scaled(handSouthlist[cnt]->size(), Qt::IgnoreAspectRatio);
            handSouthlist[cnt]->setScaledContents(true);//00000
            handSouthlist[cnt]->setPixmap(handSouthMjPix);//00000

            handSouthlist[cnt]->setGeometry(260+cnt*20, 633, 20, 30);//00000 cnt=1:280
        }
        cnt++;
    }

    //清除last
    for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
        iter->setLast(false);
    }
}

void UIMainWindows::eastHandDisplay(std::list<Mj> &handEastMjs)
{
    //清空之前的手牌数据数据
    for (int i=0;i<18;i++)
        handEastlist[i]->clear();
    //提示箭头
    for (int i=0;i<18;i++)
        handPromptEastlist[i]->clear();

    if(changeEastPai == true){
        vector<Mj> tempMjs;
        for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
            tempMjs.push_back(*iter);
        }

        tempMjs[0].setResult(18);
        tempMjs[1].setResult(13);
        tempMjs[2].setResult(19);
        tempMjs[3].setResult(12);
        tempMjs[4].setResult(12);
        tempMjs[5].setResult(12);
        tempMjs[6].setResult(17);
        tempMjs[7].setResult(18);
        tempMjs[8].setResult(19);
        tempMjs[9].setResult(22);
        tempMjs[10].setResult(22);
        tempMjs[11].setResult(22);
        tempMjs[12].setResult(29);

        handEastMjs.clear();
        for(vector<Mj>::iterator iter = tempMjs.begin();iter != tempMjs.end() ;iter++){
            handEastMjs.push_back(*iter);
        }

        changeEastPai = false;
    }



    if(systemConfig.queyimen == 1){//加缺（用于自摸胡判断）
        //清空其他玩家的缺门信息
        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                iter->setIsque(false);
        }

        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
            if(iter->getResult() > eastQue && iter->getResult() < eastQue + 10){
                iter->setIsque(true);
            }
        }
    }

    bool isLast = false;

    //排序
    if(handEastMjs.size() == 13){
        handEastMjs.sort(cmpHandMjs);//排序
    }else if(isDraw == true){
        list<Mj>::iterator iter = handEastMjs.end();
        iter--;
        Mj mjTail = *iter;//找到最后一张
        handEastMjs.erase(iter);//删除最后一张

        handEastMjs.sort(cmpHandMjs);//排序
        handEastMjs.push_back(mjTail);//重新加入最后一张
    }else if(isDraw == false && handEastMjs.size() > 13){
        Mj mjTail;
        for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
            if(iter->isLast() == true){
                mjTail = *iter;
                handEastMjs.erase(iter);
                isLast = true;
                break;
            }
        }
      if(isLast == true){
          handEastMjs.sort(cmpHandMjs);//排序
          handEastMjs.push_back(mjTail);//重新加入最后一张
      }
    }
    if(isDraw == false && handEastMjs.size() > 13 && isLast == false){
        handEastMjs.sort(cmpHandMjs);//排序
    }



    //吃碰杠的个数
    int offset = 0;
    //刚摸起牌的偏移
    int disX = 0;
    int disY = 0;

    for(auto i:handEastMjs){
        if(i.getPaizhuangtai() != 0){
            offset++;
        }
    }

    offset = (offset > 0) ?(offset * 15 - 40): 0;//有吃碰杠的牌，正常的手牌就向右偏移（40），否则就正常显示

    if(isDraw == true || isLast == true){
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(255, 0, 0, 100%);"));
    }

    //显示新的手牌
    QString imgPath = ":/image/";
    QString imgStatus1 = "r";
    QString imgStatus2 = "zr";
    QString imgQue = "qr";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: handEastMjs){
        int number = i.getResult();
        int status = i.getPaizhuangtai();
        bool isQue = i.getIsque();
        bool getLast = i.isLast();
        bool getHu = i.isHu();
        QString res = QString::number(number);

        if ((systemConfig.isAIshow==false)&&(zhuangjia != 1)&&(status == 0 && getHu == false))
            res="0";
        //
        if(status == 0 && getHu == false){
            if(isQue == false){
                QPixmap handEastMjPix(imgPath + imgStatus1 + res + imgFile);
                handEastMjPix.scaled(handEastlist[cnt]->size(), Qt::IgnoreAspectRatio);
                handEastlist[cnt]->setScaledContents(true);
                handEastlist[cnt]->setPixmap(handEastMjPix);
                if (cnt>=13){
                    if((cnt == static_cast<int>(handEastMjs.size()) - 1 && isDraw == true) || getLast == true){
                        disX = 2;
                        disY = 15;
                        ui->justTakenLabel->setGeometry(976 - disX * 2, 639-35*cnt + offset - disY - disX, 59, 39);
                    }
                    handEastlist[cnt]->setGeometry(976- disX,  639-35*cnt + offset- disY,  55, 35);
                }else
                    handEastlist[cnt]->setGeometry(976,  639-35*cnt + offset,  55, 35);
            }else{
                QPixmap handEastMjPix(imgPath + imgQue + res + imgFile);
                handEastMjPix.scaled(handEastlist[cnt]->size(), Qt::IgnoreAspectRatio);
                handEastlist[cnt]->setScaledContents(true);
                handEastlist[cnt]->setPixmap(handEastMjPix);

                if (cnt>=13){
                    if((cnt == static_cast<int>(handEastMjs.size()) - 1 && isDraw == true) || getLast == true){
                        disX = 2;
                        disY = 15;
                        ui->justTakenLabel->setGeometry(976 - disX * 2, 639-35*cnt + offset - disY - disX, 59, 39);
                    }
                    handEastlist[cnt]->setGeometry(976- disX,  639-35*cnt + offset- disY,  55, 35);
                }else
                    handEastlist[cnt]->setGeometry(976,  639-35*cnt + offset,  55, 35);
            }

            bool getChow = false;
            bool getPong = false;
            bool getKong = false;
            QPixmap handPrompt;
            //吃判断
            if(systemConfig.chipai == 1){
                if(isChow2(1, number) == true){
                    getChow = true;
                    handPrompt = QPixmap(QString(":/image/chowNorth.png"));
                }
            }
            //碰判断
            if(systemConfig.pongpai == 1){
                if(isPong2(1, number) != -1){
                    getPong = true;
                     if(isPong2(1, number) == 0){
                         handPrompt = QPixmap(QString(":/image/pongSouth.png"));
                     }else if(isPong2(1, number) == 2){
                          handPrompt = QPixmap(QString(":/image/pongNorth.png"));
                     }else if(isPong2(1, number) == 3){
                          handPrompt = QPixmap(QString(":/image/pongWest.png"));
                     }
                }
            }
            //杠判断
            if(systemConfig.minggang == 1){
                if(isKong2(1, number) != -1){
                    getKong = true;
                     if(isPong2(1, number) == 0){
                         handPrompt = QPixmap(QString(":/image/kongSouth.png"));
                     }else if(isPong2(1, number) == 2){
                          handPrompt = QPixmap(QString(":/image/kongNorth.png"));
                     }else if(isPong2(1, number) == 3){
                          handPrompt = QPixmap(QString(":/image/kongWest.png"));
                     }

                }
            }
            //胡牌判断
            if(systemConfig.zhixianzimo == 0){
                list<Mj> handMjs;
                Mj mj;

                handMjs = handSouthMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,southQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huSouth.png"));
                }
                handMjs = handWestMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs, westQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huWest.png"));
                }
                handMjs = handNorthMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,northQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huNorth.png"));
                }
            }
            //显示图片
            if(getChow == true || getPong == true || getKong == true){
                handPromptEastlist[cnt]->setScaledContents(true);
                handPromptEastlist[cnt]->setPixmap(handPrompt);
                handPromptEastlist[cnt]->setGeometry(956, handEastlist[cnt]->y(), 20, 35);
            }

        }else{
            QPixmap handEastMjPix(imgPath + imgStatus2 + res + imgFile);
            handEastMjPix.scaled(handPromptEastlist[cnt]->size(), Qt::IgnoreAspectRatio);
            handPromptEastlist[cnt]->setScaledContents(true);
            handPromptEastlist[cnt]->setPixmap(handEastMjPix);

            handPromptEastlist[cnt]->setGeometry(1001,  654-20*cnt,  30, 20);
        }
        cnt++;
    }

    //清除last
    for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
        iter->setLast(false);
    }

}

void UIMainWindows::northHandDisplay(std::list<Mj> &handNorthMjs)
{
    //清空之前手牌数据
    for (int i=0;i<18;i++)
        handNorthlist[i]->clear();
    //提示箭头消失
    for (int i=0;i<18;i++)
        handPromptNorthlist[i]->clear();

    //改牌
    if(changeNorthPai == true){
        vector<Mj> tempMjs;
        for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
            tempMjs.push_back(*iter);
        }

        tempMjs[0].setResult(1);
        tempMjs[1].setResult(3);
        tempMjs[2].setResult(4);
        tempMjs[3].setResult(9);
        tempMjs[4].setResult(11);
        tempMjs[5].setResult(15);
        tempMjs[6].setResult(26);
        tempMjs[7].setResult(26);
        tempMjs[8].setResult(26);
        tempMjs[9].setResult(27);
        tempMjs[10].setResult(27);
        tempMjs[11].setResult(27);
        tempMjs[12].setResult(27);

        handNorthMjs.clear();
        for(vector<Mj>::iterator iter = tempMjs.begin();iter != tempMjs.end() ;iter++){
            handNorthMjs.push_back(*iter);
        }

        changeNorthPai = false;
    }


    if(systemConfig.queyimen == 1){//加缺（用于自摸胡判断）
        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                iter->setIsque(false);
        }

        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
            if(iter->getResult() > northQue && iter->getResult() < northQue + 10){
                iter->setIsque(true);
            }
        }
    }
    bool isLast = false;

    //排序
    if(handNorthMjs.size() == 13){
        handNorthMjs.sort(cmpHandMjs);//排序
    }else if(isDraw == true){
        list<Mj>::iterator iter = handNorthMjs.end();
        iter--;
        Mj mjTail = *iter;//找到最后一张
        handNorthMjs.erase(iter);//删除最后一张

        handNorthMjs.sort(cmpHandMjs);//排序
        handNorthMjs.push_back(mjTail);//重新加入最后一张
    }else if(isDraw == false && handNorthMjs.size() > 13){
        Mj mjTail;
        for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
            if(iter->isLast() == true){
                mjTail = *iter;
                handNorthMjs.erase(iter);
                isLast = true;
                break;
            }
        }

      if(isLast == true){
          handNorthMjs.sort(cmpHandMjs);//排序
          handNorthMjs.push_back(mjTail);//重新加入最后一张
      }
    }
    if(isDraw == false && handNorthMjs.size() > 13 && isLast == false){
         handNorthMjs.sort(cmpHandMjs);//排序
    }


    //吃碰杠的个数
    int offset = 0;
    //刚摸起牌的偏移
    int disX = 0;
    int disY = 0;

    for(auto i:handNorthMjs){
        if(i.getPaizhuangtai() != 0){
            offset++;
        }
    }

    offset = (offset > 0) ?( 40 - offset * 15): 0;//有吃碰杠的牌，正常的手牌就向右偏移（40），否则就正常显示

    //遮罩层
    if(isDraw == true || isLast == true){
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(255, 0, 0, 100%);"));
    }


//    for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
//        iter->setPaizhuangtai(1);
//    }

    //显示新的手牌
    QString imgPath = ":/image/";
    QString imgStatus = "z";
    QString imgQue = "q";
    QString imgFile = ".png";    

    int cnt = 0;
    for(auto i: handNorthMjs){
        int number = i.getResult();
        int status = i.getPaizhuangtai();
        bool isQue = i.getIsque();
        bool getLast = i.isLast();
        bool getHu = i.isHu();
        QString res = QString::number(number);

        if ((systemConfig.isAIshow==false)&&(zhuangjia != 2)&&(status == 0 && getHu == false))
            res="0";

        //
        if(status == 0 && getHu == false){
            if(isQue == false){
                QPixmap handNorthMjPix(imgPath + res + imgFile);
                handNorthMjPix.scaled(handNorthlist[cnt]->size(), Qt::IgnoreAspectRatio);
                handNorthlist[cnt]->setScaledContents(true);
                handNorthlist[cnt]->setPixmap(handNorthMjPix);

                if (cnt>=13){
                    if((cnt == static_cast<int>(handNorthMjs.size())  - 1 && isDraw == true) || getLast == true){
                        disX = 15;
                        disY = 2;
                        ui->justTakenLabel->setGeometry(855-35*cnt - offset - disX - disY, 48, 39, 59);
                    }
                    handNorthlist[cnt]->setGeometry(855-35*cnt - offset- disX, 48+disY, 35, 55);
                }else
                    handNorthlist[cnt]->setGeometry(855-35*cnt - offset, 48, 35, 55);
            }else{
                QPixmap handNorthMjPix(imgPath + imgQue + res + imgFile);
                handNorthMjPix.scaled(handNorthlist[cnt]->size(), Qt::IgnoreAspectRatio);
                handNorthlist[cnt]->setScaledContents(true);
                handNorthlist[cnt]->setPixmap(handNorthMjPix);

                if (cnt>=13){
                    if((cnt == static_cast<int>(handNorthMjs.size())  - 1 && isDraw == true) || getLast == true){
                        disX = 15;
                        disY = 2;
                        ui->justTakenLabel->setGeometry(855-35*cnt - offset - disX - disY, 48, 39, 59);
                    }
                    handNorthlist[cnt]->setGeometry(855-35*cnt - offset- disX, 48+disY, 35, 55);
                }else
                    handNorthlist[cnt]->setGeometry(855-35*cnt - offset, 48, 35, 55);
            }

            bool getChow = false;
            bool getPong = false;
            bool getKong = false;
            QPixmap handPrompt;
            //吃判断
            if(systemConfig.chipai == 1){
                if(isChow2(2, number) == true){
                    getChow = true;
                    handPrompt = QPixmap(QString(":/image/chowWest.png"));
                }
            }
            //碰判断
            if(systemConfig.pongpai == 1){
                if(isPong2(2, number) != -1){
                    getPong = true;
                     if(isPong2(2, number) == 0){
                         handPrompt = QPixmap(QString(":/image/pongSouth.png"));
                     }else if(isPong2(2, number) == 1){
                          handPrompt = QPixmap(QString(":/image/pongEast.png"));
                     }else if(isPong2(2, number) == 3){
                          handPrompt = QPixmap(QString(":/image/pongWest.png"));
                     }
                }
            }
            //杠判断
            if(systemConfig.minggang == 1){
                if(isKong2(2, number) != -1){
                    getKong = true;
                     if(isPong2(2, number) == 0){
                         handPrompt = QPixmap(QString(":/image/kongSouth.png"));
                     }else if(isPong2(2, number) == 1){
                          handPrompt = QPixmap(QString(":/image/kongEast.png"));
                     }else if(isPong2(2, number) == 3){
                          handPrompt = QPixmap(QString(":/image/kongWest.png"));
                     }

                }
            }
            //胡牌判断
            if(systemConfig.zhixianzimo == 0){
                list<Mj> handMjs;
                Mj mj;

                handMjs = handEastMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,eastQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huEast.png"));
                }
                handMjs = handSouthMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,southQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huSouth.png"));
                }
                handMjs = handWestMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs, westQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huWest.png"));
                }
            }
            //显示图片
            if(getChow == true || getPong == true || getKong == true){
                handPromptNorthlist[cnt]->setScaledContents(true);
                handPromptNorthlist[cnt]->setPixmap(handPrompt);
                handPromptNorthlist[cnt]->setGeometry(handNorthlist[cnt]->x(), 103, 35, 20);
            }

        }else{
            QPixmap handNorthMjPix(imgPath + imgStatus + res + imgFile);

            handNorthMjPix.scaled(handNorthlist[cnt]->size(), Qt::IgnoreAspectRatio);
            handNorthlist[cnt]->setScaledContents(true);
            handNorthlist[cnt]->setPixmap(handNorthMjPix);

            handNorthlist[cnt]->setGeometry(870-20*cnt, 73, 20, 30);
        }
        cnt++;
    }

    //清除last
    for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
        iter->setLast(false);
    }

}

void UIMainWindows::westHandDisplay(std::list<Mj> &handWestMjs)
{
    //清空之前数据
    for (int i=0;i<18;i++)
        handWestlist[i]->clear();

    for (int i=0;i<18;i++)
        handPromptWestlist[i]->clear();

    if(changeWestPai == true){
        vector<Mj> tempMjs;
        for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
            tempMjs.push_back(*iter);
        }

        tempMjs[0].setResult(1);
        tempMjs[1].setResult(2);
        tempMjs[2].setResult(3);
        tempMjs[3].setResult(4);
        tempMjs[4].setResult(5);
        tempMjs[5].setResult(6);
        tempMjs[6].setResult(7);
        tempMjs[7].setResult(8);
        tempMjs[8].setResult(9);
        tempMjs[9].setResult(29);
        tempMjs[10].setResult(29);
        tempMjs[11].setResult(29);
        tempMjs[12].setResult(25);

        handWestMjs.clear();
        for(vector<Mj>::iterator iter = tempMjs.begin();iter != tempMjs.end() ;iter++){
            handWestMjs.push_back(*iter);
        }

        changeWestPai = false;
    }


    if(systemConfig.queyimen == 1){//加缺（用于自摸胡判断）
        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                iter->setIsque(false);
        }

        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
            if(iter->getResult() > westQue && iter->getResult() < westQue + 10){
                iter->setIsque(true);
            }
        }
    }

    bool isLast = false;

    //排序
    if(handWestMjs.size() == 13){
       handWestMjs.sort(cmpHandMjs);//排序
    }else if(isDraw == true ){
        list<Mj>::iterator iter = handWestMjs.end();
        iter--;
        Mj mjTail = *iter;//找到最后一张
        handWestMjs.erase(iter);//删除最后一张

        handWestMjs.sort(cmpHandMjs);//排序
        handWestMjs.push_back(mjTail);//重新加入最后一张
    }else if(isDraw == false && handWestMjs.size() > 13){
        Mj mjTail;
        for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
            if(iter->isLast() == true){
                mjTail = *iter;
                handWestMjs.erase(iter);
                isLast = true;
                break;
            }
        }

      if(isLast == true){
          handWestMjs.sort(cmpHandMjs);//排序
          handWestMjs.push_back(mjTail);//重新加入最后一张
      }
    }
    if(isDraw == false && handWestMjs.size() > 13 && isLast == false){
        handWestMjs.sort(cmpHandMjs);//排序
    }


    //吃碰杠的个数
    int offset = 0;
    //刚摸起牌的偏移
    int disX = 0;
    int disY = 0;

    for(auto i:handWestMjs){
        if(i.getPaizhuangtai() != 0){
            offset++;
        }
    }

    offset = (offset > 0) ?(offset * 15 - 40): 0;//有吃碰杠的牌，正常的手牌就向下偏移（40），否则就正常显示

    if(isDraw == true || isLast == true){
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(255, 0, 0, 100%);"));
    }


    //显示新的手牌
    QString imgPath = ":/image/";
    QString imgStatus1 = "l";
    QString imgStatus2 = "zl";
    QString imgQue = "ql";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: handWestMjs){
        int number = i.getResult();
        int status = i.getPaizhuangtai();
        bool isQue = i.getIsque();
        bool getLast = i.isLast();
        bool getHu = i.isHu();
        QString res = QString::number(number);

        if ((systemConfig.isAIshow==false)&&(zhuangjia != 3)&&(status == 0 && getHu == false))
            res="0";

        ///////////////////////////////////////////////////////////////
        if(status == 0 && getHu == false){
            if(isQue == false){
               QPixmap handWestMjPix(imgPath + imgStatus1 + res + imgFile);
               handWestMjPix.scaled(handWestlist[cnt]->size(), Qt::IgnoreAspectRatio);
               handWestlist[cnt]->setScaledContents(true);
               handWestlist[cnt]->setPixmap(handWestMjPix);

               if (cnt>=13){
                   if((cnt == static_cast<int>(handWestMjs.size())  - 1 && isDraw == true) || getLast == true){
                        disX = 2;
                        disY = 15;
                        ui->justTakenLabel->setGeometry(136, 35+35*cnt - offset + disY - disX, 59, 39);
                    }
                   handWestlist[cnt]->setGeometry(136+disX, 35+35*cnt - offset+ disY, 55, 35);
               }else
                   handWestlist[cnt]->setGeometry(136, 35+35*cnt - offset, 55, 35);
            }else{
               QPixmap handWestMjPix(imgPath + imgQue + res + imgFile);
               handWestMjPix.scaled(handWestlist[cnt]->size(), Qt::IgnoreAspectRatio);
               handWestlist[cnt]->setScaledContents(true);
               handWestlist[cnt]->setPixmap(handWestMjPix);

               if (cnt>=13){
                   if((cnt == static_cast<int>(handWestMjs.size())  - 1 && isDraw == true) || getLast == true){
                        disX = 2;
                        disY = 15;
                        ui->justTakenLabel->setGeometry(136, 35+35*cnt - offset + disY - disX, 59, 39);
                    }
                   handWestlist[cnt]->setGeometry(136+disX, 35+35*cnt - offset+ disY, 55, 35);
               }else
                   handWestlist[cnt]->setGeometry(136, 35+35*cnt - offset, 55, 35);
            }

            bool getChow = false;
            bool getPong = false;
            bool getKong = false;
            QPixmap handPrompt;
            //吃判断
            if(systemConfig.chipai == 1){
                if(isChow2(3, number) == true){
                    getChow = true;
                    handPrompt = QPixmap(QString(":/image/chowSouth.png"));
                }
            }
            //碰判断
            if(systemConfig.pongpai == 1){
                if(isPong2(3, number) != -1){
                    getPong = true;
                     if(isPong2(3, number) == 0){
                         handPrompt = QPixmap(QString(":/image/pongSouth.png"));
                     }else if(isPong2(3, number) == 1){
                          handPrompt = QPixmap(QString(":/image/pongEast.png"));
                     }else if(isPong2(3, number) == 2){
                          handPrompt = QPixmap(QString(":/image/pongNorth.png"));
                     }
                }
            }
            //杠判断
            if(systemConfig.minggang == 1){
                if(isKong2(3, number) != -1){
                    getKong = true;
                     if(isPong2(3, number) == 0){
                         handPrompt = QPixmap(QString(":/image/kongSouth.png"));
                     }else if(isPong2(3, number) == 1){
                          handPrompt = QPixmap(QString(":/image/kongEast.png"));
                     }else if(isPong2(3, number) == 2){
                          handPrompt = QPixmap(QString(":/image/kongNorth.png"));
                     }

                }
            }

            //胡牌判断
            if(systemConfig.zhixianzimo == 0){
                list<Mj> handMjs;
                Mj mj;

                handMjs = handNorthMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs, northQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huNorth.png"));
                }
                handMjs = handEastMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,eastQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huEast.png"));
                }
                handMjs = handSouthMjs;
                mj.setResult(number);
                handMjs.push_back(mj);
                if(HuPaiPanDin(handMjs,southQue, systemConfig) == true){
                     handPrompt = QPixmap(QString(":/image/huSouth.png"));
                }
            }
            //显示图片
            if(getChow == true || getPong == true || getKong == true){
                handPromptWestlist[cnt]->setScaledContents(true);
                handPromptWestlist[cnt]->setPixmap(handPrompt);
                handPromptWestlist[cnt]->setGeometry(191, handWestlist[cnt]->y(), 20, 35);
            }

        }else{
            QPixmap handWestMjPix(imgPath + imgStatus2 + res + imgFile);
            handWestMjPix.scaled(handWestlist[cnt]->size(), Qt::IgnoreAspectRatio);
            handWestlist[cnt]->setScaledContents(true);
            handWestlist[cnt]->setPixmap(handWestMjPix);

            handWestlist[cnt]->setGeometry(136, 35+20*cnt, 30, 20);
        }
        cnt++;
    }

    //清除last
    for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
        iter->setLast(false);
    }
}
//显示弃牌
void UIMainWindows::discardDisplay(const std::list<Mj> &discardMjs) const
{
    //弃牌
    ui->discard1_1->clear();
    ui->discard1_2->clear();
    ui->discard1_3->clear();
    ui->discard1_4->clear();
    ui->discard1_5->clear();
    ui->discard1_6->clear();
    ui->discard1_7->clear();
    ui->discard1_8->clear();
    ui->discard1_9->clear();
    ui->discard1_10->clear();
    ui->discard1_11->clear();
    ui->discard1_12->clear();
    ui->discard1_13->clear();
    ui->discard1_14->clear();
    ui->discard1_15->clear();
    ui->discard1_16->clear();
    ui->discard1_17->clear();
    ui->discard1_18->clear();
    ui->discard1_19->clear();
    ui->discard1_20->clear();
    ui->discard1_21->clear();
    ui->discard1_22->clear();
    ui->discard1_23->clear();
    ui->discard1_24->clear();
    ui->discard1_25->clear();
    ui->discard1_26->clear();
    ui->discard1_27->clear();
    ui->discard1_28->clear();
    ui->discard1_29->clear();
    ui->discard1_30->clear();
    ui->discard1_31->clear();
    ui->discard1_32->clear();
    ui->discard1_33->clear();
    ui->discard1_34->clear();
    ui->discard1_35->clear();
    ui->discard1_36->clear();
    ui->discard1_37->clear();
    ui->discard1_38->clear();
    ui->discard1_39->clear();
    ui->discard1_40->clear();
    ui->discard1_41->clear();
    ui->discard1_42->clear();
    ui->discard1_43->clear();
    ui->discard1_44->clear();
    ui->discard1_45->clear();
    ui->discard1_46->clear();
    ui->discard1_47->clear();
    ui->discard1_48->clear();
    ui->discard1_49->clear();
    ui->discard1_50->clear();
    ui->discard1_51->clear();
    ui->discard1_52->clear();
    ui->discard1_53->clear();
    ui->discard1_54->clear();
    ui->discard1_55->clear();
    ui->discard1_56->clear();
    ui->discard1_57->clear();
    ui->discard1_58->clear();
    ui->discard1_59->clear();
    ui->discard1_60->clear();
    ui->discard1_61->clear();
    ui->discard1_62->clear();
    ui->discard1_63->clear();
    ui->discard1_64->clear();
    ui->discard1_65->clear();
    ui->discard1_66->clear();
    ui->discard1_67->clear();
    ui->discard1_68->clear();
    ui->discard1_69->clear();
    ui->discard1_70->clear();
    ui->discard1_71->clear();
    ui->discard1_72->clear();
    ui->discard1_73->clear();
    ui->discard1_74->clear();
    ui->discard1_75->clear();
    ui->discard1_76->clear();
    ui->discard1_77->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_79->clear();
    ui->discard1_80->clear();
    ui->discard1_81->clear();
    ui->discard1_82->clear();
    ui->discard1_83->clear();
    ui->discard1_84->clear();
    ui->discard1_85->clear();
    ui->discard1_86->clear();
    ui->discard1_87->clear();
    ui->discard1_88->clear();
    ui->discard1_89->clear();
    ui->discard1_90->clear();
    ui->discard1_91->clear();
    ui->discard1_92->clear();
    ui->discard1_93->clear();
    ui->discard1_94->clear();
    ui->discard1_95->clear();
    ui->discard1_96->clear();
    ui->discard1_97->clear();
    ui->discard1_98->clear();
    ui->discard1_99->clear();
    ui->discard1_100->clear();

    //显示新的手牌
    QString imgPath = ":/image/";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: discardMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt == 0){
            QPixmap discardMj1_1(imgPath + res + imgFile);
            discardMj1_1.scaled(ui->discard1_1->size(), Qt::IgnoreAspectRatio);
            ui->discard1_1->setScaledContents(true);
            ui->discard1_1->setPixmap(discardMj1_1);
        }else if (cnt == 1) {
            QPixmap discardMj1_2(imgPath + res + imgFile);
            discardMj1_2.scaled(ui->discard1_2->size(), Qt::IgnoreAspectRatio);
            ui->discard1_2->setScaledContents(true);
            ui->discard1_2->setPixmap(discardMj1_2);
        }else if (cnt == 2) {
            QPixmap discardMj1_3(imgPath + res + imgFile);
            discardMj1_3.scaled(ui->discard1_3->size(), Qt::IgnoreAspectRatio);
            ui->discard1_3->setScaledContents(true);
            ui->discard1_3->setPixmap(discardMj1_3);
        }else if (cnt == 3) {
            QPixmap discardMj1_4(imgPath + res + imgFile);
            discardMj1_4.scaled(ui->discard1_4->size(), Qt::IgnoreAspectRatio);
            ui->discard1_4->setScaledContents(true);
            ui->discard1_4->setPixmap(discardMj1_4);
        }else if (cnt == 4) {
            QPixmap discardMj1_5(imgPath + res + imgFile);
            discardMj1_5.scaled(ui->discard1_5->size(), Qt::IgnoreAspectRatio);
            ui->discard1_5->setScaledContents(true);
            ui->discard1_5->setPixmap(discardMj1_5);
        }else if (cnt == 5) {
            QPixmap discardMj1_6(imgPath + res + imgFile);
            discardMj1_6.scaled(ui->discard1_6->size(), Qt::IgnoreAspectRatio);
            ui->discard1_6->setScaledContents(true);
            ui->discard1_6->setPixmap(discardMj1_6);
        }else if (cnt == 6) {
            QPixmap discardMj1_7(imgPath + res + imgFile);
            discardMj1_7.scaled(ui->discard1_7->size(), Qt::IgnoreAspectRatio);
            ui->discard1_7->setScaledContents(true);
            ui->discard1_7->setPixmap(discardMj1_7);
        }else if (cnt == 7) {
            QPixmap discardMj1_8(imgPath + res + imgFile);
            discardMj1_8.scaled(ui->discard1_8->size(), Qt::IgnoreAspectRatio);
            ui->discard1_8->setScaledContents(true);
            ui->discard1_8->setPixmap(discardMj1_8);
        }else if (cnt == 8) {
            QPixmap discardMj1_9(imgPath + res + imgFile);
            discardMj1_9.scaled(ui->discard1_9->size(), Qt::IgnoreAspectRatio);
            ui->discard1_9->setScaledContents(true);
            ui->discard1_9->setPixmap(discardMj1_9);
        }else if (cnt == 9) {
            QPixmap discardMj1_10(imgPath + res + imgFile);
            discardMj1_10.scaled(ui->discard1_10->size(), Qt::IgnoreAspectRatio);
            ui->discard1_10->setScaledContents(true);
            ui->discard1_10->setPixmap(discardMj1_10);
        }else if (cnt == 10) {
            QPixmap discardMj1_11(imgPath + res + imgFile);
            discardMj1_11.scaled(ui->discard1_11->size(), Qt::IgnoreAspectRatio);
            ui->discard1_11->setScaledContents(true);
            ui->discard1_11->setPixmap(discardMj1_11);
        }else if (cnt == 11) {
            QPixmap discardMj1_12(imgPath + res + imgFile);
            discardMj1_12.scaled(ui->discard1_12->size(), Qt::IgnoreAspectRatio);
            ui->discard1_12->setScaledContents(true);
            ui->discard1_12->setPixmap(discardMj1_12);
        }else if (cnt == 12) {
            QPixmap discardMj1_13(imgPath + res + imgFile);
            discardMj1_13.scaled(ui->discard1_13->size(), Qt::IgnoreAspectRatio);
            ui->discard1_13->setScaledContents(true);
            ui->discard1_13->setPixmap(discardMj1_13);
        }else if (cnt == 13) {
            QPixmap discardMj1_14(imgPath + res + imgFile);
            discardMj1_14.scaled(ui->discard1_14->size(), Qt::IgnoreAspectRatio);
            ui->discard1_14->setScaledContents(true);
            ui->discard1_14->setPixmap(discardMj1_14);
        }else if (cnt == 14) {
            QPixmap discardMj1_15(imgPath + res + imgFile);
            discardMj1_15.scaled(ui->discard1_15->size(), Qt::IgnoreAspectRatio);
            ui->discard1_15->setScaledContents(true);
            ui->discard1_15->setPixmap(discardMj1_15);
        }else if (cnt == 15) {
            QPixmap discardMj1_16(imgPath + res + imgFile);
            discardMj1_16.scaled(ui->discard1_16->size(), Qt::IgnoreAspectRatio);
            ui->discard1_16->setScaledContents(true);
            ui->discard1_16->setPixmap(discardMj1_16);
        }else if (cnt == 16) {
            QPixmap discardMj1_17(imgPath + res + imgFile);
            discardMj1_17.scaled(ui->discard1_17->size(), Qt::IgnoreAspectRatio);
            ui->discard1_17->setScaledContents(true);
            ui->discard1_17->setPixmap(discardMj1_17);
        }else if (cnt == 17) {
            QPixmap discardMj1_18(imgPath + res + imgFile);
            discardMj1_18.scaled(ui->discard1_18->size(), Qt::IgnoreAspectRatio);
            ui->discard1_18->setScaledContents(true);
            ui->discard1_18->setPixmap(discardMj1_18);
        }else if (cnt == 18) {
            QPixmap discardMj1_19(imgPath + res + imgFile);
            discardMj1_19.scaled(ui->discard1_19->size(), Qt::IgnoreAspectRatio);
            ui->discard1_19->setScaledContents(true);
            ui->discard1_19->setPixmap(discardMj1_19);
        }else if (cnt == 19) {
            QPixmap discardMj1_20(imgPath + res + imgFile);
            discardMj1_20.scaled(ui->discard1_20->size(), Qt::IgnoreAspectRatio);
            ui->discard1_20->setScaledContents(true);
            ui->discard1_20->setPixmap(discardMj1_20);
        }else if (cnt == 20) {
            QPixmap discardMj1_21(imgPath + res + imgFile);
            discardMj1_21.scaled(ui->discard1_21->size(), Qt::IgnoreAspectRatio);
            ui->discard1_21->setScaledContents(true);
            ui->discard1_21->setPixmap(discardMj1_21);
        }else if (cnt == 21) {
            QPixmap discardMj1_22(imgPath + res + imgFile);
            discardMj1_22.scaled(ui->discard1_22->size(), Qt::IgnoreAspectRatio);
            ui->discard1_22->setScaledContents(true);
            ui->discard1_22->setPixmap(discardMj1_22);
        }else if (cnt == 22) {
            QPixmap discardMj1_23(imgPath + res + imgFile);
            discardMj1_23.scaled(ui->discard1_23->size(), Qt::IgnoreAspectRatio);
            ui->discard1_23->setScaledContents(true);
            ui->discard1_23->setPixmap(discardMj1_23);
        }else if (cnt == 23) {
            QPixmap discardMj1_24(imgPath + res + imgFile);
            discardMj1_24.scaled(ui->discard1_24->size(), Qt::IgnoreAspectRatio);
            ui->discard1_24->setScaledContents(true);
            ui->discard1_24->setPixmap(discardMj1_24);
        }else if (cnt == 24) {
            QPixmap discardMj1_25(imgPath + res + imgFile);
            discardMj1_25.scaled(ui->discard1_25->size(), Qt::IgnoreAspectRatio);
            ui->discard1_25->setScaledContents(true);
            ui->discard1_25->setPixmap(discardMj1_25);
        }else if (cnt == 25) {
            QPixmap discardMj1_26(imgPath + res + imgFile);
            discardMj1_26.scaled(ui->discard1_26->size(), Qt::IgnoreAspectRatio);
            ui->discard1_26->setScaledContents(true);
            ui->discard1_26->setPixmap(discardMj1_26);
        }else if (cnt == 26) {
            QPixmap discardMj1_27(imgPath + res + imgFile);
            discardMj1_27.scaled(ui->discard1_27->size(), Qt::IgnoreAspectRatio);
            ui->discard1_27->setScaledContents(true);
            ui->discard1_27->setPixmap(discardMj1_27);
        }else if (cnt == 27) {
            QPixmap discardMj1_28(imgPath + res + imgFile);
            discardMj1_28.scaled(ui->discard1_28->size(), Qt::IgnoreAspectRatio);
            ui->discard1_28->setScaledContents(true);
            ui->discard1_28->setPixmap(discardMj1_28);
        }else if (cnt == 28) {
            QPixmap discardMj1_29(imgPath + res + imgFile);
            discardMj1_29.scaled(ui->discard1_29->size(), Qt::IgnoreAspectRatio);
            ui->discard1_29->setScaledContents(true);
            ui->discard1_29->setPixmap(discardMj1_29);
        }else if (cnt == 29) {
            QPixmap discardMj1_30(imgPath + res + imgFile);
            discardMj1_30.scaled(ui->discard1_30->size(), Qt::IgnoreAspectRatio);
            ui->discard1_30->setScaledContents(true);
            ui->discard1_30->setPixmap(discardMj1_30);
        }else if (cnt == 30) {
            QPixmap discardMj1_31(imgPath + res + imgFile);
            discardMj1_31.scaled(ui->discard1_31->size(), Qt::IgnoreAspectRatio);
            ui->discard1_31->setScaledContents(true);
            ui->discard1_31->setPixmap(discardMj1_31);
        }else if (cnt == 31) {
            QPixmap discardMj1_32(imgPath + res + imgFile);
            discardMj1_32.scaled(ui->discard1_32->size(), Qt::IgnoreAspectRatio);
            ui->discard1_32->setScaledContents(true);
            ui->discard1_32->setPixmap(discardMj1_32);
        }else if (cnt == 32) {
            QPixmap discardMj1_33(imgPath + res + imgFile);
            discardMj1_33.scaled(ui->discard1_33->size(), Qt::IgnoreAspectRatio);
            ui->discard1_33->setScaledContents(true);
            ui->discard1_33->setPixmap(discardMj1_33);
        }else if (cnt == 33) {
            QPixmap discardMj1_34(imgPath + res + imgFile);
            discardMj1_34.scaled(ui->discard1_34->size(), Qt::IgnoreAspectRatio);
            ui->discard1_34->setScaledContents(true);
            ui->discard1_34->setPixmap(discardMj1_34);
        }else if (cnt == 34) {
            QPixmap discardMj1_35(imgPath + res + imgFile);
            discardMj1_35.scaled(ui->discard1_35->size(), Qt::IgnoreAspectRatio);
            ui->discard1_35->setScaledContents(true);
            ui->discard1_35->setPixmap(discardMj1_35);
        }else if (cnt == 35) {
            QPixmap discardMj1_36(imgPath + res + imgFile);
            discardMj1_36.scaled(ui->discard1_36->size(), Qt::IgnoreAspectRatio);
            ui->discard1_36->setScaledContents(true);
            ui->discard1_36->setPixmap(discardMj1_36);
        }else if (cnt == 36) {
            QPixmap discardMj1_37(imgPath + res + imgFile);
            discardMj1_37.scaled(ui->discard1_37->size(), Qt::IgnoreAspectRatio);
            ui->discard1_37->setScaledContents(true);
            ui->discard1_37->setPixmap(discardMj1_37);
        }else if (cnt == 37) {
            QPixmap discardMj1_38(imgPath + res + imgFile);
            discardMj1_38.scaled(ui->discard1_38->size(), Qt::IgnoreAspectRatio);
            ui->discard1_38->setScaledContents(true);
            ui->discard1_38->setPixmap(discardMj1_38);
        }else if (cnt == 38) {
            QPixmap discardMj1_39(imgPath + res + imgFile);
            discardMj1_39.scaled(ui->discard1_39->size(), Qt::IgnoreAspectRatio);
            ui->discard1_39->setScaledContents(true);
            ui->discard1_39->setPixmap(discardMj1_39);
        }else if (cnt == 39) {
            QPixmap discardMj1_40(imgPath + res + imgFile);
            discardMj1_40.scaled(ui->discard1_40->size(), Qt::IgnoreAspectRatio);
            ui->discard1_40->setScaledContents(true);
            ui->discard1_40->setPixmap(discardMj1_40);
        }else if (cnt == 40) {
            QPixmap discardMj1_41(imgPath + res + imgFile);
            discardMj1_41.scaled(ui->discard1_41->size(), Qt::IgnoreAspectRatio);
            ui->discard1_41->setScaledContents(true);
            ui->discard1_41->setPixmap(discardMj1_41);
        }else if (cnt == 41) {
            QPixmap discardMj1_42(imgPath + res + imgFile);
            discardMj1_42.scaled(ui->discard1_42->size(), Qt::IgnoreAspectRatio);
            ui->discard1_42->setScaledContents(true);
            ui->discard1_42->setPixmap(discardMj1_42);
        }else if (cnt == 42) {
            QPixmap discardMj1_43(imgPath + res + imgFile);
            discardMj1_43.scaled(ui->discard1_43->size(), Qt::IgnoreAspectRatio);
            ui->discard1_43->setScaledContents(true);
            ui->discard1_43->setPixmap(discardMj1_43);
        }else if (cnt == 43) {
            QPixmap discardMj1_44(imgPath + res + imgFile);
            discardMj1_44.scaled(ui->discard1_44->size(), Qt::IgnoreAspectRatio);
            ui->discard1_44->setScaledContents(true);
            ui->discard1_44->setPixmap(discardMj1_44);
        }else if (cnt == 44) {
            QPixmap discardMj1_45(imgPath + res + imgFile);
            discardMj1_45.scaled(ui->discard1_45->size(), Qt::IgnoreAspectRatio);
            ui->discard1_45->setScaledContents(true);
            ui->discard1_45->setPixmap(discardMj1_45);
        }else if (cnt == 45) {
            QPixmap discardMj1_46(imgPath + res + imgFile);
            discardMj1_46.scaled(ui->discard1_46->size(), Qt::IgnoreAspectRatio);
            ui->discard1_46->setScaledContents(true);
            ui->discard1_46->setPixmap(discardMj1_46);
        }else if (cnt == 46) {
            QPixmap discardMj1_47(imgPath + res + imgFile);
            discardMj1_47.scaled(ui->discard1_47->size(), Qt::IgnoreAspectRatio);
            ui->discard1_47->setScaledContents(true);
            ui->discard1_47->setPixmap(discardMj1_47);
        }else if (cnt == 47) {
            QPixmap discardMj1_48(imgPath + res + imgFile);
            discardMj1_48.scaled(ui->discard1_48->size(), Qt::IgnoreAspectRatio);
            ui->discard1_48->setScaledContents(true);
            ui->discard1_48->setPixmap(discardMj1_48);
        }else if (cnt == 48) {
            QPixmap discardMj1_49(imgPath + res + imgFile);
            discardMj1_49.scaled(ui->discard1_49->size(), Qt::IgnoreAspectRatio);
            ui->discard1_49->setScaledContents(true);
            ui->discard1_49->setPixmap(discardMj1_49);
        }else if (cnt == 49) {
            QPixmap discardMj1_50(imgPath + res + imgFile);
            discardMj1_50.scaled(ui->discard1_50->size(), Qt::IgnoreAspectRatio);
            ui->discard1_50->setScaledContents(true);
            ui->discard1_50->setPixmap(discardMj1_50);
        }else if (cnt == 50) {
            QPixmap discardMj1_51(imgPath + res + imgFile);
            discardMj1_51.scaled(ui->discard1_51->size(), Qt::IgnoreAspectRatio);
            ui->discard1_51->setScaledContents(true);
            ui->discard1_51->setPixmap(discardMj1_51);
        }else if (cnt == 51) {
            QPixmap discardMj1_52(imgPath + res + imgFile);
            discardMj1_52.scaled(ui->discard1_52->size(), Qt::IgnoreAspectRatio);
            ui->discard1_52->setScaledContents(true);
            ui->discard1_52->setPixmap(discardMj1_52);
        }else if (cnt == 52) {
            QPixmap discardMj1_53(imgPath + res + imgFile);
            discardMj1_53.scaled(ui->discard1_53->size(), Qt::IgnoreAspectRatio);
            ui->discard1_53->setScaledContents(true);
            ui->discard1_53->setPixmap(discardMj1_53);
        }else if (cnt == 53) {
            QPixmap discardMj1_54(imgPath + res + imgFile);
            discardMj1_54.scaled(ui->discard1_54->size(), Qt::IgnoreAspectRatio);
            ui->discard1_54->setScaledContents(true);
            ui->discard1_54->setPixmap(discardMj1_54);
        }else if (cnt == 54) {
            QPixmap discardMj1_55(imgPath + res + imgFile);
            discardMj1_55.scaled(ui->discard1_55->size(), Qt::IgnoreAspectRatio);
            ui->discard1_55->setScaledContents(true);
            ui->discard1_55->setPixmap(discardMj1_55);
        }else if (cnt == 55) {
            QPixmap discardMj1_56(imgPath + res + imgFile);
            discardMj1_56.scaled(ui->discard1_56->size(), Qt::IgnoreAspectRatio);
            ui->discard1_56->setScaledContents(true);
            ui->discard1_56->setPixmap(discardMj1_56);
        }else if (cnt == 56) {
            QPixmap discardMj1_57(imgPath + res + imgFile);
            discardMj1_57.scaled(ui->discard1_57->size(), Qt::IgnoreAspectRatio);
            ui->discard1_57->setScaledContents(true);
            ui->discard1_57->setPixmap(discardMj1_57);
        }else if (cnt == 57) {
            QPixmap discardMj1_58(imgPath + res + imgFile);
            discardMj1_58.scaled(ui->discard1_58->size(), Qt::IgnoreAspectRatio);
            ui->discard1_58->setScaledContents(true);
            ui->discard1_58->setPixmap(discardMj1_58);
        }else if (cnt == 58) {
            QPixmap discardMj1_59(imgPath + res + imgFile);
            discardMj1_59.scaled(ui->discard1_59->size(), Qt::IgnoreAspectRatio);
            ui->discard1_59->setScaledContents(true);
            ui->discard1_59->setPixmap(discardMj1_59);
        }else if (cnt == 59) {
            QPixmap discardMj1_60(imgPath + res + imgFile);
            discardMj1_60.scaled(ui->discard1_60->size(), Qt::IgnoreAspectRatio);
            ui->discard1_60->setScaledContents(true);
            ui->discard1_60->setPixmap(discardMj1_60);
        }else if (cnt == 60) {
            QPixmap discardMj1_61(imgPath + res + imgFile);
            discardMj1_61.scaled(ui->discard1_61->size(), Qt::IgnoreAspectRatio);
            ui->discard1_61->setScaledContents(true);
            ui->discard1_61->setPixmap(discardMj1_61);
        }else if (cnt == 61) {
            QPixmap discardMj1_62(imgPath + res + imgFile);
            discardMj1_62.scaled(ui->discard1_62->size(), Qt::IgnoreAspectRatio);
            ui->discard1_62->setScaledContents(true);
            ui->discard1_62->setPixmap(discardMj1_62);
        }else if (cnt == 62) {
            QPixmap discardMj1_63(imgPath + res + imgFile);
            discardMj1_63.scaled(ui->discard1_63->size(), Qt::IgnoreAspectRatio);
            ui->discard1_63->setScaledContents(true);
            ui->discard1_63->setPixmap(discardMj1_63);
        }else if (cnt == 63) {
            QPixmap discardMj1_64(imgPath + res + imgFile);
            discardMj1_64.scaled(ui->discard1_64->size(), Qt::IgnoreAspectRatio);
            ui->discard1_64->setScaledContents(true);
            ui->discard1_64->setPixmap(discardMj1_64);
        }else if (cnt == 64) {
            QPixmap discardMj1_65(imgPath + res + imgFile);
            discardMj1_65.scaled(ui->discard1_65->size(), Qt::IgnoreAspectRatio);
            ui->discard1_65->setScaledContents(true);
            ui->discard1_65->setPixmap(discardMj1_65);
        }else if (cnt == 65) {
            QPixmap discardMj1_66(imgPath + res + imgFile);
            discardMj1_66.scaled(ui->discard1_66->size(), Qt::IgnoreAspectRatio);
            ui->discard1_66->setScaledContents(true);
            ui->discard1_66->setPixmap(discardMj1_66);
        }else if (cnt == 66) {
            QPixmap discardMj1_67(imgPath + res + imgFile);
            discardMj1_67.scaled(ui->discard1_67->size(), Qt::IgnoreAspectRatio);
            ui->discard1_67->setScaledContents(true);
            ui->discard1_67->setPixmap(discardMj1_67);
        }else if (cnt == 67) {
            QPixmap discardMj1_68(imgPath + res + imgFile);
            discardMj1_68.scaled(ui->discard1_68->size(), Qt::IgnoreAspectRatio);
            ui->discard1_68->setScaledContents(true);
            ui->discard1_68->setPixmap(discardMj1_68);
        }else if (cnt == 68) {
            QPixmap discardMj1_69(imgPath + res + imgFile);
            discardMj1_69.scaled(ui->discard1_69->size(), Qt::IgnoreAspectRatio);
            ui->discard1_69->setScaledContents(true);
            ui->discard1_69->setPixmap(discardMj1_69);
        }else if (cnt == 69) {
            QPixmap discardMj1_70(imgPath + res + imgFile);
            discardMj1_70.scaled(ui->discard1_70->size(), Qt::IgnoreAspectRatio);
            ui->discard1_70->setScaledContents(true);
            ui->discard1_70->setPixmap(discardMj1_70);
        }else if (cnt == 70) {
            QPixmap discardMj1_71(imgPath + res + imgFile);
            discardMj1_71.scaled(ui->discard1_71->size(), Qt::IgnoreAspectRatio);
            ui->discard1_71->setScaledContents(true);
            ui->discard1_71->setPixmap(discardMj1_71);
        }else if (cnt == 71) {
            QPixmap discardMj1_72(imgPath + res + imgFile);
            discardMj1_72.scaled(ui->discard1_72->size(), Qt::IgnoreAspectRatio);
            ui->discard1_72->setScaledContents(true);
            ui->discard1_72->setPixmap(discardMj1_72);
        }else if (cnt == 72) {
            QPixmap discardMj1_73(imgPath + res + imgFile);
            discardMj1_73.scaled(ui->discard1_73->size(), Qt::IgnoreAspectRatio);
            ui->discard1_73->setScaledContents(true);
            ui->discard1_73->setPixmap(discardMj1_73);
        }else if (cnt == 73) {
            QPixmap discardMj1_74(imgPath + res + imgFile);
            discardMj1_74.scaled(ui->discard1_74->size(), Qt::IgnoreAspectRatio);
            ui->discard1_74->setScaledContents(true);
            ui->discard1_74->setPixmap(discardMj1_74);
        }else if (cnt == 74) {
            QPixmap discardMj1_75(imgPath + res + imgFile);
            discardMj1_75.scaled(ui->discard1_75->size(), Qt::IgnoreAspectRatio);
            ui->discard1_75->setScaledContents(true);
            ui->discard1_75->setPixmap(discardMj1_75);
        }else if (cnt == 75) {
            QPixmap discardMj1_76(imgPath + res + imgFile);
            discardMj1_76.scaled(ui->discard1_76->size(), Qt::IgnoreAspectRatio);
            ui->discard1_76->setScaledContents(true);
            ui->discard1_76->setPixmap(discardMj1_76);
        }else if (cnt == 76) {
            QPixmap discardMj1_77(imgPath + res + imgFile);
            discardMj1_77.scaled(ui->discard1_77->size(), Qt::IgnoreAspectRatio);
            ui->discard1_77->setScaledContents(true);
            ui->discard1_77->setPixmap(discardMj1_77);
        }else if (cnt == 77) {
            QPixmap discardMj1_78(imgPath + res + imgFile);
            discardMj1_78.scaled(ui->discard1_78->size(), Qt::IgnoreAspectRatio);
            ui->discard1_78->setScaledContents(true);
            ui->discard1_78->setPixmap(discardMj1_78);
        }else if (cnt == 78) {
            QPixmap discardMj1_79(imgPath + res + imgFile);
            discardMj1_79.scaled(ui->discard1_79->size(), Qt::IgnoreAspectRatio);
            ui->discard1_79->setScaledContents(true);
            ui->discard1_79->setPixmap(discardMj1_79);
        }else if (cnt == 79) {
            QPixmap discardMj1_80(imgPath + res + imgFile);
            discardMj1_80.scaled(ui->discard1_80->size(), Qt::IgnoreAspectRatio);
            ui->discard1_80->setScaledContents(true);
            ui->discard1_80->setPixmap(discardMj1_80);
        }else if (cnt == 80) {
            QPixmap discardMj1_81(imgPath + res + imgFile);
            discardMj1_81.scaled(ui->discard1_81->size(), Qt::IgnoreAspectRatio);
            ui->discard1_81->setScaledContents(true);
            ui->discard1_81->setPixmap(discardMj1_81);
        }else if (cnt == 81) {
            QPixmap discardMj1_82(imgPath + res + imgFile);
            discardMj1_82.scaled(ui->discard1_82->size(), Qt::IgnoreAspectRatio);
            ui->discard1_82->setScaledContents(true);
            ui->discard1_82->setPixmap(discardMj1_82);
        }else if (cnt == 82) {
            QPixmap discardMj1_83(imgPath + res + imgFile);
            discardMj1_83.scaled(ui->discard1_83->size(), Qt::IgnoreAspectRatio);
            ui->discard1_83->setScaledContents(true);
            ui->discard1_83->setPixmap(discardMj1_83);
        }else if (cnt == 83) {
            QPixmap discardMj1_84(imgPath + res + imgFile);
            discardMj1_84.scaled(ui->discard1_84->size(), Qt::IgnoreAspectRatio);
            ui->discard1_84->setScaledContents(true);
            ui->discard1_84->setPixmap(discardMj1_84);
        }else if (cnt == 84) {
            QPixmap discardMj1_85(imgPath + res + imgFile);
            discardMj1_85.scaled(ui->discard1_85->size(), Qt::IgnoreAspectRatio);
            ui->discard1_85->setScaledContents(true);
            ui->discard1_85->setPixmap(discardMj1_85);
        }else if (cnt == 85) {
            QPixmap discardMj1_86(imgPath + res + imgFile);
            discardMj1_86.scaled(ui->discard1_86->size(), Qt::IgnoreAspectRatio);
            ui->discard1_86->setScaledContents(true);
            ui->discard1_86->setPixmap(discardMj1_86);
        }else if (cnt == 86) {
            QPixmap discardMj1_87(imgPath + res + imgFile);
            discardMj1_87.scaled(ui->discard1_87->size(), Qt::IgnoreAspectRatio);
            ui->discard1_87->setScaledContents(true);
            ui->discard1_87->setPixmap(discardMj1_87);
        }else if (cnt == 87) {
            QPixmap discardMj1_88(imgPath + res + imgFile);
            discardMj1_88.scaled(ui->discard1_88->size(), Qt::IgnoreAspectRatio);
            ui->discard1_88->setScaledContents(true);
            ui->discard1_88->setPixmap(discardMj1_88);
        }else if (cnt == 89) {
            QPixmap discardMj1_89(imgPath + res + imgFile);
            discardMj1_89.scaled(ui->discard1_89->size(), Qt::IgnoreAspectRatio);
            ui->discard1_89->setScaledContents(true);
            ui->discard1_89->setPixmap(discardMj1_89);
        }else if (cnt == 90) {
            QPixmap discardMj1_91(imgPath + res + imgFile);
            discardMj1_91.scaled(ui->discard1_91->size(), Qt::IgnoreAspectRatio);
            ui->discard1_91->setScaledContents(true);
            ui->discard1_91->setPixmap(discardMj1_91);
        }else if (cnt == 91) {
            QPixmap discardMj1_92(imgPath + res + imgFile);
            discardMj1_92.scaled(ui->discard1_92->size(), Qt::IgnoreAspectRatio);
            ui->discard1_92->setScaledContents(true);
            ui->discard1_92->setPixmap(discardMj1_92);
        }else if (cnt == 92) {
            QPixmap discardMj1_93(imgPath + res + imgFile);
            discardMj1_93.scaled(ui->discard1_93->size(), Qt::IgnoreAspectRatio);
            ui->discard1_93->setScaledContents(true);
            ui->discard1_93->setPixmap(discardMj1_93);
        }else if (cnt == 93) {
            QPixmap discardMj1_94(imgPath + res + imgFile);
            discardMj1_94.scaled(ui->discard1_94->size(), Qt::IgnoreAspectRatio);
            ui->discard1_94->setScaledContents(true);
            ui->discard1_94->setPixmap(discardMj1_94);
        }else if (cnt == 94) {
            QPixmap discardMj1_95(imgPath + res + imgFile);
            discardMj1_95.scaled(ui->discard1_95->size(), Qt::IgnoreAspectRatio);
            ui->discard1_95->setScaledContents(true);
            ui->discard1_95->setPixmap(discardMj1_95);
        }else if (cnt == 95) {
            QPixmap discardMj1_96(imgPath + res + imgFile);
            discardMj1_96.scaled(ui->discard1_96->size(), Qt::IgnoreAspectRatio);
            ui->discard1_96->setScaledContents(true);
            ui->discard1_96->setPixmap(discardMj1_96);
        }else if (cnt == 96) {
            QPixmap discardMj1_97(imgPath + res + imgFile);
            discardMj1_97.scaled(ui->discard1_97->size(), Qt::IgnoreAspectRatio);
            ui->discard1_97->setScaledContents(true);
            ui->discard1_97->setPixmap(discardMj1_97);
        }else if (cnt == 97) {
            QPixmap discardMj1_98(imgPath + res + imgFile);
            discardMj1_98.scaled(ui->discard1_98->size(), Qt::IgnoreAspectRatio);
            ui->discard1_98->setScaledContents(true);
            ui->discard1_98->setPixmap(discardMj1_98);
        }else if (cnt == 98) {
            QPixmap discardMj1_99(imgPath + res + imgFile);
            discardMj1_99.scaled(ui->discard1_99->size(), Qt::IgnoreAspectRatio);
            ui->discard1_99->setScaledContents(true);
            ui->discard1_99->setPixmap(discardMj1_99);
        }else if (cnt == 99) {
            QPixmap discardMj1_100(imgPath + res + imgFile);
            discardMj1_100.scaled(ui->discard1_100->size(), Qt::IgnoreAspectRatio);
            ui->discard1_100->setScaledContents(true);
            ui->discard1_100->setPixmap(discardMj1_100);
        }
        cnt++;
    }
}

//开始抓牌（判起手自摸）
void UIMainWindows::beginGameDisplay(std::list<Mj> &handOne, std::list<Mj> &handTwo, std::list<Mj> &handThree, std::list<Mj> &handFour)
{
    //确认庄家、确认开始拿牌玩家
    //拿的牌对应庄家
    if(zhuangjia ==0){//南
        handSouthMjs = handOne;
        handEastMjs = handTwo;
        handNorthMjs = handThree;
        handWestMjs = handFour;

        if(systemConfig.angang == 1){
            isConcealedKong(handSouthMjs, 0);//检测暗杠
            if(concealedKongNum[0] != 0){
               KongDisplay();
            }
        }

//        directionDisplay(0);
    }else if(zhuangjia ==1){//东
        handEastMjs = handOne;
        handNorthMjs = handTwo;
        handWestMjs = handThree;
        handSouthMjs = handFour;

        if(systemConfig.angang == 1){
            isConcealedKong(handEastMjs, 1);//检测暗杠
            if(concealedKongNum[1] != 0){
               KongDisplay();
            }
        }

//        directionDisplay(1);
    }else if(zhuangjia ==2){//北
        handNorthMjs = handOne;
        handWestMjs = handTwo;
        handSouthMjs = handThree;
        handEastMjs = handFour;

        if(systemConfig.angang == 1){
            isConcealedKong(handNorthMjs,2);//检测暗杠
            if(concealedKongNum[2] != 0){
               KongDisplay();
            }
        }

//        directionDisplay(2);
    }else if(zhuangjia ==3){//西
        handWestMjs   = handOne;
        handSouthMjs = handTwo;
        handEastMjs = handThree;
        handNorthMjs = handFour;

        if(systemConfig.angang == 1){
            isConcealedKong(handWestMjs, 3);//检测暗杠
            if(concealedKongNum[3] != 0){
               KongDisplay();
            }
        }

//        directionDisplay(3);
    }
    //展示手牌
    isDraw = true;
    southHandDisplay(handSouthMjs);
    eastHandDisplay(handEastMjs);
    northHandDisplay(handNorthMjs);
    westHandDisplay(handWestMjs);
    isDraw = false;


    //判起手自摸
    isWin4();//(有用)

    //设置遮罩层
    //ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
    //ui->justTakenLabel->setGeometry(1130,20,10,10);


}
//预测抓牌，为了演示用，可以展示每个玩家下一步可抓到的牌，默认10张
void UIMainWindows::southPredictionDisplay(const std::list<Mj> &predictionSouthMjs) const
{
    if (systemConfig.isPrediction==false)
        return ;
    //清空之前数据
    ui->predictionSouth1->clear();
    ui->predictionSouth2->clear();
    ui->predictionSouth3->clear();
    ui->predictionSouth4->clear();
    ui->predictionSouth5->clear();
    ui->predictionSouth6->clear();
    ui->predictionSouth7->clear();
    ui->predictionSouth8->clear();
    ui->predictionSouth9->clear();
    ui->predictionSouth10->clear();

    //显示新的预测牌
    QString imgPath = ":/image/";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: predictionSouthMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt == 0){
            QPixmap predictionSouth1(imgPath + res + imgFile);
            predictionSouth1.scaled(ui->predictionSouth1->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth1->setScaledContents(true);
            ui->predictionSouth1->setPixmap(predictionSouth1);
        }else if(cnt == 1){
            QPixmap predictionSouth2(imgPath + res + imgFile);
            predictionSouth2.scaled(ui->predictionSouth2->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth2->setScaledContents(true);
            ui->predictionSouth2->setPixmap(predictionSouth2);
        }else if(cnt == 2){
            QPixmap predictionSouth3(imgPath + res + imgFile);
            predictionSouth3.scaled(ui->predictionSouth3->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth3->setScaledContents(true);
            ui->predictionSouth3->setPixmap(predictionSouth3);
        }else if(cnt == 3){
            QPixmap predictionSouth4(imgPath + res + imgFile);
            predictionSouth4.scaled(ui->predictionSouth4->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth4->setScaledContents(true);
            ui->predictionSouth4->setPixmap(predictionSouth4);
        }else if(cnt == 4){
            QPixmap predictionSouth5(imgPath + res + imgFile);
            predictionSouth5.scaled(ui->predictionSouth5->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth5->setScaledContents(true);
            ui->predictionSouth5->setPixmap(predictionSouth5);
        }else if(cnt == 5){
            QPixmap predictionSouth6(imgPath + res + imgFile);
            predictionSouth6.scaled(ui->predictionSouth6->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth6->setScaledContents(true);
            ui->predictionSouth6->setPixmap(predictionSouth6);
        }else if(cnt == 6){
            QPixmap predictionSouth7(imgPath + res + imgFile);
            predictionSouth7.scaled(ui->predictionSouth7->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth7->setScaledContents(true);
            ui->predictionSouth7->setPixmap(predictionSouth7);
        }else if(cnt == 7){
            QPixmap predictionSouth8(imgPath + res + imgFile);
            predictionSouth8.scaled(ui->predictionSouth8->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth8->setScaledContents(true);
            ui->predictionSouth8->setPixmap(predictionSouth8);
        }else if(cnt == 8){
            QPixmap predictionSouth9(imgPath + res + imgFile);
            predictionSouth9.scaled(ui->predictionSouth9->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth9->setScaledContents(true);
            ui->predictionSouth9->setPixmap(predictionSouth9);
        }else if(cnt == 9){
            QPixmap predictionSouth10(imgPath + res + imgFile);
            predictionSouth10.scaled(ui->predictionSouth10->size(), Qt::IgnoreAspectRatio);
            ui->predictionSouth10->setScaledContents(true);
            ui->predictionSouth10->setPixmap(predictionSouth10);
        }
        cnt++;
    }
}

void UIMainWindows::eastPredictionDisplay(const std::list<Mj> &predictionEastMjs) const
{
    if (systemConfig.isPrediction==false)
        return ;
    //清空之前数据
    ui->predictionEast1->clear();
    ui->predictionEast2->clear();
    ui->predictionEast3->clear();
    ui->predictionEast4->clear();
    ui->predictionEast5->clear();
    ui->predictionEast6->clear();
    ui->predictionEast7->clear();
    ui->predictionEast8->clear();
    ui->predictionEast9->clear();
    ui->predictionEast10->clear();

    //显示新的预测牌
    QString imgPath = ":/image/r";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: predictionEastMjs){
        int number = i.getResult();
        QString res = QString::number(number);
        if(cnt == 0){
            QPixmap predictionEast1(imgPath + res + imgFile);
            predictionEast1.scaled(ui->predictionEast1->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast1->setScaledContents(true);
            ui->predictionEast1->setPixmap(predictionEast1);
        }else if(cnt == 1){
            QPixmap predictionEast2(imgPath + res + imgFile);
            predictionEast2.scaled(ui->predictionEast2->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast2->setScaledContents(true);
            ui->predictionEast2->setPixmap(predictionEast2);
        }else if(cnt == 2){
            QPixmap predictionEast3(imgPath + res + imgFile);
            predictionEast3.scaled(ui->predictionEast3->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast3->setScaledContents(true);
            ui->predictionEast3->setPixmap(predictionEast3);
        }else if(cnt == 3){
            QPixmap predictionEast4(imgPath + res + imgFile);
            predictionEast4.scaled(ui->predictionEast4->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast4->setScaledContents(true);
            ui->predictionEast4->setPixmap(predictionEast4);
        }else if(cnt == 4){
            QPixmap predictionEast5(imgPath + res + imgFile);
            predictionEast5.scaled(ui->predictionEast5->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast5->setScaledContents(true);
            ui->predictionEast5->setPixmap(predictionEast5);
        }else if(cnt == 5){
            QPixmap predictionEast6(imgPath + res + imgFile);
            predictionEast6.scaled(ui->predictionEast6->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast6->setScaledContents(true);
            ui->predictionEast6->setPixmap(predictionEast6);
        }else if(cnt == 6){
            QPixmap predictionEast7(imgPath + res + imgFile);
            predictionEast7.scaled(ui->predictionEast7->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast7->setScaledContents(true);
            ui->predictionEast7->setPixmap(predictionEast7);
        }else if(cnt == 7){
            QPixmap predictionEast8(imgPath + res + imgFile);
            predictionEast8.scaled(ui->predictionEast8->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast8->setScaledContents(true);
            ui->predictionEast8->setPixmap(predictionEast8);
        }else if(cnt == 8){
            QPixmap predictionEast9(imgPath + res + imgFile);
            predictionEast9.scaled(ui->predictionEast9->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast9->setScaledContents(true);
            ui->predictionEast9->setPixmap(predictionEast9);
        }else if(cnt == 9){
            QPixmap predictionEast10(imgPath + res + imgFile);
            predictionEast10.scaled(ui->predictionEast10->size(), Qt::IgnoreAspectRatio);
            ui->predictionEast10->setScaledContents(true);
            ui->predictionEast10->setPixmap(predictionEast10);
        }
        cnt++;
    }

}

void UIMainWindows::northPredictionDisplay(const std::list<Mj> &predictionNorthMjs) const
{
    if (systemConfig.isPrediction==false)
        return ;
    //清空之前数据
    ui->predictionNorth1->clear();
    ui->predictionNorth2->clear();
    ui->predictionNorth3->clear();
    ui->predictionNorth4->clear();
    ui->predictionNorth5->clear();
    ui->predictionNorth6->clear();
    ui->predictionNorth7->clear();
    ui->predictionNorth8->clear();
    ui->predictionNorth9->clear();
    ui->predictionNorth10->clear();

    //显示新的预测牌
    QString imgPath = ":/image/";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: predictionNorthMjs){
        int number = i.getResult();
        QString res = QString::number(number);

        if(cnt == 0){
            QPixmap predictionNorth1(imgPath + res + imgFile);
            predictionNorth1.scaled(ui->predictionNorth1->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth1->setScaledContents(true);
            ui->predictionNorth1->setPixmap(predictionNorth1);
        }else if(cnt == 1){
            QPixmap predictionNorth2(imgPath + res + imgFile);
            predictionNorth2.scaled(ui->predictionNorth2->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth2->setScaledContents(true);
            ui->predictionNorth2->setPixmap(predictionNorth2);
        }else if(cnt == 2){
            QPixmap predictionNorth3(imgPath + res + imgFile);
            predictionNorth3.scaled(ui->predictionNorth3->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth3->setScaledContents(true);
            ui->predictionNorth3->setPixmap(predictionNorth3);
        }else if(cnt == 3){
            QPixmap predictionNorth4(imgPath + res + imgFile);
            predictionNorth4.scaled(ui->predictionNorth4->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth4->setScaledContents(true);
            ui->predictionNorth4->setPixmap(predictionNorth4);
        }else if(cnt == 4){
            QPixmap predictionNorth5(imgPath + res + imgFile);
            predictionNorth5.scaled(ui->predictionNorth5->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth5->setScaledContents(true);
            ui->predictionNorth5->setPixmap(predictionNorth5);
        }else if(cnt == 5){
            QPixmap predictionNorth6(imgPath + res + imgFile);
            predictionNorth6.scaled(ui->predictionNorth6->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth6->setScaledContents(true);
            ui->predictionNorth6->setPixmap(predictionNorth6);
        }else if(cnt == 6){
            QPixmap predictionNorth7(imgPath + res + imgFile);
            predictionNorth7.scaled(ui->predictionNorth7->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth7->setScaledContents(true);
            ui->predictionNorth7->setPixmap(predictionNorth7);
        }else if(cnt == 7){
            QPixmap predictionNorth8(imgPath + res + imgFile);
            predictionNorth8.scaled(ui->predictionNorth8->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth8->setScaledContents(true);
            ui->predictionNorth8->setPixmap(predictionNorth8);
        }else if(cnt == 8){
            QPixmap predictionNorth9(imgPath + res + imgFile);
            predictionNorth9.scaled(ui->predictionNorth9->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth9->setScaledContents(true);
            ui->predictionNorth9->setPixmap(predictionNorth9);
        }else if(cnt == 9){
            QPixmap predictionNorth10(imgPath + res + imgFile);
            predictionNorth10.scaled(ui->predictionNorth10->size(), Qt::IgnoreAspectRatio);
            ui->predictionNorth10->setScaledContents(true);
            ui->predictionNorth10->setPixmap(predictionNorth10);
        }
        cnt++;
    }
}

void UIMainWindows::westPredictionDisplay(const std::list<Mj> &predictionWestMjs) const
{
    if (systemConfig.isPrediction==false)
        return ;
    //清空之前数据
    ui->predictionWest1->clear();
    ui->predictionWest2->clear();
    ui->predictionWest3->clear();
    ui->predictionWest4->clear();
    ui->predictionWest5->clear();
    ui->predictionWest6->clear();
    ui->predictionWest7->clear();
    ui->predictionWest8->clear();
    ui->predictionWest9->clear();
    ui->predictionWest10->clear();

    //显示新的预测牌
    QString imgPath = ":/image/l";
    QString imgFile = ".png";

    int cnt = 0;
    for(auto i: predictionWestMjs){
        int number = i.getResult();
        QString res = QString::number(number);
        if(cnt == 0){
            QPixmap predictionWest1(imgPath + res + imgFile);
            predictionWest1.scaled(ui->predictionWest1->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest1->setScaledContents(true);
            ui->predictionWest1->setPixmap(predictionWest1);
        }else if(cnt == 1){
            QPixmap predictionWest2(imgPath + res + imgFile);
            predictionWest2.scaled(ui->predictionWest2->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest2->setScaledContents(true);
            ui->predictionWest2->setPixmap(predictionWest2);
        }else if(cnt == 2){
            QPixmap predictionWest3(imgPath + res + imgFile);
            predictionWest3.scaled(ui->predictionWest3->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest3->setScaledContents(true);
            ui->predictionWest3->setPixmap(predictionWest3);
        }else if(cnt == 3){
            QPixmap predictionWest4(imgPath + res + imgFile);
            predictionWest4.scaled(ui->predictionWest4->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest4->setScaledContents(true);
            ui->predictionWest4->setPixmap(predictionWest4);
        }else if(cnt == 4){
            QPixmap predictionWest5(imgPath + res + imgFile);
            predictionWest5.scaled(ui->predictionWest5->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest5->setScaledContents(true);
            ui->predictionWest5->setPixmap(predictionWest5);
        }else if(cnt == 5){
            QPixmap predictionWest6(imgPath + res + imgFile);
            predictionWest6.scaled(ui->predictionWest6->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest6->setScaledContents(true);
            ui->predictionWest6->setPixmap(predictionWest6);
        }else if(cnt == 6){
            QPixmap predictionWest7(imgPath + res + imgFile);
            predictionWest7.scaled(ui->predictionWest7->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest7->setScaledContents(true);
            ui->predictionWest7->setPixmap(predictionWest7);
        }else if(cnt == 7){
            QPixmap predictionWest8(imgPath + res + imgFile);
            predictionWest8.scaled(ui->predictionWest8->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest8->setScaledContents(true);
            ui->predictionWest8->setPixmap(predictionWest8);
        }else if(cnt == 8){
            QPixmap predictionWest9(imgPath + res + imgFile);
            predictionWest9.scaled(ui->predictionWest9->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest9->setScaledContents(true);
            ui->predictionWest9->setPixmap(predictionWest9);
        }else if(cnt == 9){
            QPixmap predictionWest10(imgPath + res + imgFile);
            predictionWest10.scaled(ui->predictionWest10->size(), Qt::IgnoreAspectRatio);
            ui->predictionWest10->setScaledContents(true);
            ui->predictionWest10->setPixmap(predictionWest10);
        }
        cnt++;
    }

}
//用箭头指示当前打牌玩家
void UIMainWindows::directionDisplay(const int dapaiWanjia)
{
    //撤回
    dapaiWanjiaStack.push(dapaiWanjia);

    if(dapaiWanjia == 0){
        ui->directionSouth->clear();
        ui->directionEast->clear();
        ui->directionNorth->clear();
        ui->directionWest->clear();

        QPixmap directionSouth(":/image/south.png");
        directionSouth.scaled(ui->directionSouth->size(), Qt::IgnoreAspectRatio);
        ui->directionSouth->setScaledContents(true);
        ui->directionSouth->setPixmap(directionSouth);

        int x = 230, y = 608;
        int w = 30, h = 25;

        int cnt = 0;
        for(auto i:handSouthMjs)
            if(i.getPaizhuangtai() != 0)
                cnt++;

        if(chowType.size() > 1)
            cnt--;

        if(cnt != 0){//出现吃碰杠
            x = 260 + 20 * cnt + 10;
        }

        ui->directionSouth->setGeometry(x, y, w, h);


//        QPoint pos;
//        x = ui->directionSouth->x();
//        y = ui->directionSouth->y();
//        pos.setX(x+88);
//        pos.setY(y+85);
//        QCursor::setPos(pos);

//        QPoint pos = QCursor::pos();

    }else if(dapaiWanjia == 1){
        ui->directionSouth->clear();
        ui->directionEast->clear();
        ui->directionNorth->clear();
        ui->directionWest->clear();

        QPixmap directionEast(":/image/east.png");
        directionEast.scaled(ui->directionEast->size(), Qt::IgnoreAspectRatio);
        ui->directionEast->setScaledContents(true);
        ui->directionEast->setPixmap(directionEast);

        int x = 976, y = 674;
        int w = 25, h = 30;

        int cnt = 0;
        for(auto i:handEastMjs){
            if(i.getPaizhuangtai() != 0){
                cnt++;
             }
        }

        if(chowType.size() > 1){
            cnt--;
        }

        if(cnt != 0){
            y = 674 - 20 * cnt - 40;
        }

        ui->directionEast->setGeometry(x, y, w, h);

    }else if(dapaiWanjia == 2){
        ui->directionSouth->clear();
        ui->directionEast->clear();
        ui->directionNorth->clear();
        ui->directionWest->clear();

        QPixmap directionNorth(":/image/north.png");
        directionNorth.scaled(ui->directionNorth->size(), Qt::IgnoreAspectRatio);
        ui->directionNorth->setScaledContents(true);
        ui->directionNorth->setPixmap(directionNorth);

        int x = 890, y = 48;
        int w = 30, h = 25;

        int cnt = 0;
        for(auto i:handNorthMjs){
            if(i.getPaizhuangtai() != 0){
                cnt++;
             }
        }

        if(chowType.size() > 1){
            cnt--;
        }

        if(cnt != 0){
            x = 890 - 20 * cnt - 40;
        }

        ui->directionNorth->setGeometry(x, y, w, h);

    }else if(dapaiWanjia == 3){
        ui->directionSouth->clear();
        ui->directionEast->clear();
        ui->directionNorth->clear();
        ui->directionWest->clear();

        QPixmap directionWest(":/image/west.png");
        directionWest.scaled(ui->directionWest->size(), Qt::IgnoreAspectRatio);
        ui->directionWest->setScaledContents(true);
        ui->directionWest->setPixmap(directionWest);

        int x = 166, y = 5;
        int w = 25, h = 30;

        int cnt = 0;
        for(auto i:handWestMjs){
            if(i.getPaizhuangtai() != 0){
                cnt++;
             }
        }

        if(chowType.size() > 1){
            cnt--;
        }

        if(cnt != 0){
            y = 35 + 20 * cnt + 10;
        }

        ui->directionWest->setGeometry(x, y, w, h);
    }

}
//吃牌展示
void UIMainWindows::ChowDisplay()
{
    if(isSouthChow == true){
        QPixmap statusSouthChow(":/image/chi.png");
        statusSouthChow.scaled(ui->statusSouthChow->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthChow->setScaledContents(true);
        ui->statusSouthChow->setPixmap(statusSouthChow);

        QPixmap statusSouthCheck(":/image/guo.png");
        statusSouthCheck.scaled(ui->statusSouthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthCheck->setScaledContents(true);
        ui->statusSouthCheck->setPixmap(statusSouthCheck);
    }else if(isEastChow == true){
        QPixmap statusEastChow(":/image/chi.png");
        statusEastChow.scaled(ui->statusEastChow->size(), Qt::IgnoreAspectRatio);
        ui->statusEastChow->setScaledContents(true);
        ui->statusEastChow->setPixmap(statusEastChow);

        QPixmap statusEastCheck(":/image/guo.png");
        statusEastCheck.scaled(ui->statusEastCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusEastCheck->setScaledContents(true);
        ui->statusEastCheck->setPixmap(statusEastCheck);
    }else if(isNorthChow == true){
        QPixmap statusNorthChow(":/image/chi.png");
        statusNorthChow.scaled(ui->statusNorthChow->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthChow->setScaledContents(true);
        ui->statusNorthChow->setPixmap(statusNorthChow);

        QPixmap statusNorthCheck(":/image/guo.png");
        statusNorthCheck.scaled(ui->statusNorthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthCheck->setScaledContents(true);
        ui->statusNorthCheck->setPixmap(statusNorthCheck);
    }else if(isWestChow == true){
        QPixmap statusWestChow(":/image/chi.png");
        statusWestChow.scaled(ui->statusWestChow->size(), Qt::IgnoreAspectRatio);
        ui->statusWestChow->setScaledContents(true);
        ui->statusWestChow->setPixmap(statusWestChow);

        QPixmap statusWestCheck(":/image/guo.png");
        statusWestCheck.scaled(ui->statusWestCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusWestCheck->setScaledContents(true);
        ui->statusWestCheck->setPixmap(statusWestCheck);
    }

}
//碰牌展示
void UIMainWindows::PongDisplay()
{
    if(isSouthPong == true){
        QPixmap statusSouthPong(":/image/peng.png");
        statusSouthPong.scaled(ui->statusSouthPong->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthPong->setScaledContents(true);
        ui->statusSouthPong->setPixmap(statusSouthPong);

        QPixmap statusSouthCheck(":/image/guo.png");
        statusSouthCheck.scaled(ui->statusSouthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthCheck->setScaledContents(true);
        ui->statusSouthCheck->setPixmap(statusSouthCheck);
    }else if(isEastPong == true){
        QPixmap statusEastPong(":/image/peng.png");
        statusEastPong.scaled(ui->statusEastPong->size(), Qt::IgnoreAspectRatio);
        ui->statusEastPong->setScaledContents(true);
        ui->statusEastPong->setPixmap(statusEastPong);

        QPixmap statusEastCheck(":/image/guo.png");
        statusEastCheck.scaled(ui->statusEastCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusEastCheck->setScaledContents(true);
        ui->statusEastCheck->setPixmap(statusEastCheck);
    }else if(isNorthPong == true){
        QPixmap statusNorthPong(":/image/peng.png");
        statusNorthPong.scaled(ui->statusNorthPong->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthPong->setScaledContents(true);
        ui->statusNorthPong->setPixmap(statusNorthPong);

        QPixmap statusNorthCheck(":/image/guo.png");
        statusNorthCheck.scaled(ui->statusNorthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthCheck->setScaledContents(true);
        ui->statusNorthCheck->setPixmap(statusNorthCheck);
    }else if(isWestPong == true){
        QPixmap statusWestPong(":/image/peng.png");
        statusWestPong.scaled(ui->statusWestPong->size(), Qt::IgnoreAspectRatio);
        ui->statusWestPong->setScaledContents(true);
        ui->statusWestPong->setPixmap(statusWestPong);

        QPixmap statusWestCheck(":/image/guo.png");
        statusWestCheck.scaled(ui->statusWestCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusWestCheck->setScaledContents(true);
        ui->statusWestCheck->setPixmap(statusWestCheck);
    }
}
//杠显示（暗杠不显示过）
void UIMainWindows::KongDisplay()
{
    //暗杠不显示过
    if(isSouthKong == true ){
        QPixmap statusSouthKong(":/image/gang.png");
        statusSouthKong.scaled(ui-> statusSouthKong->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthKong->setScaledContents(true);
        ui->statusSouthKong->setPixmap( statusSouthKong);

        QPixmap statusSouthCheck(":/image/guo.png");
        statusSouthCheck.scaled(ui->statusSouthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthCheck->setScaledContents(true);
        ui->statusSouthCheck->setPixmap(statusSouthCheck);
    }else if(isEastKong == true ){
        QPixmap statusEastKong(":/image/gang.png");
        statusEastKong.scaled(ui-> statusEastKong->size(), Qt::IgnoreAspectRatio);
        ui->statusEastKong->setScaledContents(true);
        ui->statusEastKong->setPixmap( statusEastKong);

        QPixmap statusEastCheck(":/image/guo.png");
        statusEastCheck.scaled(ui->statusEastCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusEastCheck->setScaledContents(true);
        ui->statusEastCheck->setPixmap(statusEastCheck);
    }else if(isNorthKong == true){
        QPixmap statusNorthKong(":/image/gang.png");
        statusNorthKong.scaled(ui-> statusNorthKong->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthKong->setScaledContents(true);
        ui->statusNorthKong->setPixmap( statusNorthKong);

        QPixmap statusNorthCheck(":/image/guo.png");
        statusNorthCheck.scaled(ui->statusNorthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthCheck->setScaledContents(true);
        ui->statusNorthCheck->setPixmap(statusNorthCheck);
    }else if(isWestKong == true){
        QPixmap statusWestKong(":/image/gang.png");
        statusWestKong.scaled(ui-> statusWestKong->size(), Qt::IgnoreAspectRatio);
        ui->statusWestKong->setScaledContents(true);
        ui->statusWestKong->setPixmap( statusWestKong);

        QPixmap statusWestCheck(":/image/guo.png");
        statusWestCheck.scaled(ui->statusWestCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusWestCheck->setScaledContents(true);
        ui->statusWestCheck->setPixmap(statusWestCheck);
    }else if( concealedKongNum[0] > 0){//暗杠，不显示过
        QPixmap statusSouthKong(":/image/gang.png");
        statusSouthKong.scaled(ui-> statusSouthKong->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthKong->setScaledContents(true);
        ui->statusSouthKong->setPixmap( statusSouthKong);
    }else if(concealedKongNum[1] > 0){
        QPixmap statusEastKong(":/image/gang.png");
        statusEastKong.scaled(ui-> statusEastKong->size(), Qt::IgnoreAspectRatio);
        ui->statusEastKong->setScaledContents(true);
        ui->statusEastKong->setPixmap( statusEastKong);
    }else if(concealedKongNum[2] > 0){
        QPixmap statusNorthKong(":/image/gang.png");
        statusNorthKong.scaled(ui-> statusNorthKong->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthKong->setScaledContents(true);
        ui->statusNorthKong->setPixmap( statusNorthKong);
    }else if(concealedKongNum[3] > 0){
        QPixmap statusWestKong(":/image/gang.png");
        statusWestKong.scaled(ui-> statusWestKong->size(), Qt::IgnoreAspectRatio);
        ui->statusWestKong->setScaledContents(true);
        ui->statusWestKong->setPixmap( statusWestKong);
    }
}
//过牌显示
void UIMainWindows::checkDisplay()
{
    if(dapaiWanjia == 0){
        QPixmap statusSouthCheck(":/image/guo.png");
        statusSouthCheck.scaled(ui->statusSouthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthCheck->setScaledContents(true);
        ui->statusSouthCheck->setPixmap(statusSouthCheck);
    }else if(dapaiWanjia == 1){
        QPixmap statusEastCheck(":/image/guo.png");
        statusEastCheck.scaled(ui->statusEastCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusEastCheck->setScaledContents(true);
        ui->statusEastCheck->setPixmap(statusEastCheck);
    }else if(dapaiWanjia == 2){
        QPixmap statusNorthCheck(":/image/guo.png");
        statusNorthCheck.scaled(ui->statusNorthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthCheck->setScaledContents(true);
        ui->statusNorthCheck->setPixmap(statusNorthCheck);
    }else if(dapaiWanjia == 3){
        QPixmap statusWestCheck(":/image/guo.png");
        statusWestCheck.scaled(ui->statusWestCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusWestCheck->setScaledContents(true);
        ui->statusWestCheck->setPixmap(statusWestCheck);
    }
}
//赢家展示
void UIMainWindows::winDisplay()
{
    if(isSouthWin == true){
        QPixmap statusSouthWin(":/image/hu.png");
        statusSouthWin.scaled(ui->statusSouthWin->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthWin->setScaledContents(true);
        ui->statusSouthWin->setPixmap(statusSouthWin);

        QPixmap statusSouthCheck(":/image/guo.png");
        statusSouthCheck.scaled(ui->statusSouthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthCheck->setScaledContents(true);
        ui->statusSouthCheck->setPixmap(statusSouthCheck);
    }else if(isEastWin == true){
        QPixmap statusEastWin(":/image/hu.png");
        statusEastWin.scaled(ui->statusEastWin->size(), Qt::IgnoreAspectRatio);
        ui->statusEastWin->setScaledContents(true);
        ui->statusEastWin->setPixmap(statusEastWin);

        QPixmap statusEastCheck(":/image/guo.png");
        statusEastCheck.scaled(ui->statusEastCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusEastCheck->setScaledContents(true);
        ui->statusEastCheck->setPixmap(statusEastCheck);
    }else if(isNorthWin == true){
        QPixmap statusNorthWin(":/image/hu.png");
        statusNorthWin.scaled(ui->statusNorthWin->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthWin->setScaledContents(true);
        ui->statusNorthWin->setPixmap(statusNorthWin);

        QPixmap statusNorthCheck(":/image/guo.png");
        statusNorthCheck.scaled(ui->statusNorthCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthCheck->setScaledContents(true);
        ui->statusNorthCheck->setPixmap(statusNorthCheck);
    }else if(isWestWin == true){
        QPixmap statusWestWin(":/image/hu.png");
        statusWestWin.scaled(ui->statusWestWin->size(), Qt::IgnoreAspectRatio);
        ui->statusWestWin->setScaledContents(true);
        ui->statusWestWin->setPixmap(statusWestWin);

        QPixmap statusWestCheck(":/image/guo.png");
        statusWestCheck.scaled(ui->statusWestCheck->size(), Qt::IgnoreAspectRatio);
        ui->statusWestCheck->setScaledContents(true);
        ui->statusWestCheck->setPixmap(statusWestCheck);
    }
}
//听牌展示
void UIMainWindows::readyDisplay()
{
    if(isSouthReady == true){
        //清空之前的内容
        ui->statusSouthReadyNum1->clear();
        ui->statusSouthReadyNum2->clear();
        ui->statusSouthReadyNum3->clear();
        ui->statusSouthReadyNum4->clear();
        ui->statusSouthReadyNum5->clear();
        ui->statusSouthReadyNum6->clear();
        ui->statusSouthReadyNum7->clear();
        ui->statusSouthReadyNum8->clear();
        ui->statusSouthReadyNum9->clear();
        ui->statusSouthReadyNum10->clear();

        ui->statusSouthReadyPai1->clear();
        ui->statusSouthReadyPai2->clear();
        ui->statusSouthReadyPai3->clear();
        ui->statusSouthReadyPai4->clear();
        ui->statusSouthReadyPai5->clear();
        ui->statusSouthReadyPai6->clear();
        ui->statusSouthReadyPai7->clear();
        ui->statusSouthReadyPai8->clear();
        ui->statusSouthReadyPai9->clear();
        ui->statusSouthReadyPai10->clear();

        //听牌标志显示
        QPixmap statusSouthReady(":/image/ting.png");
        statusSouthReady.scaled(ui->statusSouthReady->size(), Qt::IgnoreAspectRatio);
        ui->statusSouthReady->setScaledContents(true);
        ui->statusSouthReady->setPixmap(statusSouthReady);

        int cnt = 0;
        for(auto i: southReadyHash){
            if(cnt == 0){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai1(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai1.scaled(ui->statusSouthReadyPai1->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai1->setScaledContents(true);
                ui->statusSouthReadyPai1->setPixmap(statusSouthReadyPai1);
                //个数显示
                ui->statusSouthReadyNum1->setText(paiCntStr);
            }else if(cnt == 1){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai1(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai1.scaled(ui->statusSouthReadyPai1->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai1->setScaledContents(true);
                ui->statusSouthReadyPai1->setPixmap(statusSouthReadyPai1);
                //个数显示
                ui->statusSouthReadyNum1->setText(paiCntStr);
            }else if(cnt == 1){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai2(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai2.scaled(ui->statusSouthReadyPai2->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai2->setScaledContents(true);
                ui->statusSouthReadyPai2->setPixmap(statusSouthReadyPai2);
                //个数显示
                ui->statusSouthReadyNum2->setText(paiCntStr);
            }else if(cnt == 2){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai3(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai3.scaled(ui->statusSouthReadyPai3->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai3->setScaledContents(true);
                ui->statusSouthReadyPai3->setPixmap(statusSouthReadyPai3);
                //个数显示
                ui->statusSouthReadyNum3->setText(paiCntStr);
            }else if(cnt == 3){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai4(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai4.scaled(ui->statusSouthReadyPai4->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai4->setScaledContents(true);
                ui->statusSouthReadyPai4->setPixmap(statusSouthReadyPai4);
                //个数显示
                ui->statusSouthReadyNum4->setText(paiCntStr);
            }else if(cnt == 4){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai5(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai5.scaled(ui->statusSouthReadyPai5->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai5->setScaledContents(true);
                ui->statusSouthReadyPai5->setPixmap(statusSouthReadyPai5);
                //个数显示
                ui->statusSouthReadyNum5->setText(paiCntStr);
            }else if(cnt == 5){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai6(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai6.scaled(ui->statusSouthReadyPai6->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai6->setScaledContents(true);
                ui->statusSouthReadyPai6->setPixmap(statusSouthReadyPai6);
                //个数显示
                ui->statusSouthReadyNum6->setText(paiCntStr);
            }else if(cnt == 6){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai7(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai7.scaled(ui->statusSouthReadyPai7->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai7->setScaledContents(true);
                ui->statusSouthReadyPai7->setPixmap(statusSouthReadyPai7);
                //个数显示
                ui->statusSouthReadyNum7->setText(paiCntStr);
            }else if(cnt == 7){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai8(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai8.scaled(ui->statusSouthReadyPai8->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai8->setScaledContents(true);
                ui->statusSouthReadyPai8->setPixmap(statusSouthReadyPai8);
                //个数显示
                ui->statusSouthReadyNum8->setText(paiCntStr);
            }else if(cnt == 8){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai9(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai9.scaled(ui->statusSouthReadyPai9->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai9->setScaledContents(true);
                ui->statusSouthReadyPai9->setPixmap(statusSouthReadyPai9);
                //个数显示
                ui->statusSouthReadyNum9->setText(paiCntStr);
            }else if(cnt == 9){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusSouthReadyPai10(":/image/" + paiResultStr + ".png");
                statusSouthReadyPai10.scaled(ui->statusSouthReadyPai10->size(), Qt::IgnoreAspectRatio);
                ui->statusSouthReadyPai10->setScaledContents(true);
                ui->statusSouthReadyPai10->setPixmap(statusSouthReadyPai10);
                //个数显示
                ui->statusSouthReadyNum10->setText(paiCntStr);
            }
            cnt++;
        }

    }
    if(isEastReady == true){
        //清空之前的内容
        ui->statusEastReadyNum1->clear();
        ui->statusEastReadyNum2->clear();
        ui->statusEastReadyNum3->clear();
        ui->statusEastReadyNum4->clear();
        ui->statusEastReadyNum5->clear();
        ui->statusEastReadyNum6->clear();
        ui->statusEastReadyNum7->clear();
        ui->statusEastReadyNum8->clear();
        ui->statusEastReadyNum9->clear();
        ui->statusEastReadyNum10->clear();

        ui->statusEastReadyPai1->clear();
        ui->statusEastReadyPai2->clear();
        ui->statusEastReadyPai3->clear();
        ui->statusEastReadyPai4->clear();
        ui->statusEastReadyPai5->clear();
        ui->statusEastReadyPai6->clear();
        ui->statusEastReadyPai7->clear();
        ui->statusEastReadyPai8->clear();
        ui->statusEastReadyPai9->clear();
        ui->statusEastReadyPai10->clear();

        //听牌标志显示
        QPixmap statusEastReady(":/image/ting.png");
        statusEastReady.scaled(ui->statusEastReady->size(), Qt::IgnoreAspectRatio);
        ui->statusEastReady->setScaledContents(true);
        ui->statusEastReady->setPixmap(statusEastReady);

        int cnt = 0;
        for(auto i: eastReadyHash){
            if(cnt == 0){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai1(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai1.scaled(ui->statusEastReadyPai1->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai1->setScaledContents(true);
                ui->statusEastReadyPai1->setPixmap(statusEastReadyPai1);
                //个数显示
                ui->statusEastReadyNum1->setText(paiCntStr);
            }else if(cnt == 1){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai2(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai2.scaled(ui->statusEastReadyPai2->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai2->setScaledContents(true);
                ui->statusEastReadyPai2->setPixmap(statusEastReadyPai2);
                //个数显示
                ui->statusEastReadyNum2->setText(paiCntStr);
            }else if(cnt == 2){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai3(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai3.scaled(ui->statusEastReadyPai3->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai3->setScaledContents(true);
                ui->statusEastReadyPai3->setPixmap(statusEastReadyPai3);
                //个数显示
                ui->statusEastReadyNum3->setText(paiCntStr);
            }else if(cnt == 3){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai4(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai4.scaled(ui->statusEastReadyPai4->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai4->setScaledContents(true);
                ui->statusEastReadyPai4->setPixmap(statusEastReadyPai4);
                //个数显示
                ui->statusEastReadyNum4->setText(paiCntStr);
            }else if(cnt == 4){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai5(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai5.scaled(ui->statusEastReadyPai5->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai5->setScaledContents(true);
                ui->statusEastReadyPai5->setPixmap(statusEastReadyPai5);
                //个数显示
                ui->statusEastReadyNum5->setText(paiCntStr);
            }else if(cnt == 5){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai6(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai6.scaled(ui->statusEastReadyPai6->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai6->setScaledContents(true);
                ui->statusEastReadyPai6->setPixmap(statusEastReadyPai6);
                //个数显示
                ui->statusEastReadyNum6->setText(paiCntStr);
            }else if(cnt == 6){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai7(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai7.scaled(ui->statusEastReadyPai7->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai7->setScaledContents(true);
                ui->statusEastReadyPai7->setPixmap(statusEastReadyPai7);
                //个数显示
                ui->statusEastReadyNum7->setText(paiCntStr);
            }else if(cnt == 7){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai8(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai8.scaled(ui->statusEastReadyPai8->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai8->setScaledContents(true);
                ui->statusEastReadyPai8->setPixmap(statusEastReadyPai8);
                //个数显示
                ui->statusEastReadyNum8->setText(paiCntStr);
            }else if(cnt == 8){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai9(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai9.scaled(ui->statusEastReadyPai9->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai9->setScaledContents(true);
                ui->statusEastReadyPai9->setPixmap(statusEastReadyPai9);
                //个数显示
                ui->statusEastReadyNum9->setText(paiCntStr);
            }else if(cnt == 9){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusEastReadyPai10(":/image/r" + paiResultStr + ".png");
                statusEastReadyPai10.scaled(ui->statusEastReadyPai10->size(), Qt::IgnoreAspectRatio);
                ui->statusEastReadyPai10->setScaledContents(true);
                ui->statusEastReadyPai10->setPixmap(statusEastReadyPai10);
                //个数显示
                ui->statusEastReadyNum10->setText(paiCntStr);
            }
            cnt++;
        }


    }
    if(isNorthReady == true){
        //清空之前的内容
        ui->statusNorthReadyNum1->clear();
        ui->statusNorthReadyNum2->clear();
        ui->statusNorthReadyNum3->clear();
        ui->statusNorthReadyNum4->clear();
        ui->statusNorthReadyNum5->clear();
        ui->statusNorthReadyNum6->clear();
        ui->statusNorthReadyNum7->clear();
        ui->statusNorthReadyNum8->clear();
        ui->statusNorthReadyNum9->clear();
        ui->statusNorthReadyNum10->clear();

        ui->statusNorthReadyPai1->clear();
        ui->statusNorthReadyPai2->clear();
        ui->statusNorthReadyPai3->clear();
        ui->statusNorthReadyPai4->clear();
        ui->statusNorthReadyPai5->clear();
        ui->statusNorthReadyPai6->clear();
        ui->statusNorthReadyPai7->clear();
        ui->statusNorthReadyPai8->clear();
        ui->statusNorthReadyPai9->clear();
        ui->statusNorthReadyPai10->clear();

        //听牌标志显示
        QPixmap statusNorthReady(":/image/ting.png");
        statusNorthReady.scaled(ui->statusNorthReady->size(), Qt::IgnoreAspectRatio);
        ui->statusNorthReady->setScaledContents(true);
        ui->statusNorthReady->setPixmap(statusNorthReady);

        int cnt = 0;
        for(auto i: northReadyHash){
            if(cnt == 0){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai1(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai1.scaled(ui->statusNorthReadyPai1->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai1->setScaledContents(true);
                ui->statusNorthReadyPai1->setPixmap(statusNorthReadyPai1);
                //个数显示
                ui->statusNorthReadyNum1->setText(paiCntStr);
            }else if(cnt == 1){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai2(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai2.scaled(ui->statusNorthReadyPai2->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai2->setScaledContents(true);
                ui->statusNorthReadyPai2->setPixmap(statusNorthReadyPai2);
                //个数显示
                ui->statusNorthReadyNum2->setText(paiCntStr);
            }else if(cnt == 2){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai3(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai3.scaled(ui->statusNorthReadyPai3->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai3->setScaledContents(true);
                ui->statusNorthReadyPai3->setPixmap(statusNorthReadyPai3);
                //个数显示
                ui->statusNorthReadyNum3->setText(paiCntStr);
            }else if(cnt == 3){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai4(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai4.scaled(ui->statusNorthReadyPai4->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai4->setScaledContents(true);
                ui->statusNorthReadyPai4->setPixmap(statusNorthReadyPai4);
                //个数显示
                ui->statusNorthReadyNum4->setText(paiCntStr);
            }else if(cnt == 4){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai5(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai5.scaled(ui->statusNorthReadyPai5->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai5->setScaledContents(true);
                ui->statusNorthReadyPai5->setPixmap(statusNorthReadyPai5);
                //个数显示
                ui->statusNorthReadyNum5->setText(paiCntStr);
            }else if(cnt == 5){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai6(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai6.scaled(ui->statusNorthReadyPai6->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai6->setScaledContents(true);
                ui->statusNorthReadyPai6->setPixmap(statusNorthReadyPai6);
                //个数显示
                ui->statusNorthReadyNum6->setText(paiCntStr);
            }else if(cnt == 6){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai7(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai7.scaled(ui->statusNorthReadyPai7->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai7->setScaledContents(true);
                ui->statusNorthReadyPai7->setPixmap(statusNorthReadyPai7);
                //个数显示
                ui->statusNorthReadyNum7->setText(paiCntStr);
            }else if(cnt == 7){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai8(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai8.scaled(ui->statusNorthReadyPai8->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai8->setScaledContents(true);
                ui->statusNorthReadyPai8->setPixmap(statusNorthReadyPai8);
                //个数显示
                ui->statusNorthReadyNum8->setText(paiCntStr);
            }else if(cnt == 8){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai9(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai9.scaled(ui->statusNorthReadyPai9->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai9->setScaledContents(true);
                ui->statusNorthReadyPai9->setPixmap(statusNorthReadyPai9);
                //个数显示
                ui->statusNorthReadyNum9->setText(paiCntStr);
            }else if(cnt == 9){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusNorthReadyPai10(":/image/" + paiResultStr + ".png");
                statusNorthReadyPai10.scaled(ui->statusNorthReadyPai10->size(), Qt::IgnoreAspectRatio);
                ui->statusNorthReadyPai10->setScaledContents(true);
                ui->statusNorthReadyPai10->setPixmap(statusNorthReadyPai10);
                //个数显示
                ui->statusNorthReadyNum10->setText(paiCntStr);
            }
            cnt++;
        }


    }
    if(isWestReady == true){
        //清空之前的内容
        ui->statusWestReadyNum1->clear();
        ui->statusWestReadyNum2->clear();
        ui->statusWestReadyNum3->clear();
        ui->statusWestReadyNum4->clear();
        ui->statusWestReadyNum5->clear();
        ui->statusWestReadyNum6->clear();
        ui->statusWestReadyNum7->clear();
        ui->statusWestReadyNum8->clear();
        ui->statusWestReadyNum9->clear();
        ui->statusWestReadyNum10->clear();

        ui->statusWestReadyPai1->clear();
        ui->statusWestReadyPai2->clear();
        ui->statusWestReadyPai3->clear();
        ui->statusWestReadyPai4->clear();
        ui->statusWestReadyPai5->clear();
        ui->statusWestReadyPai6->clear();
        ui->statusWestReadyPai7->clear();
        ui->statusWestReadyPai8->clear();
        ui->statusWestReadyPai9->clear();
        ui->statusWestReadyPai10->clear();

        //听牌标志显示
        QPixmap statusWestReady(":/image/ting.png");
        statusWestReady.scaled(ui->statusWestReady->size(), Qt::IgnoreAspectRatio);
        ui->statusWestReady->setScaledContents(true);
        ui->statusWestReady->setPixmap(statusWestReady);

        int cnt = 0;
        for(auto i: westReadyHash){
            if(cnt == 0){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai1(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai1.scaled(ui->statusWestReadyPai1->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai1->setScaledContents(true);
                ui->statusWestReadyPai1->setPixmap(statusWestReadyPai1);
                //个数显示
                ui->statusWestReadyNum1->setText(paiCntStr);
            }else if(cnt == 1){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai2(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai2.scaled(ui->statusWestReadyPai2->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai2->setScaledContents(true);
                ui->statusWestReadyPai2->setPixmap(statusWestReadyPai2);
                //个数显示
                ui->statusWestReadyNum2->setText(paiCntStr);
            }else if(cnt == 2){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai3(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai3.scaled(ui->statusWestReadyPai3->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai3->setScaledContents(true);
                ui->statusWestReadyPai3->setPixmap(statusWestReadyPai3);
                //个数显示
                ui->statusWestReadyNum3->setText(paiCntStr);
            }else if(cnt == 3){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai4(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai4.scaled(ui->statusWestReadyPai4->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai4->setScaledContents(true);
                ui->statusWestReadyPai4->setPixmap(statusWestReadyPai4);
                //个数显示
                ui->statusWestReadyNum4->setText(paiCntStr);
            }else if(cnt == 4){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai5(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai5.scaled(ui->statusWestReadyPai5->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai5->setScaledContents(true);
                ui->statusWestReadyPai5->setPixmap(statusWestReadyPai5);
                //个数显示
                ui->statusWestReadyNum5->setText(paiCntStr);
            }else if(cnt == 5){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai6(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai6.scaled(ui->statusWestReadyPai6->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai6->setScaledContents(true);
                ui->statusWestReadyPai6->setPixmap(statusWestReadyPai6);
                //个数显示
                ui->statusWestReadyNum6->setText(paiCntStr);
            }else if(cnt == 6){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai7(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai7.scaled(ui->statusWestReadyPai7->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai7->setScaledContents(true);
                ui->statusWestReadyPai7->setPixmap(statusWestReadyPai7);
                //个数显示
                ui->statusWestReadyNum7->setText(paiCntStr);
            }else if(cnt == 7){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai8(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai8.scaled(ui->statusWestReadyPai8->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai8->setScaledContents(true);
                ui->statusWestReadyPai8->setPixmap(statusWestReadyPai8);
                //个数显示
                ui->statusWestReadyNum8->setText(paiCntStr);
            }else if(cnt == 8){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai9(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai9.scaled(ui->statusWestReadyPai9->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai9->setScaledContents(true);
                ui->statusWestReadyPai9->setPixmap(statusWestReadyPai9);
                //个数显示
                ui->statusWestReadyNum9->setText(paiCntStr);
            }else if(cnt == 9){
                int paiResult = i.first;
                int paiCnt = i.second;

                QString paiResultStr = QString::number(paiResult);
                QString paiCntStr = QString::number(paiCnt);
                //牌显示
                QPixmap statusWestReadyPai10(":/image/l" + paiResultStr + ".png");
                statusWestReadyPai10.scaled(ui->statusWestReadyPai10->size(), Qt::IgnoreAspectRatio);
                ui->statusWestReadyPai10->setScaledContents(true);
                ui->statusWestReadyPai10->setPixmap(statusWestReadyPai10);
                //个数显示
                ui->statusWestReadyNum10->setText(paiCntStr);
            }
            cnt++;
        }

    }
}
//清空手牌显示的各种状态
void UIMainWindows::clearHandStatus()
{        
//    ui->statusSouthReady->clear();
    ui->statusSouthChow->clear();
    ui->statusSouthPong->clear();
    ui->statusSouthKong->clear();
    ui->statusSouthWin->clear();
    ui->statusSouthCheck->clear();

//    ui->statusEastReady->clear();
    ui->statusEastChow->clear();
    ui->statusEastPong->clear();
    ui->statusEastKong->clear();
    ui->statusEastWin->clear();
    ui->statusEastCheck->clear();

//    ui->statusNorthReady->clear();
    ui->statusNorthChow->clear();
    ui->statusNorthPong->clear();
    ui->statusNorthKong->clear();
    ui->statusNorthWin->clear();
    ui->statusNorthCheck->clear();

//    ui->statusWestReady->clear();
    ui->statusWestChow->clear();
    ui->statusWestPong->clear();
    ui->statusWestKong->clear();
    ui->statusWestWin->clear();
    ui->statusWestCheck->clear();

    //听牌
    //南
    ui->statusSouthReady->clear();

    ui->statusSouthReadyNum1->clear();
    ui->statusSouthReadyNum2->clear();
    ui->statusSouthReadyNum3->clear();
    ui->statusSouthReadyNum4->clear();
    ui->statusSouthReadyNum5->clear();
    ui->statusSouthReadyNum6->clear();
    ui->statusSouthReadyNum7->clear();
    ui->statusSouthReadyNum8->clear();
    ui->statusSouthReadyNum9->clear();
    ui->statusSouthReadyNum10->clear();

    ui->statusSouthReadyPai1->clear();
    ui->statusSouthReadyPai2->clear();
    ui->statusSouthReadyPai3->clear();
    ui->statusSouthReadyPai4->clear();
    ui->statusSouthReadyPai5->clear();
    ui->statusSouthReadyPai6->clear();
    ui->statusSouthReadyPai7->clear();
    ui->statusSouthReadyPai8->clear();
    ui->statusSouthReadyPai9->clear();
    ui->statusSouthReadyPai10->clear();
    //东
    ui->statusEastReady->clear();

    ui->statusEastReadyNum1->clear();
    ui->statusEastReadyNum2->clear();
    ui->statusEastReadyNum3->clear();
    ui->statusEastReadyNum4->clear();
    ui->statusEastReadyNum5->clear();
    ui->statusEastReadyNum6->clear();
    ui->statusEastReadyNum7->clear();
    ui->statusEastReadyNum8->clear();
    ui->statusEastReadyNum9->clear();
    ui->statusEastReadyNum10->clear();

    ui->statusEastReadyPai1->clear();
    ui->statusEastReadyPai2->clear();
    ui->statusEastReadyPai3->clear();
    ui->statusEastReadyPai4->clear();
    ui->statusEastReadyPai5->clear();
    ui->statusEastReadyPai6->clear();
    ui->statusEastReadyPai7->clear();
    ui->statusEastReadyPai8->clear();
    ui->statusEastReadyPai9->clear();
    ui->statusEastReadyPai10->clear();
    //北
    ui->statusNorthReady->clear();

    ui->statusNorthReadyNum1->clear();
    ui->statusNorthReadyNum2->clear();
    ui->statusNorthReadyNum3->clear();
    ui->statusNorthReadyNum4->clear();
    ui->statusNorthReadyNum5->clear();
    ui->statusNorthReadyNum6->clear();
    ui->statusNorthReadyNum7->clear();
    ui->statusNorthReadyNum8->clear();
    ui->statusNorthReadyNum9->clear();
    ui->statusNorthReadyNum10->clear();

    ui->statusNorthReadyPai1->clear();
    ui->statusNorthReadyPai2->clear();
    ui->statusNorthReadyPai3->clear();
    ui->statusNorthReadyPai4->clear();
    ui->statusNorthReadyPai5->clear();
    ui->statusNorthReadyPai6->clear();
    ui->statusNorthReadyPai7->clear();
    ui->statusNorthReadyPai8->clear();
    ui->statusNorthReadyPai9->clear();
    ui->statusNorthReadyPai10->clear();

    //西
    ui->statusWestReady->clear();

    ui->statusWestReadyNum1->clear();
    ui->statusWestReadyNum2->clear();
    ui->statusWestReadyNum3->clear();
    ui->statusWestReadyNum4->clear();
    ui->statusWestReadyNum5->clear();
    ui->statusWestReadyNum6->clear();
    ui->statusWestReadyNum7->clear();
    ui->statusWestReadyNum8->clear();
    ui->statusWestReadyNum9->clear();
    ui->statusWestReadyNum10->clear();

    ui->statusWestReadyPai1->clear();
    ui->statusWestReadyPai2->clear();
    ui->statusWestReadyPai3->clear();
    ui->statusWestReadyPai4->clear();
    ui->statusWestReadyPai5->clear();
    ui->statusWestReadyPai6->clear();
    ui->statusWestReadyPai7->clear();
    ui->statusWestReadyPai8->clear();
    ui->statusWestReadyPai9->clear();
    ui->statusWestReadyPai10->clear();
}
//清空手牌的听牌状态
void UIMainWindows::clearReady()
{
    if(mopaiWanjia == 1){

        //南
        ui->statusSouthReady->clear();

        ui->statusSouthReadyNum1->clear();
        ui->statusSouthReadyNum2->clear();
        ui->statusSouthReadyNum3->clear();
        ui->statusSouthReadyNum4->clear();
        ui->statusSouthReadyNum5->clear();
        ui->statusSouthReadyNum6->clear();
        ui->statusSouthReadyNum7->clear();
        ui->statusSouthReadyNum8->clear();
        ui->statusSouthReadyNum9->clear();
        ui->statusSouthReadyNum10->clear();

        ui->statusSouthReadyPai1->clear();
        ui->statusSouthReadyPai2->clear();
        ui->statusSouthReadyPai3->clear();
        ui->statusSouthReadyPai4->clear();
        ui->statusSouthReadyPai5->clear();
        ui->statusSouthReadyPai6->clear();
        ui->statusSouthReadyPai7->clear();
        ui->statusSouthReadyPai8->clear();
        ui->statusSouthReadyPai9->clear();
        ui->statusSouthReadyPai10->clear();
    }else if(mopaiWanjia == 0){
        //东
        ui->statusEastReady->clear();

        ui->statusEastReadyNum1->clear();
        ui->statusEastReadyNum2->clear();
        ui->statusEastReadyNum3->clear();
        ui->statusEastReadyNum4->clear();
        ui->statusEastReadyNum5->clear();
        ui->statusEastReadyNum6->clear();
        ui->statusEastReadyNum7->clear();
        ui->statusEastReadyNum8->clear();
        ui->statusEastReadyNum9->clear();
        ui->statusEastReadyNum10->clear();

        ui->statusEastReadyPai1->clear();
        ui->statusEastReadyPai2->clear();
        ui->statusEastReadyPai3->clear();
        ui->statusEastReadyPai4->clear();
        ui->statusEastReadyPai5->clear();
        ui->statusEastReadyPai6->clear();
        ui->statusEastReadyPai7->clear();
        ui->statusEastReadyPai8->clear();
        ui->statusEastReadyPai9->clear();
        ui->statusEastReadyPai10->clear();
    }else if(mopaiWanjia == 3){
        //北
        ui->statusNorthReady->clear();

        ui->statusNorthReadyNum1->clear();
        ui->statusNorthReadyNum2->clear();
        ui->statusNorthReadyNum3->clear();
        ui->statusNorthReadyNum4->clear();
        ui->statusNorthReadyNum5->clear();
        ui->statusNorthReadyNum6->clear();
        ui->statusNorthReadyNum7->clear();
        ui->statusNorthReadyNum8->clear();
        ui->statusNorthReadyNum9->clear();
        ui->statusNorthReadyNum10->clear();

        ui->statusNorthReadyPai1->clear();
        ui->statusNorthReadyPai2->clear();
        ui->statusNorthReadyPai3->clear();
        ui->statusNorthReadyPai4->clear();
        ui->statusNorthReadyPai5->clear();
        ui->statusNorthReadyPai6->clear();
        ui->statusNorthReadyPai7->clear();
        ui->statusNorthReadyPai8->clear();
        ui->statusNorthReadyPai9->clear();
        ui->statusNorthReadyPai10->clear();
    }else if(mopaiWanjia == 2){
        //西
        ui->statusWestReady->clear();

        ui->statusWestReadyNum1->clear();
        ui->statusWestReadyNum2->clear();
        ui->statusWestReadyNum3->clear();
        ui->statusWestReadyNum4->clear();
        ui->statusWestReadyNum5->clear();
        ui->statusWestReadyNum6->clear();
        ui->statusWestReadyNum7->clear();
        ui->statusWestReadyNum8->clear();
        ui->statusWestReadyNum9->clear();
        ui->statusWestReadyNum10->clear();

        ui->statusWestReadyPai1->clear();
        ui->statusWestReadyPai2->clear();
        ui->statusWestReadyPai3->clear();
        ui->statusWestReadyPai4->clear();
        ui->statusWestReadyPai5->clear();
        ui->statusWestReadyPai6->clear();
        ui->statusWestReadyPai7->clear();
        ui->statusWestReadyPai8->clear();
        ui->statusWestReadyPai9->clear();
        ui->statusWestReadyPai10->clear();
    }
}
//东南西北显示
void UIMainWindows::bankerDisplay()
{
    ui->bankerNan->lower();
    ui->bankerBei->lower();
    ui->bankerXi->lower();
    ui->bankerDong->lower();
    ui->bglabel->lower();

    QPixmap bankerNan(":/image/nan2.png");
    ui->bankerNan->setPixmap(bankerNan);
    ui->bankerNan->setFixedSize(bankerNan.size());

    ui->bankerNan->setMask(bankerNan.mask()); //遮罩
   ui->bankerNan->setGeometry(550, 430, ui->bankerNan->width(), ui->bankerNan->height());

   QPixmap bankerBei(":/image/bei2.png");
   ui->bankerBei->setPixmap(bankerBei);
   ui->bankerBei->setFixedSize(bankerBei.size());

   ui->bankerBei->setMask(bankerBei.mask()); //遮罩
  ui->bankerBei->setGeometry(550, 250, ui->bankerBei->width(), ui->bankerBei->height());

  QPixmap bankerXi(":/image/xi2.png");
  ui->bankerXi->setPixmap(bankerXi);
  ui->bankerXi->setFixedSize(bankerXi.size());

  ui->bankerXi->setMask(bankerXi.mask()); //遮罩
 ui->bankerXi->setGeometry(430, 340, ui->bankerXi->width(), ui->bankerXi->height());

 QPixmap bankerDong(":/image/dong2.png");
 ui->bankerDong->setPixmap(bankerDong);
 ui->bankerDong->setFixedSize(bankerDong.size());

 ui->bankerDong->setMask(bankerDong.mask()); //遮罩
 ui->bankerDong->setGeometry(670, 340, ui->bankerDong->width(), ui->bankerDong->height());

}
//清除东南西北显示
void UIMainWindows::clearBanker()
{

    ui->bankerDong->clear();
    ui->bankerNan->clear();
    ui->bankerXi->clear();
    ui->bankerBei->clear();

}
//庄家展示
void UIMainWindows::bankerDirectionDisplay()
{
    //获得庄家
    QPixmap prompt(":/image/prompt.png");
    if(zhuangjia == 0){
        QPixmap bankerPrompt(":/image/nan.png");
        bankerPrompt.scaled(ui->bankerPrompt->size(), Qt::IgnoreAspectRatio);
        ui->bankerPrompt->setMask(bankerPrompt.mask());
        ui->bankerPrompt->setScaledContents(true);
        ui->bankerPrompt->setPixmap(prompt);
    }else if(zhuangjia == 1){
        QPixmap bankerPrompt(":/image/dong.png");
        bankerPrompt.scaled(ui->bankerPrompt->size(), Qt::IgnoreAspectRatio);
        ui->bankerPrompt->setMask(bankerPrompt.mask());
        ui->bankerPrompt->setScaledContents(true);
        ui->bankerPrompt->setPixmap(prompt);
    }else if(zhuangjia == 2){
        QPixmap bankerPrompt(":/image/bei.png");
        bankerPrompt.scaled(ui->bankerPrompt->size(), Qt::IgnoreAspectRatio);
        ui->bankerPrompt->setMask(bankerPrompt.mask());
        ui->bankerPrompt->setScaledContents(true);
        ui->bankerPrompt->setPixmap(prompt);
    }else if(zhuangjia == 3){
        QPixmap bankerPrompt(":/image/xi.png");
        bankerPrompt.scaled(ui->bankerPrompt->size(), Qt::IgnoreAspectRatio);
        ui->bankerPrompt->setMask(bankerPrompt.mask());
        ui->bankerPrompt->setScaledContents(true);
        ui->bankerPrompt->setPixmap(prompt);
    }

}

//初始化游戏界面
void UIMainWindows::initGamePanel()
{
//    //选庄
    QFont font;
    font.setPointSize(9);

    ui->countComboBox->addItem(tr("108"));
    ui->countComboBox->addItem(tr("136"));
    ui->countComboBox->setCurrentIndex(1);//默认值设置为136

    ui->groupBox_1->setStyleSheet("border:none");
    ui->groupBox_2->setStyleSheet("border:none");
    ui->groupBox_3->setStyleSheet("border:none");
    ui->groupBox_4->setStyleSheet("border:none");
}

void UIMainWindows::initTray()
{
    //创建托盘
    this->initTrayIcon();
    connect(trayIcon, &QSystemTrayIcon::activated,
                this, &UIMainWindows::iconActivated);
    //托盘事件
    connect(trayShowMainAction, &QAction::triggered,
            this, &UIMainWindows::showNormal);
     connect(trayExitAppAction, &QAction::triggered,
             this, &UIMainWindows::on_exitAppAction);
    //this->setWindowState((this->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

}

//安装事件过滤器，界面上各类鼠标操作对应的功能由该函数触发
void UIMainWindows::initInstallEventFilter()
{
    //事件过滤器
     //手牌
     ui->handSouth1->installEventFilter(this);
     ui->handSouth2->installEventFilter(this);
     ui->handSouth3->installEventFilter(this);
     ui->handSouth4->installEventFilter(this);
     ui->handSouth5->installEventFilter(this);
     ui->handSouth6->installEventFilter(this);
     ui->handSouth7->installEventFilter(this);
     ui->handSouth8->installEventFilter(this);
     ui->handSouth9->installEventFilter(this);
     ui->handSouth10->installEventFilter(this);
     ui->handSouth11->installEventFilter(this);
     ui->handSouth12->installEventFilter(this);
     ui->handSouth13->installEventFilter(this);
     ui->handSouth14->installEventFilter(this);
     ui->handSouth15->installEventFilter(this);
     ui->handSouth16->installEventFilter(this);
     ui->handSouth17->installEventFilter(this);
     ui->handSouth18->installEventFilter(this);

     ui->handEast1->installEventFilter(this);
     ui->handEast2->installEventFilter(this);
     ui->handEast3->installEventFilter(this);
     ui->handEast4->installEventFilter(this);
     ui->handEast5->installEventFilter(this);
     ui->handEast6->installEventFilter(this);
     ui->handEast7->installEventFilter(this);
     ui->handEast8->installEventFilter(this);
     ui->handEast9->installEventFilter(this);
     ui->handEast10->installEventFilter(this);
     ui->handEast11->installEventFilter(this);
     ui->handEast12->installEventFilter(this);
     ui->handEast13->installEventFilter(this);
     ui->handEast14->installEventFilter(this);
     ui->handEast15->installEventFilter(this);
     ui->handEast16->installEventFilter(this);
     ui->handEast17->installEventFilter(this);
     ui->handEast18->installEventFilter(this);

     ui->handNorth1->installEventFilter(this);
     ui->handNorth2->installEventFilter(this);
     ui->handNorth3->installEventFilter(this);
     ui->handNorth4->installEventFilter(this);
     ui->handNorth5->installEventFilter(this);
     ui->handNorth6->installEventFilter(this);
     ui->handNorth7->installEventFilter(this);
     ui->handNorth8->installEventFilter(this);
     ui->handNorth9->installEventFilter(this);
     ui->handNorth10->installEventFilter(this);
     ui->handNorth11->installEventFilter(this);
     ui->handNorth12->installEventFilter(this);
     ui->handNorth13->installEventFilter(this);
     ui->handNorth14->installEventFilter(this);
     ui->handNorth15->installEventFilter(this);
     ui->handNorth16->installEventFilter(this);
     ui->handNorth17->installEventFilter(this);
     ui->handNorth18->installEventFilter(this);

     ui->handWest1->installEventFilter(this);
     ui->handWest2->installEventFilter(this);
     ui->handWest3->installEventFilter(this);
     ui->handWest4->installEventFilter(this);
     ui->handWest5->installEventFilter(this);
     ui->handWest6->installEventFilter(this);
     ui->handWest7->installEventFilter(this);
     ui->handWest8->installEventFilter(this);
     ui->handWest9->installEventFilter(this);
     ui->handWest10->installEventFilter(this);
     ui->handWest11->installEventFilter(this);
     ui->handWest12->installEventFilter(this);
     ui->handWest13->installEventFilter(this);
     ui->handWest14->installEventFilter(this);
     ui->handWest15->installEventFilter(this);
     ui->handWest16->installEventFilter(this);
     ui->handWest17->installEventFilter(this);
     ui->handWest18->installEventFilter(this);

     //摸牌
     ui->drawSouth1_2->installEventFilter(this);
     ui->drawSouth1_3->installEventFilter(this);
     ui->drawSouth1_4->installEventFilter(this);
     ui->drawSouth1_5->installEventFilter(this);
     ui->drawSouth1_6->installEventFilter(this);
     ui->drawSouth1_7->installEventFilter(this);
     ui->drawSouth1_8->installEventFilter(this);
     ui->drawSouth1_9->installEventFilter(this);
     ui->drawSouth1_10->installEventFilter(this);
     ui->drawSouth1_11->installEventFilter(this);
     ui->drawSouth1_12->installEventFilter(this);
     ui->drawSouth1_13->installEventFilter(this);

     ui->drawSouth2_2->installEventFilter(this);
     ui->drawSouth2_3->installEventFilter(this);
     ui->drawSouth2_4->installEventFilter(this);
     ui->drawSouth2_5->installEventFilter(this);
     ui->drawSouth2_6->installEventFilter(this);
     ui->drawSouth2_7->installEventFilter(this);
     ui->drawSouth2_8->installEventFilter(this);
     ui->drawSouth2_9->installEventFilter(this);
     ui->drawSouth2_10->installEventFilter(this);
     ui->drawSouth2_11->installEventFilter(this);
     ui->drawSouth2_12->installEventFilter(this);
     ui->drawSouth2_13->installEventFilter(this);

     ui->drawWest1_2->installEventFilter(this);
     ui->drawWest1_3->installEventFilter(this);
     ui->drawWest1_4->installEventFilter(this);
     ui->drawWest1_5->installEventFilter(this);
     ui->drawWest1_6->installEventFilter(this);
     ui->drawWest1_7->installEventFilter(this);
     ui->drawWest1_8->installEventFilter(this);
     ui->drawWest1_9->installEventFilter(this);
     ui->drawWest1_10->installEventFilter(this);
     ui->drawWest1_11->installEventFilter(this);
     ui->drawWest1_12->installEventFilter(this);
     ui->drawWest1_13->installEventFilter(this);

     ui->drawWest2_2->installEventFilter(this);
     ui->drawWest2_3->installEventFilter(this);
     ui->drawWest2_4->installEventFilter(this);
     ui->drawWest2_5->installEventFilter(this);
     ui->drawWest2_6->installEventFilter(this);
     ui->drawWest2_7->installEventFilter(this);
     ui->drawWest2_8->installEventFilter(this);
     ui->drawWest2_9->installEventFilter(this);
     ui->drawWest2_10->installEventFilter(this);
     ui->drawWest2_11->installEventFilter(this);
     ui->drawWest2_12->installEventFilter(this);
     ui->drawWest2_13->installEventFilter(this);



     ui->drawNorth1_2->installEventFilter(this);
     ui->drawNorth1_3->installEventFilter(this);
     ui->drawNorth1_4->installEventFilter(this);
     ui->drawNorth1_5->installEventFilter(this);
     ui->drawNorth1_6->installEventFilter(this);
     ui->drawNorth1_7->installEventFilter(this);
     ui->drawNorth1_8->installEventFilter(this);
     ui->drawNorth1_9->installEventFilter(this);
     ui->drawNorth1_10->installEventFilter(this);
     ui->drawNorth1_11->installEventFilter(this);
     ui->drawNorth1_12->installEventFilter(this);
     ui->drawNorth1_13->installEventFilter(this);

     ui->drawNorth2_2->installEventFilter(this);
     ui->drawNorth2_3->installEventFilter(this);
     ui->drawNorth2_4->installEventFilter(this);
     ui->drawNorth2_5->installEventFilter(this);
     ui->drawNorth2_6->installEventFilter(this);
     ui->drawNorth2_7->installEventFilter(this);
     ui->drawNorth2_8->installEventFilter(this);
     ui->drawNorth2_9->installEventFilter(this);
     ui->drawNorth2_10->installEventFilter(this);
     ui->drawNorth2_11->installEventFilter(this);
     ui->drawNorth2_12->installEventFilter(this);
     ui->drawNorth2_13->installEventFilter(this);


     ui->drawEast1_2->installEventFilter(this);
     ui->drawEast1_3->installEventFilter(this);
     ui->drawEast1_4->installEventFilter(this);
     ui->drawEast1_5->installEventFilter(this);
     ui->drawEast1_6->installEventFilter(this);
     ui->drawEast1_7->installEventFilter(this);
     ui->drawEast1_8->installEventFilter(this);
     ui->drawEast1_9->installEventFilter(this);
     ui->drawEast1_10->installEventFilter(this);
     ui->drawEast1_11->installEventFilter(this);
     ui->drawEast1_12->installEventFilter(this);
     ui->drawEast1_13->installEventFilter(this);

     ui->drawEast2_2->installEventFilter(this);
     ui->drawEast2_3->installEventFilter(this);
     ui->drawEast2_4->installEventFilter(this);
     ui->drawEast2_5->installEventFilter(this);
     ui->drawEast2_6->installEventFilter(this);
     ui->drawEast2_7->installEventFilter(this);
     ui->drawEast2_8->installEventFilter(this);
     ui->drawEast2_9->installEventFilter(this);
     ui->drawEast2_10->installEventFilter(this);
     ui->drawEast2_11->installEventFilter(this);
     ui->drawEast2_12->installEventFilter(this);
     ui->drawEast2_13->installEventFilter(this);



     //碰
     ui->statusSouthPong->installEventFilter(this);
     ui->statusEastPong->installEventFilter(this);
     ui->statusNorthPong->installEventFilter(this);
     ui->statusWestPong->installEventFilter(this);
    //杠
     ui->statusSouthKong->installEventFilter(this);
     ui->statusEastKong->installEventFilter(this);
     ui->statusNorthKong->installEventFilter(this);
     ui->statusWestKong->installEventFilter(this);
     //过
     ui->statusSouthCheck->installEventFilter(this);
     ui->statusEastCheck->installEventFilter(this);
     ui->statusNorthCheck->installEventFilter(this);
     ui->statusWestCheck->installEventFilter(this);
     //吃
     ui->statusSouthChow->installEventFilter(this);
     ui->statusEastChow->installEventFilter(this);
     ui->statusNorthChow->installEventFilter(this);
     ui->statusWestChow->installEventFilter(this);
     //胡
     ui->statusSouthWin->installEventFilter(this);
     ui->statusEastWin->installEventFilter(this);
     ui->statusNorthWin->installEventFilter(this);
     ui->statusWestWin->installEventFilter(this);


     //撤回
     ui->gamePage->installEventFilter(this);

     //庄家
     //cccccc
     ui->eastbeginButton->installEventFilter(this);
     ui->southbeginButton->installEventFilter(this);
     ui->northbeginButton->installEventFilter(this);
     ui->westbeginButton->installEventFilter(this);

     ui->bankerDong->installEventFilter(this);
     ui->bankerNan->installEventFilter(this);
     ui->bankerXi->installEventFilter(this);
     ui->bankerBei->installEventFilter(this);

     ui->undoButton->installEventFilter(this);
}
//初始化游戏的设置
void UIMainWindows::initConfig()
{
     //碰
     ui->pongCheckBox->setChecked(true);
     //吃
     ui->chowCheckBox->setChecked(true);
     //明杠
     ui->kongCheckBox->setChecked(true);
     //暗杠
     ui->concealedkongCheckBox->setChecked(true);
     ui->gangshouzhongpaiCheckBox->setChecked(true);//碰后杠


    ///启牌
     QFont font;
     font.setPointSize(9);
     //跳牌方式
     ui->tiaopaiComboBox->setFont(font);
     ui->tiaopaiComboBox->addItem(tr("隔跳"));
     ui->tiaopaiComboBox->addItem(tr("平跳"));
     ui->tiaopaiComboBox->addItem(tr("上下跳"));

     //预测牌数
    ui->yuceComboBox->setFont(font);
    ui->yuceComboBox->addItem(tr("10"));
    ui->yuceComboBox->addItem(tr("9"));
    ui->yuceComboBox->addItem(tr("8"));
    ui->yuceComboBox->addItem(tr("7"));
    ui->yuceComboBox->addItem(tr("6"));
    ui->yuceComboBox->addItem(tr("5"));
    ui->yuceComboBox->addItem(tr("4"));
    ui->yuceComboBox->addItem(tr("3"));
    ui->yuceComboBox->addItem(tr("2"));
    ui->yuceComboBox->addItem(tr("1"));

    ///胡牌
    ///一炮多响
   // ui->yipaoduoxiangCheckBox->setChecked(true);
    //抢杠胡
    ui->qiangganghuCheckBox->setChecked(true);
    //小七对
    ui->xiaoqiduiCheckBox->setChecked(true);
    //缺一门
    ui->queyimenCheckBox->setChecked(false);//CRay
    //血战到底
    ui->xuezhandaodiCheckBox->setChecked(false);

    //显示AI玩家手牌
    ui->isAIshowcheckBox->setChecked(true);//CRay
    //对家设为AI玩家
    ui->isAIRadioButton->setChecked(true);

    ui->playernumcomboBox->addItem(tr("4"));

    //二层牌墙
    ui->ercengRadioButton->setChecked(true);

    QPixmap pixmap1(":/image/bg1.png");
    QPixmap pixmap2(":/image/bg2.png");
    QPixmap pixmap3(":/image/bg3.png");
    QPixmap pixmap4(":/image/bg4.png");

    pixmap1.scaled(ui->bglabel_1->size(), Qt::IgnoreAspectRatio);
    ui->bglabel_1->setScaledContents(true);
    ui->bglabel_1->setPixmap(pixmap1);

    pixmap2.scaled(ui->bglabel_2->size(), Qt::IgnoreAspectRatio);
    ui->bglabel_2->setScaledContents(true);
    ui->bglabel_2->setPixmap(pixmap2);


    pixmap3.scaled(ui->bglabel_3->size(), Qt::IgnoreAspectRatio);
    ui->bglabel_3->setScaledContents(true);
    ui->bglabel_3->setPixmap(pixmap3);


    pixmap4.scaled(ui->bglabel_4->size(), Qt::IgnoreAspectRatio);
    ui->bglabel_4->setScaledContents(true);
    ui->bglabel_4->setPixmap(pixmap4);

    //ui->bglabel_5->

    ui->bgcheckBox_1->setChecked(true);

//    QPixmap undopixmap(":/image/undo.png");
//    ui->undoButton->setScaledContents(true);
//    ui->undoButton->setPixmap(undopixmap);
//    ui->undoButton->setStyleSheet("#undoButton{border-image:url(/image/undo.png)}"
//                                 "#undoButton:pressed{border-image:url(/image/undo.png)}");

}

void UIMainWindows::initUselessConfig()
{


    ui->sancengRadioButton->setStyleSheet("QRadioButton{color:rgba(255, 255, 255, 20%)}");

    ui->checkBox_31->setStyleSheet("QCheckBox{color:rgba(255, 255, 255, 20%)}");
    ui->checkBox_32->setStyleSheet("QCheckBox{color:rgba(255, 255, 255, 20%)}");
    ui->checkBox_34->setStyleSheet("QCheckBox{color:rgba(255, 255, 255, 20%)}");

}
//读取游戏的参数设置
void UIMainWindows::getConfig()
{

    //获得配置信息

    //清空暗杠的情况
    memset(concealedKongNum, 0, sizeof(concealedKongNum));


    ///打牌
    //碰牌设置
    if(ui->pongCheckBox->isChecked() == true){
        systemConfig.pongpai = 1;
    }else if(ui->pongCheckBox->isChecked() == false){
        systemConfig.pongpai = 0;
    }
    //吃牌设置
    if(ui->chowCheckBox->isChecked() == true){
        systemConfig.chipai = 1;
    }else if(ui->chowCheckBox->isChecked() == false){
        systemConfig.chipai = 0;
    }
    //杠牌设置
    //明杠
    if(ui->kongCheckBox->isChecked() == true){
        systemConfig.minggang = 1;
    }else if(ui->kongCheckBox->isChecked() == false){
         systemConfig.minggang = 0;
    }
    //暗杠
    if(ui->concealedkongCheckBox->isChecked() == true){
        systemConfig.angang = 1;
    }else if(ui->concealedkongCheckBox->isChecked() == false){
        systemConfig.angang = 0;
    }
    //杠手中牌
    if(ui->gangshouzhongpaiCheckBox->isChecked() == true){
        systemConfig.gangshouzhongpai = 1;
    }else if(ui->gangshouzhongpaiCheckBox->isChecked() == false){
        systemConfig.gangshouzhongpai = 0;
    }

    ///启牌
    //设置跳牌
    QString tiaopaiStr = ui->tiaopaiComboBox->currentText();
    systemConfig.tiaopai = tiaopaiStr;
    //CRay AI智商级别 1--随机；2--中智商（评分）；3--高智商（神经网络等，暂未实现）
    if (ui->lowlevRadioButton->isChecked())
        systemConfig.AILevel=1;
    else if (ui->medlevRadioButton->isChecked())
        systemConfig.AILevel=2;
    else if (ui->highlevRadioButton->isChecked())
        systemConfig.AILevel=2;             //暂未实现

    //CRay获得预测牌
    systemConfig.isPrediction=ui->isPredictioncheckBox->isChecked();
    QString yucePaiStr  = ui->yuceComboBox->currentText();
    systemConfig.yucepai = yucePaiStr.toInt();
    //CRay 是否显示AI玩家手牌
    systemConfig.isAIshow=ui->isAIshowcheckBox->isChecked();
    //玩家是否为AI 默认3个AI玩家
    if (ui->isAIRadioButton->isChecked())
        systemConfig.AIPlayers=3;
    else
        systemConfig.AIPlayers=0;

    ///胡牌
    /// //抢杠胡
    if(ui->qiangganghuCheckBox->isChecked() == true){
        systemConfig.qiangganghu = 1;
    }else if(ui->qiangganghuCheckBox->isChecked() == false){
        systemConfig.qiangganghu = 0;
    }
    //二五八将
    if(ui->erwubajiangCheckBox->isChecked() == true){
        systemConfig.erwubajiang = 1;
    }else if(ui->erwubajiangCheckBox->isChecked() == false){
       systemConfig.erwubajiang = 0;
    }
    //一炮多响
//    if(ui->yipaoduoxiangCheckBox->isChecked() == true){
//        systemConfig.yipaoduoxiang = 1;
 //  }else if(ui->yipaoduoxiangCheckBox->isChecked() == false){
 //        systemConfig.yipaoduoxiang = 0;
  //  }
    //小七对
    if(ui->xiaoqiduiCheckBox->isChecked() == true){
        systemConfig.xiaoqidui = 1;
    }else if(ui->xiaoqiduiCheckBox->isChecked() == false){
        systemConfig.xiaoqidui = 0;
    }
    //只限自摸
    if(ui->zhixianzimoCheckBox->isChecked() == true){
        systemConfig.zhixianzimo = 1;
    }else if(ui->zhixianzimoCheckBox->isChecked() == false){
         systemConfig.zhixianzimo = 0;
    }
    //缺一门
    if(ui->queyimenCheckBox->isChecked() == true){
        systemConfig.queyimen = 1;
    }else if(ui->queyimenCheckBox->isChecked() == false){
        systemConfig.queyimen = 0;
    }
    //血战到底
    if(ui->xuezhandaodiCheckBox->isChecked() == true){
        systemConfig.xuezhandaodi = 1;
    }else if(ui->xuezhandaodiCheckBox->isChecked() == false){
        systemConfig.xuezhandaodi = 0;
    }


}
//清空136张残留的信息
void UIMainWindows::clear136Information()
{
    ui->drawSouth1_15->clear();
    ui->drawSouth2_15->clear();
    ui->drawSouth1_16->clear();
    ui->drawSouth2_16->clear();
    ui->drawSouth1_17->clear();
    ui->drawSouth2_17->clear();
    ui->drawSouthNumber1_15->clear();
    ui->drawSouthNumber1_16->clear();
    ui->drawSouthNumber1_17->clear();

    ui->drawNorth1_15->clear();
    ui->drawNorth2_15->clear();
    ui->drawNorth1_16->clear();
    ui->drawNorth2_16->clear();
    ui->drawNorth1_17->clear();
    ui->drawNorth2_17->clear();
    ui->drawNorthNumber1_15->clear();
    ui->drawNorthNumber1_16->clear();
    ui->drawNorthNumber1_17->clear();

    ui->drawWest1_15->clear();
    ui->drawWest2_15->clear();
    ui->drawWest1_16->clear();
    ui->drawWest2_16->clear();
    ui->drawWest1_17->clear();
    ui->drawWest2_17->clear();
    ui->drawWestNumber15->clear();
    ui->drawWestNumber16->clear();
    ui->drawWestNumber17->clear();

    ui->drawEast1_15->clear();
    ui->drawEast2_15->clear();
    ui->drawEast1_16->clear();
    ui->drawEast2_16->clear();
    ui->drawEast1_17->clear();
    ui->drawEast2_17->clear();
    ui->drawEastNumber1_15->clear();
    ui->drawEastNumber1_16->clear();
    ui->drawEastNumber1_17->clear();
}
//摸牌
void UIMainWindows::draw()
{

    //判断是否结束游戏
    if(discardMjs.size() == majhongTotal.size() - 52){
        return;
    }

    //查找将摸起的牌
    Mj tempPai;
    findPai(tempPai);
    clearDrawDisplay();
    //更新下次摸牌的位置
    updatePai();

    bool isNapai = true;//可以被拿
    for(auto i:majhongTaken){//查找该牌是否已被拿
        if(i.getId() == tempPai.getId()){//找到
            isNapai = false;
        }
    }

    //可以摸牌，摸到的牌，分配到玩家手里
    if(isNapai == true){
        //清空之前的听牌
        isSouthReady = false;
        isEastReady = false;
        isNorthReady = false;
        isWestReady = false;

        int kongCnt = 0;

        qDebug()<<"zhuapai wanjia :"<<mopaiWanjia;
        qDebug()<<"zhuapai:"<<tempPai.getResult();

        //把牌加入手牌,并重新展示手牌

        if(mopaiWanjia == 0){
            handSouthMjs.push_back(tempPai);

            isDraw = true;
            southHandDisplay(handSouthMjs);
            isDraw = false;

            if(systemConfig.angang == 1){
                isConcealedKong(handSouthMjs, 0);//检测暗杠
                if(concealedKongNum[0] != 0){
                   KongDisplay();
                }
            }


            //检测听牌
            clearReady();
            isReady();

            //检测胡牌
            isWin();

             //mopaiWanjia = 1;
            updateMopaiWanjia();

            //把被摸的牌放入摸牌队列中
            majhongTaken.push_back(tempPai);

            for(list<Mj>::iterator iter = majhongRemain.begin(); iter != majhongRemain.end(); iter++){
                if(iter->getId() == tempPai.getId()){
                    majhongRemain.erase(iter);
                    break;
                }
            }

//            int id=handSouthMjs.size()-1;
//            dapai(id);
//            yucePai();

        }else if(mopaiWanjia == 1){
            handEastMjs.push_back(tempPai);
            isDraw = true;
            eastHandDisplay(handEastMjs);
            isDraw = false;

            if(systemConfig.angang == 1){
                isConcealedKong(handEastMjs, 1);//检测暗杠
                if(concealedKongNum[1] != 0){
                   KongDisplay();
                }
            }
            //检测听牌
            clearReady();
            isReady();
            //检测胡牌
            isWin();

          // mopaiWanjia = 2;
            updateMopaiWanjia();

            //把被摸的牌放入摸牌队列中
            majhongTaken.push_back(tempPai);

            for(list<Mj>::iterator iter = majhongRemain.begin(); iter != majhongRemain.end(); iter++){
                if(iter->getId() == tempPai.getId()){
                    majhongRemain.erase(iter);
                    break;
                }
            }
//            int id=handEastMjs.size()-1;
//            dapai(id);
//            yucePai();
        }else if(mopaiWanjia == 2){
            handNorthMjs.push_back(tempPai);
            isDraw = true;
            northHandDisplay(handNorthMjs);
            isDraw = false;

            if(systemConfig.angang == 1){
                isConcealedKong(handNorthMjs,2);//检测暗杠
                if(concealedKongNum[2] != 0){
                   KongDisplay();
                }
            }

            //检测听牌
            clearReady();
            isReady();

            //检测胡牌
            isWin();

           //mopaiWanjia = 3;
            updateMopaiWanjia();

            //把被摸的牌放入摸牌队列中
            majhongTaken.push_back(tempPai);

            for(list<Mj>::iterator iter = majhongRemain.begin(); iter != majhongRemain.end(); iter++){
                if(iter->getId() == tempPai.getId()){
                    majhongRemain.erase(iter);
                    break;
                }
            }
//            int id=handNorthMjs.size()-1;
//            dapai(id);
//            yucePai();
        }else if(mopaiWanjia == 3){
            handWestMjs.push_back(tempPai);
            isDraw = true;
            westHandDisplay(handWestMjs);
            isDraw = false;

            if(systemConfig.angang == 1){
                isConcealedKong(handWestMjs, 3);//检测暗杠
                if(concealedKongNum[3] != 0){
                   KongDisplay();
                }
            }


            //检测听牌
            clearReady();
            isReady();

            //检测胡牌
            isWin();

           // mopaiWanjia = 0;
            updateMopaiWanjia();

            //把被摸的牌放入摸牌队列中
            majhongTaken.push_back(tempPai);

            for(list<Mj>::iterator iter = majhongRemain.begin(); iter != majhongRemain.end(); iter++){
                if(iter->getId() == tempPai.getId()){
                    majhongRemain.erase(iter);
                    break;
                }
            }

        }
    }
}

//叫庄后开始抓牌
void UIMainWindows::beginDraw(std::list<Mj>& handOne, std::list<Mj>& handTwo,
                              std::list<Mj>& handThree, std::list<Mj>& handFour){
    Mj tempPai;

    //1
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//

    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//

    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();//

    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    //2
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    findPai(tempPai);///改牌
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    //3
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handOne.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handTwo.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    findPai(tempPai);    
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handThree.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();
    findPai(tempPai);
    handFour.push_back(tempPai);
    clearDrawDisplay();
    updatePai();

    ///跳牌摸牌
    if(systemConfig.tiaopai == "隔跳"){//跳牌
        findPai(tempPai);
        handOne.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handTwo.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handThree.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handFour.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handOne.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

    }else if(systemConfig.tiaopai == "上下跳"){//上下跳
        findPai(tempPai);
        handOne.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handOne.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handTwo.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handThree.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handFour.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

    }else if(systemConfig.tiaopai == "平跳"){//平跳
        findPai(tempPai);
        handOne.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handTwo.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handOne.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handThree.push_back(tempPai);
        clearDrawDisplay();
        updatePai();

        findPai(tempPai);
        handFour.push_back(tempPai);
        clearDrawDisplay();
        updatePai();
    }

    //更新下次摸牌的玩家
    updateMopaiWanjia();

//     if(mopaiWanjia == 0){
//         mopaiWanjia = 1;
//     }else if(mopaiWanjia == 1){
//         mopaiWanjia = 2;
//     }else if(mopaiWanjia == 2){
//         mopaiWanjia = 3;
//     }else if(mopaiWanjia == 3){
//         mopaiWanjia = 0;
//     }

    //把第一次摸过的牌放进已摸牌中    
     for(auto i:handTwo){
         majhongTaken.push_back(i);        

     }

     for(auto i:handThree){
         majhongTaken.push_back(i);

     }

     for(auto i:handFour){
         majhongTaken.push_back(i);

     }

     for(auto i:handOne){
         majhongTaken.push_back(i);
     }

     for(list<Mj>::iterator i = majhongTaken.begin();i != majhongTaken.end(); i++){
         for(list<Mj>::iterator j = majhongRemain.begin();j != majhongRemain.end(); j++){
             if(i->getId() == j->getId()){
                 j = majhongRemain.erase(j);
                 break;
             }
         }
      }


    //展示当前打牌位置
    directionDisplay(dapaiWanjia);

    //预测    
    yuceDirection  = mopaiDirection;
    yucePos = mopaiPos;
    yuceCeng = mopaiCeng;

    yucePai();

}

//查找将摸起的牌
void UIMainWindows::findPai(Mj& tempPai)
{
    if(mopaiDirection == 0){
        if(mopaiPos == 0){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[0];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[0 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 1){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[1];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[1 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 2){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[2];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[2 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 3){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[3];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[3 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 4){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[4];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[4 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 5){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[5];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[5 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 6){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[6];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[6 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 7){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[7];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[7 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 8){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[8];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[8 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 9){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[9];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[9 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 10){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[10];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[10 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 11){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[11];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[11 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 12){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[12];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[12 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 13){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[13];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[13 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 14){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[14];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[14 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 15){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[15];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[15 + zhangshuSouth/2];
            }
        }else if(mopaiPos == 16){
            if(mopaiCeng == 0){
                tempPai = drawSouthMjs[16];
            }else if(mopaiCeng == 1){
                 tempPai = drawSouthMjs[16 + zhangshuSouth/2];
            }
        }
    }else if(mopaiDirection == 1){
        if(mopaiPos == 0){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[0];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[0 + zhangshuEast/2];
            }
        }else if(mopaiPos == 1){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[1];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[1 + zhangshuEast/2];
            }
        }else if(mopaiPos == 2){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[2];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[2 + zhangshuEast/2];
            }
        }else if(mopaiPos == 3){
            if(mopaiCeng== 0){
                tempPai = drawEastMjs[3];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[3 + zhangshuEast/2];
            }
        }else if(mopaiPos == 4){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[4];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[4 + zhangshuEast/2];
            }
        }else if(mopaiPos == 5){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[5];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[5 + zhangshuEast/2];
            }
        }else if(mopaiPos == 6){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[6];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[6 + zhangshuEast/2];
            }
        }else if(mopaiPos == 7){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[7];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[7 + zhangshuEast/2];
            }
        }else if(mopaiPos == 8){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[8];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[8 + zhangshuEast/2];
            }
        }else if(mopaiPos == 9){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[9];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[9 + zhangshuEast/2];
            }
        }else if(mopaiPos == 10){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[10];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[10 + zhangshuEast/2];
            }
        }else if(mopaiPos == 11){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[11];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[11 + zhangshuEast/2];
            }
        }else if(mopaiPos == 12){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[12];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[12 + zhangshuEast/2];
            }
        }else if(mopaiPos == 13){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[13];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[13 + zhangshuEast/2];
            }
        }else if(mopaiPos == 14){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[14];
            }else if(mopaiCeng== 1){
                tempPai = drawEastMjs[14 + zhangshuEast/2];
            }
        }else if(mopaiPos == 15){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[15];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[15 + zhangshuEast/2];
            }
        }else if(mopaiPos == 16){
            if(mopaiCeng == 0){
                tempPai = drawEastMjs[16];
             }else if(mopaiCeng== 1){
                tempPai = drawEastMjs[16 + zhangshuEast/2];
            }
        }
    }else if(mopaiDirection == 2){
        if(mopaiPos == 0){
          if(mopaiCeng == 0){
              tempPai = drawNorthMjs[0];
          }else if(mopaiCeng == 1){
              tempPai = drawNorthMjs[0 + zhangshuNorth/2];
          }
        }else if(mopaiPos == 1){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[1];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[1 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 2){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[2];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[2 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 3){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[3];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[3 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 4){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[4];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[4 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 5){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[5];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[5 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 6){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[6];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[6 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 7){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[7];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[7 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 8){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[8];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[8 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 9){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[9];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[9 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 10){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[10];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[10 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 11){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[11];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[11 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 12){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[12];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[12 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 13){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[13];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[13 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 14){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[14];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[14 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 15){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[15];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[15 + zhangshuNorth/2];
            }
        }else if(mopaiPos == 16){
            if(mopaiCeng == 0){
                tempPai = drawNorthMjs[16];
            }else if(mopaiCeng == 1){
                tempPai = drawNorthMjs[16 + zhangshuNorth/2];
            }
        }
    }else if(mopaiDirection == 3){
            if(mopaiPos == 0){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[0];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[0 + zhangshuWest/2];
                }
            }else if(mopaiPos == 1){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[1];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[1 + zhangshuWest/2];
                }
            }else if(mopaiPos == 2){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[2];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[2 + zhangshuWest/2];
                }
            }else if(mopaiPos == 3){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[3];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[3 + zhangshuWest/2];
                }
            }else if(mopaiPos == 4){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[4];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[4 + zhangshuWest/2];
                }
            }else if(mopaiPos == 5){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[5];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[5 + zhangshuWest/2];
                }
            }else if(mopaiPos == 6){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[6];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[6 + zhangshuWest/2];
                }
            }else if(mopaiPos == 7){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[7];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[7 + zhangshuWest/2];
                }
            }else if(mopaiPos == 8){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[8];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[8 + zhangshuWest/2];
                }
            }else if(mopaiPos == 9){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[9];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[9 + zhangshuWest/2];
                }
            }else if(mopaiPos == 10){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[10];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[10 + zhangshuWest/2];
                }
            }else if(mopaiPos == 11){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[11];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[11 + zhangshuWest/2];
                }
            }else if(mopaiPos == 12){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[12];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[12 + zhangshuWest/2];
                }
            }else if(mopaiPos == 13){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[13];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[13 + zhangshuWest/2];
                }
            }else if(mopaiPos == 14){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[14];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[14 + zhangshuWest/2];
                }
            }else if(mopaiPos ==15){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[15];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[15 + zhangshuWest/2];
                }
            }else if(mopaiPos ==16){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[16];
                }else if(mopaiCeng == 1){
                    tempPai = drawWestMjs[16 + zhangshuWest/2];
                }
            }
    }
}
//更新下一摸牌的位置
void UIMainWindows::updatePai()
{
    if(mopaiDirection == 0){//南
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
            mopaiPos++;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
        }

        if(mopaiPos >= zhangshuSouth/2){
            mopaiDirection = 3;//西
            mopaiPos = 0;
            mopaiCeng = 0;
        }
    }else if(mopaiDirection == 1){//东
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
            mopaiPos++;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
        }

        if(mopaiPos >= zhangshuEast/2){
            mopaiDirection = 0;//南
            mopaiPos = 0;
            mopaiCeng = 0;
        }
    }else if(mopaiDirection == 2){//北
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
            mopaiPos++;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
        }

        if(mopaiPos >= zhangshuNorth/2){
            mopaiDirection = 1;//东
            mopaiPos = 0;
            mopaiCeng = 0;
        }
    }else if(mopaiDirection == 3){//西
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
            mopaiPos++;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
        }

        if(mopaiPos >= zhangshuWest/2){
            mopaiDirection = 2;//北
            mopaiPos = 0;
            mopaiCeng = 0;
        }
    }

    //预测
    yuceDirection  = mopaiDirection;
    yucePos = mopaiPos;
    yuceCeng = mopaiCeng;
}
//回退摸牌位置，由undooperator函数调用
void UIMainWindows::undoPai()
{
    //更新下一摸牌的位置
    if(mopaiDirection == 0){//南
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
            mopaiPos--;
        }

        if(mopaiPos < 0){
            mopaiDirection = 1;//东
            mopaiPos = zhangshuEast/2;
            mopaiCeng = 1;
        }
    }else if(mopaiDirection == 1){//东
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
             mopaiPos--;
        }

        if(mopaiPos < 0 ){
            mopaiDirection = 2;//北
            mopaiPos = zhangshuEast/2;
            mopaiCeng = 1;
        }
    }else if(mopaiDirection == 2){//北
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
            mopaiPos--;
        }

        if(mopaiPos < 0){
            mopaiDirection = 3;//西
            mopaiPos = zhangshuNorth/2;
            mopaiCeng = 1;
        }
    }else if(mopaiDirection == 3){//西
        if(mopaiCeng == 1){//第二层
            mopaiCeng = 0;
        }else if(mopaiCeng == 0){//第一层
            mopaiCeng = 1;
            mopaiPos--;
        }

        if(mopaiPos < 0){
            mopaiDirection = 0;//南
            mopaiPos = zhangshuWest/2;
            mopaiCeng = 1;
        }
    }

    //预测
    yuceDirection  = mopaiDirection;
    yucePos = mopaiPos;
    yuceCeng = mopaiCeng;
}

//结束游戏
void UIMainWindows::endGame()
{   

    //清空所有变量
    clearVariable();

    //清空面板
    clearPanel();


}
//预测抓牌
void UIMainWindows::yucePai()
{
    predictionNorthMjs.clear();
    predictionSouthMjs.clear();
    predictionEastMjs.clear();
    predictionWestMjs.clear();

    list<Mj> predOne;
    list<Mj> predTwo;
    list<Mj> predThree;
    list<Mj> predFour;

    if(endWanjia.size() == 0){
        //查找将摸起的牌
        Mj tempPai;

        bool isNapai = true;//可以被拿
        int num = systemConfig.yucepai;
        while(num--){
            yuceFindPai(tempPai);

            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predOne.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

            yuceFindPai(tempPai);
            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predTwo.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

            yuceFindPai(tempPai);
            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predThree.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

            yuceFindPai(tempPai);
            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predFour.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

        }

        if(mopaiWanjia == 0){
            predictionSouthMjs = predOne;
            predictionEastMjs = predTwo;
            predictionNorthMjs = predThree;
            predictionWestMjs = predFour;
        }else if(mopaiWanjia == 1){
            predictionSouthMjs = predFour;
            predictionEastMjs = predOne;
            predictionNorthMjs = predTwo;
            predictionWestMjs = predThree;
        }else if(mopaiWanjia == 2){
            predictionSouthMjs = predThree;
            predictionEastMjs = predFour;
            predictionNorthMjs = predOne;
            predictionWestMjs = predTwo;
        }else if(mopaiWanjia == 3){
            predictionSouthMjs = predTwo;
            predictionEastMjs = predThree;
            predictionNorthMjs = predFour;
            predictionWestMjs = predOne;
        }

        //展示预测牌
        southPredictionDisplay(predictionSouthMjs);
        northPredictionDisplay(predictionNorthMjs);
        westPredictionDisplay(predictionWestMjs);
        eastPredictionDisplay(predictionEastMjs);
    }else if(endWanjia.size() == 1){
        //查找将摸起的牌
        Mj tempPai;

        bool isNapai = true;//可以被拿
        int num = systemConfig.yucepai;
        while(num--){
            yuceFindPai(tempPai);

            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predOne.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

            yuceFindPai(tempPai);
            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predTwo.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

            yuceFindPai(tempPai);
            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predThree.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }
        }

        if(endWanjia.find(0) != endWanjia.end()){//南胡
            if(mopaiWanjia == 1){
                predictionEastMjs = predOne;
                predictionNorthMjs = predTwo;
                predictionWestMjs = predThree;
            }else if(mopaiWanjia == 2){
                predictionEastMjs =  predThree;
                predictionNorthMjs = predOne;
                predictionWestMjs = predTwo;
            }else if(mopaiWanjia == 3){
                predictionEastMjs = predTwo;
                predictionNorthMjs = predThree;
                predictionWestMjs = predOne;
            }

            //展示预测牌
            northPredictionDisplay(predictionNorthMjs);
            westPredictionDisplay(predictionWestMjs);
            eastPredictionDisplay(predictionEastMjs);
        }else if(endWanjia.find(1) != endWanjia.end()){//东胡
            if(mopaiWanjia == 0){
                predictionSouthMjs = predOne;
                predictionNorthMjs = predTwo;
                predictionWestMjs = predThree;
            }else if(mopaiWanjia == 2){
                predictionSouthMjs = predThree;
                predictionNorthMjs = predOne;
                predictionWestMjs = predTwo;
            }else if(mopaiWanjia == 3){
                predictionSouthMjs = predTwo;
                predictionNorthMjs = predThree;
                predictionWestMjs = predOne;
            }

            //展示预测牌
            southPredictionDisplay(predictionSouthMjs);
            northPredictionDisplay(predictionNorthMjs);
            westPredictionDisplay(predictionWestMjs);
        }else if(endWanjia.find(2) != endWanjia.end()){//北胡
            if(mopaiWanjia == 0){
                predictionSouthMjs = predOne;
                predictionEastMjs = predTwo;
                predictionWestMjs = predThree;
            }else if(mopaiWanjia == 1){
                predictionSouthMjs = predThree;
                predictionEastMjs = predOne;
                predictionWestMjs = predTwo;
            }else if(mopaiWanjia == 3){
                predictionSouthMjs = predTwo;
                predictionEastMjs = predThree;
                predictionWestMjs = predOne;
            }
            //展示预测牌
            southPredictionDisplay(predictionSouthMjs);
            westPredictionDisplay(predictionWestMjs);
            eastPredictionDisplay(predictionEastMjs);

        }else if(endWanjia.find(3) != endWanjia.end()){
            if(mopaiWanjia == 0){
                predictionSouthMjs = predOne;
                predictionEastMjs = predTwo;
                predictionNorthMjs = predThree;
            }else if(mopaiWanjia == 1){
                predictionSouthMjs = predThree;
                predictionEastMjs = predOne;
                predictionNorthMjs = predTwo;
            }else if(mopaiWanjia == 2){
                predictionSouthMjs = predTwo;
                predictionEastMjs = predThree;
                predictionNorthMjs = predOne;
            }
            //展示预测牌
            southPredictionDisplay(predictionSouthMjs);
            northPredictionDisplay(predictionNorthMjs);
            eastPredictionDisplay(predictionEastMjs);
        }

    }else if(endWanjia.size() == 2){
        //查找将摸起的牌
        Mj tempPai;

        bool isNapai = true;//可以被拿
        int num = systemConfig.yucepai;
        while(num--){
            yuceFindPai(tempPai);

            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predOne.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }

            yuceFindPai(tempPai);
            for(auto i:majhongTaken){//查找该牌是否已被拿
                if(i.getId() == tempPai.getId()){//找到
                    isNapai = false;
                }
            }

            if(isNapai == true){
                predTwo.push_back(tempPai);
                yuceUpdatePai();
            }else{
                break;
            }
        }

        if(endWanjia.find(0) != endWanjia.end() && endWanjia.find(1) != endWanjia.end()){
            if(mopaiWanjia == 2){
                predictionNorthMjs = predOne;
                predictionWestMjs = predTwo;
            }else if(mopaiWanjia == 3){
                predictionNorthMjs = predTwo;
                predictionWestMjs = predOne;
            }

            //展示预测牌
            northPredictionDisplay(predictionNorthMjs);
            westPredictionDisplay(predictionWestMjs);
        }if(endWanjia.find(0) != endWanjia.end() && endWanjia.find(2) != endWanjia.end()){
            if(mopaiWanjia == 1){
                predictionEastMjs = predOne;
                predictionWestMjs = predTwo;
            }else if(mopaiWanjia == 3){
                predictionEastMjs = predTwo;
                predictionWestMjs = predOne;
            }

            //展示预测牌
            westPredictionDisplay(predictionWestMjs);
            eastPredictionDisplay(predictionEastMjs);
        }if(endWanjia.find(0) != endWanjia.end() && endWanjia.find(3) != endWanjia.end()){
           if(mopaiWanjia == 1){
                predictionEastMjs = predOne;
                predictionNorthMjs = predTwo;
            }else if(mopaiWanjia == 2){
                predictionEastMjs = predTwo;
                predictionNorthMjs = predOne;
            }

           //展示预测牌
           northPredictionDisplay(predictionNorthMjs);
           eastPredictionDisplay(predictionEastMjs);
        }if(endWanjia.find(1) != endWanjia.end() && endWanjia.find(2) != endWanjia.end()){
            if(mopaiWanjia == 0){
                predictionSouthMjs = predOne;
                predictionWestMjs = predTwo;
            }else if(mopaiWanjia == 3){
                predictionSouthMjs = predTwo;
                predictionWestMjs = predOne;
            }

            //展示预测牌
            southPredictionDisplay(predictionSouthMjs);
            westPredictionDisplay(predictionWestMjs);
        }if(endWanjia.find(1) != endWanjia.end() && endWanjia.find(3) != endWanjia.end()){
            if(mopaiWanjia == 0){
                predictionSouthMjs = predOne;
                predictionNorthMjs = predTwo;
            }else if(mopaiWanjia == 2){
                predictionSouthMjs = predTwo;
                predictionNorthMjs = predOne;
            }

            //展示预测牌
            southPredictionDisplay(predictionSouthMjs);
            northPredictionDisplay(predictionNorthMjs);
        }if(endWanjia.find(2) != endWanjia.end() && endWanjia.find(3) != endWanjia.end()){
            if(mopaiWanjia == 0){
                predictionSouthMjs = predOne;
                predictionEastMjs = predTwo;
            }else if(mopaiWanjia == 1){
                predictionSouthMjs = predTwo;
                predictionEastMjs = predOne;
            }

            //展示预测牌
            southPredictionDisplay(predictionSouthMjs);
            eastPredictionDisplay(predictionEastMjs);
        }
    }
}
//打牌，本程序中最主要的函数，在函数尾部调用了AIHu()、AIKong()、AIPong()、AIChow()、AIPlay()五个步骤
void UIMainWindows::dapai(int pos)
{

    if(dapaiWanjia == 0){//防止点击重叠部分，造成pos溢出
        if(pos >= static_cast<int>(handSouthMjs.size())){
            pos = static_cast<int>(handSouthMjs.size()) - 1;
        }
    }else if(dapaiWanjia == 1){
        if(pos >= static_cast<int>(handEastMjs.size())){
            pos = static_cast<int>(handEastMjs.size()) - 1;
        }
    }else if(dapaiWanjia == 2){
        if(pos >= static_cast<int>(handNorthMjs.size())){
            pos = static_cast<int>(handNorthMjs.size()) - 1;
        }
    }else if(dapaiWanjia == 3){
        if(pos >= static_cast<int>(handWestMjs.size())){
            pos = static_cast<int>(handWestMjs.size()) - 1;
        }
    }

    playedPai.clear();
    //清空之前的胡牌
    isSouthWin = false;
    isEastWin = false;
    isNorthWin = false;
    isWestWin = false;

    //剔除打出的牌
    int cnt = 0;

    bool AIflag=false;

    if(dapaiWanjia == 0){
        qDebug()<<"CRay  dapaiWanjia:"<<"East";
        for(list<Mj>::iterator iter =  handSouthMjs.begin(); iter != handSouthMjs.end();iter++){

            if(cnt == pos){
                playedPai.push_back(*iter);//暂存已打出的牌
                //记录缺门牌
                if(isSouthQue == true && systemConfig.queyimen == 1){
                    if(iter->getResult() < 10){
                        southQue = 0;
                    }else if(iter->getResult() > 10 && iter->getResult() < 20){
                        southQue = 10;
                    }else if(iter->getResult() > 20 && iter->getResult() < 30){
                        southQue = 20;
                    }
                    isSouthQue = false;
                }
                qDebug()<<"dapai:"<<iter->getResult();
                //加入弃牌堆
                discardMjs.push_back(*iter);
                //从手牌剔除
                handSouthMjs.erase(iter);
                break;
            }
            cnt++;
        }

       discardDisplay(discardMjs);//展示弃牌

        //撤回：记录打牌
       playedPaiStack.push(*(playedPai.begin()));

       //重新展示手牌
       handSouthMjs.sort(cmpHandMjs);//重新排序
       southHandDisplay(handSouthMjs);

       //设置遮罩层(消失)
       ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
       ui->justTakenLabel->setGeometry(1130,20,10,10);

       //判断吃碰杠
       if(systemConfig.chipai == 1 && systemConfig.queyimen == 0){
           isChow();
           ChowDisplay();
       }

       if(systemConfig.pongpai == 1){
           isPong();
           PongDisplay();
       }

       if(systemConfig.minggang == 1){
           isKong();
           KongDisplay();
       }

       ui->statusSouthKong->clear();//杠
       ui->statusSouthCheck->clear();//过
       ui->statusSouthWin->clear();//胡

       if(systemConfig.zhixianzimo == 0){
             isWin2();
       }

       if(isSouthPong == false && isEastPong == false && isNorthPong == false && isWestPong == false
         && isSouthChow == false && isEastChow == false && isNorthChow == false && isWestChow == false
         && isSouthKong == false && isEastKong == false && isNorthKong == false && isWestKong == false
//         && concealedKongNum[0] == 0
         && isSouthWin == false && isEastWin == false && isNorthWin == false && isWestWin == false
           ){
           //清除暗杠标识
           ui->statusSouthKong->clear();
           ui->statusSouthCheck->clear();

           //下家摸新牌
           draw();//更新下一个摸牌(更新摸牌玩家)

           updateDapaiWanjia();
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);

           AIflag=true;

       }else{
           //预测位置更新为下一个摸牌的位置，以此来预测
           yuceDirection  = mopaiDirection;
           yucePos = mopaiPos;
           yuceCeng = mopaiCeng;
       }


    }else if(dapaiWanjia == 1){
        qDebug()<<"CRay  dapaiWanjia:"<<"South";
        for(list<Mj>::iterator iter =  handEastMjs.begin(); iter != handEastMjs.end();iter++){

            if(cnt == pos){
                //暂存已打出的牌
                 playedPai.push_back(*iter);

                 //记录缺门牌
                 if(isEastQue == true && systemConfig.queyimen == 1){
                     if(iter->getResult() < 10){
                         eastQue = 0;
                     }else if(iter->getResult() > 10 && iter->getResult() < 20){
                         eastQue = 10;
                     }else if(iter->getResult() > 20 && iter->getResult() < 30){
                         eastQue = 20;
                     }
                     isEastQue = false;
                 }
                qDebug()<<"dapai:"<<iter->getResult();
                //加入弃牌堆
                discardMjs.push_back(*iter);
                //从手牌剔除
                handEastMjs.erase(iter);
                break;
            }
            cnt++;

        }

        discardDisplay(discardMjs);//展示弃牌

        //撤回：记录打牌
       playedPaiStack.push(*(playedPai.begin()));

       //重新展示手牌
        handEastMjs.sort(cmpHandMjs);
       eastHandDisplay(handEastMjs);
       //设置遮罩层(消失)
       ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
       ui->justTakenLabel->setGeometry(1130,20,10,10);

       //判断吃碰杠
       if(systemConfig.chipai == 1 && systemConfig.queyimen == 0){
           isChow();
           ChowDisplay();
       }

       if(systemConfig.pongpai == 1){
           isPong();
           PongDisplay();
       }

       if(systemConfig.minggang == 1){
           isKong();
           KongDisplay();
       }


       ui->statusEastKong->clear();
       ui->statusEastCheck->clear();
       ui->statusEastWin->clear();//胡

       if(systemConfig.zhixianzimo == 0){
            isWin2();
       }

      if(isSouthPong == false && isEastPong == false && isNorthPong == false && isWestPong == false
         && isSouthChow == false && isEastChow == false && isNorthChow == false && isWestChow == false
         && isSouthKong == false && isEastKong == false && isNorthKong == false && isWestKong == false
//         && concealedKongNum[1] == 0
         && isSouthWin == false && isEastWin == false && isNorthWin == false && isWestWin == false
              ){
          //清除暗杠标识
          ui->statusEastKong->clear();
          ui->statusEastCheck->clear();

           //下家摸新牌
           draw();//更新下一个摸牌(更新摸牌玩家)
           updateDapaiWanjia();
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);

           AIflag=true;

       }else{
          //预测位置更新为下一个摸牌的位置，以此来预测
          yuceDirection  = mopaiDirection;
          yucePos = mopaiPos;
          yuceCeng = mopaiCeng;
      }

    }else if(dapaiWanjia == 2){
        qDebug()<<"CRay  dapaiWanjia:"<<"North";
        for(list<Mj>::iterator iter =  handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
            if(cnt == pos){
                //暂存已打出的牌
                 playedPai.push_back(*iter);

                 //记录缺门牌
                 if(isNorthQue == true && systemConfig.queyimen == 1){
                     if(iter->getResult() < 10){
                         northQue = 0;
                     }else if(iter->getResult() > 10 && iter->getResult() < 20){
                         northQue = 10;
                     }else if(iter->getResult() > 20 && iter->getResult() < 30){
                         northQue = 20;
                     }
                     isNorthQue = false;
                 }

                qDebug()<<"dapai:"<<iter->getResult();

                //加入弃牌堆
                discardMjs.push_back(*iter);
                //从手牌剔除
                handNorthMjs.erase(iter);
                break;
            }
            cnt++;
        }
       discardDisplay(discardMjs);//展示弃牌

       //撤回：记录打牌
       playedPaiStack.push(*(playedPai.begin()));

       //重新展示手牌
       handNorthMjs.sort(cmpHandMjs);
       northHandDisplay(handNorthMjs);
       //设置遮罩层(消失)
       ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
       ui->justTakenLabel->setGeometry(1130,20,10,10);

       //判断吃碰杠
       if(systemConfig.chipai == 1  && systemConfig.queyimen == 0){
           isChow();
           ChowDisplay();
       }

       if(systemConfig.pongpai == 1){
           isPong();
           PongDisplay();
       }

       if(systemConfig.minggang == 1){
           isKong();
           KongDisplay();
       }


       ui->statusNorthKong->clear();
       ui->statusNorthCheck->clear();
       ui->statusNorthWin->clear();//胡

       if(systemConfig.zhixianzimo == 0){
            isWin2();
       }

       if(isSouthPong == false && isEastPong == false && isNorthPong == false && isWestPong == false
        && isSouthChow == false && isEastChow == false && isNorthChow == false && isWestChow == false
         && isSouthKong == false && isEastKong == false && isNorthKong == false && isWestKong == false
//         && concealedKongNum[2] == 0
         && isSouthWin == false && isEastWin == false && isNorthWin == false && isWestWin == false
               ){
           //清除暗杠标识
           ui->statusNorthKong->clear();
           ui->statusNorthCheck->clear();

           //下家摸新牌
           //ccccc
           draw();//更新下一个摸牌(更新摸牌玩家)

           updateDapaiWanjia();
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);

           AIflag=true;

       }else{
           //预测位置更新为下一个摸牌的位置，以此来预测
           yuceDirection  = mopaiDirection;
           yucePos = mopaiPos;
           yuceCeng = mopaiCeng;
       }

    }else if(dapaiWanjia == 3){
        qDebug()<<"CRay  dapaiWanjia:"<<"West";
        for(list<Mj>::iterator iter =  handWestMjs.begin(); iter != handWestMjs.end();iter++){
            if(cnt == pos){
                //暂存已打出的牌
                 playedPai.push_back(*iter);

                 //记录缺门牌
                 if(isWestQue == true && systemConfig.queyimen == 1){
                     if(iter->getResult() < 10){
                         westQue = 0;
                     }else if(iter->getResult() > 10 && iter->getResult() < 20){
                         westQue = 10;
                     }else if(iter->getResult() > 20 && iter->getResult() < 30){
                         westQue = 20;
                     }
                     isWestQue = false;
                 }
                qDebug()<<"dapai:"<<iter->getResult();
                //加入弃牌堆
                discardMjs.push_back(*iter);
                //从手牌剔除
                handWestMjs.erase(iter);
                break;
            }
            cnt++;
        }
        discardDisplay(discardMjs);//展示弃牌

        //撤回：记录打牌
       playedPaiStack.push(*(playedPai.begin()));


       //重新展示手牌
       handWestMjs.sort(cmpHandMjs);
       westHandDisplay(handWestMjs);
       //设置遮罩层(消失)
       ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
       ui->justTakenLabel->setGeometry(1130,20,10,10);

       //判断吃碰杠
       if(systemConfig.chipai == 1 && systemConfig.queyimen == 0){
           isChow();
           ChowDisplay();
       }

       if(systemConfig.pongpai == 1){
           isPong();
           PongDisplay();
       }

       if(systemConfig.minggang == 1){
           isKong();
           KongDisplay();
       }

       ui->statusWestKong->clear();
       ui->statusWestCheck->clear();
       ui->statusWestWin->clear();//胡
       if(systemConfig.zhixianzimo == 0){
            isWin2();
       }

       if(isSouthPong == false && isEastPong == false && isNorthPong == false && isWestPong == false
         && isSouthChow == false && isEastChow == false && isNorthChow == false && isWestChow == false
         && isSouthKong == false && isEastKong == false && isNorthKong == false && isWestKong == false
//          && concealedKongNum[3] == 0
          && isSouthWin == false && isEastWin == false && isNorthWin == false && isWestWin == false
               ){
           //清除暗杠标识
           ui->statusSouthKong->clear();
           ui->statusSouthCheck->clear();

           //下家摸新牌
           draw();//更新下一个摸牌(更新摸牌玩家)

           updateDapaiWanjia();
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);

           AIflag=true;

       }else{
           //预测位置更新为下一个摸牌的位置，以此来预测
           yuceDirection  = mopaiDirection;
           yucePos = mopaiPos;
           yuceCeng = mopaiCeng;
       }
    }

    if(discardMjs.size() == majhongTotal.size() - 52){//减去4个人13张手牌

        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                 QMessageBox::Ok);
        clearVariable();//结束游戏，重置各种状态，但不清空面板
        return;
    }
    yucePai();

    if (systemConfig.AIPlayers>0)
    {
        AIHu();
        AIKong();
        AIPong();
        AIChow();

        AIPlay();
    }

}
//南胡
void UIMainWindows::HuSouth()
{
    if(isSouthWin == true){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>恭喜玩家 南 胡牌！！</font></h1>"),
                                 QMessageBox::Ok);
        //胡牌后的显示
        //手牌全部摊开
        for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
            if(iter->getPaizhuangtai() == 0){
                iter->setHu(true);
            }
        }
        //展示手牌
        southHandDisplay(handSouthMjs);

        //清空标示
        clearHandStatus();

        //显示胡牌标示
        QPixmap huSouth(":/image/hu2.png");
        huSouth.scaled(ui->huSouth->size(), Qt::IgnoreAspectRatio);
        ui->huSouth->setScaledContents(true);
        ui->huSouth->setPixmap(huSouth);
        //清空遮罩
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
        ui->justTakenLabel->setGeometry(1130,20,10,10);
        ui->mainStackedWidget->repaint();

    }
    endWanjia.insert(0);
    if(systemConfig.queyimen == 1){
        if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
            isQiangganghu = false;
            //endWanjia.insert(0);

            Mj tempMj;//抢胡的牌
            if(dapaiWanjia == 1){
               //删除被抢杠的牌
               for(list<Mj>::iterator i = handEastMjs.begin(); i != handEastMjs.end();i++){
                   if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                      tempMj = *i;
                      handEastMjs.erase(i);
                      break;
                     }
                }
                ui->statusEastKong->clear();//删除杠识
                eastHandDisplay(handEastMjs);

             }else if(dapaiWanjia == 2){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handNorthMjs.begin(); i != handNorthMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handNorthMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusNorthKong->clear();//删除杠识
                 northHandDisplay(handNorthMjs);

             }else if(dapaiWanjia == 3){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handWestMjs.begin(); i != handWestMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handWestMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusWestKong->clear();//删除杠识
                 westHandDisplay(handWestMjs);
             }

             //胡牌加入抢杠的牌
             handEastMjs.push_back(tempMj);

             //预测牌消失
             ui->predictionSouth1->clear();
             ui->predictionSouth2->clear();
             ui->predictionSouth3->clear();
             ui->predictionSouth4->clear();
             ui->predictionSouth5->clear();
             ui->predictionSouth6->clear();
             ui->predictionSouth7->clear();
             ui->predictionSouth8->clear();
             ui->predictionSouth9->clear();
             ui->predictionSouth10->clear();
             //手牌全部摊开
             for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                 if(iter->getPaizhuangtai() == 0){
                     iter->setHu(true);
                 }
             }
             //展示手牌
             southHandDisplay(handSouthMjs);

             //清空胡牌和过标示
             ui->statusSouthCheck->clear();
             ui->statusSouthWin->clear();
             isSouthWin = false;

             //显示胡牌标示
             QPixmap huSouth(":/image/hu2.png");
             huSouth.scaled(ui->huSouth->size(), Qt::IgnoreAspectRatio);
             ui->huSouth->setScaledContents(true);
             ui->huSouth->setPixmap(huSouth);

             //摸牌
             mopaiWanjia = 0;
             updateMopaiWanjia();
             draw();//内包括检测暗杠

             //更新打牌玩家
             dapaiWanjia = 0;
             updateDapaiWanjia();

             //展示当前打牌位置
             directionDisplay(dapaiWanjia);

        }else{
            //endWanjia.insert(0);
            //预测牌消失
            ui->predictionSouth1->clear();
            ui->predictionSouth2->clear();
            ui->predictionSouth3->clear();
            ui->predictionSouth4->clear();
            ui->predictionSouth5->clear();
            ui->predictionSouth6->clear();
            ui->predictionSouth7->clear();
            ui->predictionSouth8->clear();
            ui->predictionSouth9->clear();
            ui->predictionSouth10->clear();
            //手牌全部摊开
            for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                if(iter->getPaizhuangtai() == 0){
                    iter->setHu(true);
                }
            }
            //展示手牌
            southHandDisplay(handSouthMjs);

            //清空标示
            clearHandStatus();

            isSouthWin = false;

            //显示胡牌标示
            QPixmap huSouth(":/image/hu2.png");
            huSouth.scaled(ui->huSouth->size(), Qt::IgnoreAspectRatio);
            ui->huSouth->setScaledContents(true);
            ui->huSouth->setPixmap(huSouth);

            //摸牌
            mopaiWanjia = 0;
            updateMopaiWanjia();
            draw();//内包括检测暗杠

            //更新打牌玩家
            dapaiWanjia = 0;
            updateDapaiWanjia();
            //展示当前打牌位置
            directionDisplay(dapaiWanjia);

            if(isZimo == false){
                //从弃牌堆拿走被胡的牌
                for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                    if(iter->getId() == playedPai.begin()->getId()){
                        discardMjs.erase(iter);
                        break;
                    }
                }
                discardDisplay(discardMjs);
            }else{
                isZimo = false;
            }

        }
    }

    if(endWanjia.size() == 3 && systemConfig.xuezhandaodi == 1){
         QMessageBox::information(this,tr("提示"),
         tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                  QMessageBox::Ok);
         clearVariable();//结束游戏，重置各种状态，但不清空面板
    }else if(endWanjia.size() == 1 && systemConfig.xuezhandaodi == 0){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                 QMessageBox::Ok);
        clearVariable();//结束游戏，重置各种状态，但不清空面板
    }
    southscore+=10;
    setScoreTxt();

}
//东胡
void UIMainWindows::HuEast()
{
    if(isEastWin == true){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>恭喜玩家 东 胡牌！！</font></h1>"),
                                 QMessageBox::Ok);

                //手牌全部摊开
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        iter->setHu(true);
                    }
                }
                //展示手牌
                eastHandDisplay(handEastMjs);

                //清空标示
                clearHandStatus();

                //显示胡牌标示
                QPixmap huEast(":/image/hu2.png");
                huEast.scaled(ui->huEast->size(), Qt::IgnoreAspectRatio);
                ui->huEast->setScaledContents(true);
                ui->huEast->setPixmap(huEast);
                //清空遮罩
                ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
                ui->justTakenLabel->setGeometry(1130,20,10,10);
                ui->mainStackedWidget->repaint();
    }
    endWanjia.insert(1);
    if(systemConfig.queyimen ==1 ){
        if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
            isQiangganghu = false;
           // endWanjia.insert(1);

            Mj tempMj;//抢胡的牌
             if(dapaiWanjia == 0){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handSouthMjs.begin(); i != handSouthMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handSouthMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusSouthKong->clear();//删除杠识
                 southHandDisplay(handSouthMjs);
             }else if(dapaiWanjia == 2){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handNorthMjs.begin(); i != handNorthMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handNorthMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusNorthKong->clear();//删除杠识
                 northHandDisplay(handNorthMjs);

             }else if(dapaiWanjia == 3){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handWestMjs.begin(); i != handWestMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handWestMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusWestKong->clear();//删除杠识
                 westHandDisplay(handWestMjs);
             }

             //胡牌加入抢杠的牌
             handEastMjs.push_back(tempMj);

             //删除预测牌
             ui->predictionEast1->clear();
             ui->predictionEast2->clear();
             ui->predictionEast3->clear();
             ui->predictionEast4->clear();
             ui->predictionEast5->clear();
             ui->predictionEast6->clear();
             ui->predictionEast7->clear();
             ui->predictionEast8->clear();
             ui->predictionEast9->clear();
             ui->predictionEast10->clear();
            //重新展示胡牌
             for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                 if(iter->getPaizhuangtai() == 0){
                     iter->setHu(true);
                 }
             }
             eastHandDisplay(handEastMjs);

             //清空胡牌和过标示
             ui->statusEastCheck->clear();
             ui->statusEastWin->clear();
             isEastWin = false;

             //显示胡牌标示
             QPixmap huEast(":/image/hu2.png");
             huEast.scaled(ui->huEast->size(), Qt::IgnoreAspectRatio);
             ui->huEast->setScaledContents(true);
             ui->huEast->setPixmap(huEast);

             //摸牌
             mopaiWanjia = 1;
             updateMopaiWanjia();
             draw();

             //更新打牌玩家
             dapaiWanjia = 1;
             updateDapaiWanjia();
             //展示当前打牌位置
             directionDisplay(dapaiWanjia);

        }else{
            //endWanjia.insert(1);

            ui->predictionEast1->clear();
            ui->predictionEast2->clear();
            ui->predictionEast3->clear();
            ui->predictionEast4->clear();
            ui->predictionEast5->clear();
            ui->predictionEast6->clear();
            ui->predictionEast7->clear();
            ui->predictionEast8->clear();
            ui->predictionEast9->clear();
            ui->predictionEast10->clear();


            for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                if(iter->getPaizhuangtai() == 0){
                    iter->setHu(true);
                }
            }
            eastHandDisplay(handEastMjs);

            //清空胡牌和过标示
            clearHandStatus();
            isEastWin = false;

            //显示胡牌标示
            QPixmap huEast(":/image/hu2.png");
            huEast.scaled(ui->huEast->size(), Qt::IgnoreAspectRatio);
            ui->huEast->setScaledContents(true);
            ui->huEast->setPixmap(huEast);

            //摸牌
            mopaiWanjia = 1;
            updateMopaiWanjia();
            draw();

            //更新打牌玩家
            dapaiWanjia = 1;
            updateDapaiWanjia();
            //展示当前打牌位置
            directionDisplay(dapaiWanjia);

            if(isZimo == false){
                //从弃牌堆拿走被胡的牌
                for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                    if(iter->getId() == playedPai.begin()->getId()){
                        discardMjs.erase(iter);
                        break;
                    }
                }
                discardDisplay(discardMjs);
            }else{
                isZimo = false;
            }
        }
    }

    if(endWanjia.size() == 3 && systemConfig.xuezhandaodi == 1){
         QMessageBox::information(this,tr("提示"),
         tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                  QMessageBox::Ok);
         clearVariable();//结束游戏，重置各种状态，但不清空面板
    }else if(endWanjia.size() == 1 && systemConfig.xuezhandaodi == 0){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                 QMessageBox::Ok);
        clearVariable();//结束游戏，重置各种状态，但不清空面板
    }

    eastscore+=10;
    setScoreTxt();
}
//北胡
void UIMainWindows::HuNorth()
{
    if(isNorthWin == true){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>恭喜玩家 北 胡牌！！</font></h1>"),
                                 QMessageBox::Ok);

                //手牌全部摊开
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        iter->setHu(true);
                    }
                }
                //展示手牌
                northHandDisplay(handNorthMjs);

                //清空标示
                clearHandStatus();

                //显示胡牌标示
                QPixmap huNorth(":/image/hu2.png");
                huNorth.scaled(ui->huNorth->size(), Qt::IgnoreAspectRatio);
                ui->huNorth->setScaledContents(true);
                ui->huNorth->setPixmap(huNorth);
                //清空遮罩
                ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
                ui->justTakenLabel->setGeometry(1130,20,10,10);
                ui->mainStackedWidget->repaint();
    }
    endWanjia.insert(2);
    if(systemConfig.queyimen == 1){
        if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
            isQiangganghu = false;
            //endWanjia.insert(2);

            Mj tempMj;//抢胡的牌
             if(dapaiWanjia == 0){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handSouthMjs.begin(); i != handSouthMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handSouthMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusSouthKong->clear();//删除杠识
                 southHandDisplay(handSouthMjs);
             }else if(dapaiWanjia == 1){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handEastMjs.begin(); i != handEastMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handEastMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusEastKong->clear();//删除杠识
                 eastHandDisplay(handEastMjs);

             }else if(dapaiWanjia == 3){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handWestMjs.begin(); i != handWestMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handWestMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusWestKong->clear();//删除杠识
                 westHandDisplay(handWestMjs);
             }

             //胡牌加入抢杠的牌
             handNorthMjs.push_back(tempMj);
             //删除预测牌
             ui->predictionNorth1->clear();
             ui->predictionNorth2->clear();
             ui->predictionNorth3->clear();
             ui->predictionNorth4->clear();
             ui->predictionNorth5->clear();
             ui->predictionNorth6->clear();
             ui->predictionNorth7->clear();
             ui->predictionNorth8->clear();
             ui->predictionNorth9->clear();
             ui->predictionNorth10->clear();
            //重新展示胡牌
             for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                 if(iter->getPaizhuangtai() == 0){
                     iter->setHu(true);
                 }
             }
             northHandDisplay(handNorthMjs);


             //清空胡牌和过标示
             ui->statusNorthCheck->clear();
             ui->statusNorthWin->clear();
             isNorthWin = false;

             //显示胡牌标示
             QPixmap huNorth(":/image/hu2.png");
             huNorth.scaled(ui->huNorth->size(), Qt::IgnoreAspectRatio);
             ui->huNorth->setScaledContents(true);
             ui->huNorth->setPixmap(huNorth);

             //摸牌
             mopaiWanjia = 2;
             updateMopaiWanjia();
             draw();

             //更新打牌玩家
             dapaiWanjia = 2;
             updateDapaiWanjia();
             //展示当前打牌位置
             directionDisplay(dapaiWanjia);


        }else{
            //endWanjia.insert(2);

            ui->predictionNorth1->clear();
            ui->predictionNorth2->clear();
            ui->predictionNorth3->clear();
            ui->predictionNorth4->clear();
            ui->predictionNorth5->clear();
            ui->predictionNorth6->clear();
            ui->predictionNorth7->clear();
            ui->predictionNorth8->clear();
            ui->predictionNorth9->clear();
            ui->predictionNorth10->clear();

            for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                if(iter->getPaizhuangtai() == 0){
                    iter->setHu(true);
                }
            }
            northHandDisplay(handNorthMjs);

            //清空胡牌和过标示
            clearHandStatus();
            isNorthWin = false;

            //显示胡牌标示
            QPixmap huNorth(":/image/hu2.png");
            huNorth.scaled(ui->huNorth->size(), Qt::IgnoreAspectRatio);
            ui->huNorth->setScaledContents(true);
            ui->huNorth->setPixmap(huNorth);

            //摸牌
            mopaiWanjia = 2;
            updateMopaiWanjia();
            draw();

            //更新打牌玩家
            dapaiWanjia = 2;
            updateDapaiWanjia();
            //展示当前打牌位置
            directionDisplay(dapaiWanjia);

            //从弃牌堆拿走被胡的牌
            if(isZimo == false){
                for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                    if(iter->getId() == playedPai.begin()->getId()){
                        discardMjs.erase(iter);
                        break;
                    }
                }
                discardDisplay(discardMjs);
        }else{
            isZimo = false;
        }
    }

    }

    if(endWanjia.size() == 3 && systemConfig.xuezhandaodi == 1){
         QMessageBox::information(this,tr("提示"),
         tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                  QMessageBox::Ok);
         clearVariable();//结束游戏，重置各种状态，但不清空面板
    }else if(endWanjia.size() == 1 && systemConfig.xuezhandaodi == 0){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                 QMessageBox::Ok);
        clearVariable();//结束游戏，重置各种状态，但不清空面板
    }

    northscore+=10;
    setScoreTxt();
}
//西胡
void UIMainWindows::HuWest()//
{
    if(isWestWin == true){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>恭喜玩家 西 胡牌！！</font></h1>"),
                                 QMessageBox::Ok);

                //手牌全部摊开
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        iter->setHu(true);
                    }
                }
                //展示手牌
                westHandDisplay(handWestMjs);

                //清空标示
                clearHandStatus();

                //显示胡牌标示
                QPixmap huWest(":/image/hu2.png");
                huWest.scaled(ui->huWest->size(), Qt::IgnoreAspectRatio);
                ui->huWest->setScaledContents(true);
                ui->huWest->setPixmap(huWest);
                //清空遮罩
                ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
                ui->justTakenLabel->setGeometry(1130,20,10,10);
                ui->mainStackedWidget->repaint();
    }
    endWanjia.insert(2);
    if(systemConfig.queyimen == 1){
        if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
            isQiangganghu = false;
            //endWanjia.insert(3);

            Mj tempMj;//抢胡的牌
             if(dapaiWanjia == 0){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handSouthMjs.begin(); i != handSouthMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handSouthMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusSouthKong->clear();//删除杠识
                 southHandDisplay(handSouthMjs);
             }else if(dapaiWanjia == 1){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handEastMjs.begin(); i != handEastMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handEastMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusEastKong->clear();//删除杠识
                 eastHandDisplay(handEastMjs);

             }else if(dapaiWanjia == 2){
                 //删除被抢杠的牌
                 for(list<Mj>::iterator i = handNorthMjs.begin(); i != handNorthMjs.end();i++){
                     if(i->getPaizhuangtai() == 0 && i->getResult() == qiangganghuPaiNum){
                         tempMj = *i;
                         handNorthMjs.erase(i);
                         break;
                     }
                 }
                 ui->statusNorthKong->clear();//删除杠识
                 northHandDisplay(handNorthMjs);

             }

             //胡牌加入抢杠的牌
             handWestMjs.push_back(tempMj);

             ui->predictionWest1->clear();
             ui->predictionWest2->clear();
             ui->predictionWest3->clear();
             ui->predictionWest4->clear();
             ui->predictionWest5->clear();
             ui->predictionWest6->clear();
             ui->predictionWest7->clear();
             ui->predictionWest8->clear();
             ui->predictionWest9->clear();
             ui->predictionWest10->clear();

             for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                 if(iter->getPaizhuangtai() == 0){
                     iter->setHu(true);
                 }
             }
             westHandDisplay(handWestMjs);

             //清空胡牌和过标示
             ui->statusWestCheck->clear();
             ui->statusWestWin->clear();
             isWestWin = false;

             //显示胡牌标示
             QPixmap huWest(":/image/hu2.png");
             huWest.scaled(ui->huWest->size(), Qt::IgnoreAspectRatio);
             ui->huWest->setScaledContents(true);
             ui->huWest->setPixmap(huWest);

             //摸牌
             mopaiWanjia = 3;
             updateMopaiWanjia();
             draw();

             //更新打牌玩家
             dapaiWanjia = 3;
             updateDapaiWanjia();
             //展示当前打牌位置
             directionDisplay(dapaiWanjia);


        }else{
            //endWanjia.insert(3);

            ui->predictionWest1->clear();
            ui->predictionWest2->clear();
            ui->predictionWest3->clear();
            ui->predictionWest4->clear();
            ui->predictionWest5->clear();
            ui->predictionWest6->clear();
            ui->predictionWest7->clear();
            ui->predictionWest8->clear();
            ui->predictionWest9->clear();
            ui->predictionWest10->clear();

            for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                if(iter->getPaizhuangtai() == 0){
                    iter->setHu(true);
                }
            }
            westHandDisplay(handWestMjs);

            //清空胡牌和过标示
            clearHandStatus();
            isWestWin = false;

            //显示胡牌标示
            QPixmap huWest(":/image/hu2.png");
            huWest.scaled(ui->huWest->size(), Qt::IgnoreAspectRatio);
            ui->huWest->setScaledContents(true);
            ui->huWest->setPixmap(huWest);

            //摸牌
            mopaiWanjia = 3;
            updateMopaiWanjia();
            draw();

            //更新打牌玩家
            dapaiWanjia = 3;
            updateDapaiWanjia();
            //展示当前打牌位置
            directionDisplay(dapaiWanjia);

            //从弃牌堆拿走被胡的牌
            if(isZimo == false){
                for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                    if(iter->getId() == playedPai.begin()->getId()){
                        discardMjs.erase(iter);
                        break;
                    }
                }
                discardDisplay(discardMjs);
            }else{//自摸不拿走牌
                isZimo = false;
            }
        }
    }

    if(endWanjia.size() == 3 && systemConfig.xuezhandaodi == 1){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                 QMessageBox::Ok);
        clearVariable();//结束游戏，重置各种状态，但不清空面板
    }else if(endWanjia.size() == 1 && systemConfig.xuezhandaodi == 0){
        QMessageBox::information(this,tr("提示"),
        tr("<h1> <font color=red size=3>本局结束！！</font></h1>"),
                                 QMessageBox::Ok);
        clearVariable();//结束游戏，重置各种状态，但不清空面板
    }

    westscore+=10;
    setScoreTxt();
}
//AI玩家吃牌
void UIMainWindows::AIChow()
{
    if ((zhuangjia == 0)&&(isSouthChow==true))
        return;
    if ((zhuangjia == 1)&&(isEastChow==true))
        return;
    if ((zhuangjia == 2)&&(isNorthChow==true))
        return;
    if ((zhuangjia == 3)&&(isWestChow==true))
        return;



    if (isSouthChow==true)
    {
        qDebug()<<"chipai:"<<playedPai.begin()->getResult();
        //吃操作
        AIchowOperating(handSouthMjs);

        //变更打牌玩家
        dapaiWanjia = 0;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);

        if(systemConfig.angang == 1){
           //判断暗杠
           isConcealedKong(handSouthMjs, 0);
           KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();

        if(chowType.size() < 1) return;
        //可以操作的牌的开始位置
        handSouthIndex += 3;
        //重置吃标志
        isSouthChow = false;

        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 1;

        //展示手牌
        southHandDisplay(handSouthMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //从弃牌堆拿走被吃的牌
        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
            if(iter->getId() == playedPai.begin()->getId()){
                discardMjs.erase(iter);
                break;
            }
        }
        discardDisplay(discardMjs);
        return;
     }
     if (isEastChow==true)
     {
         qDebug()<<"chipai:"<<playedPai.begin()->getResult();
        //吃操作
        AIchowOperating(handEastMjs);

        //变更打牌玩家
        dapaiWanjia = 1;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);

        if(systemConfig.angang == 1){
           //判断暗杠
           isConcealedKong(handEastMjs, 1);
           KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();

        if(chowType.size() < 1) return;
        //可以操作的牌的开始位置
        handEastIndex += 3;
        //重置吃标志
        isEastChow = false;

        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 2;

        //展示手牌
        eastHandDisplay(handEastMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //从弃牌堆拿走被吃的牌
        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
            if(iter->getId() == playedPai.begin()->getId()){
                discardMjs.erase(iter);
                break;
            }
        }
        discardDisplay(discardMjs);
        return;
    }
     if (isNorthChow==true)
     {
         qDebug()<<"chipai:"<<playedPai.begin()->getResult();
        //吃操作
        AIchowOperating(handNorthMjs);

        //变更打牌玩家
        dapaiWanjia = 2;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);

        if(systemConfig.angang == 1){
           //判断暗杠
           isConcealedKong(handNorthMjs, 2);
           KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();

        if(chowType.size() < 1) return;
        //可以操作的牌的开始位置
        handNorthIndex += 3;
        //重置吃标志
        isNorthChow = false;

        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 3;

        //展示手牌
        northHandDisplay(handNorthMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //从弃牌堆拿走被吃的牌
        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
            if(iter->getId() == playedPai.begin()->getId()){
                discardMjs.erase(iter);
                break;
            }
        }
        discardDisplay(discardMjs);
        return;
    }
     if (isWestChow==true)
     {
         qDebug()<<"chipai:"<<playedPai.begin()->getResult();
        //吃操作
        AIchowOperating(handWestMjs);

        //变更打牌玩家
        dapaiWanjia = 3;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);

        if(systemConfig.angang == 1){
           //判断暗杠
           isConcealedKong(handWestMjs, 3);
           KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();

        if(chowType.size() < 1) return;
        //可以操作的牌的开始位置
        handWestIndex += 3;
        //重置吃标志
        isWestChow = false;

        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 0;

        //展示手牌
        westHandDisplay(handWestMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //从弃牌堆拿走被吃的牌
        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
            if(iter->getId() == playedPai.begin()->getId()){
                discardMjs.erase(iter);
                break;
            }
        }
        discardDisplay(discardMjs);
        return;
    }

}
//AI玩家碰牌
void UIMainWindows::AIPong()
{
    if ((zhuangjia == 0)&&(isSouthPong==true))
        return;
    if ((zhuangjia == 1)&&(isEastPong==true))
        return;
    if ((zhuangjia == 2)&&(isNorthPong==true))
        return;
    if ((zhuangjia == 3)&&(isWestPong==true))
        return;

    if (isSouthPong==true){
        pongOperating(handSouthMjs);
        if(isSouthKong == true){//本可以杠，且碰了的
            isSouthKong = false;
        }

        if(systemConfig.angang == 1){
            isConcealedKong(handSouthMjs, 0);//判断暗杠
            KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();
        return;
    }
    if (isEastPong==true){
        pongOperating(handEastMjs);
        if(isEastKong == true){//本可以杠，且碰了的
            isEastKong = false;
        }
        if(systemConfig.angang == 1){
            isConcealedKong(handEastMjs, 1);//判断暗杠
            KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();
        return;
    }
    if (isNorthPong==true){
        pongOperating(handNorthMjs);
        if(isNorthKong == true){//本可以杠，且碰了的
            isNorthKong = false;
        }
        if(systemConfig.angang == 1){
            isConcealedKong(handNorthMjs, 2);//判断暗杠
            KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();
        return;
    }
    if (isWestPong==true){
        pongOperating(handWestMjs);
        if(isWestKong == true){//本可以杠，且碰了的
            isWestKong = false;
        }
        if(systemConfig.angang == 1){
            isConcealedKong(handWestMjs, 3);//判断暗杠
            KongDisplay();
        }

        //检测听牌
        clearReady();
        isReady();
        return;
    }

}
//AI玩家杠牌
void UIMainWindows::AIKong()
{
    if ((zhuangjia == 0)&&(isSouthKong==true)) return;
    if ((zhuangjia == 1)&&(isEastKong==true)) return;
    if ((zhuangjia == 2)&&(isNorthKong==true)) return;
    if ((zhuangjia == 3)&&(isWestKong==true)) return;
    //南
    if(concealedKongNum[0] == 0 && isSouthKong == true){//只有一个明杠
        kongOperating(handSouthMjs);
        return;
    }else if(concealedKongNum[0] == 1 && isSouthKong == false){//只有一个暗杠
       kongOperating2(handSouthMjs);
       return;
    }else if(concealedKongNum[0] > 1){
//        dapaiWanjia = 0;
//        isSouthConcealedKong = true;
        kongOperating2(handSouthMjs);//AI，当做只有一个暗杠处理
        return;
    }
    //东
    if(concealedKongNum[1] == 0 && isEastKong == true){//只有一个明杠
        kongOperating(handEastMjs);
        return;
    }else if(concealedKongNum[1] == 1 && isEastKong == false){//只有一个暗杠
       kongOperating2(handEastMjs);
       return;
    }else if(concealedKongNum[1] > 1){
//        dapaiWanjia = 1;
//        isEastConcealedKong = true;
        kongOperating2(handEastMjs);
        return;
    }
    //北
    if(concealedKongNum[2] == 0 && isNorthKong == true){//只有一个明杠
        kongOperating(handNorthMjs);
        return;
    }else if(concealedKongNum[2] == 1 && isNorthKong == false){//只有一个暗杠
       kongOperating2(handNorthMjs);
       return;
    }else if(concealedKongNum[2] > 1){
//        dapaiWanjia = 2;
//        isNorthConcealedKong = true;
        kongOperating2(handNorthMjs);
        return;
    }
    //西
    if(concealedKongNum[3] == 0 && isWestKong == true){//只有一个明杠
       kongOperating(handWestMjs);
       return;
    }else if(concealedKongNum[3] == 1 && isWestKong == false){//只有一个暗杠
       kongOperating2(handWestMjs);
       return;
    }else if(concealedKongNum[3] > 1){
//        dapaiWanjia = 3;
//        isWestConcealedKong = true;
        kongOperating2(handWestMjs);
        return;
    }

}
//AI玩家胡牌
void UIMainWindows::AIHu()
{
    if ((zhuangjia == 0)&&(isSouthWin==true)) return;
    if ((zhuangjia == 1)&&(isEastWin==true)) return;
    if ((zhuangjia == 2)&&(isNorthWin==true)) return;
    if ((zhuangjia == 3)&&(isWestWin==true)) return;
    if (isSouthWin==true)   HuSouth();
    if (isEastWin==true)    HuEast();
    if (isNorthWin==true)   HuNorth();
    if (isWestWin==true)    HuWest();

}
//AI玩家判断打出哪张牌
int UIMainWindows::AIPosition(std::list<Mj> &tmpMjs)
{
    int pos[18]={0};
    int val[18]={0};
    int cn=0;
    int id;
    int minval;
    for(list<Mj>::iterator iter =  tmpMjs.begin(); iter != tmpMjs.end();iter++){
        qDebug()<<"tmpMjs:"<<cn<<":"<<iter->getResult();
        pos[cn]=iter->getResult();
        cn++;
    }
    for(int i=0;i<cn;i++){
        //刻子 100
        if (((i+2)<cn)&&(pos[i]==pos[i+1])&&(pos[i]==pos[i+2])&&(val[i+2]<100)){
            val[i]=100;  val[i+1]=100;val[i+2]=100;  }
        //顺子，排除字牌 80
        else if (((i+2)<cn)&&(pos[i]==pos[i+1]-1)&&(pos[i]==pos[i+2]-2)&&(pos[i+2]<31)){
            val[i]=80;val[i+1]=80;val[i+2]=80;}
        //对子 50
        else if (((i+1)<cn)&&(pos[i]==pos[i+1])&&(val[i]<100)){
            val[i]=50;val[i+1]=50;}
        //连牌 30
        else if (((i+1)<cn)&&(pos[i]==pos[i+1]-1)&&(val[i]<80)&&(pos[i+1]<31)){
            val[i]=30;val[i+1]=30;}
        qDebug()<<"val[]:"<<i<<":"<<val[i];
    }
    minval=val[cn-1];
    id=cn-1;
    for(int i=cn-1;i>=0;i--){
        if (val[i]<minval){
            id=i;
            minval=val[i];
        }
    }
    return id;
}
//AI玩家打牌
void UIMainWindows::AIPlay()
{

//ccccc
    if (dapaiWanjia == zhuangjia)
        return;
    if ((zhuangjia == 0)&&(isSouthPong==true)) return;
    if ((zhuangjia == 1)&&(isEastPong==true))  return;
    if ((zhuangjia == 2)&&(isNorthPong==true)) return;
    if ((zhuangjia == 3)&&(isWestPong==true))  return;

    if ((zhuangjia == 0)&&(isSouthWin==true))  return;
    if ((zhuangjia == 1)&&(isEastWin==true))   return;
    if ((zhuangjia == 2)&&(isNorthWin==true))  return;
    if ((zhuangjia == 3)&&(isWestWin==true))   return;

    if ((zhuangjia == 0)&&(isSouthKong==true)) return;
    if ((zhuangjia == 1)&&(isEastKong==true))  return;
    if ((zhuangjia == 2)&&(isNorthKong==true)) return;
    if ((zhuangjia == 3)&&(isWestKong==true))  return;

    if ((zhuangjia == 0)&&(isSouthChow==true)) return;
    if ((zhuangjia == 1)&&(isEastChow==true))  return;
    if ((zhuangjia == 2)&&(isNorthChow==true)) return;
    if ((zhuangjia == 3)&&(isWestChow==true))  return;

    if (dapaiWanjia == 0){
        //重新展示手牌
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handSouthMjs.sort(cmpHandMjs);//重新排序
        southHandDisplay(handSouthMjs);
        //设置遮罩层(消失)
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
        ui->justTakenLabel->setGeometry(1130,20,10,10);
        ui->mainStackedWidget->repaint();
        Sleep(400);

        int id=0;
        if (systemConfig.AILevel==1)
            id=handSouthMjs.size()-3;
        if (systemConfig.AILevel==2)
            id=AIPosition(handSouthMjs);

        int x=handSouthlist[id]->x();

        handSouthlist[id]->setGeometry(x, 598, 35, 55);;//设置选中牌的预提示动作
        ui->mainStackedWidget->repaint();
        Sleep(400);                                     //停顿显示
        handSouthlist[id]->setGeometry(x, 608, 35, 55);;
        ui->mainStackedWidget->repaint();

        if(isSouthChow == false && isSouthConcealedKong == false){
            if(handSouthIndex <=id){
                dapai(id);
                //yucePai();
            }
        }else if(isSouthChow == true){
            chowDapai(id);
        }else if(isSouthConcealedKong == true){
            kongDapai(id);
        }
        return;
    }
    if (dapaiWanjia == 1){
        //重新展示手牌
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handEastMjs.sort(cmpHandMjs);//重新排序
        eastHandDisplay(handEastMjs);

        //设置遮罩层(消失)
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
        ui->justTakenLabel->setGeometry(1130,20,10,10);
        ui->mainStackedWidget->repaint();
        Sleep(400);

        int id=0;
        if (systemConfig.AILevel==1)
            id=handEastMjs.size()-3;
        if (systemConfig.AILevel==2)
            id=AIPosition(handEastMjs);

        int y=handEastlist[id]->y();
        handEastlist[id]->setGeometry(966, y, 55, 35);
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handEastlist[id]->setGeometry(976, y, 55, 35);
        ui->mainStackedWidget->repaint();

        if(isEastChow == false && isEastConcealedKong == false){
            if(handEastIndex <=id){
                dapai(id);
                //yucePai();
            }
        }else if(isEastChow == true){
            chowDapai(id);
        }else if(isEastConcealedKong == true){
            kongDapai(id);
        }
        return;
    }
    if (dapaiWanjia == 2){
        //重新展示手牌
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handNorthMjs.sort(cmpHandMjs);//重新排序
        northHandDisplay(handNorthMjs);
        //设置遮罩层(消失)
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
        ui->justTakenLabel->setGeometry(1130,20,10,10);
        ui->mainStackedWidget->repaint();
        Sleep(400);

        int id=0;
        if (systemConfig.AILevel==1)
            id=handNorthMjs.size()-3;
        if (systemConfig.AILevel==2)
            id=AIPosition(handNorthMjs);

        int x=handNorthlist[id]->x();
        handNorthlist[id]->setGeometry(x, 38, 35, 55);
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handNorthlist[id]->setGeometry(x, 48, 35, 55);
        ui->mainStackedWidget->repaint();

        if(isNorthChow == false && isNorthConcealedKong == false){
            if(handNorthIndex <=id){
                 dapai(id);
                 //yucePai();
            }
        }else if(isNorthChow == true){
             chowDapai(id);
        }else if(isNorthConcealedKong == true){
             kongDapai(id);
        }
        return;
    }
    if (dapaiWanjia == 3){
        //重新展示手牌
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handWestMjs.sort(cmpHandMjs);//重新排序
        westHandDisplay(handWestMjs);
        //设置遮罩层(消失)
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
        ui->justTakenLabel->setGeometry(1130,20,10,10);
        ui->mainStackedWidget->repaint();
        Sleep(400);

        int id=0;
        if (systemConfig.AILevel==1)
            id=handSouthMjs.size()-3;
        if (systemConfig.AILevel==2)
            id=AIPosition(handWestMjs);

        int y=handWestlist[id]->y();
        handWestlist[id]->setGeometry(146, y, 55, 35);
        ui->mainStackedWidget->repaint();
        Sleep(400);
        handWestlist[id]->setGeometry(136, y, 55, 35);
        ui->mainStackedWidget->repaint();

        if(isWestChow == false && isWestConcealedKong == false){
            if(handWestIndex <=id){
                dapai(id);
                //yucePai();
            }
        }else if(isWestChow == true){
            chowDapai(id);
        }else if(isWestConcealedKong == true){
            kongDapai(id);
        }
        return;
    }
}
//吃牌后的打牌操作
void UIMainWindows::chowDapai(int pos)
{

    pos++;//到实际位置
    pos++;//因为前面多了一个吃的牌

    if(dapaiWanjia == 0){//南
        list<Mj>::iterator iter = handSouthMjs.begin();
        while(--pos){
            iter++;
        }
        bool isFound = false;
        int paiNum;
        for(auto i:chowVec){
            if(i.getId() == iter->getId()){
                isFound = true;
                paiNum = iter->getResult();
                break;
            }
        }

        if(isFound == true){
            int diff = playedPai.begin()->getResult() - paiNum;//差值

            if(diff == 1){//type = 0  【3,4,5】diff = 4-3 = 1
                chowOperating2(handSouthMjs,0);
            }else if(diff == -1){//type = 1 【4,5,6】diff = 4 - 5 = -1
                chowOperating2(handSouthMjs,1);
            }else if(diff == 2){//type = 2 【2,3,4】 diff = 4 - 2 = 2
                chowOperating2(handSouthMjs,2);
            }

            //可以操作的牌的开始位置
            handSouthIndex += 3;
            //重置碰标志
            isSouthChow = false;
            isSouthPong = false;

             //更新摸牌玩家
             mopaiWanjia = 1;//摸牌转移到下家
             //展示手牌
             southHandDisplay(handSouthMjs);

             //清空吃组合
             chowType.clear();
             //展示当前打牌位置(更新位置)
             directionDisplay(dapaiWanjia);

             //预测（不摸牌的预测）
             yuceDirection  = mopaiDirection;
             yucePos = mopaiPos;
             yuceCeng = mopaiCeng;
             //预测牌
             yucePai();


        }

    }else if(dapaiWanjia == 1){//东
        list<Mj>::iterator iter = handEastMjs.begin();

        while(--pos){
            iter++;
        }
        bool isFound = false;
        int paiNum;
        for(auto i:chowVec){

            if(i.getId() == iter->getId()){
                isFound = true;
                paiNum = iter->getResult();

            }
        }

        if(isFound == true){
            int diff = playedPai.begin()->getResult() - paiNum;//差值
            //4为例
            if(diff == 1){//type = 0  【3,4,5】diff = 4-3 = 1
                chowOperating2(handEastMjs, 0);
            }else if(diff == -1){//type = 1 【4,5,6】diff = 4 - 5 = -1
                chowOperating2(handEastMjs, 1);
            }else if(diff == 2){//type = 2 【2,3,4】 diff = 4 - 2 = 2
                chowOperating2(handEastMjs, 2);
            }

            //可以操作的牌的开始位置
            handEastIndex += 3;
            //重置碰标志
            isEastChow = false;
            isEastPong = false;

             //更新摸牌玩家
             mopaiWanjia = 2;
             //展示手牌
             eastHandDisplay(handEastMjs);

             //清空吃组合
             chowType.clear();
             //展示当前打牌位置(更新位置)
             directionDisplay(dapaiWanjia);

             //预测（不摸牌的预测）
             yuceDirection  = mopaiDirection;
             yucePos = mopaiPos;
             yuceCeng = mopaiCeng;
             //预测牌
             yucePai();
        }


    }else if(dapaiWanjia == 2){//北
        list<Mj>::iterator iter = handNorthMjs.begin();
        while(--pos){
            iter++;
        }
        bool isFound = false;
        int paiNum;
        for(auto i:chowVec){
            if(i.getId() == iter->getId()){
                isFound = true;
                paiNum = iter->getResult();
                break;
            }
        }

        if(isFound == true){
            int diff = playedPai.begin()->getResult() - paiNum;//差值
            if(diff == 1){//type = 0  【3,4,5】diff = 4-3 = 1
                chowOperating2(handNorthMjs,0);
            }else if(diff == -1){//type = 1 【4,5,6】diff = 4 - 5 = -1
                chowOperating2(handNorthMjs,1);
            }else if(diff == 2){//type = 2 【2,3,4】 diff = 4 - 2 = 2
                chowOperating2(handNorthMjs,2);
            }

            //可以操作的牌的开始位置
            handNorthIndex += 3;
            //重置碰标志
            isNorthChow = false;
            isNorthPong = false;

             //更新摸牌玩家
             mopaiWanjia = 3;
             //展示手牌
             northHandDisplay(handNorthMjs);

             //清空吃组合
             chowType.clear();
             //展示当前打牌位置(更新位置)
             directionDisplay(dapaiWanjia);

             //预测（不摸牌的预测）
             yuceDirection  = mopaiDirection;
             yucePos = mopaiPos;
             yuceCeng = mopaiCeng;
             //预测牌
             yucePai();
        }
    }else if(dapaiWanjia == 3){//西
        list<Mj>::iterator iter = handWestMjs.begin();
        while(--pos){
            iter++;
        }
        bool isFound = false;
        int paiNum;
        for(auto i:chowVec){
            if(i.getId() == iter->getId()){
                isFound = true;
                paiNum = iter->getResult();
                break;
            }
        }

        if(isFound == true){
            int diff = playedPai.begin()->getResult() - paiNum;//差值
            if(diff == 1){//type = 0  【3,4,5】diff = 4-3 = 1
                chowOperating2(handWestMjs,0);
            }else if(diff == -1){//type = 1 【4,5,6】diff = 4 - 5 = -1
                chowOperating2(handWestMjs,1);
            }else if(diff == 2){//type = 2 【2,3,4】 diff = 4 - 2 = 2
                chowOperating2(handWestMjs,2);
            }

            //可以操作的牌的开始位置
            handWestIndex += 3;
            //重置碰标志
            isWestChow = false;
            isWestPong = false;

             //更新摸牌玩家
             mopaiWanjia = 0;
             //展示手牌
             westHandDisplay(handWestMjs);

             //清空吃组合
             chowType.clear();
             //展示当前打牌位置(更新位置)
             directionDisplay(dapaiWanjia);

             //预测（不摸牌的预测）
             yuceDirection  = mopaiDirection;
             yucePos = mopaiPos;
             yuceCeng = mopaiCeng;
             //预测牌
             yucePai();
        }
    }

    //从弃牌堆拿走被吃的牌
    for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
        if(iter->getId() == playedPai.begin()->getId()){
            discardMjs.erase(iter);
            break;
        }
    }
    discardDisplay(discardMjs);


}
//碰牌
void UIMainWindows::kongDapai(int pos)
{
   isQiangganghu = false;
   qiangganghuPaiNum = 0;
   qiangganghuType = -1;

   pos++;//到实际位置

   if(dapaiWanjia == 0){
       list<Mj>::iterator iter = handSouthMjs.begin();
       while(--pos){
           iter++;
       }
       bool isFound = false;
       int paiNum  = 0;

       for(auto i:concealedKongElement[0]){
           if(i == iter->getResult() && iter->getPaizhuangtai() == 0){
               isFound = true;
               paiNum = iter->getResult();
               break;
           }
       }

       if(isFound == true){
           for(auto i:qiangganghuElement[0]){
               if(i == paiNum){
                   isQiangganghu = true;
                   break;
               }
           }
           if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
               isWin3(paiNum);
           }

            if(systemConfig.qiangganghu == 1 & isQiangganghu == true && (isSouthWin == true || isEastWin == true || isNorthWin == true || isWestWin == true)){
                qiangganghuPaiNum = paiNum;
                qiangganghuType = 1;
           }else{
                 kongOperating3(handSouthMjs, paiNum);
            }

       }

   }else if(dapaiWanjia == 1){
       list<Mj>::iterator iter = handEastMjs.begin();
       while(--pos){
           iter++;
       }
       bool isFound = false;
       int paiNum = 0;
       for(auto i:concealedKongElement[1]){
           if(i == iter->getResult() && iter->getPaizhuangtai() == 0){
               isFound = true;
               paiNum = iter->getResult();
               break;
           }
       }

       if(isFound == true){
           for(auto i:qiangganghuElement[1]){
               if(i == paiNum){
                   isQiangganghu = true;
                   break;
               }
           }
           if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
               isWin3(paiNum);
           }

           if(systemConfig.qiangganghu == 1 & isQiangganghu == true && (isSouthWin == true || isEastWin == true || isNorthWin == true || isWestWin == true)){
               qiangganghuPaiNum = paiNum;
                  qiangganghuType = 1;

           }else{
                kongOperating3(handEastMjs, paiNum);
            }
       }
   }else if(dapaiWanjia == 2){
       list<Mj>::iterator iter = handNorthMjs.begin();
       while(--pos){
           iter++;
       }
       bool isFound = false;
       int paiNum = 0;
       for(auto i:concealedKongElement[2]){
           if(i == iter->getResult() && iter->getPaizhuangtai() == 0){
               isFound = true;
               paiNum = iter->getResult();
               break;
           }
       }

       if(isFound == true){
           for(auto i:qiangganghuElement[2]){
               if(i == paiNum){
                   isQiangganghu = true;
                   break;
               }
           }

           if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
               isWin3(paiNum);
           }

           if(systemConfig.qiangganghu == 1 & isQiangganghu == true && (isSouthWin == true || isEastWin == true || isNorthWin == true || isWestWin == true)){
                qiangganghuPaiNum = paiNum;
                qiangganghuType = 1;
           }else{
               kongOperating3(handNorthMjs, paiNum);
           }
       }
   }else if(dapaiWanjia == 3){
       list<Mj>::iterator iter = handWestMjs.begin();
       while(--pos){
           iter++;
       }
       bool isFound = false;
       int paiNum =  0;
       for(auto i:concealedKongElement[3]){
           if(i == iter->getResult() && iter->getPaizhuangtai() == 0){
               isFound = true;
               paiNum = iter->getResult();
               break;
           }
       }

       if(isFound == true){
           for(auto i:qiangganghuElement[3]){
               if(i == paiNum){
                   isQiangganghu = true;
                   break;
               }
           }
           if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
                isWin3(paiNum);
           }

            if(systemConfig.qiangganghu == 1 & isQiangganghu == true && (isSouthWin == true || isEastWin == true || isNorthWin == true || isWestWin == true)){
                 qiangganghuPaiNum = paiNum;
                 qiangganghuType = 1;
           }else{
                 kongOperating3(handWestMjs, paiNum);
            }
       }
   }

}
//更新下一摸牌的位置
void UIMainWindows::yuceUpdatePai()
{
    if(yuceDirection == 0){//南
        if(yuceCeng == 1){//第二层
            yuceCeng = 0;
            yucePos++;
        }else if(yuceCeng == 0){//第一层
            yuceCeng = 1;
        }

        if(yucePos >= zhangshuSouth/2){
            yuceDirection = 3;//西
            yucePos = 0;
            yuceCeng = 0;
        }
    }else if(yuceDirection == 1){//东
        if(yuceCeng == 1){//第二层
            yuceCeng = 0;
            yucePos++;
        }else if(yuceCeng == 0){//第一层
            yuceCeng = 1;
        }

        if(yucePos >= zhangshuEast/2){
            yuceDirection = 0;//南
            yucePos = 0;
            yuceCeng = 0;
        }
    }else if(yuceDirection == 2){//北
        if(yuceCeng == 1){//第二层
            yuceCeng = 0;
            yucePos++;
        }else if(yuceCeng == 0){//第一层
            yuceCeng = 1;
        }

        if(yucePos >= zhangshuNorth/2){
            yuceDirection = 1;//东
            yucePos = 0;
            yuceCeng = 0;
        }
    }else if(yuceDirection == 3){//西
        if(yuceCeng == 1){//第二层
            yuceCeng = 0;
            yucePos++;
        }else if(yuceCeng == 0){//第一层
            yuceCeng = 1;
        }

        if(yucePos >= zhangshuWest/2){
            yuceDirection = 2;//北
            yucePos = 0;
            yuceCeng = 0;
        }
    }
}
//查找将摸起的牌
void UIMainWindows::yuceFindPai(Mj &tempPai)
{
    if(yuceDirection == 0){
        if(yucePos == 0){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[0];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[0 + zhangshuSouth/2];
            }
        }else if(yucePos == 1){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[1];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[1 + zhangshuSouth/2];
            }
        }else if(yucePos == 2){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[2];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[2 + zhangshuSouth/2];
            }
        }else if(yucePos == 3){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[3];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[3 + zhangshuSouth/2];
            }
        }else if(yucePos == 4){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[4];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[4 + zhangshuSouth/2];
            }
        }else if(yucePos == 5){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[5];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[5 + zhangshuSouth/2];
            }
        }else if(yucePos == 6){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[6];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[6 + zhangshuSouth/2];
            }
        }else if(yucePos == 7){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[7];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[7 + zhangshuSouth/2];
            }
        }else if(yucePos == 8){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[8];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[8 + zhangshuSouth/2];
            }
        }else if(yucePos == 9){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[9];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[9 + zhangshuSouth/2];
            }
        }else if(yucePos == 10){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[10];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[10 + zhangshuSouth/2];
            }
        }else if(yucePos == 11){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[11];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[11 + zhangshuSouth/2];
            }
        }else if(yucePos == 12){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[12];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[12 + zhangshuSouth/2];
            }
        }else if(yucePos == 13){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[13];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[13 + zhangshuSouth/2];
            }
        }else if(yucePos == 14){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[14];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[14 + zhangshuSouth/2];
            }
        }else if(yucePos == 15){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[15];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[15 + zhangshuSouth/2];
            }
        }else if(yucePos == 16){
            if(yuceCeng == 0){
                tempPai = drawSouthMjs[16];
            }else if(yuceCeng == 1){
                 tempPai = drawSouthMjs[16 + zhangshuSouth/2];
            }
        }
    }else if(yuceDirection == 1){
        if(yucePos == 0){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[0];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[0 + zhangshuEast/2];
            }
        }else if(yucePos == 1){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[1];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[1 + zhangshuEast/2];
            }
        }else if(yucePos == 2){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[2];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[2 + zhangshuEast/2];
            }
        }else if(yucePos == 3){
            if(yuceCeng== 0){
                tempPai = drawEastMjs[3];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[3 + zhangshuEast/2];
            }
        }else if(yucePos == 4){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[4];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[4 + zhangshuEast/2];
            }
        }else if(yucePos == 5){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[5];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[5 + zhangshuEast/2];
            }
        }else if(yucePos == 6){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[6];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[6 + zhangshuEast/2];
            }
        }else if(yucePos == 7){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[7];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[7 + zhangshuEast/2];
            }
        }else if(yucePos == 8){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[8];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[8 + zhangshuEast/2];
            }
        }else if(yucePos == 9){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[9];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[9 + zhangshuEast/2];
            }
        }else if(yucePos == 10){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[10];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[10 + zhangshuEast/2];
            }
        }else if(yucePos == 11){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[11];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[11 + zhangshuEast/2];
            }
        }else if(yucePos == 12){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[12];
            }else if(mopaiCeng == 1){
                tempPai = drawEastMjs[12 + zhangshuEast/2];
            }
        }else if(yucePos == 13){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[13];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[13 + zhangshuEast/2];
            }
        }else if(yucePos == 14){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[14];
            }else if(yuceCeng== 1){
                tempPai = drawEastMjs[14 + zhangshuEast/2];
            }
        }else if(yucePos == 15){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[15];
            }else if(yuceCeng == 1){
                tempPai = drawEastMjs[15 + zhangshuEast/2];
            }
        }else if(yucePos == 16){
            if(yuceCeng == 0){
                tempPai = drawEastMjs[16];
             }else if(yuceCeng== 1){
                tempPai = drawEastMjs[16 + zhangshuEast/2];
            }
        }
    }else if(yuceDirection == 2){
        if(yucePos == 0){
          if(yuceCeng == 0){
              tempPai = drawNorthMjs[0];
          }else if(yuceCeng == 1){
              tempPai = drawNorthMjs[0 + zhangshuNorth/2];
          }
        }else if(yucePos == 1){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[1];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[1 + zhangshuNorth/2];
            }
        }else if(yucePos == 2){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[2];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[2 + zhangshuNorth/2];
            }
        }else if(yucePos == 3){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[3];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[3 + zhangshuNorth/2];
            }
        }else if(yucePos == 4){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[4];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[4 + zhangshuNorth/2];
            }
        }else if(yucePos == 5){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[5];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[5 + zhangshuNorth/2];
            }
        }else if(yucePos == 6){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[6];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[6 + zhangshuNorth/2];
            }
        }else if(yucePos == 7){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[7];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[7 + zhangshuNorth/2];
            }
        }else if(yucePos == 8){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[8];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[8 + zhangshuNorth/2];
            }
        }else if(yucePos == 9){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[9];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[9 + zhangshuNorth/2];
            }
        }else if(yucePos == 10){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[10];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[10 + zhangshuNorth/2];
            }
        }else if(yucePos == 11){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[11];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[11 + zhangshuNorth/2];
            }
        }else if(yucePos == 12){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[12];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[12 + zhangshuNorth/2];
            }
        }else if(yucePos == 13){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[13];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[13 + zhangshuNorth/2];
            }
        }else if(yucePos == 14){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[14];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[14 + zhangshuNorth/2];
            }
        }else if(yucePos == 15){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[15];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[15 + zhangshuNorth/2];
            }
        }else if(yucePos == 16){
            if(yuceCeng == 0){
                tempPai = drawNorthMjs[16];
            }else if(yuceCeng == 1){
                tempPai = drawNorthMjs[16 + zhangshuNorth/2];
            }
        }
    }else if(yuceDirection == 3){
            if(yucePos == 0){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[0];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[0 + zhangshuWest/2];
                }
            }else if(yucePos == 1){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[1];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[1 + zhangshuWest/2];
                }
            }else if(yucePos == 2){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[2];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[2 + zhangshuWest/2];
                }
            }else if(yucePos == 3){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[3];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[3 + zhangshuWest/2];
                }
            }else if(yucePos == 4){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[4];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[4 + zhangshuWest/2];
                }
            }else if(yucePos == 5){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[5];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[5 + zhangshuWest/2];
                }
            }else if(yucePos == 6){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[6];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[6 + zhangshuWest/2];
                }
            }else if(yucePos == 7){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[7];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[7 + zhangshuWest/2];
                }
            }else if(yucePos == 8){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[8];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[8 + zhangshuWest/2];
                }
            }else if(yucePos == 9){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[9];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[9 + zhangshuWest/2];
                }
            }else if(yucePos == 10){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[10];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[10 + zhangshuWest/2];
                }
            }else if(yucePos == 11){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[11];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[11 + zhangshuWest/2];
                }
            }else if(yucePos == 12){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[12];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[12 + zhangshuWest/2];
                }
            }else if(yucePos == 13){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[13];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[13 + zhangshuWest/2];
                }
            }else if(yucePos == 14){
                if(mopaiCeng == 0){
                    tempPai = drawWestMjs[14];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[14 + zhangshuWest/2];
                }
            }else if(yucePos ==15){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[15];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[15 + zhangshuWest/2];
                }
            }else if(yucePos ==16){
                if(yuceCeng == 0){
                    tempPai = drawWestMjs[16];
                }else if(yuceCeng == 1){
                    tempPai = drawWestMjs[16 + zhangshuWest/2];
                }
            }
    }
}
//判断是否存在吃牌操作，如有设置相关状态
void UIMainWindows::isChow()
{
    isSouthChow = false;
    isNorthChow = false;
    isEastChow = false;
    isWestChow = false;
    chowType.clear();

    int paiValue = playedPai.begin()->getResult();//获得当前牌的数字

    int nPai1;//相邻的两张牌
    int nPai2;
    bool isFound1;
    bool isFound2;

    if (paiValue>30) return;//如是字牌直接跳出，不用判断

    if(dapaiWanjia == 0){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handEastMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isEastChow = true;
             chowType.push_back(0);
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handEastMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isEastChow = true;
            chowType.push_back(1);
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handEastMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;

            }
        }
        if(isFound1 == true && isFound2 == true){
            isEastChow = true;
             chowType.push_back(2);
        }

    }else if(dapaiWanjia == 1){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handNorthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isNorthChow = true;
            chowType.push_back(0);
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handNorthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isNorthChow = true;
            chowType.push_back(1);
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handNorthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isNorthChow = true;
            chowType.push_back(2);
        }
    }else if(dapaiWanjia == 2){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handWestMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isWestChow = true;
            chowType.push_back(0);
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handWestMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isWestChow = true;
            chowType.push_back(1);
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handWestMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isWestChow = true;
            chowType.push_back(2);
        }
    }else if(dapaiWanjia == 3){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handSouthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isSouthChow = true;
            chowType.push_back(0);
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handSouthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isSouthChow = true;
            chowType.push_back(1);
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handSouthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            isSouthChow = true;
            chowType.push_back(2);
        }
    }


}
//判断是否存在两种吃的可能。
//如手牌为2万、3万、4万、5万，上家打出3万，一种吃法为用2万、4万吃，一种吃法为用4万、5万吃
//当存在这种情形时，需要由打牌玩家选择可能吃法的第一张牌，才能执行吃操作
//AI玩家默认选择第一种吃法
bool UIMainWindows::isChow2(int direction, int paiValue)
{
    int nPai1;//相邻的两张牌
    int nPai2;
    bool isFound1;
    bool isFound2;

    if(direction == 0){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handEastMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handEastMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
           return true;
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handEastMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;

            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }

    }else if(direction == 1){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handNorthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handNorthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
           return true;
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handNorthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }
    }else if(direction == 2){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handWestMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handWestMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
           return true;
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handWestMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
           return true;
        }
    }else if(direction == 3){

        nPai1 = paiValue - 1;
        nPai2 = paiValue + 1;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handSouthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }

        nPai1 = paiValue + 1;
        nPai2 = paiValue + 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handSouthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
            return true;
        }

        nPai1 = paiValue - 1;
        nPai2 = paiValue - 2;
        isFound1 = false;
        isFound2 = false;

        for(auto i:handSouthMjs){
            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 0){
                isFound1 = true;
            }
            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 0){
                isFound2 = true;
            }
        }
        if(isFound1 == true && isFound2 == true){
           return true;
        }
    }
    return false;
}
//AI吃牌操作
void UIMainWindows::AIchowOperating(std::list<Mj> &handMjs)
{
    //把吃的牌放入牌首
    handMjs.push_front(*(playedPai.begin()));
    handMjs.begin()->setPaizhuangtai(4);

    //清空吃碰杠状态
    clearHandStatus();
    //if(chowType.size() == 1){
    if(chowType.size() >= 1){
        int type = *chowType.begin();
        int nPai1, nPai2;//自己牌中吃的牌
        int cnt1, cnt2;//只记录第一个组合可以吃的牌
        int paiNum = playedPai.begin()->getResult();//吃的牌
        Mj mj1, mj2;//插入的两个麻将

        if(type == 0){//-1,+1
            cnt1 = 0;
            cnt2 = 0;

            nPai1 = paiNum - 1;
            nPai2 = paiNum + 1;
            list<Mj>::iterator iter = handMjs.begin();

            while(iter != handMjs.end()){
                if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                    mj1 = *iter;
                    mj1.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt1++;
                }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                    mj2 = *iter;
                    mj2.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt2++;
                }else {
                    iter++;
                }
            }

            handMjs.push_front(mj1);

            iter = handMjs.begin();
            iter++;
            iter++;
            handMjs.insert(iter, mj2);
        }else if(type == 1){//+1.+2

            cnt1 = 0;
            cnt2 = 0;

            nPai1 = paiNum + 1;
            nPai2 = paiNum + 2;
            list<Mj>::iterator iter = handMjs.begin();

            while(iter != handMjs.end()){
                if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                    mj1 = *iter;
                    mj1.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt1++;
                }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                    mj2 = *iter;
                    mj2.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt2++;
                }else {
                    iter++;
                }
            }

            iter = handMjs.begin();
            iter++;
            handMjs.insert(iter, mj1);
            handMjs.insert(iter, mj2);


        }else if(type == 2){//-1,-2
            cnt1 = 0;
            cnt2 = 0;

            nPai1 = paiNum - 1;
            nPai2 = paiNum - 2;
            list<Mj>::iterator iter = handMjs.begin();

            while(iter != handMjs.end()){
                if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                    mj1 = *iter;
                    mj1.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt1++;
                }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                    mj2 = *iter;
                    mj2.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt2++;
                }else {
                    iter++;
                }
            }

            handMjs.push_front(mj1);
            handMjs.push_front(mj2);
        }
    }

}
//吃牌操作
void UIMainWindows::chowOperating(std::list<Mj> &handMjs)
{
    //把吃的牌放入牌首
    handMjs.push_front(*(playedPai.begin()));
    handMjs.begin()->setPaizhuangtai(4);

    //清空吃碰杠状态
    clearHandStatus();

    if(chowType.size() == 1){
        int type = *chowType.begin();
        int nPai1, nPai2;//自己牌中吃的牌
        int cnt1, cnt2;//只记录第一个组合可以吃的牌
        int paiNum = playedPai.begin()->getResult();//吃的牌
        Mj mj1, mj2;//插入的两个麻将

        if(type == 0){//-1,+1
            cnt1 = 0;
            cnt2 = 0;

            nPai1 = paiNum - 1;
            nPai2 = paiNum + 1;
            list<Mj>::iterator iter = handMjs.begin();

            while(iter != handMjs.end()){
                if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                    mj1 = *iter;
                    mj1.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt1++;
                }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                    mj2 = *iter;
                    mj2.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt2++;
                }else {
                    iter++;
                }
            }

            handMjs.push_front(mj1);

            iter = handMjs.begin();
            iter++;
            iter++;
            handMjs.insert(iter, mj2);
        }else if(type == 1){//+1.+2

            cnt1 = 0;
            cnt2 = 0;

            nPai1 = paiNum + 1;
            nPai2 = paiNum + 2;
            list<Mj>::iterator iter = handMjs.begin();

            while(iter != handMjs.end()){
                if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                    mj1 = *iter;
                    mj1.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt1++;
                }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                    mj2 = *iter;
                    mj2.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt2++;
                }else {
                    iter++;
                }
            }

            iter = handMjs.begin();
            iter++;
            handMjs.insert(iter, mj1);
            handMjs.insert(iter, mj2);


        }else if(type == 2){//-1,-2
            cnt1 = 0;
            cnt2 = 0;

            nPai1 = paiNum - 1;
            nPai2 = paiNum - 2;
            list<Mj>::iterator iter = handMjs.begin();

            while(iter != handMjs.end()){
                if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                    mj1 = *iter;
                    mj1.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt1++;
                }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                    mj2 = *iter;
                    mj2.setPaizhuangtai(4);
                    iter = handMjs.erase(iter);

                    cnt2++;
                }else {
                    iter++;
                }
            }

            handMjs.push_front(mj1);
            handMjs.push_front(mj2);
        }
    }else{//多个吃组合， 记录吃组合的第一张牌
         chowVec.clear();

         int nPai;//自己牌中吃的牌
         int paiNum = playedPai.begin()->getResult();//吃的牌
          Mj mj1;//插入的两个麻将

         for(auto i:chowType){
             list<Mj>::iterator iter = handMjs.begin();
             iter++;

             if(i == 0){//-1,+1
                  nPai = paiNum - 1;
                 while(iter != handMjs.end()){
                     if(iter->getResult() == nPai && iter->getPaizhuangtai() == 0){
                         chowVec.push_back(*iter);

                     }
                     iter++;
                 }
             }else if(i == 1){//+1，+2
                 nPai = paiNum + 1;
                while(iter != handMjs.end()){
                    if(iter->getResult() == nPai && iter->getPaizhuangtai() == 0){
                        chowVec.push_back(*iter);

                    }
                    iter++;
                }

             }else if(i == 2){//-1，-2
                 nPai = paiNum - 2;
                while(iter != handMjs.end()){
                    if(iter->getResult() == nPai && iter->getPaizhuangtai() == 0){
                        chowVec.push_back(*iter);

                    }
                    iter++;
                }
             }
         }
    }//else
}
//两种可能吃法下的吃牌操作
void UIMainWindows::chowOperating2(std::list<Mj> &handMjs, int type)
{

    int nPai1, nPai2;//自己牌中吃的牌
    int cnt1, cnt2;//只记录第一个组合可以吃的牌
    int paiNum = playedPai.begin()->getResult();//吃的牌
    Mj mj1, mj2;//插入的两个麻将

    if(type == 0){//-1，+1
        cnt1 = 0;
        cnt2 = 0;

        nPai1 = paiNum - 1;
        nPai2 = paiNum + 1;
        list<Mj>::iterator iter = handMjs.begin();

        while(iter != handMjs.end()){
            if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                mj1 = *iter;
                mj1.setPaizhuangtai(4);
                iter = handMjs.erase(iter);

                cnt1++;
            }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                mj2 = *iter;
                mj2.setPaizhuangtai(4);
                iter = handMjs.erase(iter);

                cnt2++;
            }else {
                iter++;
            }
        }

        handMjs.push_front(mj1);

        iter = handMjs.begin();
        iter++;
        iter++;
        handMjs.insert(iter, mj2);
    }else if(type == 1){//+1，+2

        cnt1 = 0;
        cnt2 = 0;

        nPai1 = paiNum + 1;
        nPai2 = paiNum + 2;

        list<Mj>::iterator iter = handMjs.begin();

        while(iter != handMjs.end()){
            if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                mj1 = *iter;
                mj1.setPaizhuangtai(4);
                iter = handMjs.erase(iter);

                cnt1++;
            }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                mj2 = *iter;
                mj2.setPaizhuangtai(4);
                iter = handMjs.erase(iter);

                cnt2++;
            }else {
                iter++;
            }
        }

        iter = handMjs.begin();
        iter++;
        handMjs.insert(iter,mj1);

        handMjs.insert(iter, mj2);


    }else if(type == 2){
        cnt1 = 0;
        cnt2 = 0;

        nPai1 = paiNum - 1;
        nPai2 = paiNum - 2;
        list<Mj>::iterator iter = handMjs.begin();

        while(iter != handMjs.end()){
            if(iter->getResult() == nPai1 && cnt1 == 0 && iter->getPaizhuangtai() == 0){
                mj1 = *iter;
                mj1.setPaizhuangtai(4);
                iter = handMjs.erase(iter);

                cnt1++;
            }else if(iter->getResult() == nPai2 && cnt2 == 0 && iter->getPaizhuangtai() == 0){
                mj2 = *iter;
                mj2.setPaizhuangtai(4);
                iter = handMjs.erase(iter);

                cnt2++;
            }else {
                iter++;
            }
        }

        handMjs.push_front(mj1);
        handMjs.push_front(mj2);
    }
}
//判断是否存在碰牌操作，如有设置相关状态
void UIMainWindows::isPong()
{
    isSouthPong = false;
    isNorthPong = false;
    isEastPong = false;
    isWestPong = false;

    int cnt = 0;

    int paiValue = playedPai.begin()->getResult();//获得当前牌的数字

    if(dapaiWanjia == 0){//南
        if(systemConfig.queyimen == 1 && eastQue < paiValue && paiValue < eastQue + 10){

        }else{
            for(auto i:handEastMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                    cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isEastPong  = true;
                return;
            }
        }

        cnt = 0;
        if(systemConfig.queyimen == 1 && northQue < paiValue && paiValue < northQue + 10){

        }else{
            for(auto i:handNorthMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isNorthPong = true;
                return;
            }
        }


        cnt = 0;
        if(systemConfig.queyimen == 1 && westQue < paiValue && paiValue < westQue + 10){

        }else{
            for(auto i:handWestMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isWestPong = true;
                return;
            }
        }


    }else if(dapaiWanjia == 1){
        if(systemConfig.queyimen == 1 && northQue < paiValue && paiValue < northQue + 10){

        }else{
            for(auto i:handNorthMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isNorthPong = true;
                return;
            }
        }

        cnt = 0;
        if(systemConfig.queyimen == 1 && westQue < paiValue && paiValue < westQue + 10){

        }else{
            for(auto i:handWestMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isWestPong = true;
                return;
            }
        }

        cnt = 0;
        if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

        }else{
            for(auto i:handSouthMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                    cnt++;
                }
            }

            if(cnt == 2 || cnt == 3){
                isSouthPong = true;
                return;
            }
        }

    }else if(dapaiWanjia == 2){
        if(systemConfig.queyimen == 1 && westQue < paiValue && paiValue < westQue + 10){

        }else{
            for(auto i:handWestMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isWestPong = true;
                return;
            }
        }

        cnt = 0;
        if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

        }else{
            for(auto i:handSouthMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                    cnt++;
                }
            }

            if(cnt == 2 || cnt == 3){
                isSouthPong = true;
                return;
            }
        }

        cnt = 0;
        for(auto i:handEastMjs){
            if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
               cnt++;
            }
        }

        if(cnt == 2 || cnt == 3){
            isEastPong = true;
            return;
        }



    }else if(dapaiWanjia == 3){
        if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

        }else{
            for(auto i:handSouthMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                    cnt++;
                }
            }

            if(cnt == 2 || cnt == 3){
                isSouthPong = true;
                return;
            }
        }

        cnt = 0;
        if(systemConfig.queyimen == 1 && eastQue < paiValue && paiValue < eastQue + 10){

        }else{
            for(auto i:handEastMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                    cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isEastPong  = true;
                return;
            }
        }

        cnt = 0;
        if(systemConfig.queyimen == 1 && northQue < paiValue && paiValue < northQue + 10){

        }else{
            for(auto i:handNorthMjs){
                if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
                }
            }
            if(cnt == 2 || cnt == 3){
                isNorthPong = true;
                return;
            }
        }
    }

}
//碰操作
void UIMainWindows::pongOperating(std::list<Mj> &handMjs)
{
    //把碰的牌放入牌首
    handMjs.push_front(*(playedPai.begin()));
    handMjs.begin()->setPaizhuangtai(1);

    //把牌中组成碰的牌放到牌首
    Mj tempMj;
    list<Mj>::iterator iter =  handMjs.begin();
    iter++;
    int cnt = 0;

    while(iter != handMjs.end()){
        if(iter->getResult() == playedPai.begin()->getResult()){
            tempMj = *iter;
            tempMj.setPaizhuangtai(1);

            iter =  handMjs.erase(iter);
            handMjs.push_front(tempMj);

            cnt++;

        }else{
            iter++;
        }
        if(cnt == 2){
            break;
        }
    }

    //从弃牌堆拿走被碰的牌
    for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
        if(iter->getId() == playedPai.begin()->getId()){
            discardMjs.erase(iter);
            break;
        }
    }
    discardDisplay(discardMjs);


    if(isSouthPong == true){//南碰
        handSouthIndex += 3;

        //重置碰标志
        isSouthPong = false;

        isSouthChow = false;//CRay 如碰了，所有玩家都不可能还有吃牌的状态
        isEastChow =false;
        isNorthChow =false;
        isWestChow =false;

        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 0;
        updateMopaiWanjia();


        //展示手牌
        southHandDisplay(handSouthMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //变更打牌玩家
         dapaiWanjia = 0;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);
    }else if(isEastPong == true){//东碰
        handEastIndex += 3;

        //重置碰标志
        isEastPong = false;
        isEastChow = false;
        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
       mopaiWanjia = 1;
       updateMopaiWanjia();


        //展示手牌
        eastHandDisplay(handEastMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //变更打牌玩家
        dapaiWanjia = 1;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);

    }else if(isNorthPong == true){//北碰

        handNorthIndex += 3;

        //重置碰标志
        isNorthPong = false;

        isSouthChow = false;//CRay 如碰了，所有玩家都不可能还有吃牌的状态
        isEastChow =false;
        isNorthChow =false;
        isWestChow =false;

        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 2;
        updateMopaiWanjia();

        //展示手牌
        northHandDisplay(handNorthMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //变更打牌玩家
         dapaiWanjia = 2;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);
    }else if(isWestPong == true){//西碰
        handWestIndex += 3;

        //重置碰标志
        isWestPong = false;

        isSouthChow = false;//CRay 如碰了，所有玩家都不可能还有吃牌的状态
        isEastChow =false;
        isNorthChow =false;
        isWestChow =false;

        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 3;
        updateMopaiWanjia();

        //展示手牌
        westHandDisplay(handWestMjs);

        //预测
        yuceDirection  = mopaiDirection;
        yucePos = mopaiPos;
        yuceCeng = mopaiCeng;
        //预测牌
        yucePai();

        //变更打牌玩家
        dapaiWanjia = 3;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);
    }
}
//如存在可碰的操作，在对应牌上显示箭头
int UIMainWindows::isPong2(int direction, int paiNum)
{
     int paiCnt = 1;
    if(direction == 0){
        if(systemConfig.queyimen == 1){
            if(paiNum < eastQue || paiNum > eastQue){
                for(auto i:handEastMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 1;
                }
            }
        }else{
            for(auto i:handEastMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 1;
            }
        }


        paiCnt = 1;
        if(systemConfig.queyimen == 1){
            if(paiNum < northQue || paiNum > northQue){
                for(auto i:handNorthMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 2;
                }
            }
        }else{
            for(auto i:handNorthMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 2;
            }
        }

        paiCnt = 1;
        if(systemConfig.queyimen == 1){
            if(paiNum < westQue || paiNum > westQue){
                for(auto i:handWestMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 3;
                }
            }
        }else{
            for(auto i:handWestMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 3;
            }
        }

    }else if(direction == 1){
        if(systemConfig.queyimen == 1){
            if(paiNum < northQue || paiNum > northQue){
                for(auto i:handNorthMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 2;
                }
            }
        }else{
            for(auto i:handNorthMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 2;
            }
        }

        paiCnt = 1;
        if(systemConfig.queyimen == 1){
            if(paiNum < westQue || paiNum > westQue){
                for(auto i:handWestMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 3;
                }
            }
        }else{
            for(auto i:handWestMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 3;
            }
        }


        paiCnt = 1;
        if(systemConfig.queyimen == 1){
             if(paiNum < southQue || paiNum > southQue){
                 for(auto i:handSouthMjs){
                     if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                         paiCnt++;
                     }
                 }
                 if(paiCnt >= 3){
                     return 0;
                 }
             }
        }else{
            for(auto i:handSouthMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 0;
            }
        }

    }else if(direction == 2){
        if(systemConfig.queyimen == 1){
            if(paiNum < westQue || paiNum > westQue){
                for(auto i:handWestMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 3;
                }
            }
        }else{
            for(auto i:handWestMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 3;
            }
        }

        paiCnt = 1;
        if(systemConfig.queyimen == 1){
             if(paiNum < southQue || paiNum > southQue){
                 for(auto i:handSouthMjs){
                     if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                         paiCnt++;
                     }
                 }
                 if(paiCnt >= 3){
                     return 0;
                 }
             }
        }else{
            for(auto i:handSouthMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 0;
            }
        }

        paiCnt = 1;
        if(systemConfig.queyimen == 1){
            if(paiNum < eastQue || paiNum > eastQue){
                for(auto i:handEastMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 1;
                }
            }
        }else{
            for(auto i:handEastMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 1;
            }
        }
    }else if(direction == 3){
        if(systemConfig.queyimen == 1){
             if(paiNum < southQue || paiNum > southQue){
                 for(auto i:handSouthMjs){
                     if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                         paiCnt++;
                     }
                 }
                 if(paiCnt >= 3){
                     return 0;
                 }
             }
        }else{
            for(auto i:handSouthMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 0;
            }
        }

        paiCnt = 1;
        if(systemConfig.queyimen == 1){
            if(paiNum < eastQue || paiNum > eastQue){
                for(auto i:handEastMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 1;
                }
            }
        }else{
            for(auto i:handEastMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 1;
            }
        }

        paiCnt = 1;
        if(systemConfig.queyimen == 1){
            if(paiNum < northQue || paiNum > northQue){
                for(auto i:handNorthMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt >= 3){
                    return 2;
                }
            }
        }else{
            for(auto i:handNorthMjs){
                if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                    paiCnt++;
                }
            }
            if(paiCnt >= 3){
                return 2;
            }
        }
    }
    return -1;
}
//明杠判断
void UIMainWindows::isKong()
{
   isSouthKong = false;
   isWestKong = false;
   isNorthKong = false;
   isEastKong = false;

   int paiValue = playedPai.begin()->getResult();//获得当前牌的数字

    //明杠
   int cnt = 0;
   if(dapaiWanjia == 0){//南

       if(systemConfig.queyimen == 1 && eastQue < paiValue && paiValue < eastQue + 10){

       }else{
           for(auto i:handEastMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }
           if(cnt == 3){
               isEastKong  = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && northQue < paiValue && paiValue < northQue + 10){

       }else{
           for(auto i:handNorthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                  cnt++;
               }
           }
           if(cnt == 3){
               isNorthKong = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && westQue < paiValue && paiValue < westQue + 10){

       }else{
           for(auto i:handWestMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                  cnt++;
               }
           }
           if(cnt == 3){
               isWestKong = true;
               return;
           }
       }

       //南
       if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }

           if(cnt == 3){
               isSouthKong = true;
               return;
           }
       }

   }else if(dapaiWanjia == 1){
       if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }

           if(cnt == 3){
               isSouthKong = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && northQue < paiValue && paiValue < northQue + 10){

       }else{
           for(auto i:handNorthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                  cnt++;
               }
           }
           if(cnt == 3){
               isNorthKong = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && westQue < paiValue && paiValue < westQue + 10){

       }else{
           for(auto i:handWestMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                  cnt++;
               }
           }
           if(cnt == 3){
               isWestKong = true;
               return;
           }
       }

   }else if(dapaiWanjia == 2){
       if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }

           if(cnt == 3){
               isSouthKong = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && eastQue < paiValue && paiValue < eastQue + 10){

       }else{
           for(auto i:handEastMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }
           if(cnt == 3){
               isEastKong  = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && westQue < paiValue && paiValue < westQue + 10){

       }else{
           for(auto i:handWestMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                  cnt++;
               }
           }
           if(cnt == 3){
               isWestKong = true;
               return;
           }
       }
   }else if(dapaiWanjia == 3){
       if(systemConfig.queyimen == 1 && southQue < paiValue && paiValue < southQue + 10){

       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }

           if(cnt == 3){
               isSouthKong = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && eastQue < paiValue && paiValue < eastQue + 10){

       }else{
           for(auto i:handEastMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                   cnt++;
               }
           }
           if(cnt == 3){
               isEastKong  = true;
               return;
           }
       }

       cnt = 0;
       if(systemConfig.queyimen == 1 && northQue < paiValue && paiValue < northQue + 10){

       }else{
           for(auto i:handNorthMjs){
               if(i.getResult() == paiValue && i.getPaizhuangtai() == 0){
                  cnt++;
               }
           }
           if(cnt == 3){
               isNorthKong = true;
               return;
           }
       }
   }
}
//如存在可杠的操作，在对应牌上显示箭头
int UIMainWindows::isKong2(int direction, int paiNum)
{
    int paiCnt = 1;
   if(direction == 0){
       if(systemConfig.queyimen == 1){
           if(paiNum < eastQue || paiNum > eastQue){
               for(auto i:handEastMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 1;
               }
           }
       }else{
           for(auto i:handEastMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 1;
           }
       }


       paiCnt = 1;
       if(systemConfig.queyimen == 1){
           if(paiNum < northQue || paiNum > northQue){
               for(auto i:handNorthMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 2;
               }
           }
       }else{
           for(auto i:handNorthMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 2;
           }
       }

       paiCnt = 1;
       if(systemConfig.queyimen == 1){
           if(paiNum < westQue || paiNum > westQue){
               for(auto i:handWestMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 3;
               }
           }
       }else{
           for(auto i:handWestMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 3;
           }
       }

   }else if(direction == 1){
       if(systemConfig.queyimen == 1){
           if(paiNum < northQue || paiNum > northQue){
               for(auto i:handNorthMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 2;
               }
           }
       }else{
           for(auto i:handNorthMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 2;
           }
       }

       paiCnt = 1;
       if(systemConfig.queyimen == 1){
           if(paiNum < westQue || paiNum > westQue){
               for(auto i:handWestMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 3;
               }
           }
       }else{
           for(auto i:handWestMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 3;
           }
       }


       paiCnt = 1;
       if(systemConfig.queyimen == 1){
            if(paiNum < southQue || paiNum > southQue){
                for(auto i:handSouthMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt == 4){
                    return 0;
                }
            }
       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
            if(paiCnt == 4){
               return 0;
           }
       }

   }else if(direction == 2){
       if(systemConfig.queyimen == 1){
           if(paiNum < westQue || paiNum > westQue){
               for(auto i:handWestMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 3;
               }
           }
       }else{
           for(auto i:handWestMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 3;
           }
       }

       paiCnt = 1;
       if(systemConfig.queyimen == 1){
            if(paiNum < southQue || paiNum > southQue){
                for(auto i:handSouthMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt == 4){
                    return 0;
                }
            }
       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 0;
           }
       }

       paiCnt = 1;
       if(systemConfig.queyimen == 1){
           if(paiNum < eastQue || paiNum > eastQue){
               for(auto i:handEastMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 1;
               }
           }
       }else{
           for(auto i:handEastMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 1;
           }
       }
   }else if(direction == 3){
       if(systemConfig.queyimen == 1){
            if(paiNum < southQue || paiNum > southQue){
                for(auto i:handSouthMjs){
                    if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                        paiCnt++;
                    }
                }
                if(paiCnt == 4){
                    return 0;
                }
            }
       }else{
           for(auto i:handSouthMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 0;
           }
       }

       paiCnt = 1;
       if(systemConfig.queyimen == 1){
           if(paiNum < eastQue || paiNum > eastQue){
               for(auto i:handEastMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 1;
               }
           }
       }else{
           for(auto i:handEastMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 1;
           }
       }

       paiCnt = 1;
       if(systemConfig.queyimen == 1){
           if(paiNum < northQue || paiNum > northQue){
               for(auto i:handNorthMjs){
                   if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                       paiCnt++;
                   }
               }
               if(paiCnt == 4){
                   return 2;
               }
           }
       }else{
           for(auto i:handNorthMjs){
               if(i.getResult() == paiNum && i.getPaizhuangtai() == 0){
                   paiCnt++;
               }
           }
           if(paiCnt == 4){
               return 2;
           }
       }
   }
   return -1;
}
//暗杠判断
void UIMainWindows::isConcealedKong(std::list<Mj> handMjs,int wanjia)
{
    //清空之前的数据
    concealedKongNum[0] = 0;
    concealedKongNum[1] = 0;
    concealedKongNum[2] = 0;
    concealedKongNum[3] = 0;

    concealedKongElement[0].clear();
    concealedKongElement[1].clear();
    concealedKongElement[2].clear();
    concealedKongElement[3].clear();

    concealedKongType[0].clear();
    concealedKongType[1].clear();
    concealedKongType[2].clear();
    concealedKongType[3].clear();

    //抢杠胡
    qiangganghuElement[0].clear();
    qiangganghuElement[1].clear();
    qiangganghuElement[2].clear();
    qiangganghuElement[3].clear();

    int cnt = 0;
    int PongNum = 0;
    for(list<Mj>::iterator i = handMjs.begin();i != handMjs.end();i++){
       int iResult = i->getResult();

        if(i->getPaizhuangtai() == 0){//4个暗杠都是手牌            
            if(systemConfig.queyimen == 1){//判断缺一门
                if(wanjia == 0 && i->getResult() > southQue && i->getResult() < southQue + 10){
                    continue;
                }else if(wanjia == 1 && i->getResult() > eastQue && i->getResult() < eastQue + 10){
                    continue;
                }else if(wanjia == 2 && i->getResult() > northQue && i->getResult() < northQue + 10){
                    continue;
                }else if(wanjia == 3 && i->getResult() > westQue && i->getResult() < westQue + 10){
                    continue;
                }
            }

            cnt = 0;
            list<Mj>::iterator tempI = i;
            tempI++;
            for(list<Mj>::iterator j = tempI;j != handMjs.end();j++){
                int paiNum = j->getResult();//暂时记录牌数字
                if(i->getResult() == j->getResult()){
                    cnt++;
                }



                if(cnt == 3){
                    if(wanjia == 0){
                        concealedKongNum[0]++;
                        concealedKongElement[0].push_back(paiNum);
                        concealedKongType[0].push_back(0);

                    }else if(wanjia == 1){
                        concealedKongNum[1]++;
                        concealedKongElement[1].push_back(paiNum);
                        concealedKongType[1].push_back(0);

                    }else if(wanjia == 2){
                       concealedKongNum[2]++;
                       concealedKongElement[2].push_back(paiNum);
                       concealedKongType[2].push_back(0);

                    }else if(wanjia == 3){
                       concealedKongNum[3]++;
                       concealedKongElement[3].push_back(paiNum);
                       concealedKongType[3].push_back(0);

                    }
                    break;
                }

            }
        }else if(i->getPaizhuangtai() == 1 && systemConfig.gangshouzhongpai == 1){//3个碰牌，一个手牌
            if(PongNum == i->getResult()){//过滤相同的杠牌
                continue;
            }else{
               PongNum = i->getResult();
            }

            cnt = 0;
            list<Mj>::iterator tempI = i;
            tempI++;

            for(list<Mj>::iterator j = ++tempI;j != handMjs.end();j++){
                int paiNum = j->getResult();//暂时记录牌数字

                if(j->getPaizhuangtai() == 0 && i->getResult() == j->getResult()){
                    if(wanjia == 0){
                        concealedKongNum[0]++;
                        concealedKongElement[0].push_back(paiNum);
                        concealedKongType[0].push_back(1);

                        qiangganghuElement[0].push_back(paiNum);
                    }else if(wanjia == 1){
                        concealedKongNum[1]++;
                        concealedKongElement[1].push_back(paiNum);
                        concealedKongType[1].push_back(1);

                        qiangganghuElement[1].push_back(paiNum);
                    }else if(wanjia == 2){
                       concealedKongNum[2]++;
                       concealedKongElement[2].push_back(paiNum);
                       concealedKongType[2].push_back(1);

                       qiangganghuElement[2].push_back(paiNum);
                    }else if(wanjia == 3){
                       concealedKongNum[3]++;
                       concealedKongElement[3].push_back(paiNum);
                       concealedKongType[3].push_back(1);

                       qiangganghuElement[3].push_back(paiNum);
                    }
                    break;
                }

            }
        }//else if
    }

}
//明杠操作
void UIMainWindows::kongOperating(std::list<Mj> &handMjs)
{
    //把杠的牌放入牌首
    handMjs.push_front(*(playedPai.begin()));
    handMjs.begin()->setPaizhuangtai(2);

    qDebug()<<"gangpai:"<<playedPai.begin()->getResult();

    //把牌中组成碰的牌放到牌首
    Mj tempMj;
    list<Mj>::iterator iter =  handMjs.begin();
    iter++;
    int cnt = 0;
    while(iter != handMjs.end()){
        if(iter->getResult() == playedPai.begin()->getResult()){
            tempMj = *iter;
            tempMj.setPaizhuangtai(2);

            iter =  handMjs.erase(iter);
            handMjs.push_front(tempMj);

            cnt++;
        }else{
            iter++;
        }
        if(cnt == 3){
            break;
        }
    }

    //从弃牌堆拿走被杠的牌
    for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
        if(iter->getId() == playedPai.begin()->getId()){
            discardMjs.erase(iter);
            break;
        }
    }
    discardDisplay(discardMjs);


    if(isSouthKong == true){//南杠
        handSouthIndex += 4;

        //重置碰标志
        isSouthKong = false;
        isSouthPong=false;//AI模式下有限杠牌，只要杠了，就不可能还能碰

        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 0;
        //摸牌

        draw();//已经包含手牌展示

        //预测牌
        yucePai();

        //变更打牌玩家
         dapaiWanjia = 0;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);
    }else if(isEastKong == true){
        handEastIndex += 4;

        //重置杠标志
        isEastKong = false;
        isEastPong=false;

        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 1;

        //摸牌
        draw();//已经包含手牌展示

        //预测牌
        yucePai();

        //变更打牌玩家
         dapaiWanjia = 1;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);

    }else if(isNorthKong == true){
        handNorthIndex += 4;

        //重置杠标志
        isNorthKong = false;
        isNorthPong=false;

        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 2;
        //摸牌
        draw();//已经包含手牌展示

        //预测牌
        yucePai();

        //变更打牌玩家
        dapaiWanjia = 2;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);
    }else if(isWestKong == true){
        handWestIndex += 4;

        //重置杠标志
        isWestKong = false;
        isWestPong=false;
        //清空吃碰杠状态
        clearHandStatus();

        //更新摸牌玩家
        mopaiWanjia = 3;
        //摸牌
        draw();//已经包含手牌展示

        //预测牌
        yucePai();

        //变更打牌玩家
       dapaiWanjia = 3;
        //展示当前打牌位置
        directionDisplay(dapaiWanjia);
    }


}
//暗杠操作
void UIMainWindows::kongOperating2(std::list<Mj> &handMjs)
{
    //重置抢杠胡数据
    isQiangganghu = false;
    qiangganghuType = -1;
    qiangganghuPaiNum = 0;
    bool ispongflag = false;//如已是碰牌，index位置只加1
    int paiNum;
    pair<int, int> kongPair;//撤回记录的暗杠牌以及类型

    if(dapaiWanjia == 0){
        concealedKongNum[0]--;
        paiNum = *(concealedKongElement[0].begin());
        kongPair.first = paiNum;
        kongPair.second = *(concealedKongType[0].begin());
        southKongStack.push(kongPair);//把暗杠牌加入栈
        concealedKongElement[0].pop_back();
        concealedKongType[0].pop_back();
        if(qiangganghuElement[0].size() != 0){
            if(paiNum == *(qiangganghuElement[0].begin())){
                isQiangganghu = true;
            }
        }

    }else if(dapaiWanjia == 1){
        concealedKongNum[1]--;
        paiNum = *(concealedKongElement[1].begin());

        kongPair.first = paiNum;
        kongPair.second = *(concealedKongType[1].begin());
        eastKongStack.push(kongPair);//把暗杠牌加入栈

        concealedKongElement[1].pop_back();
        concealedKongType[1].pop_back();

        if(qiangganghuElement[1].size() != 0){
            if(paiNum == *(qiangganghuElement[1].begin())){
                isQiangganghu = true;
            }
        }

    }else if(dapaiWanjia == 2){
        concealedKongNum[2]--;
        paiNum = *(concealedKongElement[2].begin());
        kongPair.first = paiNum;
        kongPair.second = *(concealedKongType[2].begin());
        northKongStack.push(kongPair);//把暗杠牌加入栈
        concealedKongElement[2].pop_back();
        concealedKongType[2].pop_back();
        if(qiangganghuElement[2].size() != 0){
            if(paiNum == *(qiangganghuElement[2].begin())){
                isQiangganghu = true;
            }
        }
    }else if(dapaiWanjia == 3){
        concealedKongNum[3]--;
        paiNum = *(concealedKongElement[3].begin());

        kongPair.first = paiNum;
        kongPair.second = *(concealedKongType[2].begin());
        westKongStack.push(kongPair);//把暗杠牌加入栈


        concealedKongElement[3].pop_back();
        concealedKongType[3].pop_back();

        if(qiangganghuElement[3].size() != 0){
            if(paiNum == *(qiangganghuElement[3].begin())){
                isQiangganghu = true;
            }
        }
    }
    //检测抢杠胡
   if(systemConfig.qiangganghu == 1 & isQiangganghu == true){
        isWin3(paiNum);
   }
   if(systemConfig.qiangganghu == 1 & isQiangganghu == true && (isSouthWin == true || isEastWin == true || isNorthWin == true || isWestWin == true)){
        qiangganghuType = 0;
        qiangganghuPaiNum = paiNum;

   }else{
       //把牌中组成杠的牌放到牌首
       Mj tempMj;
       list<Mj>::iterator iter = handMjs.begin();
       int cnt = 0;
       while(iter != handMjs.end()){
           if(iter->getResult() == paiNum){
               tempMj = *iter;
               if (tempMj.getPaizhuangtai() == 1)
                   ispongflag=true;

               tempMj.setPaizhuangtai(2);

               iter =  handMjs.erase(iter);
               handMjs.push_front(tempMj);

               cnt++;
           }else{
               iter++;
           }
           if(cnt == 4){
               break;
           }
       }

       //清空吃碰杠状态
       clearHandStatus();
       if(dapaiWanjia == 0){
           //更新摸牌玩家
           mopaiWanjia = 0;

           //摸牌
           draw();//包含手牌展示
           //预测牌
           yucePai();
           //变更打牌玩家
           dapaiWanjia = 0;
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);
           //如果已经碰过，+1，否则+4
           if (ispongflag)
               handSouthIndex += 1;
           else
               handSouthIndex += 4;
       }else if(dapaiWanjia == 1){
           //更新摸牌玩家
          mopaiWanjia = 1;
           //摸牌
           draw();//包含手牌展示

           //预测牌
           yucePai();

           //变更打牌玩家
           dapaiWanjia = 1;
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);
           if (ispongflag)
                handEastIndex += 1;
           else
                handEastIndex += 4;
       }else if(dapaiWanjia == 2){
           //更新摸牌玩家
           mopaiWanjia = 2;
           //摸牌
           draw();//包含手牌展示

           //预测牌
           yucePai();

           //变更打牌玩家
           dapaiWanjia = 2;
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);
           if (ispongflag)
               handNorthIndex += 1;
           else
               handNorthIndex += 4;
       }else if(dapaiWanjia == 3){
           //更新摸牌玩家
          mopaiWanjia = 3;
           //摸牌
           draw();//包含手牌展示

           //预测牌
           yucePai();

           //变更打牌玩家
           dapaiWanjia = 3;
           //展示当前打牌位置
           directionDisplay(dapaiWanjia);
           if (ispongflag)
               handWestIndex += 1;
           else
               handWestIndex += 4;
       }

   }
}
//多个暗杠操作时，进行单个暗杠操作
void UIMainWindows::kongOperating3(std::list<Mj> &handMjs, int paiNum)
{
    //把牌中组成碰的牌放到牌首
    Mj tempMj;
    list<Mj>::iterator iter = handMjs.begin();
    int cnt = 0;
    pair<int, int> kongPair;//撤回记录的暗杠牌以及类型

    while(iter != handMjs.end()){
        if(iter->getResult() == paiNum){
            tempMj = *iter;
            tempMj.setPaizhuangtai(2);

            iter =  handMjs.erase(iter);
            handMjs.push_front(tempMj);

            cnt++;
        }else{
            iter++;
        }
        if(cnt == 4){
            break;
        }
    }

    if(dapaiWanjia == 0){
        isSouthConcealedKong = false;
        concealedKongNum[0]--;

        vector<int>::iterator kongIter = concealedKongType[0].begin();
        for(vector<int>::iterator iter = concealedKongElement[0].begin(); iter != concealedKongElement[0].end(); iter++){
            if(*iter == paiNum){
                kongPair.first = *iter;
                kongPair.second = *kongIter;
                southKongStack.push(kongPair);//把暗杠牌加入栈

                concealedKongElement[0].erase(iter);
                concealedKongType[0].erase(kongIter);

                break;
            }
            kongIter++;
         }

        //更新摸牌玩家
        mopaiWanjia = 0;
        //摸牌
        draw();//包含手牌展示
        directionDisplay(0);

        handSouthIndex += 4;
        //预测牌
        yucePai();

    }else if(dapaiWanjia == 1){
        isEastConcealedKong = false;
        concealedKongNum[1]--;

        vector<int>::iterator kongIter = concealedKongType[0].begin();
        for(vector<int>::iterator iter = concealedKongElement[1].begin(); iter != concealedKongElement[1].end(); iter++){
            if(*iter == paiNum){
                kongPair.first = *iter;
                kongPair.second = *kongIter;
                eastKongStack.push(kongPair);//把暗杠牌加入栈

                concealedKongElement[1].erase(iter);
                concealedKongType[1].erase(kongIter);
                break;
            }
            kongIter++;
         }

        //更新摸牌玩家
         mopaiWanjia = 1;
        //摸牌
        draw();//包含手牌展示
        directionDisplay(1);

         handEastIndex += 4;

        //预测牌
        yucePai();

    }else if(dapaiWanjia == 2){
        isNorthConcealedKong = false;
        concealedKongNum[2]--;

        vector<int>::iterator kongIter = concealedKongType[2].begin();
        for(vector<int>::iterator iter = concealedKongElement[2].begin(); iter != concealedKongElement[2].end(); iter++){
            if(*iter == paiNum){
                kongPair.first = *iter;
                kongPair.second = *kongIter;
                northKongStack.push(kongPair);//把暗杠牌加入栈

                concealedKongElement[2].erase(iter);
                concealedKongType[2].erase(kongIter);
                break;
            }
            kongIter++;
         }

        //更新摸牌玩家
        mopaiWanjia = 2;
        //摸牌
        draw();//包含手牌展示
        directionDisplay(2);
         handNorthIndex += 4;
        //预测牌
        yucePai();

    }else if(dapaiWanjia == 3){
        isWestConcealedKong = false;
        concealedKongNum[3]--;

         vector<int>::iterator kongIter = concealedKongType[3].begin();
        for(vector<int>::iterator iter = concealedKongElement[3].begin(); iter != concealedKongElement[3].end(); iter++){
            if(*iter == paiNum){
                kongPair.first = *iter;
                kongPair.second = *kongIter;
                westKongStack.push(kongPair);//把暗杠牌加入栈

                concealedKongElement[3].erase(iter);
                concealedKongType[3].erase(kongIter);
                break;
            }
         }

        //更新摸牌玩家
         mopaiWanjia = 3;
        //摸牌
        draw();//包含手牌展示

        directionDisplay(3);
        handWestIndex += 4;
        //预测牌
        yucePai();
    }
}
//自摸
void UIMainWindows::isWin()
{
    if(mopaiWanjia == 0){//南
        //检测胡牌
        if(HuPaiPanDin(handSouthMjs, -1, systemConfig) == true){
            isSouthWin = true;
            isZimo = true;
        }

        winDisplay();
    }else if(mopaiWanjia == 1){//东
        //检测胡牌
        if(HuPaiPanDin(handEastMjs, -1, systemConfig) == true){
            isEastWin = true;
            isZimo = true;
        }

        winDisplay();
    }else if(mopaiWanjia == 2){//北
        //检测胡牌
        if(HuPaiPanDin(handNorthMjs, -1, systemConfig) == true){
            isNorthWin = true;
            isZimo = true;
        }

        winDisplay();
    }else if(mopaiWanjia == 3){//西
        //检测胡牌
        if(HuPaiPanDin(handWestMjs, -1, systemConfig) == true){
            isWestWin = true;
            isZimo = true;
        }

        winDisplay();
    }

}
//放炮
void UIMainWindows::isWin2()
{
    list<Mj> handMjs;

    if(dapaiWanjia == 0){//南
        //东
        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > eastQue && playedPai.begin()->getResult() < eastQue + 10){

            }else{
                if(endWanjia.find(1) == endWanjia.end()){
                    handMjs = handEastMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    //检测胡牌
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastWin = true;
                    }
                }
            }
        }else{
            handMjs = handEastMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isEastWin = true;
            }
        }

        //北
        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > northQue && playedPai.begin()->getResult() < northQue + 10){

            }else{
                if(endWanjia.find(2) == endWanjia.end()){
                    handMjs = handNorthMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isNorthWin = true;
                    }
                }
            }
        }else{
            handMjs = handNorthMjs;
            handMjs.push_back(*(playedPai.begin()));
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isNorthWin = true;
            }
        }

        //西
        if(systemConfig.queyimen == 1){
            if( playedPai.begin()->getResult() > westQue && playedPai.begin()->getResult() < westQue + 10){

            }else{
                if(endWanjia.find(3) == endWanjia.end()){
                    handMjs = handWestMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isWestWin = true;
                    }
                }
            }
        }else{
            handMjs = handWestMjs;
            handMjs.push_back(*(playedPai.begin()));
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isWestWin = true;
            }
        }

        //南
        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > southQue && playedPai.begin()->getResult() < southQue + 10){

            }else{
               if(endWanjia.find(0) == endWanjia.end()){
                   handMjs = handSouthMjs;
                   handMjs.push_back(*(playedPai.begin()));
                   //检测胡牌
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isSouthWin = true;
                   }
               }
            }
        }else{
            handMjs = handSouthMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isSouthWin = true;
            }
        }


        winDisplay();
    }else if(dapaiWanjia == 1){//东
        //检测胡牌
        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > northQue && playedPai.begin()->getResult() < northQue + 10){

            }else{
                if(endWanjia.find(2) == endWanjia.end()){
                    handMjs = handNorthMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isNorthWin = true;
                    }
                }
            }
        }else{
            handMjs = handNorthMjs;
            handMjs.push_back(*(playedPai.begin()));
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isNorthWin = true;
            }
        }

        if(systemConfig.queyimen == 1){
            if( playedPai.begin()->getResult() > westQue && playedPai.begin()->getResult() < westQue + 10){

            }else{
                if(endWanjia.find(3) == endWanjia.end()){
                    handMjs = handWestMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isWestWin = true;
                    }
                }
            }
        }else{
            handMjs = handWestMjs;
            handMjs.push_back(*(playedPai.begin()));
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isWestWin = true;
            }
        }

        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > southQue && playedPai.begin()->getResult() < southQue + 10){

            }else{
               if(endWanjia.find(0) == endWanjia.end()){
                   handMjs = handSouthMjs;
                   handMjs.push_back(*(playedPai.begin()));
                   //检测胡牌
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isSouthWin = true;
                   }
               }
            }
        }else{
            handMjs = handSouthMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isSouthWin = true;
            }
        }

        winDisplay();
    }else if(dapaiWanjia == 2){//北
        //检测胡牌
        if(systemConfig.queyimen == 1){
            if( playedPai.begin()->getResult() > westQue && playedPai.begin()->getResult() < westQue + 10){

            }else{
                if(endWanjia.find(3) == endWanjia.end()){
                    handMjs = handWestMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isWestWin = true;
                    }
                }
            }
        }else{
            handMjs = handWestMjs;
            handMjs.push_back(*(playedPai.begin()));
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isWestWin = true;
            }
        }


        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > southQue && playedPai.begin()->getResult() < southQue + 10){

            }else{
               if(endWanjia.find(0) == endWanjia.end()){
                   handMjs = handSouthMjs;
                   handMjs.push_back(*(playedPai.begin()));
                   //检测胡牌
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isSouthWin = true;
                   }
               }
            }
        }else{
            handMjs = handSouthMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isSouthWin = true;
            }
        }


        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > eastQue && playedPai.begin()->getResult() < eastQue + 10){

            }else{
                if(endWanjia.find(1) == endWanjia.end()){
                    handMjs = handEastMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    //检测胡牌
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastWin = true;
                    }
                }
            }
        }else{
            handMjs = handEastMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isEastWin = true;
            }
        }


        winDisplay();
    }else if(dapaiWanjia == 3){//西
        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > southQue && playedPai.begin()->getResult() < southQue + 10){

            }else{
               if(endWanjia.find(0) == endWanjia.end()){
                   handMjs = handSouthMjs;
                   handMjs.push_back(*(playedPai.begin()));
                   //检测胡牌
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isSouthWin = true;
                   }
               }
            }
        }else{
            handMjs = handSouthMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isSouthWin = true;
            }
        }

        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > eastQue && playedPai.begin()->getResult() < eastQue + 10){

            }else{
                if(endWanjia.find(1) == endWanjia.end()){
                    handMjs = handEastMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    //检测胡牌
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastWin = true;
                    }
                }
            }
        }else{
            handMjs = handEastMjs;
            handMjs.push_back(*(playedPai.begin()));
            //检测胡牌
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isEastWin = true;
            }
        }


        if(systemConfig.queyimen == 1){
            if(playedPai.begin()->getResult() > northQue && playedPai.begin()->getResult() < northQue + 10){

            }else{
                if(endWanjia.find(2) == endWanjia.end()){
                    handMjs = handNorthMjs;
                    handMjs.push_back(*(playedPai.begin()));
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isNorthWin = true;
                    }
                }
            }
        }else{
            handMjs = handNorthMjs;
            handMjs.push_back(*(playedPai.begin()));
            if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                isNorthWin = true;
            }
        }

        winDisplay();
    }
}
//抢杠胡
void UIMainWindows::isWin3(int paiNum)
{
    list<Mj> handMjs;
    Mj mj;
    mj.setResult(paiNum);


    if(dapaiWanjia == 0){//南
        handMjs = handEastMjs;
        handMjs.push_back(mj);
        //检测胡牌
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isEastWin = true;
        }

        handMjs = handNorthMjs;
        handMjs.push_back(mj);
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isNorthWin = true;
        }

        handMjs = handWestMjs;
        handMjs.push_back(mj);
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isWestWin = true;
        }

        winDisplay();
    }else if(dapaiWanjia == 1){//东
        //检测胡牌
        handMjs = handNorthMjs;
        handMjs.push_back(mj);
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isNorthWin = true;
        }

        handMjs = handWestMjs;
        handMjs.push_back(mj);
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isWestWin = true;
        }

        handMjs = handSouthMjs;
        handMjs.push_back(mj);
        //检测胡牌
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isSouthWin = true;
        }

        winDisplay();
    }else if(dapaiWanjia == 2){//北
        //检测胡牌
        handMjs = handWestMjs;
        handMjs.push_back(mj);
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isWestWin = true;
        }

        handMjs = handSouthMjs;
        handMjs.push_back(mj);
        //检测胡牌
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isSouthWin = true;
        }

        handMjs = handEastMjs;
        handMjs.push_back(mj);
        //检测胡牌
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isEastWin = true;
        }

        winDisplay();
    }else if(dapaiWanjia == 3){//西
        //检测胡牌
        handMjs = handSouthMjs;
        handMjs.push_back(mj);
        //检测胡牌
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isSouthWin = true;
        }


        handMjs = handEastMjs;
        handMjs.push_back(mj);
        //检测胡牌
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isEastWin = true;
        }

        handMjs = handNorthMjs;
        handMjs.push_back(mj);
        if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
            isNorthWin = true;
        }

        winDisplay();
    }
}
//开局判胡
void UIMainWindows::isWin4()
{
    if(dapaiWanjia == 0){//南
        //检测胡牌
        if(HuPaiPanDin(handSouthMjs, -1, systemConfig) == true){
            isSouthWin = true;
            isZimo = true;
        }
        winDisplay();
    }else if(dapaiWanjia == 1){//东
        //检测胡牌
        if(HuPaiPanDin(handEastMjs, -1, systemConfig) == true){
            isEastWin = true;
            isZimo = true;
        }
        winDisplay();
    }else if(dapaiWanjia == 2){//北
        //检测胡牌
        if(HuPaiPanDin(handNorthMjs, -1, systemConfig) == true){
            isNorthWin = true;
            isZimo = true;
        }
        winDisplay();
    }else if(dapaiWanjia == 3){//西
        //检测胡牌
        if(HuPaiPanDin(handWestMjs, -1, systemConfig) == true){
            isWestWin = true;
            isZimo = true;
        }
        winDisplay();
    }

}
//听牌判断
void UIMainWindows::isReady()
{
    //清空数据
    isSouthReady = false;
    isEastReady = false;
    isNorthReady = false;
    isWestReady = false;

    readyElemnt[0].clear();
    readyElemnt[1].clear();
    readyElemnt[2].clear();
    readyElemnt[3].clear();

    southReadyHash.clear();
    eastReadyHash.clear();
    northReadyHash.clear();
    westReadyHash.clear();

    list<Mj> handMjs;
    list<Mj> tempReadyMjs;//暂存其他方向的手牌

    if(mopaiWanjia == 0){

            if(endWanjia.find(1) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

                tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }


            }

            if(endWanjia.find(2) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handNorthMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isNorthReady = true;

                        readyElemnt[2].push_back(iter->getResult());
                        northReadyHash[iter->getResult()]++;
                    }
                }

               tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }

            if(endWanjia.find(3) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handWestMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isWestReady = true;

                        readyElemnt[3].push_back(iter->getResult());
                        westReadyHash[iter->getResult()]++;
                    }
                }

                tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }

       readyDisplay();
    }else if(mopaiWanjia == 1){

            if(endWanjia.find(0) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handSouthMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isSouthReady = true;

                        readyElemnt[0].push_back(iter->getResult());
                        southReadyHash[iter->getResult()]++;
                    }
                }

                tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }

            if(endWanjia.find(2) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handNorthMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isNorthReady = true;

                        readyElemnt[2].push_back(iter->getResult());
                        northReadyHash[iter->getResult()]++;
                    }
                }

               tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }


            if(endWanjia.find(3) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handWestMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isWestReady = true;

                        readyElemnt[3].push_back(iter->getResult());
                        westReadyHash[iter->getResult()]++;
                    }
                }

                tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }


         readyDisplay();
    }else if(mopaiWanjia == 2){
           if(endWanjia.find(0) == endWanjia.end()){

               for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                   handMjs = handSouthMjs;
                   handMjs.push_back(*iter);
                   handMjs.sort(cmpHandMjs);
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isSouthReady = true;

                       readyElemnt[0].push_back(iter->getResult());
                       southReadyHash[iter->getResult()]++;
                   }
               }

               tempReadyMjs.clear();
               for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }
               for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }
               for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }

               for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                   handMjs = handEastMjs;
                   handMjs.push_back(*iter);
                   handMjs.sort(cmpHandMjs);
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isEastReady = true;

                       readyElemnt[1].push_back(iter->getResult());
                       eastReadyHash[iter->getResult()]++;
                   }
               }

           }


           if(endWanjia.find(1) == endWanjia.end()){

               for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                   handMjs = handEastMjs;
                   handMjs.push_back(*iter);
                   handMjs.sort(cmpHandMjs);
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isEastReady = true;

                       readyElemnt[1].push_back(iter->getResult());
                       eastReadyHash[iter->getResult()]++;
                   }
               }

               tempReadyMjs.clear();
               for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }
               for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }
               for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }

               for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                   handMjs = handEastMjs;
                   handMjs.push_back(*iter);
                   handMjs.sort(cmpHandMjs);
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isEastReady = true;

                       readyElemnt[1].push_back(iter->getResult());
                       eastReadyHash[iter->getResult()]++;
                   }
               }


           }


           if(endWanjia.find(3) == endWanjia.end()){

               for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                   handMjs = handWestMjs;
                   handMjs.push_back(*iter);
                   handMjs.sort(cmpHandMjs);
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isWestReady = true;

                       readyElemnt[3].push_back(iter->getResult());
                       westReadyHash[iter->getResult()]++;
                   }
               }

               tempReadyMjs.clear();
               for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }
               for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }
               for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                   if(iter->getPaizhuangtai() == 0){
                       tempReadyMjs.push_back(*iter);
                   }
               }

               for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                   handMjs = handEastMjs;
                   handMjs.push_back(*iter);
                   handMjs.sort(cmpHandMjs);
                   if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                       isEastReady = true;

                       readyElemnt[1].push_back(iter->getResult());
                       eastReadyHash[iter->getResult()]++;
                   }
               }

           }

         readyDisplay();
    }else if(mopaiWanjia == 3){

            if(endWanjia.find(0) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handSouthMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isSouthReady = true;

                        readyElemnt[0].push_back(iter->getResult());
                        southReadyHash[iter->getResult()]++;
                    }
                }

                tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }

            if(endWanjia.find(1) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

                tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handNorthMjs.begin();iter != handNorthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }


            }


            if(endWanjia.find(2) == endWanjia.end()){

                for(list<Mj>::iterator iter = majhongRemain.begin();iter != majhongRemain.end();iter++){
                    handMjs = handNorthMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isNorthReady = true;

                        readyElemnt[2].push_back(iter->getResult());
                        northReadyHash[iter->getResult()]++;
                    }
                }

               tempReadyMjs.clear();
                for(list<Mj>::iterator iter = handEastMjs.begin();iter != handEastMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handWestMjs.begin();iter != handWestMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }
                for(list<Mj>::iterator iter = handSouthMjs.begin();iter != handSouthMjs.end();iter++){
                    if(iter->getPaizhuangtai() == 0){
                        tempReadyMjs.push_back(*iter);
                    }
                }

                for(list<Mj>::iterator iter = tempReadyMjs.begin(); iter != tempReadyMjs.end();iter++){
                    handMjs = handEastMjs;
                    handMjs.push_back(*iter);
                    handMjs.sort(cmpHandMjs);
                    if(HuPaiPanDin(handMjs, -1, systemConfig) == true){
                        isEastReady = true;

                        readyElemnt[1].push_back(iter->getResult());
                        eastReadyHash[iter->getResult()]++;
                    }
                }

            }

         readyDisplay();
    }

}
//更新摸牌玩家
void UIMainWindows::updateMopaiWanjia()
{

    if(systemConfig.queyimen == 1){
        mopaiWanjia = (mopaiWanjia + 1) % 4;
        while(1){            
            unordered_set<int>::iterator iter = endWanjia.find(mopaiWanjia);
            if(iter != endWanjia.end()){
                 mopaiWanjia = (mopaiWanjia + 1) % 4;
            }else{
                break;
            }
        }
    }else{
        mopaiWanjia = (mopaiWanjia + 1) % 4;
    }

}
//更新打牌玩家
void UIMainWindows::updateDapaiWanjia()
{

    if(systemConfig.queyimen == 1){
        dapaiWanjia = (dapaiWanjia + 1) % 4;
        while(1){
            unordered_set<int>::iterator iter = endWanjia.find(dapaiWanjia);
            if(iter != endWanjia.end()){
                 dapaiWanjia = (dapaiWanjia + 1) % 4;
            }else{
                break;
            }
        }
    }else{
        dapaiWanjia = (dapaiWanjia + 1) % 4;
    }

}
//清除分数显示
void UIMainWindows::clearScore()
{
    eastscore=0;
    southscore=0;
    westscore=0;
    northscore=0;
}
//显示各玩家的分数
void UIMainWindows::setScoreTxt()
{
    ui->eastscorelabel->setText("东 "+ QString::number(eastscore)+"分");
    ui->southscorelabel->setText("南 "+ QString::number(southscore)+"分");
    ui->westscorelabel->setText("西 "+ QString::number(westscore)+"分");
    ui->northscorelabel->setText("北 "+ QString::number(northscore)+"分");
}
//清除面板显示
void UIMainWindows::clearPanel()
{
    //清理选庄
    clearBanker();

    //设置遮罩层(消失)
    ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
    ui->justTakenLabel->setGeometry(1130,20,10,10);

    //清空手牌
    ui->handSouth1->clear();
    ui->handSouth2->clear();
    ui->handSouth3->clear();
    ui->handSouth4->clear();
    ui->handSouth5->clear();
    ui->handSouth6->clear();
    ui->handSouth7->clear();
    ui->handSouth8->clear();
    ui->handSouth9->clear();
    ui->handSouth10->clear();
    ui->handSouth11->clear();
    ui->handSouth12->clear();
    ui->handSouth13->clear();
    ui->handSouth14->clear();
    ui->handSouth15->clear();
    ui->handSouth16->clear();
    ui->handSouth17->clear();
    ui->handSouth18->clear();

    ui->handEast1->clear();
    ui->handEast2->clear();
    ui->handEast3->clear();
    ui->handEast4->clear();
    ui->handEast5->clear();
    ui->handEast6->clear();
    ui->handEast7->clear();
    ui->handEast8->clear();
    ui->handEast9->clear();
    ui->handEast10->clear();
    ui->handEast11->clear();
    ui->handEast12->clear();
    ui->handEast13->clear();
    ui->handEast14->clear();
    ui->handEast15->clear();
    ui->handEast16->clear();
    ui->handEast17->clear();
    ui->handEast18->clear();

    ui->handNorth1->clear();
    ui->handNorth2->clear();
    ui->handNorth3->clear();
    ui->handNorth4->clear();
    ui->handNorth5->clear();
    ui->handNorth6->clear();
    ui->handNorth7->clear();
    ui->handNorth8->clear();
    ui->handNorth9->clear();
    ui->handNorth10->clear();
    ui->handNorth11->clear();
    ui->handNorth12->clear();
    ui->handNorth13->clear();
    ui->handNorth14->clear();
    ui->handNorth15->clear();
    ui->handNorth16->clear();
    ui->handNorth17->clear();
    ui->handNorth18->clear();

    ui->handWest1->clear();
    ui->handWest2->clear();
    ui->handWest3->clear();
    ui->handWest4->clear();
    ui->handWest5->clear();
    ui->handWest6->clear();
    ui->handWest7->clear();
    ui->handWest8->clear();
    ui->handWest9->clear();
    ui->handWest10->clear();
    ui->handWest11->clear();
    ui->handWest12->clear();
    ui->handWest13->clear();
    ui->handWest14->clear();
    ui->handWest15->clear();
    ui->handWest16->clear();
    ui->handWest17->clear();
    ui->handWest18->clear();

    //清空预测
    ui->predictionSouth1->clear();
    ui->predictionSouth2->clear();
    ui->predictionSouth3->clear();
    ui->predictionSouth4->clear();
    ui->predictionSouth5->clear();
    ui->predictionSouth6->clear();
    ui->predictionSouth7->clear();
    ui->predictionSouth8->clear();
    ui->predictionSouth9->clear();
    ui->predictionSouth10->clear();

    ui->predictionEast1->clear();
    ui->predictionEast2->clear();
    ui->predictionEast3->clear();
    ui->predictionEast4->clear();
    ui->predictionEast5->clear();
    ui->predictionEast6->clear();
    ui->predictionEast7->clear();
    ui->predictionEast8->clear();
    ui->predictionEast9->clear();
    ui->predictionEast10->clear();

    ui->predictionNorth1->clear();
    ui->predictionNorth2->clear();
    ui->predictionNorth3->clear();
    ui->predictionNorth4->clear();
    ui->predictionNorth5->clear();
    ui->predictionNorth6->clear();
    ui->predictionNorth7->clear();
    ui->predictionNorth8->clear();
    ui->predictionNorth9->clear();
    ui->predictionNorth10->clear();

    ui->predictionWest1->clear();
    ui->predictionWest2->clear();
    ui->predictionWest3->clear();
    ui->predictionWest4->clear();
    ui->predictionWest5->clear();
    ui->predictionWest6->clear();
    ui->predictionWest7->clear();
    ui->predictionWest8->clear();
    ui->predictionWest9->clear();
    ui->predictionWest10->clear();

    //清空牌墙
    //牌墙数字和牌墙
    //西
    ui->drawWestNumber1->clear();
    ui->drawWestNumber2->clear();
    ui->drawWestNumber3->clear();
    ui->drawWestNumber4->clear();
    ui->drawWestNumber5->clear();
    ui->drawWestNumber6->clear();
    ui->drawWestNumber7->clear();
    ui->drawWestNumber8->clear();
    ui->drawWestNumber9->clear();
    ui->drawWestNumber10->clear();
    ui->drawWestNumber11->clear();
    ui->drawWestNumber12->clear();
    ui->drawWestNumber13->clear();
    ui->drawWestNumber14->clear();
    ui->drawWestNumber15->clear();
    ui->drawWestNumber16->clear();
    ui->drawWestNumber17->clear();

    ui->drawWest1_1->clear();
    ui->drawWest2_1->clear();
    ui->drawWest1_2->clear();
    ui->drawWest2_2->clear();
    ui->drawWest1_3->clear();
    ui->drawWest2_3->clear();
    ui->drawWest1_4->clear();
    ui->drawWest2_4->clear();
    ui->drawWest1_5->clear();
    ui->drawWest2_5->clear();
    ui->drawWest1_6->clear();
    ui->drawWest2_6->clear();
    ui->drawWest1_7->clear();
    ui->drawWest2_7->clear();
    ui->drawWest1_8->clear();
    ui->drawWest2_8->clear();
    ui->drawWest1_9->clear();
    ui->drawWest2_9->clear();
    ui->drawWest1_10->clear();
    ui->drawWest2_10->clear();
    ui->drawWest1_11->clear();
    ui->drawWest2_11->clear();
    ui->drawWest1_12->clear();
    ui->drawWest2_12->clear();
    ui->drawWest1_13->clear();
    ui->drawWest2_13->clear();
    ui->drawWest1_14->clear();
    ui->drawWest2_14->clear();
    ui->drawWest1_15->clear();
    ui->drawWest2_15->clear();
    ui->drawWest1_16->clear();
    ui->drawWest2_16->clear();
    ui->drawWest1_17->clear();
    ui->drawWest2_17->clear();
    //南
    ui->drawSouthNumber1_1->clear();
    ui->drawSouthNumber1_2->clear();
    ui->drawSouthNumber1_3->clear();
    ui->drawSouthNumber1_4->clear();
    ui->drawSouthNumber1_5->clear();
    ui->drawSouthNumber1_6->clear();
    ui->drawSouthNumber1_7->clear();
    ui->drawSouthNumber1_8->clear();
    ui->drawSouthNumber1_9->clear();
    ui->drawSouthNumber1_10->clear();
    ui->drawSouthNumber1_11->clear();
    ui->drawSouthNumber1_12->clear();
    ui->drawSouthNumber1_13->clear();
    ui->drawSouthNumber1_14->clear();
    ui->drawSouthNumber1_15->clear();
    ui->drawSouthNumber1_16->clear();
    ui->drawSouthNumber1_17->clear();

    ui->drawSouth1_1->clear();
    ui->drawSouth2_1->clear();
    ui->drawSouth1_2->clear();
    ui->drawSouth2_2->clear();
    ui->drawSouth1_3->clear();
    ui->drawSouth2_3->clear();
    ui->drawSouth1_4->clear();
    ui->drawSouth2_4->clear();
    ui->drawSouth1_5->clear();
    ui->drawSouth2_5->clear();
    ui->drawSouth1_6->clear();
    ui->drawSouth2_6->clear();
    ui->drawSouth1_7->clear();
    ui->drawSouth2_7->clear();
    ui->drawSouth1_8->clear();
    ui->drawSouth2_8->clear();
    ui->drawSouth1_9->clear();
    ui->drawSouth2_9->clear();
    ui->drawSouth1_10->clear();
    ui->drawSouth2_10->clear();
    ui->drawSouth1_11->clear();
    ui->drawSouth2_11->clear();
    ui->drawSouth1_12->clear();
    ui->drawSouth2_12->clear();
    ui->drawSouth1_13->clear();
    ui->drawSouth2_13->clear();
    ui->drawSouth1_14->clear();
    ui->drawSouth2_14->clear();
    ui->drawSouth1_15->clear();
    ui->drawSouth2_15->clear();
    ui->drawSouth1_16->clear();
    ui->drawSouth2_16->clear();
    ui->drawSouth1_17->clear();
    ui->drawSouth2_17->clear();

    //北
    ui->drawNorthNumber1_1->clear();
    ui->drawNorthNumber1_2->clear();
    ui->drawNorthNumber1_3->clear();
    ui->drawNorthNumber1_4->clear();
    ui->drawNorthNumber1_5->clear();
    ui->drawNorthNumber1_6->clear();
    ui->drawNorthNumber1_7->clear();
    ui->drawNorthNumber1_8->clear();
    ui->drawNorthNumber1_9->clear();
    ui->drawNorthNumber1_10->clear();
    ui->drawNorthNumber1_11->clear();
    ui->drawNorthNumber1_12->clear();
    ui->drawNorthNumber1_13->clear();
    ui->drawNorthNumber1_14->clear();
    ui->drawNorthNumber1_15->clear();
    ui->drawNorthNumber1_16->clear();
    ui->drawNorthNumber1_17->clear();

    ui->drawNorth1_1->clear();
    ui->drawNorth2_1->clear();
    ui->drawNorth1_2->clear();
    ui->drawNorth2_2->clear();
    ui->drawNorth1_3->clear();
    ui->drawNorth2_3->clear();
    ui->drawNorth1_4->clear();
    ui->drawNorth2_4->clear();
    ui->drawNorth1_5->clear();
    ui->drawNorth2_5->clear();
    ui->drawNorth1_6->clear();
    ui->drawNorth2_6->clear();
    ui->drawNorth1_7->clear();
    ui->drawNorth2_7->clear();
    ui->drawNorth1_8->clear();
    ui->drawNorth2_8->clear();
    ui->drawNorth1_9->clear();
    ui->drawNorth2_9->clear();
    ui->drawNorth1_10->clear();
    ui->drawNorth2_10->clear();
    ui->drawNorth1_11->clear();
    ui->drawNorth2_11->clear();
    ui->drawNorth1_12->clear();
    ui->drawNorth2_12->clear();
    ui->drawNorth1_13->clear();
    ui->drawNorth2_13->clear();
    ui->drawNorth1_14->clear();
    ui->drawNorth2_14->clear();
    ui->drawNorth1_15->clear();
    ui->drawNorth2_15->clear();
    ui->drawNorth1_16->clear();
    ui->drawNorth2_16->clear();
    ui->drawNorth1_17->clear();
    ui->drawNorth2_17->clear();

    //东
    ui->drawEastNumber1_1->clear();
    ui->drawEastNumber1_2->clear();
    ui->drawEastNumber1_3->clear();
    ui->drawEastNumber1_4->clear();
    ui->drawEastNumber1_5->clear();
    ui->drawEastNumber1_6->clear();
    ui->drawEastNumber1_7->clear();
    ui->drawEastNumber1_8->clear();
    ui->drawEastNumber1_9->clear();
    ui->drawEastNumber1_10->clear();
    ui->drawEastNumber1_11->clear();
    ui->drawEastNumber1_12->clear();
    ui->drawEastNumber1_13->clear();
    ui->drawEastNumber1_14->clear();
    ui->drawEastNumber1_15->clear();
    ui->drawEastNumber1_16->clear();
    ui->drawEastNumber1_17->clear();

    ui->drawEast1_1->clear();
    ui->drawEast2_1->clear();
    ui->drawEast1_2->clear();
    ui->drawEast2_2->clear();
    ui->drawEast1_3->clear();
    ui->drawEast2_3->clear();
    ui->drawEast1_4->clear();
    ui->drawEast2_4->clear();
    ui->drawEast1_5->clear();
    ui->drawEast2_5->clear();
    ui->drawEast1_6->clear();
    ui->drawEast2_6->clear();
    ui->drawEast1_7->clear();
    ui->drawEast2_7->clear();
    ui->drawEast1_8->clear();
    ui->drawEast2_8->clear();
    ui->drawEast1_9->clear();
    ui->drawEast2_9->clear();
    ui->drawEast1_10->clear();
    ui->drawEast2_10->clear();
    ui->drawEast1_11->clear();
    ui->drawEast2_11->clear();
    ui->drawEast1_12->clear();
    ui->drawEast2_12->clear();
    ui->drawEast1_13->clear();
    ui->drawEast2_13->clear();
    ui->drawEast1_14->clear();
    ui->drawEast2_14->clear();
    ui->drawEast1_15->clear();
    ui->drawEast2_15->clear();
    ui->drawEast1_16->clear();
    ui->drawEast2_16->clear();
    ui->drawEast1_17->clear();
    ui->drawEast2_17->clear();

    //庄家方向
    ui->bankerPrompt->clear();

    //打牌玩家箭头
    ui->directionSouth->clear();
    ui->directionEast->clear();
    ui->directionNorth->clear();
    ui->directionWest->clear();

    //弃牌
    ui->discard1_1->clear();
    ui->discard1_2->clear();
    ui->discard1_3->clear();
    ui->discard1_4->clear();
    ui->discard1_5->clear();
    ui->discard1_6->clear();
    ui->discard1_7->clear();
    ui->discard1_8->clear();
    ui->discard1_9->clear();
    ui->discard1_10->clear();
    ui->discard1_11->clear();
    ui->discard1_12->clear();
    ui->discard1_13->clear();
    ui->discard1_14->clear();
    ui->discard1_15->clear();
    ui->discard1_16->clear();
    ui->discard1_17->clear();
    ui->discard1_18->clear();
    ui->discard1_19->clear();
    ui->discard1_20->clear();
    ui->discard1_21->clear();
    ui->discard1_22->clear();
    ui->discard1_23->clear();
    ui->discard1_24->clear();
    ui->discard1_25->clear();
    ui->discard1_26->clear();
    ui->discard1_27->clear();
    ui->discard1_28->clear();
    ui->discard1_29->clear();
    ui->discard1_30->clear();
    ui->discard1_31->clear();
    ui->discard1_32->clear();
    ui->discard1_33->clear();
    ui->discard1_34->clear();
    ui->discard1_35->clear();
    ui->discard1_36->clear();
    ui->discard1_37->clear();
    ui->discard1_38->clear();
    ui->discard1_39->clear();
    ui->discard1_40->clear();
    ui->discard1_41->clear();
    ui->discard1_42->clear();
    ui->discard1_43->clear();
    ui->discard1_44->clear();
    ui->discard1_45->clear();
    ui->discard1_46->clear();
    ui->discard1_47->clear();
    ui->discard1_48->clear();
    ui->discard1_49->clear();
    ui->discard1_50->clear();
    ui->discard1_51->clear();
    ui->discard1_52->clear();
    ui->discard1_53->clear();
    ui->discard1_54->clear();
    ui->discard1_55->clear();
    ui->discard1_56->clear();
    ui->discard1_57->clear();
    ui->discard1_58->clear();
    ui->discard1_59->clear();
    ui->discard1_60->clear();
    ui->discard1_61->clear();
    ui->discard1_62->clear();
    ui->discard1_63->clear();
    ui->discard1_64->clear();
    ui->discard1_65->clear();
    ui->discard1_66->clear();
    ui->discard1_67->clear();
    ui->discard1_68->clear();
    ui->discard1_69->clear();
    ui->discard1_70->clear();
    ui->discard1_71->clear();
    ui->discard1_72->clear();
    ui->discard1_73->clear();
    ui->discard1_74->clear();
    ui->discard1_75->clear();
    ui->discard1_76->clear();
    ui->discard1_77->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_78->clear();
    ui->discard1_79->clear();
    ui->discard1_80->clear();
    ui->discard1_81->clear();
    ui->discard1_82->clear();
    ui->discard1_83->clear();
    ui->discard1_84->clear();
    ui->discard1_85->clear();
    ui->discard1_86->clear();
    ui->discard1_87->clear();
    ui->discard1_88->clear();
    ui->discard1_89->clear();
    ui->discard1_90->clear();
    ui->discard1_91->clear();
    ui->discard1_92->clear();
    ui->discard1_93->clear();
    ui->discard1_94->clear();
    ui->discard1_95->clear();
    ui->discard1_96->clear();
    ui->discard1_97->clear();
    ui->discard1_98->clear();
    ui->discard1_99->clear();
    ui->discard1_100->clear();

    //清空吃、碰、杠、胡、听、过
    ui->statusSouthWin->clear();
    ui->statusEastWin->clear();
    ui->statusNorthWin->clear();
    ui->statusWestWin->clear();

    ui->statusSouthCheck->clear();
    ui->statusEastCheck->clear();
    ui->statusNorthCheck->clear();
    ui->statusWestCheck->clear();

    ui->statusSouthChow->clear();
    ui->statusEastChow->clear();
    ui->statusNorthChow->clear();
    ui->statusWestChow->clear();

    ui->statusSouthPong->clear();
    ui->statusEastPong->clear();
    ui->statusNorthPong->clear();
    ui->statusWestPong->clear();

    ui->statusSouthKong->clear();
    ui->statusEastKong->clear();
    ui->statusNorthKong->clear();
    ui->statusWestKong->clear();

    ui->statusSouthReady->clear();
    ui->statusEastReady->clear();
    ui->statusNorthReady->clear();
    ui->statusWestReady->clear();

    //清空胡牌标示
    ui->huSouth->clear();
    ui->huEast->clear();
    ui->huNorth->clear();
    ui->huWest->clear();

    //清空听牌
    ui->statusSouthReadyNum1->clear();
    ui->statusSouthReadyNum2->clear();
    ui->statusSouthReadyNum3->clear();
    ui->statusSouthReadyNum4->clear();
    ui->statusSouthReadyNum5->clear();
    ui->statusSouthReadyNum6->clear();
    ui->statusSouthReadyNum7->clear();
    ui->statusSouthReadyNum8->clear();
    ui->statusSouthReadyNum9->clear();
    ui->statusSouthReadyNum10->clear();

    ui->statusSouthReadyPai1->clear();
    ui->statusSouthReadyPai2->clear();
    ui->statusSouthReadyPai3->clear();
    ui->statusSouthReadyPai4->clear();
    ui->statusSouthReadyPai5->clear();
    ui->statusSouthReadyPai6->clear();
    ui->statusSouthReadyPai7->clear();
    ui->statusSouthReadyPai8->clear();
    ui->statusSouthReadyPai9->clear();
    ui->statusSouthReadyPai10->clear();

    ui->statusEastReadyNum1->clear();
    ui->statusEastReadyNum2->clear();
    ui->statusEastReadyNum3->clear();
    ui->statusEastReadyNum4->clear();
    ui->statusEastReadyNum5->clear();
    ui->statusEastReadyNum6->clear();
    ui->statusEastReadyNum7->clear();
    ui->statusEastReadyNum8->clear();
    ui->statusEastReadyNum9->clear();
    ui->statusEastReadyNum10->clear();

    ui->statusEastReadyPai1->clear();
    ui->statusEastReadyPai2->clear();
    ui->statusEastReadyPai3->clear();
    ui->statusEastReadyPai4->clear();
    ui->statusEastReadyPai5->clear();
    ui->statusEastReadyPai6->clear();
    ui->statusEastReadyPai7->clear();
    ui->statusEastReadyPai8->clear();
    ui->statusEastReadyPai9->clear();
    ui->statusEastReadyPai10->clear();

    ui->statusNorthReadyNum1->clear();
    ui->statusNorthReadyNum2->clear();
    ui->statusNorthReadyNum3->clear();
    ui->statusNorthReadyNum4->clear();
    ui->statusNorthReadyNum5->clear();
    ui->statusNorthReadyNum6->clear();
    ui->statusNorthReadyNum7->clear();
    ui->statusNorthReadyNum8->clear();
    ui->statusNorthReadyNum9->clear();
    ui->statusNorthReadyNum10->clear();

    ui->statusNorthReadyPai1->clear();
    ui->statusNorthReadyPai2->clear();
    ui->statusNorthReadyPai3->clear();
    ui->statusNorthReadyPai4->clear();
    ui->statusNorthReadyPai5->clear();
    ui->statusNorthReadyPai6->clear();
    ui->statusNorthReadyPai7->clear();
    ui->statusNorthReadyPai8->clear();
    ui->statusNorthReadyPai9->clear();
    ui->statusNorthReadyPai10->clear();

    ui->statusWestReadyNum1->clear();
    ui->statusWestReadyNum2->clear();
    ui->statusWestReadyNum3->clear();
    ui->statusWestReadyNum4->clear();
    ui->statusWestReadyNum5->clear();
    ui->statusWestReadyNum6->clear();
    ui->statusWestReadyNum7->clear();
    ui->statusWestReadyNum8->clear();
    ui->statusWestReadyNum9->clear();
    ui->statusWestReadyNum10->clear();

    ui->statusWestReadyPai1->clear();
    ui->statusWestReadyPai2->clear();
    ui->statusWestReadyPai3->clear();
    ui->statusWestReadyPai4->clear();
    ui->statusWestReadyPai5->clear();
    ui->statusWestReadyPai6->clear();
    ui->statusWestReadyPai7->clear();
    ui->statusWestReadyPai8->clear();
    ui->statusWestReadyPai9->clear();
    ui->statusWestReadyPai10->clear();

    //清空碰牌标识
    ui->handPromptEast1->clear();
    ui->handPromptEast2->clear();
    ui->handPromptEast3->clear();
    ui->handPromptEast4->clear();
    ui->handPromptEast5->clear();
    ui->handPromptEast6->clear();
    ui->handPromptEast7->clear();
    ui->handPromptEast8->clear();
    ui->handPromptEast9->clear();
    ui->handPromptEast10->clear();
    ui->handPromptEast11->clear();
    ui->handPromptEast12->clear();
    ui->handPromptEast13->clear();
    ui->handPromptEast14->clear();
    ui->handPromptEast15->clear();
    ui->handPromptEast16->clear();
    ui->handPromptEast17->clear();
    ui->handPromptEast18->clear();

    ui->handPromptSouth1->clear();
    ui->handPromptSouth2->clear();
    ui->handPromptSouth3->clear();
    ui->handPromptSouth4->clear();
    ui->handPromptSouth5->clear();
    ui->handPromptSouth6->clear();
    ui->handPromptSouth7->clear();
    ui->handPromptSouth8->clear();
    ui->handPromptSouth9->clear();
    ui->handPromptSouth10->clear();
    ui->handPromptSouth11->clear();
    ui->handPromptSouth12->clear();
    ui->handPromptSouth13->clear();
    ui->handPromptSouth14->clear();
    ui->handPromptSouth15->clear();
    ui->handPromptSouth16->clear();
    ui->handPromptSouth17->clear();
    ui->handPromptSouth18->clear();

    ui->handPromptWest1->clear();
    ui->handPromptWest2->clear();
    ui->handPromptWest3->clear();
    ui->handPromptWest4->clear();
    ui->handPromptWest5->clear();
    ui->handPromptWest6->clear();
    ui->handPromptWest7->clear();
    ui->handPromptWest8->clear();
    ui->handPromptWest9->clear();
    ui->handPromptWest10->clear();
    ui->handPromptWest11->clear();
    ui->handPromptWest12->clear();
    ui->handPromptWest13->clear();
    ui->handPromptWest14->clear();
    ui->handPromptWest15->clear();
    ui->handPromptWest16->clear();
    ui->handPromptWest17->clear();
    ui->handPromptWest18->clear();

    ui->handPromptNorth1->clear();
    ui->handPromptNorth2->clear();
    ui->handPromptNorth3->clear();
    ui->handPromptNorth4->clear();
    ui->handPromptNorth5->clear();
    ui->handPromptNorth6->clear();
    ui->handPromptNorth7->clear();
    ui->handPromptNorth8->clear();
    ui->handPromptNorth9->clear();
    ui->handPromptNorth10->clear();
    ui->handPromptNorth11->clear();
    ui->handPromptNorth12->clear();
    ui->handPromptNorth13->clear();
    ui->handPromptNorth14->clear();
    ui->handPromptNorth15->clear();
    ui->handPromptNorth16->clear();
    ui->handPromptNorth17->clear();
    ui->handPromptNorth18->clear();
}
//清除变量
void UIMainWindows::clearVariable()
{
    //庄家
    zhuangjia = -1;

    //重新叫庄
    isBanker = true;//等待叫庄状态
    isMopai = false;///非摸牌状态，掷色子阶段

    //摸牌
    mopaiDirection = -1;
    mopaiPos = -1;
    mopaiCeng = 1;

    //预测
    yuceDirection = -1;
    yucePos = -1;
    yuceCeng = 1;

    //摸牌打牌玩家
    mopaiWanjia = -1;
    dapaiWanjia = -1;

    //清空数据
    majhongTaken.clear();
    majhongTotal.clear();
    majhongRemain.clear();

    //手牌
    handNorthMjs.clear();
    handSouthMjs.clear();
    handEastMjs.clear();
    handWestMjs.clear();

    //牌墙
    drawNorthMjs.clear();
    drawEastMjs.clear();
    drawSouthMjs.clear();
    drawWestMjs.clear();

    //预测
    predictionNorthMjs.clear();
    predictionSouthMjs.clear();
    predictionWestMjs.clear();
    predictionEastMjs.clear();

    //弃牌
    discardMjs.clear();

   //预测的数目
   predictionNumber = 10;

   //吃
   isSouthChow = false;
   isNorthChow = false;
   isEastChow = false;
   isWestChow = false;
   chowType.clear();//吃牌的类型0（-1，+1），1（+1，+2），2（-1，-2）
   chowVec.clear();//吃牌的队列组合中 原始牌中的第一个元素

   //碰
   isSouthPong = false;
   isNorthPong = false;
   isEastPong = false;
   isWestPong = false;

   //杠(明杠)
   isSouthKong = false;
   isWestKong = false;
   isNorthKong = false;
   isEastKong = false;

   //记录暗杠个数
   memset(concealedKongNum, 0, sizeof(concealedKongNum));
   concealedKongElement[0].clear();
   concealedKongElement[1].clear();
   concealedKongElement[2].clear();
   concealedKongElement[3].clear();

   //能否暗杠
   isSouthConcealedKong = false;
   isWestConcealedKong = false;
   isNorthConcealedKong = false;
   isEastConcealedKong = false;

   //抢杠胡
   isQiangganghu = false;
   qiangganghuElement[0].clear();
   qiangganghuElement[1].clear();
   qiangganghuElement[2].clear();
   qiangganghuElement[3].clear();
   qiangganghuPaiNum = 0;//抢杠的牌
   qiangganghuType = -1;//0-——-一个碰杠，1————多个碰杠

   //手牌有效位置
   handSouthIndex = 0;
   handWestIndex = 0;
   handEastIndex = 0;
   handNorthIndex = 0;

   //胡
   isSouthWin = false;
   isEastWin = false;
   isNorthWin = false;
   isWestWin = false;

   //听
   isSouthReady = false;
   isEastReady = false;
   isNorthReady = false;
   isWestReady = false;

   southReadyHash.clear();
   eastReadyHash.clear();
   northReadyHash.clear();
   westReadyHash.clear();

   readyElemnt[0].clear();
   readyElemnt[1].clear();
   readyElemnt[2].clear();
   readyElemnt[3].clear();



   //每个方向的牌数
   zhangshuSouth  = 0;
   zhangshuWest = 0;
   zhangshuNorth = 0;
   zhangshuEast = 0;

   //缺门
   southQue = -10;//0---万、10---条、20---筒
   eastQue = -10;
   northQue = -10;
   westQue = -10;

   isSouthQue = true;
   isEastQue = true;
   isNorthQue = true;
   isWestQue = true;

   //开始游戏
   isBeginGame = false;

   isZimo = false;//自摸

   //撤回
   while(!dapaiWanjiaStack.empty()){
       dapaiWanjiaStack.pop();
   }
   while(!playedPaiStack.empty()){
       playedPaiStack.pop();
   }

   //记录暗杠
   while(!southKongStack.empty()){
       southKongStack.pop();
   }
   while(!eastKongStack.empty()){
       eastKongStack.pop();
   }
   while(!northKongStack.empty()){
       northKongStack.pop();
   }
   while(!westKongStack.empty()){
       westKongStack.pop();
   }

   //改牌
   changeSouthPai = false;
   changeEastPai = false;
   changeNorthPai = false;
   changeWestPai = false;

   endWanjia.clear();

}
//事件响应函数，界面上的操作都通过该函数接收和判断对应操作
bool UIMainWindows::eventFilter(QObject *obj, QEvent *event)
{
    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

    //开始游戏    //MouseButtonRelease
    if(isBeginGame == false)   return false;

    for(int i = 0; i < 4; i++){
        if(((obj == bankerlist[i])||(obj ==dirbeginlist[i]))&&
            (event->type() == QEvent::MouseButtonPress)&&
            (mouseEvent->button() == Qt::LeftButton)&&(isBanker == true)){

                isBanker = false;
                zhuangjia = i;
                //获得摸牌玩家的编号
                mopaiWanjia = zhuangjia;
                dapaiWanjia = zhuangjia;
                bankerDirectionDisplay();
                //clearBanker();
                return true;
         }
    }
    if (zhuangjia==-1)  return false;

        for(int i = 0; i < 17; i++)
            if(((obj == drawSouthlist1[i])||(obj == drawSouthlist2[i]))&&
               (event->type() == QEvent::MouseButtonPress)&&
               (mouseEvent->button() == Qt::LeftButton)&&
               (isMopai == false)){
                    isMopai = true;
                    list<Mj> handOne;
                    list<Mj> handTwo;
                    list<Mj> handThree;
                    list<Mj> handFour;

                    mopaiDirection = 0;
                    mopaiCeng = 0;
                    mopaiPos =i+1;
                    beginDraw(handOne, handTwo, handThree, handFour);
                    beginGameDisplay(handOne, handTwo, handThree, handFour);
                    return true;
            }
//ccccc
        for(int i = 0; i < 17; i++)
            if(((obj == drawEastlist1[i])||(obj == drawEastlist2[i]))&&
               (event->type() == QEvent::MouseButtonPress)&&
               (mouseEvent->button() == Qt::LeftButton)&&
               (isMopai == false)){
                    isMopai = true;
                    list<Mj> handOne;
                    list<Mj> handTwo;
                    list<Mj> handThree;
                    list<Mj> handFour;

                    mopaiDirection = 1;
                    mopaiCeng = 0;
                    mopaiPos =i+1;
                    beginDraw(handOne, handTwo, handThree, handFour);
                    beginGameDisplay(handOne, handTwo, handThree, handFour);
                    return true;
            }
        for(int i = 0; i < 17; i++)
            if(((obj == drawNorthlist1[i])||(obj == drawNorthlist2[i]))&&
               (event->type() == QEvent::MouseButtonPress)&&
               (mouseEvent->button() == Qt::LeftButton)&&
               (isMopai == false)){
                    isMopai = true;
                    list<Mj> handOne;
                    list<Mj> handTwo;
                    list<Mj> handThree;
                    list<Mj> handFour;

                    mopaiDirection = 2;
                    mopaiCeng = 0;
                    mopaiPos =i+1;
                    beginDraw(handOne, handTwo, handThree, handFour);
                    beginGameDisplay(handOne, handTwo, handThree, handFour);
                    return true;
            }

        for(int i = 0; i < 17; i++)
            if(((obj == drawWestlist1[i])||(obj == drawWestlist2[i]))&&
               (event->type() == QEvent::MouseButtonPress)&&
               (mouseEvent->button() == Qt::LeftButton)&&
               (isMopai == false)){
                    isMopai = true;
                    list<Mj> handOne;
                    list<Mj> handTwo;
                    list<Mj> handThree;
                    list<Mj> handFour;

                    mopaiDirection = 3;
                    mopaiCeng = 0;
                    mopaiPos =i+1;
                    beginDraw(handOne, handTwo, handThree, handFour);
                    beginGameDisplay(handOne, handTwo, handThree, handFour);
                    return true;
            }

                //手牌监听事件
        //cccccccccccccccccccc
        for(int i = 0; i < 18; i++)
            if(obj == handSouthlist[i]){ //南 判断部件
                if(event->type() == QEvent::Enter){//鼠标进入
                    int cnt = 0;
                    for(auto j:handSouthMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int x = handSouthlist[i]->x();
                                handSouthlist[i]->setGeometry(x, 598, 35, 55);
                                break;
                            }
                        }
                        cnt++;
                    }
                    return true;
                }else if(event->type() == QEvent::Leave){//鼠标离开
                    int cnt = 0;
                    for(auto j:handSouthMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int x = handSouthlist[i]->x();
                                handSouthlist[i]->setGeometry(x, 608, 35, 55);
                                break;
                            }
                        }
                        cnt++;
                     }
                    return true;
                 }else if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                    //将event强制转换为发生时间的类型
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if(mouseEvent->button() == Qt::LeftButton){     //鼠标左键
                        if(isSouthChow == false && isSouthConcealedKong == false && dapaiWanjia == 0){
                            if(handSouthIndex <= i){
                                dapai(i);
                            }
                        }else if(isSouthChow == true){
                            chowDapai(i);
                        }else if(isSouthConcealedKong == true && dapaiWanjia == 0){
                            kongDapai(i);
                        }
                        return true;// 该事件已经被处理
                    }else{ return false; }
                }else{  return false;}
                return true;
            }

        for(int i = 0; i < 18; i++)
            if(obj == handEastlist[i]){  //东 判断部件
                if(event->type() == QEvent::Enter){//鼠标进入
                    int cnt = 0;
                    for(auto j:handEastMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int y = handEastlist[i]->y();
                                handEastlist[i]->setGeometry(966, y, 55, 35);
                                break;
                            }
                        }
                        cnt++;
                    }
                    return true;
                }else if(event->type() == QEvent::Leave){//鼠标离开
                    int cnt = 0;
                    for(auto j:handEastMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int y = handEastlist[i]->y();
                                handEastlist[i]->setGeometry(976, y, 55, 35);
                                break;
                            }
                        }
                        cnt++;
                     }
                    return true;
                 }else if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                    //将event强制转换为发生时间的类型
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if(mouseEvent->button() == Qt::LeftButton){     //鼠标左键
                        if(isEastChow == false && isEastConcealedKong == false && dapaiWanjia == 1){
                            if(handEastIndex <= i){
                                dapai(i);
                            }
                        }else if(isEastChow == true){
                            chowDapai(i);
                        }else if(isEastConcealedKong == true && dapaiWanjia == 1){
                            kongDapai(i);
                        }
                        return true;// 该事件已经被处理
                    }else{ return false; }
                }else{  return false;}
                return true;
            }


        for(int i = 0; i < 18; i++)
            if(obj == handNorthlist[i]){ //北 判断部件
                if(event->type() == QEvent::Enter){//鼠标进入
                    int cnt = 0;
                    for(auto j:handNorthMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int x = handNorthlist[i]->x();
                                handNorthlist[i]->setGeometry(x, 38, 35, 55);
                                break;
                            }
                        }
                        cnt++;
                    }
                    return true;
                }else if(event->type() == QEvent::Leave){//鼠标离开
                    int cnt = 0;
                    for(auto j:handNorthMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int x = handNorthlist[i]->x();
                                handNorthlist[i]->setGeometry(x, 48, 35, 55);
                                break;
                            }
                        }
                        cnt++;
                     }
                    return true;
                 }else if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                    //将event强制转换为发生时间的类型
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if(mouseEvent->button() == Qt::LeftButton){     //鼠标左键
                        if(isNorthChow == false && isNorthConcealedKong == false && dapaiWanjia == 2){
                            if(handNorthIndex <= i){
                                dapai(i);
                            }
                        }else if(isNorthChow == true){
                            chowDapai(i);
                        }else if(isNorthConcealedKong == true && dapaiWanjia == 2){
                            kongDapai(i);
                        }
                        return true;// 该事件已经被处理
                    }else{ return false; }
                }else{  return false;}
                return true;
            }

        for(int i = 0; i < 18; i++)
            if(obj == handWestlist[i]){  //西 判断部件
                if(event->type() == QEvent::Enter){//鼠标进入
                    int cnt = 0;
                    for(auto j:handWestMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int y = handWestlist[i]->y();
                                handWestlist[i]->setGeometry(146, y, 55, 35);
                                break;
                            }
                        }
                        cnt++;
                    }
                    return true;
                }else if(event->type() == QEvent::Leave){//鼠标离开
                    int cnt = 0;
                    for(auto j:handWestMjs){
                        if(cnt == i){
                            if(j.getPaizhuangtai() == 0 && j.isHu() == false){
                                int y = handWestlist[i]->y();
                                handWestlist[i]->setGeometry(136, y, 55, 35);
                                break;
                            }
                        }
                        cnt++;
                     }
                    return true;
                 }else if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                    //将event强制转换为发生时间的类型
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if(mouseEvent->button() == Qt::LeftButton){     //鼠标左键
                        if(isWestChow == false && isWestConcealedKong == false && dapaiWanjia == 3){
                            if(handWestIndex <= i){
                                dapai(i);
                            }
                        }else if(isWestChow == true){
                            chowDapai(i);
                        }else if(isWestConcealedKong == true && dapaiWanjia == 3){
                            kongDapai(i);
                        }
                        return true;// 该事件已经被处理
                    }else{ return false; }
                }else{  return false;}
                return true;
            }


            if(obj == ui->statusSouthPong){//南碰
                if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                    //将event强制转换为发生时间的类型
                    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                    if(mouseEvent->button() == Qt::LeftButton){
                        pongOperating(handSouthMjs);
                        if(isSouthKong == true){//本可以杠，且碰了的
                            isSouthKong = false;
                        }

                        if(systemConfig.angang == 1){
                            isConcealedKong(handSouthMjs, 0);//判断暗杠
                            KongDisplay();
                        }

                        //检测听牌
                        clearReady();
                        isReady();

                        return true;// 该事件已经被处理
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
        }else if(obj == ui->statusSouthChow){//南吃
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   //吃操作
                   chowOperating(handSouthMjs);

                   //变更打牌玩家
                   dapaiWanjia = 0;
                   //展示当前打牌位置
                   directionDisplay(dapaiWanjia);

                   if(systemConfig.angang == 1){
                       //判断暗杠
                       isConcealedKong(handSouthMjs, 0);
                       KongDisplay();
                   }

                   //检测听牌
                   clearReady();
                   isReady();

                   if(chowType.size() == 1){
                       //可以操作的牌的开始位置
                      handSouthIndex += 3;
                       //重置吃标志
                       isSouthChow = false;

                       clearHandStatus();

                        //更新摸牌玩家
                        mopaiWanjia = 1;

                        //展示手牌
                        southHandDisplay(handSouthMjs);

                        //预测
                        yuceDirection  = mopaiDirection;
                        yucePos = mopaiPos;
                        yuceCeng = mopaiCeng;
                        //预测牌
                        yucePai();

                        //从弃牌堆拿走被吃的牌
                        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                            if(iter->getId() == playedPai.begin()->getId()){
                                discardMjs.erase(iter);
                                break;
                            }
                        }
                        discardDisplay(discardMjs);

                   }

                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusSouthKong){//南杠
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   if(concealedKongNum[0] == 0 && isSouthKong == true){//只有一个明杠
                       kongOperating(handSouthMjs);
                   }else if(concealedKongNum[0] == 1 && isSouthKong == false){//只有一个暗杠
                      kongOperating2(handSouthMjs);
                   }else if(concealedKongNum[0] > 1){
                       dapaiWanjia = 0;
                       //展示当前打牌位置
                       //directionDisplay(dapaiWanjia);

                       isSouthConcealedKong = true;
                   }

                   return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusSouthWin){//南胡
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    HuSouth();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusSouthCheck){//南过
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    //清空自摸
                    if(isZimo == true){
                        isZimo = false;
                    }

                    if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
                        if(isSouthWin == true ){
                            if(qiangganghuType == 0){
                                 if(dapaiWanjia == 0){
                                     kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusSouthKong->clear();
                                 }else if(dapaiWanjia == 1){
                                     kongOperating3(handEastMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusEastKong->clear();
                                 }else if(dapaiWanjia == 2){
                                     kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusNorthKong->clear();
                                 }else if(dapaiWanjia == 3){
                                     kongOperating3(handWestMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusWestKong->clear();
                                 }
                            }else if(qiangganghuType == 1){
                                if(dapaiWanjia == 0){
                                    kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 1){
                                    kongOperating3(handEastMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 2){
                                    kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 3){
                                    kongOperating3(handWestMjs, qiangganghuPaiNum);
                                }
                            }

                            isSouthWin = false;
                            ui->statusSouthWin->clear();
                            ui->statusSouthCheck->clear();

                        }

                    }else{
                        //清空状态
                        isSouthPong = false;//碰
                        isSouthChow = false;//吃
                        isSouthKong = false;//明杠
                        isSouthConcealedKong = false;//暗杠
                        isSouthWin = false;//胡


                        //清空吃碰杠状态
                        ui->statusSouthChow->clear();
                        ui->statusSouthPong->clear();
                        ui->statusSouthKong->clear();
                        ui->statusSouthWin->clear();
                        ui->statusSouthCheck->clear();

                        //摸牌
                        draw();
                        //更新打牌玩家
                        updateDapaiWanjia();
                        //展示当前打牌位置
                        directionDisplay(dapaiWanjia);
                    }
                    //过牌之后，重新进入自动打牌状态
                    if (systemConfig.AIPlayers>0)
                        AIPlay();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusEastPong){//东碰
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    pongOperating(handEastMjs);
                    if(isEastKong == true){//本可以杠，且碰了的
                        isEastKong = false;
                    }
                    if(systemConfig.angang == 1){
                        isConcealedKong(handEastMjs, 1);//判断暗杠
                         KongDisplay();
                    }

                     //检测听牌
                     clearReady();
                     isReady();


                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusEastChow){//东吃
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   //吃操作
                   chowOperating(handEastMjs);

                   //变更打牌玩家
                   dapaiWanjia = 1;
                   //展示当前打牌位置
                   directionDisplay(dapaiWanjia);

                   if(systemConfig.angang == 1){
                       //判断暗杠
                       isConcealedKong(handEastMjs, 1);//判断暗杠
                       KongDisplay();
                   }

                   //检测听牌
                   clearReady();
                   isReady();

                   if(chowType.size() == 1){
                       //可以操作的牌的开始位置
                       handEastIndex += 3;
                       //重置碰标志
                       isEastChow = false;

                       clearHandStatus();

                        //更新摸牌玩家
                        mopaiWanjia = 2;

                        //展示手牌
                        eastHandDisplay(handEastMjs);

                        //预测
                        yuceDirection  = mopaiDirection;
                        yucePos = mopaiPos;
                        yuceCeng = mopaiCeng;
                        //预测牌
                        yucePai();

                   }

                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusEastKong){//东杠
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   if(concealedKongNum[1] == 0 && isEastKong == true){//只有一个明杠
                       kongOperating(handEastMjs);
                   }else if(concealedKongNum[1] == 1 && isEastKong == false){//只有一个暗杠
                      kongOperating2(handEastMjs);
                   }else if(concealedKongNum[1] > 1){
                       dapaiWanjia = 1;
                       //展示当前打牌位置
                     //  directionDisplay(dapaiWanjia);

                       isEastConcealedKong = true;
                   }

                   return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusEastWin){//东胡
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    HuEast();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusEastCheck){//东过
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){

                    if(isZimo == true){
                        isZimo = false;
                    }

                    if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
                        if(isEastWin == true){
                            if(qiangganghuType == 0){
                                 if(dapaiWanjia == 0){
                                     kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusSouthKong->clear();
                                 }else if(dapaiWanjia == 1){
                                     kongOperating3(handEastMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusEastKong->clear();
                                 }else if(dapaiWanjia == 2){
                                     kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusNorthKong->clear();
                                 }else if(dapaiWanjia == 3){
                                     kongOperating3(handWestMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusWestKong->clear();
                                 }
                            }else if(qiangganghuType == 1){
                                if(dapaiWanjia == 0){
                                    kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 1){
                                    kongOperating3(handEastMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 2){
                                    kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 3){
                                    kongOperating3(handWestMjs, qiangganghuPaiNum);
                                }
                            }

                            isEastWin = false;
                            ui->statusEastWin->clear();
                            ui->statusEastCheck->clear();
                        }

                    }else{
                        isEastPong = false;
                        isEastChow = false;
                        isEastKong = false;//明杠
                        isEastConcealedKong = false;//暗杠
                        isEastWin = false;//胡

                        //清空吃碰杠状态
                        ui->statusEastChow->clear();
                        ui->statusEastPong->clear();
                        ui->statusEastKong->clear();
                        ui->statusEastWin->clear();
                        ui->statusEastCheck->clear();

                        //摸牌
                        draw();

                        //更新打牌玩家
                        updateDapaiWanjia();
                        //展示当前打牌位置
                        directionDisplay(dapaiWanjia);

                        //从弃牌堆拿走被吃的牌
                        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                            if(iter->getId() == playedPai.begin()->getId()){
                                discardMjs.erase(iter);
                                break;
                            }
                        }
                        discardDisplay(discardMjs);
                    }
                    //过牌之后，重新进入自动打牌状态
                    if (systemConfig.AIPlayers>0)
                        AIPlay();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusNorthPong){//北碰
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    pongOperating(handNorthMjs);
                    if(isNorthKong == true){//本可以杠，且碰了的
                        isNorthKong = false;
                    }
                    if(systemConfig.angang == 1){
                        isConcealedKong(handNorthMjs, 2);//判断暗杠
                         KongDisplay();
                    }

                     //检测听牌
                     clearReady();
                     isReady();

                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusNorthChow){//北吃
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   //吃操作
                   chowOperating(handNorthMjs);

                   //变更打牌玩家
                   dapaiWanjia = 2;
                   //展示当前打牌位置
                   directionDisplay(dapaiWanjia);
                   if(systemConfig.angang == 1){
                        isConcealedKong(handNorthMjs, 2);//判断暗杠
                         KongDisplay();

                    }

                    //检测听牌
                    clearReady();
                    isReady();

                   if(chowType.size() == 1){
                       //可以操作的牌的开始位置
                       handNorthIndex += 3;
                       //重置碰标志
                       isNorthChow = false;

                       clearHandStatus();

                        //更新摸牌玩家
                        mopaiWanjia = 3;

                        //展示手牌
                        northHandDisplay(handNorthMjs); 

                        //预测
                        yuceDirection  = mopaiDirection;
                        yucePos = mopaiPos;
                        yuceCeng = mopaiCeng;
                        //预测牌
                        yucePai();

                   }

                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusNorthKong){//北杠
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   if(concealedKongNum[2] == 0 && isNorthKong == true){//只有一个明杠
                       kongOperating(handNorthMjs);
                   }else if(concealedKongNum[2] == 1 && isNorthKong == false){//只有一个暗杠
                      kongOperating2(handNorthMjs);
                   }else if(concealedKongNum[2] > 1){
                       dapaiWanjia = 2;
                       //展示当前打牌位置
                     //  directionDisplay(dapaiWanjia);

                       isNorthConcealedKong = true;
                   }

                   return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusNorthWin){//北胡
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    HuNorth();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusNorthCheck){//北过
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    if(isZimo == true){
                        isZimo = false;
                    }

                    if(systemConfig.qiangganghu == 1 && isQiangganghu == true){

                        if(isNorthWin == true ){
                            if(qiangganghuType == 0){
                                 if(dapaiWanjia == 0){
                                     kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusSouthKong->clear();
                                 }else if(dapaiWanjia == 1){
                                     kongOperating3(handEastMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusEastKong->clear();
                                 }else if(dapaiWanjia == 2){
                                     kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusNorthKong->clear();
                                 }else if(dapaiWanjia == 3){
                                     kongOperating3(handWestMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusWestKong->clear();
                                 }
                            }else if(qiangganghuType == 1){
                                if(dapaiWanjia == 0){
                                    kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 1){
                                    kongOperating3(handEastMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 2){
                                    kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 3){
                                    kongOperating3(handWestMjs, qiangganghuPaiNum);
                                }
                            }

                            //胡标志消失
                            isNorthWin = false;
                            ui->statusNorthWin->clear();
                            ui->statusNorthCheck->clear();

                        }
                    }else{
                        isNorthPong = false;
                        isNorthChow = false;
                        isNorthKong = false;//明杠
                        isNorthConcealedKong = false;//暗杠
                        isNorthWin = false;//胡

                        //清空吃碰杠状态
                        ui->statusNorthChow->clear();
                        ui->statusNorthPong->clear();
                        ui->statusNorthKong->clear();
                        ui->statusNorthWin->clear();
                        ui->statusNorthCheck->clear();

                        //摸牌
                        draw();

                        isConcealedKong(handNorthMjs, 2);

                        //更新打牌玩家
                        updateDapaiWanjia();
                        //展示当前打牌位置
                        directionDisplay(dapaiWanjia);

                        //从弃牌堆拿走被吃的牌
                        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                            if(iter->getId() == playedPai.begin()->getId()){
                                discardMjs.erase(iter);
                                break;
                            }
                        }
                        discardDisplay(discardMjs);
                    }

                    //过牌之后，重新进入自动打牌状态
                    if (systemConfig.AIPlayers>0)
                        AIPlay();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusWestPong){//西碰
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    pongOperating(handWestMjs);
                    if(isWestKong == true){//本可以杠，且碰了的
                        isWestKong = false;
                    }
                    if(systemConfig.angang == 1){
                        isConcealedKong(handWestMjs, 3);//判断暗杠
                         KongDisplay();
                    }
                     //检测听牌
                     clearReady();
                     isReady();

                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusWestChow){//西吃
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   //吃操作
                   chowOperating(handWestMjs);

                   //变更打牌玩家
                   dapaiWanjia = 3;
                   //展示当前打牌位置
                   directionDisplay(dapaiWanjia);

                   if(systemConfig.angang == 1){
                       isConcealedKong(handWestMjs, 3);//判断暗杠
                        KongDisplay();
                   }

                    //检测听牌
                    clearReady();
                    isReady();

                   if(chowType.size() == 1){
                       //可以操作的牌的开始位置
                       handWestIndex += 3;
                       //重置碰标志
                       isWestChow = false;

                       clearHandStatus();

                        //更新摸牌玩家
                        mopaiWanjia = 0;

                        //展示手牌
                        westHandDisplay(handWestMjs);

                        //预测
                        yuceDirection  = mopaiDirection;
                        yucePos = mopaiPos;
                        yuceCeng = mopaiCeng;
                        //预测牌
                        yucePai();
                   }

                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusWestKong){//西杠
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                   if(concealedKongNum[3] == 0 && isWestKong == true){//只有一个明杠
                      kongOperating(handWestMjs);
                   }else if(concealedKongNum[3] == 1 && isWestKong == false){//只有一个暗杠
                      kongOperating2(handWestMjs);
                   }else if(concealedKongNum[3] > 1){
                       dapaiWanjia = 3;
                       //展示当前打牌位置
                    //   directionDisplay(dapaiWanjia);

                       isWestConcealedKong = true;
                   }

                   return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusWestWin){//西胡
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    HuWest();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else if(obj == ui->statusWestCheck){//西过
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                //将event强制转换为发生时间的类型
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    if(isZimo == true){
                        isZimo = false;
                    }

                    if(systemConfig.qiangganghu == 1 && isQiangganghu == true){
                        if(isWestWin == true){
                            if(qiangganghuType == 0){
                                 if(dapaiWanjia == 0){
                                     kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusSouthKong->clear();
                                 }else if(dapaiWanjia == 1){
                                     kongOperating3(handEastMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusEastKong->clear();
                                 }else if(dapaiWanjia == 2){
                                     kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusNorthKong->clear();
                                 }else if(dapaiWanjia == 3){
                                     kongOperating3(handWestMjs, qiangganghuPaiNum);
                                     //清空杠标志
                                     ui->statusWestKong->clear();
                                 }
                            }else if(qiangganghuType == 1){
                                if(dapaiWanjia == 0){
                                    kongOperating3(handSouthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 1){
                                    kongOperating3(handEastMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 2){
                                    kongOperating3(handNorthMjs, qiangganghuPaiNum);
                                }else if(dapaiWanjia == 3){
                                    kongOperating3(handWestMjs, qiangganghuPaiNum);
                                }
                            }
                            isWestWin = false;
                            ui->statusWestWin->clear();
                            ui->statusWestCheck->clear();
                        }
                    }else{
                        isWestPong = false;
                        isWestChow = false;
                        isWestKong = false;//明杠
                        isWestConcealedKong = false;//暗杠
                        isWestWin = false;//胡

                        //清空吃碰杠状态
                        ui->statusWestChow->clear();
                        ui->statusWestPong->clear();
                        ui->statusWestKong->clear();
                        ui->statusWestWin->clear();
                        ui->statusWestCheck->clear();

                        //摸牌
                        draw();
                        //更新打牌玩家
                        updateDapaiWanjia();
                        //展示当前打牌位置
                        directionDisplay(dapaiWanjia);

                        //从弃牌堆拿走被吃的牌
                        for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                            if(iter->getId() == playedPai.begin()->getId()){
                                discardMjs.erase(iter);
                                break;
                            }
                        }
                        discardDisplay(discardMjs);
                    }
                    //过牌之后，重新进入自动打牌状态
                    if (systemConfig.AIPlayers>0)
                        AIPlay();
                    return true;// 该事件已经被处理
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }

        //撤回事件
        else if(obj == ui->gamePage){
            if(event->type() == QEvent::MouseButtonPress){
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::RightButton){
                    undoOperating();
                    return true;
                }
            }else{
                return false;
            }
        }
        else if(obj == ui->undoButton){//撤销操作
            if(event->type() == QEvent::MouseButtonPress){//鼠标按压
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if(mouseEvent->button() == Qt::LeftButton){
                    undoOperating();
                    return true;
                }
            }else{
                return false;
            }
        }


        else{
               return QWidget::eventFilter(obj, event);
           }


}
//撤销打牌操作
void UIMainWindows::undoOperating()
{

    stack<int> StackDapaiWanjia = dapaiWanjiaStack;
    while(!StackDapaiWanjia.empty()){
        StackDapaiWanjia.pop();
    }



    if(!dapaiWanjiaStack.empty() && dapaiWanjiaStack.size() != 1){
        //设置遮罩层(消失)
        ui->justTakenLabel->setStyleSheet(QString("background-color:rgba(0, 0, 0, 0%);"));
        ui->justTakenLabel->setGeometry(1130,20,10,10);

        //清空状态
        clearHandStatus();

        int tempDapaiWanjia = dapaiWanjiaStack.top();


        //重新选定打牌玩家
        dapaiWanjia = tempDapaiWanjia;

        //寻找刚摸起来的牌
        list<Mj>::iterator takenIter = majhongTaken.end();
        takenIter--;

        if(dapaiWanjiaStack.size() == playedPaiStack.size()){//打出牌，卡在吃碰杠胡的界面
          //清空吃碰杠胡
            isSouthChow = false;
            isNorthChow = false;
            isEastChow = false;
            isWestChow = false;

            chowType.clear();
            chowVec.clear();

            isSouthPong = false;
            isNorthPong = false;
            isEastPong = false;
            isWestPong = false;

            isSouthKong = false;
            isWestKong = false;
            isNorthKong = false;
            isEastKong = false;
            //抢杠胡
            isQiangganghu = false;
            qiangganghuElement[0].clear();
            qiangganghuElement[1].clear();
            qiangganghuElement[2].clear();
            qiangganghuElement[3].clear();
            qiangganghuPaiNum = 0;
            qiangganghuType = -1;

           isSouthWin = false;
           isEastWin = false;
           isNorthWin = false;
           isWestWin = false;

           isZimo = false;

            //清空手牌状态显示
           clearHandStatus();

           //寻找刚打出的牌
           Mj tempPlayedPai = playedPaiStack.top();
           dapaiWanjiaStack.pop();

           //刚打出的牌重新加回手牌
           if(dapaiWanjia == 0){
               handSouthMjs.push_back(tempPlayedPai);

               for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){//重新设置为刚摸来的牌
                   if(iter->getId() == takenIter->getId()){
                       iter->setLast(true);
                       break;
                   }
               }
               southHandDisplay(handSouthMjs);
           }else if(dapaiWanjia == 1){
               handEastMjs.push_back(tempPlayedPai);

               for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){//重新设置为刚摸来的牌
                   if(iter->getId() == takenIter->getId()){
                       iter->setLast(true);
                        break;
                   }
               }
               eastHandDisplay(handEastMjs);
           }else if(dapaiWanjia == 2){
               handNorthMjs.push_back(tempPlayedPai);

               for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){//重新设置为刚摸来的牌
                   if(iter->getId() == takenIter->getId()){
                       iter->setLast(true);
                        break;
                   }
               }
               northHandDisplay(handNorthMjs);
           }else if(dapaiWanjia == 3){
               handWestMjs.push_back(tempPlayedPai);

               for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){//重新设置为刚摸来的牌
                   if(iter->getId() == takenIter->getId()){
                       iter->setLast(true);
                        break;
                   }
               }
               westHandDisplay(handWestMjs);
           }
           //检测暗杠、听牌、摸牌
           if(systemConfig.angang == 1){
               isConcealedKong(handSouthMjs, 0);//检测暗杠
               if(concealedKongNum[0] != 0){
                  KongDisplay();
               }
           }

           //检测听牌
           clearReady();
           isReady();

           //检测胡牌
           isWin();

           //弃牌堆里删除刚打出的牌
           for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
               if(iter->getId() == tempPlayedPai.getId()){
                   discardMjs.erase(iter);
                   break;
               }
           }
           discardDisplay(discardMjs);

           //打出的手牌出栈
           playedPaiStack.pop();
           //展示打牌玩家
           directionDisplay(dapaiWanjia);
           //摸牌玩家重新计算
           mopaiWanjia = dapaiWanjia;
           updateMopaiWanjia();


        }else if(dapaiWanjiaStack.size() == playedPaiStack.size() + 1){//刚好到下一家摸起牌

            //撤回一(无任何吃碰杠)

            //假设摸起来的手牌来自上家的手牌
            bool isFoundHand = true;
            bool isFoundHand2 = false;//除了摸出去就打出去并且被碰的情况

            bool getConcealedKong = false;//暗杠判断
            bool getChow = false;
            bool getPong = false;

            //删除当前玩家摸起来的牌
            if(dapaiWanjia == 0){
               for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                    if(iter->getId() == takenIter->getId()){
                        handSouthMjs.erase(iter);
                        if(iter->getPaizhuangtai() != 1 && iter->getPaizhuangtai() != 4){
                            isFoundHand = false;
                        }
                        if(iter->getPaizhuangtai() == 1){
                            isFoundHand2 = true;
                        }
                        break;
                    }
               }
               southHandDisplay(handSouthMjs);
            }else if(dapaiWanjia == 1){
                for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                     if(iter->getId() == takenIter->getId()){
                         handEastMjs.erase(iter);
                         if(iter->getPaizhuangtai() != 1 && iter->getPaizhuangtai() != 4){
                             isFoundHand = false;
                         }
                         if(iter->getPaizhuangtai() == 1){
                             isFoundHand2 = true;
                         }
                         break;
                     }
                }
                eastHandDisplay(handEastMjs);
            }else if(dapaiWanjia == 2){
                for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                     if(iter->getId() == takenIter->getId()){
                         handNorthMjs.erase(iter);
                         if(iter->getPaizhuangtai() != 1 && iter->getPaizhuangtai() != 4){
                             isFoundHand = false;
                         }
                         if(iter->getPaizhuangtai() == 1){
                             isFoundHand2 = true;
                         }
                         break;
                     }
                }
                northHandDisplay(handNorthMjs);
            }else if(dapaiWanjia == 3){
                for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                     if(iter->getId() == takenIter->getId()){
                         handWestMjs.erase(iter);
                         if(iter->getPaizhuangtai() != 1 && iter->getPaizhuangtai() != 4){
                             isFoundHand = false;
                         }
                         if(iter->getPaizhuangtai() == 1){
                             isFoundHand2 = true;
                         }
                         break;
                     }
                }
                westHandDisplay(handWestMjs);
            }



            //寻找刚打出的牌
            Mj tempPlayedPai = playedPaiStack.top();

            //摸起来的牌来自其他家的手牌，还原吃、碰、放炮胡之前的状态
            if(isFoundHand == true){
                int cnt = 0;

                if(dapaiWanjia == 0){
                    //统计碰的个数
                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                        if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                            cnt++;                           
                        }
                    }
                    if(isFoundHand2 == true){
                        cnt++;
                    }

                    if(cnt == 3){
                       getPong = true;
                       for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                           if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                               iter->setPaizhuangtai(0);
                           }
                       }
                       handSouthIndex -= 3;
                    }

                    if(cnt != 3){
                        int chiType = -1; //吃牌的类型0（-1，+1），1（+1，+2），2（-1，-2）

                        int nPai1, nPai2;
                        int nId1, nId2;
                        bool isFound1, isFound2;
                        int paiValue = tempPlayedPai.getResult();


                        nPai1 = paiValue - 1;
                        nPai2 = paiValue + 1;
                        isFound1 = false;
                        isFound2 = false;

                        for(auto i:handSouthMjs){
                            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                isFound1 = true;
                                nId1 = i.getId();
                            }
                            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                isFound2 = true;
                                nId2 = i.getId();
                            }
                        }
                        if(isFound1 == true && isFound2 == true){
                           chiType = 0;
                           getChow = true;
                        }

                        if(chiType != 0){
                            nPai1 = paiValue + 1;
                            nPai2 = paiValue + 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handSouthMjs){
                                if(i.getResult() == nPai1  && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2  && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 1;
                                getChow = true;
                            }
                        }

                        if(chiType != 0 && chiType != 1){
                            nPai1 = paiValue - 1;
                            nPai2 = paiValue - 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handSouthMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2  && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 2;
                                getChow = true;
                            }
                        }

                        if(getChow == true){
                             for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 4){
                                    iter->setPaizhuangtai(0);//还原牌状态
                                    handSouthIndex -= 3;
                                    break;
                                }
                            }

                            for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                                    if(iter->getId() == nId1){
                                       iter->setPaizhuangtai(0);
                                    }
                                    if(iter->getId() == nId2){
                                       iter->setPaizhuangtai(0);
                                    }
                            }
                            //handSouthIndex -= 3;
                        }
                    }

                    if(getChow == false && getPong == false){//胡牌的牌
                        if(endWanjia.find(0) != endWanjia.end()){
                            endWanjia.erase(endWanjia.find(0));

                            for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                                 iter->setHu(false);
                            }
                        }

                    }

                    //删除吃碰杠杠上一家的牌
                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == tempPlayedPai.getId()){
                             handSouthMjs.erase(iter);
                             break;
                         }
                    }
                    
                    southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                        if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                            cnt++;
                        }
                    }
                    if(isFoundHand2 == true){
                        cnt++;
                    }
                    if(cnt == 3){

                       getPong = true;
                       for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                           if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                               iter->setPaizhuangtai(0);//还原牌状态
                               handEastIndex -= 3;
                           }
                       }
                       //handEastIndex -= 3;
                    }

                    if(cnt != 3){
                        int chiType = -1; //吃牌的类型0（-1，+1），1（+1，+2），2（-1，-2）
                        int nPai1, nPai2;
                        int nId1, nId2;
                        bool isFound1, isFound2;
                        int paiValue = tempPlayedPai.getResult();

                        nPai1 = paiValue - 1;
                        nPai2 = paiValue + 1;
                        isFound1 = false;
                        isFound2 = false;

                        for(auto i:handEastMjs){
                            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                isFound1 = true;
                                nId1 = i.getId();
                            }
                            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                isFound2 = true;
                                nId2 = i.getId();
                            }
                        }
                        if(isFound1 == true && isFound2 == true){
                           chiType = 0;
                           getChow = true;
                        }

                        if(chiType != 0){
                            nPai1 = paiValue + 1;
                            nPai2 = paiValue + 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handEastMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 1;
                                getChow = true;
                            }
                        }

                        if(chiType != 0 && chiType != 1){
                            nPai1 = paiValue - 1;
                            nPai2 = paiValue - 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handEastMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 2;
                                getChow = true;
                            }
                        }

                        if(getChow == true){
                            for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 4){
                                    iter->setPaizhuangtai(0);//还原牌状态
                                    handEastIndex -= 3;
                                    break;
                                }
                            }
                            for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                                    if(iter->getId() == nId1){
                                       iter->setPaizhuangtai(0);
                                    }
                                    if(iter->getId() == nId2){
                                       iter->setPaizhuangtai(0);
                                    }
                            }
                            //handEastIndex -= 3;
                        }
                    }

                    if(getChow == false && getPong == false){//胡牌的牌
                        if(endWanjia.find(1) != endWanjia.end()){
                            endWanjia.erase(endWanjia.find(1));

                            for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                                 iter->setHu(false);
                            }
                        }

                    }

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == tempPlayedPai.getId()){
                             handEastMjs.erase(iter);
                             break;
                         }
                    }

                    eastHandDisplay(handEastMjs);

                }else if(dapaiWanjia == 2){
                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                        if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                            cnt++;
                            iter->setPaizhuangtai(0);//还原牌状态
                        }
                    }
                    if(isFoundHand2 == true){
                        cnt++;
                    }

                    if(cnt == 3){
                       getPong = true;
                       for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                           if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                               iter->setPaizhuangtai(0);//还原牌状态
                               handNorthIndex -= 3;
                           }
                       }
                       //handNorthIndex -= 3;
                    }

                    if(cnt != 3){
                        int chiType = -1; //吃牌的类型0（-1，+1），1（+1，+2），2（-1，-2）

                        int nPai1, nPai2;
                        int nId1, nId2;
                        bool isFound1, isFound2;
                        int paiValue = tempPlayedPai.getResult();


                        nPai1 = paiValue - 1;
                        nPai2 = paiValue + 1;
                        isFound1 = false;
                        isFound2 = false;

                        for(auto i:handNorthMjs){
                            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                isFound1 = true;
                                nId1 = i.getId();
                            }
                            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                isFound2 = true;
                                nId2 = i.getId();
                            }
                        }
                        if(isFound1 == true && isFound2 == true){
                           chiType = 0;
                           getChow = true;
                        }

                        if(chiType != 0){
                            nPai1 = paiValue + 1;
                            nPai2 = paiValue + 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handNorthMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 1;
                                getChow = true;
                            }
                        }

                        if(chiType != 0 && chiType != 1){
                            nPai1 = paiValue - 1;
                            nPai2 = paiValue - 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handNorthMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 2;
                                getChow = true;
                            }
                        }

                        if(getChow == true){
                            for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 4){
                                    iter->setPaizhuangtai(0);//还原牌状态
                                    handNorthIndex -= 3;
                                }
                            }

                            for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                                    if(iter->getId() == nId1){
                                       iter->setPaizhuangtai(0);
                                    }
                                    if(iter->getId() == nId2){
                                       iter->setPaizhuangtai(0);
                                    }
                            }
                            //handNorthIndex -= 3;
                        }
                    }

                    if(getChow == false && getPong == false){//胡牌的牌
                        if(endWanjia.find(2) != endWanjia.end()){
                            endWanjia.erase(endWanjia.find(2));

                            for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                                 iter->setHu(false);
                            }
                        }

                    }

                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == tempPlayedPai.getId()){
                             handNorthMjs.erase(iter);
                             break;
                         }
                    }

                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){

                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                        if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                            cnt++;
                            iter->setPaizhuangtai(0);//还原牌状态
                        }
                    }
                    if(isFoundHand2 == true){
                        cnt++;
                    }

                    if(cnt == 3){
                       getPong = true;
                       for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                           if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 1){
                               iter->setPaizhuangtai(0);//还原牌状态
                               handWestIndex -= 3;
                           }
                       }
                        //handWestIndex -= 3;
                    }

                    if(cnt != 3){
                        int chiType = -1; //吃牌的类型0（-1，+1），1（+1，+2），2（-1，-2）

                        int nPai1, nPai2;
                        int nId1, nId2;
                        bool isFound1, isFound2;
                        int paiValue = tempPlayedPai.getResult();


                        nPai1 = paiValue - 1;
                        nPai2 = paiValue + 1;
                        isFound1 = false;
                        isFound2 = false;

                        for(auto i:handWestMjs){
                            if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                isFound1 = true;
                                nId1 = i.getId();
                            }
                            if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                isFound2 = true;
                                nId2 = i.getId();
                            }
                        }
                        if(isFound1 == true && isFound2 == true){
                           chiType = 0;
                            getChow = true;
                        }

                        if(chiType != 0){
                            nPai1 = paiValue + 1;
                            nPai2 = paiValue + 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handWestMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 1;
                                 getChow = true;
                            }
                        }

                        if(chiType != 0 && chiType != 1){
                            nPai1 = paiValue - 1;
                            nPai2 = paiValue - 2;
                            isFound1 = false;
                            isFound2 = false;

                            for(auto i:handWestMjs){
                                if(i.getResult() == nPai1 && i.getPaizhuangtai() == 4 && isFound1 == false){
                                    isFound1 = true;
                                    nId1 = i.getId();
                                }
                                if(i.getResult() == nPai2 && i.getPaizhuangtai() == 4 && isFound2 == false){
                                    isFound2 = true;
                                    nId2 = i.getId();
                                }
                            }
                            if(isFound1 == true && isFound2 == true){
                                chiType = 2;
                                 getChow = true;
                            }
                        }

                        if(getChow == true){
                            for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                               if(iter->getResult() == tempPlayedPai.getResult() && iter->getPaizhuangtai() == 4){
                                   iter->setPaizhuangtai(0);//还原牌状态
                                   handWestIndex -= 3;
                                   break;
                               }
                           }

                            for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                                    if(iter->getId() == nId1){
                                       iter->setPaizhuangtai(0);
                                    }
                                    if(iter->getId() == nId2){
                                       iter->setPaizhuangtai(0);
                                    }
                            }
                            //handWestIndex -= 3;
                        }
                    }

                    if(getChow == false && getPong == false){//胡牌的牌
                        if(endWanjia.find(3) != endWanjia.end()){
                            endWanjia.erase(endWanjia.find(3));

                            for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                                 iter->setHu(false);
                            }
                        }
                    }

                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == tempPlayedPai.getId()){
                             handWestMjs.erase(iter);
                             break;
                         }
                    }

                    westHandDisplay(handWestMjs);
                }
            }

            int tempDapaiWanjia2 = dapaiWanjia;//暂存现在打牌玩家
            dapaiWanjiaStack.pop();
            dapaiWanjia = dapaiWanjiaStack.top();//变更为上一个打牌玩家
            dapaiWanjiaStack.pop();//上一个打牌玩家出栈

            if(tempDapaiWanjia2 == dapaiWanjia){
                getConcealedKong  = true;
            }

            int dapaiWanjiaCnt[4];//每个方向打牌玩家的轮到次数
            std::memset(dapaiWanjiaCnt, 0, sizeof(dapaiWanjiaCnt));
            //缺一门，判断是否是确认缺门的回合
            if(systemConfig.queyimen == 1){
                stack<int> tempDapaiWanjiaStack = dapaiWanjiaStack;
                int tempDapaiWanjia3;

                while(!tempDapaiWanjiaStack.empty()){
                    tempDapaiWanjia3 = tempDapaiWanjiaStack.top();
                    tempDapaiWanjiaStack.pop();
                    dapaiWanjiaCnt[tempDapaiWanjia3]++;
                }
             }


            if(isFoundHand == false){//摸起来的手牌来自牌墙

                //放回牌堆
                takenIter->setPaizhuangtai(0);
                takenIter->setIsque(false);
                takenIter->setLast(false);

                //剩余的牌再重新加入摸起来的牌
                majhongRemain.push_back(*takenIter);
                //删除刚摸牌来的牌                
                majhongTaken.pop_back();
                //更新刚摸起来的牌
                takenIter = majhongTaken.end();
                takenIter--;

                if(tempDapaiWanjia2 == 0){
                        int kongCnt = 0;
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                            if(iter->getResult() == tempPlayedPai.getResult()){
                                kongCnt++;
                            }
                        }
                        if(kongCnt == 4){//是碰杠
                            for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   iter->setPaizhuangtai(0);
                                }
                            }
                            //删除明杠的牌
                            for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   handSouthMjs.erase(iter);
                                   break;
                                }
                            }

                            handSouthIndex -= 4;
                            southHandDisplay(handSouthMjs);
                        }

                }else if(tempDapaiWanjia2 == 1){
                        int kongCnt = 0;
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                            if(iter->getResult() == tempPlayedPai.getResult()){
                                kongCnt++;
                            }
                        }

                        if(kongCnt == 4){//是碰杠

                            for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   iter->setPaizhuangtai(0);
                                }
                            }
                            //删除明杠的牌
                            for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   handEastMjs.erase(iter);
                                   break;
                                }
                            }

                            handEastIndex -= 4;
                            eastHandDisplay(handEastMjs);

                        }

                }else if(tempDapaiWanjia2 == 2){

                        int kongCnt = 0;
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                            if(iter->getResult() == tempPlayedPai.getResult()){
                                kongCnt++;
                            }
                        }

                        if(kongCnt == 4){//是碰杠
                            for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   iter->setPaizhuangtai(0);
                                }
                            }
                            //删除明杠的牌
                            for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   handNorthMjs.erase(iter);
                                   break;
                                }
                            }

                            handNorthIndex -= 4;
                            northHandDisplay(handNorthMjs);

                        }

                }else if(tempDapaiWanjia2 == 3){

                        int kongCnt = 0;
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                            if(iter->getResult() == tempPlayedPai.getResult()){
                                kongCnt++;
                            }
                        }

                        if(kongCnt == 4){//是碰杠
                            for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   iter->setPaizhuangtai(0);
                                }
                            }
                            //删除明杠的牌
                            for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                                if(iter->getResult() == tempPlayedPai.getResult()){
                                   handWestMjs.erase(iter);
                                   break;
                                }
                            }

                            handWestIndex -= 4;
                            westHandDisplay(handWestMjs);

                        }
                    }

                //寻找刚打出的牌
                Mj tempPlayedPai = playedPaiStack.top();

                //刚打出的牌重新加回手牌
                if(dapaiWanjia == 0){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[0] == 0){
                        southQue = -10;
                        isSouthQue = true;
                    }

                    handSouthMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                            break;
                        }
                    }                         

                   if(getConcealedKong == true){

                            pair<int, int> kongPair = southKongStack.top();
                            int kongNum = kongPair.first;
                            if(kongPair.second == 0){//全部手牌杠
                                for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                                    if(iter->getResult() == kongNum){
                                        iter->setPaizhuangtai(0);
                                    }
                                }
                            }else if(kongPair.second == 1){//碰杠
                                for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                                    if(iter->getResult() == kongNum){
                                        iter->setPaizhuangtai(0);
                                        break;
                                    }
                                }
                            }
                            handSouthIndex -= 4;

                        }

                    southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[1] == 0){
                        eastQue = -10;
                        isEastQue = true;
                    }

                    handEastMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                             break;
                        }
                    }

                    //还原暗杠
                    if(getConcealedKong == true){
                          pair<int, int> kongPair = eastKongStack.top();
                          int kongNum = kongPair.first;
                          if(kongPair.second == 0){//全部手牌杠
                              for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                                  if(iter->getResult() == kongNum){
                                      iter->setPaizhuangtai(0);
                                  }
                              }
                          }else if(kongPair.second == 1){//碰杠
                              for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                                  if(iter->getResult() == kongNum){
                                      iter->setPaizhuangtai(0);
                                      break;
                                  }
                              }
                          }
                           handEastIndex -= 4;
                    }

                    eastHandDisplay(handEastMjs);
                }else if(dapaiWanjia == 2){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[2] == 0){
                        northQue = -10;
                        isNorthQue = true;
                    }

                    handNorthMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                             break;
                        }
                    }

                    //还原暗杠
                    if(getConcealedKong == true){
                          pair<int, int> kongPair = northKongStack.top();
                          int kongNum = kongPair.first;
                          if(kongPair.second == 0){//全部手牌杠
                              for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                                  if(iter->getResult() == kongNum){
                                      iter->setPaizhuangtai(0);
                                  }
                              }
                          }else if(kongPair.second == 1){//碰杠
                              for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                                  if(iter->getResult() == kongNum){
                                      iter->setPaizhuangtai(0);
                                      break;
                                  }
                              }
                          }
                          handNorthIndex -= 4;
                    }

                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[3] == 0){
                        westQue = -10;
                        isWestQue = true;
                    }

                    handWestMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                             break;
                        }
                    }

                    //还原暗杠
                    if(getConcealedKong == true){
                          pair<int, int> kongPair = westKongStack.top();
                          int kongNum = kongPair.first;
                          if(kongPair.second == 0){//全部手牌杠
                              for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                                  if(iter->getResult() == kongNum){
                                      iter->setPaizhuangtai(0);
                                  }
                              }
                          }else if(kongPair.second == 1){//碰杠
                              for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                                  if(iter->getResult() == kongNum){
                                      iter->setPaizhuangtai(0);
                                      break;
                                  }
                              }
                          }
                           handWestIndex -= 4;
                    }

                    westHandDisplay(handWestMjs);
                }

                //弃牌堆里删除刚打出的牌
                for(list<Mj>::iterator iter = discardMjs.begin();iter != discardMjs.end();iter++){
                    if(iter->getId() == tempPlayedPai.getId()){
                        discardMjs.erase(iter);
                        break;
                    }
                }
                discardDisplay(discardMjs);

                //打出的手牌出栈
                playedPaiStack.pop();

                //展示打牌玩家
                directionDisplay(dapaiWanjia);
                //摸牌玩家重新计算
                mopaiWanjia = dapaiWanjia;
                updateMopaiWanjia();

                //回退摸牌位置
                undoPai();
                //预测牌
                yucePai();
            }else{//摸起来的牌来自其他玩家

                //刚打出的牌重新加回手牌
                if(dapaiWanjia == 0){
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[0] == 0){
                        southQue = -10;
                        isSouthQue = true;
                    }

                    handSouthMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                            break;
                        }
                    }
                    southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[1] == 0){
                        eastQue = -10;
                        isEastQue = true;
                    }

                    handEastMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                             break;
                        }
                    }
                    eastHandDisplay(handEastMjs);
                }else if(dapaiWanjia == 2){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[2] == 0){
                        northQue = -10;
                        isNorthQue = true;
                    }

                    handNorthMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                             break;
                        }
                    }
                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){
                    //重置缺门信息
                    if(systemConfig.queyimen == 1 && dapaiWanjiaCnt[3] == 0){
                        westQue = -10;
                        isWestQue = true;
                    }

                    handWestMjs.push_back(tempPlayedPai);

                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){//重新设置为刚摸来的牌
                        if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                             break;
                        }
                    }
                    westHandDisplay(handWestMjs);
                }

                //打出的手牌出栈
                playedPaiStack.pop();
                //展示打牌玩家
                directionDisplay(dapaiWanjia);
                //摸牌玩家重新计算
                mopaiWanjia = dapaiWanjia;
                updateMopaiWanjia();
                //回退摸牌位置
              //  undoPai();
                //预测
                yuceDirection  = mopaiDirection;
                yucePos = mopaiPos;
                yuceCeng = mopaiCeng;
                //预测牌
                yucePai();

            }

        }else if(dapaiWanjiaStack.size() == playedPaiStack.size() + 2){//自摸胡+暗杠判断

            bool getConcealedKong = false;//暗杠判断

            int tempDapaiWanjia2 = dapaiWanjia;//暂存现在打牌玩家
            dapaiWanjiaStack.pop();
            dapaiWanjia = dapaiWanjiaStack.top();//变更为上一个打牌玩家
            dapaiWanjiaStack.pop();//上一个打牌玩家出栈

            if(tempDapaiWanjia2 == dapaiWanjia){
                    getConcealedKong  = true;
            }

            if(getConcealedKong == true){

                if(dapaiWanjia == 0){
                    pair<int, int> kongPair = southKongStack.top();
                    southKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }

                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handSouthMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }


                    handSouthIndex -= 4;
                    southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){
                    //还原暗杠
                    pair<int, int> kongPair = eastKongStack.top();
                    eastKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                     //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handEastMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                    handEastIndex -= 4;
                    eastHandDisplay(handEastMjs);
                }else if(dapaiWanjia == 2){
                    pair<int, int> kongPair = northKongStack.top();
                    northKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handNorthMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                   for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                    handNorthIndex -= 4;
                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){
                    pair<int, int> kongPair = westKongStack.top();
                    westKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handWestMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                   for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                     handWestIndex -= 4;
                     westHandDisplay(handWestMjs);
                }
                //展示打牌玩家
                directionDisplay(dapaiWanjia);

                //回退摸牌位置
                undoPai();
                //预测牌
                yucePai();
            }
            else{//自摸胡回退
                dapaiWanjiaStack.push(dapaiWanjia);//回退打牌玩家
                dapaiWanjiaStack.push(tempDapaiWanjia2);//回退打牌玩家
                dapaiWanjia = tempDapaiWanjia2;

                //自摸
                //删除当前玩家摸起来的牌
                if(dapaiWanjia == 0){
                   for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                        if(iter->getId() == takenIter->getId()){
                            handSouthMjs.erase(iter);
                            break;
                        }
                   }
                   southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){
                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handEastMjs.erase(iter);
                             break;
                         }
                    }
                    eastHandDisplay(handEastMjs);
                }else if(dapaiWanjia == 2){
                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handNorthMjs.erase(iter);
                             break;
                         }
                    }
                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){
                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handWestMjs.erase(iter);
                             break;
                         }
                    }
                    westHandDisplay(handWestMjs);
                }

                //剩余的牌再重新加入摸起来的牌
                majhongRemain.push_back(*takenIter);
                //摸牌来的牌重新放回
                majhongTaken.pop_back();
                //更新刚摸起来的牌
                takenIter = majhongTaken.end();
                takenIter--;


                dapaiWanjiaStack.pop();
                dapaiWanjia = dapaiWanjiaStack.top();//变更为上一个打牌玩家
                dapaiWanjiaStack.pop();//上一个打牌玩家出栈

                if(dapaiWanjia == 0){
                    endWanjia.erase(endWanjia.find(0));
                   for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                       iter->setHu(false);
                       if(iter->getId() == takenIter->getId()){
                            iter->setLast(true);
                       }
                   }
                   southHandDisplay(handSouthMjs);
                   ui->huSouth->clear();//胡表示消失
                }else if(dapaiWanjia == 1){
                    endWanjia.erase(endWanjia.find(1));
                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                        iter->setHu(false);
                        if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                        }
                    }
                     eastHandDisplay(handEastMjs);
                     ui->huEast->clear();//胡表示消失
                }else if(dapaiWanjia == 2){
                    endWanjia.erase(endWanjia.find(2));
                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                        iter->setHu(false);
                        if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                        }
                    }
                     northHandDisplay(handNorthMjs);
                    ui->huNorth->clear();//胡表示消失
                }else if(dapaiWanjia == 3){
                    endWanjia.erase(endWanjia.find(3));
                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                        iter->setHu(false);
                        if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                        }
                    }
                     westHandDisplay(handWestMjs);
                     ui->huWest->clear();//胡表示消失
                }

                //检测听牌
                clearReady();
                isReady();

                //检测胡牌
                isWin();

                //展示打牌玩家
                directionDisplay(dapaiWanjia);
                //摸牌玩家重新计算
                mopaiWanjia = dapaiWanjia;
                updateMopaiWanjia();


            }
        }else if(dapaiWanjiaStack.size() == playedPaiStack.size() + 3){//两个暗杠
            bool getConcealedKong = false;//暗杠判断

            int tempDapaiWanjia2 = dapaiWanjia;//暂存现在打牌玩家
            dapaiWanjiaStack.pop();
            dapaiWanjia = dapaiWanjiaStack.top();//变更为上一个打牌玩家
            dapaiWanjiaStack.pop();//上一个打牌玩家出栈
            if(tempDapaiWanjia2 == dapaiWanjia){
                    getConcealedKong  = true;
            }

            if(getConcealedKong == true){
                if(dapaiWanjia == 0){
                    pair<int, int> kongPair = southKongStack.top();
                    southKongStack.pop();

                    int kongNum = kongPair.first;

                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }

                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handSouthMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }


                    handSouthIndex -= 4;
                    southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){
                    //还原暗杠
                    pair<int, int> kongPair = eastKongStack.top();
                    eastKongStack.pop();
                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                     //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handEastMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                    handEastIndex -= 4;
                    eastHandDisplay(handEastMjs);
                }else if(dapaiWanjia == 2){
                    pair<int, int> kongPair = northKongStack.top();
                    northKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handNorthMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                   for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                    handNorthIndex -= 4;
                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){
                    pair<int, int> kongPair = westKongStack.top();
                    westKongStack.pop();
                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handWestMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                   for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                     handWestIndex -= 4;
                     westHandDisplay(handWestMjs);
                }
                //展示打牌玩家
                directionDisplay(dapaiWanjia);

                //回退摸牌位置
                undoPai();
                //预测牌
                yucePai();
            }

        }else if(dapaiWanjiaStack.size() == playedPaiStack.size() + 4){//三个暗杠
            bool getConcealedKong = false;//暗杠判断

            int tempDapaiWanjia2 = dapaiWanjia;//暂存现在打牌玩家
            dapaiWanjiaStack.pop();
            dapaiWanjia = dapaiWanjiaStack.top();//变更为上一个打牌玩家
            dapaiWanjiaStack.pop();//上一个打牌玩家出栈
            if(tempDapaiWanjia2 == dapaiWanjia){
                    getConcealedKong  = true;
            }

            if(getConcealedKong == true){
                if(dapaiWanjia == 0){

                    pair<int, int> kongPair = southKongStack.top();
                    southKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }

                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handSouthMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                    for(list<Mj>::iterator iter = handSouthMjs.begin(); iter != handSouthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }


                    handSouthIndex -= 4;
                    southHandDisplay(handSouthMjs);
                }else if(dapaiWanjia == 1){
                    //还原暗杠
                    pair<int, int> kongPair = eastKongStack.top();
                    eastKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                     //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handEastMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                    for(list<Mj>::iterator iter = handEastMjs.begin(); iter != handEastMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                    handEastIndex -= 4;
                    eastHandDisplay(handEastMjs);
                }else if(dapaiWanjia == 2){
                    pair<int, int> kongPair = northKongStack.top();
                    northKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handNorthMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                   for(list<Mj>::iterator iter = handNorthMjs.begin(); iter != handNorthMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                    handNorthIndex -= 4;
                    northHandDisplay(handNorthMjs);
                }else if(dapaiWanjia == 3){
                    pair<int, int> kongPair = westKongStack.top();
                    westKongStack.pop();

                    int kongNum = kongPair.first;
                    if(kongPair.second == 0){//全部手牌杠
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                            }
                        }
                    }else if(kongPair.second == 1){//碰杠
                        for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end(); iter++){
                            if(iter->getResult() == kongNum){
                                iter->setPaizhuangtai(0);
                                break;
                            }
                        }
                    }
                    //删除杠拿起来的手牌
                    for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             handWestMjs.erase(iter);
                             break;
                         }
                    }

                    takenIter->setPaizhuangtai(0);
                    takenIter->setIsque(false);
                    takenIter->setLast(false);
                    majhongRemain.push_back(*takenIter);
                    majhongTaken.pop_back();
                    takenIter = majhongTaken.end();
                    takenIter--;

                   for(list<Mj>::iterator iter = handWestMjs.begin(); iter != handWestMjs.end();iter++){
                         if(iter->getId() == takenIter->getId()){
                             iter->setLast(true);
                             break;
                         }
                    }

                     handWestIndex -= 4;
                     westHandDisplay(handWestMjs);
                }

                //展示打牌玩家
                directionDisplay(dapaiWanjia);


                //回退摸牌位置
                undoPai();
                //预测牌
                yucePai();
            }
        }

    }

}

//洗牌
void UIMainWindows::on_xipaiButton_clicked()
{   

    //清空上一把遗留数据
     majhongTotal.clear();
     majhongRemain.clear();

     drawWestMjs.clear();
     drawSouthMjs.clear();
     drawEastMjs.clear();
     drawNorthMjs.clear();

     //清空所有变量
     clearVariable();

     //清空面板
     clearPanel();

    QString zhangshuStr = ui->countComboBox->currentText();//获得选择的张数
    int zhangshu = zhangshuStr.toInt();//转换为int

    config.setMJ_COUNT(zhangshu);//设置张数
    config.xipai(majhongTotal);

    majhongRemain = majhongTotal;

    if(zhangshu == 136){
        int cnt = 0;
        for(auto i: majhongTotal){
            if(cnt < 34){
                drawNorthMjs.push_back(i);
            }
            if(cnt < 68 && cnt >= 34){
                drawEastMjs.push_back(i);
            }
            if(cnt < 102 && cnt >= 68){
                drawSouthMjs.push_back(i);
            }
            if(cnt < 136 && cnt >= 102){
                drawWestMjs.push_back(i);
            }
            cnt++;
        }

        initWestDrawDisplay(drawWestMjs, 34);
        initEastDrawDisplay(drawEastMjs, 34);
        initNorthDrawDisplay(drawNorthMjs, 34);
        initSouthDrawDisplay(drawSouthMjs, 34);

        zhangshuSouth = 34;
        zhangshuWest = 34;
        zhangshuNorth = 34;
        zhangshuEast = 34;

    }else if(zhangshu == 108){

        int cnt = 0;
        for(auto i: majhongTotal){
            if(cnt < 28){
                drawNorthMjs.push_back(i);
            }
            if(cnt < 54 && cnt >= 28){
                drawEastMjs.push_back(i);
            }
            if(cnt < 82 && cnt >= 54){
                drawSouthMjs.push_back(i);
            }
            if(cnt < 108 && cnt >= 82){
                drawWestMjs.push_back(i);
            }
            cnt++;
        }


        //清空136张牌残留的多余位置的信息（如15、16、17位）
        clear136Information();

        //显示牌
        initNorthDrawDisplay(drawNorthMjs, 28);
        initEastDrawDisplay(drawEastMjs, 26);
        initSouthDrawDisplay(drawSouthMjs, 28);
        initWestDrawDisplay(drawWestMjs, 26);        

        //每个方向的张数分配
        zhangshuNorth = 28;
        zhangshuEast = 26;
        zhangshuSouth = 28;               
        zhangshuWest = 26;

    }

    bankerDisplay();//庄家显示（获得起始打牌玩家）
    //获得配置信息
    getConfig();

    isBeginGame = true;//开始游戏

}

//随机打乱list顺序
template <class T>
void shuffle(list<T>& List) {
    vector<T> tempList;
    for(auto i:List){
        tempList.push_back(i);
    }

    std::random_shuffle(tempList.begin(), tempList.end());

    List.clear();
    for(auto i: tempList){
        List.push_back(i);
    }
}

//麻将牌初始化
void Config::xipai(list<Mj>& mjs) {//洗牌函数

   if(MJ_COUNT == 72){
       for(int i = 0; i < 4; i++){
           for(int j = 11;j <= 19; j++){//筒
               Mj mj;
               mj.setResult(j);
               mjs.push_back(mj);
           }
           for(int j = 21;j <= 29; j++){//条
               Mj mj;
               mj.setResult(j);
               mjs.push_back(mj);
           }
       }
       shuffle(mjs);
   }else if(MJ_COUNT == 90){

   }else if(MJ_COUNT == 108){
       int id = 0;

       for(int i = 0; i < 4; i++){
           for(int j = 1;j <= 9; j++){
               Mj mj;
               mj.setResult(j);
               mj.setId(id++);
               mjs.push_back(mj);
           }
           for(int j = 11;j <= 19; j++){
               Mj mj;
               mj.setResult(j);
                mj.setId(id++);
               mjs.push_back(mj);
           }
           for(int j = 21;j <= 29; j++){
               Mj mj;
               mj.setResult(j);
               mj.setId(id++);
               mjs.push_back(mj);
           }
       }
       shuffle(mjs);

   }else if(MJ_COUNT == 112){

   }else if(MJ_COUNT == 136){
        int id = 0;

       for(int i = 0; i < 4; i++){
           for(int j = 1;j <= 9; j++){
               Mj mj;
               mj.setResult(j);
               mj.setId(id++);
               mjs.push_back(mj);
           }
           for(int j = 11;j <= 19; j++){
               Mj mj;
               mj.setResult(j);
               mj.setId(id++);
               mjs.push_back(mj);
           }
           for(int j = 21;j <= 29; j++){
               Mj mj;
               mj.setResult(j);
               mj.setId(id++);
               mjs.push_back(mj);
           }
           for(int j = 31;j <= 37; j++){
               Mj mj;
               mj.setResult(j);
               mj.setId(id++);
               mjs.push_back(mj);
           }
       }

       shuffle(mjs);
   }else if(MJ_COUNT == 144){

   }else if(MJ_COUNT == 152){

   }
}

//麻将牌和序号对应关系
void UIMainWindows::printMajhongData(int data)
{
    if(data == 1){
        //qDebug()<<"1万";
    }else if(data == 2){
        //qDebug()<<"2万";
    }else if(data == 3){
        //qDebug()<<"3万";
    }else if(data == 4){
        //qDebug()<<"4万";
    }else if(data == 5){
        //qDebug()<<"5万";
    }else if(data == 6){
        //qDebug()<<"6万";
    }else if(data == 7){
        //qDebug()<<"7万";
    }else if(data == 8){
        //qDebug()<<"8万";
    }else if(data == 9){
        //qDebug()<<"9万";
    }else if(data == 11){
        //qDebug()<<"1条";
    }else if(data == 12){
        //qDebug()<<"2条";
    }else if(data == 13){
        //qDebug()<<"3条";
    }else if(data == 14){
        //qDebug()<<"4条";
    }else if(data == 15){
        //qDebug()<<"5条";
    }else if(data == 16){
        //qDebug()<<"6条";
    }else if(data == 17){
        //qDebug()<<"7条";
    }else if(data == 18){
        //qDebug()<<"8条";
    }else if(data == 19){
        //qDebug()<<"9条";
    }else if(data == 21){
        //qDebug()<<"1筒";
    }else if(data == 22){
        //qDebug()<<"2筒";
    }else if(data == 23){
        //qDebug()<<"3筒";
    }else if(data == 24){
        //qDebug()<<"4筒";
    }else if(data == 25){
        //qDebug()<<"5筒";
    }else if(data == 26){
        //qDebug()<<"6筒";
    }else if(data == 27){
        //qDebug()<<"7筒";
    }else if(data == 28){
        //qDebug()<<"8筒";
    }else if(data == 29){
        //qDebug()<<"9筒";
    }else if(data == 31){
        //qDebug()<<"东";
    }else if(data == 32){
        //qDebug()<<"南";
    }else if(data == 33){
        //qDebug()<<"西";
    }else if(data == 34){
        //qDebug()<<"北";
    }else if(data == 35){
        //qDebug()<<"中";
    }else if(data == 36){
        //qDebug()<<"发";
    }else if(data == 37){
        //qDebug()<<"白";
    }
}

//开始游戏（获得游戏设定，显示庄家方向）
void UIMainWindows::on_startGameButton_clicked()
{
    //清空上一把遗留数据
     majhongTotal.clear();
     majhongRemain.clear();

     drawWestMjs.clear();
     drawSouthMjs.clear();
     drawEastMjs.clear();
     drawNorthMjs.clear();

     //每个方向的张数分配
     zhangshuSouth = 26;
     zhangshuWest = 28;
     zhangshuNorth = 26;
     zhangshuEast = 28;

     bool isAdd = false;
     int majhongCount = 0;

     for(int i = 0; i < zhangshuSouth;i++){
        Mj mj;
        drawSouthMjs.push_back(mj);
     }
     for(int i = 0; i < zhangshuWest;i++){
        Mj mj;
        drawWestMjs.push_back(mj);
     }
     for(int i = 0; i < zhangshuNorth;i++){
        Mj mj;
        drawNorthMjs.push_back(mj);
     }
     for(int i = 0; i < zhangshuEast;i++){
        Mj mj;
        drawEastMjs.push_back(mj);
     }

     int majhongNumCount = 0;
     int drawIndex = 0;
     while(majhongNumCount < 108){
         int paiNum = majhongNumTotal[majhongNumCount];

         if(majhongNumCount == 26 || majhongNumCount == 54 || majhongNumCount == 80 || majhongNumCount == 108){
             drawIndex = 0;
         }

         if(majhongNumCount < 26){
             if(isAdd == false){
                 isAdd = true;
                 drawSouthMjs[drawIndex + zhangshuSouth/2].setResult(paiNum);
                 majhongCount++;
             }else{
                 isAdd = false;
                 drawSouthMjs[drawIndex].setResult(paiNum);
                 drawIndex++;
                 majhongCount++;
             }
         }

         if(majhongNumCount < 54 && majhongNumCount >= 26){
             if(isAdd == false){
                 isAdd = true;
                 drawWestMjs[drawIndex + zhangshuWest/2].setResult(paiNum);
                 majhongCount++;
             }else{
                 isAdd = false;
                 drawWestMjs[drawIndex].setResult(paiNum);
                 drawIndex++;
                 majhongCount++;
             }
         }

         if(majhongNumCount < 80 && majhongNumCount >= 54){
             if(isAdd == false){
                 isAdd = true;
                 drawNorthMjs[drawIndex + zhangshuNorth/2].setResult(paiNum);
                 majhongCount++;
             }else{
                 isAdd = false;
                 drawNorthMjs[drawIndex].setResult(paiNum);
                 drawIndex++;
                 majhongCount++;
             }
         }

         if(majhongNumCount < 108 && majhongNumCount >= 80){
             if(isAdd == false){
                 isAdd = true;
                 drawEastMjs[drawIndex + zhangshuEast/2].setResult(paiNum);
                 majhongCount++;
             }else{
                 isAdd = false;
                 drawEastMjs[drawIndex].setResult(paiNum);
                 drawIndex++;
                 majhongCount++;
             }
         }
         majhongNumCount++;
     }



    //清空136张牌残留的多余位置的信息（如15、16、17位）
    clear136Information();

    initSouthDrawDisplay(drawSouthMjs, 26);
    initWestDrawDisplay(drawWestMjs, 28);
    initNorthDrawDisplay(drawNorthMjs, 26);
    initEastDrawDisplay(drawEastMjs, 28);

    bankerDisplay();//庄家显示（获得起始打牌玩家）
    //获得配置信息
    getConfig();

    isBeginGame = true;//开始游戏
}

//结束游戏
void UIMainWindows::on_endGameButton_clicked()
{
    endGame();
    clearVariable();
    //清空积分
    clearScore();
    setScoreTxt();
}


///胡牌算法
//unordered_map按值排序（先转vector，排序后再存进去）
bool cmpByValue(const pair<int, int>& l, const pair<int, int>& r)
{
    return l.second > r.second;
}

bool cmpByKey(const pair<int, int>& l, const pair<int, int>& r){
    return l.first > r.first;
}

template<> struct std::greater<Mj>
        {
        bool operator()(Mj x,  Mj y) const{// 重载运算符
            double r0= x.getResult();
            double r1= y.getResult();

            if(r0==56.0){
                r0=10.0;
            }if(r1==56.0){
                r1=10.0;
            }

            if(r0==57.0){
                r0=30.0;
            }if(r1==57.0){
                r1=30.0;
            }

            if(r0==58.0){
                r0=20.0;
            }if(r1==58.0){
                r1=20.0;
            }

            if(r0==52.0){
                r0=38.0;
            }if(r1==52.0){
                r1=38.0;
            }
            if(r0==53.0){
                r0=34.5;
            }
            if(r1==53.0){
                r1=34.5;
            }

            double r = (r0 - r1);

            if(r > 0){
                return 1;
            }
            if(r < 0){
                return -1;
            }
            return 0;
            }
        };

//在unordered_map中按键搜索，找到返回值，找不到返回默认值
int getOrDefault(const unordered_map<int, int>& mp, const int findKey,const int defaultValue){
    if(mp.find(findKey) != mp.end()){
        return mp.find(findKey)->second;
    }else{
        return defaultValue;
    }
}

void deleteList(list<Mj>& suanpai, Mj mj){
    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end();) {
        if(*i == mj){
           i = suanpai.erase(i);
            break;
        }else{
            i++;
        }
    }
}

//胡牌判定
bool UIMainWindows::HuPaiPanDin(std::list<Mj> mahs, int que, SystemConfig systemConfig)
{
    //缺一门
    if (systemConfig.queyimen == 1) {
        for (Mj mj : mahs) {
            if (mj.getIsque() == true && mj.isCaisheng() == false) {
                return false;
            }
        }
    }

    list<Mj> pais = mahs;
//先剔除碰 杠的牌
    list<Mj>::iterator iterator = pais.begin();
    while (iterator != pais.end()) {
        if (iterator->getPaizhuangtai() == 1 || iterator->getPaizhuangtai() == 2 || iterator->getPaizhuangtai() == 3 || iterator->getPaizhuangtai() == 4) {
            iterator = pais.erase(iterator);
        }else{
             iterator++;
        }

    }
    if (pais.size() % 3 != 2) {
        return false;
    }


    bool kehu = hupaipanduan(pais, systemConfig);


    return kehu;
}
//判断顺子
bool UIMainWindows::isSequence(const std::list<Mj> & handMjs, int pai) const
{
    int nPai1,nPai2;
    nPai1 = pai + 1;
    nPai2 = pai + 2;

    bool b1 = false,b2 = false;
    for(auto i: handMjs){
       if(i.getResult() == nPai1){
            b1 = true;
            break;
        }
     }
     for(auto i: handMjs){
        if(i.getResult() == nPai2){
            b2 = true;
            break;
        }
       }

       //牌1牌2都存在就为真,其余都为假
     return (b1 && b2);
}
//判断刻子，三个相同牌
bool UIMainWindows::isTriplet(const std::list<Mj> & handMjs, int pai) const
{
    int cnt = 0;
    for(auto i:handMjs){
        if(i.getResult() == pai){
            cnt++;
        }
    }
    return cnt >= 3;
}
//胡牌判断，由HuPaiPanDin函数调用
bool UIMainWindows::hupaipanduan(std::list<Mj> cards, SystemConfig systemConfig)
{
    list<Mj> pais = cards;//复制一根备份
    //统计每张牌出现的次数
    unordered_map<int, int> Map;
    for (list<Mj>::iterator i = pais.begin(); i != pais.end(); ++i) {
        if (Map.find(i->getResult()) != Map.end()) {
            Map[i->getResult()]++;
        } else {
            Map[i->getResult()] = 1;
        }
    }
    //统计出现次数
    list<int> result_count;//出现的次数
    for (unordered_map<int,int>::const_iterator i = Map.begin(); i != Map.end(); ++i) {
        result_count.push_back(i->second);
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;//出现1，2，3，4次
    for (list<int>::iterator i = result_count.begin(); i != result_count.end(); ++i) {
        if (*i == 1) {//出现一次的
            cnt1++;
        }
        if (*i == 2) {//出现两次的
            cnt2++;
        }
        if (*i == 3) {//出现三次的
            cnt3++;
        }
        if (*i == 4) {//出现四次的
            cnt4++;
        }
    }
    //所有的牌全部都能组成2个 胡牌
    if (cnt2 * 2 == systemConfig.wanjiapaishu + 1) {//小七对
        return true;
    }
    //只有两张牌
    if (pais.size() == 2) {//刚好凑成将
        return pais.begin()->getResult() == (++pais.begin())->getResult();
    }
    //有至少两个4张一样的牌，其余牌都是对子 胡牌(龙七对)
    if (cnt4 > 1 && (cnt2 * 2 + cnt4 * 4 == static_cast<int>(pais.size()))) {
        return true;
    }
    //有4张一样的牌且没杠，其余牌都是对子 (小七对)
    if(cnt2 == 5 && cnt4 == 1){
        return  true;
    }
    //d都是四个加一对 胡牌(18罗汉)
    if (cnt2 == 1 && cnt4 * 4 == static_cast<int>(pais.size()) - 2) {
        return true;
    }

    if(systemConfig.erwubajiang == 1){
        //全部是3个相同的加一对将
        if(cnt2 == 1 && cnt3 * 3 == static_cast<int>(pais.size()) - 2){
            for(auto i:Map){
                if(i.second == 2){
                    if(i.first % 10 == 2 || i.first % 10 == 5 || i.first % 10 == 8){
                        return true;
                    }
                }
            }
        }

        for (unordered_map<int, int>::iterator sub_enty = Map.begin();sub_enty != Map.end();sub_enty++) {//至少有一个顺子的胡牌组合
             list<Mj> suanpai = pais;//算牌(重置)
             list<Mj> tempSuanpai;
              list<Mj>::iterator iterator = suanpai.begin();
              int jiangCnt = 0;
              int testNum = sub_enty->first;//用于调试
              while(iterator != suanpai.end()){
                  if(iterator->getResult() == sub_enty->first && jiangCnt < 2 && (sub_enty->first % 10 == 2 || sub_enty->first % 10 == 5 || sub_enty->first % 10 == 8)){
                     iterator = suanpai.erase(iterator);
                     jiangCnt++;
                  }else{
                      iterator++;
                  }
              }
              if(suanpai.size() % 3 != 0){//剩下的不是3的倍数
                  continue;
              }

             //排序
              suanpai.sort(ComparatorMjResult2);
              tempSuanpai = suanpai;

              //先移除顺子再移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              //移除顺子
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(isSequence(suanpai,iterator->getResult()) == true){


                      int pai = iterator->getResult();
                      int nPai1 = pai + 1;
                      int nPai2 = pai + 2;

                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai1){
                              suanpai.erase(i);
                              break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai2){
                               suanpai.erase(i);
                               break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == pai){
                             iterator = suanpai.erase(i);
                             break;
                          }
                      }
                      if(suanpai.size() > 0){

                      }
                  }else{
                      iterator++;
                  }
              }

              //移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(iterator->getResult() != sub_enty->first && isTriplet(suanpai, iterator->getResult()) == true){//删除刻字

                      int pai = iterator->getResult();
                      int cnt = 0;
                      for(list<Mj>::iterator i = suanpai.begin();i != suanpai.end();){
                          if(pai == i->getResult()){
                              i = suanpai.erase(i);
                              cnt++;
                          }else{
                              i++;
                          }
                          if(cnt == 3){
                              break;
                          }
                      }
                      if(suanpai.size() > 0){
                          iterator = suanpai.begin();

                      }
                  }else{
                      iterator++;
                  }
              }

              if (suanpai.size() == 0) {

                  return true;
              }


              suanpai = tempSuanpai;//有一对刻字，其余的都是顺子（刻字被拆未顺子）
              iterator = suanpai.begin();
              //移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              int getTriplet = 0;
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(getTriplet != 0){break;}
                  if(iterator->getResult() != sub_enty->first && isTriplet(suanpai, iterator->getResult()) == true){//删除刻字

                      int pai = iterator->getResult();
                      int cnt = 0;
                      for(list<Mj>::iterator i = suanpai.begin();i != suanpai.end();){
                          if(pai == i->getResult()){
                              i = suanpai.erase(i);
                              cnt++;
                              getTriplet++;
                          }else{
                              i++;
                          }
                          if(cnt == 3){
                              break;
                          }
                      }
                      if(suanpai.size() > 0){
                          iterator = suanpai.begin();

                      }
                  }else{
                      iterator++;
                  }
              }

              //先移除顺子再移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              //移除顺子
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(isSequence(suanpai,iterator->getResult()) == true){

                      int pai = iterator->getResult();
                      int nPai1 = pai + 1;
                      int nPai2 = pai + 2;

                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai1){
                              suanpai.erase(i);
                              break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai2){
                               suanpai.erase(i);
                               break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == pai){
                             iterator = suanpai.erase(i);
                             break;
                          }
                      }
                      if(suanpai.size() > 0){

                      }
                  }else{
                      iterator++;
                  }
              }

              if (suanpai.size() == 0) {

                  return true;
              }
        }
    }else{
        //全部是3个相同的加一对将
        if(cnt2 == 1 && cnt3 * 3 == static_cast<int>(pais.size()) - 2){
            return true;
        }

        for (unordered_map<int, int>::iterator sub_enty = Map.begin();sub_enty != Map.end();sub_enty++) {//至少有一个顺子的胡牌组合
             list<Mj> suanpai = pais;//算牌(重置)
             list<Mj> tempSuanpai;
              list<Mj>::iterator iterator = suanpai.begin();
              int jiangCnt = 0;
              int testNum = sub_enty->first;//用于调试
              while(iterator != suanpai.end()){
                  if(iterator->getResult() == sub_enty->first && jiangCnt < 2){
                     iterator = suanpai.erase(iterator);
                     jiangCnt++;
                  }else{
                      iterator++;
                  }
              }
              if(suanpai.size() % 3 != 0){//剩下的不是3的倍数
                  continue;
              }

             //排序
              suanpai.sort(ComparatorMjResult2);
              tempSuanpai = suanpai;

              //先移除顺子再移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              //移除顺子
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(isSequence(suanpai,iterator->getResult()) == true){


                      int pai = iterator->getResult();
                      int nPai1 = pai + 1;
                      int nPai2 = pai + 2;

                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai1){
                              suanpai.erase(i);
                              break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai2){
                               suanpai.erase(i);
                               break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == pai){
                             iterator = suanpai.erase(i);
                             break;
                          }
                      }
                      if(suanpai.size() > 0){

                      }
                  }else{
                      iterator++;
                  }
              }

              //移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(iterator->getResult() != sub_enty->first && isTriplet(suanpai, iterator->getResult()) == true){//删除刻字

                      int pai = iterator->getResult();
                      int cnt = 0;
                      for(list<Mj>::iterator i = suanpai.begin();i != suanpai.end();){
                          if(pai == i->getResult()){
                              i = suanpai.erase(i);
                              cnt++;
                          }else{
                              i++;
                          }
                          if(cnt == 3){
                              break;
                          }
                      }
                      if(suanpai.size() > 0){
                          iterator = suanpai.begin();

                      }
                  }else{
                      iterator++;
                  }
              }

              if (suanpai.size() == 0) {

                  return true;
              }


              suanpai = tempSuanpai;//有一对刻字，其余的都是顺子（刻字被拆未顺子）
              iterator = suanpai.begin();
              //移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              int getTriplet = 0;
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(getTriplet != 0){break;}
                  if(iterator->getResult() != sub_enty->first && isTriplet(suanpai, iterator->getResult()) == true){//删除刻字

                      int pai = iterator->getResult();
                      int cnt = 0;
                      for(list<Mj>::iterator i = suanpai.begin();i != suanpai.end();){
                          if(pai == i->getResult()){
                              i = suanpai.erase(i);
                              cnt++;
                              getTriplet++;
                          }else{
                              i++;
                          }
                          if(cnt == 3){
                              break;
                          }
                      }
                      if(suanpai.size() > 0){
                          iterator = suanpai.begin();

                      }
                  }else{
                      iterator++;
                  }
              }

              //先移除顺子再移除刻字
              if(suanpai.size() > 0){
                   iterator = suanpai.begin();
              }
              //移除顺子
              while(suanpai.size() > 0 && iterator != suanpai.end()){
                  if(isSequence(suanpai,iterator->getResult()) == true){

                      int pai = iterator->getResult();
                      int nPai1 = pai + 1;
                      int nPai2 = pai + 2;

                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai1){
                              suanpai.erase(i);
                              break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == nPai2){
                               suanpai.erase(i);
                               break;
                          }
                      }
                      for(list<Mj>::iterator i = suanpai.begin(); i!= suanpai.end();i++){
                          if(i->getResult() == pai){
                             iterator = suanpai.erase(i);
                             break;
                          }
                      }
                      if(suanpai.size() > 0){

                      }
                  }else{
                      iterator++;
                  }
              }

              if (suanpai.size() == 0) {

                  return true;
              }
        }
    }

    return false;
}
