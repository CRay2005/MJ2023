#pragma once

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include<QSystemTrayIcon>
#include <QMenu>

#include <QLabel>

#include <unordered_set>

#include <string>

#include <vector>

#include <map>

#include <QString>

#include <stack>

#include<utility>//pair

#include "majhong.h"


//#include<QTcpSocket>//套接字

#include <QTimer>

#include <QDebug>

class QToolButton;

namespace Ui {
class UIMainWindows;
}

class Mj;
class Mj  {
//    friend HuPaiKit;
public:
    bool isHu() const{return hu;}
    void setHu(bool hu) {this->hu = hu;}

    bool isLast() const {return last;}
    void setLast(bool last) {this->last = last;}

// ImageView getHupai_imageView() {return hupai_imageView;}
    ///缺一门（有用）
    bool getIsque() const {return isque;}
    void setIsque(bool isque) {this->isque = isque;}
 //void setHupai_imageView(ImageView hupai_imageView) {this->hupai_imageView = hupai_imageView;}
    ///吃碰杠胡(有用)
    int getPaizhuangtai() const {return paizhuangtai;}
    void setPaizhuangtai(int paizhuangtai) {this->paizhuangtai = paizhuangtai;}

    int getYuce_direction() {return yuce_direction;}
    void setYuce_direction(int yuce_direction) {this->yuce_direction = yuce_direction;}

    int getNapai_direction() {return napai_direction;}
    void setNapai_direction(int napai_direction) {this->napai_direction = napai_direction;}

    bool getSimo() {return simo;}
    void setSimo(bool simo) {this->simo = simo;}

    int getChupai_direction() {return chupai_direction;}
    void setChupai_direction(int chupai_direction) {this->chupai_direction = chupai_direction;}

    int getResult() const{return result;}
    void setResult(int result) {this->result = result;}
//牌id（有用）
    int getId() const {return id;}
    void setId(int id) {this->id = id;}

    int getSerial_number() {return serial_number;}
    void setSerial_number(int serial_number) {this->serial_number = serial_number;}

    int getMahjong_number() {return mahjong_number;}
    void setMahjong_number(int mahjong_number) {this->mahjong_number = mahjong_number;}

    int getDirection() {return direction;}
    void setDirection(int direction) {this->direction = direction;}

    int getZhuo_id() {return zhuo_id;}
    void setZhuo_id(int zhuo_id) {this->zhuo_id = zhuo_id;}

    bool isMaima() {return maima;}
    void setMaima(bool maima) {this->maima = maima;}

    std::string getZhiBiaoZHi() {return std::to_string(result) + "_" + std::to_string(yuanpai) ; }

    ///自写
    bool isCaisheng() const{ return  caisheng;}

    bool operator==(const Mj mj) const {
        if(this->result == mj.getResult()){
            return  true;
        }else{
            return  false;
        }
    }

    Mj& operator=(const Mj &mj) {
        if(&mj != this){//自我赋值判断
            result = mj.getResult();
            paizhuangtai = mj.getPaizhuangtai();
            id = mj.getId();
            hu = mj.isHu() ;
            last = mj.isLast();
            isque = mj.getIsque();
          }
            return *this;
    }

private:
    int id;//id
    int serial_number;//设备序列号  桌号
    int mahjong_number;//第几张牌
    int zhuo_id = 0;//局id
    int direction;//设备方向
    int napai_direction = -1;//拿牌方向
    int yuce_direction = -1;//预测方向
    int chupai_direction = -1;//出牌方向
    std::string add_time;//时间
    int result = -1;

    int  paizhuangtai = 0;//牌的状态  0:正常  1:碰 2:明杠 3:暗杠 4:吃的牌 5:胡牌
    bool isque = false;//缺一门
    bool simo = false;//是否已拿
    bool maima = false;//买马
    bool last = false;//最后摸的
    bool hu = false;//胡的
public:
    bool caisheng = false;//财神
    int caisheng_dipai = 0;//财神所抵的牌
    bool kedi_caisheng = false;//可抵财神
    int yuanpai = 0;//抵财神或花牌的原牌
    bool kedi_huapai = false;//可抵花牌
    bool huapai_yuce = false;//预测花牌 杠后预测的牌


};


