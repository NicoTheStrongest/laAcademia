#ifndef FANTASMAS_H
#define FANTASMAS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include <vector>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()

using namespace std;

class fantasmas : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit fantasmas(QObject *parent = nullptr);
    fantasmas(int posSpriteX, int posSpriteY, QGraphicsScene* escena, QPointF posicion, vector<vector<int>> &zonas);

    int oneBloqueSize, posSpriteX, posSpriteY;
    QPixmap sprite;
    QGraphicsPixmapItem* fantasmano;
    vector<vector<int>> mapa;
    int velocidad;
    int velocidadX;
    int velocidadY;
    int direccion = Qt::Key_Right;
    int nextDirection = Qt::Key_Right;
    int direccionDeseada = Qt::Key_Right;

    void moverAtras();
    void moverAdelante();
    bool colisionParedEnDireccion(int direccion1);
    bool colisionPared();
    void cambiarDireccion();
    int getMapX();
    int getMapY();
    int getMapXRightSide();
    int getMapYRightSide();
private:
    QTimer* timer;
signals:
public slots:
    void movimiento();
};

#endif // FANTASMAS_H
