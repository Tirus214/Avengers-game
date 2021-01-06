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
    mundo->llenarHeap();
    mundo->arbolHeap->imprimir();
    NodoHeap* hijo = mundo->arbolHeap->buscarIndice(3);

    NodoHeap* padre = mundo->arbolHeap->acomodar(hijo);
    qDebug() << " [ Hijo : Indice =  " << hijo->indice << " ID : " << hijo->nodoDoble->persona->id << " ]";
    qDebug() << " [ Padre : Indice =  " << padre->indice << " ID : " << padre->nodoDoble->persona->id << " ]";
    mundo->arbolHeap->swap(mundo->arbolHeap->primerNodo,padre->indice,hijo->indice);
    mundo->arbolHeap->imprimir();
}
