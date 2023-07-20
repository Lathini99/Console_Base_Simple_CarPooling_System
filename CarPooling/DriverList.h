#pragma once
#include<vector>
#include "Driver.h"

class DriverList
{
private:

	vector<Driver> drivers;

public:
	DriverList()
	{
	}

	void insert(Driver driver)
	{
		drivers.push_back(driver);
		
	}

	Driver* login(string uname, string pwd)
	{
		Driver* d = new Driver();

		for (int i=0 ; i<drivers.size(); i++)
		{
			*d = drivers[i];

			if (drivers[i].getUsername() == uname && drivers[i].getPassword() == pwd)
			{
				return d;
			}
		}

		cout << "\nIncorrect username or password!" << endl;
		return NULL;

	}
};