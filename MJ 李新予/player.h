#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "card.h"
#include "paixing.h"


class player
{
public:
    int bianhao;
    card player_card[14]; // 最后一位为临时空间，用于判断切牌及和牌
    int card_sum; // 手牌数
    card peng[20]; // 碰
    int peng_sum;
    card gang[20]; // 杠
    int gang_sum;
    int bei; // 拔北
    int score; // 点数
    int yizhong[20]; // 役种
    int cnt; // 役种个数
    bool menqianqing; // 门前清
    int tingpai[5]; // 听牌
    card angang[20]; // 暗杠
    int angang_sum;
    bool myturn; // 是否自摸
    bool reach; // 是否立直
    bool zhuangjia; // 庄家
    bool lingshang; // 岭上开花
    bool haidi; // 海底摸月
    bool yifa; // 一发
    int zifeng; // 自风
    int changfeng; // 场风
    int dora; // 手牌中宝牌数量
    int rdora; // 手牌中红宝牌数量
    paixing xing; // 打表所有合法牌型

    player(int i);

    int is_win(); // 是否和牌,如果和牌计算点数

    card discard(); // AI切牌

    int sum(int a[9]);
};

#endif // PLAYER_H
