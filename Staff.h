//
// Created by zaid on 14/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_STAFF_H
#define REIMBURSEMENTSYSTEM1_0_STAFF_H


#include "User.h"

class Staff: public User {
public:
    string position;
    Staff(string t);
    Staff(bool flag);
    void setPosition(string pst);
    string getPosition();
};


#endif //REIMBURSEMENTSYSTEM1_0_STAFF_H
