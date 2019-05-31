//
// Created by zaid on 14/6/18.
//

#include "User.h"
User :: User(){
    fstream ip("UsernameDatabase.txt") ;
    string tempUsername ;
    while(!ip.eof()) {
        ip >> tempUsername ;
        usernameDatabase.insert(tempUsername);
    }
    ip.close();
}

bool User :: isValidMobileNumber(string num) {
    /// check if all chars are between 0 and 9
    for(int i = 0 ; i < num.size() ; ++i ) if(!(num[i] >= '0' and num[i] <= '9')) return false; return (num.size() == 10) ;
}
/// make a contructor and load all theses details from the files

User :: User(bool flag) {				/// helps to register the new user
    flag1:cout << "Username : ";
    cin.ignore ();
    getline (cin, username, '\n');
    if (usernameDatabase.find (username) != usernameDatabase.end ())
    {
        cout << "Username already exists, enter a new username : " << endl;
        goto flag1;
    }
    cout << endl;
    cout << "Name : ";
    getline (cin, name, '\n');
    cout << endl;
    cout << "Password : ";
    getline (cin, password, '\n');
    cout << endl;
    cout << "Security question : ";
    getline (cin, securityQuestion, '\n');
    cout << endl;
    cout << "Answer to this question : ";
    getline (cin, securityAnswer, '\n');
    cout << endl;
    allowanceMoneyRemaining = MaxMoney;
    flag:cout << "Mobile number : ";
    getline (cin, mobileNumber, '\n');
    if (!isValidMobileNumber (mobileNumber))
    {
        cout << "Invalid mobile number \n";
        goto flag;
    }				/// store all these details in the database now, preferably file

}

void User :: setName(string nm){
    name = nm ;
}
string User :: getName(){
    return name;
}
void User :: setUsername(string nm){
    username = nm;
}
string User :: getUsername(){
    return username;
}
void User :: setPassword(string pass){
    password = pass;
}
string User :: getPassword(){
    return password;
}
void User :: setSecurityQuestion(string sQn){
    securityQuestion=sQn;
}
string User :: getSecurityQuestion(){
    return securityQuestion;
}
void User :: setSecurityAnswer(string seqAns){
    securityAnswer=seqAns;
}
string User :: getSecurityAnswer() {
    return securityAnswer;
}
void User :: setAllowanceMoneyRemaining(int allowanceMoneyRemainingUpdated){
    allowanceMoneyRemaining = allowanceMoneyRemainingUpdated;
}
int User :: getAllowanceMoneyRemaining(){
    return allowanceMoneyRemaining;
}


//Error handling must be used to check valid mobile Number
void User :: setMobileNumber(string mN){
    mobileNumber=mN;
}

string User :: getMobileNumber(){
    return mobileNumber;
}