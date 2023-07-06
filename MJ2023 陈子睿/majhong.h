#ifndef MAJHONG_H
#define MAJHONG_H

#include "mainwidget.h"

#include <string>
#include <list>
#include<functional>//greater
#include<unordered_set>


class HuPaiKit;

class SystemConfig;

//class Mj  {
//    friend HuPaiKit;
//public:
//    bool isHu() {return hu;}
//    void setHu(bool hu) {this->hu = hu;}

//    bool isLast() {return last;}
//    void setLast(bool last) {this->last = last;}

//// ImageView getHupai_imageView() {return hupai_imageView;}
//    bool getIsque() {return isque;}
//    void setIsque(bool isque) {this->isque = isque;}
// //void setHupai_imageView(ImageView hupai_imageView) {this->hupai_imageView = hupai_imageView;}

//    int getPaizhuangtai() const {return paizhuangtai;}
//    void setPaizhuangtai(int paizhuangtai) {this->paizhuangtai = paizhuangtai;}

//    int getYuce_direction() {return yuce_direction;}
//    void setYuce_direction(int yuce_direction) {this->yuce_direction = yuce_direction;}

//    int getNapai_direction() {return napai_direction;}
//    void setNapai_direction(int napai_direction) {this->napai_direction = napai_direction;}

//    bool getSimo() {return simo;}
//    void setSimo(bool simo) {this->simo = simo;}

//    int getChupai_direction() {return chupai_direction;}
//    void setChupai_direction(int chupai_direction) {this->chupai_direction = chupai_direction;}
//    //Node getOther() {return other;}
//    //void setOther(Node other) {this->other = other;}
//    //ImageView getWeina_imageView() {return weina_imageView;}
//    //void setWeina_imageView(ImageView weina_imageView) {this->weina_imageView = weina_imageView;}
//    //MjControlInterface getYina_imageView() {return yina_imageView;}
//    //void setYina_imageView(MjControlInterface yina_imageView) {this->yina_imageView = yina_imageView;}
//    //MjControlInterface getYuce_imageView() {return yuce_imageView;}
//    //void setYuce_imageView(MjControlInterface yuce_imageView) {this->yuce_imageView = yuce_imageView;}
//    //ImageView getYichu_imageView() {return yichu_imageView;}
//    //void setYichu_imageView(ImageView yichu_imageView) {this->yichu_imageView = yichu_imageView;}

//    int getResult() const{return result;}
//    void setResult(int result) {this->result = result;}

//    int getId() {return id;}
//    void setId(int id) {this->id = id;}

//    int getSerial_number() {return serial_number;}
//    void setSerial_number(int serial_number) {this->serial_number = serial_number;}

//    int getMahjong_number() {return mahjong_number;}
//    void setMahjong_number(int mahjong_number) {this->mahjong_number = mahjong_number;}

//    int getDirection() {return direction;}
//    void setDirection(int direction) {this->direction = direction;}

//    int getZhuo_id() {return zhuo_id;}
//    void setZhuo_id(int zhuo_id) {this->zhuo_id = zhuo_id;}

//    bool isMaima() {return maima;}
//    void setMaima(bool maima) {this->maima = maima;}

//    std::string getZhiBiaoZHi() {return std::to_string(result) + "_" + std::to_string(yuanpai) ; }

//    ///自写
//    bool isCaisheng() const{ return  caisheng;}

//    bool operator==(const Mj mj) const {
//        if(this->result == mj.getResult()){
//            return  true;
//        }else{
//            return  false;
//        }
//    }

//private:
//    int id;//id
//    int serial_number;//设备序列号  桌号
//    int mahjong_number;//第几张牌
//    int zhuo_id = 0;//局id
//    int direction;//设备方向
//    int napai_direction = -1;//拿牌方向
//    int yuce_direction = -1;//预测方向
//    int chupai_direction = -1;//出牌方向
//    std::string add_time;//时间
//    int result;

//    int  paizhuangtai = 0;//牌的状态  0:正常  1:碰 2:明杠 3:暗杠 4:吃的牌
//    bool isque = false;//缺一门
//    bool simo = false;//是否已拿
//    bool maima = false;//买马
//    bool last = false;//最后摸的
//    bool hu = false;//胡的
//public:
//    bool caisheng = false;//财神
//    int caisheng_dipai = 0;//财神所抵的牌
//    bool kedi_caisheng = false;//可抵财神
//    int yuanpai = 0;//抵财神或花牌的原牌
//    bool kedi_huapai = false;//可抵花牌
//    bool huapai_yuce = false;//预测花牌 杠后预测的牌

