#ifndef _CONTROLLER_CPP_
#define _CONTROLLER_CPP_

#include <iostream>
#include <string>
#include <functional>
#include "../../../header/common/class/Controller.h"

using namespace std;

void throwBadFunctionCall(void) const {
    throw bad_function_call("Chamada de metodo nao extendido por controller filho");
}

int Controller::getNumberFromStdIO(string presentationMsg, string invalidInputMsg) const {

    bool reapeat = false;
    bool tried = false;
    string readInput;
    int number;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << invalidInputMsg << "'" << readInput << "'!" << endl << endl;
        tried = true;

        // Captura entrada
        cout << presentationMsg << ": ";
        cin >> readInput;

        try {
            number = stoi(readInput);
            reapeat = false;

        } catch (exception error) {
            reapeat = true;
        }

    } while (reapeat);

    return number;
};

bool Controller::runAction(void) {
    this->throwBadFunctionCall();
};

bool Controller::runAction(const int action) {
    this->throwBadFunctionCall();
}

bool Controller::runAction(const int action, const shared_ptr<UserModel> currentUser) {
    this->throwBadFunctionCall();
}

#endif
