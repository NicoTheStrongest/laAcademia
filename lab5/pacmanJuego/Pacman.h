#ifndef PACMAN_H
#define PACMAN_H

#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <vector>

using namespace std;

class pacman : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit pacman(QObject *parent = nullptr);
    pacman(vector<vector<int>> &zonas, int* score, QGraphicsScene* escena);

    int posX;
    int posY;
    int ancho;
    int alto;
    int velocidad;
    int velocidadX;
    int velocidadY;
    int oneBloqueSize = 20;
    int *score;
    QGraphicsScene* escena;
    QTimer* timer;
    vector<vector<int>> mapa;
    bool choque;
    int direccion = Qt::Key_Right;
    int nextDirection = Qt::Key_Right;
    int direccionDeseada;


    void keyPressEvent(QKeyEvent* event);
    void movimientoPacman();
    void moverAtras();
    void moverAdelante();
    bool colisionPared();
    bool colisionParedEnDireccion(int direccion1);
    void colisionFantasma();
    void cambiarDireccion();

    int getMapX();
    int getMapY();
    int getMapXRightSide();
    int getMapYRightSide();
    void eat();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    float filasSprite, columnasSprite, anchoSprite, altoSprite;
private:
    QTimer* sprite;
    QPixmap* pixmap;
public slots:
    void mover();
    void cambiarSprite();
signals:
};

#endif // PACMAN_H
