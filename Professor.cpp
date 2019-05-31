//
// Created by zaid on 14/6/18.
//

#include "Professor.h"
Professor :: Professor(string t){}

Professor :: Professor(bool flag){
    cin.ignore ();
    flag1:cout << "Username : ";
    getline (cin, username, '\n');

    if (usernameDatabase.find (username) != usernameDatabase.end ())
    {
        cout << "Username already exists, enter a new usernam : " << endl;
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
    getline (cin, mobileNumber, '\n');\
    if (!isValidMobileNumber (mobileNumber))
    {
        cout << "Invalid mobile number \n";\
	goto flag;
    }				/// store all these details in the database now, preferably file
    cout << "Enter your position : ";
    cin >> position;
    cout << endl;
}
void Professor :: setPosition(string pst){
    position=pst;
}

string Professor :: getPosition(){
    return position;
}
