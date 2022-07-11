#ifndef IMAGETHREAD_H
#define IMAGETHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QImage>
#include <QDebug>
#include <QRandomGenerator>

class ImageThread : public QThread
{
    Q_OBJECT
public:
    ImageThread(QImage *image, QMutex *imageMutex, QObject *parent = nullptr);

public slots:
    void updateImage();

signals:
    void updateReady();

private:
    QImage *p_image;
    QMutex *p_imageMutex;
    QTimer timer;
};

#endif // IMAGETHREAD_H
