#ifndef _USER_DAO_H_
#define _USER_DAO_H_

#include <memory>
#include "UserModel.h"
#include "../../common/DAO.h"


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

public:

    UserDAO(void) {};

    /**
     * @inherit
     */
    string getStorageFileName(void) override;

    /**
     * @inherit
     */
    shared_ptr<UserModel> insert(const shared_ptr<UserModel> model);
};

#endif