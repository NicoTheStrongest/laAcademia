#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "Pacman.h"
#include "fantasmas.h"

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
#include <Qtimer>
#include <map>
#include <vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void keyPressEvent(QKeyEvent *event);

    QPixmap* mapa;
    QTimer timer;
    vector<vector<int>> zonas;
    pacman* pacmanInicial;
    fantasmas* blinky;
    fantasmas* pinky;
    fantasmas* inky;
    fantasmas* clyde;
    int oneBloqueSize;
    int oneFoodSize;
    int score;

    void drawWalls();
    void drawFood();
private:
    Ui::MainWindow *ui;
    // QGraphicsView* view;     // Vista para mostrar la escena
    QGraphicsScene* scene;   // La escena que se va a construir.
    void crearEscena();  // Método para configurar la escena y agregar las paredes
};
#endif // MAINWINDOW_H
