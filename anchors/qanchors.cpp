#include "qanchors.h"

QAnchors::QAnchors(QObject *parent) :
    QObject(parent)
{
}

//! add new widget for resize
void QAnchors::addWidget(QWidget* parentNode, QWidget* childNode, int anchors)
{
    QANCHOR_DATA data;
    data.parentNode = parentNode;
    data.parentRect = parentNode->geometry();
    data.childNode = childNode;
    data.childRect = childNode->geometry();
    data.anchors = anchors;
    elems.push_back(data);
}

//! resize widget
void QAnchors::resizeWidget(int i)
{
    if (i < 0 || i >= elems.size()) return;

    QANCHOR_DATA data=elems[i];
    QRect rect = data.childRect;

    if (data.anchors & QANCHOR_BOTTOM)
    {
        if (data.anchors & QANCHOR_TOP) {
            int dh=data.parentRect.height()-data.childRect.height();
            rect.setHeight(data.parentNode->height()-dh);
        } else {
           int bottom = data.parentRect.height()-data.childRect.height()-data.childRect.top();
           rect.setTop(data.parentNode->height()-data.childRect.height()-bottom);
           rect.setHeight(data.childRect.height());
        }
    }

    if (data.anchors & QANCHOR_RIGHT)
    {
        if (data.anchors & QANCHOR_LEFT) {
            int dw=data.parentRect.width()-data.childRect.width();
            rect.setWidth(data.parentNode->width()-dw);
        }else{
            int right=data.parentRect.width()-data.childRect.width()-data.childRect.left();
            rect.setLeft(data.parentNode->width()-data.childRect.width()-right);
            rect.setWidth(data.childRect.width());
        }
    }

    if (rect.width() < 0) rect.setWidth(0);
    if (rect.height() < 0) rect.setHeight(0);

    if (rect.left() < 0) rect.setLeft(0);
    if (rect.top() < 0) rect.setTop(0);

    data.childNode->setGeometry(rect);
}

//! resize all widgets
void QAnchors::resizeWidgets()
{
    for (int i=0; i<elems.size(); ++i) resizeWidget(i);
}










