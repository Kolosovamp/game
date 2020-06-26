#ifndef MYITEM_H
#define MYITEM_H

#include <QAbstractItemModel>

/*class MyItem : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MyItem(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};*/

#include <QPainter>
#include <QGraphicsItem>
//#include "mainwindow.h"

// class for customization
class MyItem :public QGraphicsItem
{
public:
    MyItem();

    QRectF boundingRect() const;

    // overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);
    void draw(QWidget * widget);

    // item state
    bool Pressed;
protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYITEM_H
