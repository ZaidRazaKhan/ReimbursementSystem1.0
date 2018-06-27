//
// Created by zaid on 14/6/18.
//

#include "Student.h"

void Student :: setRollNumber(string rN){
    rollNumber=rN;
}

string Student :: getRollNumber(){
    return rollNumber;
}

void Student :: setYear(int y){
    year=y;
}

bool Student :: isValidRollNumber (string s)
{
    if (s.size () != 8)
        return 0;
    char a = s[0];
    if (!(a == 'B' or a == 'b' or a == 'P' or a == 'p' or a == 'M' or a == 'm'))
        return 0;
    int num = (s[1] - '0') * 10 + s[2] - '0';
    if (!(num >= 8 and num <= 18))
        return 0;
    if (!((s[3] >= 'a' and s[4] <= 'z') or (s[3] >= 'A' and s[4] <= 'Z')))
        return 0;
    char b = s[s.size () - 3], c = s[s.size () - 2], d = s[s.size () - 1];
    if (!
            (b >= '0' and b <= '9' and c >= '0' and c <= '9' and d >= '0' and d <= '9'))
        return 0;
    return 1;
}

int Student :: getYear(){
    return year;
}

Student :: Student (bool flag) {
    cin.ignore ();
    flag1:cout << "Username : ";
    getline (cin, username, '\n');
    if (usernameDatabase.find (username) != usernameDatabase.end ())
    {
        cout <<
             "This username already exists in database, enter another username : "
             << endl;
        goto flag1;
    }
    cout << "Name : ";
    getline (cin, name, '\n');
    cout << "Password : ";
    getline (cin, password, '\n');
    cout << "Security question : ";
    getline (cin, securityQuestion, '\n');
    cout << "Answer to this question : ";
    getline (cin, securityAnswer, '\n');
    allowanceMoneyRemaining = MaxMoney;
    flag:cout << "Mobile number : ";
    getline (cin, mobileNumber, '\n');
    if (!isValidMobileNumber (mobileNumber))
    {
        cout << "Invalid mobile number \n";
        goto flag;
    }				/// store all these details in the database now, preferably file

    flag_2:cout << "RollNumber (like B16CS020 or M17CS051) : ";
    getline (cin, rollNumber, '\n');
    if (!isValidRollNumber (rollNumber))
    {
        cout << "Invalid format, please enter as suggested \n";
        goto flag_2;
    }
    /// validate the roll number
    cout << "Please enter the year you are in, eg(1,2,3,4) : " << endl;
    while (cout << "Year : " and ! (cin >> year))
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "Please enter a valid input ! \n";
    }
    cout << "Press U if you are an undergrad and P if you are postgrad ";
    cin >> ugPgType;
    /// store all these details in the databse from here
}
Student :: Student(string fetchData){}