//
// Created by zaid on 14/6/18.
//

#include "Staff.h"

Staff :: Staff(string t){}

Staff :: Staff(bool flag) {

    //User(true);
    /// helps to register the new user

    //flag1: cout << "Please enter the username : " << endl ;

    cin.ignore ();
    flag1:cout << "Username : ";
    getline (cin, username, '\n');

    if (usernameDatabase.find (username) != usernameDatabase.end ())
    {

        cout << "Username already exists, enter a new usernam : " << endl;

        goto flag1;
    }
    cout << endl;

    //cout<<"Please enter your name : "<<endl;

    cout << "Name : ";

    // cin.ignore();

    getline (cin, name, '\n');
    cout << endl;

    cout << "Password : ";

    //cin.ignore() ;

    getline (cin, password, '\n');
    cout << endl;

    cout << "Security question : ";

    // cin.ignore() ;

    getline (cin, securityQuestion, '\n');
    cout << endl;

    cout << "Answer to this question : ";

//               cin.ignore() ;

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

    cout << "Enter position : ";

    cin >> position;

    cout << endl;

}


void Staff :: setPosition(string pst) {
    position=pst;
}

string Staff :: getPosition(){
    return position;
}