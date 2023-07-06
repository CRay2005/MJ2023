#ifndef PAIXING_H
#define PAIXING_H

class paixing
{
public:
    paixing();

    int isvalid[5][5][5][5][5][5][5][5][5], shunzi[5][5][5][5][5][5][5][5][5], kezi[5][5][5][5][5][5][5][5][5];
    int quetou[5][5][5][5][5][5][5][5][5], hunquandai[5][5][5][5][5][5][5][5][5];

    int sum(int a[9]);

    void ditui(int zhuangtai[9]);

};

#endif // PAIXING_H
