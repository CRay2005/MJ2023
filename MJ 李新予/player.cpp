#include "player.h"
#include "card.h"
#include "paixing.h"
#include <algorithm>
#include <string>
#include <iostream>
#include<math.h>

player::player(int i)
{
    score = 35000;
    card_sum = 14;
    bei = 0;
    bianhao = i;
    peng_sum = 0;
    gang_sum = 0;
    angang_sum = 0;
    cnt = 0;
    menqianqing = true;
    myturn = false;
    reach = false;
    lingshang = false;
    haidi = false;
    yifa = false;
    dora = 0;
    rdora = 0;
    for (int j = 0; j < 10; j++){
        peng[j] = 0;
        gang[j] = 0;
    }
    for (int j = 0; j < 20; j++) yizhong[j] = 0;
    for (int j = 0; j < 5; j++) tingpai[j] = 0;
}

card player::discard(){
    card temp[13];
    int maxvalue = 0, maxidx = 0;
    for (int i = 0; i < card_sum; i++){
        int cnt = 0, value = 0;
        for (int j = 0; j < card_sum - 1; j++){
            if (j == i) cnt++;
            temp[j] = player_card[cnt++];
        }
        std::sort(temp, temp + card_sum - 1);
        for (int j = 0; j < card_sum - 2; j++){
            if (temp[j].type == temp[j + 1].type){
                if (j < card_sum - 3 && temp[j + 1].type == temp[j + 2].type && temp[j].num + 1 == temp[j + 1].num && temp[j].num + 2 == temp[j + 2].num) value += 30;
                else if (j < card_sum - 3 && temp[j + 1].type == temp[j + 2].type && temp[j].num== temp[j + 1].num && temp[j].num== temp[j + 2].num) value += 25;
                else if (temp[j].num == temp[j + 1].num){
                    if (temp[j].type == 3 && (temp[j].num == zifeng || temp[j].num == changfeng && temp[j].num > 3)) value += 30;
                    else value += 10;
                }
                else if (temp[j + 1].num == temp[j].num + 1){
                    if (temp[j].num == 0 || temp[j].num == 7) value += 3;
                    else value += 10;
                }
                else if (temp[j + 1].num == temp[j].num + 2){
                    if (temp[j].num != 0 && temp[j + 1].num != 8) value += 3;
                }
                else{
                    if (temp[j].type == 3){
                        if (temp[j].num == zifeng || temp[j].num == changfeng || temp[j].num > 3) value += 3;
                        else value -= 5;
                    }
                    else if (temp[j].type == 0) value -= 5;
                    else{
                        value -= abs(5 - temp[j].num);
                    }
                }
            }
            else{
                if (temp[j].type == 3){
                    if (temp[j].num == zifeng || temp[j].num == changfeng || temp[j].num > 3) value += 5;
                    else value -= 5;
                }
                else if (temp[j].type == 0) value -= 5;
                else{
                    value -= abs(5 - temp[j].num);
                }
            }
        }
        if (value > maxvalue){
            maxvalue = value;
            maxidx = i;
        }
    }
    card ret = player_card[maxidx];
    player_card[maxidx] = player_card[card_sum - 1];
    player_card[maxidx].owner = bianhao;
    return ret;
}

int player::sum(int a[9]){
    int ret = 0;
    for (int i = 0; i < 9; i++) ret += a[i];
    return ret;
}

