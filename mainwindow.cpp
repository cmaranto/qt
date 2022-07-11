#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      image(QSize(100,100),QImage::Format_Grayscale8),
      imageThread(nullptr),
      imagePainter(nullptr)

{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl("qrc:/qml/quickimage.qml"));
    imagePainter = dynamic_cast<ImagePainter*>(ui->quickWidget->rootObject());
    imagePainter->init(&image,&imageMutex);

    imageThread = new ImageThread(&image,&imageMutex,this);
    imageThread->start();

    connect(imageThread,SIGNAL(updateReady()),imagePainter,SLOT(update()));
}

MainWindow::~MainWindow()
{
    imageThread->quit();
    delete ui;
}

