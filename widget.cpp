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

    translator = new QTranslator(this);
    QIcon newfolder_icon(":/rsc/newfolder_ico.ico");
    folderAction = new QAction("Папка");
    folderAction->setIcon(newfolder_icon);

    sort = new QSortFilterProxyModel(this);
    sort->setSourceModel(fileSystemModel);
    //sort->setHeaderData(0, Qt::Horizontal, "aa");



    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    treeView->setStyleSheet("QTreeView{ background: white; } QTreeView::branch:closed:has-children { image: url(:/rsc/black_branch_close.ico); "
                            " } QTreeView::branch:open:has-children { image: url(:/rsc/black_branch_open.ico); }");

    //treeView->setModel(fileSystemModel);
    treeView->setModel(sort);
    contextMenu = new QMenu(this);

    fileMenu = new QMenu(tr("Файл"));
    editMenu = new QMenu(tr("Правка"));
    viewMenu = new QMenu(tr("Вид"));
    settingsMenu = new QMenu(tr("Настройки"));
    settingsMenu = new QMenu();
    helpMenu = new QMenu(tr("Справка"));
    menuBar = new QMenuBar(this);


    QColor fontColor(255,200,0);
    QPalette menuPalette;
    menuBar->setGeometry(0,0,800,25);
    menuBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    menuPalette.setColor(QPalette::Background, fontColor);
    menuBar->setPalette(menuPalette);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    //menuBar->addMenu(viewMenu);
    menuBar->addMenu(settingsMenu);
    menuBar->addMenu(helpMenu);

    gridLayout = new QGridLayout(this);
    gridLayout->setContentsMargins(5,5,5,5);
    gridLayout->addWidget(menuBar, 0, 0);
    gridLayout->addWidget(treeView, 1, 0);

    QIcon info_icon(":/rsc/info_ico.ico");

    QIcon add_icon(":/rsc/create_ico.ico");
    //QIcon undo_icon(":/rsc/undo_ico.ico");
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

    translateMenu = new QMenu(tr("Язык"));
    belarussianAction = new QAction("Беларуская");
    russianAction = new QAction("Русский");
    englishAction = new QAction("English");
    germanAction = new QAction("German");

    openAction = new QAction(tr("Открыть"));
    openAction->setIcon(open_icon);

    propertiesAction = new QAction(tr("Свойства"));
    propertiesAction->setIcon(properties_icon);


    createMenu = new QMenu(tr("Создать"));
    createMenu->setIcon(add_icon);


    undoAction = new QAction("Отменить");
   // undoAction->setIcon(undo_icon);
    QKeySequence undoShortcut(Qt::CTRL+Qt::Key_Z);
    undoAction->setShortcut(undoShortcut);

    copyAction = new QAction("Копировать");
    copyAction->setIcon(copy_icon);
    QKeySequence copyShortcut(Qt::CTRL+Qt::Key_C);
    copyAction->setShortcut(copyShortcut);

    pasteAction = new QAction(tr("Вставить"));
    pasteAction->setIcon(paste_icon);
    QKeySequence pasteShortcut(Qt::CTRL+Qt::Key_V);
    pasteAction->setShortcut(pasteShortcut);

    cutAction = new QAction(tr("Вырезать"));
    cutAction->setIcon(cut_icon);
    QKeySequence cutShortcut(Qt::CTRL+Qt::Key_X);
    cutAction->setShortcut(cutShortcut);

    renameAction = new QAction(tr("Переименовать"));
    renameAction->setIcon(rename_icon);
    QKeySequence renameShortcut(Qt::Key_F2);
    renameAction->setShortcut(renameShortcut);

    deleteAction = new QAction(tr("Удалить"));
    deleteAction->setIcon(delete_icon);
    QKeySequence deleteShortcut(Qt::Key_Delete);
    deleteAction->setShortcut(deleteShortcut);

    colorMenu = new QMenu(tr("Цвет"));
    colorMenu->setIcon(theme_icon);

    aboutAction = new QAction(tr("О программе"));
    QKeySequence aboutShortcut(Qt::CTRL+Qt::Key_I);
    aboutAction->setIcon(info_icon);
    aboutAction->setShortcut(aboutShortcut);

    sortAction = new QAction("Сортировать");
    sortAction->setIcon(sort_icon);

    exitAction = new QAction(tr("Выйти"));
    exitAction->setIcon(exit_icon);

    helpAction = new QAction(tr("Справка"));
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
    //helpMenu->addAction(helpAction);
    //editMenu->addAction(undoAction);

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
    translator->load("main_ru", ".");
    qApp->installTranslator(translator);
    setNameWindow = new SetNameWindow(this);
    retranslation();
    cutFlag = 0;
    treeView->setSortingEnabled(true);
    process = new QProcess(this);
}

