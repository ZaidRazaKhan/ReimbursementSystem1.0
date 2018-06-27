//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_NOTIFICATIONMANAGER_H
#define REIMBURSEMENTSYSTEM1_0_NOTIFICATIONMANAGER_H

#include<bits/stdc++.h>
#include<unistd.h>
#include "TripDetails.h"
#include "Notification.h"
#include "ReimbursementDetails.h"
using namespace std;

class NotificationManager {
public:
    void sendNotification(TripDetails &trp,Notification nm);
    void deleteNotification(Notification nm);
    void editNotification();
    string itos(int n);
    int stoi_1(string s);
};


#endif //REIMBURSEMENTSYSTEM1_0_NOTIFICATIONMANAGER_H
