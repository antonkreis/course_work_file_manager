#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("main_en", ".");
    a.installTranslator(&translator);
    Widget w;
    w.show();
    return a.exec();
}
