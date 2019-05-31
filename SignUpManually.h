//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_SIGNUPMANUALLY_H
#define REIMBURSEMENTSYSTEM1_0_SIGNUPMANUALLY_H
#include<bits/stdc++.h>
#include<unistd.h>
#include "RegistrationManager.h"
#include "Application.h"
#include "Student.h"
#include "Professor.h"
#include "Staff.h"
using namespace std;

class SignUpManually: public RegistrationManager {
public:
    void registration();
};


#endif //REIMBURSEMENTSYSTEM1_0_SIGNUPMANUALLY_H
