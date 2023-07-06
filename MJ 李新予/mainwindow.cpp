#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <windows.h>
#include "card.h"
#include <iostream>
#include <QMessageBox>
#include <random>


static player player1(1), player2(2), player3(3);
static QVector<card> paishan;
static QVector<card> paihe;
static QVector<QListWidgetItem> mingpai;
static QVector<QListWidgetItem> bei;
static QVector<card> baopai;
static card nowcard; // 场上打出的牌
static QIcon button[5];
static QIcon icon[29];
static int zhuangtai; // 鸣牌跳过后做什么
static int idx, cnt, nowplayer;
static QString yi[39] = {"", "国士无双十三面", "国士无双", "七对子", "四暗刻单骑", "四暗刻", "三暗刻", "绿一色", "字一色", "纯正九莲宝灯", "九莲宝灯", "清一色"\
                     , "大三元", "大四喜", "小四喜", "小三元", "断幺九", "自摸", "役牌 门风牌", "役牌 场风牌", "役牌 白", "役牌 发"\
                      , "役牌 中", "平和", "岭上开花", "海底摸月", "河底捞鱼", "一发", "宝牌", "红宝牌", "拔北宝牌", "三杠子", "混老头", " 清老头"\
                     , "混全带幺九", "一气通贯", "纯全带幺九", "混一色", "对对和"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    icon[0].addFile(":/image/1m.png");
    icon[1].addFile(":/image/9m.png");
    icon[2].addFile(":/image/1s.png");
    icon[3].addFile(":/image/2s.png");
    icon[4].addFile(":/image/3s.png");
    icon[5].addFile(":/image/4s.png");
    icon[6].addFile(":/image/5s.png");
    icon[7].addFile(":/image/6s.png");
    icon[8].addFile(":/image/7s.png");
    icon[9].addFile(":/image/8s.png");
    icon[10].addFile(":/image/9s.png");
    icon[11].addFile(":/image/1p.png");
    icon[12].addFile(":/image/2p.png");
    icon[13].addFile(":/image/3p.png");
    icon[14].addFile(":/image/4p.png");
    icon[15].addFile(":/image/5p.png");
    icon[16].addFile(":/image/6p.png");
    icon[17].addFile(":/image/7p.png");
    icon[18].addFile(":/image/8p.png");
    icon[19].addFile(":/image/9p.png");
    icon[20].addFile(":/image/don.png");
    icon[21].addFile(":/image/nan.png");
    icon[22].addFile(":/image/shii.png");
    icon[23].addFile(":/image/pei.png");
    icon[24].addFile(":/image/haku.png");
    icon[25].addFile(":/image/hatsu.png");
    icon[26].addFile(":/image/chuun.png");
    icon[27].addFile(":/image/5sr.png");
    icon[28].addFile(":/image/5pr.png");
    button[0].addFile(":/image/peng.png");
    button[1].addFile(":/image/gang.png");
    button[2].addFile(":/image/skip.png");
    button[3].addFile(":/image/babei.png");
    button[4].addFile(":/image/ron.png");
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(45, 80)); // 玩家舍牌
    ui->listWidget_8->setIconSize(QSize(36, 60)); // 玩家拔北
    ui->listWidget_9->setIconSize(QSize(36, 60)); // 玩家鸣牌
    ui->listWidget_2->setIconSize(QSize(45, 80)); // player2舍牌
    ui->listWidget_3->setIconSize(QSize(45, 80)); // player3舍牌
    ui->listWidget_4->setIconSize(QSize(36, 60)); // player2鸣牌
    ui->listWidget_5->setIconSize(QSize(36, 60)); // player2拔北
    ui->listWidget_6->setIconSize(QSize(36, 60)); // player3鸣牌
    ui->listWidget_7->setIconSize(QSize(36, 60)); // player3拔北
    ui->listWidget_10->setIconSize(QSize(36, 60));
    disable_discard();
    hidemingpai();
    player1.changfeng = 0;
    player1.zifeng = 0;
    player2.changfeng = 0;
    player2.zifeng = 1;
    player3.changfeng = 0;
    player3.zifeng = 2;
    QPalette pal(palette());
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/image/background.png"))); //设置背景黑色
    setAutoFillBackground(true);
    setPalette(pal);
}

