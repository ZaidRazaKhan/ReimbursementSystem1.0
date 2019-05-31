//
// Created by zaid on 14/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_STUDENT_H
#define REIMBURSEMENTSYSTEM1_0_STUDENT_H

#include "User.h"
class Student: public User {
public:
    string rollNumber;
    char ugPgType;
    int year;
public:
    void setRollNumber(string rN);
    string getRollNumber();
    void setYear(int y);
    int getYear();
    string getPassword() ;
    Student (bool flag);
    Student(string fetchData);
    bool isValidRollNumber (string s);
};
#endif //REIMBURSEMENTSYSTEM1_0_STUDENT_H
