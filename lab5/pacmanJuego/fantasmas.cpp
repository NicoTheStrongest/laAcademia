#include "fantasmas.h"

fantasmas::fantasmas(QObject *parent)
    : QObject{parent}
{}

fantasmas::fantasmas(int posSpriteX, int posSpriteY, QGraphicsScene* escena, QPointF posicion, vector<vector<int>> &zonas){
    this->posSpriteX = posSpriteX;
    this->posSpriteY = posSpriteY;
    this->velocidadX = 0;
    this->velocidadY = 0;
    oneBloqueSize = 20;
    QPixmap sprite(":/sprites/ghost.png");
    QRect porcion(posSpriteX, posSpriteY, oneBloqueSize, oneBloqueSize);
    sprite = sprite.copy(porcion);
    fantasmano = new QGraphicsPixmapItem(sprite);
    fantasmano->setPos(posicion);
    escena->addItem(fantasmano);
    fantasmano->setData(0, "fantasma");

    mapa = zonas;

    setRect(0,0,oneBloqueSize,oneBloqueSize);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(movimiento()));
    timer->start(100);
}

void fantasmas::movimiento()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int numeroAleatorio = std::rand() % 4 + 1;
    switch (numeroAleatorio) {
    case 1:
        direccion = Qt::Key_Right;
        break;
    case 2:
        direccion = Qt::Key_Left;
        break;
    case 3:
        direccion = Qt::Key_Up;
        break;
    case 4:
        direccion = Qt::Key_Down;
        break;
    default:
        break;
    }
    cambiarDireccion();
    if (!colisionPared()) {
        moverAdelante();
        setPos(x() + velocidadX, y() + velocidadY);
    }
}

void fantasmas::moverAtras(){
    switch (direccion) {
    case Qt::Key_Right:{
        velocidadX=-(velocidad);
        velocidadY=0;
        setPos(x()+velocidadX,y());
    }
    break;
    case Qt::Key_Up:
    {
        velocidadY=+(velocidad);
        velocidadX=0;
        setPos(x(),y()+velocidadY);
    }
    break;
    case Qt::Key_Left:
    {
        velocidadX=+(velocidad);
        velocidadY=0;
        setPos(x()+velocidadX,y());
    }
    break;
    case Qt::Key_Down:
    {
        //posY=y()-velocidad;
        velocidadY=-(velocidad);
        velocidadX=0;
        setPos(x(),y()+velocidadY);
        //nextDirection = direccion;
        //if(choque == true){setPos(x()+velocidadX,y()+velocidadY); choque==false;}
    }
    break;
    default:
        return;
    }
}

void fantasmas::moverAdelante(){
    switch (direccion) {
    case Qt::Key_Right:
    {
        velocidadX=+(velocidad);
        velocidadY=0;
    }
    break;
    case Qt::Key_Up:
    {
        velocidadY=-(velocidad);
        velocidadX=0;
    }
    break;
    case Qt::Key_Left:
    {
        velocidadX=-(velocidad);
        velocidadY=0;
    }
    break;
    case Qt::Key_Down:
    {
        //posY=y()+velocidad;
        //setPos(x(),y()+velocidad);
        //nextDirection = direccion;
        velocidadY=+(velocidad);
        velocidadX=0;
        //if(choque == true){setPos(x()+velocidadX,y()+velocidadY); choque==false;}
    }
    break;
    default:
        return;
    }
}

bool fantasmas::colisionParedEnDireccion(int direccion1) {
    int fila = y() / oneBloqueSize;  // Asumiendo que el tamaño del tile es tileSize.
    int columna = x() / oneBloqueSize;

    // Calcula la posición futura según la dirección
    switch (direccion1) {
    case Qt::Key_Up:
        fila--;
        break;
    case Qt::Key_Down:
        fila++;
        break;
    case Qt::Key_Left:
        columna--;
        break;
    case Qt::Key_Right:
        columna++;
        break;
    default:
        return false;  // Si la dirección no es válida, no hay colisión.
    }

    bool colisiona = false;

    // Verifica si la posición futura está dentro de los límites y si hay una pared.
    if (fila >= 0 && fila < mapa.size() && columna >= 0 && columna < mapa[0].size()) {
        if (mapa[fila][columna] == 1
            || mapa[getMapYRightSide()][columna] == 1
            || mapa[fila][getMapXRightSide()] == 1
            || mapa[getMapYRightSide()][getMapXRightSide()] == 1){colisiona = true;}
        return colisiona;
    }

    // Si está fuera de los límites, considera que hay colisión.
    return true;
}

bool fantasmas::colisionPared(){
    bool colisiona = false;
    if(mapa[getMapY()][getMapX()] == 1
        || mapa[getMapYRightSide()][getMapX()] == 1
        || mapa[getMapY()][getMapXRightSide()] == 1
        || mapa[getMapYRightSide()][getMapXRightSide()] == 1){colisiona = true;}
    return colisiona;
}

void fantasmas::cambiarDireccion()
{
    if (direccionDeseada != -1 && !colisionParedEnDireccion(direccionDeseada)) {
        nextDirection = direccionDeseada;
        direccionDeseada = -1;  // Reseteamos ya que aplicamos la dirección deseada.
    }

    // Intentamos cambiar a `nextDirection` si es diferente a la dirección actual.
    if (direccion != nextDirection) {
        int direccionTemporal = direccion;
        direccion = nextDirection;
        if (colisionPared()) {
            // Si colisionamos, revertimos a la dirección anterior.
            direccion = direccionTemporal;
        }
    }
}

int fantasmas::getMapX(){return (x()/oneBloqueSize);}

int fantasmas::getMapY(){return (y()/oneBloqueSize);}

int fantasmas::getMapXRightSide(){return ((x()+0.9999*oneBloqueSize)/oneBloqueSize);}

int fantasmas::getMapYRightSide(){return ((y()+0.9999*oneBloqueSize)/oneBloqueSize);}
