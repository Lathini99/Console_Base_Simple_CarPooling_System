#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

class Driver {
private:
    string name;
    string username;
    string password;
    string vehicleNo;
    string vehicleType;

public:

    string getName()
    {
        return name;
    }
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
    string getType()
    {
        return vehicleType;
    }
    string getVno()
    {
        return vehicleNo;
    }
    void registerDriver(string , string , string,string,string );

    void offerRide(string , string , double , int );

};

void Driver::registerDriver(string name, string username, string password, string vehicleType, string vehicleNo ) {
    this->name = name;
    this->username = username;
    this->password = password;
    this->vehicleNo = vehicleNo;
    this->vehicleType = vehicleType;
       
}