class Config;
class SystemConfig{
    friend Config;
public:
    //规则参数
    bool isPrediction=false;   //CRay,  false 不显示预测牌，true显示
    bool isAIshow=true;         //CRay,false 不显示AI玩家手牌，true显示
    int AILevel;
    int AIPlayers=3;

    int mapaicengshu=2;//码牌层数
    int mapaifangshi=0;//码牌方式 0:摆两层 1:摆三层 2:单张(栋)在后 3:逐层码牌 4:136三层 5:144三层 6:摆四层(头+尾=六栋)
    int wanjiapaishu=13;//玩家牌数
    QString tiaopai="隔跳";//跳牌
    int meishouzhangshu=4;//每手张数
    int yucepai = 10;//预测牌
    int wanjiarenshu=4;//玩家人数
    int huanshoupai=0;//换手牌
    int guoshanchediaohuan=0;//过山车调换牌

    int zhuapaihouxuanzhuang=0;//抓牌后选庄
    int sanceng_liangdongsizhang=0;//三层,两栋四张(抓牌)
    int errenzhuaerfangweipai=0;//二人抓二方位牌
    int qutouzhang=0;//去头张
    int xianzhuan8houzhuan4=0;//先抓8后抓4
    int meijuchongxuanquefang=0;//每局重选缺方
    int disancengzuowanjiapai=0;//第三层做玩家牌
    int meijushetiaopai=0;//每局设挑牌
    int bugoudongyizhiweibu=0;//不够栋移至尾部
    int _20zhangzhuangjiaxianzhuangsanzhangzaizhuayizhang=0;//20张庄家先抓3张再抓1张
    int butiaopaizhangjialianxu14xian13=0;//不跳牌，庄家连续14,闲13
    int zhuapai123=0;//抓牌123
    int zhuapai321=0;//抓牌321
    int pingna=0;//平拿
    int niezhuanimo=0;//逆抓逆摸
    int nanbeihuhuandongdexiajiashibei=0;//南北互换,东的下家是北
    int zijiazuosandunyousandun=0;//自家左3墩右3墩
    int sicengsandun=0;//四层3墩
    int qishourenyiliangdong=0;//起手任意两栋
    int renyiandongnapai=0;//任意按栋拿牌

    //花牌
    std::string gangfa="轮到自由杠(手动杠花)";//杠法
    int zixuanhuapai=0;//自选花牌(非花牌当花)
    int anhuiganghua=0;//安徽杠花(首轮)
    int shoupaibuxianshihuapai=0;//手牌不显示花牌
    int yucepaibuxianshihuapai=0;//预测牌不显示花牌
    int anqingmajiangdahua=0;//安庆麻将打花
    int huapaikepang_foushanmajiang=0;//花牌可碰(佛山麻将)
    int huapaidaiticaishengpai_foushanmajiang=0;//花牌代替财神牌(佛山麻将140)
    std::string ganghua="顺杠牌";//杠花

    //扣牌
    int diyishou=0;//第一手
    int diershou=0;//第二手
    int disanshou=0;//第三手
    int zuihouyizhang=0;//最后一张
    int zixuankoupai=1;//自选扣牌

    //其它
    int jiemianbuju=0;//界面布局
//    double[] zidingyibeijingyanse={0,0,0};//自定义背景颜色
    int shengyingtishi=0;//声音提示
    int chupaixianshi=0;//出牌显示 0:出牌顺序 1;花色
    int zidongjietu=0;//自动截图
    int mimabaohu=0;//密码保护
    int jianpancaozuomoshi=0;//键盘操作模式
    int zhuomianbuxuanzhuan=0;//桌面牌不旋转

