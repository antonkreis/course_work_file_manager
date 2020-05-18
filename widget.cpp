#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Файловый менеджер"));
    resize(800, 600);
    QIcon emblem_ico(":/rsc/emblem.ico");
    setWindowIcon(emblem_ico);
    fileSystemModel = new QFileSystemModel(this);
    treeView = new QTreeView(this);
    fileSystemModel->setRootPath(QDir::currentPath());


    QIcon newfolder_icon(":/rsc/newfolder_ico.ico");
    folderAction = new QAction("Папка");
    folderAction->setIcon(newfolder_icon);

    sort = new QSortFilterProxyModel(this);
    sort->setSourceModel(fileSystemModel);



    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    treeView->setStyleSheet("QTreeView{ background: white; } QTreeView::branch:closed:has-children { image: url(:/rsc/black_branch_close.ico); "
                            " } QTreeView::branch:open:has-children { image: url(:/rsc/black_branch_open.ico); }");

    //treeView->setModel(fileSystemModel);
    treeView->setModel(sort);
    //fileSystemModel->setHeaderData(0, Qt::Horizontal, tr("Название"));
    contextMenu = new QMenu(this);

    fileMenu = new QMenu(tr("Файл"));
    editMenu = new QMenu(tr("Правка"));
    viewMenu = new QMenu(tr("Вид"));
    settingsMenu = new QMenu(tr("Настройки"));
    settingsMenu = new QMenu();
    helpMenu = new QMenu(tr("Справка"));

    //fileMenu->addAction(openAction);



    menuBar = new QMenuBar(this);


    QColor fontColor(255,200,0);
    QPalette menuPalette;
    menuBar->setGeometry(0,0,800,25);
    menuBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    menuPalette.setColor(QPalette::Background, fontColor);
    menuBar->setPalette(menuPalette);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    menuBar->addMenu(viewMenu);
    menuBar->addMenu(settingsMenu);
    menuBar->addMenu(helpMenu);

    gridLayout = new QGridLayout(this);
    gridLayout->setContentsMargins(5,5,5,5);
    gridLayout->addWidget(menuBar, 0, 0);
    gridLayout->addWidget(treeView, 1, 0);

    QIcon info_icon(":/rsc/info_ico.ico");

    QIcon add_icon(":/rsc/create_ico.ico");
    QIcon undo_icon(":/rsc/undo_ico.ico");
    QIcon copy_icon(":/rsc/copy_ico.ico");
    QIcon paste_icon(":/rsc/paste_ico.ico");
    QIcon cut_icon(":/rsc/cut_ico.ico");
    QIcon help_icon(":/rsc/help_ico.ico");
    QIcon theme_icon(":/rsc/theme_ico.ico");
    QIcon exit_icon(":/rsc/exit_ico.ico");
    QIcon rename_icon(":/rsc/rename_ico.ico");
    QIcon label_icon(":/rsc/label_ico.ico");
    QIcon dark_icon(":/rsc/dark_ico.ico");
    QIcon light_icon(":/rsc/light_ico.ico");
    QIcon sort_icon(":/rsc/sort_ico.ico");
    QIcon delete_icon(":/rsc/delete_ico.ico");
    QIcon open_icon(":/rsc/open_ico.ico");
    QIcon doc_icon(":/rsc/doc_ico.ico");
    QIcon properties_icon(":/rsc/properties_ico.ico");

    translateMenu = new QMenu(QApplication::translate("Widget","Язык",0));
    belarussianAction = new QAction("Беларуская");
    russianAction = new QAction("Русский");
    englishAction = new QAction("English");
    germanAction = new QAction("German");

    openAction = new QAction("Открыть");
    openAction->setIcon(open_icon);

    propertiesAction = new QAction("Свойства");
    propertiesAction->setIcon(properties_icon);


    createMenu = new QMenu("Создать");
    createMenu->setIcon(add_icon);


    undoAction = new QAction("Отменить");
    undoAction->setIcon(undo_icon);
    QKeySequence undoShortcut(Qt::CTRL+Qt::Key_Z);
    undoAction->setShortcut(undoShortcut);

    copyAction = new QAction("Копировать");
    copyAction->setIcon(copy_icon);
    QKeySequence copyShortcut(Qt::CTRL+Qt::Key_C);
    copyAction->setShortcut(copyShortcut);

    pasteAction = new QAction("Вставить");
    pasteAction->setIcon(paste_icon);
    QKeySequence pasteShortcut(Qt::CTRL+Qt::Key_V);
    pasteAction->setShortcut(pasteShortcut);

    cutAction = new QAction("Вырезать");
    cutAction->setIcon(cut_icon);
    QKeySequence cutShortcut(Qt::CTRL+Qt::Key_X);
    cutAction->setShortcut(cutShortcut);

    renameAction = new QAction("Переименовать");
    renameAction->setIcon(rename_icon);
    QKeySequence renameShortcut(Qt::Key_F2);
    renameAction->setShortcut(renameShortcut);

    deleteAction = new QAction("Удалить");
    deleteAction->setIcon(delete_icon);
    QKeySequence deleteShortcut(Qt::Key_Delete);
    deleteAction->setShortcut(deleteShortcut);

    colorMenu = new QMenu("Цвет");
    colorMenu->setIcon(theme_icon);

    aboutAction = new QAction("О программе");
    QKeySequence aboutShortcut(Qt::CTRL+Qt::Key_I);
    aboutAction->setIcon(info_icon);
    aboutAction->setShortcut(aboutShortcut);

    sortAction = new QAction("Сортировать");
    sortAction->setIcon(sort_icon);

    exitAction = new QAction("Выйти");
    exitAction->setIcon(exit_icon);

    helpAction = new QAction("Справка");
    helpAction->setIcon(help_icon);
    QKeySequence helpShortcut(Qt::Key_F1);
    helpAction->setShortcut(helpShortcut);

    fileMenu->addAction(openAction);
    fileMenu->addAction(propertiesAction);
    fileMenu->addAction(folderAction);
    //fileMenu->addMenu(createMenu);
    fileMenu->addAction(exitAction);
    settingsMenu->addMenu(colorMenu);
    settingsMenu->addMenu(translateMenu);
    helpMenu->addAction(aboutAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);
    editMenu->addAction(renameAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    viewMenu->addAction(sortAction);
    helpMenu->addAction(helpAction);
    editMenu->addAction(undoAction);

    translateMenu->addAction(belarussianAction);
    translateMenu->addAction(russianAction);
    translateMenu->addAction(englishAction);
    translateMenu->addAction(germanAction);


    docAction = new QAction("Документ");
    docAction->setIcon(doc_icon);
    labelAction = new QAction("Ярлык");
    labelAction->setIcon(label_icon);
    createMenu->addAction(folderAction);
    createMenu->addAction(docAction);
    createMenu->addAction(labelAction);

    greyColorAction = new QAction(tr("Темный"));
    greyColorAction->setIcon(dark_icon);
    lightColorAction = new QAction(tr("Светлый"));
    lightColorAction->setIcon(light_icon);
    colorMenu->addAction(greyColorAction);
    colorMenu->addAction(lightColorAction);

    treeView->setColumnWidth(0, 440);

    connect(belarussianAction, SIGNAL(triggered()), SLOT(on_belarussianAction_clicked()));
    connect(russianAction, SIGNAL(triggered()), SLOT(on_russianAction_clicked()));
    connect(englishAction, SIGNAL(triggered()), SLOT(on_englishAction_clicked()));
    connect(germanAction, SIGNAL(triggered()), SLOT(on_germanAction_clicked()));
    connect(treeView, SIGNAL(doubleClicked(QModelIndex)), SLOT(on_openAction_clicked(QModelIndex)));
    connect(openAction, SIGNAL(triggered()), SLOT(on_openAction_clicked()));
    connect(propertiesAction, SIGNAL(triggered()), SLOT(on_propertiesAction_clicked()));
    connect(treeView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(contextMenu_called(QPoint)));
    connect(aboutAction, SIGNAL(triggered()), SLOT(on_aboutAction_clicked()));
    connect(exitAction, SIGNAL(triggered()), SLOT(on_exitAction_clicked()));
    connect(greyColorAction, SIGNAL(triggered()), SLOT(on_greyColorAction_clicked()));
    connect(lightColorAction, SIGNAL(triggered()), SLOT(on_lightColorAction_clicked()));
    connect(renameAction, SIGNAL(triggered()), SLOT(on_renameAction_clicked()));
    connect(folderAction, SIGNAL(triggered()), SLOT(on_folderAction_clicked()));
    connect(deleteAction, SIGNAL(triggered()), SLOT(on_deleteAction_clicked()));
    connect(renameAction, SIGNAL(triggered()), SLOT(on_renameAction_clicked()));
    connect(cutAction, SIGNAL(triggered()), SLOT(on_cutAction_clicked()));
    connect(copyAction, SIGNAL(triggered()), SLOT(on_copyAction_clicked()));
    connect(pasteAction, SIGNAL(triggered()), SLOT(on_pasteAction_clicked()));
    //connect(sortAction, SIGNAL(triggered()), SLOT(on_sortAction_clicked(int)));
    //connect(treeView->header(), SIGNAL(sectionClicked(int)), this, SLOT(on_sortAction_clicked(int)));

    setNameWindow = new SetNameWindow(this);
    retranslation();
    cutFlag = 0;
     treeView->setSortingEnabled(true);
}

