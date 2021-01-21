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
    // consultas
    consultas = new Consultas(mundo);
    // villanos
    structCorvus = new CorvusGlaive(mundo);
    _nebula = new Nebula(mundo);
    ebony = new EbonyMaw(mundo);
    _thanos = new Thanos(mundo);
    _midnight = new Midnight(mundo);
    _dwarf = new Dwarf(mundo);
    // heroes
    _thor = new Thor(mundo);
    _spiderman = new Spiderman(mundo);
    _antman = new Antman(mundo);
    _ironman = new Ironman(mundo);

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
    structCorvus->contadorUltimaCorrida = 0;
    structCorvus->matarPersonas();
    ui->txtPantalla->appendPlainText("\n================== CORVUS GLAIVE ==================");
    // falta imprimir el mas pecador
    ui->txtPantalla->appendPlainText("Cantidad de personas eliminadas: " + QString::number(structCorvus->contadorUltimaCorrida) + "\n" + "Total de personas elimandas por Corvus Glaive: " + QString::number(structCorvus->contador) + "\n");
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}


void MainWindow::on_btnMidnight_clicked()
{
    _midnight->contadorUltimaCorrida = 0;
    mundo->llenarHeap(_midnight->heap);
    _midnight->recorrerHeap();
    _midnight->matarPersonas();
    ui->txtPantalla->appendPlainText("\n================== MIDNIGHT ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas eliminadas: " + QString::number(_midnight->contadorUltimaCorrida) + "\n" + "Total de personas eliminadas por Midnight: " + QString::number(_midnight->contador) + "\n");
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}


