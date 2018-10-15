// SkyNet.cpp
//Nathaniel Grimsley
//10/15/2018

//We are including the following dependancies.
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	int tries = 0;
	int guess = 0;

	int target = rand() % 64;

	cout << "Generate Random enemy location on 8x8 grid..." << endl;
	cout << "The enemy is located at location #" << target << " on 8x8 grid with 1-64 sectors." << endl;
	cout << "Skynet HK-Aerial Initializing software....." << endl;

	while (guess != target)
	{
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		tries++;

		if (targetLocationPrediction > target)
		{
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "=========================================================================" << endl;
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << endl;
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << target << "." << endl;
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
		}
		else if (targetLocationPrediction < target) 
		{
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "=========================================================================" << endl;
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << endl;
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << target << "." << endl;
			cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
		}
		else
		{
			cout << "=========================================================================" << endl;
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << endl;
			cout << "Enemy was hiding at location #" << target << endl;
			cout << "Target was found at location #" << target << endl;
			cout << "Skynet HK-Aerial Software took " << tries << " predictions to find the enemy location on a grid size of 8x8 (64)" << endl;
			break;
		}
		 
	}


}

  