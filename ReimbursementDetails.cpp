//
// Created by zaid on 15/6/18.
//

#include "ReimbursementDetails.h"

ReimbursementDetails :: ReimbursementDetails(string a,string b,string c,string d,string e, int f,string g) {
    username = a;
    goingFrom = b ;
    goingTo = c ;
    purpose = d ;
    phase = e ;
    moneyNeeded = f;
    status = g ;
}

void ReimbursementDetails :: printReimbursementDetails() {
    cout <<"------------------------------------"<<endl;
    cout << "Username : "                    	 << username << endl;
    cout << "Going From : "                  	 << goingFrom << endl ;
    cout <<"Going To : "                     	 << goingTo << endl;
    cout << "Purpose : "                     	 << purpose << endl ;
    cout << "Phase : "                       	 << phase << endl ;
    cout << "Money Needed : "                	 <<moneyNeeded <<endl ;
    cout << "Status of reimbursement request : " <<status << endl ;
    cout <<"------------------------------------" << endl ;
    return ;
}

string ReimbursementDetails ::  getPhase() {
    return phase;
}

string ReimbursementDetails ::  getUsername() {
    return username;
}

string ReimbursementDetails ::  getGoingFrom() {
    return goingFrom;
}

string ReimbursementDetails ::  getGoingTo() {
    return goingTo;
}

string ReimbursementDetails :: getPurpose() {
    return purpose;
}

int ReimbursementDetails ::  getMoneyNeeded() {
    return moneyNeeded;
}

void ReimbursementDetails ::  setPhase(string ph) {
    phase = ph ;
}

void ReimbursementDetails ::  setUsername(string usnm) {
    username = usnm ;
}

void ReimbursementDetails ::  setGoingFrom(string gf) {
    goingFrom = gf ;
}

void ReimbursementDetails ::  setGoingTo(string gt) {
    goingTo = gt;
}

void ReimbursementDetails :: setPurpose(string prps) {
    purpose = prps ;
}

void ReimbursementDetails ::  setMoneyNeeded(int mn) {
    moneyNeeded = mn ;
}