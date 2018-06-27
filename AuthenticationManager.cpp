//
// Created by zaid on 15/6/18.
//

#include "AuthenticationManager.h"

bool AuthenticationManager :: authenticateLoginDetails(Credentials userDetails){
    /// verifies the details from the database and returns true else returns false

    ///first check if such a uer even exists in databse

    fstream f;
    // cout << "Entered username frmo user : ";
    // cout << userDetails.username << endl ;

    f.open (userDetails.username + ".txt", fstream::in | fstream::out);

    if (!f)
    {
        /// in case no such username exits
        cout << "Invalid Username " << endl;
        return 0;
    }

    string storedPassword;
    //cin.ignore();//          as we already have one cin.ignore() in the getCredentials function.
    getline (f, storedPassword, '\n');
    getline (f, storedPassword, '\n');

    //storedPassword.erase(storedPassword.begin()+storedPassword.size()-1);

    f.close ();
    // cout <<"password from file : " <<storedPassword.size() << endl ;
    // cout << "password from user : " <<userDetails.password.size() << endl;

    return (storedPassword == userDetails.password);
}

/// no need of response string here
bool AuthenticationManager :: authenticateChangePasswordResponse(User currentUser , string response="")
{

    string responseFromUser, newPassword, confirmNewPassword;

    string securityQues = currentUser.getSecurityQuestion ();

    string securityAns = currentUser.getSecurityAnswer ();

    cout << "You invoked a password change request : " << endl <<
         "Please answer the security question : " << endl;

    int attempts = 0;

    while (1)
    {

        cout << securityQues << " : " << endl;

        cin >> responseFromUser;

        if (responseFromUser == securityAns)
        {

            cout << "Password change request approved : " << endl;

            flag:if (attempts >= 3)
        {
            cout <<
                 "Wrong attempts reached max allowed value, hence pass remains unchanged !"
                 << endl;
            return 0;
        }
            cout << "Enter new password " << endl;

            cin >> newPassword;

            cout << "Re-enter the password to confirm it :" << endl;

            cin >> confirmNewPassword;

            if (confirmNewPassword == newPassword)
            {
                /// upadte the newpassword for the user
                //  passwordDatabase[currentUser.username] = newPassword;
                cout << "Password succussfully updated " << endl;
                return 1;		/// password change response verified
            }
            else
            {

                cout << "The two passwords do not match !" << endl;

                goto flag;
            }

        }

        else
        {
            ++attempts;

            cout << "Wrong answer " << "You have " << 3 -
                                                      attempts << " left !" << endl;
        }
    }
    cout <<
         "Wrong attempts reached max allowed value, hence pass remains unchanged !"
         << endl;
    return 0;

}