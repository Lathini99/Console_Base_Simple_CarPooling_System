#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"
#include "Driver.h"
#include <list>
using namespace std;

class Rider {
    string name;
    string username;
    string password;
    int source, destination;
    double tripFee;
    int n;
    list<Driver> availableDrivers;

public:
    Rider() {
        n = 0;
    }
    void registerRider(string, string, string);
    void SelectDriver(int driverIndex);

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
    int getSource() {
        return source;
    }

    int getDestination() {
        return destination;
    }
    void setSource(int s) {
        source=s;
    }

    void setDestination(int d) {
       destination=d;
    }
    double getFee()
    {
        return tripFee;
    }
    void setFee(double fee)
    {
        tripFee=fee;
    }


    };

void Rider::registerRider(string name, string username, string password) {
    this->name = name;
    this->username = username;
    this->password = password;
}

