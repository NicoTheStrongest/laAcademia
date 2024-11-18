#include "Pacman.h"
#include <vector>

pacman::pacman(QObject *parent)
    : QObject{parent}
{}

pacman::pacman(vector<vector<int>> &zonas, int *score, QGraphicsScene* escena): posX(10*oneBloqueSize), posY(13*oneBloqueSize), ancho(20), alto(20), velocidad(1){
    this->velocidadX = 0;
    this->velocidadY = 0;
    this->score = score;
    mapa = zonas;
    this->escena = escena;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mover()));
    timer->start(16.67);

    sprite = new QTimer();
    connect(sprite, SIGNAL(timeout()), this, SLOT(cambiarSprite()));
    sprite->start(16.67);
    filasSprite = 0;
    columnasSprite = 0;
    pixmap = new QPixmap(":/sprites/animations.gif");
    anchoSprite = 20;
    altoSprite = 20;

    setRect(0,0,ancho,alto);
    // para aplicar los movimientos del pacman
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void pacman:: keyPressEvent(QKeyEvent* event) {
    //nextDirection = event->key();
    int nuevaDireccion = event->key();
    if (!colisionParedEnDireccion(nuevaDireccion)) {
        // Si la nueva dirección no está bloqueada, la asignamos a `nextDirection`.
        nextDirection = nuevaDireccion;
        direccionDeseada = -1;  // Reseteamos direccionDeseada ya que nextDirection es válida.
    } else {
        // Si está bloqueada, la guardamos en `direccionDeseada` para un intento posterior.
        direccionDeseada = nuevaDireccion;
    }

    cambiarDireccion();
    if(colisionPared()){
        moverAtras();
        nextDirection = event->key();
        cambiarDireccion();
        return;
    } else {
        moverAdelante();
        setPos(x()+velocidadX,y()+velocidadY);
    }
}

void pacman::moverAtras(){
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
    case Qt::Key_Escape:
    {
        qDebug() << "Se presionó ESC. Cerrando la aplicación...";
        QApplication::quit();  // Cerrar la aplicación
    }
        return;
    default:
        return;
    }
}

void pacman::moverAdelante()
{
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
    case Qt::Key_Escape:
    {
        qDebug() << "Se presionó ESC. Cerrando la aplicación...";
        QApplication::quit();  // Cerrar la aplicación
    }
        return;
    default:
        return;
    }
}

bool pacman::colisionPared()
{
    bool colisiona = false;
    if(mapa[getMapY()][getMapX()] == 1
        || mapa[getMapYRightSide()][getMapX()] == 1
        || mapa[getMapY()][getMapXRightSide()] == 1
        || mapa[getMapYRightSide()][getMapXRightSide()] == 1){colisiona = true;}
    return colisiona;
}

bool pacman::colisionParedEnDireccion(int direccion1) {
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

void pacman::colisionFantasma()
{
    QList<QGraphicsItem*> colisiones = collidingItems();
    for (QGraphicsItem* item : colisiones) {
        if (item->data(0).toString() == "fantasma") {
            qDebug() << "Se presionó ESC. Cerrando la aplicación...";
            QApplication::quit();  // Cerrar la aplicación
            break;
        }
    }
}

void pacman::cambiarDireccion()
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

int pacman::getMapX(){return (x()/oneBloqueSize);}

int pacman::getMapY(){return (y()/oneBloqueSize);}

int pacman::getMapXRightSide(){return ((x()+0.9999*ancho)/oneBloqueSize);}

int pacman::getMapYRightSide(){return ((y()+0.9999*ancho)/oneBloqueSize);}

void pacman::mover(){
    cambiarDireccion();
    if (!colisionPared()) {
        moverAdelante();
        setPos(x() + velocidadX, y() + velocidadY);
    }
    if(x() == 0 && y() == 10*oneBloqueSize){setPos(20*oneBloqueSize, y());}
    else if (x() == 20*oneBloqueSize && y() == 10*oneBloqueSize){setPos(1, y());}
    colisionFantasma();
    eat();
    if(*score == 215){
        qDebug() << "Se presionó ESC. Cerrando la aplicación...";
        QApplication::quit();  // Cerrar la aplicación
    }
}

void pacman::cambiarSprite()
{
    columnasSprite += 20;
    if(columnasSprite>=140){
        columnasSprite = 0;
    }
    this->update(-anchoSprite/2,-altoSprite/2,anchoSprite,altoSprite);
}

void pacman:: eat(){
    QList<QGraphicsItem*> colisiones = collidingItems();
    for (QGraphicsItem* item : colisiones) {
        if (item->data(0).toString() == "comida") {
            escena->removeItem(item);
            (*score)++;
            qDebug()<<*score;
            break;
        }
    }
}

QRectF pacman::boundingRect() const
{
    return QRectF(-anchoSprite/9999999,-altoSprite/9999999,anchoSprite,altoSprite);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-anchoSprite/9999999,-altoSprite/9999999,*pixmap,columnasSprite,0,anchoSprite, altoSprite);
}

















