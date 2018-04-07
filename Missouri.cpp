/*******************************************************************************File: Missouri.cpp
Name: Calista Wong 
Description: This is the implementation for the Missouri class.
***************************************************************************/
#include <iostream>
#include "Missouri.hpp"
#include "Space.hpp"

Missouri::Missouri()
	{
	  up = NULL;
	  down = NULL;
	  left = NULL;
	  right = NULL;
	  distance = 100; 
	  state = "Missouri";
	  upFood = 0;
	  upAmmo = 0;
	  upOxen = 0;
	  upSpare = 0;
	  upMoney = 0;
	  upMembers = 0;
	}

bool Missouri::challenge()
	{
	  cout << "You have arrived at the edge of the Missouri River." << endl;
	  cout << "In order to do this. your wagon must be less than 8000 pounds." << endl;
	  cout << "Your wagon currently weighs: " << pounds << " pounds." << endl;
	  if (pounds > 8000)
		{
		  cout << "Your wagon is too heavy. Your enter party will drown." << endl;
		  return false;
		}	 
	  else
		{
		  cout << "Your wagon is able to cross the river." << endl;	
		  return true;
		}
	  
	}
	

