/*
    //撤销
    private void chexiao() {
        if (state.size() > 0) {
            clear();
            yichu_pane.getChildren().clear();
            Config.yuce.clear();

            Map<String, Object> stringObjectMap = state.get(state.size() - 1);
            state.remove(state.size() - 1);
            dapaifangx = (int) stringObjectMap.get("打牌方向");
            directions.forEach(direction -> {
                direction.setPre_pai("");
                direction.getYina_hupai().clear();
                direction.getHupaiPanel().getChildren().clear();
                direction.setQue((int) stringObjectMap.get("que_" + direction.getDirection()));
                direction.setHu((int) stringObjectMap.get("hu_" + direction.getDirection()));
                direction.setKehu((boolean) stringObjectMap.get("kehu_" + direction.getDirection()));
            });
            Config.weina.clear();
            Config.weina.addAll((HashSet<Mj>) stringObjectMap.get("config_weina"));
            Config.yina.clear();
            Config.yina.addAll((LinkedList<Mj>) stringObjectMap.get("yina"));
            Config.yuce.clear();
            Config.yuce.addAll((LinkedList<Mj>) stringObjectMap.get("yuce"));
            Config.yichu.clear();
            Config.yichu.addAll((LinkedList<Mj>) stringObjectMap.get("yichu"));
            weina.clear();
            weina.addAll((LinkedList<Mj>) stringObjectMap.get("weina"));
            for (Mj mj : Config.weina) {
                mj.getWeina_imageView().setUserData(mj);
                if (mj.isMaima()) {
                    mj.getWeina_imageView().setStyle("-fx-opacity: 0.5");
                    if (mj.getOther() != null) {
                        mj.getOther().setVisible(false);
                    }
                    mj.getWeina_imageView().setOnMouseClicked(event -> {
                        mj.getWeina_imageView().setStyle("-fx-opacity: 1");
                        if (mj.getOther() != null) {
                            mj.getOther().setVisible(true);
                        }
                        mj.setMaima(false);
                        Config.weina.forEach(mj1 -> {
                            if (mj1.equals(mj)) {
                                mj1.setMaima(false);
                            }
                        });
                        weina.forEach(mj1 -> {
                            if (mj1.equals(mj)) {
                                mj1.setMaima(false);
                            }
                        });
                        //清除
                        clear();
                        directions.forEach(direction -> {
                            direction.setPre_pai("");
                            direction.getYina_hupai().clear();
                            direction.getHupaiPanel().getChildren().clear();
                        });
                        Config.yuce.clear();
                        yucepaiAfterMopai(0, dapaifangx);
                        displayYinaPai();
                        mj.getWeina_imageView().setOnMouseClicked(event1 -> {
                            napaisuanfa(mj);
                        });
                    });
                } else {
                    if (!mj.getSimo()) {
                        mj.getWeina_imageView().setVisible(true);
                        if (mj.getOther() != null) {
                            mj.getOther().setVisible(true);
                        }
                    } else {
                        mj.getWeina_imageView().setVisible(false);
                        if (mj.getOther() != null) {
                            mj.getOther().setVisible(false);
                        }
                    }
                }
            }
            if (Config.systemConfig.chupaixianshi == 1) {
                Config.yichu.sort(new ComparatorMjResult());
            }
            Config.yichu.forEach(mj1 -> {
                mj1.getYichu_imageView().getStyleClass().clear();
                mj1.getYichu_imageView().setImage(Config.getImageByNumber(mj1.getResult()));
                yichu_pane.getChildren().add(mj1.getYichu_imageView());
            });
            displayYinaPai();
        } else if (huanhoupai_yixuan.size() > 0) {
            Config.yina.forEach(mj -> {
                if (huanhoupai_yixuan.contains(mj)) {
                    mj.getYina_imageView().addClass("huanpai_biaoji");
                }
            });
            huanShouPai();
        }
    }

    //还原牌
    private void huanyuan() {
        guo_combobox.setValue("------");
        bottom_panel.getChildren().clear();
        bottom_panel.getChildren().add(bottom_zhuang_label);
        clear();
        directions.forEach(direction -> {
            direction.setPre_pai("");
            direction.getYina_hupai().clear();
            direction.getHupaiPanel().getChildren().clear();
        });
        yinapai = false;
        zhuangjia = -1;
        directions.forEach(direction -> {
            direction.setQue(-1);
            direction.setQiangzhiHu(0);
            direction.setHu(0);
            direction.setKehu(false);
            direction.setMo(0);
            direction.setHu_mj(null);
            direction.setDiyizhangda_mj(null);
        });


        Config.yina.clear();
        Config.yuce.clear();
        yichu_pane.getChildren().clear();
        main_panel.getChildren().removeAll(yichu_pane, zhuangPanel, yuceYinaPanel);
        Config.yichu.clear();
        weina.clear();
        Config.weina.forEach(mj -> {
            mj.caisheng = false;
            if (mj.kedi_caisheng) {
                mj.kedi_caisheng = false;
                if (mj.yuanpai > 0) {
                    mj.setResult(mj.yuanpai);
                    mj.yuanpai = 0;
                }
            }
            mj.setPaizhuantai(0);
            mj.setChupai_direction(-1);
            mj.setSimo(false);
            mj.setIsque(false);
            mj.setYuce_direction(-1);
            mj.setNapai_direction(-1);
            main_panel.getChildren().removeAll(mj.getWeina_imageView(), mj.getOther());
        });
        Config.weina.clear();
        weina_backup.forEach(mj -> {
            Mj mj1 = (Mj) mj.clone();
            Config.weina.add(mj1);
        });
        dapaifangx = -1;
        if (Config.weina.size() > 0) {
            displayWeinaPai();
        }
    }

 */



//#include "majhong.h"

//#include <iostream>
//using std::cout; using std::endl;

//#include <list>
//using std::list;

//#include <vector>
//using std::vector;



//#include <algorithm>
//using std::sort;

//#include <string>
//using std::string;

//#include<time.h>

//#include <set>
//using std::set;

//#include <unordered_map>
//using std::pair;
//using std::unordered_map;

//#include <unordered_set>
//using std::unordered_set;

////unordered_map按值排序（先转vector，排序后再存进去）
//bool cmpByValue(const pair<int, int>& l, const pair<int, int>& r)
//{
//    return l.second > r.second;
//}

//bool cmpByKey(const pair<int, int>& l, const pair<int, int>& r){
//    return l.first > r.first;
//}

//template<> struct std::greater<Mj>
//        {
//        bool operator()(Mj x,  Mj y) const{// 重载运算符
//            double r0= x.getResult();
//            double r1= y.getResult();

//            if(r0==56.0){
//                r0=10.0;
//            }if(r1==56.0){
//                r1=10.0;
//            }

//            if(r0==57.0){
//                r0=30.0;
//            }if(r1==57.0){
//                r1=30.0;
//            }

//            if(r0==58.0){
//                r0=20.0;
//            }if(r1==58.0){
//                r1=20.0;
//            }

//            if(r0==52.0){
//                r0=38.0;
//            }if(r1==52.0){
//                r1=38.0;
//            }
//            if(r0==53.0){
//                r0=34.5;
//            }
//            if(r1==53.0){
//                r1=34.5;
//            }

//            double r = (r0 - r1);

//            if(r > 0){
//                return 1;
//            }
//            if(r < 0){
//                return -1;
//            }
//            return 0;
//            }
//        };

//////随机打乱list顺序
////template <class T>
////void shuffle(list<T>& List) {
////    vector<T> tempList;
////    for(auto i:List){
////        tempList.push_back(i);
////    }

////    std::random_shuffle(tempList.begin(), tempList.end());

////    List.clear();
////    for(auto i: tempList){
////        List.push_back(i);
////    }
////}

////在unordered_map中按键搜索，找到返回值，找不到返回默认值
//int getOrDefault(const unordered_map<int, int>& mp, const int findKey,const int defaultValue){
//    if(mp.find(findKey) != mp.end()){
//        return mp.find(findKey)->second;
//    }else{
//        return defaultValue;
//    }
//}

//void deleteList(list<Mj>& suanpai, Mj mj){
//    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//        if(*i == mj){
//            suanpai.erase(i);
//            break;
//        }
//    }
//}


//bool HuPaiKit::hupaipanduan(list<Mj> cards, SystemConfig systemConfig) {
//    list<Mj> pais = cards;//复制一根备份
//    list<Mj> caisheng_list;

//    //pais全部财神放到list中
//    for (list<Mj>::const_iterator i = pais.begin(); i != pais.end(); ++i) {
//        if (i->isCaisheng()) {
//            caisheng_list.push_back(*i);
//        }
//    }

//    //有财神
//    if (caisheng_list.size() > 0) {
//        //删除财神
//        list<Mj>::iterator iterator3 = pais.begin();
//        for ( iterator3 = pais.begin(); iterator3 != pais.end(); ++iterator3) {
//            if(iterator3->isCaisheng()){
//               // pais.remove(*iterator3);
//                pais.erase(iterator3);
//            }
//        }

//        unordered_map<int, int> Map;//新建一个unordered_map集合，用来保存重复的次数
//        for (list<Mj>::const_iterator iter = pais.begin(); iter != pais.end(); ++iter) {
//            if (iter->getResult()) {//判断是否已经有该数值，如有，则将次数加1
//                Map[iter->getResult()]++;
//            } else {
//                Map[iter->getResult()] = 1;
//            }
//        }

//        //二五八将
//        list<int> result_count;//存入unordered_map的值
//        for (unordered_map<int, int>::iterator i = Map.begin(); i != Map.end(); ++i) {
//            result_count.push_back(i->second);
//        }

//        if (systemConfig.erwubajiang) {
//            list<int> jiangs;

//            if (caisheng_list.size() >= 2) {
//                jiangs.push_back(caisheng_list.begin()->getResult());
//            }

//            for (unordered_map<int, int>::const_iterator iter = Map.begin(); iter != Map.end(); ++iter) {
//                if (iter->first < 30
//                    && (iter->second >= 1 &&
//                    (iter->first % 10 == 2 || iter->first % 10 == 5 || iter->first % 10 == 8))
//                    && iter->second < 4) {
//                    jiangs.push_back(iter->first);
//                }
//            }

//            if (jiangs.size() < 1) {
//                return false;
//            }

