#ifndef _REJECTTYPE_MODEL_H_
#define _REJECTTYPE_MODEL_H_

#include <string>

using namespace std;

class RejectTypeModel {

private:
    int code;
    string name;
    string storageSpecification;

public:
    RejectTypeModel(void) {};

    // Codigo
    void setCode(int code);
    int getCode(void);

    // Nome
    void setName(string name);
    string getName(void);

    // Instrucoes de armazenamento
    void setStorageSpecification(string specification);
    string getStorageSpecification(void);
};

#endif