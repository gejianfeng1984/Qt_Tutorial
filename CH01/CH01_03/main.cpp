#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextCodec>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb18030"));

    QWidget *pWidget = new QWidget;
    QLabel label(pWidget);
    label.setText(QObject::tr("同一个世界，同一个梦想!"));

    QPushButton *btn = new QPushButton(QObject::tr("关闭"), pWidget);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(&label);
    layout->addWidget(btn);
    pWidget->setLayout(layout);

    QObject::connect(btn, SIGNAL(clicked()), pWidget, SLOT(close()));

    pWidget->show();

    return a.exec();
}
