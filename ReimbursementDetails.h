//
// Created by zaid on 15/6/18.
//

#ifndef REIMBURSEMENTSYSTEM1_0_REIMBURSEMENTDETAILS_H
#define REIMBURSEMENTSYSTEM1_0_REIMBURSEMENTDETAILS_H
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;


class ReimbursementDetails {
public:

    string username;

    string goingFrom;

    string goingTo;

    string purpose;

    string phase;

    int moneyNeeded;		/// add a field status here.

    string status;

public:
    ReimbursementDetails(){}
    ReimbursementDetails(string,string,string,string,string,int,string);

    string getUsername();

    string getGoingFrom();

    string getGoingTo();

    string getPurpose();

    string getPhase();

    int getMoneyNeeded();

    void printReimbursementDetails();

    void  setMoneyNeeded(int);

    void  setUsername(string);

    void  setGoingFrom(string);

    void  setGoingTo(string);

    void  setPurpose(string);

    void  setPhase(string);

};


#endif //REIMBURSEMENTSYSTEM1_0_REIMBURSEMENTDETAILS_H
