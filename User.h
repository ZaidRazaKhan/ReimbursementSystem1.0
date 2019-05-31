//
// Created by zaid on 14/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_USER_H
#define REIMBURSEMENTSYSTEM1_0_USER_H
#include<bits/stdc++.h>
#include<unistd.h>
#include<cstdlib>
using namespace std;
#define MaxMoney 15000
class User {
public:
public:
    string username;
    string name;
    string password;
    string securityQuestion;
    string securityAnswer;
    int allowanceMoneyRemaining;
    string mobileNumber;
    set<string>usernameDatabase;
public:
    User();
    User(bool);
    void setName(string nm);
    string getName();
    void setUsername(string nm);
    string getUsername();
    void setPassword(string pass);
    string getPassword();
    void setSecurityQuestion(string sQn);
    string getSecurityQuestion();
    void setSecurityAnswer(string seqAns);
    string getSecurityAnswer() ;
    void setAllowanceMoneyRemaining(int allowanceMoneyRemainingUpdated);
    int getAllowanceMoneyRemaining();
    void setMobileNumber(string mN);
    string getMobileNumber();
    bool isValidMobileNumber(string num);
};


#endif //REIMBURSEMENTSYSTEM1_0_USER_H
