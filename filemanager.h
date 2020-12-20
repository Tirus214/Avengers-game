#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QApplication>
#include <QDebug>


struct FileManager{
    QString stringArray;

    FileManager(){
        stringArray = "";
    }

    void leer(QString name);
    void escribir(QString name);
};

#endif // FILEMANAGER_H