void Widget::on_sortAction_clicked(int){
    treeView->setSortingEnabled(true);
    treeView->sortByColumn(0, Qt::AscendingOrder);
}

void Widget::on_pasteAction_clicked(){
    DIR* moveDir = opendir(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())).toStdString().c_str());
    dirent* dirContent;
    while((dirContent = readdir(moveDir)) != NULL){
        if(QString(dirContent->d_name) == moveName){
            QMessageBox* alreadyExistMessage = new QMessageBox(this);
            alreadyExistMessage->setModal(true);
            QPixmap info_ico(":/rsc/info_ico.ico");
            alreadyExistMessage->setIconPixmap(info_ico);
            alreadyExistMessage->setText("Файл/папка с таким названием уже существует.");
            alreadyExistMessage->setWindowTitle(tr("Ошибка"));
            alreadyExistMessage->addButton(tr("Ок"), QMessageBox::ActionRole);
            alreadyExistMessage->exec();
            delete alreadyExistMessage;
            return;
        }
    }
    if(!isDir){
        if(moveName.size() != 0){
            QFile file(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())));
            QFile::copy(movePath, fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()))+ '/' + moveName);
        }
    }
    else{
        QDir dir(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()))+ moveName);
        //QFileInfo info;
        QString newBaseFolderPath = fileSystemModel->filePath(fileSystemModel->mkdir(sort->mapToSource(treeView->currentIndex()), moveName));
        QString relativePath;
        QString oldPath;
        QString movePathLocal = movePath;
        for(int i =0; i < moveName.size(); i++){
            movePathLocal.resize(movePathLocal.size() - 1);
        }
        int pathLength = movePathLocal.size();
        foreach (QString path, innerFolders) {
            if(path.back()!='.'){

                if(QFileInfo(path).isFile()){
                    oldPath = path;
                    relativePath = path.remove(0, pathLength + moveName.size());
                    QString newPath = dir.currentPath();
                    QFile::copy(oldPath,newBaseFolderPath + relativePath);
                }
                else{
                    path.remove(0, pathLength);
                    fileSystemModel->mkdir(sort->mapToSource(treeView->currentIndex()), path);
                }
            }
        }
    }
    if(cutFlag){
        fileSystemModel->remove(oldFile);
    }
    //moveName.clear();
    //movePath.clear();
}

void Widget::on_cutAction_clicked(){
    if(!fileSystemModel->isDir(sort->mapToSource(treeView->currentIndex()))){
        QFile file(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())));
        moveName = fileSystemModel->fileName(sort->mapToSource(treeView->currentIndex()));
        movePath = fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()));
        cutFlag = 1;
        isDir = 0;
    }
    else{
        cutFlag = 1;
        isDir = 1;
        movePath = fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()));
        moveName = fileSystemModel->fileName(sort->mapToSource(treeView->currentIndex()));
        QDirIterator iterator("/" + moveName, QDirIterator::Subdirectories);
        innerFolders.clear();
        while(iterator.hasNext()){
            innerFolders << iterator.next();
        }
    }
    oldFile = sort->mapToSource(treeView->currentIndex());
}

void Widget::on_copyAction_clicked(){
    if(!fileSystemModel->isDir(sort->mapToSource(treeView->currentIndex()))){
        QFile file(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())));
        moveName = fileSystemModel->fileName(sort->mapToSource(treeView->currentIndex()));
        movePath = fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()));
        cutFlag = 0;
        isDir = 0;
    }
    else{
        cutFlag = 0;
        isDir = 1;
        movePath = fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()));
        moveName = fileSystemModel->fileName(sort->mapToSource(treeView->currentIndex()));
        QDirIterator iterator(movePath, QDirIterator::Subdirectories);
        innerFolders.clear();
        while(iterator.hasNext()){
            innerFolders << iterator.next();
        }
    }
    oldFile = sort->mapToSource(treeView->currentIndex());
}

