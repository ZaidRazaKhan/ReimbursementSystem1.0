//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_AUTHENTICATIONMANAGER_H
#define REIMBURSEMENTSYSTEM1_0_AUTHENTICATIONMANAGER_H

#include<bits/stdc++.h>
#include<unistd.h>
#include "Credentials.h"
#include "User.h"
using namespace std;
class AuthenticationManager {
public :

    bool authenticateLoginDetails(Credentials);
    bool authenticateChangePasswordResponse(User currentUser,string);  /// if user wants to change the password, then this function asks the user for the answer of security quesiton atmist 3 times
    /// application class mein 3 chcks for password

};


#endif //REIMBURSEMENTSYSTEM1_0_AUTHENTICATIONMANAGER_H
