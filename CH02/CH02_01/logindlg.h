#ifndef __LOGINDLG_H__
#define __LOGINDLG_H__

#include <QDialog>

class QLineEdit;

class CLoginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit CLoginDlg(QWidget *parent = 0);

signals:

public slots:
    virtual void accept();

private:
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
};

#endif // __LOGINDLG_H__
