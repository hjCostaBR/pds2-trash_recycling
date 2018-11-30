#ifndef _DAO_H_
#define _DAO_H_

#include <memory>
#include <fstream>
#include "IModel.h"

/**
 * DAO
 * Clase generica a ser extendida por classes que implementem a funcao de DAO no sistema
 * Trash Recycling System
 *
 * @author hjcostabr
 */
class DAO {

protected:

    /** Path relativo a pasta da chamada para execuaco para a pasta de armazenamento. */
    static const string STORAGE_DIR_PATH;

    /** Arquivo de armazenamento de dados manipulados por esta DAO. */
    ofstream storageFile;

public:

    DAO(void) {};
    ~DAO(void) { storageFile.close(); };

    /**
     * Abre arquivo de armazenamento usado pela DAO.
     * @param filePath Path do arquivo.
     */
    virtual void openStorageFile(void) = 0;

    /**
     * Encapsula procedimento de inicializacao do controlador.
     *
     * @param model Dados a serem inseridos.
     * @return Registro recem inserido.
     */
    virtual shared_ptr<IModel> insert(const shared_ptr<IModel> model) {};
};

#endif