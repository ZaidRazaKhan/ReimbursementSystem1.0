//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_NOTIFICATION_H
#define REIMBURSEMENTSYSTEM1_0_NOTIFICATION_H

#include<bits/stdc++.h>
#include<unistd.h>
#include "TripDetails.h"
using namespace std;
class Notification {
private:
    TripDetails tripDetails;
    bool status;
    string username;
public:
    string getUsername();
    Notification(TripDetails & trpDetail,string usrName,bool stat);
};


#endif //REIMBURSEMENTSYSTEM1_0_NOTIFICATION_H