void Widget::retranslation(){
    settingsMenu->setTitle(tr("Настройки"));
    fileMenu->setTitle(tr("Файл"));
    editMenu->setTitle(tr("Правка"));
    //viewMenu->setTitle(tr("Вид"));
    helpMenu->setTitle(tr("Справка"));
    openAction->setText(tr("Открыть"));
    propertiesAction->setText(tr("Свойства"));
    folderAction->setText(tr("Папка"));
    exitAction->setText(tr("Выход"));
    renameAction->setText(tr("Переименовать"));
    cutAction->setText(tr("Вырезать"));
    copyAction->setText(tr("Копировать"));
    pasteAction->setText(tr("Вставить"));
    deleteAction->setText(tr("Удалить"));
    translateMenu->setTitle(tr("Язык"));
    colorMenu->setTitle(tr("Тема"));
    aboutAction->setText(tr("О программе"));
}

void Widget::on_belarussianAction_clicked(){
   translator->load("main_by", ".");
   qApp->installTranslator(translator);
   retranslation();
}

void Widget::on_russianAction_clicked(){
    //QTranslator translator1;
    translator->load("main_ru", ".");
    qApp->installTranslator(translator);
   // translator1.load("qt_fa", ".");
   // qApp->installTranslator(&translator1);
    retranslation();
}

void Widget::on_englishAction_clicked(){
    translator->load("main_en", ".");
    qApp->installTranslator(translator);
    retranslation();
}

void Widget::on_germanAction_clicked(){
    translator->load("main_de", ".");
    qApp->installTranslator(translator);
    retranslation();
}

void Widget::on_propertiesAction_clicked(){

    QMessageBox* propertiesMessage = new QMessageBox(this);
    QFileInfo* fileInfo = new QFileInfo(fileSystemModel->fileInfo(sort->mapToSource(treeView->currentIndex())));
    propertiesMessage->setModal(true);
    QPixmap info_ico(":/rsc/info_ico.ico");
    propertiesMessage->setIconPixmap(info_ico);
    struct stat info;
    stat(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())).toStdString().c_str(), &info);
    QString fileType, fileSize = "-";
    switch (info.st_mode & S_IFMT) {
    case S_IFSOCK: fileType = "Сокет"; break;
    case S_IFLNK: fileType = "Символическая ссылка"; fileSize = QString::number(info.st_size); break;
    case S_IFREG: fileType = "Обычный файл"; fileSize = QString::number(info.st_size); break;
    case S_IFBLK: fileType = "Блочное устройство"; break;
    case S_IFDIR: fileType = "Директория"; break;
    case S_IFCHR: fileType = "Символьное устройство"; break;
    case S_IFIFO: fileType = "Канал"; break;
    }
    propertiesMessage->setText("Имя: " + fileInfo->fileName()+ "\nТип: " + fileType + "\nРазмер: " + fileSize + " байт\nID владельца: " +
                           QString::number(info.st_uid) + "\nID группы владельца: " + QString::number(info.st_gid) +
                           "\nДата изменения: " + QString(asctime(localtime(&info.st_mtim.tv_sec))));
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
    contextMenu->addAction(deleteAction);
    contextMenu->popup(treeView->viewport()->mapToGlobal(point));
}


void Widget::on_openAction_clicked(QModelIndex index){
    if(!fileSystemModel->isDir(sort->mapToSource(index))){
        if(!access(fileSystemModel->filePath(sort->mapToSource(index)).toStdString().c_str(), X_OK)){
            QStringList args;
            args << "";
            process->start(fileSystemModel->filePath(sort->mapToSource(index)), args);
        }
        else{
            QDesktopServices desktop;
            desktop.openUrl(QUrl::fromLocalFile(fileSystemModel->filePath(sort->mapToSource(index))));
        }
    }
}

void Widget::on_openAction_clicked(){
    if(!fileSystemModel->isDir(sort->mapToSource(treeView->currentIndex()))){
        if(!access(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())).toStdString().c_str(), X_OK)){
            QStringList args;
            args << "";
            process->start(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())), args);
        }
        else{
            QDesktopServices desktop;
            desktop.openUrl(QUrl::fromLocalFile(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()))));
        }
    }
}

void Widget::on_renameAction_clicked(){
    newNamePurpose = RENAME;
    setNameWindow->show();
}

void Widget::on_folderAction_clicked(){
    newNamePurpose = NEW_FOLDER;
    QProcess *p = new QProcess(this);
    QStringList args;
    args << "/home/anton/Рабочий стол/gcc.txt";
    p->start(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())), args);
    setNameWindow->show();
}

