#ifndef CARD_H
#define CARD_H

class card
{
public:
    int type; // 0, 1, 2, 3分别对应万、饼、索、字
    int num; // 0, 1, 2, 3, 4, 5, 6, 7, 8分别对应东南西北白发中或123456789数牌
    int idx; // 0, 1, 2, 3,其中0对应红宝牌
    int owner; // 1, 2, 3对应3个player
    bool dora; // 是否为宝牌

    card();
    card(int i);

    int idx_in_all(); // 排序的依据

    bool operator<(card& c);
    bool operator>(card& c);

    bool samecard(card& c);
};

#endif // CARD_H
