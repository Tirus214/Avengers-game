#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mundo = new Mundo();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCrearPersonas_clicked(){
    int num = ui->txfCrearPersonas->text().toInt();
    mundo->crearPersonas(num);
    mundo->imprimir();
    qDebug() << mundo->listaPersonas->largo();

//      mundo->crearArbol();
//      mundo->arbolHeap->imprimir();
//    NodoHeap* hijo = mundo->arbolHeap->buscarIndice(3);

//    NodoHeap* padre = mundo->arbolHeap->acomodar(hijo);
//    qDebug() << " [ Hijo : Indice =  " << hijo->indice << " ID : " << hijo->nodoDoble->persona->id << " ]";
//    qDebug() << " [ Padre : Indice =  " << padre->indice << " ID : " << padre->nodoDoble->persona->id << " ]";
//    mundo->arbolHeap->swap(hijo,padre);
//    mundo->arbolHeap->imprimir();

    // Primero se llena el mundo y luego se llenan los heaps
//    structCorvus = new CorvusGlaive(mundo);
    //structCorvus->heap->imprimir();
    //structCorvus->imprimir();
//    Midnight * structMidnight = new Midnight(mundo);


    //Nebula * structNebula = new Nebula(mundo);
    //structNebula->nodoSeleccionado->imprimir();
    //structNebula->matarPersonas(structNebula->nodoSeleccionado);


}
