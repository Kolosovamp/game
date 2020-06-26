#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPaintEvent>
#include <QFileDialog>
#include "myitem.h"
#include "enum.h"
#include <vector>
#include "map"
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class Canvas : public QGraphicsView {

    Q_OBJECT
    std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> LandscapeMap;
    //standart size
    size_t w = 5;
    size_t h = 5;
    size_t minSizeOfCage = 90;
public:
    explicit Canvas(size_t height, size_t width, std::map<LandscapeType,
                   std::vector<std::pair<size_t, size_t>>> LandscapeMap, QWidget *parent = 0);

public slots:

protected slots:
    void paintEvent(QPaintEvent *event) override;
    //void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
protected:
    QGraphicsScene fieldScene;
    bool isGameStarted;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> LandscapeMap;

public:

    MainWindow(QWidget *parent = nullptr);
    void setLandscapeMap(std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> map);
    void setBoardSize(size_t w, size_t h) {
        this->w = w;
        this->h = h;
    }
    std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> getLandscapeMap() const { return LandscapeMap; }
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    size_t w = 0;
    size_t h = 0;


};


#endif // MAINWINDOW_H
