#ifndef _USER_DAO_H_
#define _USER_DAO_H_

#include "../../common/DAO.h"
#include "UserModel.h"


/**
 * DAO
 * Gerencia acesso a 'camada de dados' relacionados a entidade USUARIO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class UserDAO: public DAO {

public:

    UserDAO() {};

    /**
     * @inherit
     */
    UserModel insert(const UserModel model) override;
};

#endif