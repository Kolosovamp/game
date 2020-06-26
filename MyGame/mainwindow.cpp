#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedWidth(1200);
    this->setFixedHeight(950);
    ui->splitter->move(1000, 0);
}

void MainWindow::setLandscapeMap(std::map<LandscapeType, std::vector<std::pair<size_t, size_t> > > map)
{
    this->LandscapeMap = map;
}

MainWindow::~MainWindow()
{
    delete ui;
}

Canvas::Canvas(size_t height, size_t width, std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> LandscapeMap, QWidget *parent)
    : QGraphicsView(parent), LandscapeMap(LandscapeMap),
      fieldScene(0, 0, 900, 900, this),
      isGameStarted(true) {

    minSizeOfCage = 90;//px
    setScene(&fieldScene);
    fitInView(fieldScene.sceneRect(), Qt::KeepAspectRatio);
    this->resize(900, 900);
    this->move(20, 20);
    w = width;
    h = height;

    w = 5;
    h = 5;

    if(w == h){
        minSizeOfCage = 900/w;
    }
    else{
        if(w < h){
            QGraphicsScene m_scene(0, 0, minSizeOfCage*w, minSizeOfCage*h, this);
            setScene(&m_scene);
            fitInView(m_scene.sceneRect(), Qt::KeepAspectRatio);
            this->resize(minSizeOfCage*w, minSizeOfCage*h);
            //std::cout << "check "<<this->width()<<" "<<this->height()<<std::endl;
        }
        else{
            QGraphicsScene m_scene(0, 0, minSizeOfCage*w, minSizeOfCage*h, this);
            setScene(&m_scene);
            fitInView(m_scene.sceneRect(), Qt::KeepAspectRatio);
            this->resize(minSizeOfCage*w, minSizeOfCage*h);
            //std::cout << "check "<<this->width()<<" "<<this->height()<<std::endl;
        }
    }


}

void Canvas::paintEvent(QPaintEvent *event)
{
   QPainter p;
   p.begin(viewport());
   p.setRenderHint(QPainter::Antialiasing, true);
   p.setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));   

   //double k = std::max(w, h) / std::min(w, h);
   //vertical lines
   for (int i = 0; i < w; ++i){
        p.drawLine(i*(double(width())/w), 0,  i*(double(width())/w), height());
    }
   //horizontal lines
    for (int i = 0; i < h; ++i){
        p.drawLine(0, i*(double(height())/h), width(), i*(double(height())/h));
    }

    QImage forest(":/resources/forest2.jpg");
    QTransform transformForForest;
    QImage image = forest.transformed(transformForForest, Qt::SmoothTransformation);
    QPixmap forestPixmap = QPixmap::fromImage(image);

    QImage plain(":/img/resources/plain.jpg");
    QTransform transformForPlain;
    QImage image_ = plain.transformed(transformForPlain, Qt::SmoothTransformation);
    QPixmap plainPixmap = QPixmap::fromImage(image_);

    QImage mountain(":/resources/mountain2.jpg");
    QTransform transformForMountain;
    QImage image__ = mountain.transformed(transformForMountain, Qt::SmoothTransformation);
    QPixmap mountainPixmap = QPixmap::fromImage(image__);

    size_t c1 = 0, c2 = 0, c3 = 0;
    for(auto el : LandscapeMap){
        if(el.first == FOREST)
            for(auto coord : el.second){
                c1++;
                std::cout << coord.first<<" "<<coord.second<<std::endl;
                p.drawPixmap(coord.second*minSizeOfCage, coord.first*minSizeOfCage, minSizeOfCage, minSizeOfCage, forestPixmap);
                //p.drawPixmap(0,0,170,170, forestPixmap);
            }
        if(el.first == PLAIN)
            for(auto coord : el.second){
                c2++;
                std::cout << coord.first<<" "<<coord.second<<std::endl;
                p.drawPixmap(coord.second*minSizeOfCage, coord.first*minSizeOfCage, minSizeOfCage, minSizeOfCage, plainPixmap);
                //p.drawPixmap(0,0,170,170, forestPixmap);
            }
        if(el.first == MOUNTAIN)
            for(auto coord : el.second){
                c3++;
                std::cout << coord.first<<" "<<coord.second<<std::endl;
                p.drawPixmap(coord.second*minSizeOfCage, coord.first*minSizeOfCage, minSizeOfCage, minSizeOfCage, mountainPixmap);
                //p.drawPixmap(0,0,170,170, forestPixmap);
            }
    }
    std::cout <<"!!! " << c1 << " " <<c2<< " "<<c3<<std::endl;


    /*QImage myImg("/home/marina/f.jpg");
    QTransform transform;
    QImage image = myImg.transformed(transform, Qt::SmoothTransformation);
    QPixmap m = QPixmap::fromImage(myImg);*/


    /*for (int i = 0; i < w; ++i)
            p.drawLine(double(i)/w_*width(), 0, double(i)/w_*width(), width());
        for (int i = 0; i < h; ++i)
            p.drawLine(0, i/h_*height(), width(), i/h_*height());*/
   //std::cout << h << " " << w << std::endl;
   //w = 13;
   //h = 5;

   //fieldScene.update(0, 0, 450, 450);
   /*if (w != h){
       if(w > h)
        fieldScene.update(0,0, (850/w)*h, 850/w);
   }*/



   // p.drawPixmap(0,0,170,170, forestPixmap);
   // p.drawPixmap(170*3, 170*3, 170, 170, forestPixmap);



    QImage myImg2("/home/marina/d.jpg");
    QTransform transform2;
    QImage image2 = myImg2.transformed(transform2, Qt::SmoothTransformation);
    QPixmap m2 = QPixmap::fromImage(myImg2);
//    p.drawPixmap(170*4, 170*3, 170, 170, m2);



    /*QImage myImg3("/home/marina/q.png");
    QTransform transform3;
    QImage image3 = myImg3.transformed(transform3, Qt::SmoothTransformation);
    QPixmap m3 = QPixmap::fromImage(myImg3);
    p.drawPixmap(170*4, 170*3, 170, 170, m3);*/

    p.end();



}
void MainWindow::on_pushButton_clicked()
{
    //Canvas *canvas = .new Canvas(850, 850, this);
    size_t w_ = 5, h_ = 5;
    if(this->w && this->h){
        w_ = w;
        h_ = h;
    }
    canvas = new Canvas(h_, w_, this->LandscapeMap, this);
    canvas->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
    canvas->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    std:: cout << this->size().width() << std:: endl;
    std:: cout << this->size().height() << std::endl;
    Settings settings;
    settings.setModal(true);
    settings.show();
    settings.exec();
}
