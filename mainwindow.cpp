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
//    qDebug() << mundo->listaPersonas->largo();
//        CorvusGlaive * corvus = new CorvusGlaive(mundo);
//        corvus->insertarAHeap();
//        qDebug() << "Corvus sirve 1";
//        corvus->matarPersonas();
//        qDebug() << "Corvus sirve 2";
        Midnight * midnight = new Midnight(mundo);
        mundo->llenarHeap(midnight->heap);

//        qDebug() << "Midnight sirve 1";
        midnight->recorrerHeap();
        midnight->matarPersonas();
        mundo->contarMuertos();
        mundo->contarVivos();
        qDebug() << "After salvar";
//        Nebula * nebula = new Nebula(mundo);
//        nebula->randNodoArbol();
//        nebula->matarPersonas(nebula->nodoSeleccionado, nebula->nodoSeleccionado->persona->id);
//        qDebug() << nebula->contador;
//        qDebug() << "Nebula sirve";
//        //mundo->imprimir();
//        Dwarf * black = new Dwarf(mundo);
//        qDebug() << "Dwarf sirve sirve constructor";
//        black->matarPersonas();
//        qDebug() << "Dwarf sirve sirve";
//        qDebug() << black->contador;
        Ironman * ironmanPrueba = new Ironman(mundo);
        ironmanPrueba->detonarBombas();
        mundo->contarMuertos();
        mundo->contarVivos();
    //Thanos * thanosPrueba = new Thanos(mundo);
    //thanosPrueba->recorrerLista();
    //thanosPrueba->comandoThanos(65,-1);
    //qDebug() << thanosPrueba->eliminados;
    //qDebug() << "Thanos recorrer sirve";

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
