#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb18030"));
    QWidget *pWidget = new QWidget;
    QLabel label(pWidget);
    label.setText(QObject::tr("同一个世界，同一个梦想!"));
    pWidget->show();

    return a.exec();
}
