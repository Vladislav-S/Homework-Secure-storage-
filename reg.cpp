#include "reg.h"
#include "database.h"
#include "ui_reg.h"

Reg::Reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reg)
{
    ui->setupUi(this);

}

Reg::~Reg()
{
    //1 - я не понимаю как ты присваиваешь db
    //2 - если подразумевается, что это указатель на объект, инициализированный в mainwindow, то выходит,
    // что ты его два раза удаляешь
    //delete db;
    delete ui;
}



void Reg::on_pushButton_clicked()
{
    db->connectDatabase();
    QString log=ui->lineEdit->text();
    QString fname=ui->lineEdit_4->text();
    QString lname=ui->lineEdit_5->text();
    QString rpas=ui->lineEdit_3->text();
    QByteArray ba=str.toUtf8();
    if ((log.size()!=0)&&(fname.size()!=0)&&(lname.size()!=0)&&(str.size()!=0)&&(rpas.size()!=0)){
    if((db->checkLogin(log))==true){
        ui->label_8->setText("This login at used");
    }
    else{
    if(str==str1){
        db->insertIntoTable(fname,lname,log,QCryptographicHash::hash(ba,QCryptographicHash::Sha256).toHex());
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        this->close();
        emit firstWindow();
    }
    else{
    ui->label_7->setText("Check password");
    }
    }
}
    else{
        if(str.size()==0)
        ui->label_7->setText("Please enter password");
        if(log.size()==0)
        ui->label_8->setText("Please enter login");
        if(rpas.size()==0)
        ui->label_9->setText("Please enter repit password");
        if(fname.size()==0)
        ui->label_10->setText("Please enter firstname");
        if(lname.size()==0)
        ui->label_11->setText("Please enter lastname");
    }
}


//многократный повтор кода, рекомендую функцию замены символов на звездочки реализовать отдельно
void Reg::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(sTextchanged){
        int itcoutn=arg1.length();
        QString arg2 = arg1;
        QString arg3 = arg1;
        if(str.size() == itcoutn+1){
            str.resize(str.size()-1);
        }
        else str += arg2.remove("*");

        arg3.replace(QRegularExpression("."), "*");
        sTextchanged = false;
        ui->lineEdit_2->setText(arg3);
    }
    sTextchanged = true;
}

void Reg::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(sTextchanged1){
        int itcoutn=arg1.length();
        QString arg2 = arg1;
        QString arg3 = arg1;
        if(str1.size() == itcoutn+1){
            str1.resize(str1.size()-1);
        }
        else str1 += arg2.remove("*");

        arg3.replace(QRegularExpression("."), "*");
        sTextchanged1 = false;
        ui->lineEdit_3->setText(arg3);
    }
    sTextchanged1 = true;
}