    //打牌
    int pongpai = 1;//碰牌(yong)
    int chipai = 0;//吃牌(yong)
    int baoliupai = 0;//保留手上的牌
    int danzhangkechi = 0;//单张可吃
    int chisanfangpai = 0;//吃三方牌
    int gangshouzhongpai = 1;//杠手中牌(yong)
    int fengpaizipaisanzhangkegang = 0;//风牌字牌三张可杠
    int angang = 1;//暗杠(yong)
    int minggang = 1;//明杠(yong)
    int danzhangkegang = 0;//单张可杠
    std::list<int> danzhangkegang_pai;//单张可杠的牌
    int koupai=0;//扣牌(右击)
    int dongnanxibeikechikegang=0;//东南西北可吃可杠
    int zipaifengkai=0;//字牌分开(西南北,中发白)
    int renyisangedanzhangzipai=0;//任意三个单张字牌
    int leqing=0;//乐清(红中当花)
    int dongnanxibeizhongfabaigang=0;//东南西北(中发白)杠
    int dongnanxibeizhongfabaigangqingdao=0;//东南西北(中发白)杠（青岛）
    int dongnanxibeizhongfabaishunzi=0;//东南西北(中发白)顺子
    int pangjiang=0;//碰将
    int yaojiyitongdangfengpai=0;//幺鸡一筒当风牌(甘肃)
    int rengyijiu=0;//扔一九(甘肃)
    int yaojiyitongdangzipai=0;//幺鸡一筒当字牌(甘肃)
    int yaojiyitongdangzipaifengpai=0;//幺鸡一筒当字牌风牌(甘肃)
    int wugezipaigang=0;//五个字牌杠(三个风牌两个箭牌,补两个)
    int yaojiugangsangebubusigebuyige=0;//幺九杠(三个不补,四个补一个)
    int yaojiugang=0;//幺九杠
    int yaojiugangshengyangbusangehuosige=0;//幺九杠(沈阳补三个或四个)
    int zhucengnapai=0;//逐层拿牌
    int niezhuapai=0;//逆抓牌
    int yingchuanbufeng=0;//银川补风
    std::string gangpaishunxu="顺杠牌";//杠牌顺序

    //胡牌
    int zhixianzimo=0;//只限自摸
    int qiangganghu=1;//抢杠胡
    int erwubajiang=0;//二五八将
    int queyimen =0;//缺一门
    int xuezhandaodi=0;//Cray 血战到底

    int hupaikepang=0;//胡牌可碰
    int hupaikegang=0;//胡牌可杠
    int fangpaoxiajia=0;//放炮下家
    int yipaoduoxiang=1;//一炮多响
    int hupaikemo=0;//胡牌可摸
    int buchibupangdapaitishi=0;//不吃不碰打牌提示
    int lanpai=0;//烂牌
    int xiaoqidui=1;//小七对
    int bixuyou19zipaifengpairenyiyizhang=0;//19字牌风牌任意一张
    int pengpaihuozhezhongfabaidui=0;//碰牌或者中发白对

