#include "imagepainter.h"

ImagePainter::ImagePainter(QQuickItem *parent) : QQuickPaintedItem(parent),
    p_image(nullptr),
    p_imageMutex(nullptr)
{
}

void ImagePainter::init(QImage *image, QMutex *imageMutex)
{
    p_image = image;
    p_imageMutex = imageMutex;
}

void ImagePainter::paint(QPainter *painter)
{
    if(p_image){
        QMutexLocker locker(p_imageMutex);
        painter->drawImage(QPoint(0,0),*p_image);
    }
}
