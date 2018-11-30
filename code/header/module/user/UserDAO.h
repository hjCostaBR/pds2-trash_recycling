#ifndef _USER_DAO_H_
#define _USER_DAO_H_

#include <memory>
#include "../../common/class/DAO.h"
#include "UserModel.h"
#include "UserService.h"


/**
 * DAO
 * Gerencia acesso a 'camada de dados' relacionados a entidade USUARIO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class UserDAO: public DAO {

private:

    /** Nome do arquivo de armqazenamento de dados de usuario. */
    static const string STORAGE_FILE;

    /** Classe de servico. */
    shared_ptr<UserService> service = nullptr;

protected:

    /**
     * @inherit
     */
    string getStorageFileName(void) override;

    /**
     * @inherit
     */
    shared_ptr<UserModel> getModelFromStorageLine(const vector<string> lineProps);

public:

    UserDAO(shared_ptr<UserService> service): service(service) {};

    /**
     * @inherit
     */
    shared_ptr<UserModel> insert(const shared_ptr<UserModel> model);

    /**
     * @inherit
     */
    shared_ptr<UserModel> update(const int code, const shared_ptr<UserModel> user);

    /**
     * Pesquisa & retorna 01 registro identificado pelo codigo OU cpf/cnpj.
     *
     * @param code Codigo
     * @param cpfCnpj
     * @return Instancia do objeto encontrado.
     */
    shared_ptr<UserModel> getExistingUser(const int code, const string cpfCnpj);
};

#endif