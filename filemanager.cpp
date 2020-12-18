#include "filemanager.h"

QString FileManager::lectura(QString name){
    QFile inputFile(name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
          QTextStream in(&inputFile);
          while (!in.atEnd())
          {
             QString line = in.readLine();
          }
          inputFile.close();
    }
}
