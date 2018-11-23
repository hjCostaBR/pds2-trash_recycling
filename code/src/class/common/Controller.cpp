#ifndef _CONTROLLER_CPP_
#define _CONTROLLER_CPP_

#include <iostream>
#include <string>
#include "../../../header/common/Controller.h"

using namespace std;

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

#endif
