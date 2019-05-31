//
// Created by zaid on 15/6/18.
//

#include "Application.h"


BOOST_PYTHON_MODULE(Application)
{
    class_<Application>("Application")
        def(init<>());
        
        def("start", &Application::start);
        //.def("goToPage", &Application::goToPage);
      // .add_property("msg", &Bonjour::get_msg, &Bonjour::set_msg);
}


Application :: Application() {
    adminPass = "algorithm";


    fstream ip("UsernameDatabase.txt") ;
    string tempUsername ;
    while(!ip.eof()) {
        ip >> tempUsername ;
        usernameDatabase.insert(tempUsername);
    }
    /// above function to be present in app.start() function
    ip.close();

}
void Application :: start(){
    cout<<"In start "<<endl;
    // goToPage("homepage");
}

// void Application ::  forgotPassword() {

//     cout << "You choose to change your forgotton password : " << endl;

//     string username;
//     string seqQue, seqAns;
//     string name;

//     flag:cout << "Please enter your username : " << endl;

//     getline (cin, username, '\n');

//     fstream ip (username + ".txt");
//     string _username, _password, _type, _name, _seqQue, _seqAns, _money, _roll;
//     if (!ip)
//     {
//         cout << "Invalid username" << endl;
//         goto flag;
//     }
//     else
//     {



//         getline (ip, _username, '\n');
//         getline (ip, _password, '\n');
//         getline (ip, _type, '\n');
//         getline (ip, _name, '\n');
//         getline (ip, _seqQue, '\n');
//         getline (ip, _seqAns, '\n');
//         getline (ip, _money, '\n');
//         getline (ip, _roll, '\n');

//         ip.close ();

//     }

//     flag_1:cout << "Answer your security question : " << _seqQue << endl;

//     string responseFromUser;

//     getline (cin, responseFromUser, '\n');

//     if (responseFromUser == _seqAns)
//     {
//         cout << "Change Password request authorized" << endl;
//         cout << "Enter a new password " << endl;
//         string pass;
//         getline (cin, pass, '\n');
//         fstream ip (username + ".txt");
//         ip << _username << "\n" << pass << "\n" << _type << "\n" << _name <<
//            "\n" << _seqQue << "\n" << _seqAns << "\n" << _money << "\n" << _roll
//            << "\n";
//         cout << "password successfully updated" << endl;
//         ip.close ();
//     }
//     else
//     {
//         goto flag_1;
//     }

//     goToPage ("homepage");

// }

// void Application ::resetPassword(){
//     string newPassword ;
//     string username = usr -> username ;
//     cin.ignore();
//     cout << "Please enter your new password : ";
//     getline(cin,newPassword,'\n');

//     fstream ip (username + ".txt");
//     string _username, _password, _type, _name, _seqQue, _seqAns, _money, _roll;

//     {



//         getline (ip, _username, '\n');
//         getline (ip, _password, '\n');
//         getline (ip, _type, '\n');
//         getline (ip, _name, '\n');
//         getline (ip, _seqQue, '\n');
//         getline (ip, _seqAns, '\n');
//         getline (ip, _money, '\n');
//         getline (ip, _roll, '\n');

//         ip.close ();

//     }
//     fstream op (username + ".txt");
//     op << _username << "\n" << newPassword << "\n" << _type << "\n" << _name <<
//        "\n" << _seqQue << "\n" << _seqAns << "\n" << _money << "\n" << _roll
//        << "\n";
//     cout << "password successfully updated" << endl;
//     op.close ();

//     goToPage("userDashboard");

// }


// void Application :: registerUser(){
//     RegistrationManager * rm = new SignUpManually() ;
//     rm -> registration() ;
//     goToPage("homepage");
// }
// void Application :: updateReimbursement(string str){

//     if (str == "user")
//     {
//         dbal = new DataBaseAccessLayer ();
//         vector < ReimbursementDetails > userReimbursementInventory =
//                 dbal->fetchNotificationsForUser (usr->getUsername());

//         int cnt;
//         int notification_index = 1;
//         for (int i = 0; i < userReimbursementInventory.size (); i++)
//         {
//             cout << (notification_index++) << endl;
//             userReimbursementInventory[i].printReimbursementDetails ();
//             cout << endl;
//         }

//         // cout<<"debugging"<<userReimbursementInventory[0].username<<endl;

//         f3:while (cout <<
//                        "Enter notification number you want to change \n Press 0 to return back"
//                   and ! (cin >> cnt))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//         if (cnt == 0)
//         {
//             goToPage ("userDashboard");
//         }
//         else if (cnt > userReimbursementInventory.size ())
//         {
//             cout << "Invalid index number" << endl;
//             goto f3;
//         }
//         int choice;
//         cout << "Press 1 to update pre to post phase and enter money spent" <<
//              endl;
//         while (cout << "Enter choice" and ! (cin >> choice))
//         {