void MainWindow::on_btnNebula_clicked()
{
    _nebula->contadorUltimaCorrida = 0;
    _nebula->tamanoArbol = mundo->arbolOrdenado->contadorNodos(mundo->arbolOrdenado->raiz);
    _nebula->nodoSeleccionado = _nebula->randNodoArbol();
    _nebula->matarPersonas(_nebula->nodoSeleccionado,_nebula->listaEliminados, _nebula->nodoSeleccionado->persona->id);
    ui->txtPantalla->appendPlainText("\n================== NEBULA ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas elimanadas: " + QString::number(_nebula->contadorUltimaCorrida) + "\n" + "Total de personas eliminadas por Nebula: " + QString::number(_nebula->contador) + "\n");
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

void MainWindow::on_btnEbonyMaw_clicked()
{
    ebony->listaIDAniquilados.clear();
    ebony->contadorUltimaCorrida = 0;
    NodoDoble* nodo = mundo->listaPersonas->buscarEnPosicion(mundo->aleatorio(0,mundo->listaPersonas->index-1));
    Persona* personaRandom = nodo->persona;
    ebony->matarAscendentes(personaRandom);
    ebony->matarDescendentes(personaRandom);
    ui->txtPantalla->appendPlainText("  Ebony Maw\nPersona seleccionada: [" + QString::number(personaRandom->id)+"] Nombre: " + personaRandom->nombre);
    ui->txtPantalla->appendPlainText("Cantidad de parientes eliminados: " + QString::number(ebony->contadorUltimaCorrida));
    ui->txtPantalla->appendPlainText("Cantidad de personas eliminadas por Ebony Maw: " + QString::number(ebony->contador));
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
    _dwarf->contadorUltimaCorrida = 0;
    _dwarf->deporteSeleccionado = deporte;
    _dwarf->deporteRepeticiones = frecuencia;
    _dwarf->matarPersonas();
    ui->txtPantalla->appendPlainText("\n================== BLACK DWARF ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas elimandas: " + QString::number(_dwarf->contador) + "\n" + "Total de personas eliminadas por Black Dwarf: " + QString::number(_dwarf->contadorUltimaCorrida) + "\n");
    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

void MainWindow::on_btnThanos_clicked()
{
    int nivelHash = QInputDialog::getInt(this,"Thanos","Ingrese el nivel del Hash",0,-1,9,1);
    int edad = QInputDialog::getInt(this,"Thanos","Ingrese la edad",0,-1,70,1);
    ui->txtPantalla->appendPlainText("Nivel: " + QString::number(nivelHash) + " Edad: " + QString::number(edad));
    if (nivelHash == -1 && edad == -1) {
        ui->txtPantalla->appendPlainText("Error, los dos valores son -1");
    } else {
        _thanos->recorrerLista();
        _thanos->comandoThanos(edad,nivelHash);
    }

    mundo->fileManager->escribir("LogMuertes", mundo->logMuertes->historico);
    mundo->fileManager->leer2("LogMuertes", mundo->logMuertes->historico);
    return;
}

// Salvacion

void MainWindow::on_btnAntMan_clicked()
{
    int cantidadHormigas = QInputDialog::getInt(this,"Ant Man","Ingrese la cantidad de hormigas",0,0,500,1);
    ui->txtPantalla->appendPlainText("Cantidad de hormigas: " + QString::number(cantidadHormigas));
    _antman->contadorUltimaCorrida = 0;
    _antman->cantidadHormigas = cantidadHormigas;
    _antman->dejarFeromonas(mundo->arbolOrdenado->raiz);
    ui->txtPantalla->appendPlainText("\n================== ANT MAN ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas salvadas: " + QString::number(_antman->contador) + "\n" + "Total de personas salvadas por Ant Man: " + QString::number(_antman->contadorUltimaCorrida) + "\n");
    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnIronman_clicked()
{
    _ironman->contadorUltimaCorrida = 0;
    _ironman->detonarBombas();
    ui->txtPantalla->appendPlainText("\n================== IRONMAN ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas salvadas: " + QString::number(_ironman->contador) + "\n" + "Total de personas salvadas por Ironman: " + QString::number(_ironman->contadorUltimaCorrida) + "\n");

    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnThor_clicked()
{
    int nivel = QInputDialog::getInt(this,"Thor","Ingrese el nivel",0,0,mundo->arbolOrdenado->altura(mundo->arbolOrdenado->raiz));
    ui->txtPantalla->appendPlainText("Nivel : " + QString::number(nivel));
    _thor->contadorUltimaCorrida = 0;
    _thor->obtenerNodoPorNivel(mundo->arbolOrdenado->raiz,0,nivel);
    ui->txtPantalla->appendPlainText("\n================== THOR ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas salvadas: " + QString::number(_thor->contador) + "\n" + "Total de personas salvadas por Thor: " + QString::number(_thor->contadorUltimaCorrida) + "\n");
    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

void MainWindow::on_btnSpiderman_clicked()
{
    _spiderman->contadorUltimaCorrida = 0;
    _spiderman->crearTela();
    ui->txtPantalla->appendPlainText("\n================== SPIDERMAN ==================");
    ui->txtPantalla->appendPlainText("Cantidad de personas salvadas: " + QString::number(_spiderman->contador) + "\n" + "Total de personas salvadas por Spiderman: " + QString::number(_spiderman->contadorUltimaCorrida) + "\n");
    mundo->fileManager->escribir("LogSalvacion", mundo->logSalvacion->historico);
    mundo->fileManager->leer2("LogSalvacion", mundo->logSalvacion->historico);
    return;
}

// Consultas
void MainWindow::on_btnConsultarHumano_clicked()
{
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
    return;
}

void MainWindow::on_btnLog_clicked()
{

    return;
}

void MainWindow::on_pushButton_clicked()
{
    ui->txtPantalla->appendPlainText("\nCantidad de nodos: " + QString::number(mundo->arbolOrdenado->contadorNodos(mundo->arbolOrdenado->raiz)));
    return;
}


void MainWindow::on_btnVisualizar_clicked(){
    if(!mundo->listaPersonas->isEmpty())
        ui->txtPantalla->setPlainText(mundo->getStringArbol());
    return;
}









