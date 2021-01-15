#include "filemanager.h"

void FileManager::escribir(QString name, QString arreglo[]){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    int index = 0;
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        try {
            arreglo[index] = line;
            index++;
        }  catch (FileManager) {
            continue;
        }
    }
    file.close();
}


void FileManager::leer(QString name, QString arreglo[]){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    int index = 0;
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        try {
            arreglo[index] = line;
            index++;
        }  catch (FileManager) {
            continue;
        }
    }
    file.close();
}