//             cin.clear ();

//             cin.ignore (numeric_limits < streamsize >::max (), '\n');

//             cout << "Invalid input\n";
//         }
//         if (choice == 1)
//         {
//             cout << "Enter money spent" << endl;
//             int moneySpent;
//             while (cout << "Enter money spent" and ! (cin >> moneySpent))
//             {

//                 cin.clear ();

//                 cin.ignore (numeric_limits < streamsize >::max (), '\n');

//                 cout << "Invalid input\n";
//             }
//             userReimbursementInventory[cnt - 1].phase = "post";

//             userReimbursementInventory[cnt - 1].moneyNeeded =
//                     moneySpent - userReimbursementInventory[cnt - 1].moneyNeeded;

//         }
//         dbal->updateNotification (userReimbursementInventory[cnt - 1], cnt);

//         userReimbursementInventory[cnt - 1].printReimbursementDetails ();
//         cout << endl;
//         goToPage ("userDashboard");
//         cout << "loda" << endl;

//     }
//     else if (str == "admin")
//     {
//         dbal = new DataBaseAccessLayer ();
//         vector < ReimbursementDetails > adminReimbursementInventory =
//                 dbal->fetchAllNotificationsForAdmin ();
//         int cnt;
//         int notification_index = 1;
//         for (int i = 0; i < adminReimbursementInventory.size (); i++)
//         {
//             cout << (notification_index++) << endl;
//             adminReimbursementInventory[i].printReimbursementDetails ();
//             cout << endl;
//         }
//         // cout<<"debugging"<<userReimbursementInventory[0].username<<endl;

//         f4:while (cout <<
//                        "Enter notification number you want to change status\n Press 0 to return back"
//                   and ! (cin >> cnt))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//         if (cnt == 0)
//         {
//             goToPage ("adminDashBoard");
//         }
//         else if (cnt > adminReimbursementInventory.size ())
//         {
//             cout << "Invalid entry Re-enter" << endl;
//             goto f4;
//         }
//         int i;            //Index of First reimbursement element where that username occurs
//         for (i = 0; i < adminReimbursementInventory.size (); i++)
//         {
//             if (adminReimbursementInventory[i].username ==
//                 adminReimbursementInventory[cnt - 1].username)
//                 break;
//         }

//         int choice;
//         cout <<
//              "Press 1 to approve and 2 to disprove and anything else to do nothing"
//              << endl;
//         while (cout << "Enter choice" and ! (cin >> choice))
//         {

//             cin.clear ();

//             cin.ignore (numeric_limits < streamsize >::max (), '\n');

//             cout << "Invalid input\n";
//         }
//         if (choice == 1)
//         {
//             adminReimbursementInventory[cnt - 1].status = "approved";
//         }
//         else if (choice == 2)
//         {
//             adminReimbursementInventory[cnt - 1].status = "rejected";
//         }

//         dbal->updateNotification (adminReimbursementInventory[cnt - 1],
//                                   cnt - i);

//         adminReimbursementInventory[cnt - 1].printReimbursementDetails ();
//         cout << endl;
//         goToPage ("adminDashBoard");

//     }
// }

// void Application :: viewReimbursementInventory(string str){

//     if (str == "user")
//     {
//         DataBaseAccessLayer d;
//         vector < ReimbursementDetails > temp = d.fetchNotificationsForUser (usr->getUsername());
//         if (temp.size () == 0)
//         {
//             cout << "No reimbursement(s) applied yet !" << endl;
//             sleep (0.5);
//             goto yy;
//         }
//         yy:
//         int cnt = 1;
//         for (auto itr:temp)
//         {
//             cout << cnt++ << " : ";
//             itr.printReimbursementDetails ();
//             cout << endl;
//         }
//         goToPage ("userDashboard");
//     }
//     else
//     {
//         DataBaseAccessLayer d;
//         cout <<
//              "*****************************Viewing all reimbursement details for the admin : **********************************"
//              << endl;
//         vector < ReimbursementDetails > temp =
//                 d.fetchAllNotificationsForAdmin ();
//         int cnt = 1;
//         for (auto itr:temp)
//         {
//             cout << cnt++ << " : ";
//             itr.printReimbursementDetails ();
//             cout << endl;
//         }

//         goToPage ("adminDashBoard");

//     }
// }

// void Application :: loginAsAdmin() {

//     int attempts = 0;

//     while (1)
//     {

