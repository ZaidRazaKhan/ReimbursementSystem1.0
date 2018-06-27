//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_SIMPLELOGGER_H
#define REIMBURSEMENTSYSTEM1_0_SIMPLELOGGER_H
#include<bits/stdc++.h>
#include<unistd.h>
//#include "LoginManager.h"
#include "DataBaseAccessLayer.h"
#include "AuthenticationManager.h"
#include "User.h"
#include "Credentials.h"
//#include "Application.h"
using namespace std;


class SimpleLogger: public AuthenticationManager {
public :
    Credentials userCred ;
    string s1,s2 ;
    User *usr;
    User* login();
};


#endif //REIMBURSEMENTSYSTEM1_0_SIMPLELOGGER_H
