#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

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
    structCorvus = new CorvusGlaive(mundo);
    _nebula = new Nebula(mundo);
    consultas = new Consultas(mundo);
    //mundo->imprimir();
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
    ui->txtPantalla->clear();
    structCorvus->matarPersonas();
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}


void MainWindow::on_btnMidnight_clicked()
{
    ui->txtPantalla->clear();
    //aqui va la aniquilacion

    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}


void MainWindow::on_btnNebula_clicked()
{
    ui->txtPantalla->clear();
    _nebula->tamanoArbol = mundo->arbolOrdenado->contadorNodos(mundo->arbolOrdenado->raiz);
    _nebula->nodoSeleccionado = _nebula->randNodoArbol();
    _nebula->matarPersonas(_nebula->nodoSeleccionado,_nebula->listaEliminados, _nebula->nodoSeleccionado->persona->id);
    ui->txtPantalla->appendPlainText("Cantidad de muertos: " + QString::number(mundo->contarMuertos()));
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

void MainWindow::on_btnEbonyMaw_clicked()
{
    ui->txtPantalla->clear();
    //aqui va la aniquilacion

    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

void MainWindow::on_btnBlackDwarf_clicked()
{

    //aqui va la aniquilacion
    QString deporte = QInputDialog::getText(this,"Black Dwarf","Ingrese el deporte");
        int frecuencia = QInputDialog::getInt(this,"Black Dwarf","Ingrese la frecuencia",0,0,7,1);
        ui->txtPantalla->appendPlainText("Deporte: " + deporte + " Frecuencia: " + QString::number(frecuencia));
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

void MainWindow::on_btnThanos_clicked()
{
    int nivelArbol = QInputDialog::getInt(this,"Thanos","Ingrese el nivel del arbol",0,-1,9,1);
        int edad = QInputDialog::getInt(this,"Thanos","Ingrese la edad",0,-1,70,1);
        ui->txtPantalla->appendPlainText("Nivel: " + QString::number(nivelArbol) + " Edad: " + QString::number(edad));
    //aqui va la aniquilacion

    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

// Salvacion

void MainWindow::on_btnAntMan_clicked()
{
    int cantidadHormigas = QInputDialog::getInt(this,"Ant Man","Ingrese la cantidad de hormigas",0,0,500,1);
       ui->txtPantalla->appendPlainText("Cantidad de hormigas: " + QString::number(cantidadHormigas));
    //aqui va la salvacion

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnIronman_clicked()
{

    //aqui va la salvacion

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnThor_clicked()
{
    int alturaArbol = mundo->arbolOrdenado->obtenerAltura(mundo->arbolOrdenado->raiz) - 1;
        int nivel = QInputDialog::getInt(this,"Thor","Ingrese el nivel",0,0,alturaArbol,1);
        ui->txtPantalla->appendPlainText("Nivel : " + QString::number(nivel));
    //aqui va la salvacion

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnSpiderman_clicked()
{
    ui->txtPantalla->clear();
    //aqui va la salvacion

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

// Consultas
void MainWindow::on_btnConsultarHumano_clicked()
{
    ui->txtPantalla->clear();
    int _id = ui->txfConsultarHumano->text().toInt();
    consultas->consultarPersona(_id,ui->txtPantalla);
    return;
}


void MainWindow::on_btnConsultarFamilia_clicked()
{

    int _id = ui->txfConsultarFamilia->text().toInt();
    consultas->consultarFamilia(_id,ui->txtPantalla);
    return;
}


void MainWindow::on_btnConsultarAmigos_clicked()
{
    int _id = ui->txfConsultarAmigos->text().toInt();
    consultas->consultarAmigos(_id,ui->txtPantalla);
    return;
}


void MainWindow::on_btnConsultarDeporte_clicked()
{

    QString deporte = ui->txfConsultarDeporte->text();
    consultas->consultarDeporte(deporte,ui->txtPantalla);
    return;
}

// Estadisticas

void MainWindow::on_btnHumanosVivos_clicked()
{
    consultas->consultarHumanosVivos(ui->txtPantalla);
    return;
}


void MainWindow::on_btnHumanosMuertos_clicked()
{
    consultas->consultarHumanosMuertos(ui->txtPantalla);
    return;
}


void MainWindow::on_btnHumanosSalvados_clicked()
{
    consultas->consultarHumanosSalvados(ui->txtPantalla);
    return;
}


void MainWindow::on_btnImprimirArbol_clicked()
{
    ui->txtPantalla->clear();
    return;
}

void MainWindow::on_btnLog_clicked()
{

    return;
}

void MainWindow::on_pushButton_clicked()
{
    ui->txtPantalla->appendPlainText("\nCantidad de nodos: " + QString::number(mundo->arbolOrdenado->contadorNodos(mundo->arbolOrdenado->raiz)));
}


void MainWindow::on_btnVisualizar_clicked(){
    if(!mundo->listaPersonas->isEmpty())
        ui->txtPantalla->setPlainText(mundo->getStringArbol());
}









