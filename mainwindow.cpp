#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mundo = new Mundo();

    ui->setupUi(this);
    // No se puede escribir en la pantalla
    ui->txtPantalla->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCrearPersonas_clicked(){
    int num = ui->txfCrearPersonas->text().toInt();
    mundo->crearPersonas(num);
    mundo->imprimir();
//        Nebula * nebula = new Nebula(mundo);
//        nebula->randNodoArbol();
//        nebula->matarPersonas(nebula->nodoSeleccionado, nebula->nodoSeleccionado->persona->id);
//        qDebug() << "Muertos:" << mundo->contarMuertos();
//        qDebug() << "Vivos:" << mundo->contarVivos();
//        qDebug() << "After salvar";
//        Antman * antmanPrueba = new Antman(mundo);
//        antmanPrueba->cantidadHormigas = 15;
//        antmanPrueba->dejarFeromonas();
//        qDebug() << "Muertos:" << mundo->contarMuertos();
//        qDebug() << "Vivos:" << mundo->contarVivos();


}