    //财神
    int zixuancaisheng=0;//自选财神
    int houcaisheng=0;//后财神
    int shunmocaisheng=0;//顺摸财神
    int renyicaisheng=0;//任意财神
    int shengjicaisheng=0;//升级财神
    int shuangcaisheng=0;//双财神
    int shangcaisheng_combox=0;//双财神
    int zhongjianpaizuohua=0;//中间牌做花
    int shengjicaishengshihuapaijixu=0;//升级财神是花牌继续升
    int daiticaishengpai=0;//代替财神牌
    int daiticaishengpai_combox=0;//代替财神牌
    int daitipaibaoliuyuanpaizuoyong=0;//代替牌保留原牌作用
    int caishenganzhengchangpaichanyuchangpanggang=0;//财神按正常牌参与吃碰杠
    int andaitipaixianshi=0;//按代替牌显示
    int budaiticaishengzipai=0;//不代替财神字牌
    int buhuahoumocaisheng=0;//补花后摸财神
    int caishengcanyuchipanggang=0;//财神参与吃碰杠(起飞)
    int caishengkedangang=0;//财神可单杠
    int jiaohuanpai=0;//交换牌(与拿牌位置倒数第三栋第一张)
    int fankaidcaishengpaidanghua=0;//翻开的财神牌当花
    int fankaidcaishengpaifangzuihouweizhi=0;//翻开的财神牌放在最后位置
    int fankaishihuapaijixufan=0;//翻开是花牌继续翻
    int caishenganzhengchangpaicanyuchengpanggang=0;//财神按正常牌参与吃碰杠
    int zhuapaihouxuancaisheng=0;//抓牌后选财神
    int zipaifengpaifenkaishengji=0;//字牌风牌分开升级
    int fankaidepaibuzuocaisheng=0;//翻开的牌不做财神
//int
    //快捷方式
    std::string huoqushuju;//获取数据
    std::string guopai;//过牌
    std::string xunhuanguopai;//循环过牌
    std::string guodong;//过栋
    std::string kanchupai;//看出牌
    std::string mopai="空格键";//摸牌
    std::string chipai_kjj;//吃牌
    std::string gangpai;//杠牌
    std::string pangpai_kjj;//碰牌
    std::string chexiao="z";//撤销
    std::string chongxuanzhuang;//重选庄
    std::string shubiaoyouji="撤销";//鼠标右击

    int leqingmajiang=0;//乐清麻将
    int guangxi152=0;//广西152
    int xianmajiang=0;//仙麻将
    int yuhuanwahua=0;//玉环挖花
    int wenchengmajiang=0;//文城麻将
    int wenlingmajiang=0;//温岭麻将
    int xianmaimahoudingzhuang=0;//先买马后定庄
};

class MjConfig {
public:
    int getId() {return id;}
    void setId(int id) {this->id = id;}

    int getNumber() { return number;}
    void setNumber(int number) {this->number = number;}

    std::string getName() {return name;}
    void setName(std::string name) {this->name = name;}

    std::string getUrl() {return url;}
    void setUrl(std::string url) {this->url = url;}

private:
    int id;
    int number;
    std::string name;
    std::string url;
};


class Config {

public:
     int MJ_COUNT = 108;//牌数（用到）
     std::list<MjConfig> mjConfigs;

//     std::unordered_set<Mj> weina;//未摸牌
     std::list<Mj> yina;//手上的牌
     std::list<Mj> yuce;//将要拿到的牌
     std::list<Mj> yichu;//打出去的牌

     SystemConfig systemConfig;//详细设置
public:
     void setMJ_COUNT(int num){ this->MJ_COUNT = num;}//设置牌的张数（用到）
     //洗牌
    void xipai(std::list<Mj>&);//有用
    void xipai(int ,int );

};


class UIMainWindows : public QWidget
{
    Q_OBJECT

public:
    explicit UIMainWindows(QWidget *parent = 0);
    ~UIMainWindows();

private://界面控件
    Ui::UIMainWindows *ui;

    QList<int> pixCharMain;
    QList<QToolButton *> btnsMain;

    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;

    //窗口任务栏属性
      QSystemTrayIcon *trayIcon;
      QMenu *trayMenu ;

      void iconActivated(QSystemTrayIcon::ActivationReason);

       QAction *trayShowMainAction;//托盘显示窗口信号发生体
       QAction *trayExitAppAction;//托盘显示窗口信号发生体
       void on_showMainAction();//托盘槽
       void on_exitAppAction();//托盘槽

private slots://初始化窗体界面
    void initForm();
    void buttonClick();
    void initLeftMain();
    void initLeftConfig();
    void leftMainClick();
    void leftConfigClick();
    void initTrayIcon();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void on_xipaiButton_clicked();

