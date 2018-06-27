//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_APPLICATION_H
#define REIMBURSEMENTSYSTEM1_0_APPLICATION_H
#include<bits/stdc++.h>
#include<unistd.h>
#include<boost/python.hpp>
#include "User.h"
#include "NotificationManager.h"
#include "AuthenticationManager.h"
#include "RegistrationManager.h"
#include "SignUpManually.h"
#include "DataBaseAccessLayer.h"
#include <boost/python.hpp>
#include "SimpleLogger.h"
using namespace std;
using namespace boost::python;

class Application {
private :
    string currentPageType;
    string previousPageType;
    string adminPass;
    string tempForDebugging;
    User *usr;
    RegistrationManager * rm;
    DataBaseAccessLayer * dbal;
    SimpleLogger * lm;
    NotificationManager *Nm;
    set<string>usernameDatabase;
public:

    Application();
    /*void goToPage(string);
    void registerUser();
    void login() ;
    void loginAsAdmin() ;
    void resetPassword() ;
    void forgotPassword() ;
    void applyForReimbursement() ;
    void viewReimbursementInventory(string); /// string will be user or admin, for user, call fetchNotificationsForUser() else call fetchAllNotificationsForAdmin()
    void updateReimbursement(string);
    void cancelRequest() ;   /// i dont't know the use of this method ;
    */
    void start() ;

};



#endif //REIMBURSEMENTSYSTEM1_0_APPLICATION_H
