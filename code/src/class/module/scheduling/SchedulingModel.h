#ifndef _SCHEDULING_MODEL_H_
#define _SCHEDULING_MODEL_H_

#include <string>
#include <vector>

#include "../reject-type/RejectTypeModel.h"
#include "../user/UserModel.h"
#include "../../meeting-point/MeetingPointModel/MeetingPointModel.h"

using namespace std;

class SchedulingModel
{
private:
    int code;
    string date;
    string time;
    MeetingPointModel meetingPoint;
    UserModel donator;
    UserModel receiver;
    vector<RejectTypeModel> rejectsToBeExchanged;
    boolean done;

public:
    SchedulingModel(void){};
    // ~SchedulingModel() {};

    // Codigo
    void setCode(int code);
    int getCode(void);

    // Data
    void setDate(string date);
    string getDate(void);

    // Horario
    void setTime(string time);
    string getTime(void);

    // Ponto de Coleta
    void setMeetingPointModel(MeetingPointModel meetingPoint);
    MeetingPointModel getMeetingPointModel(void);

    // Doador
    void setDonator(UserModel donator);
    UserModel getDonator(void);

    // Recebedor
    void setReceiver(UserModel receiver);
    UserModel getReceiver(void);

    // Residuos a serem trocados
    void resetRejectsToBeExchanged(void);
    void addRejectToBeExchanged(RejectTypeModel rejectToBeExchanged);
    vector<RejectTypeModel> getRejectsToBeExchanged(void);

    // Flag: Realizado?
    void setIsDone(bool done);
    bool isDone(void);
};

#endif