    void on_startGameButton_clicked();//开始游戏按钮

    void on_endGameButton_clicked();//结束游戏按钮



public slots://面板显示：
    //抓牌显示
    void initSouthDrawDisplay(const std::vector<Mj>& ,int ) const;
    void initWestDrawDisplay(const std::vector<Mj>& , int ) const;
    void initNorthDrawDisplay(const std::vector<Mj>&, int ) const;
    void initEastDrawDisplay(const std::vector<Mj>&, int ) const;   

    //清除牌墙
    void clearSouthDrawDisplay(int cnt);
    void clearEastDrawDisplay(int cnt);
    void clearNorthDrawDisplay(int cnt);
    void clearWestDrawDisplay(int cnt);
    void clearDrawDisplay();

    //拿牌显示
    void southHandDisplay(std::list<Mj>&);
    void eastHandDisplay(std::list<Mj>&);
    void northHandDisplay(std::list<Mj>&);
    void westHandDisplay(std::list<Mj>&);

    //弃牌显示
    void discardDisplay(const std::list<Mj>&) const;
    //游戏开始拿牌显示
    void beginGameDisplay(std::list<Mj>&, std::list<Mj>&, std::list<Mj>&, std::list<Mj>&);
    //预测牌显示
    void southPredictionDisplay(const std::list<Mj>&) const;
    void eastPredictionDisplay(const std::list<Mj>&) const;
    void northPredictionDisplay(const std::list<Mj>&) const;
    void westPredictionDisplay(const std::list<Mj>&) const;
    //展示箭头
    void directionDisplay(const int);
    //吃、碰、 牌展示
    void ChowDisplay();
    void PongDisplay();
    void KongDisplay();
    void checkDisplay();
    //胡牌展示
    void winDisplay();
    //听牌展示
    void readyDisplay();

    //清空手牌吃碰杠状态
    void clearHandStatus();
    //清空听牌状态
    void clearReady();
    //选庄家显示
    void bankerDisplay();
    void clearBanker();
    void bankerDirectionDisplay();//庄家方向显示

public slots:
    //初始化游戏界面
    void initGamePanel();
    //初始化托盘
    void initTray();
    //安装事件过滤器
    void initInstallEventFilter();
    //初始化配置设置
    void initConfig();
    void initUselessConfig();
    void getConfig();//得到配置信息


signals://信号
    void logoutdialogShow();//显示登陆界面
    void accountShow();//重新加载账号
    void onPlayBackgroundMusic();//播放背景音乐

private://重要变量
    std::list<Mj> majhongTotal;//全部的麻将
    std::list<Mj> majhongRemain;//剩余的麻将
    std::list<Mj> majhongTaken;// 拿走的麻将

    //牌墙的牌
    std::vector<Mj> drawNorthMjs;
    std::vector<Mj> drawEastMjs;
    std::vector<Mj> drawSouthMjs;
    std::vector<Mj> drawWestMjs;

    //手牌
    std::list<Mj> handNorthMjs;
    std::list<Mj> handSouthMjs;
    std::list<Mj> handWestMjs;
    std::list<Mj> handEastMjs;

    //预测牌
    std::list<Mj> predictionNorthMjs;
    std::list<Mj> predictionSouthMjs;
    std::list<Mj> predictionWestMjs;
    std::list<Mj> predictionEastMjs;

    //弃牌
    std::list<Mj> discardMjs;

    Config config;//设置
    SystemConfig systemConfig;//胡牌设置

    bool isBeginGame = false;//开始游戏，可以点击牌墙来摸牌

    //每个方向的牌数
    int zhangshuSouth;
    int zhangshuWest;
    int zhangshuNorth;
    int zhangshuEast;

    bool isMopai = false;

    //第一次摸完牌后，下一次摸牌的位置
    int mopaiDirection = -1;//0南  1东 2北 3西
    int mopaiPos = -1;//0,1,2,....
    int mopaiCeng = 1;//1第二层 1第二层

