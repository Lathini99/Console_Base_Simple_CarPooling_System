#pragma once
#include<vector>
#include "Rider.h"

class RiderList
{
private:

	vector<Rider> riders;

public:
	RiderList()
	{
	}

	void insert(Rider rider)
	{
		riders.push_back(rider);
	}

	Rider* login(string uname, string pwd)
	{
		Rider* r = new Rider();

		for (int i = 0; i < riders.size(); i++)
		{
			*r = riders[i];

			if (riders[i].getUsername() == uname && riders[i].getPassword() == pwd)
			{
				return r;
			}
		}

		cout << "\nIncorrect username or password!" << endl;
		return NULL;

	}
};