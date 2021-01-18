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
    qDebug() << "Sort pasa";
    mundo->imprimir();
    //mundo->llenarHeap(mundo->arbolHeap);
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
        //Ironman * ironmanPrueba = new Ironman(mundo);
        //ironmanPrueba->detonarBombas();
        Antman * antmanPrueba = new Antman(mundo);
        antmanPrueba->cantidadHormigas = 200;
        antmanPrueba->dejarFeromonas();
        mundo->contarMuertos();
        mundo->contarVivos();
    //Thanos * thanosPrueba = new Thanos(mundo);
    //thanosPrueba->recorrerLista();
    //thanosPrueba->comandoThanos(65,-1);
    //qDebug() << thanosPrueba->eliminados;
    //qDebug() << "Thanos recorrer sirve";


    qDebug() << mundo->arbolOrdenado->contadorNodos(mundo->arbolOrdenado->raiz);
}
