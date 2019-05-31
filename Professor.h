//
// Created by zaid on 14/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_PROFESSOR_H
#define REIMBURSEMENTSYSTEM1_0_PROFESSOR_H


#include "User.h"

class Professor: public User {
public:
    string position;
    Professor(string t);
    Professor(bool flag);
    void setPosition(string pst);
    string getPosition();

};


#endif //REIMBURSEMENTSYSTEM1_0_PROFESSOR_H
