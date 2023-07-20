#include <iostream>
#include <string>
#include "Ride.h"
#include "Driver.h"
#include "DriverList.h"
#include "RideList.h"
#include "RiderList.h"

using namespace std;

int main()
{
    DriverList dlist;

    RideList ridelist;

    RiderList rlist;

    Driver d1;
    d1.registerDriver("kasun", "0771234567", "123","Car", "CBF 3479");
    dlist.insert(d1);

    Driver d2;
    d2.registerDriver("Sanjeewa", "0772345678", "123", "Mini van", "KL 2748");
    dlist.insert(d2);

    Rider r1;
    r1.registerRider("Amila", "0773456789", "123");
    rlist.insert(r1);

    Ride rr1(7, 4, "23/02/2023", "3.00pm", 100, 4, &d1);
    ridelist.insert(rr1);

    Ride rr2(7, 4, "23/02/2023", "8.30am", 110, 2, &d2);
    ridelist.insert(rr2);

    string* map= new string[9]{ "City A", "City B", "City C", "City D", "City E", "City F", "City G", "City H", "City I" };
    
    while (1)
    {
        cout << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n";
        cout << "| Welcome to the carpooling system! |\n";
        cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\n";
        
        cout << "           1. Driver" << endl;
        cout << "           2. Passenger" << endl;
        cout << "           3. Exit" << endl;
        cout << "\nPlease select an option: " ;
        int c;
        cin >> c;
        if (c == 1)
        {

            while (1) {
                Driver driver;
                cout<<"\n************************************************\n";
                cout << "\n           1. Register as a driver" << endl;
                cout << "           2. Login as a driver" << endl;
                cout << "           3. Exit" << endl << endl;;
                cout << "Please select an option: ";

                int choice;
                cin >> choice;
                string name, username, password, type, vno;
                if (choice == 1)
                {
                    cout << "\nEnter your name          : ";
                    cin >> name;
                    cout << "Enter your mobile no     : ";
                    cin >> username;
                    cout << "Enter your password      : ";
                    cin >> password;
                    cout << "Enter your vehicle type  : ";
                    cin >> type;
                    cout << "Enter your vehicle number: ";
                    cin >> vno;
                    driver.registerDriver(name, username, password, type, vno);
                    dlist.insert(driver);
                    cout << "\nDriver registered successfully!\n";
                }
                else if (choice == 2)
                {
                    cout << "\nEnter your mobile no: ";
                    cin >> username;
                    cout <<   "Enter your password : ";
                    cin >> password;


                    if (dlist.login(username, password) != NULL) {

                        cout << "\nDriver logged in successfully!" << endl;
                        Driver* driverLogged = new Driver();
                        driverLogged = dlist.login(username, password);

                        while (1)
                        {
                            cout << "\n************************************************\n";
                            cout << "           \nWelcome " << driverLogged->getName()<< "!" << endl;
                            cout << "\n           Driver Menu";
                            cout << "\n           ------------\n";
                            cout << "           1. Offer a ride" << endl;
                            cout << "           2. Display the passenger details" << endl;
                            cout << "           3. Back to menu" << endl;
                            cout << "\nPlease select an option: ";
                            int driverChoice;
                            cin >> driverChoice;
                            string riderName, riderStart, riderEnd, name, date, time;
                            double amountPerKm;
                            int startPlace, endPlace, seats;
                            char slash;
                            if (driverChoice == 1)
                            {
                                cout << endl;
                                for (int i = 0; i < 9; i++)
                                {
                                    cout <<"            " << i << " - " << map[i] << endl;;
                                }
                                cout << endl;
                                cout << "Enter your starting location             : ";
                                cin >> startPlace;
                                cout << "Enter your ending location               : ";
                                cin >> endPlace;
                                cout << "Enter the date (dd/mm/yyyy)              : ";
                                cin >> date;
                                cout << "Enter the starting time                  : ";
                                cin >> time;
                                cout << "Enter your amount per km                 : ";
                                cin >> amountPerKm;
                                cout << "Enter the available seats in your vehicle: ";
                                cin >> seats;
                                Ride ride(startPlace, endPlace, date, time, amountPerKm, seats, driverLogged);
                                ridelist.insert(ride);
                                cout << endl << "* Driver " << driverLogged->getName() << " is offering a ride from " << map[startPlace] << " to " << map[endPlace] << " at a rate of Rs." << amountPerKm << " per km and available seats in the vehicle is " << seats << endl;
                                cout << endl << "* The shortest path to reach the destination is "; ride.printPath(map);
                                cout << endl << "\n* Distance of the ride is " << ride.getDistance() << "km" << endl ;

                            }

                            else if (driverChoice == 2)
                            {
                                for (Ride ride : ridelist.getRides())
                                {

                                    if (ride.getDriver().getUsername() == driverLogged->getUsername())
                                    {
                                        cout << "\nRide details" << endl;
                                        cout << "------------" << endl;
                                        cout << "From: " <<map[ride.getSource()] << endl;
                                        cout << "To  : " << map[ride.getDestination()] << endl;
                                        cout << "Date: " << ride.getDate() << endl;
                                        cout << "Time: " << ride.getTime() << endl<<endl;

                                        for (Rider* rider : ride.getRiderArray())
                                        {
                                            cout << "Passenger's name: " << rider->getName() << endl;
                                            cout << "Contact number  : " << rider->getUsername() << endl;
                                            cout << "From            : " << map[rider->getSource()] << endl;
                                            cout << "To              : " <<map[rider->getDestination()] << endl;
                                            cout << "Trip Fee        : Rs." << rider->getFee() << endl;
                                        }

                                    }
                                }
                               
                            }
                            else if (driverChoice == 3)
                            {
                                cout << "Back to the menu...." << endl;
                                break;
                            }
                            else {
                                cout << "Invalid option. Please try again." << endl;


                            }

                        }
                    }

                }

                else if (choice == 3)
                {
                    cout << "Exiting the driver program..." << endl;
                    break;
                }
                else {
                    cout << "Invalid option. Please try again." << endl;

                }

            }
        }
        else if (c == 2)
        {
            while (1) {
                cout << "\n************************************************\n";
                cout << "\n           1. Register as a passenger" << endl;
                cout << "           2. Login as a passenger" << endl;
                cout << "           3. Exit" << endl;
                cout << "\nPlease select an option: " ;
                int choice;
                cin >> choice;
                string name, username, password;
                if (choice == 1)

                {
                    Rider rider;
                    cout << "\nEnter your name     : ";
                    cin >> name;
                    cout <<   "Enter your mobile no: ";
                    cin >> username;
                    cout <<   "Enter your password : ";
                    cin >> password;
                    rider.registerRider(name, username, password);
                    rlist.insert(rider);
                    cout << "\nPassenger registered successfully!\n";

                }

                else if (choice == 2)
                {
                    cout << "\nEnter your mobile no: ";
                    cin >> username;
                    cout <<   "Enter your password : ";
                    cin >> password;

                    if (rlist.login(username, password) != NULL) {

                        cout << "\nPassenger logged in successfully!" << endl;
                        Rider* riderLogged = new Rider();
                        riderLogged = rlist.login(username, password);

                        while (1)
                        {
                            cout << "\n************************************************\n";
                            cout << "           \nWelcome " << riderLogged->getName() << "!" << endl;
                            cout << "\n           Passenger Menu";
                            cout << "\n           --------------\n";
                            cout << "           1. Search a ride" << endl;
                            cout << "           2. Display ride details" << endl;
                            cout << "           3. Back to menu" << endl;
                            cout << "\nPlease select an option: ";
                            int riderChoice;
                            char slash;
                            cin >> riderChoice;
                            int source, destination;
                            string date;

                            if (riderChoice == 1)

                            {
                                cout << endl;
                                for (int i = 0; i < 9; i++)
                                {
                                    cout <<"            " << i << " - " << map[i] << endl;;
                                }

                                cout << "\nEnter your starting location: ";
                                cin >> source;
                                cout <<   "Enter your ending location  : ";
                                cin >> destination;
                                cout <<   "Enter the date(dd/mm/yyyy)  : ";
                                cin >> date;
                              
                                ridelist.search(source, destination, date, riderLogged);

                            }
                            else if (riderChoice == 2)
                            {
                                for (Ride ride : ridelist.getRides())
                                {
                                  
                                    for (Rider* rider : ride.getRiderArray())
                                    {
                                        if (rider->getUsername() == riderLogged->getUsername())
                                        {
                                            cout << "\nRide details" << endl;
                                            cout << "------------" << endl;
                                            cout << "From              : " << map[rider->getSource()] << endl;
                                            cout << "To                : " << map[rider->getDestination()] << endl;
                                            cout << "Date              : " << ride.getDate() << endl;
                                            cout << "Ride Starting Time: " << ride.getTime() << endl;

                                            cout << "\nDriver's details" << endl;
                                            cout << "----------------" << endl;
                                            cout << "Name        : " << ride.getDriver().getName() << endl;
                                            cout << "Contact No  : " << ride.getDriver().getUsername()<< endl;
                                            cout << "Vehicle Type: " << ride.getDriver().getType() << endl;
                                            cout << "Vehicle No  : " << ride.getDriver().getVno() << endl;

                                        }
                                    }

                                }
                            }

                            else if (riderChoice == 3)
                            {
                                cout << "Back to the menu...." << endl;
                                break;
                            }
                            else {
                                cout << "Invalid option. Please try again." << endl;


                            }

                        }

                    }

                }

                else if (choice == 3)
                {
                    cout << "Exiting the rider program..." << endl;
                    break;
                }
                else {
                    cout << "Invalid option. Please try again." << endl;

                }
            }
        }
        else if (c == 3)
        {
            cout << "Exiting the program..." << endl;
            break;
        }
        else {
            cout << "Invalid option. Please try again." << endl;

        }

    }

    return 0;
}