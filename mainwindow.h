#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mundo.h"
#include "aniquilacion.h"
#include "salvacion.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Mundo * mundo;
    CorvusGlaive* structCorvus;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCrearPersonas_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
