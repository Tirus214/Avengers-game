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
        Nebula * nebula = new Nebula(mundo);
        nebula->randNodoArbol();
        nebula->matarPersonas(nebula->nodoSeleccionado, nebula->nodoSeleccionado->persona->id);
        mundo->imprimir();
        mundo->imprimirPantalla(ui->txtPantalla);
//        qDebug() << "After salvar";
//        Antman * antmanPrueba = new Antman(mundo);
//        antmanPrueba->cantidadHormigas = 15;
//        antmanPrueba->dejarFeromonas();
//        qDebug() << "Muertos:" << mundo->contarMuertos();
//        qDebug() << "Vivos:" << mundo->contarVivos();


}

// Aniquilacion
void MainWindow::on_btnCorvusGlaive_clicked()
{
    return;
}


void MainWindow::on_btnMidnight_clicked()
{
    return;
}


void MainWindow::on_btnNebula_clicked()
{
    return;
}

void MainWindow::on_btnEbonyMaw_clicked()
{
    return;
}

void MainWindow::on_btnBlackDwarf_clicked()
{
    return;
}

void MainWindow::on_btnThanos_clicked()
{
    return;
}

// Salvacion

void MainWindow::on_btnAntMan_clicked()
{
    return;
}


void MainWindow::on_btnIronman_clicked()
{
    return;
}


void MainWindow::on_btnThor_clicked()
{
    return;
}


void MainWindow::on_btnSpiderman_clicked()
{
    return;
}

// Consultas
void MainWindow::on_btnConsultarHumano_clicked()
{
    int _id = ui->txfConsultarHumano->text().toInt();
}


void MainWindow::on_btnConsultarFamilia_clicked()
{
    int _id = ui->txfConsultarFamilia->text().toInt();
}


void MainWindow::on_btnConsultarAmigos_clicked()
{
    int _id = ui->txfConsultarAmigos->text().toInt();
}


void MainWindow::on_btnConsultarDeporte_clicked()
{
    QString deporte = ui->txfConsultarDeporte->text();
}

// Estadisticas

void MainWindow::on_btnHumanosVivos_clicked()
{
    return;
}