void Widget::on_sortAction_clicked(int){
    treeView->setSortingEnabled(true);

    treeView->sortByColumn(0, Qt::AscendingOrder);
}

void Widget::on_pasteAction_clicked(){
    if(moveName.size() != 0){
        QFile file(fileSystemModel->filePath(treeView->currentIndex()));
        QFile::copy(movePath, fileSystemModel->filePath(treeView->currentIndex())+ '/' + moveName);
        if(cutFlag){
            fileSystemModel->remove(oldFile);
        }
        moveName.clear();
        movePath.clear();
    }
}

void Widget::on_cutAction_clicked(){
    QFile file(fileSystemModel->filePath(treeView->currentIndex()));
    moveName = fileSystemModel->fileName(treeView->currentIndex());
    movePath = fileSystemModel->filePath(treeView->currentIndex());
    cutFlag = 1;
}

void Widget::on_copyAction_clicked(){
    QFile file(fileSystemModel->filePath(treeView->currentIndex()));
    moveName = fileSystemModel->fileName(treeView->currentIndex());
    movePath = fileSystemModel->filePath(treeView->currentIndex());
    cutFlag = 0;
    oldFile = treeView->currentIndex();
}

void Widget::retranslation(){
    settingsMenu->setTitle(tr("Настройки"));
//    fileMenu->setTitle(tr("Файл"));
//    editMenu->setTitle(tr("Правка"));
//    viewMenu->setTitle(tr("Вид"));
//    helpMenu->setTitle(tr("Справка"));

}