void MainWindow::init(){
    for (int i = 0; i < 4; i++) paishan.push_back(card(i));
    for (int i = 32; i < 136; i++) paishan.push_back(card(i));
    long long seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    std::shuffle(paishan.begin(),paishan.end(),std::default_random_engine(seed)); // 洗牌
    for (int i = 0; i < 13; i++){
        player1.player_card[i] = paishan[i];
        player1.player_card[i].owner = 1;
        player2.player_card[i] = paishan[12 + i];
        player2.player_card[i].owner = 2;
        player3.player_card[i] = paishan[25 + i];
        player3.player_card[i].owner = 3;
    }
    int t = 0;
    for (auto it = paishan.begin(); t <= 38;){
        it = paishan.erase(it);
        t++;
    }
    baopai.push_back(*(paishan.end() - 1));
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon((*(baopai.end() - 1)).idx_in_all()), "");
    ui->listWidget_10->addItem(item);
    paishan.erase(paishan.end() - 1);
    showcard();
}

QIcon MainWindow::idx_to_icon(int idx){
    int t;
    t = idx / 4;
    if (t == 13 && idx % 4 == 0) return icon[27];
    if (t == 22 && idx % 4 == 0) return icon[28];
    if (idx < 4) return icon[0];
    return icon[t - 7];
}

void MainWindow::showcard(){
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    for (int i = 0; i < player1.card_sum - 1; i++){
        switch(i){
            case 0: ui->shoupai1->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 1: ui->shoupai2->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 2: ui->shoupai3->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 3: ui->shoupai4->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 4: ui->shoupai5->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 5: ui->shoupai6->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 6: ui->shoupai7->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 7: ui->shoupai8->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 8: ui->shoupai9->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 9: ui->shoupai10->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 10: ui->shoupai11->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 11: ui->shoupai12->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
            case 12: ui->shoupai13->setIcon(idx_to_icon(player1.player_card[i].idx_in_all())); break;
        }
//        std::cout << player1.player_card[i].idx_in_all() << " ";
    }
    for (int i = player1.card_sum - 1; i < 13; i++){
        switch(i){
            case 0: ui->shoupai1->setIcon(QIcon()); break;
            case 1: ui->shoupai2->setIcon(QIcon()); break;
            case 2: ui->shoupai3->setIcon(QIcon()); break;
            case 3: ui->shoupai4->setIcon(QIcon()); break;
            case 4: ui->shoupai5->setIcon(QIcon()); break;
            case 5: ui->shoupai6->setIcon(QIcon()); break;
            case 6: ui->shoupai7->setIcon(QIcon()); break;
            case 7: ui->shoupai8->setIcon(QIcon()); break;
            case 8: ui->shoupai9->setIcon(QIcon()); break;
            case 9: ui->shoupai10->setIcon(QIcon()); break;
            case 10: ui->shoupai11->setIcon(QIcon()); break;
            case 11: ui->shoupai12->setIcon(QIcon()); break;
            case 12: ui->shoupai13->setIcon(QIcon()); break;
        }
    }
    ui->shoupai1->setIconSize(QSize(75, 120));
    ui->shoupai2->setIconSize(QSize(75, 120));
    ui->shoupai3->setIconSize(QSize(75, 120));
    ui->shoupai4->setIconSize(QSize(75, 120));
    ui->shoupai5->setIconSize(QSize(75, 120));
    ui->shoupai6->setIconSize(QSize(75, 120));
    ui->shoupai7->setIconSize(QSize(75, 120));
    ui->shoupai8->setIconSize(QSize(75, 120));
    ui->shoupai9->setIconSize(QSize(75, 120));
    ui->shoupai10->setIconSize(QSize(75, 120));
    ui->shoupai11->setIconSize(QSize(75, 120));
    ui->shoupai12->setIconSize(QSize(75, 120));
    ui->shoupai13->setIconSize(QSize(75, 120));
}

