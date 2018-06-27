//
// Created by zaid on 14/6/18.
//

#include "TripDetails.h"
TripDetails :: TripDetails(){}
TripDetails :: TripDetails(bool flag){
    cout << "Going from: ";
    cin.ignore ();
    getline (cin, goingFrom, '\n');
    cout << "Going to: ";
    getline (cin, goingTo, '\n');
    cout << "Purpose of trip: ";
    getline (cin, purpose, '\n');
    y:cout << "Duration of the trip(in days, eg: 5): ";
    getline (cin, duration, '\n');
    for (int i = 0; i < duration.size (); ++i)
    {
        if (!(duration[i] >= '0' and duration[i] <= '9'))
        {
            cout << "Invalid Entry" << endl;
            goto y;
        }
    }
    cout <<"Phase-Pre/Post :(Wheather you are applying for the reimbursement before or after the trip) :" << endl;
    u:cout << "Enter 0 for Pre and 1 for Post" << endl;
    string TMP;
    getline (cin, TMP, '\n');
    if (TMP != "0" and TMP != "1")
    {
        cout << "Invalid Entry" << endl;
        goto u;
    }
    if (TMP == "0")
        phase = "pre";
    else
    {
        phase = "post";
    }
    transform (phase.begin (), phase.end (), phase.begin (),::tolower);
    if (phase == "pre")
    {
        while (cout << "Please enter the amount of Money you need : " << endl
               and ! (cin >> moneyNeeded))
        {
            cin.clear ();
            cin.ignore (numeric_limits < streamsize >::max (), '\n');
            cout << "Invalid input\n";
        }
        moneySpent = 0;
    }
    else if (phase == "post")
    {
        while (cout << "Please enter the money spent : " << endl and !
                (cin >> moneySpent))
        {
            cin.clear ();
            cin.ignore (numeric_limits < streamsize >::max (), '\n');
            cout << "Invalid input\n";
        }
        if (moneySpent > moneyNeeded)
        {
            moneyNeeded = moneySpent - moneyNeeded;
        }
        else
        {
            cout << "Please enter valid phase" << endl;
        }
    }
}
void TripDetails :: changePhase(int kharch){
    if(phase=="pre"){
        moneySpent=kharch;
        if(moneySpent>moneyNeeded){
            moneyNeeded=moneySpent-moneyNeeded;
            phase="post";
        }
        else {
            moneyNeeded=moneySpent-moneyNeeded;
            cout<<"You need to return "<<-(moneyNeeded)<<endl;
        }
    }
    else {
        cout<<"Already in post phase"<<endl;
    }

}

string TripDetails :: getPhase(){
    return phase;
}

string TripDetails :: getGoingFrom() {
    return goingFrom ;
}
string TripDetails :: getGoingTo() {
    return goingTo ;
}

string TripDetails :: getDuration(){
    return duration;
}

string TripDetails :: getPurpose(){
    return purpose;
}
int TripDetails :: getMoneyNeeded() {
    return moneyNeeded ;
}
void TripDetails :: setDuration(string dur){
    duration=dur;
}
void TripDetails :: setPurpose(string pur){
    purpose=pur;
}
void TripDetails :: setTripMentor(string ment){
    tripMentor=ment;
}