void Widget::on_belarussianAction_clicked(){
   QTranslator translator;
   translator.load("main_by", ".");
   qApp->installTranslator(&translator);
   retranslation();
}

void Widget::on_russianAction_clicked(){
    QTranslator translator;
    translator.load("main_ru", ".");
    qApp->installTranslator(&translator);
    retranslation();
}

void Widget::on_englishAction_clicked(){
    QTranslator translator;
    translator.load("main_en", ".");
    qApp->installTranslator(&translator);
    retranslation();
}

void Widget::on_germanAction_clicked(){
    QTranslator translator;
    translator.load("main_de", ".");
    qApp->installTranslator(&translator);
    retranslation();
}

void Widget::on_propertiesAction_clicked(){

    QMessageBox* propertiesMessage = new QMessageBox(this);
    QFileInfo* fileInfo = new QFileInfo(fileSystemModel->fileInfo(treeView->currentIndex()));
    propertiesMessage->setModal(true);
    QPixmap info_ico(":/rsc/info_ico.ico");
    propertiesMessage->setIconPixmap(info_ico);
    if(fileSystemModel->isDir(treeView->currentIndex())){
         propertiesMessage->setText("Имя: " + fileInfo->fileName() + "\nПуть: " + fileInfo->filePath() + "\nРазмер: -" + "\nДата создания: " + fileInfo->lastRead().toString());
    }
    else{
        propertiesMessage->setText("Имя: " + fileInfo->fileName() + "\nПуть: " + fileInfo->filePath() + "\nРазмер: " + QString::number(fileInfo->size()) + "\nДата создания: " + fileInfo->lastRead().toString());
    }

    propertiesMessage->setWindowTitle(tr("Свойства"));
    propertiesMessage->addButton(tr("Ок"), QMessageBox::ActionRole);
    propertiesMessage->exec();
    delete fileInfo;
    delete propertiesMessage;
}

void Widget::contextMenu_called(QPoint point){
    contextMenu->addAction(openAction);
    contextMenu->addAction(renameAction);
    contextMenu->addAction(copyAction);
    contextMenu->addAction(cutAction);
    contextMenu->addAction(pasteAction);
    contextMenu->addAction(folderAction);
    contextMenu->addAction(propertiesAction);
    contextMenu->popup(treeView->viewport()->mapToGlobal(point));
}


void Widget::on_openAction_clicked(QModelIndex index){
    if(!fileSystemModel->isDir(sort->mapToSource(index))){
        QDesktopServices desktop;
        desktop.openUrl(QUrl::fromLocalFile(fileSystemModel->filePath(sort->mapToSource(index))));
    }
}

void Widget::on_openAction_clicked(){
    if(!fileSystemModel->isDir(treeView->currentIndex())){
        QDesktopServices desktop;
        desktop.openUrl(QUrl::fromLocalFile(fileSystemModel->filePath(treeView->currentIndex())));
    }
}

