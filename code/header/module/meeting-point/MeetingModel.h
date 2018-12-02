#ifndef _MEETING_POINT_MODEL_H_
#define _MEETING_POINT_MODEL_H_

#include <string>

using namespace std;

class MeetingModel {

private:
    int code;
    string name;
    string cep;
    string state;
    string city;
    string neighborhood;
    string street;
    int number;
    string complement;
    

public:

    MeetingModel(void) {};


    // Codigo
    int getCode() const { return code; }
    void setCode(int code) { code = code; }

    // Nome
    const string &getName() const { return name; }
    void setName(const string &name) { name = name; }

    // Cep
    const string &getCep() const { return cep; }
    void setCep(const string &cep) { cep = cep; }

    // Estado
    const string &getState() const { return state; }
    void setState(const string &state) { state = state; }

    // Cidade
    const string &getCity() const { return city; }
    void setCity(const string &city) { city = city; }

    // Bairro
    const string &getNeighborhood() const { return neighborhood; }
    void setNeighborhood(const string &neighborhood) { neighborhood = neighborhood; }

    // Rua
    const string &getStreet() const { return street; }
    void setStreet(const string &street) { street = street; }

    // Numero
    int getNumber() const { return number; }
    void setNumber(int number) { number = number; }

    // Complemento
    const string &getComplement() const { return complement; }
    void setComplement(const string &complement) { complement = complement; }
};

#endif