#pragma once
#include<vector>
#include<iomanip>
#include "Ride.h"
#include "Rider.h"

class RideList
{
private:

	vector<Ride> rides;
	string* map = new string[9]{ "City A", "City B", "City C", "City D", "City E", "City F", "City G", "City H", "City I" };

public:
	RideList()
	{
	}
	
	vector<Ride> getRides()
	{
		return rides;
	}

	void insert(Ride ride)
	{
		rides.push_back(ride);
	}

	void search(int source, int destination,string date, Rider* rider=new Rider())
	{
		int distance;
		vector<int> path;
		vector<Ride*> matchedRides;
		vector<double> fee;
		bool found=false;
		int i = 0;
		for (int j=0;j<rides.size();j++)
		{
			if (rides[j].getDate() == date && rides[j].getAvailableSeats() > 0)
			{
				int s = 0;
				for (int city : rides[j].getPath())
				{
					if (city == source)
					{
						for (int d = s; d < rides[j].getPath().size(); d++) {
							if (rides[j].getPath()[d] == destination)
							{
								found = true;
								Graph G;
								G.dijkstra(source, destination, &distance, &path);
								matchedRides.insert(matchedRides.begin() + i, &rides[j]);
								
								fee.insert(fee.begin() + i, distance * rides[j].getAmountPerKm());
								i++;
								
							}
						}
					}
					s++;
				}
			}
		}

		if (found)
		{
			int colWidth =20;
			//table header 
			cout  << "\n					Available Rides\n\n";
			cout << setfill('*') << setw(6 * colWidth) << "*" << endl;
			cout << setfill(' ') << fixed;
			cout <<setw(10) << left << "Index" << setw(colWidth) << left << "Driver" << setw(colWidth) << left << "Vehicle Type" << setw(15) << left << "Start" << setw(15) << left <<
				"End" << setw(colWidth) << left << "Starting time" << setw(colWidth) << left << "Trip fare" << endl;
			cout << setfill('*') << setw(6 * colWidth) << "*" << endl;
			cout << setfill(' ') << fixed;

			
				for (int i = 0; i < matchedRides.size(); i++)
				{
					cout  << setw(10) << left << i + 1  << setw(colWidth) << left << matchedRides[i]->getDriver().getName() << setw(colWidth) << left << matchedRides[i]->getDriver().getType()  << setw(15) << left << map[matchedRides[i]->getSource()] << setw(15) << left << map[matchedRides[i]->getDestination()] << setw(colWidth) << left << matchedRides[i]->getTime() << setprecision(0) << setw(3) << left <<"Rs." << setw(colWidth) << left << fee[i] << endl;
				}
				cout << setfill('*') << setw(6 * colWidth) << "*" << endl;
				cout << setfill(' ') << fixed;
				cout << "\n*** Press " << i + 1 << " to Exit\n\n";
				cout << "Select a Driver: ";
				int choice;
				cin >> choice;

				if (choice != i+1)
				{
					
					matchedRides[choice-1]->decreaseSeats();
					matchedRides[choice-1]->setRiderArray(rider);

					rider->setSource(source);
					rider->setDestination(destination);
					rider->setFee(fee[choice-1]);
					cout << "\nJoined the ride successfully...\n";
										
				}
			
		}

		if (!found)
			cout << "\nNo matching rides...\n";
	}


};