////private ImageView weina_imageView;
////private MjControlInterface yina_imageView;
////private MjControlInterface yuce_imageView;
////private ImageView yichu_imageView;
////private ImageView hupai_imageView;
////private Node other;

//};


//class HuPaiKit{
//public:
//    static bool ComparatorMjResult(const Mj x,const  Mj y){
//        double r0= x.getResult();
//            double r1= y.getResult();

//            if(r0 == 56.0){
//                r0 = 10.0;
//            }if(r1 == 56.0){
//                r1 = 10.0;
//            }

//            if(r0 == 57.0){
//                r0 = 30.0;
//            }if(r1 == 57.0){
//                r1 = 30.0;
//            }

//            if(r0 == 58.0){
//                r0 = 20.0;
//            }if(r1 == 58.0){
//                r1 = 20.0;
//            }

//            if(r0 == 52.0){
//                r0 = 38.0;
//            }if(r1 == 52.0){
//                r1 = 38.0;
//            }
//            if(r0 == 53.0){
//                r0 = 34.5;
//            }
//            if(r1 == 53.0){
//                r1 = 34.5;
//            }

//            double r = (r0 - r1);

//            if(r >= 0){
//                return false;
//            }else{
//                return  true;
//            }
//        //    if(r < 0){
//        //        return -1;
//        //    }

//        //    return 0;
//    }

//    //胡牌判定
//    bool HuPaiPanDin(std::list<Mj> mahs, int que, SystemConfig systemConfig);

//private:
//    bool hupaipanduan(std::list<Mj>, SystemConfig);
//    bool lanpai(std::list<Mj> yushimjs);
//    bool yaojiyitongdangzipai(std::list<Mj> yushimjs);
//    bool yaojiyitongdangzipaifengpai(std::list<Mj> yushimjs);
//};

//class MjConfig {
//public:
//    int getId() {return id;}
//    void setId(int id) {this->id = id;}

//    int getNumber() { return number;}
//    void setNumber(int number) {this->number = number;}

//    std::string getName() {return name;}
//    void setName(std::string name) {this->name = name;}

//    std::string getUrl() {return url;}
//    void setUrl(std::string url) {this->url = url;}

//private:
//    int id;
//    int number;
//    std::string name;
//    std::string url;
//};

//// std::unordered_set<Mj> weina的模版特化
//namespace std{
////    template<typename T>
////    struct identity { typedef T type; };

//    template<>
//    struct hash<Mj>
//    {
//        size_t operator()(const Mj& rhs) const{
//            return hash<int>()(rhs.getResult());
//        }
//    };

//    template<>
//    struct equal_to <Mj> {
//        bool operator()(const Mj& lhs, const Mj& rhs) const{
//            return lhs.getResult() == rhs.getResult();
//        }
//    };
//}

//class Config {

//public:
//     int MJ_COUNT = 108;//牌数
//     std::list<MjConfig> mjConfigs;

//     std::unordered_set<Mj> weina;//未摸牌
//     std::list<Mj> yina;//手上的牌
//     std::list<Mj> yuce;//将要拿到的牌
//     std::list<Mj> yichu;//打出去的牌

//     SystemConfig systemConfig;//详细设置
//public:
//     void setMJ_COUNT(int num){ this->MJ_COUNT = num;}//设置牌的张数
//     //洗牌
//    void xipai(std::list<Mj>&);//有用
//    void xipai(int ,int );

//};


//class MainController{
//public:
//    int zhuangjia = -1;
//    int dapaifangx = -1;
//    int meijuchongshehuapai = 1;//每局重设花牌
//    int meijuchongshecaisheng = 1;//每局重设财神
//    int meijuchongshedanzhangkegang = 1;//每局重设单张可杠
//    std::list<int> caisheng;//财神
//    std::list<int> zixuanhuapai;//自选的可当花牌的牌
////    Stage caisheng_seting_popup;//财神选择
////    Stage zixuanhuapai_seting_popup;//自选花牌选择
////    Stage danzhangkegang_seting_popup;//单张可杠选择
//    //Label renyicaisheng_label;
//public:
//    std::list<Mj> huanhoupai_yixuan;//换手牌 选择的牌
//};

#endif // MAJHONG_H