//         flag:if (attempts >= 3)
//     {

//         cout << "Mx limit of wrong attempts reached \n";
//         goToPage ("homepage");
//         /// redirect to homepage ;

//         break;

//     }
//         cout <<
//              "----------------------------Admin Login Page----------------------------"
//              << endl;
//         string pass = getpass("Password :");

//         if (pass == adminPass)
//         {

//             cout << "successfully logging in ... \n";
//             sleep (1);
//             goToPage ("adminDashBoard");
//             /// open the admin dashboard.
//         }

//         else
//         {
//             ++attempts;

//             cout << "Wrong Credentials , you have " << 3 -
//                                                        attempts << " left \n";

//             sleep (1);
//             system ("clear");
//             goto flag;

//         }
//     }
// }

// void Application :: login(){
//     SimpleLogger *lm=new SimpleLogger();
//     usr=lm->login();
//     if(usr!=NULL){
//         // cout<<"Hello there"<<endl;
//         goToPage("userDashboard");

//     }
//     else goToPage("homepage");
// }

// void Application :: applyForReimbursement() {

//     int choice;
//     h:cout <<
//            "Press 1 if you are applying for the fresh reimbursement and 2 for old reimbursement else continue"
//            << endl;
//     while (cout << "Enter choice : " and ! (cin >> choice))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//     if (!(choice == 1 or choice == 2))
//     {
//         cout << "Invalid entry" << endl;
//         goto h;
//     }
//     if (choice == 1)
//     {
//         cout <<
//              "----------------------------------------------------------------------"
//              << endl;
//         cout << "You choose to apply for new reimbursement of allowance : " <<
//              endl;
//         cout << "Please enter the following details of your Trip :" << endl;

//         /// ask trip details from the user

//         TripDetails tripDetails = TripDetails (true);

//         Notification nm = Notification (tripDetails, usr->getUsername (), 0);

//         Nm->sendNotification (tripDetails, nm);

//         goToPage ("userDashboard");

//     }
//     else if (choice == 2)
//     {
//         dbal = new DataBaseAccessLayer ();
//         vector < ReimbursementDetails > userReimbursementInventory =
//                 dbal->fetchNotificationsForUser (usr->getUsername());

//         int cnt;
//         int notification_index = 1;
//         for (int i = 0; i < userReimbursementInventory.size (); i++)
//         {
//             cout << (notification_index++) << endl;
//             userReimbursementInventory[i].printReimbursementDetails ();
//             cout << endl;
//         }

//         // cout<<"debugging"<<userReimbursementInventory[0].username<<endl;
//         jk:         /// chuut, explain the user what do you mean by change notification here.
//         f6:while (cout <<
//                        "Enter notification number you want to change\nPress 0 to return back\n"
//                   and ! (cin >> cnt))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//         if (cnt < 0 or cnt > userReimbursementInventory.size ())
//         {
//             cout << "Invalid Entry" << endl;
//             goto jk;
//         }
//         if (cnt == 0)
//         {
//             goToPage ("userDashboard");
//         }
//         if (userReimbursementInventory[cnt - 1].phase == "post")
//         {
//             cout << "Already in post phase :p" << endl;
//             goto f6;
//         }
//         int choice;       /// Have a look at the functioning of this part of the program.chuut
//         kl:cout <<
//                 "Press 1 to update pre to post phase and enter the grand total money spent"
//                 << endl;
//         while (cout << "Enter choice" and ! (cin >> choice))
//         {

//             cin.clear ();

//             cin.ignore (numeric_limits < streamsize >::max (), '\n');

//             cout << "Invalid input\n";
//         }
//         if (choice != 1)
//         {
//             cout << "Invalid Entry" << endl;
//             goto kl;
//         }

//         if (choice == 1)
//         {

//             int moneySpent;
//             while (cout << "Enter money spent : " and ! (cin >> moneySpent))
//             {

//                 cin.clear ();

//                 cin.ignore (numeric_limits < streamsize >::max (), '\n');

//                 cout << "Invalid input\n";
//             }
//             userReimbursementInventory[cnt - 1].phase = "post";
//             if (userReimbursementInventory[cnt - 1].status == "false")
//             {
//                 userReimbursementInventory[cnt - 1].moneyNeeded = moneySpent;

//             }
//             else
//             {
//                 userReimbursementInventory[cnt - 1].moneyNeeded =
//                         moneySpent - userReimbursementInventory[cnt - 1].moneyNeeded;
//             }
//         }

//         dbal->updateNotification (userReimbursementInventory[cnt - 1], cnt);

//         userReimbursementInventory[cnt - 1].printReimbursementDetails ();
//         cout << endl;