void MainWindow::ifhu(int nowplayer){
    zhuangtai = nowplayer;
    player1.player_card[player1.card_sum - 1] = nowcard;
    countbaopai();  
    if (nowplayer == 2){
        player3.player_card[player3.card_sum - 1] = nowcard;
        if (player3.is_win() > 0){
            disable_discard();
            hidemingpai();
            showaicard();
            QMessageBox::information(NULL, "", "player3 wins!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
    }
    if (nowplayer == 3){
        player2.player_card[player2.card_sum - 1] = nowcard;
        if (player2.is_win() > 0){
            disable_discard();
            hidemingpai();
            showaicard();
            QMessageBox::information(NULL, "", "player2 wins!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
    }
    if (player1.is_win() > 0){
        ui->mingpai4->setIcon(button[4]);
        ui->mingpai4->setIconSize(QSize(180, 85));
        ui->skip->setIcon(button[2]);
        ui->skip->setIconSize(QSize(180, 70));
        ui->mingpai4->setEnabled(true);
        ui->skip->setEnabled(true);
    }
    else{
        if (nowplayer == 1) ifbei();
        if (nowplayer == 2) ifpeng(2);
        if (nowplayer == 3) ifpeng(3);
    }
}

void MainWindow::ifbei(){
    bool f = false;
    for (int i = 0; i < player1.card_sum; i++){
        if (player1.player_card[i].type == 3 && player1.player_card[i].num == 3){
            idx = i;
            f = true;
            break;
        }
    }
    if (f){
        ui->mingpai3->setIcon(button[3]);
        ui->mingpai3->setIconSize(QSize(180, 70));
        ui->skip->setIcon(button[2]);
        ui->skip->setIconSize(QSize(180, 70));
        ui->mingpai3->setEnabled(true);
        ui->skip->setEnabled(true);
        zhuangtai = 1;
    }
    else{
        ifpeng(1);
    }
}

void MainWindow::mopai(){
    player1.lingshang = false;
    if (paishan.size() == 0){
        disable_discard();
        hidemingpai();
        showaicard();
        QMessageBox::information(NULL, "Exit", "游戏结束", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    if (paishan.size() == 1){
        player1.haidi = true;
        player2.haidi = true;
        player3.haidi = true;
    }
    nowcard = paishan[0];
    player1.player_card[player1.card_sum - 1] = nowcard;
    paishan.erase(paishan.begin());
    ui->shoupai14->setIcon(idx_to_icon(player1.player_card[player1.card_sum - 1].idx_in_all()));
    ui->shoupai14->setIconSize(QSize(75, 120));
    enable_discard();
    showcard();
    ifhu(1);
}

void MainWindow::enable_discard(){
    ui->shoupai1->blockSignals(false);
    ui->shoupai2->blockSignals(false);
    ui->shoupai3->blockSignals(false);
    ui->shoupai4->blockSignals(false);
    ui->shoupai5->blockSignals(false);
    ui->shoupai6->blockSignals(false);
    ui->shoupai7->blockSignals(false);
    ui->shoupai8->blockSignals(false);
    ui->shoupai9->blockSignals(false);
    ui->shoupai10->blockSignals(false);
    ui->shoupai11->blockSignals(false);
    ui->shoupai12->blockSignals(false);
    ui->shoupai13->blockSignals(false);
    ui->shoupai14->blockSignals(false);
}

void MainWindow::disable_discard(){
    ui->shoupai1->blockSignals(true);
    ui->shoupai2->blockSignals(true);
    ui->shoupai3->blockSignals(true);
    ui->shoupai4->blockSignals(true);
    ui->shoupai5->blockSignals(true);
    ui->shoupai6->blockSignals(true);
    ui->shoupai7->blockSignals(true);
    ui->shoupai8->blockSignals(true);
    ui->shoupai9->blockSignals(true);
    ui->shoupai10->blockSignals(true);
    ui->shoupai11->blockSignals(true);
    ui->shoupai12->blockSignals(true);
    ui->shoupai13->blockSignals(true);
    ui->shoupai14->blockSignals(true);
}

void MainWindow::player2_peng(){
    cnt = 0; idx = 0;
    if (nowcard.type == 3 && (nowcard.num == player2.changfeng || nowcard.num == player2.zifeng || nowcard.num > 3)){
        for (int i = 0; i < player2.card_sum - 1; i++){
            if (player2.player_card[i].type == nowcard.type && player2.player_card[i].num == nowcard.num){
                if (idx == 0) idx = i;
                cnt++;
            }
        }
        if (cnt == 2){
            player2.card_sum -= 2;
            for (int i = 0; i < 2; i++){
                mingpai.push_back(QListWidgetItem(idx_to_icon(player2.player_card[idx + i].idx_in_all()), ""));
                ui->listWidget_4->addItem(mingpai.end() - 1);
            }
            for (int i = 0; i < 2; i++){
                player2.peng[player2.peng_sum * 3 + i] = player2.player_card[idx + i];
            }
            player2.peng[player2.peng_sum * 3 + 2] = nowcard;
            for (int i = idx; i < player2.card_sum - 1; i++) player2.player_card[i] = player2.player_card[i + 2];
            player2.peng_sum++;
            player2.menqianqing = false;
            player2_action_peng();
        }
        if (cnt == 3){
            player2.card_sum -= 3;
            for (int i = 0; i < 3; i++){
                mingpai.push_back(QListWidgetItem(idx_to_icon(player2.player_card[idx + i].idx_in_all()), ""));
                ui->listWidget_4->addItem(mingpai.end() - 1);
            }
            for (int i = 0; i < 3; i++) player2.gang[player2.gang_sum * 4 + i] = player2.player_card[idx + i];
            player2.gang[player2.gang_sum * 4 + 3] = nowcard;
            for (int i = idx; i < player2.card_sum - 1; i++) player2.player_card[i] = player2.player_card[i + 3];
            baopai.push_back(*(paishan.end() - 1));
            paishan.erase(paishan.end() - 1);
            player2.gang_sum++;
            player2.menqianqing = false;
            player2_action();
        }
    }
}

void MainWindow::player3_peng(){
    cnt = 0; idx = 0;
    if (nowcard.type == 3 && (nowcard.num == player3.changfeng || nowcard.num == player3.zifeng || nowcard.num > 3)){
        for (int i = 0; i < player3.card_sum - 1; i++){
            if (player3.player_card[i].type == nowcard.type && player3.player_card[i].num == nowcard.num){
                if (idx == 0) idx = i;
                cnt++;
            }
        }
        if (cnt == 2){
            player3.card_sum -= 2;
            for (int i = 0; i < 2; i++){
                mingpai.push_back(QListWidgetItem(idx_to_icon(player3.player_card[idx + i].idx_in_all()), ""));
                ui->listWidget_4->addItem(mingpai.end() - 1);
            }
            for (int i = 0; i < 2; i++){
                player3.peng[player3.peng_sum * 3 + i] = player3.player_card[idx + i];
            }
            player3.peng[player3.peng_sum * 3 + 2] = nowcard;
            for (int i = idx; i < player3.card_sum - 1; i++) player3.player_card[i] = player3.player_card[i + 2];
            player3.peng_sum++;
            player3.menqianqing = false;
            player3_action_peng();
        }
        if (cnt == 3){
            player3.card_sum -= 3;
            for (int i = 0; i < 3; i++){
                mingpai.push_back(QListWidgetItem(idx_to_icon(player3.player_card[idx + i].idx_in_all()), ""));
                ui->listWidget_4->addItem(mingpai.end() - 1);
            }
            for (int i = 0; i < 3; i++) player3.gang[player3.gang_sum * 4 + i] = player3.player_card[idx + i];
            player3.gang[player3.gang_sum * 4 + 3] = nowcard;
            for (int i = idx; i < player3.card_sum - 1; i++) player3.player_card[i] = player3.player_card[i + 3];
            baopai.push_back(*(paishan.end() - 1));
            paishan.erase(paishan.end() - 1);
            player3.gang_sum++;
            player3.menqianqing = false;
            player3_action();
        }
    }
}

void MainWindow::countbaopai(){
    if (nowcard.owner == 0) player1.myturn = true;
    else player1.myturn = false;
    player1.dora = 0;
    player1.rdora = 0;
    player2.dora = 0;
    player2.rdora = 0;
    player3.dora = 0;
    player3.rdora = 0;
    for (int i = 0; i < player1.card_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player1.player_card[i].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player1.player_card[i].num) player1.dora++;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player1.player_card[i].num) player1.dora++;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player1.player_card[i].num) player1.dora++;
                }
            }
        }
        if (player1.player_card[i].type != 3 && player1.player_card[i].num == 4 && player1.player_card[i].idx == 0) player1.rdora++;
    }
    for (int i = 0; i < player1.peng_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player1.peng[i * 3].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player1.peng[i].num) player1.dora += 3;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player1.peng[i].num) player1.dora += 3;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player1.peng[i].num) player1.dora += 3;
                }
            }
        }
        for (int j = 0; j < 3; j++){
            if (player1.peng[i * 3 + j].type != 3 && player1.peng[i * 3 + j].num == 4 && player1.peng[i * 3 + j].idx == 0) player1.rdora++;
        }
    }
    for (int i = 0; i < player1.gang_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player1.gang[i * 4].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player1.gang[i].num) player1.dora += 4;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player1.gang[i].num) player1.dora += 4;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player1.gang[i].num) player1.dora += 4;
                }
            }
        }
        for (int j = 0; j < 4; j++){
            if (player1.gang[i * 4 + j].type != 3 && player1.gang[i * 4 + j].num == 4 && player1.gang[i * 4 + j].idx == 0) player1.rdora++;
        }
    }
    for (int i = 0; i < player1.angang_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player1.angang[i * 4].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player1.angang[i].num) player1.dora += 4;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player1.angang[i].num) player1.dora += 4;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player1.angang[i].num) player1.dora += 4;
                }
            }
        }
        for (int j = 0; j < 4; j++){
            if (player1.angang[i * 4 + j].type != 3 && player1.angang[i * 4 + j].num == 4 && player1.angang[i * 4 + j].idx == 0) player1.rdora++;
        }
    }
    for (int i = 0; i < player2.card_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player2.player_card[i].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player2.player_card[i].num) player2.dora++;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player2.player_card[i].num) player2.dora++;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player2.player_card[i].num) player2.dora++;
                }
            }
        }
        if (player2.player_card[i].type != 3 && player2.player_card[i].num == 4 && player2.player_card[i].idx == 0) player2.rdora++;
    }
    for (int i = 0; i < player3.card_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player3.player_card[i].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player3.player_card[i].num) player3.dora++;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player3.player_card[i].num) player3.dora++;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player3.player_card[i].num) player3.dora++;
                }
            }
        }
        if (player3.player_card[i].type != 3 && player3.player_card[i].num == 4 && player3.player_card[i].idx == 0) player3.rdora++;
    }
    for (int i = 0; i < player2.peng_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player2.peng[i * 3].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player2.peng[i].num) player2.dora += 3;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player2.peng[i].num) player2.dora += 3;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player2.peng[i].num) player2.dora += 3;
                }
            }
        }
        for (int j = 0; j < 3; j++){
            if (player2.peng[i * 3 + j].type != 3 && player2.peng[i * 3 + j].num == 4 && player2.peng[i * 3 + j].idx == 0) player2.rdora++;
        }
    }
    for (int i = 0; i < player3.peng_sum; i++){
        for (auto it = baopai.begin(); it != baopai.end(); it++){
            if (player3.peng[i * 3].type == it->type){
                if (it->type != 3){
                    if ((it->num + 1) % 9 == player3.peng[i].num) player3.dora += 3;
                }
                else if (it->num < 4){
                    if ((it->num + 1) % 4 == player3.peng[i].num) player3.dora += 3;
                }
                else{
                    if ((it->num - 3) % 3 + 4 == player3.peng[i].num) player3.dora += 3;
                }
            }
        }
        for (int j = 0; j < 3; j++){
            if (player3.peng[i * 3 + j].type != 3 && player3.peng[i * 3 + j].num == 4 && player3.peng[i * 3 + j].idx == 0) player3.rdora++;
        }
    }
}

