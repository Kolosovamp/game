#include "myitem.h"

#include "myitem.h"
#include <iostream>

MyItem::MyItem()
{
    Pressed = false;
    setFlag(ItemIsMovable);
}

QRectF MyItem::boundingRect() const
{
    // outer most edges
    return QRectF(30,30,100,100);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    //std::cout << "!!!!" << std::endl;

    if(Pressed)
    {
       //std::cout << "pressed\n";
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawEllipse(rect);
    }
    else
    {
        QPen pen(Qt::black, 3);
            //std::cout<<"not pressed\n";
        painter->setPen(pen);
        painter->drawRect(rect);
    }
}

void MyItem::draw(QWidget *widget)
{
    QRectF rect = boundingRect();
    std::cout << "!!!!" << std::endl;
    QPainter *painter = new QPainter;
    //painter.begin(widget);

    if(Pressed)
    {
       std::cout << "pressed\n";
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawEllipse(rect);
    }
    else
    {
        QPen pen(Qt::black, 3);
            std::cout<<"not pressed\n";
        painter->setPen(pen);
        painter->drawRect(rect);
    }
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


