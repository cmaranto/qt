#include "imagethread.h"

ImageThread::ImageThread(QImage *image, QMutex *imageMutex, QObject *parent) : QThread(parent),
    p_image(image),
    p_imageMutex(imageMutex)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateImage()));
    timer.start(25); //40 hz = 25 msec
}

void ImageThread::updateImage()
{
    //update image from hardware here
    QMutexLocker locker(p_imageMutex);

    int r;
    for(int x = 0; x < p_image->width(); ++x){
        for(int y = 0; y < p_image->height(); ++y){
            r = QRandomGenerator::global()->bounded(255);
            p_image->setPixelColor(x,y,QColor(r,r,r));
        }
    }

    emit updateReady();

}