void Widget::on_renameAction_clicked(){
    newNamePurpose = RENAME;
    setNameWindow->show();
}

void Widget::on_folderAction_clicked(){
    newNamePurpose = NEW_FOLDER;
    setNameWindow->show();
}

void Widget::recieveName(QString name)
{
    if(newNamePurpose == NEW_FOLDER){
        fileSystemModel->mkdir(treeView->currentIndex(), name);
    }
    if(newNamePurpose == RENAME){
        QFile file(fileSystemModel->filePath(treeView->currentIndex()));
        QString oldName = fileSystemModel->filePath(treeView->currentIndex());
        while(oldName.back() != '/') oldName.resize(oldName.size()-1);
        file.rename(oldName + name);
    }
    setNameWindow->close();

}

void Widget::on_deleteAction_clicked()
{
    QMessageBox* deleteMessage = new QMessageBox(this);
    deleteMessage->setModal(true);
    QPixmap info_ico(":/rsc/info_ico.ico");
    deleteMessage->setIconPixmap(info_ico);
    deleteMessage->setText("Вы уверены?");
    deleteMessage->setWindowTitle(tr("Удаление"));
    QPushButton* acceptButton = deleteMessage->addButton(tr("Да"), QMessageBox::ActionRole);
    deleteMessage->addButton(tr("Нет"), QMessageBox::ActionRole);
    deleteMessage->exec();
    if(deleteMessage->clickedButton() == acceptButton){
        fileSystemModel->remove(treeView->currentIndex());
    }
    delete deleteMessage;
}

void Widget::on_aboutAction_clicked(){
    QMessageBox* aboutMessage = new QMessageBox(this);
    aboutMessage->setModal(true);
    QPixmap info_ico(":/rsc/info_ico.ico");
    aboutMessage->setIconPixmap(info_ico);
    aboutMessage->setText("Курсовой проект.\nСоздан Антоном Крейсом.\nBSUIR, 2020");
    aboutMessage->setWindowTitle(tr("О программе"));
    aboutMessage->addButton(tr("Закрыть"), QMessageBox::AcceptRole);
    aboutMessage->exec();
    delete aboutMessage;
}

void Widget::on_exitAction_clicked(){
    close();
}

void Widget::on_greyColorAction_clicked(){
    QColor fontColor(0,0,100);
    QPalette menuPalette;
    menuBar->setStyleSheet("color: rgb(255, 255, 255)");
    QColor backgroudColor(55, 55, 55);
    QPalette palette;
    palette.setColor(this->backgroundRole(), backgroudColor);
    //setStyleSheet("color: rgb(80, 0, 52)");
    setPalette(palette);
    menuPalette.setColor(QPalette::Background, fontColor);
    menuBar->setPalette(menuPalette);
    treeView->setStyleSheet("QTreeView{ background: grey; color: white; } QTreeView::branch:closed:has-children { image: url(:/rsc/white_branch_close.ico); "
                            " } QTreeView::branch:open:has-children { image: url(:/rsc/white_branch_open.ico); }");
}

void Widget::on_lightColorAction_clicked(){
    QColor fontColor(255,200,0);
    QPalette menuPalette;

    menuBar->setStyleSheet("color: rgb(0, 0, 0)");
    QColor backgroudColor(255, 255, 255);
    QPalette palette;
    palette.setColor(this->backgroundRole(), backgroudColor);
    setPalette(palette);
    menuPalette.setColor(QPalette::Background, fontColor);
    menuBar->setPalette(menuPalette);
    treeView->setStyleSheet("QTreeView{ background: white; text: black; } QTreeView::branch:closed:has-children { image: url(:/rsc/black_branch_close.ico); "
                            " } QTreeView::branch:open:has-children { image: url(:/rsc/black_branch_open.ico); }");
}

Widget::~Widget()
{
    delete menuBar;
    delete gridLayout;

    delete contextMenu;

    delete fileMenu;
    delete editMenu;

    delete viewMenu;
    delete settingsMenu;
    delete helpMenu;
    delete openAction;
    delete propertiesAction;

    delete createMenu;
    delete undoAction;
    delete copyAction;
    delete pasteAction;
    delete cutAction;

    delete renameAction;
    delete deleteAction;
    delete colorMenu;
    delete aboutAction;
    delete sortAction;

    delete exitAction;
    delete helpAction;
    delete folderAction;
    delete docAction;
    delete labelAction;
    delete greyColorAction;
    delete lightColorAction;

    delete setNameWindow;

    delete fileSystemModel;
    delete treeView;

    delete translateMenu;
    delete belarussianAction;
    delete russianAction;
    delete englishAction;
    delete germanAction;

    delete sort;
}