void Widget::recieveName(QString name){
    if(newNamePurpose == NEW_FOLDER){
        fileSystemModel->mkdir(sort->mapToSource(treeView->currentIndex()), name);
    }
    if(newNamePurpose == RENAME){
        QFile file(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())));
        QString oldName = fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()));
        while(oldName.back() != '/') oldName.resize(oldName.size()-1);
        file.rename(oldName + name);
    }
    setNameWindow->close();
}

//void Widget::on_deleteAction_clicked()
//{
//    QMessageBox* deleteMessage = new QMessageBox(this);
//    deleteMessage->setModal(true);
//    QPixmap info_ico(":/rsc/info_ico.ico");
//    deleteMessage->setIconPixmap(info_ico);
//    deleteMessage->setText("Вы уверены?");
//    deleteMessage->setWindowTitle(tr("Удаление"));
//    QPushButton* acceptButton = deleteMessage->addButton(tr("Да"), QMessageBox::ActionRole);
//    deleteMessage->addButton(tr("Нет"), QMessageBox::ActionRole);
//    deleteMessage->exec();
//    if(deleteMessage->clickedButton() == acceptButton){
//        fileSystemModel->remove(sort->mapToSource(treeView->currentIndex()));
//    }
//    delete deleteMessage;
//}



void Widget::on_deleteAction_clicked(){
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
         struct stat info;
         stat(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())).toStdString().c_str(), &info);
         if((info.st_mode & S_IFMT) != S_IFDIR){
             unlink(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())).toStdString().c_str());
         }
         else{
             DIR* deletedDir;
             deletedDir = opendir(fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex())).toStdString().c_str());
             if(deletedDir == NULL){
                 QMessageBox* errorMessage = new QMessageBox(this);
                 errorMessage->setModal(true);
                 QPixmap info_ico(":/rsc/info_ico.ico");
                 errorMessage->setIconPixmap(info_ico);
                 errorMessage->setText("Невозможно удалить папку");
                 errorMessage->setWindowTitle(tr("Ошибка"));
                 errorMessage->addButton(tr("Ок"), QMessageBox::ActionRole);
                 errorMessage->exec();
             }
             QString basePath = fileSystemModel->filePath(sort->mapToSource(treeView->currentIndex()));
             QString relativePath = "";
             //del(basePath);
             QStringList basePathList;
             basePathList << basePath;
             do{
                 del(basePathList.back(), 0);
                 if(newBasePath != ""){
                     basePathList << newBasePath;
                 }
                 else{
                     basePathList.pop_back();
                 }
             }while(basePathList.size());
         }

    }
    delete deleteMessage;
}

//void Widget::del(QString path){
//    DIR* deletedDir;
//    dirent* dirContent;
//    //int amountOfChilds = 0;
//    deletedDir = opendir(path.toStdString().c_str());
//    while((dirContent = readdir(deletedDir)) != NULL){
//        if(QString(dirContent->d_name) != "." && QString(dirContent->d_name) != ".."){
//            //amountOfChilds++;
//            if(dirContent->d_type == DT_DIR){
//                //rmdir(QString(path+"/"+QString(dirContent->d_name)).toStdString().c_str());
//                del(path + "/" + QString(dirContent->d_name));
//            }
//            else{
//                //amountOfChilds--;
//                unlink(QString(path+"/"+QString(dirContent->d_name)).toStdString().c_str());

//            }
//        }
//    rmdir(path.toStdString().c_str());
//    }
//}


void Widget::del(QString path, int depth){
    newBasePath = "";
    if(depth == 5){
        newBasePath = path;
        return;
    }
    DIR* deletedDir;
    dirent* dirContent;
    deletedDir = opendir(path.toStdString().c_str());
    while((dirContent = readdir(deletedDir)) != NULL){
        if(QString(dirContent->d_name) != "." && QString(dirContent->d_name) != ".."){
            if(dirContent->d_type == DT_DIR){
                del(path + "/" + QString(dirContent->d_name), depth+1);
                if(newBasePath != ""){
                    return;
                }
            }
            else{
                unlink(QString(path+"/"+QString(dirContent->d_name)).toStdString().c_str());

            }
        }
        rmdir(path.toStdString().c_str());
    }
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
delete translator;
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

delete process;
delete sort;
}

