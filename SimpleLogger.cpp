//
// Created by zaid on 15/6/18.
//

#include "SimpleLogger.h"
User* SimpleLogger :: login() {
    int attempts = 0 ;

//User *usr;
    while(1) {

        flag : if(attempts >= 3) {
        cout << "Max attempts reached, login failed ! \n";
        /// return back to homepage
        return NULL;
    }

        userCred.getCredentials(s1, s2) ;

        bool isExistingUser = authenticateLoginDetails(userCred) ;

        if(isExistingUser) {
            cout << "successfully logging in ... \n";

            DataBaseAccessLayer *dbal = new DataBaseAccessLayer();
            //cout<<userCred.username<<endl;
            //User usr1;
            //(*usr)
            usr= dbal->fetchData(userCred.username);
            //cout<<"Hello there"<<endl;
            // cout << "hello world\n";
            return usr;
            /// open the dashboard for the user now
        }

        else {

            cout << "Wrong username or password !, you have " << 3 - attempts <<" remaining " << endl;
            system("clear") ;
            ++ attempts ; goto flag ;
        }

    }
}