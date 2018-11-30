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

private:

    /**
     * Fecha o arquivo de armazenamento da DAO (SE estiver aberto).
     * @param input Flag: Determina se o stream a ser encerrado eh de leitura (SE nao for, sera de escrita).
     */
    void closeStorage(bool input);

protected:

    /** Path relativo a pasta da chamada para execuaco para a pasta de armazenamento. */
    static const string STORAGE_DIR_PATH;

    /** Strema de ESCRITA do arquivo de armazenamento desta DAO. */
    ofstream writingStream;

    /** Strema de LEITURA do arquivo de armazenamento desta DAO. */
    ifstream readingStream;

public:

    DAO(void) {};
    ~DAO(void);

    /** Define & retorna nome do arquivo de armazenamento utilizado pela DAO. */
    virtual string getStorageFileName(void) = 0;

    /**
     * Abre arquivo de armazenamento usado pela DAO para ESCRITA.
     * @param filePath Path do arquivo.
     */
    void openStorageForWriting(void);

    /**
     * Abre arquivo de armazenamento usado pela DAO para LEITURA.
     * @param filePath Path do arquivo.
     */
    void openStorageForReading(void);

    /**
     * Encapsula procedimento de inicializacao do controlador.
     *
     * @param model Dados a serem inseridos.
     * @return Registro recem inserido.
     */
    virtual shared_ptr<IModel> insert(const shared_ptr<IModel> model) {};
};

#endif