void MainWindow::ifpeng(int nowplayer){
    idx = -1;
    cnt = 0;
    for (int i = 0; i < player1.card_sum - 1; i++){
        if (player1.player_card[i].type == nowcard.type && player1.player_card[i].num == nowcard.num){
            if (idx == -1) idx = i;
            cnt++;
        }
    }
    if (cnt == 2 && nowplayer != 1){
        disable_discard();
        ui->mingpai1->setIcon(button[0]);
        ui->mingpai1->setIconSize(QSize(180, 70));
        ui->skip->setIcon(button[2]);
        ui->skip->setIconSize(QSize(180, 70));
        ui->mingpai1->setEnabled(true);
        ui->skip->setEnabled(true);
        zhuangtai = nowplayer;
    }
    else if (cnt == 3){
        disable_discard();
        ui->mingpai1->setIcon(button[0]);
        ui->mingpai1->setIconSize(QSize(180, 70));
        ui->mingpai2->setIcon(button[1]);
        ui->mingpai2->setIconSize(QSize(180, 70));
        ui->skip->setIcon(button[2]);
        ui->skip->setIconSize(QSize(180, 70));
        ui->mingpai1->setEnabled(true);
        ui->mingpai2->setEnabled(true);
        ui->skip->setEnabled(true);
        zhuangtai = nowplayer;
    }
    else {
        if (nowplayer == 1) return;
        else if (nowplayer == 2) player3_action();
        else mopai();
    }
}

