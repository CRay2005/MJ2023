#include "card.h"

card::card(){
    owner = 0;
    idx = 0;
    num = 0;
    type = 0;
    dora = false;
}

card::card(int i)
{
    owner = 0;
    idx = i % 4;
    i /= 4;
    num = i % 9;
    i /= 9;
    type = i % 4;
    if ((type == 1 || type == 2) && num == 5 && idx == 0) dora = true;
    else dora = false;
}

int card::idx_in_all(){
    return type * 36 + num * 4 + idx;
}

bool card::operator<(card& c){
    return this->idx_in_all() < c.idx_in_all();
}

bool card::operator>(card& c){
    return this->idx_in_all() > c.idx_in_all();
}

bool card::samecard(card& c){
    return (type == c.type) && (num == c.num);
}