    int mopaiWanjia = -1;//0南  1东 2北 3西
    int dapaiWanjia = -1;

    std::unordered_set<int> endWanjia;//缺一门 （胡的玩家）

    //预测位置
    int yuceDirection = -1;//0南  1东 2北 3西
    int yucePos = -1;//0,1,2,....
    int yuceCeng = 1;//1第二层 1第二层


    //预测牌的数目
    int predictionNumber = 10;

    //目前打出的牌
    std::vector<Mj> playedPai;

    //是否是刚摸起牌
    bool isDraw = false;//是否是刚摸起来牌

    //判断吃碰杠
    //吃
    bool isSouthChow = false;
    bool isNorthChow = false;
    bool isEastChow = false;
    bool isWestChow = false;
    std::vector<int> chowType;//吃牌的类型0（-1，+1），1（+1，+2），2（-1，-2）
    std::vector<Mj> chowVec;//吃牌的队列组合中 原始牌中的第一个元素

    //碰
    bool isSouthPong = false;
    bool isNorthPong = false;
    bool isEastPong = false;
    bool isWestPong = false;

    //杠(明杠)
    bool isSouthKong = false;
    bool isWestKong = false;
    bool isNorthKong = false;
    bool isEastKong = false;
    //记录暗杠个数
    int concealedKongNum[4];//记录暗杠个数
    std::vector<int> concealedKongElement[4];//记录暗杠元素
    std::vector<int> concealedKongType[4];//暗杠类型————0全手牌，1是碰杠
    //抢杠胡
    bool isQiangganghu = false;    
    std::vector<int> qiangganghuElement[4];//碰了的但是还可以杠的牌
    int qiangganghuPaiNum = 0;//抢杠的牌
    int qiangganghuType = -1;//0-——-一个碰杠，1————多个碰杠
//    int qiangganghuDirection = -1;//抢杠胡的方向 （0南1东2北3西）

    //能否暗杠
    bool isSouthConcealedKong = false;
    bool isWestConcealedKong = false;
    bool isNorthConcealedKong = false;
    bool isEastConcealedKong = false;

    //手牌有效位置
    int handSouthIndex = 0;
    int handWestIndex = 0;
    int handEastIndex = 0;
    int handNorthIndex = 0;
    //胡
    bool isSouthWin = false;
    bool isEastWin = false;
    bool isNorthWin = false;
    bool isWestWin = false;

    //听
    bool isSouthReady = false;
    bool isEastReady = false;
    bool isNorthReady = false;
    bool isWestReady = false;

    std::vector<int> readyElemnt[4];//听牌的元素

    //听的牌对应的个数
    std::map<int, int> southReadyHash;
    std::map<int, int> eastReadyHash;
    std::map<int, int> northReadyHash;
    std::map<int, int> westReadyHash;

   //缺一门对应的花色
    //记录第一次出牌的缺门
    int southQue = -10;//0---万、10---条、20---筒
    int eastQue = -10;
    int northQue = -10;
    int westQue = -10;

    bool isSouthQue = true;
    bool isEastQue = true;
    bool isNorthQue = true;
    bool isWestQue = true;

    //改牌
   bool changeSouthPai = false;
   bool changeEastPai = false;
   bool changeNorthPai = false;
   bool changeWestPai = false;

    //胡牌
   bool isZimo = false;//自摸  

   std::stack<int> dapaiWanjiaStack;//记录每次的打牌玩家
   std::stack<Mj> playedPaiStack;//记录每次打出的牌
   //记录暗杠
   std::stack<std::pair<int,int>> southKongStack;//南 (暗杠牌，暗杠类型)————（类型：0:全手牌；1:碰杠）
   std::stack<std::pair<int,int>> eastKongStack;//东
   std::stack<std::pair<int, int>> northKongStack;//北
   std::stack<std::pair<int,int>> westKongStack;//西

