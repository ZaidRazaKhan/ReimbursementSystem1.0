//
// Created by zaid on 15/6/18.
//

#include "NotificationManager.h"

string NotificationManager :: itos(int n) {
    string ans="";
    while(n)
    {
        int dig = n%10;
        ans += (char)('0'+dig);
        n/=10;
    }
    return ans ;
}
int NotificationManager :: stoi_1(string s) {
    int num = 0 ;
    for(int i = 0 ;i < s.size() ;++i) {
        num = 10*num + (s[i]-'0');
    }
    return num;
}
void NotificationManager :: sendNotification(TripDetails &trp,Notification nm){

    int val ;

    string uitilityStr = nm.getUsername() +"_cnt_notifications" ;

    fstream utility(uitilityStr+".txt") ;

    utility >> val ;

    ++val ;

    utility.close();

    fstream util(uitilityStr+".txt",ios::out);

    util<< val ;

    util.close();

    /// updating the count of notification file for the user .

    string newUtilityStr = nm.getUsername() + "_notification_"+itos(val);

    string currentUserName = nm.getUsername();///= getUsername() ;

    ofstream obj,obj1 ;
    obj.open(newUtilityStr + ".txt",ios :: app) ;
    /// updating the users file
    obj <<currentUserName<<"`" << trp.getGoingFrom() <<"`"<<trp.getGoingTo() <<"`" << trp.getPurpose() <<"`"<<trp.getPhase() <<"`"<<trp.getMoneyNeeded() <<"`"<<"false" << "`";

    obj.close();
    /// update the admin's file
    // obj1.open("adminNotifications.txt",ios::app) ;

    // obj1 <<"\n"<<currentUserName<<"`"<<trp.getGoingFrom() <<"`"<<trp.getGoingTo() <<"`"<< trp.getPurpose() <<"`"<<trp.getPhase() <<"`"<<trp.getMoneyNeeded()<<"`" <<"false`";

    // obj1.close();


    cout << "Reimbursement Notification sent to Admin\nYou will be notified of the final decision\n";

    /// go back to the user dashboard menu;

}

void NotificationManager :: deleteNotification(Notification nm) {

}

void NotificationManager :: editNotification() {

}