//
// Created by zaid on 15/6/18.
//

#include "Notification.h"
string Notification :: getUsername() {
    return username ;
}

Notification :: Notification(TripDetails &trpDetail,string usrName,bool stat){

    tripDetails=trpDetail;
    username = usrName ;
    status = stat ;
}