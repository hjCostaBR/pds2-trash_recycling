#ifndef _DAO_CPP_
#define _DAO_CPP_

#include <exception>
#include "../../../header/common/class/DAO.h"

using namespace std;

const string DAO::STORAGE_DIR_PATH = "../storage/";

void DAO::closeStorage(bool writing) {

    if (writing && this->writingStream.is_open()) {
        this->writingStream.close();
        return;
    }

    if (!writing && this->readingStream.is_open()) {
        this->readingStream.close();
        return;
    }
}

void DAO::openStorageForWriting(void) {
    this->closeStorage(true);
    const string storageFile = this->getStorageFileName();
    this->writingStream.open(DAO::STORAGE_DIR_PATH + storageFile, ios::app);
    if (!this->writingStream.good()) throw runtime_error("Falha ao tentar abrir arquivo de armazenamento para escrita (" + storageFile + ")");
}

void DAO::openStorageForReading(void) {
    this->closeStorage(false);
    const string storageFile = this->getStorageFileName();
    this->readingStream.open(DAO::STORAGE_DIR_PATH + storageFile, ios::out);
    if (!this->writingStream.good()) throw runtime_error("Falha ao tentar abrir arquivo de armazenamento para leitura (" + storageFile + ")");
}

void DAO::deleteOne(const int line) {

    // Abre arquivos (permanente & temporario)
    this->openStorageForReading();
    const string tempFilePath = "temp.txt";
    ofstream tempFile;
    tempFile.open(tempFilePath, ios::out);

    // Transcreve armazenamento para arquivo temporario & remove linha
    string fileLine;
    int i = 0;

    while (getline(this->readingStream, fileLine)) {
        i++;
        if (i == line) continue;
        tempFile << fileLine << endl;
    }

    // Substitui armazenamento pelo arquivo temporario
    tempFile.close();
    this->closeStorage(false);

    const char* storageFile = this->getStorageFileName().c_str();
    remove(storageFile);
    rename(tempFilePath.c_str(), storageFile);
};

DAO::~DAO(void) {
    this->closeStorage(true);
    this->closeStorage(false);
}

#endif
