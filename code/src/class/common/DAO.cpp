#ifndef _DAO_CPP_
#define _DAO_CPP_

#include <exception>
#include "../../../header/common/DAO.h"

using namespace std;

const string DAO::STORAGE_DIR_PATH = "../storage/";

void DAO::closeStorage(bool input) {

    if (input && this->writingStream.is_open()) {
        this->writingStream.close();
        return;
    }

    if (!input && this->readingStream.is_open()) {
        this->readingStream.close();
        return;
    }
}

void DAO::openStorageForWriting(void) {
    this->closeStorage(true);
    const string storageFile = this->getStorageFileName();
    this->writingStream.open(DAO::STORAGE_DIR_PATH + storageFile, ios::in);
    if (!this->writingStream.good()) throw runtime_error("Falha ao tentar abrir arquivo de armazenamento para escrita (" + storageFile + ")");
}

void DAO::openStorageForReading(void) {
    this->closeStorage(false);
    const string storageFile = this->getStorageFileName();
    this->readingStream.open(DAO::STORAGE_DIR_PATH + storageFile, ios::out);
    if (!this->writingStream.good()) throw runtime_error("Falha ao tentar abrir arquivo de armazenamento para leitura (" + storageFile + ")");
}

DAO::~DAO(void) {
    this->closeStorage(true);
    this->closeStorage(false);
}

#endif
