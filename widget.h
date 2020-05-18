#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTableWidget>
#include <QMessageBox>
#include <QTreeView>
#include <QFileSystemModel>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QTranslator>
#include <QHeaderView>
#include <QApplication>
#include <QSortFilterProxyModel>

#include <QModelIndex>

#include "setnamewindow.h"

class Widget : public QWidget
{
    Q_OBJECT

    enum NewNamePurpose{
        RENAME,
        NEW_FOLDER
    } newNamePurpose;

    SetNameWindow* setNameWindow;

    QPushButton* newFolderButton;
    QPushButton* backButton;
    QGridLayout* gridLayout;
    QHBoxLayout* horizontalLayout;
    QMenuBar* menuBar;

    QLineEdit* path;
    QTableView* list;

    QMenu* contextMenu;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* settingsMenu;
    QMenu* helpMenu;
    QMenu* viewMenu;

    QAction* openAction;
    QAction* propertiesAction;
    QMenu* createMenu;

    QMenu* translateMenu;
    QAction* belarussianAction;
    QAction* russianAction;
    QAction* englishAction;
    QAction* germanAction;

    QAction* undoAction;
    QAction* copyAction;
    QAction* pasteAction;
    QAction* cutAction;
    QAction* renameAction;

    QAction* deleteAction;
    QMenu* colorMenu;
    QAction* aboutAction;
    QAction* sortAction;
    QAction* exitAction;

    QAction* helpAction;

    QAction* folderAction;
    QAction* docAction;
    QAction* labelAction;
    QAction* greyColorAction;
    QAction* lightColorAction;
    //QTranslator* translator;
    QFileSystemModel* fileSystemModel;
    QTreeView* treeView;

    QSortFilterProxyModel* sort;

    QString moveName;
    QString movePath;
    QModelIndex oldFile;
    bool cutFlag;

public:
    Widget(QWidget *parent = nullptr);
    void retranslation();

    ~Widget();
public slots:
   // void changeEvent(QEvent *event);
    // changeEvent(QEvent *);
    //void on_translateAction_clicked();
    void on_belarussianAction_clicked();
    void on_russianAction_clicked();
    void on_englishAction_clicked();
    void on_germanAction_clicked();
    void on_openAction_clicked();
    void on_openAction_clicked(QModelIndex);
    void on_propertiesAction_clicked();
    void contextMenu_called(QPoint point);
    void on_aboutAction_clicked();
    void on_exitAction_clicked();
    void on_greyColorAction_clicked();
    void on_lightColorAction_clicked();
    void on_renameAction_clicked();
    void recieveName(QString name);
    void on_cutAction_clicked();
    void on_pasteAction_clicked();
    void on_copyAction_clicked();
    void on_folderAction_clicked();
    void on_deleteAction_clicked();
    void on_sortAction_clicked(int);
};
#endif // WIDGET_H
