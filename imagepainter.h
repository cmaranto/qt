#ifndef IMAGEPAINTER_H
#define IMAGEPAINTER_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QImage>
#include <QPainter>
#include <QMutex>

class ImagePainter : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT

public:
    ImagePainter(QQuickItem *parent = nullptr);
    void init(QImage *image, QMutex *imageMutex);
    void paint(QPainter *painter);

private:
    QImage *p_image;
    QMutex *p_imageMutex;
};

#endif // IMAGEPAINTER_H
