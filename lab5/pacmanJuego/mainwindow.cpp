#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Pacman.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    // Configurar la interfaz visual desde el archivo .ui
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    QBrush brush(Qt::black);
    scene->setBackgroundBrush(brush);
    oneFoodSize = 6;
    oneBloqueSize = 20;
    score = 0;

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
        {1,1,1,1,1, 2,1,2,1,0, 0,0,1,2,1, 2,1,1,1,1, 1},
        {2,2,2,2,2, 2,2,2,1,0, 0,0,1,2,2, 2,2,2,2,2, 2},
        {1,1,1,1,1, 2,1,2,1,0, 0,0,1,2,1, 2,1,1,1,1, 1},
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

    blinky = new fantasmas(0, 0, scene, QPointF(9*oneBloqueSize, 10*oneBloqueSize), zonas);
    pinky = new fantasmas(0, 20, scene, QPointF(9*oneBloqueSize, 11*oneBloqueSize), zonas);
    inky = new fantasmas(29, 20, scene, QPointF(11*oneBloqueSize, 10*oneBloqueSize), zonas);
    clyde = new fantasmas(29, 0, scene, QPointF(11*oneBloqueSize, 11*oneBloqueSize), zonas);
    scene->addItem(blinky);
    scene->addItem(pinky);
    scene->addItem(inky);
    scene->addItem(clyde);

    pacmanInicial = new pacman(zonas, &score, ui->graphicsView->scene());
    scene->addItem(pacmanInicial);
    pacmanInicial->setPos(10*oneBloqueSize, 13*oneBloqueSize);

    brush = Qt::yellow;
    pacmanInicial->setBrush(brush);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow(){
    delete ui;
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
                pared->setData(0,"comida");
            }
        }
    }
}


