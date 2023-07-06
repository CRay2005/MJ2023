#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "mainwidget.h"
#include "inifile.h"
#include <QMediaPlayer>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    friend class UIMainWindows;
public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots://按钮
    void on_loginButton_clicked();//登陆按钮
    void on_loginCloseButton_clicked();//关闭界面按钮

    void on_accountCheckBox_clicked();

private:
    Ui::LoginDialog *ui;

    //背景音乐
    QMediaPlayer *backgroundMusic;
    //记住的用户名
    QStringList m_userNameList;//记录的账号
    int isrembered;//是否记住账户
    QString username;
    QString password;

private:
    void writeUsernameList(QStringList&);

signals:
    void mainwidgetShow();//显示主窗口
    void tcpHeartBeat();//心跳信号
public slots:
    void initUsernameList();//加载账号
    void playBackgroundMusic();//播放背景音乐

};

#endif // LOGINDIALOG_H
