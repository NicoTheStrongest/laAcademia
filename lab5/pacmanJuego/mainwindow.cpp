#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapa.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Configurar la interfaz visual desde el archivo .ui
    ui->setupUi(this);
    // Inicializar la escena
    scene = new QGraphicsScene(this);
    QGraphicsRectItem* fondo;
    QBrush brush(Qt::black);
    fondo = scene->addRect(0, 0, 420, 460);
    fondo->setBrush(brush);

    /*
    PARA AGREGAR FONDOS COMO MAPAS SIN INTERACCION, Y SIN DEFINIR OBJETOS.

    QPixmap bk =  QPixmap(":/sprites/sample.jpeg").scaled(600,590,Qt::KeepAspectRatio);
    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem(bk);
    if (bk.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen del fondo.";
    } else {
        qDebug() << "Imagen del fondo cargada correctamente.";
    }
    fondo->setPos(0, 0);
    scene->addItem(fondo);  // Agregar el fondo a la escena
    */
    scene->addItem(fondo);  // Agregar el fondo a la escena

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
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: drawWalls()
{
    QGraphicsRectItem* pared;
    QBrush brush(Qt::blue);
    for (int i = 0; i < (int)zonas.size(); ++i) {
        for (int j = 0; j < (int)zonas[0].size(); ++j) {
            if(zonas[i][j] == 1){ // pared
                pared = scene->addRect(j*oneBloqueSize, i*oneBloqueSize, oneBloqueSize, oneBloqueSize);
                pared->setBrush(brush);
            }
        }
    }
}


/*
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Configurar la interfaz visual desde el archivo .ui
    ui->setupUi(this);

    // Inicializar la escena
    scene = new QGraphicsScene(this);

    // Agregar la imagen de fondo como parte de la escena
    QPixmap bk =  QPixmap("/home/craljimenez/Documents/UdeA/Laboratorios_C_plus_plus/desarrollos_Cristian/practica_5_caj/practica_5/imgs/background.png").scaled(600,600,Qt::KeepAspectRatio);
    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem(bk);
    if (bk.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen del fondo.";
    } else {
        qDebug() << "Imagen del fondo cargada correctamente.";
    }
    fondo->setPos(0, 0);  // Posicionar la imagen en el origen de la escena
    scene->addItem(fondo);  // Agregar el fondo a la escena

    // Configurar la escena y agregar las "paredes"
    crearEscena();

    // Asignar la escena al QGraphicsView que definiste en el archivo .ui
    ui->graphicsView->setScene(scene);

    // Desactivar las barras de scroll
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Ajustar la vista al tamaño de la escena
    ui->graphicsView->setFixedSize(600, 600);

    // Crear y agregar el personaje a la escena
    Personaje* personaje = new Personaje();
    personaje->setPos(300, 500);  // Posicionar el personaje en el centro de la escena
    scene->addItem(personaje);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/


/*
void MainWindow::crearEscena() {
    scene->setSceneRect(0, 0, 600, 600);
    // Crear "paredes" como rectángulos
    QGraphicsRectItem* paredSuperior = scene->addRect(0, 0, 600, 20);   // Pared superior
    QGraphicsRectItem* paredInferior = scene->addRect(0, 580, 600, 20); // Pared inferior
    QGraphicsRectItem* paredIzquierda = scene->addRect(0, 20, 20, 560); // Pared izquierda
    QGraphicsRectItem* paredDerecha = scene->addRect(580, 20, 20, 560); // Pared derecha

    // Opcional: Cambiar color o textura de las paredes
    // QBrush brush(Qt::gray);  // Paredes grises
    // QBrush brush(Qt::NoBrush);  // Sin color de relleno
    QPixmap texturaBloques("/home/craljimenez/Documents/UdeA/Laboratorios_C_plus_plus/desarrollos_Cristian/practica_5_caj/practica_5/imgs/pared_gris.png");
    QBrush brush(texturaBloques.scaled(20,20,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada

    paredSuperior->setBrush(brush);
    paredInferior->setBrush(brush);
    paredIzquierda->setBrush(brush);
    paredDerecha->setBrush(brush);

    QPen pen(Qt::NoPen);        // Sin borde (bordes sin color.)

    paredSuperior->setPen(pen);
    paredInferior->setPen(pen);
    paredIzquierda->setPen(pen);
    paredDerecha->setPen(pen);

    paredSuperior->setOpacity(0); // se hacen invisibles
    paredInferior->setOpacity(0); // se hacen invisibles
    paredIzquierda->setOpacity(0); // se hacen invisibles
    paredDerecha->setOpacity(0); // se hacen invisibles




    // Hacer que las paredes sean detectables para colisiones
    paredSuperior->setData(0, "pared");  // Etiquetar cada pared como "pared"
    paredInferior->setData(0, "pared");
    paredIzquierda->setData(0, "pared");
    paredDerecha->setData(0, "pared");
}
*/
