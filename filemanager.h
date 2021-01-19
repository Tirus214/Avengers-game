#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QApplication>
#include <QDebug>


struct FileManager{
    QStringList array;

    FileManager(){
    }

    void leer(QString name, QString arreglo[]);
    void escribir(QString name, QStringList arreglo);
    void leer2(QString name, QStringList arreglo);
};

#endif // FILEMANAGER_H
