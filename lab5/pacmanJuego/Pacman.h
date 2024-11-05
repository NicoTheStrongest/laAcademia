#ifndef PACMAN_H
#define PACMAN_H

#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <vector>

using namespace std;

class pacman : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit pacman(QObject *parent = nullptr);

    int posX;
    int posY;
    int ancho;
    int alto;
    int velocidad;
    int velocidadX;
    int velocidadY;
    int oneBloqueSize = 20;
    QTimer* timer;
    vector<vector<int>> mapa;
    bool choque;
    int direccion = Qt::Key_Right;
    int nextDirection = Qt::Key_Right;
    int direccionDeseada;

    pacman(vector<vector<int>> &zonas);

    void keyPressEvent(QKeyEvent* event);

    void movimientoPacman();

    void moverAtras();

    void moverAdelante();

    bool colisionPared();

    bool colisionParedEnDireccion(int direccion1);

    void colisionFantasma();

    void cambiarDireccion();

    void manejoSprites();

    void pintar();

    int getMapX();
    int getMapY();
    int getMapXRightSide();
    int getMapYRightSide();


public slots:
    void mover();
signals:
};

#endif // PACMAN_H