int player::is_win(){
    cnt = 0; // 第几个役种
    int a = 0, m = 0, n = 0; // 点数、符数、番数
    int quetou = 0, kezi = 0, shunzi = 0;
    card temp[14];
    for (int i = 0; i < card_sum; i++) temp[i] = player_card[i];
    std::sort(temp, temp + card_sum);

    // 国士无双
    int shisanyao[13] = {0};
    for (int i = 0; i < card_sum; i++){
        if (temp[i].type != 3 && temp[i].num == 0){
            shisanyao[temp[i].type * 2]++;
        }
        else if (temp[i].type != 3 && temp[i].num == 8){
            shisanyao[temp[i].type * 2 + 1]++;
        }
        else if (temp[i].type == 3){
            shisanyao[temp[i].num + 6]++;
        }
    }
    for (int i = 0; i < 13; i++){
        if (!shisanyao[i]) break;
        if (i == 12){
            if (player_card[13].type != 3 && shisanyao[player_card[13].type * 2 + player_card[13].num / 8] == 2) yizhong[cnt++] = 1;
            else if (player_card[13].type == 3 && shisanyao[player_card[13].num + 6] == 2) yizhong[cnt++] = 1;
            else yizhong[cnt++] = 2;
        }
    }
    if (cnt > 0){
        a = 8000;
        return a;
    }

    // 七对子
    if (card_sum == 14){
        for (int i = 0; i < 14; i += 2){
            if (player_card[i].type != player_card[i + 1].type || player_card[i].num != player_card[i + 1].num) break;
            if (i == 12){
                yizhong[cnt++] = 3;
                n += 2;
                m += 25;
            }
        }
    }

    int temp_s[9] = {0}, temp_p[9] = {0}; // 索和饼的数量
    int temp_m[2] = {0}, temp_z[7] = {0}; // 万和字牌的数量
    for (int i = 0; i < card_sum; i++){
        if (player_card[i].type == 1) temp_s[player_card[i].num]++;
        else if (player_card[i].type == 2) temp_p[player_card[i].num]++;
        else if (player_card[i].type == 0){
            if (player_card[i].num == 1) temp_m[0]++;
            else temp_m[1]++;
        }
        else temp_z[player_card[i].num]++;
    }
    for (int i = 0; i < peng_sum; i++){
        if (peng[i * 3].type == 1) temp_s[peng[i * 3].num] += 3;
        else if (peng[i * 3].type == 2) temp_p[peng[i * 3].num] += 3;
        else if (peng[i * 3].type == 0){
            if (peng[i * 3].num == 1) temp_m[0] += 3;
            else temp_m[1] += 3;
        }
        else temp_z[peng[i * 3].num] += 3;
    }
    for (int i = 0; i < gang_sum; i++){
        if (gang[i * 4].type == 1) temp_s[gang[i * 4].num] += 3;
        else if (gang[i * 4].type == 2) temp_p[gang[i * 4].num] += 3;
        else if (gang[i * 4].type == 0){
            if (gang[i * 4].num == 1) temp_m[0] += 3;
            else temp_m[1] += 3;
        }
        else temp_z[gang[i * 4].num] += 3;
    }
    for (int i = 0; i < angang_sum; i++){
        if (angang[i * 4].type == 1) temp_s[angang[i * 4].num] += 3;
        else if (angang[i * 4].type == 2) temp_p[angang[i * 4].num] += 3;
        else if (angang[i * 4].type == 0){
            if (angang[i * 4].num == 1) temp_m[0] += 3;
            else temp_m[1] += 3;
        }
        else temp_z[angang[i * 4].num] += 3;
    }

//    std::cout << temp_m[0] << " " << temp_m[1] << std::endl;
//    for (int i = 0; i < 9; i++) std::cout << temp_s[i] << " ";
//    std::cout << std::endl;
//    for (int i = 0; i < 9; i++) std::cout << temp_p[i] << " ";
//    std::cout << std::endl;
//    for (int i = 0; i < 7; i++) std::cout << temp_z[i] << " ";
//    std::cout << std::endl;

    // 如果有单张幺九就一定不行,计算雀头、刻子
    for (int i = 0; i < 7; i++){
        if (temp_z[i] == 1 && cnt == 0) return 0;
        if (temp_z[i] == 2) quetou++;
        if (temp_z[i] == 3) kezi++;
    }
    if ((temp_m[0] == 1 || temp_m[1] == 1) && cnt == 0) return 0;
    if (temp_m[0] == 2) quetou++;
    if (temp_m[1] == 2) quetou++;
    if (temp_m[0] == 3) kezi++;
    if (temp_m[1] == 3) kezi++;
    if (quetou > 1 && cnt == 0) return 0;

    // 判断索和饼是否符合和牌型
    if ((!xing.isvalid[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]]\
            || !xing.isvalid[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]]) && cnt == 0) return 0;

    // 用雀头简单判断
    quetou += xing.quetou[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]];
    quetou += xing.quetou[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]];
    if (quetou != 1 && cnt == 0) return 0;

    // 计算刻子、顺子总数
    kezi += xing.kezi[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]];
    kezi += xing.kezi[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]];
    shunzi += xing.shunzi[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]];
    shunzi += xing.shunzi[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]];

    // 四暗刻
    if (kezi == 4 && menqianqing){
        int t = 0;
        for (int i = 0; i < card_sum; i++){
            if (player_card[14].samecard(player_card[i])) t++;
        }
        if (t == 1){
            yizhong[cnt++] = 4; // 单骑
            a = 8000;
        }
        else if (myturn) {
            yizhong[cnt++] = 5;
            a = 8000;
        }
        else{
            yizhong[cnt++] = 6; // 荣和三暗刻
            n += 2;
        }
    }
    // 绿一色
    if (temp_s[1] + temp_s[3] + temp_s[5] + temp_s[7] + temp_z[5] == 14 && menqianqing){
        yizhong[cnt++] = 7;
        a = 8000;
        return a;
    }

    // 字一色
    if (sum(temp_z) == 14){
        yizhong[cnt++] = 8;
        a = 8000;
        return a;
    }

    // 清一色、九莲宝灯
    if (sum(temp_s) == 14){
        if (temp_s[0] >= 3 && temp_s[1] >= 1 && temp_s[2] >= 1 && temp_s[3] >= 1 \
                && temp_s[4] >= 1 && temp_s[5] >= 1 && temp_s[6] >= 1 && temp_s[7] >= 1 && temp_s[8] >= 3 && menqianqing){
            int t = player_card[13].num;
            if (t == 0 || t == 8){
                if (temp_s[t] == 4) yizhong[cnt++] = 9;
                else yizhong[cnt++] = 10;
                a = 8000;
                return a;
            }
            else{
                if (temp_s[t] == 2) yizhong[cnt++] = 9;
                else yizhong[cnt++] = 10;
                a = 8000;
                return a;
            }
        }
        else {
            yizhong[cnt++] = 11;
            if (menqianqing) n += 6;
            else n += 5;
        }
    }
    if (sum(temp_p) == 14){
        if (temp_p[0] >= 3 && temp_p[1] >= 1 && temp_p[2] >= 1 && temp_p[3] >= 1 \
                && temp_p[4] >= 1 && temp_p[5] >= 1 && temp_p[6] >= 1 && temp_p[7] >= 1 && temp_p[8] >= 3 && menqianqing){
            int t = player_card[13].num;
            if (t == 0 || t == 8){
                if (temp_p[t] == 4) yizhong[cnt++] = 9;
                else yizhong[cnt++] = 10;
                a = 8000;
                return a;
            }
            else{
                if (temp_p[t] == 2) yizhong[cnt++] = 9;
                else yizhong[cnt++] = 10;
                a = 8000;
                return a;
            }
        }
        else {
            yizhong[cnt++] = 11;
            if (menqianqing) n += 6;
            else n += 5;
        }
    }


    // 大三元、小三元
    if (temp_z[4] >= 3 && temp_z[5] >= 3 && temp_z[6] >= 3){
        yizhong[cnt++] = 12;
        a = 8000;
        return a;
    }
    if (temp_z[4] >= 2 && temp_z[5] >= 2 && temp_z[6] >= 2 && cnt == 0){
        yizhong[cnt++] = 15;
        n += 2;
    }

    // 小四喜、大四喜
    if (temp_z[0] >= 3 && temp_z[1] >= 3 && temp_z[2] >= 3 && temp_z[3] >= 3){
        yizhong[cnt++] = 13;
        a = 8000;
        return a;
    }
    if (temp_z[0] >= 2 && temp_z[1] >= 2 && temp_z[3] >= 2 && temp_z[4] >= 2 && cnt == 0){
        yizhong[cnt++] = 14;
        a = 8000;
        return a;
    }

    // 清老头
    if (temp_m[0] + temp_m[1] + temp_s[0] + temp_s[8] + temp_p[0] + temp_p[8] == 14){
        yizhong[cnt++] = 33;
        a = 8000;
        return a;
    }

    // 断幺九
    if (temp_m[0] == 0 && temp_m[1] == 0 && temp_s[0] == 0 && temp_s[8] == 0 && temp_p[0] == 0 && temp_p[8] == 0\
            && temp_z[0] == 0 && temp_z[1] == 0 && temp_z[2] == 0 && temp_z[3] == 0 && temp_z[4] == 0 && temp_z[5] == 0 && temp_z[6] == 0){
        yizhong[cnt++] = 16;
        n++;
    }

    // 门前清自摸
    if (myturn && menqianqing){
        yizhong[cnt++] = 17;
        n++;
    }

    // 自风、场风
    if (temp_z[zifeng] == 3){
        yizhong[cnt++] = 18;
        n++;
    }
    if (temp_z[changfeng] == 3){
        yizhong[cnt++] = 19;
        n++;
    }

    // 三元牌
    if (temp_z[4] == 3){
        yizhong[cnt++] = 20;
        n++;
    }
    if (temp_z[5] == 3){
        yizhong[cnt++] = 21;
        n++;
    }
    if (temp_z[6] == 3){
        yizhong[cnt++] = 22;
        n++;
    }

    // 平和
    if (shunzi == 4){
        if (player_card[14].type == 1){
            int t = xing.quetou[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]];
            temp_s[player_card[14].num]--;
            if (xing.quetou[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]] == t){
                yizhong[cnt++] = 23;
                n++;
            }
            temp_s[player_card[14].num]++;
        }
        else if (player_card[14].type == 2){
            int t = xing.quetou[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]];
            temp_p[player_card[14].num]--;
            if (xing.quetou[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]] == t){
                yizhong[cnt++] = 23;
                n++;
            }
            temp_p[player_card[14].num]++;
        }
    }

    // 一杯口、二杯口难以实现

    // 岭上开花
    if (lingshang){
        yizhong[cnt++] = 24;
        n++;
    }

    // 海底摸月
    if (haidi){
        if (myturn){
            yizhong[cnt++] = 25;
            n++;
        }
        else{
            yizhong[cnt++] = 26;
            n++;
        }
    }

    // 一发
    if (yifa){
        yizhong[cnt++] = 27;
        n++;
    }

    // 宝牌
    if (dora > 0){
        yizhong[cnt++] = 28;
        n += dora;
    }
    if (rdora > 0){
        yizhong[cnt++] = 29;
        n += rdora;
    }
    if (bei > 0){
        yizhong[cnt++] = 30;
        n += bei;
    }

    // 三杠子
    if (gang_sum + angang_sum == 3){
        yizhong[cnt++] = 31;
        n += 2;
    }

    // 混老头
    if (temp_m[0] + temp_m[1] + temp_s[0] + temp_s[8] + temp_p[0] + temp_p[8] + temp_z[0] + temp_z[1] + temp_z[2]\
            + temp_z[3] + temp_z[4] + temp_z[5] + temp_z[6] == 14){
        yizhong[cnt++] = 32;
        n += 2;
    }

    // 混全带幺九
    if (xing.hunquandai[temp_p[0]][temp_p[1]][temp_p[2]][temp_p[3]][temp_p[4]][temp_p[5]][temp_p[6]][temp_p[7]][temp_p[8]] && \
            xing.hunquandai[temp_s[0]][temp_s[1]][temp_s[2]][temp_s[3]][temp_s[4]][temp_s[5]][temp_s[6]][temp_s[7]][temp_s[8]]){
        if (temp_m[0] + temp_m[1] + temp_z[0] + temp_z[1] + temp_z[2] + temp_z[3] + temp_z[4] + temp_z[5] + temp_z[6] == 0){
            if (menqianqing) n += 3;
            else n += 2;
            yizhong[cnt++] = 36;
        }
        else{
            if (menqianqing) n += 2;
            else n++;
            yizhong[cnt++] = 34;
        }
    }

    // 一气通贯（不严谨）
    for (int i = 0; i < 9; i++){
        if (temp_s[i] == 0) break;
        if (i == 8){
            yizhong[cnt++] = 35;
            if (menqianqing) n += 2;
            else n++;
        }
    }
    for (int i = 0; i < 9; i++){
        if (temp_p[i] == 0) break;
        if (i == 8){
            yizhong[cnt++] = 35;
            if (menqianqing) n += 2;
            else n++;
        }
    }

    // 混一色
    if (sum(temp_s) == 0 || sum(temp_p) == 0){
        if (menqianqing) n += 3;
        else n += 2;
        yizhong[cnt++] = 37;
    }

    // 对对和
    if (kezi == 4){
        yizhong[cnt++] = 38;
        n += 2;
    }

    // 计算符数、点数
    if (cnt != 0) m += 20;
    if (menqianqing && !myturn) m += 10;
    if (myturn) m += 2;
    // 单张、边张、嵌张雀头难以计算
    if (temp_m[0] == 2 || temp_m[1] == 2 || temp_z[zifeng] == 2 || temp_z[changfeng] == 2) m += 2;
    for (int i = 0; i < peng_sum; i += 3){
        if (peng[i * 3].type != 1 && peng[i * 3].type != 2) m += 4;
        else if (peng[i * 3].num == 0 || peng[i * 3].num == 8) m += 4;
        else m += 2;
    }
    for (int i = 0; i < gang_sum; i += 4){
        if (gang[i * 4].type != 1 && gang[i * 4].type != 2) m += 16;
        else if (gang[i * 4].num == 0 || gang[i * 4].num == 8) m += 16;
        else m += 8;
    }
    for (int i = 0; i < gang_sum; i += 4){
        if (angang[i * 4].type != 1 && angang[i * 4].type != 2) m += 32;
        else if (angang[i * 4].num == 0 || angang[i * 4].num == 8) m += 32;
        else m += 16;
    }
    int anke = kezi - peng_sum - angang_sum - gang_sum;
    m += 2 * anke; // 暗刻幺九难以计算

    m = m / 10 * 10;
    if (cnt != 0) a = m * pow(2, n + 2);
    a = a / 100 * 100;
    return a;
}