//            for (list<int>::iterator jiang = jiangs.begin(); jiang != jiangs.end(); ++jiang) {
//                int caisheng_count = caisheng_list.size();

//                if ((*jiang) == caisheng_list.begin()->getResult() && getOrDefault(Map, *jiang, 0) == 0) {
//                    caisheng_count -= 2;
//                }

//                list<Mj> suanpai = pais;
//                short shuliang = 0;
//                list<Mj>::iterator iterator1;

//                for (iterator1 = suanpai.begin(); iterator1 != suanpai.end(); ++iterator1) {
//                   // Mj item = *(++iterator1);
//                    if ((Map.find(iterator1->getResult()) != Map.end() && Map[iterator1->getResult() == 4])) {
//                        suanpai.erase(iterator1);
//                    } else if (shuliang < 2 && iterator1->getResult() == (*jiang)) {
//                        suanpai.erase(iterator1);
//                        if (Map.find(*jiang) != Map.end() && Map[*jiang] == 1) {
//                            caisheng_count--;
//                        }
//                        shuliang++;
//                    }
//                }

//                int cnt2 = 0, cnt4 = 0, cnt5 = 0;
//                for (list<int>::const_iterator i = result_count.begin(); i != result_count.end(); ++i) {
//                    if (*i == 2) {
//                        cnt2++;
//                    }
//                    if (*i == 4) {
//                        cnt4++;
//                    }
//                    if (*i == 5) {
//                        cnt5++;
//                    }
//                }

//                //所有的牌全部都能组成2个 胡牌
//                if (cnt2 == 14 - caisheng_count * 2) {
//                    return true;
//                }
//                //有至少两个4张一样的牌，其余牌都是对子 胡牌
//                if (cnt4 > 1 && (cnt2 * 2 + cnt4 * 4 == suanpai.size())) {
//                    return true;
//                }
//                //有4张一样的牌且没杠，其余牌都是对子 胡牌
//                if (cnt2 == 5 && cnt4 == 1) {
//                    return true;
//                }
//                //d都是四个 胡牌
//                if (cnt4 * 4 == suanpai.size()) {
//                    return true;
//                }

//                for (unordered_map<int, int>::const_iterator i = Map.begin(); i != Map.end(); ++i) {
//                    switch (i->second) {
//                        case 1:
//                            if ((i->first == (*jiang)) && i->first > 30) {
//                                caisheng_count -= 2;
//                            }
//                            break;
//                        case 2:
//                            break;
//                        case 3:
//                            break;
//                        case 4:
//                            break;
//                    }
//                }

//                if (caisheng_count < 0) {
//                    continue;
//                }

//                if ((suanpai.size() + caisheng_count) % 3 != 0) {
//                    continue;
//                }

