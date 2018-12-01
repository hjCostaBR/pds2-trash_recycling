#ifndef _DAO_H_
#define _DAO_H_

#include <vector>
#include <memory>
#include <fstream>
#include "../interface/IModel.h"

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
     * Remove 01 linha de 01 arquivo de texto.
     *
     * @param filePath
     * @param line
     */
    void deleteFileLine(const string filePath, const int line) {};

    /** Define & retorna nome do arquivo de armazenamento utilizado pela DAO. */
    virtual string getStorageFileName(void) = 0;

    /**
     * Transforma dados de 01 registro armazenado numa instancia do modelo gerido pela DAO.
     *
     * @param lineProps Propriedades do registro armazenado.
     * @return
     */
    virtual shared_ptr<IModel> getModelFromStorageLine(const vector<string> lineProps) const {};

public:

    DAO(void) {};
    ~DAO(void);

    /**
     * Implementa logica para insercao de novo registro.
     *
     * @param model Dados a serem inseridos.
     * @return Registro recem inserido.
     */
    virtual shared_ptr<IModel> insert(const shared_ptr<IModel> model) {};

    /**
     * Implementa logica para atualizacao 01 registro ja cadstrado.
     *
     * @param model Dados a serem persistidos.
     * @return Registro recem atualizado.
     */
    virtual shared_ptr<IModel> update(const shared_ptr<IModel> model) {};
};

#endif