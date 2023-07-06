#include "paixing.h"

paixing::paixing()
{
    isvalid[2][0][0][0][0][0][0][0][0] = 1; quetou[2][0][0][0][0][0][0][0][0] = 1; hunquandai[2][0][0][0][0][0][0][0][0] = 1; // 11
    isvalid[0][2][0][0][0][0][0][0][0] = 1; quetou[0][2][0][0][0][0][0][0][0] = 1;
    isvalid[0][0][2][0][0][0][0][0][0] = 1; quetou[0][0][2][0][0][0][0][0][0] = 1;
    isvalid[0][0][0][2][0][0][0][0][0] = 1; quetou[0][0][0][2][0][0][0][0][0] = 1;
    isvalid[0][0][0][0][2][0][0][0][0] = 1; quetou[0][0][0][0][2][0][0][0][0] = 1;
    isvalid[0][0][0][0][0][2][0][0][0] = 1; quetou[0][0][0][0][0][2][0][0][0] = 1;
    isvalid[0][0][0][0][0][0][2][0][0] = 1; quetou[0][0][0][0][0][0][2][0][0] = 1;
    isvalid[0][0][0][0][0][0][0][2][0] = 1; quetou[0][0][0][0][0][0][0][2][0] = 1;
    isvalid[0][0][0][0][0][0][0][0][2] = 1; quetou[0][0][0][0][0][0][0][0][2] = 1; hunquandai[0][0][0][0][0][0][0][0][2] = 1; // 99
    isvalid[3][0][0][0][0][0][0][0][0] = 1; kezi[3][0][0][0][0][0][0][0][0] = 1; hunquandai[3][0][0][0][0][0][0][0][0] = 1; // 111
    isvalid[0][3][0][0][0][0][0][0][0] = 1; kezi[0][3][0][0][0][0][0][0][0] = 1;
    isvalid[0][0][3][0][0][0][0][0][0] = 1; kezi[0][0][3][0][0][0][0][0][0] = 1;
    isvalid[0][0][0][3][0][0][0][0][0] = 1; kezi[0][0][0][3][0][0][0][0][0] = 1;
    isvalid[0][0][0][0][3][0][0][0][0] = 1; kezi[0][0][0][0][3][0][0][0][0] = 1;
    isvalid[0][0][0][0][0][3][0][0][0] = 1; kezi[0][0][0][0][0][3][0][0][0] = 1;
    isvalid[0][0][0][0][0][0][3][0][0] = 1; kezi[0][0][0][0][0][0][3][0][0] = 1;
    isvalid[0][0][0][0][0][0][0][3][0] = 1; kezi[0][0][0][0][0][0][0][3][0] = 1;
    isvalid[0][0][0][0][0][0][0][0][3] = 1; kezi[0][0][0][0][0][0][0][0][3] = 1; hunquandai[0][0][0][0][0][0][0][0][3] = 1; // 999
    isvalid[1][1][1][0][0][0][0][0][0] = 1; shunzi[1][1][1][0][0][0][0][0][0] = 1; hunquandai[1][1][1][0][0][0][0][0][0] = 1; // 123
    isvalid[0][1][1][1][0][0][0][0][0] = 1; shunzi[0][1][1][1][0][0][0][0][0] = 1;
    isvalid[0][0][1][1][1][0][0][0][0] = 1; shunzi[0][0][1][1][1][0][0][0][0] = 1;
    isvalid[0][0][0][1][1][1][0][0][0] = 1; shunzi[0][0][0][1][1][1][0][0][0] = 1;
    isvalid[0][0][0][0][1][1][1][0][0] = 1; shunzi[0][0][0][0][1][1][1][0][0] = 1;
    isvalid[0][0][0][0][0][1][1][1][0] = 1; shunzi[0][0][0][0][0][1][1][1][0] = 1;
    isvalid[0][0][0][0][0][0][1][1][1] = 1; shunzi[0][0][0][0][0][0][1][1][1] = 1; hunquandai[0][0][0][0][0][0][1][1][1] = 1; // 789
    int temp1[9] = {2, 0, 0, 0, 0, 0, 0, 0, 0};
    int temp2[9] = {0, 2, 0, 0, 0, 0, 0, 0, 0};
    int temp3[9] = {0, 0, 2, 0, 0, 0, 0, 0, 0};
    int temp4[9] = {0, 0, 0, 2, 0, 0, 0, 0, 0};
    int temp5[9] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    int temp6[9] = {0, 0, 0, 0, 0, 2, 0, 0, 0};
    int temp7[9] = {0, 0, 0, 0, 0, 0, 2, 0, 0};
    int temp8[9] = {0, 0, 0, 0, 0, 0, 0, 2, 0};
    int temp9[9] = {0, 0, 0, 0, 0, 0, 0, 0, 2};
    int temp10[9] = {3, 0, 0, 0, 0, 0, 0, 0, 0};
    int temp11[9] = {0, 3, 0, 0, 0, 0, 0, 0, 0};
    int temp12[9] = {0, 0, 3, 0, 0, 0, 0, 0, 0};
    int temp13[9] = {0, 0, 0, 3, 0, 0, 0, 0, 0};
    int temp14[9] = {0, 0, 0, 0, 3, 0, 0, 0, 0};
    int temp15[9] = {0, 0, 0, 0, 0, 3, 0, 0, 0};
    int temp16[9] = {0, 0, 0, 0, 0, 0, 3, 0, 0};
    int temp17[9] = {0, 0, 0, 0, 0, 0, 0, 3, 0};
    int temp18[9] = {0, 0, 0, 0, 0, 0, 0, 0, 3};
    int temp19[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
    int temp20[9] = {0, 1, 1, 1, 0, 0, 0, 0, 0};
    int temp21[9] = {0, 0, 1, 1, 1, 0, 0, 0, 0};
    int temp22[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
    int temp23[9] = {0, 0, 0, 0, 1, 1, 1, 0, 0};
    int temp24[9] = {0, 0, 0, 0, 0, 1, 1, 1, 0};
    int temp25[9] = {0, 0, 0, 0, 0, 0, 1, 1, 1};
    ditui(temp1);
    ditui(temp2);
    ditui(temp3);
    ditui(temp4);
    ditui(temp5);
    ditui(temp6);
    ditui(temp7);
    ditui(temp8);
    ditui(temp9);
    ditui(temp10);
    ditui(temp11);
    ditui(temp12);
    ditui(temp13);
    ditui(temp14);
    ditui(temp15);
    ditui(temp16);
    ditui(temp17);
    ditui(temp18);
    ditui(temp19);
    ditui(temp20);
    ditui(temp21);
    ditui(temp22);
    ditui(temp23);
    ditui(temp24);
    ditui(temp25);
}

int paixing::sum(int a[9]){
    int ans = 0;
    for (int i = 0; i < 9; i++) ans += a[i];
    return ans;
}

void paixing::ditui(int zhuangtai[9]){
    if (sum(zhuangtai) > 12) return;
    int temp[9];
    for (int i = 0; i < 9; i++) temp[i] = zhuangtai[i];
    int last_idx = 0;
    for (int i = 0; i < 9; i++){
        if (temp[i]) last_idx = i;
    }
    int que = quetou[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]];
    int hun = hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]];
    int ke = kezi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]];
    int shun = shunzi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]];
    if (!que){ // 添加一个雀头
        for (int i = last_idx; i < 9; i++){
            if (temp[i] <= 2){
                temp[i] += 2;
                quetou[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 1;
                isvalid[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 1;
                kezi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = ke;
                shunzi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = shun;
                if (i != 8) hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 0;
                else hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = hun;
                ditui(temp);
                temp[i] -= 2;
            }
        }
    }
    for (int i = last_idx; i < 9; i++){
        if (temp[i] <= 1){ // 添加一个刻子
            temp[i] += 3;
            isvalid[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 1;
            quetou[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = que;
            kezi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = ke + 1;
            shunzi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = shun;
            if (i != 8) hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 0;
            else hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = hun;
            ditui(temp);
            temp[i] -= 3;
        }
        if (i >= 2 && temp[i - 2] <= 3 && temp[i - 1] <= 3 && temp[i] <= 3){ // 添加一个顺子
            temp[i]++;
            temp[i - 1]++;
            temp[i - 2]++;
            isvalid[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 1;
            quetou[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = que;
            kezi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = ke;
            shunzi[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = shun + 1;
            if (i != 8 && i != 2) hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = 0;
            else hunquandai[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]][temp[8]] = hun;
            ditui(temp);
            temp[i]--;
            temp[i - 1]--;
            temp[i - 2]--;
        }
    }
}
