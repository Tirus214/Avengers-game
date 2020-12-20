#include "filemanager.h"

void FileManager::escribir(QString name){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return;
    QTextStream out(&file);
    out << stringArray;
    file.flush();
    file.close();
}


void FileManager::leer(QString name){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
}