//         goToPage ("userDashboard");



//     }
//     else
//         goToPage ("userDashboard");



//     // cout << "You choose to apply for reimbursement of allowance : " << endl ;

//     // /// ask trip details from the user

//     //       TripDetails tripDetails = TripDetails(true);

//     //       Notification nm = Notification(tripDetails,usr->getUsername(),0);

//     //       Nm->sendNotification(tripDetails,nm);
// }

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// void Application :: goToPage(string type){

//     sleep (1);

//     system ("clear");

//     if (type == "homepage")
//     {
//         cout <<
//              "----------------------------Welcome to Application Home Page------------------------------- "
//              << endl;
//         cout << "1. Register" << endl;
//         cout << "2. Login" << endl;
//         cout << "3. Administrator Login" << endl;
//         cout << "4. Forgot Password" << endl;
//         cout << "5. Show UserManual" << endl;
//         cout << "6. Exit" << endl;
//         int choice;
//         bool flag = true;
//         f:while (cout << "Enter choice : " and ! (cin >> choice))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//         /// trial and error wala
//         cin.ignore ();

//         while (flag)
//         {
//             switch (choice)
//             {
//                 case 1:
//                     sleep (1);
//                     system ("clear");
//                     registerUser ();

//                     flag = false;
//                     break;

//                 case 2:
//                     sleep (1);
//                     system ("clear");
//                     login ();
//                     flag = false;
//                     break;
//                 case 3:
//                     sleep (1);
//                     system ("clear");
//                     loginAsAdmin ();
//                     flag = false;
//                     break;

//                 case 4:
//                     sleep (1);
//                     system ("clear");
//                     forgotPassword ();
//                     flag = false;
//                     break;

//                 case 5:
//                     cout << "Coming soon" << endl;
//                     goToPage ("homepage");
//                     flag = false;
//                     break;

//                 case 6:
//                     sleep (1);
//                     cout <<
//                          "----------------------------GOODBYE----------------------------";

//                     exit (0);
//                     flag = false;
//                     break;

//                 default:
//                     cout << "Please enter a valid entry" << endl;
//                     goto f;
//                     break;

//             }
//         }
//     }
//     else if (type == "userDashboard")
//     {

//         //exit(0);
//         cout <<
//              "----------------------------Dashboard Page----------------------------"
//              << endl;
//         cout << "1. Apply for reimbursement" << endl;
//         cout << "2. Reset Password" << endl;
//         cout << "3. View Notifications" << endl;
//         // cout<<"4. Change details"<<endl;
//         cout << "4. SignOut" << endl;
//         int choice;
//         bool flag = true;
//         f1:while (cout << "Enter choice : " and ! (cin >> choice))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//         while (flag)
//         {
//             switch (choice)
//             {
//                 case 1:
//                     applyForReimbursement ();
//                     flag = false;
//                     break;

//                 case 2:
//                     resetPassword (); /// needs to be implemented
//                     flag = false;
//                     break;

//                 case 3:
//                     viewReimbursementInventory ("user");
//                     //inventory.viewNotifications(string userId);
//                     flag = false;
//                     break;

//                 case 4:
//                     cout << "Signing out" << endl;
//                     usr = NULL;
//                     flag = false;
//                     goToPage ("homepage");
//                     break;

//                 default:
//                     cout << "Please enter a valid entry" << endl;
//                     goto f1;
//                     break;
//             }
//         }

//     }
//     else if (type == "adminDashBoard")
//     {
//         cout << "Welcome to dashboard " << endl;
//         cout << "1. View all reimbursements" << endl;
//         cout << "2. Update Reimbursement Status" << endl;
//         cout << "3. SignOut" << endl;
//         cout << "4. Exit" << endl;
//         int choice;
//         bool flag = true;
//         f2:while (cout << "Enter choice : " and ! (cin >> choice))
//     {

//         cin.clear ();

//         cin.ignore (numeric_limits < streamsize >::max (), '\n');

//         cout << "Invalid input\n";
//     }
//         while (flag)
//         {
//             switch (choice)
//             {
//                 case 1:
//                     viewReimbursementInventory ("admin");
//                     flag = false;
//                     break;

//                 case 2:
//                     updateReimbursement ("admin");
//                     flag = false;
//                     break;

//                 case 3:
//                     //inventory.viewNotifications(string userId);
//                     goToPage ("homepage");
//                     flag = false;
//                     break;

//                 case 4:
//                 {
//                     exit (0);
//                 }
//                     flag = false;
//                     break;

//                 default:
//                     cout << "Please enter a valid entry" << endl;
//                     goto f2;
//                     break;
//             }
//         }

//     }
// }