//                //移除顺子
//                //先排序
//                suanpai.sort(ComparatorMjResult);//会掉函数
//                //suanpai.sort(std::greater<Mj>());//重载运算符函数
//                int b = (suanpai.size() + caisheng_count) / 3;
//                for (int j = 0; j < b; ++j) {
//                    if (caisheng_count < 0) {
//                        break;
//                    }
//                    if (suanpai.size() == 1 && caisheng_count == 2) {
//                        return true;
//                    }
//                    if (suanpai.size() == 2 && caisheng_count == 1 &&
//                        suanpai.begin()->getResult() == (++suanpai.begin())->getResult()) {
//                        return true;
//                    }
//                    Mj mj = *(suanpai.begin());
//                    if (getOrDefault(Map,mj.getResult(), 0) > 2 && mj.getResult() != *(jiang)) {
//                        list<Mj>::iterator i, j, k;
//                        i = (++suanpai.begin());
//                        j = (++suanpai.begin());
//                        k = ++j;
//                        if (mj.getResult() == i->getResult()
//                        && mj.getResult() == k->getResult()) {
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                           deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            if (suanpai.size() == 0) {
//                                return true;
//                            }
//                            continue;
//                        }
//                    }
//                  deleteList(suanpai, mj);
//                    if (getOrDefault(Map,mj.getResult(), 0) == 2 && mj.getResult() != *(jiang)) {
//                        if (getOrDefault(Map,mj.getResult() + 1, 0) == 2 && mj.getResult() + 1 != *(jiang)){
//                            if (mj.getResult() == suanpai.begin()->getResult()) {
//                                mj = *(suanpai.begin());
//                                deleteList(suanpai, mj);
//                                caisheng_count--;
//                                if (suanpai.size() == 0) {
//                                    return true;
//                                }
//                                continue;
//                            }
//                        }
//                    }
//                    bool has = false;
//                    list<Mj>::iterator iterator2;
//                    for (iterator2 = suanpai.begin(); iterator2 != suanpai.end(); ++iterator2) {
//                        if (mj.getResult() + 1 == iterator2->getResult() &&
//                            (mj.getResult() / 10) == (iterator2->getResult() / 10)) {
//                            suanpai.erase(iterator2);
//                            has = true;
//                            break;
//                        }
//                    }
//                    if (!has) {
//                        caisheng_count--;
//                    }
//                    has = false;
//                    for (iterator2 = suanpai.begin(); iterator2 != suanpai.end(); ++iterator2) {
//                        if (mj.getResult() + 2 == iterator2->getResult() &&
//                            (mj.getResult() / 10) == (iterator2->getResult() / 10)) {
//                            suanpai.erase(iterator2);
//                            has = true;
//                            break;
//                        }
//                    }
//                    if (!has) {
//                        caisheng_count--;
//                    }
//                    if (caisheng_count < 0) {
//                        break;
//                    }
//                    if ((suanpai.size() + caisheng_count) % 3 != 0) {
//                        break;
//                    }
//                    if (suanpai.size() == 0) {
//                        return true;
//                    }
//                }
//                if (suanpai.size() == 0 && caisheng_count >= 0) {
//                    return true;
//                }
//            }
//        }else{
//            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
//            for (list<int>::const_iterator i = result_count.begin(); i != result_count.end(); ++i) {
//                if (*i == 1) {
//                    cnt1++;
//                }
//                if (*i == 2) {
//                    cnt2++;
//                }
//                if (*i == 3) {
//                    cnt3++;
//                }
//            }
//            //所有的牌全部都能组成2个 胡牌
//            if (systemConfig.xiaoqidui == 1 && (14 - cnt2 * 2 - cnt1 == caisheng_list.size()) &&
//                cnt1 == caisheng_list.size()) {
//                return true;
//            }
//            if (systemConfig.xiaoqidui == 1 && (14 - cnt2 * 2 - cnt3 * 4 - cnt1 == caisheng_list.size() - cnt3) &&
//                (caisheng_list.size() == cnt1 + cnt3)) {
//                return true;
//            }

//            if (pais.size() == 14) {
//                list<Mj> mjs = pais;
//                mjs.sort(ComparatorMjResult);
//                int xiaoqidui_caisheng_count = caisheng_list.size();
//                for (unordered_map<int, int>::const_iterator i = Map.begin(); i != Map.end(); ++i) {
//                    switch (i->second) {
//                        case 1:
//                            for (list<Mj>::iterator iterator6 = mjs.begin(); iterator6 !=  mjs.end(); ++iterator6) {
//                                if (i->first == iterator6->getResult() && (i->first / 10 == iterator6->getResult() / 10)) {
//                                    mjs.erase(iterator6);
//                                }
//                            }
//                            xiaoqidui_caisheng_count--;
//                            break;
//                        case 2:
//                            for (list<Mj>::iterator iterator5 = mjs.begin(); iterator5 !=  mjs.end(); ++iterator5) {
//                                if (i->first == iterator5->getResult() && (i->first / 10 == iterator5->getResult() / 10)) {
//                                    mjs.erase(iterator5);
//                                }
//                            }
//                            break;
//                        case 3:
//                            for (list<Mj>::iterator iterator6 = mjs.begin(); iterator6 !=  mjs.end(); ++iterator6) {
//                                if (i->first == iterator6->getResult() && (i->first / 10 == iterator6->getResult() / 10)) {
//                                    mjs.erase(iterator6);
//                                }
//                            }
//                            xiaoqidui_caisheng_count--;
//                            break;
//                        case 4:
//                            for (list<Mj>::iterator iterator5 = mjs.begin(); iterator5 !=  mjs.end(); ++iterator5) {
//                                if (i->first == iterator5->getResult() && (i->first / 10 == iterator5->getResult() / 10)) {
//                                    mjs.erase(iterator5);
//                                }
//                            }
//                            break;
//                    }
//                }
//                if (systemConfig.xiaoqidui == 1 && (mjs.size() == 0) && (xiaoqidui_caisheng_count == 0 ||
//                                                              (xiaoqidui_caisheng_count > 0 &&
//                                                               xiaoqidui_caisheng_count % 2 == 0))) {
//                    return true;
//                }
//            }

//            list<int> jiangs;
//            if (caisheng_list.size() >= 2) {
//                jiangs.push_back(caisheng_list.begin()->getResult());
//            }
//            for (unordered_map<int, int>::const_iterator iter = Map.begin(); iter != Map.end(); ++iter) {
//                if (iter->second >= 1 && iter->second < 4) {
//                    jiangs.push_back(iter->first);
//                }
//            }
//            for (list<int>::iterator jiang = jiangs.begin(); jiang != jiangs.end(); ++jiang) {
//                int caisheng_count = caisheng_list.size();
//                if ((*jiang) == caisheng_list.begin()->getResult() && getOrDefault(Map, *jiang, 0) == 0) {
//                    caisheng_count -= 2;
//                }
//                list<Mj> suanpai = pais;
//                short shuliang = 0;
//                list<Mj>::iterator iterator1;
//                for (iterator1 = suanpai.begin(); iterator1 != suanpai.end(); ++iterator1) {
//                    if (shuliang < 2 && iterator1->getResult() == (*jiang)) {
//                        suanpai.erase(iterator1);
//                        if (getOrDefault(Map, * jiang, 0) == 1) {
//                            caisheng_count--;
//                        }
//                        shuliang++;
//                    }
//                }

//                if (systemConfig.dongnanxibeizhongfabaishunzi == 1) {
//                    list<Mj> zipai;
//                    for (list<Mj>::const_iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                        if (i->getResult() > 30) {
//                            zipai.push_back(*i);
//                        }
//                    }
//                    zipai.sort(ComparatorMjResult);
//                    int b = zipai.size() / 3;
//                    for (int j = 0; j < b; ++j) {
//                        Mj mj = *(zipai.begin());
//                        if (getOrDefault(Map, mj.getResult(), 0) > 2 && mj.getResult() != *jiang) {
//                            list<Mj>::iterator zipaiI, temp, zipaiJ;
//                            zipaiI = (++zipai.begin());
//                            temp = (++zipai.begin());
//                            zipaiJ = (++temp);
//                            if (mj.getResult() == zipaiI->getResult() && mj.getResult() == zipaiJ->getResult()) {
//                                deleteList(suanpai, mj);
//                                mj = *(zipai.begin());
//                                deleteList(suanpai, mj);
//                                mj = *(zipai.begin());
//                                deleteList(zipai, mj);
//                                deleteList(suanpai, mj);
//                                if (zipai.size() == 0) {
//                                    break;
//                                }
//                                continue;
//                            }
//                        }
//                        list<Mj> del_mjs;
//                        deleteList(zipai, mj);

//                        list<Mj>::iterator iterator1;
//                        for (iterator1 = zipai.begin(); iterator1 != zipai.end(); ++iterator1) {
//                            if ((mj.getResult() < iterator1->getResult() && mj.getResult() < 35 &&
//                                    iterator1->getResult() < 35) ||
//                                (mj.getResult() < iterator1->getResult() && mj.getResult() >= 35 &&
//                                        iterator1->getResult() >= 35)) {
//                                zipai.erase(iterator1);
//                                del_mjs.push_back(*iterator1);
//                                mj = *(iterator1);
//                                break;
//                            }
//                        }
//                        for (iterator1 = zipai.begin(); iterator1 != zipai.end(); ++iterator1) {
//                            if ((mj.getResult() < iterator1->getResult() && mj.getResult() < 35 &&
//                                    iterator1->getResult() < 35) ||
//                                (mj.getResult() < iterator1->getResult() && mj.getResult() >= 35 &&
//                                        iterator1->getResult() >= 35)) {
//                                zipai.erase(iterator1);
//                                del_mjs.push_back(*iterator1);
//                                break;
//                            }
//                        }
//                        for (list<Mj>::iterator i = del_mjs.begin(); i != del_mjs.end(); ++i) {
//                            for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                if ((*i) == (*j)) {
//                                    suanpai.erase(j);
//                                    j--;
//                                }
//                            }
//                        }
//                    }
//                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                        if (i->getResult() > 30) {
//                            zipai.push_back(*i);
//                        }
//                    }
//                    zipai.sort(ComparatorMjResult);
//                    b = (zipai.size() % 3 > 0) ? (zipai.size() / 3 + 1) :( zipai.size() / 3);
//                    for (int j = 0; j < b; j++) {
//                        if (caisheng_count < 0) {
//                            return false;
//                        }
//                        if (zipai.size() == 1) {
//                            caisheng_count -= 2;
//                            break;
//                        }
//                        if (zipai.size() == 2 && zipai.begin()->getResult() == (++zipai.begin())->getResult()) {
//                            caisheng_count--;
//                            break;
//                        }
//                        Mj mj = *(zipai.begin());
//                        deleteList(zipai, mj);
//                        if (getOrDefault(Map,mj.getResult(), 0) == 2 && mj.getResult() != (*jiang)) {
//                            if (mj.getResult() == zipai.begin()->getResult()) {
//                                mj = *(zipai.begin());
//                                deleteList(zipai, mj);
//                                caisheng_count--;
//                                if (zipai.size() == 0) {
//                                    break;
//                                }
//                                continue;
//                            }
//                        }
//                        bool has = false;
//                        list<Mj>::iterator iterator2;
//                        for (iterator2 = suanpai.begin(); iterator2 != suanpai.end(); ++iterator2) {
//                            if ((mj.getResult() < iterator2->getResult() && mj.getResult() < 35 && iterator2->getResult() < 35) || (mj.getResult() < iterator2->getResult() && mj.getResult() >= 35 && iterator2->getResult() >= 35)) {
//                                suanpai.erase(iterator2);
//                                has = true;
//                                break;
//                            }
//                        }
//                        if (!has) {
//                            caisheng_count--;
//                        }
//                        has = false;
//                        for (iterator2 = suanpai.begin(); iterator2 != suanpai.end(); ++iterator2) {
//                            if ((mj.getResult() < iterator2->getResult() && mj.getResult() < 35 && iterator2->getResult() < 35) || (mj.getResult() < iterator2->getResult() && mj.getResult() >= 35 && iterator2->getResult() >= 35)) {
//                                suanpai.erase(iterator2);
//                                has = true;
//                                break;
//                            }
//                        }
//                        if (!has) {
//                            caisheng_count--;
//                        }
//                        if (caisheng_count < 0) {
//                            break;
//                        }
//                        if ((suanpai.size() + caisheng_count) % 3 != 0) {
//                            break;
//                        }
//                        if (suanpai.size() == 0) {
//                            break;
//                        }
//                    }
//                    list<Mj> zipai1;
//                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                        if (i->getResult() > 30) {
//                            zipai1.push_back(*i);
//                            suanpai.erase(i);
//                        }
//                    }
//                }else{
//                    for (unordered_map<int, int>::iterator sub_enty = Map.begin(); sub_enty != Map.end(); ++sub_enty) {
//                        switch (sub_enty->second) {
//                            case 1:
//                                if (sub_enty->first != *(jiang) && sub_enty->first > 30) {
//                                    caisheng_count -= 2;
//                                    iterator1 = suanpai.begin();
//                                    while (iterator1 != suanpai.end()) {
//                                        if (iterator1->getResult() == sub_enty->first) {
//                                            suanpai.erase(iterator1);
//                                        }
//                                    }
//                                }
//                                break;
//                            case 2:
//                                if (sub_enty->first != *(jiang) && sub_enty->first > 30) {
//                                    caisheng_count -= 1;
//                                    iterator1 = suanpai.begin();
//                                    while (iterator1 != suanpai.end()) {
//                                        if (iterator1->getResult() == sub_enty->first) {
//                                            suanpai.erase(iterator1);
//                                        }
//                                    }
//                                }
//                                break;
//                            case 3:
//                                break;
//                            case 4:
//                                break;
//                        }
//                    }
//                }
//                if (caisheng_count < 0) {
//                    continue;
//                }
//                if ((suanpai.size() + caisheng_count) % 3 != 0) {
//                    continue;
//                }
//                //移除顺子
//                //先排序
//                suanpai.sort(ComparatorMjResult);
//                list<Mj> duoyu;
//                for (; suanpai.size() > 0;) {
//                    Mj mj = *(suanpai.begin());
//                    if (getOrDefault(Map, mj.getResult(), 0) == 3 && mj.getResult() != (*jiang) && suanpai.size() > 2) {
//                        list<Mj>::iterator zipaiI, temp, zipaiJ;
//                        zipaiI = (++suanpai.begin());
//                        temp = (++suanpai.begin());
//                        zipaiJ = (++temp);

//                        if (mj.getResult() == zipaiI->getResult() && mj.getResult() == zipaiJ->getResult()) {
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            continue;
//                        }
//                    }

//                    if (getOrDefault(Map, mj.getResult(), 0) == 2 && getOrDefault(Map, mj.getResult() + 1, 0) < 2 && mj.getResult() + 1 != *(jiang) && mj.getResult() != *(jiang) && suanpai.size() > 2 ) {
//                        if (mj.getResult() == (++suanpai.begin())->getResult()) {
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            caisheng_count--;
//                            continue;
//                        }
//                    }
//                    deleteList(suanpai, mj);

//                    Mj dierge;
//                    bool isDiergeNull = true;
//                    iterator1 = suanpai.begin();
//                    if (mj.getResult() < 30) {
//                        while (iterator1 != suanpai.end()) {
//                            if (mj.getResult() + 1 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                                suanpai.erase(iterator1);
//                                dierge = *(iterator1);
//                                isDiergeNull = false;
//                                break;
//                            }
//                            iterator1++;
//                        }
//                    }

//                    Mj disange;
//                    bool isDisangeNull = true;
//                    iterator1 = suanpai.begin();
//                    if (mj.getResult() < 30) {
//                        while (iterator1 != suanpai.end()) {
//                            if (mj.getResult() + 2 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                                suanpai.erase(iterator1);
//                                disange = *(iterator1);
//                                if (isDiergeNull == true) {
//                                    caisheng_count--;
//                                }
//                                break;
//                            }
//                        }
//                    }

//                    if (isDisangeNull == true) {
//                        duoyu.push_back(mj);
//                        if (isDiergeNull == false) {
//                            duoyu.push_back(dierge);
//                        }
//                        continue;
//                    }
//                }//for (; suanpai.size() > 0; )
//                for (list<Mj>::iterator i = duoyu.begin(); i != duoyu.end(); ++i) {
//                    suanpai.push_back(*i);
//                }
//                if (suanpai.size() == 0 && caisheng_count >= 0) {
//                    return true;
//                }

//                int b = (suanpai.size() + caisheng_count) / 3;

//                for (int j = 0; j < b; j++) {
//                    if (caisheng_count < 0) {
//                        break;
//                    }
//                    if (suanpai.size() == 1 && caisheng_count == 2) {
//                        return true;
//                    }
//                    if (suanpai.size() == 2 && caisheng_count == 1 &&
//                        (suanpai.begin())->getResult() == (++suanpai.begin())->getResult()) {
//                        return true;
//                    }
//                    Mj mj = *(suanpai.begin());

//                    if (getOrDefault(Map,mj.getResult(), 0) > 2 && mj.getResult() != *(jiang)) {
//                        list<Mj>::iterator zipaiI, temp, zipaiJ;
//                        zipaiI = (++suanpai.begin());
//                        temp = (++suanpai.begin());
//                        zipaiJ = (++temp);

//                        if (mj.getResult() == zipaiI->getResult() && mj.getResult() == zipaiJ->getResult()) {
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            if (suanpai.size() == 0) {
//                                return true;
//                            }
//                            continue;
//                        }
//                    }
//                    deleteList(suanpai, mj);

//                    if (getOrDefault(Map, mj.getResult(), 0) == 2 && mj.getResult() != *(jiang)) {
//                        if (mj.getResult() + 1 != *(jiang) && getOrDefault(Map, mj.getResult() + 1, 0) > 0) {
//                            if (mj.getResult() + 2 != *(jiang) && getOrDefault(Map, mj.getResult() + 2, 0) > 0) {

//                            } else {
//                                if (mj.getResult() == suanpai.begin()->getResult()) {
//                                    mj = *(suanpai.begin());
//                                    deleteList(suanpai, mj);
//                                    caisheng_count--;
//                                    if (suanpai.size() == 0) {
//                                        return true;
//                                    }
//                                    continue;
//                                }
//                            }
//                        } else {
//                            if (mj.getResult() == suanpai.begin()->getResult()) {
//                                mj = *(suanpai.begin());
//                                deleteList(suanpai, mj);
//                                caisheng_count--;
//                                if (suanpai.size() == 0) {
//                                    return true;
//                                }
//                                continue;
//                            }
//                        }
//                    }

//                    if (mj.getResult() > 30 && getOrDefault(Map, mj.getResult(), 0) < 2) {
//                        return false;
//                    }

//                    bool has = false;
//                    list<Mj>::iterator iterator2 = suanpai.begin();
//                    while (iterator2 != suanpai.end()) {
//                        if (mj.getResult() + 1 == iterator2->getResult() && mj.getResult() / 10 == iterator2->getResult() / 10) {
//                            suanpai.erase(iterator2);
//                            has = true;
//                            break;
//                        }
//                        iterator2++;
//                    }
//                    if (!has) {
//                        caisheng_count--;
//                    }
//                    has = false;
//                    iterator2 = suanpai.begin();
//                    while (iterator2 != suanpai.end()) {
//                        if (mj.getResult() + 2 == iterator2->getResult() && mj.getResult() / 10 == iterator2->getResult() / 10) {
//                            suanpai.erase(iterator2);
//                            has = true;
//                            break;
//                        }
//                        iterator2++;
//                    }
//                    if (!has) {
//                        caisheng_count--;
//                    }
//                    if (caisheng_count < 0) {
//                        break;
//                    }
//                    if ((suanpai.size() + caisheng_count) % 3 != 0) {
//                        break;
//                    }
//                    if (suanpai.size() == 0) {
//                        return true;
//                    }
//                }
//                if (suanpai.size() == 0 && caisheng_count >= 0) {
//                    return true;
//                }
//            }//jiang
//        }//else
//        return  false;
//    }//caisheng_list.size()>0

//    unordered_map<int, int> Map;
//    for (list<Mj>::iterator i = pais.begin(); i != pais.end(); ++i) {
//        if (Map.find(i->getResult()) != Map.end()) {
//            Map[i->getResult()]++;
//        } else {
//            Map[i->getResult()] = 1;
//        }
//    }
//    ///测试
////    vector<pair<int, int>> vec_Map(Map.begin(), Map.end());
////    sort(vec_Map.begin(), vec_Map.end(), cmpByKey);
////    Map.clear();
////    for(auto i: vec_Map){
////        Map[i.first] = i.second;
////    }
//    ///测试
////    for(auto i: Map){
////        cout << i.first<<" "<<i.second << endl;
////    }

//    list<int> result_count;
//    for (unordered_map<int,int>::const_iterator i = Map.begin(); i != Map.end(); ++i) {
//        result_count.push_back(i->second);
//    }
//    //二五八将
//    if (systemConfig.erwubajiang) {
//        for (unordered_map<int, int>::iterator sub = Map.begin(); sub != Map.end(); ++sub) {
//            list<Mj> suanpai = pais;
//            unordered_map<int, int> geshu;
//            if (sub->first < 30 && (sub->second >= 2 && (sub->first % 10 == 2 || sub->first % 10 == 5 || sub->first % 10 == 8))) {
//                //所有的牌全部都能组成2个 胡牌
//                int cnt1 = 0, cnt2 = 0, cnt4 = 0, cnt5 = 0;
//                for (list<int>::iterator i = result_count.begin(); i != result_count.end(); ++i) {
//                    if (*i == 1) {
//                        cnt1++;
//                    }
//                    if (*i == 2) {
//                        cnt2++;
//                    }
//                    if (*i == 4) {
//                        cnt4++;
//                    }
//                    if (*i == 5) {
//                        cnt5++;
//                    }
//                }
//                //所有的牌全部都能组成2个 胡牌
//                if (systemConfig.xiaoqidui == 1 && (cnt2 * 2 == 14)) {
//                    return true;
//                }
//                //有至少两个4张一样的牌，其余牌都是对子 胡牌
//                if (cnt4 > 1 && (cnt2 * 2 + cnt4 * 4 == suanpai.size())) {
//                    return true;
//                }
//                //有4张一样的牌且没杠，其余牌都是对子 胡牌
//                if (cnt2 == 5 && cnt4 == 1) {
//                    return true;
//                }
//                //d都是四个 胡牌
//                if (cnt4 * 4 == suanpai.size()) {
//                    return true;
//                }

//                list<Mj>::iterator iterator = suanpai.begin();
//                int shuliang = 0;
//                while (iterator != suanpai.end()) {
//                    if (iterator->getResult() == sub->first && shuliang < 2) {
//                        shuliang++;
//                        suanpai.erase(iterator);
//                    }
//                    if (iterator->getResult() != sub->first && getOrDefault(Map, iterator->getResult(), 0) == 4) {
//                        if (geshu.find(iterator->getResult()) == geshu.end()) {
//                            geshu[iterator->getResult()] =  0;
//                        }
//                        if (geshu[iterator->getResult()] < 3) {
//                            suanpai.erase(iterator);
//                            geshu[iterator->getResult()] = geshu[iterator->getResult()] + 1;
//                        }
//                    }
//                    iterator++;
//                }
//                if (suanpai.size() % 3 != 0) {
//                    return false;
//                }
//                //移除顺子
//                //先排序
//                suanpai.sort(ComparatorMjResult);
//                int b = suanpai.size() / 3;
//                for (int j = 0; j < b; j++) {
//                    Mj mj = *(suanpai.begin());
//                    if (getOrDefault(Map, mj.getResult(), 0) == 3 && mj.getResult() != sub->first) {
//                        list<Mj>::iterator iterI, temp, iterJ;
//                        iterI = (++suanpai.begin());
//                        temp = (++suanpai.begin());
//                        iterJ = (++temp);

//                        if (mj.getResult() == iterI->getResult() && mj.getResult() == iterJ->getResult()) {
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            continue;
//                        }
//                    }
//                    deleteList(suanpai, mj);
//                    list<Mj>::iterator iterator1 = suanpai.begin();
//                    while (iterator1 != suanpai.end()) {
//                        if (mj.getResult() + 1 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                            suanpai.erase(iterator1);
//                            break;
//                        }
//                    }
//                    while (iterator1 != suanpai.end()) {
//                        if (mj.getResult() + 2 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                            suanpai.erase(iterator1);
//                            break;
//                        }
//                    }
//                    if (suanpai.size() % 3 != 0) {
//                        break;
//                    }
//                }//for (int j = 0; j < b; j++)
//                if (suanpai.size() == 0) {
//                    return true;
//                }
//            }
//        }
//    }else{//IsErwubajiang
//        int cnt1 = 0, cnt2 = 0, cnt4 = 0, cnt5 = 0;
//        for (list<int>::iterator i = result_count.begin(); i != result_count.end(); ++i) {
//            if (*i == 1) {
//                cnt1++;
//            }
//            if (*i == 2) {
//                cnt2++;
//            }
//            if (*i == 4) {
//                cnt4++;
//            }
//            if (*i == 5) {
//                cnt5++;
//            }
//        }
//        //所有的牌全部都能组成2个 胡牌
//        if (cnt2 * 2 == systemConfig.wanjiapaishu + 1) {
//            return true;
//        }
//        //只有两张牌
//        if (pais.size() == 2) {
//            return pais.begin()->getResult() == (++pais.begin())->getResult();
//        }

//        Map.clear();
//        for (list<Mj>::const_iterator iter = pais.begin(); iter != pais.end(); ++iter) {
//            if (Map.find(iter->getResult()) != Map.end()) {
//                Map[iter->getResult()]++;
//            } else {
//                Map[iter->getResult()] = 1;
//            }
//        }
//        ///测试 按key排序Map
////        vector<pair<int, int>> vec_Map(Map.begin(), Map.end());
////        sort(vec_Map.begin(), vec_Map.end(), cmpByKey);
////        Map.clear();
////        for(auto i: vec_Map){
////            Map[i.first] = i.second;
////        }


//        result_count.clear();
//        for (unordered_map<int, int>::const_iterator i = Map.begin(); i != Map.end(); ++i) {
//            result_count.push_back(i->second);
//        }

//        int r1 = 0, r2 = 2, r4 = 0, r5 = 0;
//        //有至少两个4张一样的牌，其余牌都是对子 胡牌
//        for (list<int>::const_iterator i = result_count.begin(); i != result_count.end(); ++i) {
//            if (*i == 1) {
//                r1++;
//            }
//            if (*i == 2) {
//                r2++;
//            }
//            if (*i == 4) {
//                r4++;
//            }
//            if (*i == 5) {
//                r5++;
//            }
//        }
//        //有至少两个4张一样的牌，其余牌都是对子 胡牌
//        if (r4 > 1 && (r2 * 2 + r4 * 4 == pais.size())) {
//            return true;
//        }
//        //有4张一样的牌且没杠，其余牌都是对子 胡牌
//        if(cnt2 == 5 && cnt4 == 1){
//            return  true;
//        }
//        //d都是四个加一对 胡牌
//        if (r2 == 1 && r4 * 4 == pais.size() - 2) {
//            return true;
//        }
//        for (auto sub_enty: Map) {
//            bool keyisange = true;
//            if (systemConfig.dongnanxibeizhongfabaishunzi == 0) {
//                if (systemConfig.guangxi152 == 0) {
//                    //里面有四个的字肯定不能胡牌
//                    if (sub_enty.second == 4 && sub_enty.first > 30) {
//                        return false;
//                    }
//                    //里面有1个的字肯定不能胡牌
//                    if (sub_enty.second == 1 && sub_enty.first > 30) {
//                        return false;
//                    }
//                }
//                keyisange = (sub_enty.second > 2 && sub_enty.first < 30);
//            }

//            //先剔除3个
//            if (sub_enty.second == 2 || keyisange) {
//                list<Mj> suanpai = pais;
//                unordered_map<int, int> geshu;
//                list<Mj>::iterator iterator = suanpai.begin();
//                int shuliang = 0;
//                while (iterator != suanpai.end()) {
//                    ///测试
////                    cout << "sub_enty.first:" <<sub_enty.first <<endl;
////                    cout << "iterator->getResult()" << iterator->getResult()<<endl;

//                    if (iterator->getResult() == sub_enty.first && shuliang < 2) {
//                        shuliang++;
//                        suanpai.erase(iterator);
//                    }
//                    if (iterator->getResult() != sub_enty.first && getOrDefault(Map ,iterator->getResult(), 0) == 4) {
//                        if (geshu.find(iterator->getResult()) == geshu.end()) {
//                            geshu[iterator->getResult()] = 0;
//                        }
//                        if (geshu[iterator->getResult()] < 3) {
//                            suanpai.erase(iterator);
//                            geshu[iterator->getResult()] =  geshu[iterator->getResult()] + 1;
//                        }
//                    }
//                    iterator++;
//                }

//                if (suanpai.size() == 0) {
//                    return true;
//                }
//                if (suanpai.size() % 3 != 0) {
//                    continue;
//                }
//                //移除顺子
//                //先排序
//                if (systemConfig.dongnanxibeizhongfabaishunzi == 1) {
//                    list<Mj> zipai;
//                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                        if (i->getResult() > 30 && i->getResult() <= 37) {
//                            zipai.push_back(*i);
//                        }
//                    }

//                    unordered_map<int, int> dongnaixibei_unordered_map;
//                    for (list<Mj>::iterator i = zipai.begin(); i != zipai.end(); ++i) {
//                        if (i->getResult() >= 31 && i->getResult() <= 34) {
//                            if (dongnaixibei_unordered_map.find(i->getResult()) != dongnaixibei_unordered_map.end()) {
//                                dongnaixibei_unordered_map[i->getResult()]++;
//                            } else {
//                                dongnaixibei_unordered_map[i->getResult()] = 1;
//                            }
//                        }
//                    }

//                    set<int> keys;
//                    for (unordered_map<int, int>::iterator i = dongnaixibei_unordered_map.begin(); i != dongnaixibei_unordered_map.end(); ++i) {
//                        keys.insert(i->first);
//                    }

//                    for (set<int>::iterator k = keys.begin(); k != keys.end(); ++k) {
//                        if (dongnaixibei_unordered_map[*k] == 3) {
//                            dongnaixibei_unordered_map.erase(*k);
//                        }
//                    }
//                    unordered_map<int, int> sort_dongnaixibei_unordered_map;
//                    vector<pair<int, int>> vec_dongnaixibei_unordered_map(dongnaixibei_unordered_map.begin(), dongnaixibei_unordered_map.end());
//                    sort(vec_dongnaixibei_unordered_map.begin(), vec_dongnaixibei_unordered_map.end(), cmpByValue);

//                    for (vector<pair<int, int>>::const_iterator i = vec_dongnaixibei_unordered_map.begin();
//                         i != vec_dongnaixibei_unordered_map.end(); ++i) {
//                        sort_dongnaixibei_unordered_map[i->first] = i->second;
//                    }

//                    keys.clear();
//                    for (unordered_map<int, int>::const_iterator i = sort_dongnaixibei_unordered_map.begin();
//                         i != sort_dongnaixibei_unordered_map.end(); ++i) {
//                        keys.insert(i->first);
//                    }

//                    list<int> List;
//                    for (set<int>::iterator i = keys.begin(); i != keys.end(); ++i) {
//                        List.push_back(*i);
//                    }
//                    while (List.size() >= 3) {
//                        int tichu = 0;
//                        for (int k: List) {
//                            if(sort_dongnaixibei_unordered_map[k] == 2) {
//                                if(tichu<3) {
//                                    sort_dongnaixibei_unordered_map[k]--;
//                                    tichu++;
//                                }else {
//                                    break;
//                                }
//                            }else if (sort_dongnaixibei_unordered_map[k] == 1) {
//                                if(tichu<3) {
//                                    sort_dongnaixibei_unordered_map.erase(k);
//                                    tichu++;
//                                }else {
//                                    break;
//                                }
//                            }
//                        }
//                        ///
//                        vector<pair<int, int>> vec_sort_zhongfabai_unordered_map(sort_dongnaixibei_unordered_map.begin(),
//                                                                       sort_dongnaixibei_unordered_map.end());
//                        sort(vec_sort_zhongfabai_unordered_map.begin(), vec_sort_zhongfabai_unordered_map.end(), cmpByValue);
//                        sort_dongnaixibei_unordered_map.clear();
//                        for (vector<pair<int, int>>::iterator i = vec_sort_zhongfabai_unordered_map.begin();
//                             i != vec_sort_zhongfabai_unordered_map.end(); ++i) {
//                            sort_dongnaixibei_unordered_map[i->first] = i->second;
//                        }

//                        keys.clear();
//                        for (unordered_map<int, int>::iterator i = sort_dongnaixibei_unordered_map.begin();
//                             i != sort_dongnaixibei_unordered_map.end(); ++i) {
//                            keys.insert(i->first);
//                        }
////
//                        List.clear();
//                        for (set<int>::iterator i = keys.begin(); i != keys.end(); ++i) {
//                            List.push_back(*i);
//                        }
//                    }//(List.size() >= 3)

//                    if(List.size()!=0){
//                        continue;
//                    }
//                    unordered_map<int, int> zhongfabai_unordered_map;
//                    for (list<Mj>::iterator i = zipai.begin(); i != zipai.end(); ++i) {
//                        if (i->getResult() >= 35 && i->getResult() <= 37) {
//                            if (zhongfabai_unordered_map.find(i->getResult()) != zhongfabai_unordered_map.end()) {
//                                zhongfabai_unordered_map[i->getResult()]++;
//                            } else {
//                                zhongfabai_unordered_map[i->getResult()] = 1;
//                            }
//                        }
//                    }

//                   for(auto i: keys){
//                       keys.insert(i);
//                   }

//                   for (int k : keys) {
//                        if (zhongfabai_unordered_map[k] == 3) {
//                            zhongfabai_unordered_map.erase(k);
//                        }
//                    }

//                    unordered_map<int, int> sort_zhongfabai_unordered_map;
//                    vector<pair<int, int>> vec_zhongfabai_unordered_map(zhongfabai_unordered_map.begin(), zhongfabai_unordered_map.end());
//                    sort(vec_zhongfabai_unordered_map.begin(), vec_zhongfabai_unordered_map.end(), cmpByValue);
//                    sort_zhongfabai_unordered_map.clear();
//                    for (vector<pair<int, int>>::iterator i = vec_zhongfabai_unordered_map.begin();
//                         i != vec_zhongfabai_unordered_map.end(); ++i) {
//                        sort_zhongfabai_unordered_map[i->first] = i->second;
//                    }

//                    keys.clear();
//                    for (unordered_map<int, int>::iterator i = zhongfabai_unordered_map.begin(); i != zhongfabai_unordered_map.end(); ++i) {
//                        keys.insert(i->first);
//                    }

//                    List.clear();
//                    for (auto k :keys) {
//                        List.push_back(k);
//                    }

//                    while (List.size()>=3) {
//                        int tichu=0;
//                        for (int k: List) {
//                            if (sort_zhongfabai_unordered_map[k] == 3) {
//                                sort_dongnaixibei_unordered_map.erase(k);
//                            }else if (sort_zhongfabai_unordered_map[k] == 2) {
//                                if(tichu<3) {
//                                    sort_zhongfabai_unordered_map[k] =  sort_zhongfabai_unordered_map[k] - 1;
//                                    tichu++;
//                                }else {
//                                    break;
//                                }
//                            } else if (sort_zhongfabai_unordered_map[k] == 1) {
//                                if(tichu<3) {
//                                    sort_zhongfabai_unordered_map.erase(k);
//                                    tichu++;
//                                }else {
//                                    break;
//                                }
//                            }
//                        }

//                        vector<pair<int, int>> vec_sort_zhongfabai_unordered_map(sort_zhongfabai_unordered_map.begin(), sort_zhongfabai_unordered_map.end());
//                        sort(vec_sort_zhongfabai_unordered_map.begin(), vec_sort_zhongfabai_unordered_map.end(), cmpByValue);
//                        sort_zhongfabai_unordered_map.clear();
//                        for (vector<pair<int, int>>::iterator i = vec_sort_zhongfabai_unordered_map.begin();
//                             i != vec_sort_zhongfabai_unordered_map.end(); ++i) {
//                            sort_zhongfabai_unordered_map[i->first] = i->second;
//                        }

//                        keys.clear();
//                        for (unordered_map<int, int>::iterator i = sort_zhongfabai_unordered_map.begin(); i != sort_zhongfabai_unordered_map.end(); ++i) {
//                            keys.insert(i->first);
//                        }

//                        List.clear();
//                        for (set<int>::iterator i = keys.begin(); i != keys.end(); ++i) {
//                            List.push_back(*i);
//                        }

//                    }
//                    if(List.size()!=0){
//                        continue;
//                    }
//                    list<Mj> zipai1;
//                    for(auto i: suanpai){
//                        if(i.getResult() > 30 && i.getResult() <= 37){
//                            zipai1.push_back(i);
//                        }
//                    }
//                    for(auto i: zipai1){
//                        for(auto j: suanpai){
//                            if(i == j){
//                               deleteList(suanpai, j);
//                            }
//                        }
//                    }

//                }//dongxibeifabaishunzi

//                suanpai.sort(ComparatorMjResult);
//               // suanpai.sort(std::greater<Mj>());
//                list<Mj> duoyu;
//                for (; suanpai.size() > 0;) {
//                    Mj mj = *(suanpai.begin());

//                    if (getOrDefault(Map, mj.getResult(), 0) == 3 && mj.getResult() != sub_enty.first && suanpai.size() > 2) {
//                        list<Mj>::iterator iterI, temp, iterJ;
//                        iterI = (++suanpai.begin());
//                        temp = (++suanpai.begin());
//                        iterJ = (++temp);
//                        if (mj.getResult() == iterI->getResult() && mj.getResult() == iterJ->getResult()) {
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            mj = *(suanpai.begin());
//                            deleteList(suanpai, mj);
//                            continue;
//                        }
//                    }
//                    deleteList(suanpai, mj);

//                    Mj dierge;
//                    bool isDiergeNull = true;
//                    list<Mj>::iterator iterator1 = suanpai.begin();

//                    if (mj.getResult() < 30) {
//                        while (iterator1 != suanpai.end()) {
//                            if (mj.getResult() + 1 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                                suanpai.erase(iterator1);
//                                dierge = (*iterator1);
//                                isDiergeNull = false;
//                                break;
//                            }
//                            iterator1++;
//                        }
//                    }
//                    if (isDiergeNull == true) {
//                        duoyu.push_back(mj);
//                        continue;
//                    }

//                    Mj disange;
//                    bool isDisangeNull = true;
//                    if (mj.getResult() < 30) {
//                        while (iterator1 != suanpai.end()) {
//                            if (mj.getResult() + 2 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                                suanpai.erase(iterator1);
//                                disange = *(iterator1);
//                                isDisangeNull = false;
//                                break;
//                            }
//                            iterator1++;
//                        }
//                    }
//                    if (isDisangeNull == true) {
//                        duoyu.push_back(mj);
//                        duoyu.push_back(dierge);
//                        continue;
//                    }
//                }
//                for (list<Mj>::iterator i = duoyu.begin(); i != duoyu.end(); ++i) {
//                    suanpai.push_back(*i);
//                }

//                //广西152
//                if (systemConfig.guangxi152 == true) {
//                    list<Mj> dayu50, zong, he;
//                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                        if (i->getResult() > 50) {
//                            dayu50.push_back(*i);
//                            if (i->getResult() == 55) {
//                                zong.push_back(*i);
//                            }
//                            if (i->getResult() == 54) {
//                                he.push_back(*i);
//                            }
//                        }
//                    }
//                    if (dayu50.size() > 0) {
//                        for (list<Mj>::iterator mj = dayu50.begin(); mj != dayu50.end(); ++mj) {
//                            switch (mj->getResult()) {
//                                case 52://元
//                                    for (int i = 35; i <= 37; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                        if(*k == *j){
//                                                            suanpai.erase(k);
//                                                        }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);
//                                        }

//                                        if (zhongfabai.size() == 1 && zong.size() == 1) {

//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }

//                                            for (list<Mj>::iterator j = zong.begin(); j != zong.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            zong.clear();
//                                            deleteList(suanpai, *mj);
//                                        }
//                                    }
//                                    break;
//                                case 53://喜
//                                    for (int i = 31; i <= 34; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);
//                                        }

//                                        if (zhongfabai.size() == 1 && zong.size() == 1) {

//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }

//                                            for (list<Mj>::iterator j = zong.begin(); j != zong.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            zong.clear();
//                                            deleteList(suanpai, *mj);
//                                        }
//                                    }
//                                    break;
//                                case 56://万
//                                    for (int i = 1; i <= 9; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);
//                                        }
//                                    }
//                                    break;
//                                case 57://筒
//                                    for (int i = 21; i <= 29; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);
//                                            continue;
//                                        }
//                                    }
//                                    break;
//                                case 58://条
//                                    for (int i = 11; i <=19; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);
//                                            continue;
//                                        }
//                                    }
//                                case 54://总
//                                    for (int i = 1; i <= 29; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2 && he.size() == 1) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);

//                                            for (list<Mj>::iterator j = he.begin(); j != he.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            he.clear();
//                                            continue;
//                                        }
//                                    }
//                                    break;
//                                case 55://合
//                                    for (int i = 31; i <= 37; ++i) {
//                                        int finalI = i;

//                                        list<Mj> zhongfabai;
//                                        for (list<Mj>::iterator j = suanpai.begin(); j != suanpai.end(); ++j) {
//                                            if (j->getResult() == finalI) {
//                                                zhongfabai.push_back(*j);
//                                            }
//                                        }

//                                        if (zhongfabai.size() == 2 && zong.size() == 1) {
//                                            for (list<Mj>::iterator j = zhongfabai.begin(); j != zhongfabai.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            deleteList(suanpai, *mj);

//                                            for (list<Mj>::iterator j = zong.begin(); j != zong.end(); ++j) {
//                                                for (list<Mj> ::iterator k = suanpai.begin(); k != suanpai.end(); ++k) {
//                                                    if(*k == *j){
//                                                        suanpai.erase(k);
//                                                    }
//                                                }
//                                            }
//                                            zong.clear();
//                                            continue;
//                                        }
//                                    }
//                                    break;
//                            }
//                        }
//                    }//dayu50

//                    suanpai.sort(ComparatorMjResult);
//                    for (; suanpai.size() > 0; ) {
//                        Mj mj = *(suanpai.begin());
//                        deleteList(suanpai, mj);

//                        list<Mj>::iterator iterator1 = suanpai.begin();
//                        if (mj.getResult() < 30) {
//                            bool has = false;
//                            while (iterator1 != suanpai.end()) {
//                                if (mj.getResult() + 1 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                                    suanpai.erase(iterator1);
//                                    has = true;
//                                    break;
//                                }
//                            }
//                            if (!has) {
//                                list<Mj> zong1, he1;
//                                for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                    if (i->getResult() == 55) {
//                                        zong1.push_back(*i);
//                                    }
//                                    if (i->getResult() == 54) {
//                                        he1.push_back(*i);
//                                    }
//                                }

//                                if (mj.getResult() / 10 == 0) {
//                                    list<Mj> wan;
//                                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                        if (i->getResult() == 56) {
//                                            wan.push_back(*i);
//                                        }
//                                    }
//                                    if (wan.size() > 0) {
//                                        deleteList(suanpai, *(wan.begin()));
//                                    } else if (he1.size() > 0) {
//                                        deleteList(suanpai, *(he1.begin()));
//                                    } else if (zong1.size() > 0) {
//                                        deleteList(suanpai, *(zong1.begin()));
//                                    }
//                                }
//                                if (mj.getResult() / 10 == 1) {
//                                    list<Mj> wan;
//                                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                        if (i->getResult() == 58) {
//                                            wan.push_back(*i);
//                                        }
//                                    }
//                                    if (wan.size() > 0) {
//                                        deleteList(suanpai, *(wan.begin()));
//                                    } else if (he1.size() > 0) {
//                                        deleteList(suanpai, *(he1.begin()));
//                                    } else if (zong1.size() > 0) {
//                                        deleteList(suanpai, *(zong1.begin()));
//                                    }
//                                }
//                                if (mj.getResult() / 10 == 2) {
//                                    list<Mj> wan;
//                                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                        if (i->getResult() == 57) {
//                                            wan.push_back(*i);
//                                        }
//                                    }
//                                    if (wan.size() > 0) {
//                                        deleteList(suanpai, *(wan.begin()));
//                                    } else if (he1.size() > 0) {
//                                        deleteList(suanpai, *(he1.begin()));
//                                    } else if (zong1.size() > 0) {
//                                        deleteList(suanpai, *(zong1.begin()));
//                                    }
//                                }
//                            }
//                        }
//                        if (mj.getResult() < 30) {
//                            bool has = false;
//                            iterator1 = suanpai.begin();
//                            while (iterator1 != suanpai.end()) {
//                                if (mj.getResult() + 2 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                                    suanpai.erase(iterator1);
//                                    has = true;
//                                    break;
//                                }
//                            }
//                            if (!has) {
//                                list<Mj> zong1, he1;
//                                for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                    if (i->getResult() == 55) {
//                                        zong1.push_back(*i);
//                                    }
//                                    if (i->getResult() == 54) {
//                                        he1.push_back(*i);
//                                    }
//                                }
//                                if (mj.getResult() / 10 == 0) {
//                                    list<Mj> wan;
//                                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                        if (i->getResult() == 56) {
//                                            wan.push_back(*i);
//                                        }
//                                    }
//                                    if (wan.size() > 0) {
//                                        deleteList(suanpai, *(wan.begin()));
//                                    } else if (he1.size() > 0) {
//                                        deleteList(suanpai, *(he1.begin()));
//                                    } else if (zong1.size() > 0) {
//                                        deleteList(suanpai, *(zong1.begin()));
//                                    }
//                                }
//                                if (mj.getResult() / 10 == 1) {
//                                    list<Mj> wan;
//                                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                        if (i->getResult() == 58) {
//                                            wan.push_back(*i);
//                                        }
//                                    }
//                                    if (wan.size() > 0) {
//                                        deleteList(suanpai, *(wan.begin()));
//                                    } else if (he1.size() > 0) {
//                                        deleteList(suanpai, *(he1.begin()));
//                                    } else if (zong1.size() > 0) {
//                                        deleteList(suanpai, *(zong1.begin()));
//                                    }
//                                }
//                                if (mj.getResult() / 10 == 2) {
//                                    list<Mj> wan;
//                                    for (list<Mj>::iterator i = suanpai.begin(); i != suanpai.end(); ++i) {
//                                        if (i->getResult() == 57) {
//                                            wan.push_back(*i);
//                                        }
//                                    }
//                                    if (wan.size() > 0) {
//                                        deleteList(suanpai, *(wan.begin()));
//                                    } else if (he1.size() > 0) {
//                                        deleteList(suanpai, *(he1.begin()));
//                                    } else if (zong1.size() > 0) {
//                                        deleteList(suanpai, *(zong1.begin()));
//                                    }
//                                }
//                            }
//                        }
//                        if (suanpai.size() % 3 != 0) {
//                            break;
//                        }
//                    }
//                }
//                if (suanpai.size() == 0) {
//                    return true;
//                }
//            }//if (sub_enty->second == 2 || keyisange)
//        }//for (unordered_map<int, int>::iterator sub_enty = unordered_map.begin(); sub_enty != unordered_map.end(); ++sub_enty)
//    }
//    return  false;
//}

//bool HuPaiKit::lanpai(list<Mj> yushimjs) {
//    list<Mj> pais = yushimjs;
//    list<Mj> caisheng_list;
//    for (list<Mj>::iterator i = pais.begin(); i != pais.end(); ++i) {
//        if(i->isCaisheng()){
//            caisheng_list.push_back(*i);
//        }
//    }

//    if (caisheng_list.size() > 0) {
//        list<Mj>::iterator iterator3 = pais.begin();
//        while (iterator3 != pais.end()) {
//            if (iterator3->isCaisheng()) {
//                pais.erase(iterator3);
//            }
//            iterator3++;
//        }

//        unordered_map<int, int> unordered_map;//新建一个unordered_map集合，用来保存重复的次数
//        for (Mj obj : pais) {
//            if (unordered_map.find(obj.getResult()) != unordered_map.end()) {//判断是否已经有该数值，如有，则将次数加1
//                unordered_map[obj.getResult()]++;
//                if (unordered_map[obj.getResult()] > 1) {
//                    return false;
//                }
//            } else {
//                unordered_map[obj.getResult()] = 1;
//            }
//        }

//        list<Mj> suanpai = pais;
//        list<Mj>::iterator iterator1 = suanpai.begin();
//        while (iterator1 != suanpai.end()) {
//            if (iterator1->getResult() > 30) {
//                suanpai.erase(iterator1);
//            }
//            iterator1++;
//        }
//        if ((suanpai.size()) % 3 != 0) {
//            return false;
//        }
//        //移除顺子
//        //先排序
//        suanpai.sort(ComparatorMjResult);
//        int caisheng_count = caisheng_list.size();
//        int b = (suanpai.size() + caisheng_count) / 3;

//        for (int j = 0; j < b; j++) {
//            if (caisheng_count < 0) {
//                return false;
//            }
//            if (suanpai.size() == 1 && caisheng_count == 2) {
//                return true;
//            }
//            Mj mj = *(suanpai.begin());
//            deleteList(suanpai, mj);

//            bool has = false;
//            list<Mj>::iterator iterator2 = suanpai.begin();
//            while (iterator2 != suanpai.end()) {
//                if (iterator2->getResult() - 3 >= mj.getResult() && mj.getResult() / 10 == iterator2->getResult() / 10) {
//                    suanpai.erase(iterator2);
//                    has = true;
//                    mj = *(iterator2);
//                    break;
//                }
//                iterator2++;
//            }

//            if (!has) {
//                caisheng_count--;
//            }
//            has = false;
//            iterator2 = suanpai.begin();
//            while (iterator2 != suanpai.end()) {
//                if (iterator2->getResult() - 3 >= mj.getResult() && mj.getResult() / 10 == iterator2->getResult() / 10) {
//                    suanpai.erase(iterator2);
//                    has = true;
//                    break;
//                }
//                iterator2++;
//            }
//            if (!has) {
//                caisheng_count--;
//            }
//            if (caisheng_count < 0) {
//                return false;
//            }
//            if ((suanpai.size() + caisheng_count) % 3 != 0) {
//                return false;
//            }
//            if (suanpai.size() == 0) {
//                return true;
//            }
//        }//(int j = 0; j < b; j++)
//        if (suanpai.size() == 0 && caisheng_count > 0) {
//            return true;
//        }
//        return false;
//    }

//    unordered_map<int, int> unordered_map;//新建一个unordered_map集合，用来保存重复的次数
//    for (Mj obj : pais) {
//        if (unordered_map.find(obj.getResult()) != unordered_map.end()) {//判断是否已经有该数值，如有，则将次数加1
//            unordered_map[obj.getResult()]++;
//            if (unordered_map[obj.getResult()] > 1) {
//                return false;
//            }
//        } else {
//            unordered_map[obj.getResult()] = 1;
//        }
//    }

//    for (auto sub_enty :  unordered_map) {
//        if (sub_enty.second > 1) {
//            return false;
//        }

//        list <Mj> suanpai = pais;

//        list<Mj>::iterator iterator2 = suanpai.begin();
//        while (iterator2 != suanpai.end()) {
//            if (iterator2->getResult() > 30) {
//                suanpai.erase(iterator2);
//            }
//            iterator2++;
//        }
//        if (suanpai.size() % 3 != 0) {
//            return false;
//        }
//        //移除顺子
//        //先排序
//        suanpai.sort(ComparatorMjResult);
//        int b = suanpai.size() / 3;
//        for (int j = 0; j < b; j++) {
//            Mj mj = *(suanpai.begin());
//            deleteList(suanpai, mj);
//            list<Mj>::iterator iterator1 = suanpai.begin();
//            while (iterator1 != suanpai.end()) {
//                if (iterator1->getResult() - 3 >= mj.getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                    suanpai.erase(iterator1);
//                    mj = *(iterator1);
//                    break;
//                }
//                iterator1++;
//            }
//            while (iterator1 != suanpai.end()) {
//                if (iterator1->getResult() - 3 >= mj.getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                    suanpai.erase(iterator1);
//                    break;
//                }
//            }
//            if (suanpai.size() % 3 != 0) {
//                return false;
//            }
//        }//j < b
//        if (suanpai.size() == 0) {
//            return true;
//        }
//    }
//    return false;
//}

//bool HuPaiKit::yaojiyitongdangzipai(list<Mj> yushimjs) {
//    list<Mj> pais = yushimjs;

//    unordered_map<int, int> Map;//新建一个unordered_map集合，用来保存重复的次数

//    for (Mj obj : pais) {
//        if (Map.find(obj.getResult()) != Map.end()) {//判断是否已经有该数值，如有，则将次数加1
//            Map[obj.getResult()]++;
//            if (Map[obj.getResult()] > 1) {
//                return false;
//            }
//        } else {
//            Map[obj.getResult()] = 1;
//        }
//    }

//    for (auto sub_enty : Map) {
//        //先剔除3个
//        if (sub_enty.second == 2 || sub_enty.second > 2) {
//            list <Mj> suanpai = pais;
//            unordered_map<int, int> geshu;
//            list<Mj>::iterator iterator = suanpai.begin();
//            int shuliang = 0;
//            while (iterator != suanpai.end()) {
//                if (iterator->getResult() == sub_enty.first && shuliang < 2) {
//                    shuliang++;
//                    suanpai.erase(iterator);
//                }
//                if (iterator->getResult() != sub_enty.first && getOrDefault(Map, iterator->getResult(), 0) >= 3 &&
//                        iterator->getResult() > 34) {
//                    if (geshu.find(iterator->getResult()) == geshu.end()) {
//                        geshu[iterator->getResult()]  = 0;
//                    }
//                    if (geshu[iterator->getResult()] < 3) {
//                        suanpai.erase(iterator);
//                        geshu[iterator->getResult()]++;
//                    }
//                }
//                iterator++;
//            }
//            if (suanpai.size() == 0) {
//                return true;
//            }
//            if (suanpai.size() % 3 != 0) {
//                continue;
//            }
//            //移除字牌中发
//            int yichu = 35;
//            int xuyao_yaoji_yitong = 0;
//            int cnt34 = 0;
//            for(auto i: suanpai){
//                    if(i.getResult() > 34){
//                        cnt34++;
//                    }
//            }
//            while (cnt34 > 0 || yichu != 35) {
//                iterator = suanpai.begin();
//                bool has = false;
//                while (iterator != suanpai.end()) {
//                    if (iterator->getResult() == yichu) {
//                        suanpai.erase(iterator);
//                        yichu++;
//                        has = true;
//                        break;
//                    }
//                }
//                if (!has) {
//                    yichu++;
//                    xuyao_yaoji_yitong++;
//                }
//                if (yichu > 37) {
//                    yichu = 35;
//                }
//            }
//            long yaoji_yitong_count = 0;
//            for(auto i: suanpai){
//                if(i.getResult() == 11 || i.getResult() == 21){
//                    yaoji_yitong_count++;
//                }
//            }

//            if (xuyao_yaoji_yitong > yaoji_yitong_count) {
//                continue;
//            }

//            //移除顺子
//            //先排序

//            //倒序排列
//            suanpai.sort(ComparatorMjResult);
//            list<Mj> reverseSuanpai;
//            for (list<Mj>::iterator i = suanpai.end(); i != suanpai.begin();) {
//                    reverseSuanpai.push_back(*(--i));
//            }
//            suanpai = reverseSuanpai;

//            int daiding_yitiao_yitong = 0;
//            int del_yaoji_yitong_count = 0;
//            bool has_3 = true;

//            while (suanpai.size() > 0) {
//                Mj mj = *(suanpai.begin());
//                if (mj.getResult() == 11 || mj.getResult() == 21) {
//                    deleteList(suanpai, mj);
//                    del_yaoji_yitong_count++;
//                    continue;
//                }
//                if (getOrDefault(Map, mj.getResult(), 0) == 3 && mj.getResult() != sub_enty.first) {
//                    list<Mj>::iterator iterI, temp, iterJ;
//                    iterI = (++suanpai.begin());
//                    temp = (++suanpai.begin());
//                    iterJ = (++temp);
//                    if (mj.getResult() == iterI->getResult() && mj.getResult() == iterJ->getResult()) {
//                        deleteList(suanpai, mj);
//                        mj = *(suanpai.begin());
//                        deleteList(suanpai, mj);
//                        mj = *(suanpai.begin());
//                        deleteList(suanpai, mj);
//                        continue;
//                    }
//                }
//                deleteList(suanpai, mj);

//                list<Mj>::iterator iterator1 = suanpai.begin();
//                bool has = false;
//                while (iterator1 != suanpai.end()) {
//                    if (mj.getResult() - 1 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                        suanpai.erase(iterator1);
//                        has = true;
//                        if (iterator1->getResult() == 11 || iterator1->getResult() == 21) {
//                            daiding_yitiao_yitong++;
//                        }
//                        break;
//                    }
//                    iterator1++;
//                }
//                if (!has) {
//                    has_3 = false;
//                    break;
//                }
//                has = false;
//                while (iterator1 != suanpai.end()) {
//                    if (mj.getResult() - 2 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                        suanpai.erase(iterator1);
//                        has = true;
//                        has_3 = true;
//                        if (iterator1->getResult() == 11 || iterator1->getResult() == 21) {
//                            daiding_yitiao_yitong++;
//                        }
//                        break;
//                    }
//                    iterator1++;
//                }
//                if (!has) {
//                    has_3 = false;
//                    break;
//                }
//            }//suanpai.size() > 0
//            if (has_3 && suanpai.size() == 0 && xuyao_yaoji_yitong + daiding_yitiao_yitong == yaoji_yitong_count) {
//                return true;
//            }
//            if (has_3 && suanpai.size() == 0 && del_yaoji_yitong_count == yaoji_yitong_count && daiding_yitiao_yitong == 0 && xuyao_yaoji_yitong == 0) {
//                return true;
//            }

//        }//sub_enty
//    }//sub_enty unordered_map
//    return false;
//}

//bool HuPaiKit::yaojiyitongdangzipaifengpai(list<Mj> yushimjs) {
//    list<Mj> pais = yushimjs;

//    unordered_map<int, int> Map;//新建一个unordered_map集合，用来保存重复的次数

//    for (Mj obj : pais) {
//        if (Map.find(obj.getResult()) != Map.end()) {//判断是否已经有该数值，如有，则将次数加1
//            Map[obj.getResult()]++;
//        } else {
//            Map[obj.getResult()] = 1;
//        }
//    }

//    for (auto sub_enty : Map) {
//        //先剔除3个
//        if (sub_enty.second == 2 || sub_enty.second > 2) {
//            list <Mj> suanpai = pais;

//            unordered_map < int, int> geshu;
//            list<Mj>::iterator iterator = suanpai.begin();
//            int shuliang = 0;
//            while (iterator != suanpai.end()) {
//                if (iterator->getResult() == sub_enty.first && shuliang < 2) {
//                    shuliang++;
//                    suanpai.erase(iterator);
//                }
//                if (iterator->getResult() != sub_enty.first && getOrDefault(Map, iterator->getResult(), 0) >= 3 &&
//                        iterator->getResult() > 30) {
//                    if (geshu.find(iterator->getResult()) == geshu.end()) {
//                        geshu[iterator->getResult()] = 0;
//                    }
//                    if (geshu[iterator->getResult()] < 3) {
//                        suanpai.erase(iterator);
//                        geshu[iterator->getResult()]++;
//                    }
//                }
//                iterator++;
//            }
//            if (suanpai.size() == 0) {
//                return true;
//            }
//            if (suanpai.size() % 3 != 0) {
//                continue;
//            }
//            //移除字牌风牌
//            list<Mj> yiyoumajings;
//            iterator = suanpai.begin();
//            while (iterator != suanpai.end()) {
//                if (iterator->getResult() > 30 ) {
//                    bool isHas = false;
//                    for(auto j: yiyoumajings){
//                        if(j == *(iterator)){
//                            isHas = true;
//                            break;
//                        }
//                    }
//                    if(isHas == false){
//                        suanpai.erase(iterator);
//                        yiyoumajings.push_back(*iterator);
//                    }
//                }
//                if (yiyoumajings.size() == 3) {
//                    yiyoumajings.clear();
//                }
//                iterator++;
//            }

//            int xuyao_yaoji_yitong = 0;
//            long feng_zi_count = 0;
//            for(auto j: suanpai){
//                if(j.getResult() > 30){
//                    feng_zi_count++;
//                }
//            }

//            if (feng_zi_count > 0) {
//                xuyao_yaoji_yitong = (int) (3 - feng_zi_count);
//            }

//            iterator = suanpai.begin();
//            while (iterator != suanpai.end()) {
//                if (iterator->getResult() > 30) {
//                    suanpai.erase(iterator);
//                }
//                iterator++;
//            }

//            long yaoji_yitong_count  = 0;
//            for(auto j: suanpai){
//                if(j.getResult() == 11 || j.getResult() == 21){
//                    yaoji_yitong_count++;
//                }
//            }
//            if (xuyao_yaoji_yitong > yaoji_yitong_count) {
//                continue;
//            }

//            //移除顺子
//            //先排序
//            suanpai.sort(ComparatorMjResult);
//            list<Mj> reverseSuanpai;
//            for (list<Mj>::iterator i = suanpai.end(); i != suanpai.begin();) {
//                reverseSuanpai.push_back(*(--i));
//            }
//            suanpai = reverseSuanpai;
//            int daiding_yitiao_yitong = 0;
//            int del_yaoji_yitong_count = 0;
//            bool has_3 = true;
//            while (suanpai.size() > 0) {
//                Mj mj = *(suanpai.begin());
//                if (mj.getResult() == 11 || mj.getResult() == 21) {
//                    deleteList(suanpai, mj);
//                    del_yaoji_yitong_count++;
//                    continue;
//                }
//                if (getOrDefault(Map, mj.getResult(), 0) == 3 && mj.getResult() != sub_enty.first) {
//                    list<Mj>::iterator iterI, temp, iterJ;
//                    iterI = (++suanpai.begin());
//                    temp = (++suanpai.begin());
//                    iterJ = (++temp);

//                    if (mj.getResult() == iterI->getResult() && mj.getResult() == iterJ->getResult()) {
//                        deleteList(suanpai, mj);
//                        mj = *(suanpai.begin());
//                        deleteList(suanpai, mj);
//                        mj = *(suanpai.begin());
//                        deleteList(suanpai, mj);
//                        continue;
//                    }
//                }
//                deleteList(suanpai, mj);
//                list<Mj>::iterator iterator1 = suanpai.begin();
//                bool has = false;
//                while (iterator1 != suanpai.end()) {
//                    if (mj.getResult() - 1 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                        suanpai.erase(iterator1);
//                        has = true;
//                        if (iterator1->getResult() == 11 || iterator1->getResult() == 21) {
//                            daiding_yitiao_yitong++;
//                        }
//                        break;
//                    }
//                    iterator1++;
//                }
//                if (!has) {
//                    has_3 = false;
//                    break;
//                }
//                has = false;
//                while (iterator1 != suanpai.end()) {
//                    if (mj.getResult() - 2 == iterator1->getResult() && mj.getResult() / 10 == iterator1->getResult() / 10) {
//                        suanpai.erase(iterator1);
//                        has = true;
//                        has_3 = true;
//                        if (iterator1->getResult() == 11 || iterator1->getResult() == 21) {
//                            daiding_yitiao_yitong++;
//                        }
//                        break;
//                    }
//                    iterator1++;
//                }
//                if (!has) {
//                    has_3 = false;
//                    break;
//                }
//            }
//            if (has_3 && suanpai.size() == 0 && xuyao_yaoji_yitong + daiding_yitiao_yitong == yaoji_yitong_count) {
//                return true;
//            }
//            if (has_3 && suanpai.size() == 0 && del_yaoji_yitong_count == yaoji_yitong_count && daiding_yitiao_yitong == 0 && xuyao_yaoji_yitong == 0) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

//bool HuPaiKit::HuPaiPanDin(list<Mj> mahs, int que, SystemConfig systemConfig) {

//    set<string> kehu_list;

//    if (!(systemConfig.rengyijiu == 1 || systemConfig.wanjiapaishu < 13)) {
//        if (mahs.size() < 14) {
//            return false;
//        }
//    }

//    if (systemConfig.queyimeng == 1) {
//        for (Mj mj : mahs) {
//            if ((mj.getIsque() && mj.getChupai_direction() == -1) && !mj.isCaisheng()) {
//                return false;
//            }
//        }
//    }

//    list<Mj> pais = mahs;
//    if (systemConfig.pengpaihuozhezhongfabaidui == 1) {
//        int cnt1 = 0,cnt035 = 0, cnt036 = 0, cnt037 = 0;
//        for (list<Mj>::iterator i = pais.begin(); i != pais.end(); ++i) {
//                if(i->getPaizhuangtai() == 1){
//                    cnt1++;
//                }
//                if(i->getPaizhuangtai() == 0 && i->getResult() == 35){
//                    cnt035++;
//                }
//                if(i->getPaizhuangtai() == 0 && i->getResult() == 36){
//                    cnt036++;
//                }
//                if(i->getPaizhuangtai() == 0 && i->getResult() == 36){
//                    cnt037++;
//                }
//        }
//        if(cnt1 < 1){
//            if(cnt035 < 2 && cnt036 < 2 && cnt037 < 2){
//                return false;
//            }
//        }
//    }

////先剔除碰 杠的牌
//    list<Mj>::iterator iterator = pais.begin();
//    while (iterator != pais.end()) {
//        if (iterator->getPaizhuangtai() == 1 || iterator->getPaizhuangtai() == 2 || iterator->getPaizhuangtai() == 3 || iterator->getPaizhuangtai() == 4) {
//            pais.erase(iterator);
//        }
//            iterator++;
//    }
//    if (pais.size() % 3 != 2) {
//        return false;
//    }
//    string stringBuilder;
//    for (Mj mj : pais) {
//        if (mj.getResult() / 10 == que && !mj.isCaisheng()) {
//            return false;
//        }
//        stringBuilder.append(mj.getZhiBiaoZHi());
//        stringBuilder.append("_");

//        string strCaisheng;
//        if(mj.isCaisheng()){
//            strCaisheng = "true";
//        }else{
//            strCaisheng = "false";
//        }

//        stringBuilder.append(strCaisheng);//
//        stringBuilder.append(",");
//    }

//    if (kehu_list.find(stringBuilder) != kehu_list.end()) {
//        return true;
//    }

//    if (systemConfig.bixuyou19zipaifengpairenyiyizhang == 1) {
//        int cnt;
//        for (list<Mj>::iterator i = pais.begin(); i != pais.end(); ++i) {
//            if((i->getResult() % 10 == 1 || i->getResult() % 10 == 9) && i->getResult() < 30 && (i->getResult() > 30 && i->getResult() < 38)){
//                cnt++;
//            }
//        }
//        if(cnt < 1){
//            return false;
//        }
//    }
//    bool kehu = hupaipanduan(pais, systemConfig);
//    if (systemConfig.yaojiyitongdangzipai == 1) {
//        if (!kehu) {
//            kehu = yaojiyitongdangzipai(pais);
//        }
//    }
//    if (systemConfig.yaojiyitongdangzipaifengpai == 1) {
//        if (!kehu) {
//            kehu = yaojiyitongdangzipaifengpai(pais);
//        }
//    }
//    if (kehu) {
//        if (kehu_list.size() > 4000) {
//            kehu_list.erase(kehu_list.begin());
//        }
//        kehu_list.insert(stringBuilder);
//    } else {
//        if (systemConfig.lanpai == 1 && pais.size() == 14) {
//            kehu = lanpai(pais);
//        }
//    }
//        return kehu;
//}