    //是否是第一次选庄
   bool isBanker = true;

private://功能函数

   void clear136Information();//清空136张的残留信息

   //清空面板
   void clearPanel();
   void clearVariable();

   void clearScore();
   void setScoreTxt();//显示各玩家分值

   void setbglabel();//设置麻将桌背景

   void loadWidgetList();//控件较多，为了便于处理，将东南西北相关label赋值给对应的数组

   ///开始摸牌,包括跳牌摸牌
   void beginDraw(std::list<Mj>&, std::list<Mj>&,
                  std::list<Mj>&, std::list<Mj>&);//跳摸牌,0隔跳 1上下跳 2平跳

   //摸牌
   void draw();
   //查找牌
   void findPai(Mj&);
   //更新牌
   void updatePai();
   void undoPai();//回退牌
    //结束游戏
   void endGame();
   //打牌(正常)
   void dapai(int pos);   
   //AI打牌 CRay
   void AIPlay();
   int AIPosition(std::list<Mj>&);
   void AIChow();
   void AIPong();
   void AIKong();
   void AIHu();
   void HuSouth();
   void HuEast();
   void HuNorth();
   void HuWest();

   //吃 打牌
   void chowDapai(int pos);
   //明杠 打牌
   void kongDapai(int pos);
   ///预测
   //预测牌
   void yucePai();
   //更新预测
   void yuceUpdatePai();
   //查找牌
   void yuceFindPai(Mj&);

   ///判断
  // bool isReady();//听
   void isChow();//吃
   bool isChow2(int, int);//牌上箭头

   //Cray AI吃牌，多个可吃的操作时，选择第一个吃牌动作，后续可考虑智能判断选择哪个吃牌动作
   void AIchowOperating(std::list<Mj>&);//AI吃牌操作

   void chowOperating(std::list<Mj>&);//只有一个吃的操作
   void chowOperating2(std::list<Mj>&, int);//多个吃的操作



   void isPong();//碰
   void pongOperating(std::list<Mj>&);//碰操作
   int isPong2(int, int );//牌上面的箭头判断 //0：南,1：东,2：北,3：西，-1：无

   void isKong();//杠
   int isKong2(int, int);//牌上的箭头
   void isConcealedKong(std::list<Mj>,int);//暗杠
   void kongOperating(std::list<Mj>&);//只有一个明杠操作
   void kongOperating2(std::list<Mj>&);//只有一个暗杠操作
   void kongOperating3(std::list<Mj>&,int);//有多个暗杠操作

   void isWin();//胡（自摸）
   void isWin2();//放炮胡
   void isWin3(int);//抢杠胡
   void isWin4();//开局胡

   //听
   void isReady();

   //更新摸牌玩家
   void updateMopaiWanjia();
   //更新打牌玩家
   void updateDapaiWanjia();


   //打牌事件、摸牌事件
   bool eventFilter(QObject *obj, QEvent *event);//时间过滤器

   //撤回操作
   void undoOperating();

public://网络连接
//    QTcpSocket *tcpClient;//套接字

    QByteArray outBlock;  // 数据缓冲区，即存放每次要发送的数据块

    qint64 totalBytes;//发送数据的总大小
    qint64 writtenBytes;//已发送的
    qint64 toWrittenBytes;//剩余的

    void initClient();//初始化客户端的信号槽函数的连接

    void connectServer();//连接服务器
    void sendServerInfo();//发送数据到服务器

    QString byteArrayToHexStr(const QByteArray &data);//数据转16进制(带空格)

    QString majhongDataTotal;

    void dealMajhongData(const QString& majhongDataTotal);//把字节数组转麻将数据
    void printMajhongData(int);

    std::vector<int> majhongNumTotal;
    void testMajhongData();

public slots:
    void tcpClientConnected();//更新连接状态
    void tcpClientDisconnected();//断开连接处理的事件
    void printServerMessage();//打印服务器回应
//    void displayError(QAbstractSocket::SocketError);//处理错误函数

