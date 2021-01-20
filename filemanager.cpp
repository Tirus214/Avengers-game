#include "filemanager.h"

void FileManager::escribir(QString name, QStringList arreglo){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "No se pudo abrir el archivo " << name;
        return;
    }
    QTextStream out(&file);
    for (int i=0; i<arreglo.length(); i++) {
        QString line = arreglo[i];
        out << line;
        out << "\n";
    }
    file.flush();
    file.close();
}


void FileManager::leer(QString name, QString arreglo[]){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo abrir el archivo" << name;
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


void FileManager::leer2(QString name, QStringList arreglo){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo abrir el archivo" << name;
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        try {
            arreglo.append(line);
        }  catch (FileManager) {
            continue;
        }
    }
    file.close();
}
