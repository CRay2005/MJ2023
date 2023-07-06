#include "logindialog.h"
#include "ui_logindialog.h"

#include "connnection.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "iconhelper.h"

#include <QBitmap>
#include <QPainter>
#include <QMediaPlaylist>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    ui->loginButton->setStyleSheet("background-color: rgba(255, 255, 255, 20%;border:none)");
    ui->loginButton->setFlat(true);

    //设置关闭按钮
    IconHelper::Instance()->setIcon(ui->loginCloseButton, QChar(0xf00d));

//    QPalette palette;
//    //palette.setColor(QPalette::Background,QColor("red"));
//    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/img/img1.png").scaled(this->size())));
//    this->setPalette(palette);
    QPixmap plx;
    plx.load(":/image/logn_account.png");
    QPixmap* imgPointer = &plx;
    imgPointer->scaled(ui->accountLabel->size(), Qt::IgnoreAspectRatio);
    ui->accountLabel->setScaledContents(true);
    ui->accountLabel->setPixmap(plx);

    ui->accountLabel->show();

    plx.load(":/image/logn_password.png");
    imgPointer->scaled(ui->passwordLabel->size(), Qt::IgnoreAspectRatio);
    ui->passwordLabel->setScaledContents(true);
    ui->passwordLabel->setPixmap(plx);
    //;border:1px solid #
    ui->passwordLineEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10%)");
    ui->passwordLabel->show();

    //背景图片
    QMovie *iconShow = new QMovie(":/image/yasuo.gif");
    ui->backgroundLabel->setMovie(iconShow);
    iconShow->start();
    this->setStyleSheet("QDialog{border-image: url(:/image/login_background1.png);}");
    //循环播放音乐（暂时关闭）
    ///playBackgroundMusic();

    //棱角圆滑
     QBitmap bmp(this->size());
     bmp.fill();
     QPainter p(&bmp);
     p.setPen(Qt::NoPen);
     p.setBrush(Qt::black);
     p.setPen(Qt::transparent);//表示RGBA值为(0,0,0,0)的透明色。
     p.setRenderHint(QPainter::Antialiasing); // 反锯齿;
     p.drawRoundedRect(bmp.rect(), 20, 20);
     setMask(bmp);

    //设置界面标题
    this->setWindowTitle("战略家麻将平台");

    //下拉框
    ui->accountComboBox->setEditable(true);//可以编辑
    ui->accountComboBox->lineEdit()->setMaxLength(10);//输入的长度
    ui->accountComboBox->setStyleSheet("background-color: rgba(255, 255, 255, 10%;border:none)");
    //使用 QStringLiteral 宏可以在编译期把代码里的常量字符串 str
    //直接构造为 QString 对象，于是运行时就不再需要额外的构造开销了。
    ui->accountComboBox->lineEdit()->setPlaceholderText(QStringLiteral("请输入用户名"));
    ui->passwordLineEdit->setPlaceholderText(QStringLiteral("请输入密码"));

    initUsernameList();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    username = ui->accountComboBox->currentText() ;
    password = ui->passwordLineEdit->text();

    QMessageBox *msgBox = new QMessageBox();
    QPixmap iconImg(":/image/login_background1.png");
    QIcon icon(iconImg);
    msgBox->setWindowIcon(icon);


    if(username.isEmpty()){
        QMessageBox::information(this, tr("请输入账号"),tr("请先输入账号再登陆，谢谢！"),
                                 QMessageBox::Ok);
        ui->accountComboBox->setFocus();
    }else if(password.isEmpty()){
        QMessageBox::information(this, tr("请输入密码"),tr("请先输入密码再登陆，谢谢！"),
                                 QMessageBox::Ok);
        ui->passwordLineEdit->setFocus();
    }else{
         if(!createConnection()){
             QMessageBox::information(this, tr("提示"),tr("请先连接网络，谢谢！"),
                                      QMessageBox::Ok);
         }else{
             QSqlDatabase db = QSqlDatabase::database("connection1");
             QSqlQuery query(db);

             QString str = QString("select * from user where account = '%0' and password = '%1'").arg(username).arg(password);
             query.exec(str);
             int record = query.size();
             //qDebug() << "record:" << record<< endl;

//             while(query.next()){
//                   qDebug() << query.value(0).toInt() <<query.value(1).toInt()
//                                      <<query.value(2).toString() <<query.value(3).toString();
//              }

             //未连接上数据库返回-1，连接上查询失败返回0，查到返回1
             if(record == -1 || record == 0){
                  QMessageBox::information(this,tr("提示"),tr("用户名或密码错误！"),QMessageBox::Ok);
                  ui->passwordLineEdit->clear();
                  ui->passwordLineEdit->setFocus();
             }else{
                 QMessageBox::information(this,tr("提示"),tr("登陆成功！"),QMessageBox::Ok);
                 //QDialog::accept();
                 if(isrembered == 1){
                     //qDebug() << " m_userNameList.push_front(username)"<<endl;
                     m_userNameList.push_back(username);
                     writeUsernameList(m_userNameList);

                 }
                 //停止音乐
                 backgroundMusic->stop();

                 //清空密码
                 ui->accountComboBox->clear();
                 ui->passwordLineEdit->clear();
                // ui->accountLineEdit->setFocus();
                 ui->accountCheckBox->setFocus();
                 emit mainwidgetShow();
                 this->close();

             }

         }
     }
}

 void LoginDialog::on_loginCloseButton_clicked()
{
    exit(0);
}

void LoginDialog::writeUsernameList(QStringList& values)
{
    QString fileName = QCoreApplication::applicationDirPath() + "/login.ini";
    IniFile iniUsername(fileName);
    iniUsername.offCoverWrite();
    iniUsername.onValueDeduplication();
    iniUsername.onInsertDeduplication();
    iniUsername.saveValue(QString("config"),QString("username"), values);
}

void LoginDialog::initUsernameList()
{
    QString fileName = QCoreApplication::applicationDirPath() + "/login.ini";
    IniFile iniUsername(fileName);
    m_userNameList = iniUsername.getValue(QString("config"),QString("username"));
    ui->accountComboBox->addItems(m_userNameList);

    if(m_userNameList.size()>0){
        username = m_userNameList.at(0);
        qDebug() <<"m_userNameList.at(0)" << m_userNameList.at(0);
    }

    if(isrembered == 1)
    {
        ui->accountCheckBox->setChecked(true);
        ui->accountComboBox->setCurrentText(username);
    }
}

void LoginDialog::playBackgroundMusic()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/music/LOL.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    backgroundMusic = new QMediaPlayer();
    backgroundMusic->setPlaylist(playlist);
    backgroundMusic->setVolume(100);
    backgroundMusic->play();
}


void LoginDialog::on_accountCheckBox_clicked()
{
    if(ui->accountCheckBox->isChecked()){
          isrembered = 1;
          qDebug() << "isrembered = true";
      }else{
          isrembered = 0;
          qDebug() << "isrembered = false";
      }
}