    void startClientTransfer();//发送数据到服务器  //登录 C->S
    void sendHeartBeat();

signals:
    void buildServerConnected();//连接上服务器后，发出的信号
private slots:
     void on_connectButton_clicked();//连接服务器
///HuPaiKit类 胡牌类
     void on_sendServerButton_clicked();//发送数据到服务器

     void on_northbeginButton_clicked();

public:
   static bool ComparatorMjResult(const Mj x,const  Mj y){
       double r0= x.getResult();
           double r1= y.getResult();

           if(r0 == 56.0){
               r0 = 10.0;
           }if(r1 == 56.0){
               r1 = 10.0;
           }

           if(r0 == 57.0){
               r0 = 30.0;
           }if(r1 == 57.0){
               r1 = 30.0;
           }

           if(r0 == 58.0){
               r0 = 20.0;
           }if(r1 == 58.0){
               r1 = 20.0;
           }

           if(r0 == 52.0){
               r0 = 38.0;
           }if(r1 == 52.0){
               r1 = 38.0;
           }
           if(r0 == 53.0){
               r0 = 34.5;
           }
           if(r1 == 53.0){
               r1 = 34.5;
           }

           double r = (r0 - r1);

           if(r >= 0){
               return false;
           }else{
               return  true;
           }

   }

   static bool ComparatorMjResult2(const Mj x,const  Mj y){
         if(x.getResult() > y.getResult()){
             return  false;
         }else{
             return true;
         }
   }

   //胡牌判定
   //正式
   bool HuPaiPanDin(std::list<Mj> mahs, int que, SystemConfig systemConfig);
    //java版本
   bool HuPaiPanDin2(std::list<Mj> mahs, int que, SystemConfig systemConfig);
   bool isSequence(const std::list<Mj>&,int)const;//顺子
   bool isTriplet(const std::list<Mj>&,int)const;//刻字

private:
   bool hupaipanduan2(std::list<Mj>, SystemConfig);

   bool hupaipanduan(std::list<Mj>, SystemConfig);
   bool lanpai(std::list<Mj> yushimjs);
   bool yaojiyitongdangzipai(std::list<Mj> yushimjs);
   bool yaojiyitongdangzipaifengpai(std::list<Mj> yushimjs);


//MainController类信息
public:
    int zhuangjia = -1;//庄家 0南  1东 2北 3西 （有用）

    int dapaifangx = -1;
    int meijuchongshehuapai = 1;//每局重设花牌
    int meijuchongshecaisheng = 1;//每局重设财神
    int meijuchongshedanzhangkegang = 1;//每局重设单张可杠

    int eastscore=0;
    int southscore=0;
    int westscore=0;
    int northscore=0;

    std::list<int> caisheng;//财神
    std::list<int> zixuanhuapai;//自选的可当花牌的牌

public:
    std::list<Mj> huanhoupai_yixuan;//换手牌 选择的牌

    std::list<Mj> getPredictionNorthMjs() const;
    void setPredictionNorthMjs(const std::list<Mj> &value);

private:
    QWidget* bankerlist[4];
    QWidget* dirbeginlist[4];
    QLabel* drawSouthlist1[17];
    QLabel* drawSouthlist2[17];
    QLabel* drawEastlist1[17];
    QLabel* drawEastlist2[17];
    QLabel* drawNorthlist1[17];
    QLabel* drawNorthlist2[17];
    QLabel* drawWestlist1[17];
    QLabel* drawWestlist2[17];
    QLabel* handSouthlist[18];
    QLabel* handEastlist[18];
    QLabel* handNorthlist[18];
    QLabel* handWestlist[18];
    QLabel* handPromptSouthlist[18];
    QLabel* handPromptEastlist[18];
    QLabel* handPromptNorthlist[18];
    QLabel* handPromptWestlist[18];

};

#endif

