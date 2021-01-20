#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mundo.h"
#include "aniquilacion.h"
#include "salvacion.h"
#include "log.h"
#include <QMainWindow>
#include "consultas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Mundo * mundo;
    // aniquilacion
    CorvusGlaive* structCorvus;
    Nebula* nebula;
    Dwarf* dwarf;
    Thanos* thanos;
    Midnight* midnight;
    //  salvacion
    Antman* antman;
    Ironman* ironman;
    Thor* thor;
    Spiderman* spiderman;
    // consultas
    Consultas* consultas;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCrearPersonas_clicked();

    void on_btnLog_clicked();

    void on_btnCorvusGlaive_clicked();

    void on_btnMidnight_clicked();

    void on_btnNebula_clicked();

    void on_btnEbonyMaw_clicked();

    void on_btnBlackDwarf_clicked();

    void on_btnThanos_clicked();

    void on_btnAntMan_clicked();

    void on_btnIronman_clicked();

    void on_btnThor_clicked();

    void on_btnSpiderman_clicked();

    void on_btnConsultarHumano_clicked();

    void on_btnConsultarFamilia_clicked();

    void on_btnConsultarAmigos_clicked();

    void on_btnConsultarDeporte_clicked();

    void on_btnHumanosVivos_clicked();

    void on_btnHumanosMuertos_clicked();

    void on_btnHumanosSalvados_clicked();

    void on_btnImprimirArbol_clicked();

    void on_btnTerminar_clicked();

    void on_btnVisualizar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