void MainWindow::player2_action(){
    countbaopai();
    hidemingpai();
    player2.player_card[player2.card_sum - 1] = nowcard;
    if (player2.is_win() > 0){
        disable_discard();
        hidemingpai();
        showaicard();
        QMessageBox::information(NULL, "", "player2 wins!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    if (paishan.size() == 0){
        disable_discard();
        hidemingpai();
        showaicard();
        QMessageBox::information(NULL, "Exit", "游戏结束", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    if (paishan.size() == 1){
        player1.haidi = true;
        player2.haidi = true;
        player3.haidi = true;
    }
    player2.player_card[player2.card_sum - 1] = paishan[0];
    paishan.erase(paishan.begin());
    bool f = true;
    while (f){
        f = false;
        for (int i = 0; i < player2.card_sum; i++){
            if (player2.player_card[i].type == 3 && player2.player_card[i].num == 3){
                f = true;
                for (int j = i; j < player2.card_sum - 1; j++) player2.player_card[j] = player2.player_card[j + 1];
                break;
            }
        }
        if (f){
            nowcard = player2.player_card[player2.card_sum - 1];
            QListWidgetItem *item = new QListWidgetItem(icon[23], "");
            ui->listWidget_5->addItem(item);
            player2.player_card[player2.card_sum - 1] = paishan[0];
            paishan.erase(paishan.begin());
            player2.bei++;
            ifhu(2);
        }
    }
    nowcard = player2.discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget_2->addItem(item);
    player3.player_card[player3.card_sum - 1] = nowcard;
    if (player3.is_win() > 0){
        disable_discard();
        hidemingpai();
        showaicard();
        QMessageBox::information(NULL, "", "player3 wins!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    ifhu(2);
}

void MainWindow::player2_action_peng(){
    countbaopai();
    nowcard = player2.discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget_2->addItem(item);
    ifpeng(2);
}

void MainWindow::player3_action_peng(){
    countbaopai();
    nowcard = player3.discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget_3->addItem(item);
    nowplayer = 3;
    ifpeng(3);
}

void MainWindow::tiaoshi(){
    std::cout << player1.xing.isvalid[0][0][0][0][1][1][1][2][0];
    std::cout << player1.xing.kezi[0][0][0][0][1][1][1][2][0];
    std::cout << player1.xing.shunzi[0][0][0][0][1][1][1][2][0];
    std::cout << player1.xing.quetou[0][0][0][0][1][1][1][2][0];
}

void MainWindow::showaicard(){
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
    std::sort(player2.player_card, player2.player_card + player2.card_sum - 1);
    std::sort(player3.player_card, player3.player_card + player3.card_sum - 1);
    for (int i = 0; i < player2.card_sum - 1; i++){
        QListWidgetItem *item = new QListWidgetItem(idx_to_icon(player2.player_card[i].idx_in_all()), "");
        ui->listWidget_2->addItem(item);
    }
    for (int i = 0; i < player3.card_sum - 1; i++){
        QListWidgetItem *item = new QListWidgetItem(idx_to_icon(player3.player_card[i].idx_in_all()), "");
        ui->listWidget_3->addItem(item);
    }
}

void MainWindow::player3_action(){
    if (paishan.size() == 0){
        disable_discard();
        hidemingpai();
        showaicard();
        QMessageBox::information(NULL, "Exit", "游戏结束", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    if (paishan.size() == 1){
        player1.haidi = true;
        player2.haidi = true;
        player3.haidi = true;
    }
    countbaopai();
    player3.player_card[player3.card_sum - 1] = paishan[0];
    paishan.erase(paishan.begin());
    bool f = true;
    while (f){
        f = false;
        for (int i = 0; i < player3.card_sum; i++){
            if (player3.player_card[i].type == 3 && player3.player_card[i].num == 3){
                f = true;
                for (int j = i; j < player3.card_sum - 1; j++) player3.player_card[j] = player3.player_card[j + 1];
                break;
            }
        }
        if (f){
            nowcard = player3.player_card[player3.card_sum - 1];
            QListWidgetItem *item = new QListWidgetItem(icon[23], "");
            ui->listWidget_5->addItem(item);
            player3.player_card[player3.card_sum - 1] = paishan[0];
            paishan.erase(paishan.begin());
            player3.bei++;
            ifhu(2);
        }
    }
    nowcard = player3.discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget_3->addItem(item);
    ifhu(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hidemingpai(){
    ui->mingpai1->setEnabled(false);
    ui->mingpai2->setEnabled(false);
    ui->mingpai3->setEnabled(false);
    ui->mingpai4->setEnabled(false);
    ui->skip->setEnabled(false);
    ui->mingpai1->setIcon(QIcon());
    ui->mingpai2->setIcon(QIcon());
    ui->mingpai3->setIcon(QIcon());
    ui->mingpai4->setIcon(QIcon());
    ui->skip->setIcon(QIcon());
}

void MainWindow::on_shoupai1_clicked()
{
    nowcard = player1.player_card[0];
    player1.player_card[0] = player1.player_card[player1.card_sum - 1];
    player1.player_card[0].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai2_clicked()
{
    nowcard = player1.player_card[1];
    player1.player_card[1] = player1.player_card[player1.card_sum - 1];
    player1.player_card[1].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai10_clicked()
{
    nowcard = player1.player_card[9];
    player1.player_card[9] = player1.player_card[player1.card_sum - 1];
    player1.player_card[9].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai11_clicked()
{
    nowcard = player1.player_card[10];
    player1.player_card[10] = player1.player_card[player1.card_sum - 1];
    player1.player_card[10].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai12_clicked()
{
    nowcard = player1.player_card[11];
    player1.player_card[11] = player1.player_card[player1.card_sum - 1];
    player1.player_card[11].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai13_clicked()
{
    nowcard = player1.player_card[12];
    player1.player_card[12] = player1.player_card[player1.card_sum - 1];
    player1.player_card[12].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai14_clicked()
{
    nowcard = player1.player_card[13];
    player1.player_card[13] = player1.player_card[player1.card_sum - 1];
    player1.player_card[13].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai3_clicked()
{
    nowcard = player1.player_card[2];
    player1.player_card[2] = player1.player_card[player1.card_sum - 1];
    player1.player_card[2].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai4_clicked()
{
    nowcard = player1.player_card[3];
    player1.player_card[3] = player1.player_card[player1.card_sum - 1];
    player1.player_card[3].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai5_clicked()
{
    nowcard = player1.player_card[4];
    player1.player_card[4] = player1.player_card[player1.card_sum - 1];
    player1.player_card[4].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai6_clicked()
{
    nowcard = player1.player_card[5];
    player1.player_card[5] = player1.player_card[player1.card_sum - 1];
    player1.player_card[5].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai7_clicked()
{
    nowcard = player1.player_card[6];
    player1.player_card[6] = player1.player_card[player1.card_sum - 1];
    player1.player_card[6].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai8_clicked()
{
    nowcard = player1.player_card[7];
    player1.player_card[7] = player1.player_card[player1.card_sum - 1];
    player1.player_card[7].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_shoupai9_clicked()
{
    nowcard = player1.player_card[8];
    player1.player_card[8] = player1.player_card[player1.card_sum - 1];
    player1.player_card[8].owner = 1;
    std::sort(player1.player_card, player1.player_card + player1.card_sum - 1);
    showcard();
    disable_discard();
    paihe.push_back(nowcard);
    QListWidgetItem *item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget->addItem(item);
    ui->shoupai14->setIcon(QIcon());
    player2_action();
}

void MainWindow::on_mingpai1_clicked() // 碰
{
    player1.card_sum -= 2;
    for (int i = 0; i < 2; i++){
        QListWidgetItem* item = new QListWidgetItem(idx_to_icon(player1.player_card[idx + i].idx_in_all()), "");
        ui->listWidget_9->addItem(item);
        player1.peng[player1.peng_sum * 3 + i] = player1.player_card[idx + i];
    }
    QListWidgetItem* item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget_9->addItem(item);
    player1.peng[player1.peng_sum * 3 + 2] = nowcard;
    for (int i = idx; i < player1.card_sum - 1; i++) player1.player_card[i] = player1.player_card[i + 2];
    player1.menqianqing = false;
    player1.peng_sum++;
    if (zhuangtai == 2){
        int index = ui->listWidget_2->count();
        ui->listWidget_2->takeItem(index - 1);
    }
    if (zhuangtai == 3){
        int index = ui->listWidget_3->count();
        ui->listWidget_3->takeItem(index - 1);
    }
    hidemingpai();
    showcard();
    enable_discard();
    player1.card_sum--;
}

void MainWindow::on_mingpai2_clicked() // 杠
{
    player1.card_sum -= 3;
    for (int i = 0; i < 3; i++){
        QListWidgetItem* item = new QListWidgetItem(idx_to_icon(player1.player_card[idx + i].idx_in_all()), "");
        ui->listWidget_9->addItem(item);
        if (nowcard.owner == 0) player1.angang[player1.peng_sum * 4 + i] = player1.player_card[idx + i];
        else player1.gang[player1.peng_sum * 4 + i] = player1.player_card[idx + i];
    }
    QListWidgetItem* item = new QListWidgetItem(idx_to_icon(nowcard.idx_in_all()), "");
    ui->listWidget_9->addItem(item);
    if (nowcard.owner == 0) player1.angang[player1.peng_sum * 4 + 3] = nowcard;
    else player1.gang[player1.peng_sum * 4 + 3] = nowcard;
    for (int i = idx; i < player1.card_sum - 1; i++) player1.player_card[i] = player1.player_card[i + 3];
    if (nowcard.owner == 0){
        player1.angang_sum++;
    }
    else{
        player1.menqianqing = false;
        player1.gang_sum++;
    }
    baopai.push_back(*(paishan.end() - 1));
    paishan.erase(paishan.end() - 1);
    QListWidgetItem *itm = new QListWidgetItem(idx_to_icon((*(baopai.end() - 1)).idx_in_all()), "");
    ui->listWidget_10->addItem(itm);
    if (zhuangtai == 2){
        int index = ui->listWidget_2->count();
        ui->listWidget_2->takeItem(index);
    }
    if (zhuangtai == 3){
        int index = ui->listWidget_3->count();
        ui->listWidget_3->takeItem(index);
    }
    hidemingpai();
    player1.lingshang = true;
    mopai();
}


void MainWindow::on_skip_clicked() // 跳过
{
    if (zhuangtai == 1){
        hidemingpai();
        showcard();
        enable_discard();
    }
    if (zhuangtai == 2){
        hidemingpai();
        player3_action();
    }
    if (zhuangtai == 3){
        hidemingpai();
        mopai();
    }
}

void MainWindow::on_mingpai3_clicked() // 拔北
{
    QListWidgetItem *item = new QListWidgetItem(icon[23], "");
    ui->listWidget_8->addItem(item);
    player1.bei++;
    for (int i = idx; i < player1.card_sum - 1; i++){
        player1.player_card[i] = player1.player_card[i + 1];
    }
    hidemingpai();
    player1.lingshang = true;
    mopai();
}

void MainWindow::on_mingpai4_clicked() // 和
{
    disable_discard();
    hidemingpai();
    showaicard();
    QString output;
    for (int i = 0; i < player1.cnt; i++){
        if (player1.yizhong[i] == 28){
            QString temp = QString::number(player1.dora);
            output += yi[player1.yizhong[i]] + " " + temp + "番" + '\n';
        }
        else if (player1.yizhong[i] == 29){
            QString temp = QString::number(player1.rdora);
            output += yi[player1.yizhong[i]] + " " + temp + "番" + '\n';
        }
        else if (player1.yizhong[i] == 30){
            QString temp = QString::number(player1.bei);
            output += yi[player1.yizhong[i]] + " " + temp + "番" + '\n';
        }
        else output += yi[player1.yizhong[i]] + '\n';
    }
    QMessageBox::information(NULL, "你赢了！", output, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
