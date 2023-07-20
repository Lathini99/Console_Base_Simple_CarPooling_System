#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"
#include "Driver.h"
#include "Rider.h"

using namespace std;

class Ride
{  
    int source, destination, available_seats, distance;
    string date,time;
    double amountPerKm;
    Driver* driver;
    vector<Rider*> riderArray;
    vector <int> path;

public:
    Ride() {
        source = NULL;
        destination = NULL;
        distance = 0;
        amountPerKm = 0;
        available_seats = 0;
    }

    Ride(int startPlace, int endPlace,string date, string time, double amountPerKm, int seats, Driver* driver) {
    
            source = startPlace;
            destination = endPlace;
            this->amountPerKm = amountPerKm;
            available_seats = seats;
            this->driver = driver;
            this->date = date;
            this->time = time;
            Graph G;
            G.dijkstra(source, destination, &distance, &path);
                
        }

    int getDistance() 
    {
        return distance;
    }

    void decreaseSeats()
    {
        available_seats--;
    }

    void setRiderArray(Rider* r)
    {
        riderArray.push_back(r);
    }

    vector<Rider*> getRiderArray()
    {
        return riderArray;
    }

    vector <int> getPath()
    {
        return path;
    }

    string getDate() {
        return date;
    }

    string getTime() {
        return time;
    }


    void printPath(string* map)
    {
        for (auto it = path.begin(); it != path.end(); ++it)
        {
            if (*it == path.back())
                cout << map[*it];
            else
                cout << map[*it] << " -> ";

            
        }
            
    }

        int getSource() {
            return source;
        }

        int getDestination() {
            return destination;
        }

        double getAmountPerKm() {
            return amountPerKm;
        }

        Driver getDriver() {
            return *driver;
        }

       
        int getAvailableSeats() {
            return available_seats;
        }
};



