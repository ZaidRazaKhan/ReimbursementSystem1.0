//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_DATABASEACCESSLAYER_H
#define REIMBURSEMENTSYSTEM1_0_DATABASEACCESSLAYER_H


#include<bits/stdc++.h>
#include<unistd.h>
#include "User.h"
#include "Student.h"
#include "Professor.h"
#include "Staff.h"
#include "ReimbursementDetails.h"
//#include "Application.h"
//#include "Validate.h"
using namespace std;
class DataBaseAccessLayer {
public:

    DataBaseAccessLayer();
    User *usr;
    set<string>usernameDatabase;
    void addUser(User*,int);
    User *fetchData(string);
    vector<ReimbursementDetails> fetchNotificationsForUser(string);
    vector<ReimbursementDetails> fetchAllNotificationsForAdmin();
    void updateNotification(ReimbursementDetails &Rd,int number);
    string itos(int n);
    int stoi_1(string s) ;
};


#endif //REIMBURSEMENTSYSTEM1_0_DATABASEACCESSLAYER_H
