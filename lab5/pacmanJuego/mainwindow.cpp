#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Pacman.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Configurar la interfaz visual desde el archivo .ui
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    QBrush brush(Qt::black);
    scene->setBackgroundBrush(brush);
    oneFoodSize = 6;
    oneBloqueSize = 20;

    zonas = {
        {1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1},
        {1,2,2,2,2, 2,2,2,2,2, 1,2,2,2,2, 2,2,2,2,2, 1},
        {1,2,1,1,1, 2,1,1,1,2, 1,2,1,1,1, 2,1,1,1,2, 1},
        {1,2,1,1,1, 2,1,1,1,2, 1,2,1,1,1, 2,1,1,1,2, 1},
        {1,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 1},
        {1,2,1,1,1, 2,1,2,1,1, 1,1,1,2,1, 2,1,1,1,2, 1},
        {1,2,2,2,2, 2,1,2,2,2, 1,2,2,2,1, 2,2,2,2,2, 1},
        {1,1,1,1,1, 2,1,1,1,2, 1,2,1,1,1, 2,1,1,1,1, 1},
        {0,0,0,0,1, 2,1,2,2,2, 2,2,2,2,1, 2,1,0,0,0, 0},
        {1,1,1,1,1, 2,1,2,1,1, 2,1,1,2,1, 2,1,1,1,1, 1},
        {2,2,2,2,2, 2,2,2,1,2, 2,2,1,2,2, 2,2,2,2,2, 2},
        {1,1,1,1,1, 2,1,2,1,2, 2,2,1,2,1, 2,1,1,1,1, 1},
        {0,0,0,0,1, 2,1,2,1,1, 1,1,1,2,1, 2,1,0,0,0, 0},
        {0,0,0,0,1, 2,1,2,2,2, 2,2,2,2,1, 2,1,0,0,0, 0},
        {1,1,1,1,1, 2,2,2,1,1, 1,1,1,2,2, 2,1,1,1,1, 1},
        {1,2,2,2,2, 2,2,2,2,2, 1,2,2,2,2, 2,2,2,2,2, 1},
        {1,2,1,1,1, 2,1,1,1,2, 1,2,1,1,1, 2,1,1,1,2, 1},
        {1,2,2,2,1, 2,2,2,2,2, 2,2,2,2,2, 2,1,2,2,2, 1},
        {1,1,2,2,1, 2,1,2,1,1, 1,1,1,2,1, 2,1,2,2,1, 1},
        {1,2,2,2,2, 2,1,2,2,2, 1,2,2,2,1, 2,2,2,2,2, 1},
        {1,2,1,1,1, 1,1,1,1,2, 1,2,1,1,1, 1,1,1,1,2, 1},
        {1,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 1},
        {1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1}
    };

    drawWalls();
    drawFood();
    ui->graphicsView->setScene(scene);

    pacmanInicial = new pacman(zonas);
    scene->addItem(pacmanInicial);
    pacmanInicial->setPos(10*oneBloqueSize, 13*oneBloqueSize);

    brush = Qt::yellow;
    pacmanInicial->setBrush(brush);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: eat()
{
    for (int i = 0; i < (int)zonas.size(); ++i) {
        for (int j = 0; j < (int)zonas[0].size(); ++j) {
            if (zonas[i][j] == 2 && pacmanInicial->getMapX() == j && pacmanInicial->getMapY() == i){
                QList<QGraphicsItem*> items = scene->items();
                for (QGraphicsItem* item : items) {
                    QGraphicsRectItem* rect = dynamic_cast<QGraphicsRectItem*>(item);
                    if (rect && rect->data(0).toInt() == i) {
                        // Este es el rectángulo con el identificador buscado
                        scene->removeItem(rect);
                        delete rect;
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow:: drawWalls()
{
    QGraphicsRectItem* pared;
    QBrush brush(Qt::blue);
    for (int i = 0; i < (int)zonas.size(); ++i) {
        for (int j = 0; j < (int)zonas[0].size(); ++j) {
            if(zonas[i][j] == 1){ // pared
                pared = scene-> addRect(j*oneBloqueSize, i*oneBloqueSize, oneBloqueSize, oneBloqueSize);
                pared->setBrush(brush);
                pared->setData(0, i);
            }
        }
    }
}

void MainWindow::drawFood()
{
    QGraphicsRectItem* pared;
    QBrush brush(Qt::yellow);
    for (int i = 0; i < (int)zonas.size(); ++i) {
        for (int j = 0; j < (int)zonas[0].size(); ++j) {
            if(zonas[i][j] == 2){ // comida / camino
                pared = scene-> addRect(j*oneBloqueSize+7, i*oneBloqueSize+7, oneFoodSize, oneFoodSize);
                pared->setBrush(brush);
            }
        }
    }
}


