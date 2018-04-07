/*******************************************************************************File: Nebraska.cpp
Name: Calista Wong 
Description: This is the implementation file for the Nebraska class.
*****************************************************************************/

#include "Nebraska.hpp"

Nebraska::Nebraska() 
	{
	  up = NULL;
	  down = NULL;
	  left = NULL;
	  right = NULL;  
	  distance = 100;
	  state = "Nebraska";
	  upOxen = 0;
	  upFood = 0;
	  upAmmo = 0;
	  upSpare = 0;
	  upMoney = 0;
	  upMembers = 0;

	} 

bool Nebraska::challenge()
	{
		cout << "There is currently an unexpected snowstorm in Nebraska!" << endl;
		cout << "The weather suddenly plummetted to 10 Degrees Fahrenheit." << endl;
		cout << endl;
		int cont;
		cout << "Let's see if you brought outerwear. Press 1 to continue." << endl;
		cin >> cont;
		while (!cin || cont<1 || cont>1)
			{
			  cout << "Bad input, enter another." << endl;
			  cin.clear();
			  cin.ignore();
			  cin >> cont;
			}
		cout << endl;
		cout << "You brought " << clothing << " articles of clothing." << endl;
		if (clothing<members)
			{
			  cout << "That is only enough for " << clothing << " out of " << members << " members in your party." << endl;
			  cout << (members-clothing) << " randomly chosen members of your party will die of hypothermia." << endl;
			  upMembers = members-clothing;	//will delete this number of unclothed people
			}
		else
			{
			  cout << "Everyone in your wagon is warmly dressed for the cold conditions." << endl;
			}
	
		return true;

	}	

