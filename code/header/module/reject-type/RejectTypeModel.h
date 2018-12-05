#ifndef _REJECTTYPE_MODEL_H_
#define _REJECTTYPE_MODEL_H_

#include <string>

using namespace std;

class RejectTypeModel {

private:
    int code = 0;
    string name = "";
    string storageSpecification = "";

public:
    RejectTypeModel(void) {};

    // Codigo
    int getCode() const { return code; }
    void setCode(int code) { RejectTypeModel::code = code; }

    // Nome
    const string getName() const { return name; }
    void setName(const string name) { RejectTypeModel::name = name; }

    // Instrucoes de armazenamento
    const string getStorageSpecification() const { return storageSpecification; }
    void setStorageSpecification(const string storageSpecification) { RejectTypeModel::storageSpecification = storageSpecification; }
};

#endif