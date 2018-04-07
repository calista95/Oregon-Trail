/*******************************************************************************File: Idaho.cpp
Name: Calista Wong 
Description: This contains the implementation for the Idaho class.
**************************************************************************/

#include "Idaho.hpp"

Idaho::Idaho()
	{
	  up = NULL;
	  down = NULL;
	  left = NULL;
	  right = NULL;
	  distance = 100;
	  state = "Idaho";
	  upOxen = 0;
	  upFood = 0;
	  upAmmo = 0;
	  upSpare = 0;
	  upMoney = 0;
	  upMembers = 0;
	}

bool Idaho::challenge()
	{
	  	cout << "Oh no! You are caught in the middle of an enemy ambush in Fort Boise, Idaho! " << endl;
		cout << "Do you have any ammunition for protection? " << endl;
		int findOut;
		cout << "Press 1 to find out." << endl;
		cin >> findOut;
		while (!cin || findOut <1 || findOut>2)
			{
			  cout << "Bad input, enter another." << endl;
			  cin.clear();
		 	  cin.ignore();
			  cin >> findOut;
			}
		cout << endl;
		if (ammo >0)
		 {
			cout << "You have " << ammo << " boxes of ammo." << endl;
			cout << "Your entire party is protected." << endl;
			upAmmo = (-1)*ammo;
			return true;	
		 }
		else 
		 {
			cout << "You have no boxes of ammo." << endl;
			cout << "Your entire party was unable to make it out of the gunfire." << endl;
			return false;
		 }
	}	


