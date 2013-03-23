#ifndef QANCHORS_H
#define QANCHORS_H

#include <QObject>
#include <QWidget>

#define QANCHOR_TOP             0x001
#define QANCHOR_BOTTOM          0x002
#define QANCHOR_LEFT            0x004
#define QANCHOR_RIGHT           0x008
#define QANCHOR_TOP_LEFT        QANCHOR_TOP|QANCHOR_LEFT
#define QANCHOR_BOTTOM_LEFT     QANCHOR_BOTTOM|QANCHOR_LEFT
#define QANCHOR_TOP_RIGHT       QANCHOR_TOP|QANCHOR_RIGHT
#define QANCHOR_BOTTOM_RIGHT    QANCHOR_BOTTOM|QANCHOR_RIGHT
#define QANCHOR_ALL             QANCHOR_TOP|QANCHOR_BOTTOM|QANCHOR_LEFT|QANCHOR_RIGHT

typedef struct QANCHOR_DATA {
    int anchors;
    QWidget *parentNode;
    QWidget *childNode;
    QRect parentRect;
    QRect childRect;
};

class QAnchors : public QObject
{
    Q_OBJECT
public:
    explicit QAnchors(QObject *parent = 0);
    void addWidget(QWidget* parentNode, QWidget* childNode, int anchors);
    void resizeWidget(int i);
    void resizeWidgets();
private:
    QVector<QANCHOR_DATA> elems;
signals:
    
public slots:
    
};

#endif // QANCHORS_H
