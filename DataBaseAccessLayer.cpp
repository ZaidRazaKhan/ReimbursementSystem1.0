//
// Created by zaid on 15/6/18.
//

#include "DataBaseAccessLayer.h"
void DataBaseAccessLayer :: updateNotification(ReimbursementDetails &Rd,int number){
    string uitilityStr = Rd.username +"_notification_"+itos(number) ;
    cout<<uitilityStr<<endl<<endl<<endl<<endl;
    fstream utility(uitilityStr+".txt") ;
    utility << Rd.username<<"`" <<Rd.goingFrom<<"`" <<Rd.goingTo<<"`" <<Rd.purpose<<"`" <<Rd.phase<<"`" <<Rd.moneyNeeded<<"`" <<Rd.status<<"`";
    utility.close();
}
DataBaseAccessLayer :: DataBaseAccessLayer(){
    fstream ip("UsernameDatabase.txt") ;
    string tempUsername ;
    while(!ip.eof()) {
        ip >> tempUsername ;
        usernameDatabase.insert(tempUsername);
    }
    /// above function to be present in app.start() function
    ip.close();

}
string DataBaseAccessLayer :: itos(int n) {
    string ans="";
    while(n)
    {
        int dig = n%10;
        ans += (char)('0'+dig);
        n/=10;
    }
    return ans ;
}
int DataBaseAccessLayer :: stoi_1(string s) {
    int num = 0 ;
    for(int i = 0 ;i < s.size() ;++i) {
        num = 10*num + (s[i]-'0');
    }
    return num;
}

vector<ReimbursementDetails> DataBaseAccessLayer ::  fetchAllNotificationsForAdmin() {
    vector<ReimbursementDetails> allNotificationsForAdmin;
    set<string>usernameDatabase;
    fstream ip("UsernameDatabase.txt") ;

    string tempUsername ;

    while(!ip.eof()) {
        ip >> tempUsername ;
        usernameDatabase.insert(tempUsername);
    }

    ip.close();

    for(auto itr : usernameDatabase) {
        vector<ReimbursementDetails> temp = fetchNotificationsForUser(itr) ;
        for(auto _itr : temp) {
            allNotificationsForAdmin.push_back(_itr);
        }
    }
    return allNotificationsForAdmin;
}

void DataBaseAccessLayer :: addUser(User * currentUser,int type) {

    fstream ip(currentUser -> getUsername() + ".txt",ios::out) ;
    string typeOfUser ;
    if(type == 1) typeOfUser = "Student" ;
    else if(type == 2 ) typeOfUser = "Professor" ;
    else if(type == 3) typeOfUser = "Staff" ;
    ip << currentUser -> getUsername() << '\n' << currentUser -> getPassword() <<"\n"<<typeOfUser<<"\n"<< currentUser->getName() << "\n" << currentUser->getSecurityQuestion() <<"\n" << currentUser->getSecurityAnswer() <<"\n" << currentUser->getAllowanceMoneyRemaining() << "\n" << currentUser->getMobileNumber() <<"\n";
    ip.close() ;
    cout<<"\nPermission Granted!\nCongratulations! You have been registered\n";
    cout<<"\nYour Username is "<< currentUser->getUsername() <<"\n\n";
    fstream fs("UsernameDatabase.txt",ios::app) ;
    fs << "\n" << currentUser -> getUsername() ;
    fs.close() ;
    string t = currentUser -> getUsername() + "notifications" ;
    fstream obj(t+".txt",ios::out);
    obj.close();
    string s = currentUser -> getUsername() + "_cnt_notifications" ;
    fstream obj1(s+".txt",ios::out);
    obj1 << 0 ;
    obj1.close();
    return ;
}

User * DataBaseAccessLayer :: fetchData(string username){

    string type;

    fstream obj (username + ".txt");
    obj >> type >> type >> type;
    obj.close ();
    if (type == "Student")
    {
        usr = new Student (type);
        fstream obj (username + ".txt");
        string username, password, typeOfUser, name, securityQues, securityAns;
        obj >> username >> password >> typeOfUser >> name >> securityQues >>securityAns;
        usr->setUsername (username);
        usr->setPassword (password);
        usr->setName (name);
        usr->setSecurityQuestion (securityQues);
        usr->setSecurityAnswer (securityAns);
        obj.close ();
    }
    else if (type == "Professor")
    {
        usr = new Professor (type);
        fstream obj (username + ".txt");
        string username, password, typeOfUser, name, securityQues, securityAns;
        obj >> username >> password >> typeOfUser >> name >> securityQues >>securityAns;
        usr->setUsername (username);
        usr->setPassword (password);
        usr->setName (name);
        usr->setSecurityQuestion (securityQues);
        usr->setSecurityAnswer (securityAns);
        obj.close ();
    }
    else
    {
        usr = new Staff (type);
        fstream obj (username + ".txt");
        string username, password, typeOfUser, name, securityQues, securityAns;
        obj >> username >> password >> typeOfUser >> name >> securityQues >>securityAns;
        usr->setUsername (username);
        usr->setPassword (password);
        usr->setName (name);
        usr->setSecurityQuestion (securityQues);
        usr->setSecurityAnswer (securityAns);
        obj.close ();
    }

    return usr;

}

vector<ReimbursementDetails> DataBaseAccessLayer ::  fetchNotificationsForUser(string str) {

    int val ;
    vector<ReimbursementDetails> listOfNotifications;
    string uitilityStr = str +"_cnt_notifications" ;
    fstream utility(uitilityStr+".txt") ;
    utility >> val ;
    utility.close();
    for(int i = 0 ; i < val ; ++i)
    {
        string username = str + "_notification_"+itos(i+1)/*usr -> getUsername() */;
        fstream ip(username+".txt");
        string a,b,c,d,e,f,g;
        getline(ip,a,'`');
        getline(ip,b,'`');
        getline(ip,c,'`');
        getline(ip,d,'`');
        getline(ip,e,'`');
        getline(ip,f,'`');
        getline(ip,g,'`');
        ReimbursementDetails ptr(a,b,c,d,e,stoi_1(f),g);
        listOfNotifications.push_back(ptr);
        ip.close();
    }
    return listOfNotifications;
}