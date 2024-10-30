#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    QPixmap* mapa;
    QTimer timer;
    vector<vector<int>> zonas;
    int fps = 30;
    int oneBloqueSize = 20;
    void drawWalls();
private:
    Ui::MainWindow *ui;
    // QGraphicsView* view;     // Vista para mostrar la escena
    QGraphicsScene* scene;   // La escena que se va a construir.
    void crearEscena();  // Método para configurar la escena y agregar las paredes
};
#endif // MAINWINDOW_H
