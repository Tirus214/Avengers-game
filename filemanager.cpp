#include "filemanager.h"

/*void FileManager::escribir(QString name, QString arreglo[]){
    QFile file("C:/Archivos/" + name + ".txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return;
    QTextStream out(&file);
    out << array;
    file.flush();
    file.close();
}*/


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

    for(int i=0; i<arreglo->length(); i++){
        qDebug() << arreglo[i] + "\n";
    }
}
