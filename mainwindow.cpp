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
    ui->txtPantalla->clear();
    //aqui va la aniquilacion

    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

void MainWindow::on_btnThanos_clicked()
{
    ui->txtPantalla->clear();
    //aqui va la aniquilacion

    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

// Salvacion

void MainWindow::on_btnAntMan_clicked()
{
    ui->txtPantalla->clear();
    //aqui va la salvacion

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnIronman_clicked()
{
    ui->txtPantalla->clear();
    //aqui va la salvacion

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnThor_clicked()
{
    ui->txtPantalla->clear();
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
}


void MainWindow::on_btnConsultarFamilia_clicked()
{
    ui->txtPantalla->clear();
    int _id = ui->txfConsultarFamilia->text().toInt();
    consultas->consultarFamilia(_id,ui->txtPantalla);
}


void MainWindow::on_btnConsultarAmigos_clicked()
{
    ui->txtPantalla->clear();
    int _id = ui->txfConsultarAmigos->text().toInt();
}


void MainWindow::on_btnConsultarDeporte_clicked()
{
    ui->txtPantalla->clear();
    QString deporte = ui->txfConsultarDeporte->text();
}

// Estadisticas

void MainWindow::on_btnHumanosVivos_clicked()
{
    ui->txtPantalla->clear();
    return;
}


void MainWindow::on_btnHumanosMuertos_clicked()
{
    ui->txtPantalla->clear();
    return;
}


void MainWindow::on_btnHumanosSalvados_clicked()
{
    ui->txtPantalla->clear();
    return;
}


void MainWindow::on_btnImprimirArbol_clicked()
{
    ui->txtPantalla->clear();
    return;
}

void MainWindow::on_btnLog_clicked()
{
    ui->txtPantalla->clear();
    return;
}

void MainWindow::on_pushButton_clicked()
{
    ui->txtPantalla->clear();
    ui->txtPantalla->appendPlainText("\nCantidad de nodos: " + QString::number(mundo->arbolOrdenado->contadorNodos(mundo->arbolOrdenado->raiz)));
}


void MainWindow::on_btnVisualizar_clicked(){
    ui->txtPantalla->clear();
    if(!mundo->listaPersonas->isEmpty())
        ui->txtPantalla->setPlainText(mundo->getStringArbol());
}









