//
// Created by zaid on 15/6/18.
//

#include "SignUpManually.h"
void SignUpManually :: registration() {
    set<string>usernameDatabase;
    fstream ip("UsernameDatabase.txt") ;

    string tempUsername ;

    while(!ip.eof()) {
        ip >> tempUsername ;
        usernameDatabase.insert(tempUsername);
    }

    ip.close();

    int choice ;

    bool flag =true;
    User  *usr;

    while(flag){

        cout<<"Please enter the user type : "<<endl;

        cout<<"Press 1 for Student"<<endl;

        cout<<"Press 2 for Professor"<<endl;

        cout<<"Press 3 for Staff"<<endl;

        /// handle integer input for choice

        while(cout <<"enter choice : " and !(cin >> choice)) {

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Invalid input\n" ;
        }



        switch(choice) {
            case 1:
                cout<<"Here we go \n";

                usr = new Student(true);              /// update databse in registerStudent()

                flag=false;

                break;

            case 2:

                usr =  new Professor(true);           /// update database in registerPofessor();

                flag=false;

                break;

            case 3:

                usr = new Staff(true);             /// update database in registerStaff();

                flag = false;

                break;

            default:

                cout<<"Please enter valid entry"<<endl;

                break;
        }

        DataBaseAccessLayer * dataBasePtr = new DataBaseAccessLayer();

        dataBasePtr -> addUser(usr,choice) ;


    }


    return ;

}