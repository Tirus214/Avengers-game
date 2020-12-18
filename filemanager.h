#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QApplication>


struct FileManager{

    FileManager(){}

    QString lectura(QString name);
};

#endif // FILEMANAGER_H
