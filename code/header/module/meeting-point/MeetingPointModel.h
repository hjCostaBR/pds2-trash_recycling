#ifndef _MEETINGPOINT_MODEL_H_
#define _MEETINGPOINT_MODEL_H_

#include <string>

using namespace std;

class MeetingPointModel {

private:
    int code = 0;
    string name = "";
    string cep = "";
    string state = "";
    string city = "";
    string neighborhood = "";
    string street = "";
    int number = 0;
    string complement = "";
    

public:

    MeetingPointModel(void) {};


    // Codigo
    int getCode() const { return this->code; }
    void setCode(int code) { this->code = code; }

    // Nome
    const string getName() const { return this->name; }
    void setName(const string name) { this->name = name; }

    // Cep
    const string getCep() const { return this->cep; }
    void setCep(const string cep) { this->cep = cep; }

    // Estado
    const string getState() const { return this->state; }
    void setState(const string state) { this->state = state; }

    // Cidade
    const string getCity() const { return this->city; }
    void setCity(const string city) { this->city = city; }

    // Bairro
    const string getNeighborhood() const { return this->neighborhood; }
    void setNeighborhood(const string neighborhood) { this->neighborhood = neighborhood; }

    // Rua
    const string getStreet() const { return this->street; }
    void setStreet(const string street) { this->street = street; }

    // Numero
    int getNumber() const { return this->number; }
    void setNumber(int number) { this->number = number; }

    // Complemento
    const string getComplement() const { return this->complement; }
    void setComplement(const string complement) { this->complement = complement; }
};

#endif