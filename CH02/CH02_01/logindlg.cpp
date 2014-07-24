#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include "logindlg.h"

CLoginDlg::CLoginDlg(QWidget *parent) :
    QDialog(parent)
{
    QLabel *usrLabel = new QLabel(tr("用户名:"));
    QLabel *pwdLabel = new QLabel(tr("密  码:"));

    usrLineEdit = new QLineEdit;
    pwdLineEdit = new QLineEdit;
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(usrLabel, 0, 0, 1, 1);
    gridLayout->addWidget(usrLineEdit, 0, 1, 1, 3);
    gridLayout->addWidget(pwdLabel, 1, 0, 1, 1);
    gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 3);

    QPushButton *okBtn = new QPushButton(tr("确定"));
    QPushButton *cancelBtn = new QPushButton(tr("取消"));
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->setSpacing(60);
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);

    QVBoxLayout *dlgLayout = new QVBoxLayout;
    dlgLayout->setMargin(40);
    dlgLayout->addLayout(gridLayout);
    dlgLayout->addStretch(40);
    dlgLayout->addLayout(btnLayout);
    this->setLayout(dlgLayout);

    this->connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    this->connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));

    this->setWindowTitle(tr("登录"));
    this->resize(300, 200);
}

void CLoginDlg::accept()
{
    if (usrLineEdit->text().trimmed() == tr("1cf") &&
        pwdLineEdit->text().trimmed() == tr("1cf")) {
        QDialog::accept();
    }
    else {
        QMessageBox::warning(this,
                             tr("警告"),
                             tr("用户或密码错误!"),
                             QMessageBox::Yes);
        usrLineEdit->setFocus();
    }
}
