// SkyNet.cpp
//Nathaniel Grimsley
//10/15/2018

//We are including the following dependancies.
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//we start the main function, where the project begins and ends
int main()
{
	//we seed the rand number, starting the random number generator based on the current date and time.
	srand(static_cast<unsigned int>(time(0)));
	//we instantiate and set two integers, one for the bottom limit of the grid and the other for the top limit.
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	//we instantiate and set three integers. One for the number of tries it takes, one to store the target's location,
	// and one to use later to store the predicted target location.
	int tries = 0;
	int targetLocation = rand() % 64;
	int targetLocationPrediction = 0;

	//Were are pushing to the console the introduction to the program.
	cout << "Generate Random enemy location on 8x8 grid..." << endl;
	cout << "The enemy is located at location #" << targetLocation << " on 8x8 grid with 1-64 sectors." << endl;
	cout << "Skynet HK-Aerial Initializing software....." << endl;

	//This while loop runs until the predicted target location is the same as the target's actual location.
	while (targetLocationPrediction != targetLocation)
	{
		//we set a new value to targetLocationPrediction according to a binary algorithm.
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		//We increment the number of tries every try.
		tries++;

		//if our new prediction is higher than the target's location
		if (targetLocationPrediction > targetLocation)
		{
			//we change the high number on the search grid since the target will not be between your
			//current guess and the current high number.
			searchGridHighNumber = targetLocationPrediction- 1;
			//We begin pushing the new data to the console.
			cout << "=========================================================================" << endl;
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << endl;
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << targetLocation << "." << endl;
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
		}
		//otherwise if the prediction is lower than the target's location
		else if (targetLocationPrediction < targetLocation) 
		{
			//We change the low number on the search grid since the targer will not be between your
			//current guess and the current high number.
			searchGridLowNumber = targetLocationPrediction + 1;
			//We begin pushing the new data to the console.
			cout << "=========================================================================" << endl;
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << endl;
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << targetLocation << "." << endl;
			cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
		}
		//otherwise, if the prediction is the same as the target's location.
		else
		{
			//We push the final data to the console.
			cout << "=========================================================================" << endl;
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << endl;
			cout << "Enemy was hiding at location #" << targetLocation << endl;
			cout << "Target was found at location #" << targetLocationPrediction << endl;
			cout << "Skynet HK-Aerial Software took " << tries << " predictions to find the enemy location on a grid size of 8x8 (64)" << endl;
		}
		 
	}
	//as main is an integer, we return a number.
	return 0;
}

  