/*******************************************************************************File: Nevada.cpp
Name: Calista Wong 
Description: This is the implementation file for the Nevada derived class.
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Nevada.hpp"

Nevada::Nevada()
	{
	  up = NULL;
	  down = NULL;
	  right = NULL;
	  left = NULL;
	  distance = 100;
	  state = "Nevada";
	  upFood = 0;
	  upAmmo = 0;
	  upOxen = 0;
	  upSpare = 0;
	  upMoney = 0;
	  upMembers = 0;
	}

bool Nevada::challenge()
	{
	  cout << "You are almost at your final destination! " << endl;
	  cout << "Your party has decided to make a pitstop in Nevada." << endl;
   	  int cont;
	  cout << "Press 1 to continue." << endl;
	  cin >> cont;
	  while (!cin || cont<1 || cont>1)
		{
		  cout << "Bad input, enter another." << endl;
		  cin.clear();
	  	  cin.ignore();
		  cin >> cont; 
		}
	  	
	  cout << "You have encountered Carson's Casino." << endl;
	  cout << "The owner, Carson, has a challenge for you." << endl;
	  cout << "If you can guess the sum of the two die that he will roll within a margin of 1, your assets (excluding your antidotes) will double in size. " << endl;
	  cout << "If you are unable to, everything you own (excluding the antidoe) will decrease by half." << endl;
	  cout << "This is an all or nothing deal!" << endl;
	  cout << "Do you want to take this challenge? Press 1 for yes and 2 for no. " << endl;
	  cin >> cont;
	  while (!cin || cont<1 || cont>1)
		{
		  cout << "Bad input, enter another." << endl;
		  cin.clear();
	  	  cin.ignore();
		  cin >> cont; 
		}

	  if (cont == 1) //yes
		{
		  cout << "Carson will now roll two 6-sided die." << endl; 	
		  int die1 = rand()%6+1;
		  int die2 = rand()%6+1;
		  int sum = die1+die2;
		  int userGuess;
		  cout << "What is your guess of their sum?"<< endl;
	    	  cin >> userGuess;
		  while (!cin)
			{
				cout << "Bad input, enter another." << endl;
		  		cin.clear();
	  	  		cin.ignore();
		  		cin >> userGuess; 
			}
		  cout << "The correct sum was " << sum << endl;
		  if (userGuess == sum || userGuess == sum-1 || userGuess == sum+1)
			{
				cout << "You guessed correctly or within the margin! Everything you own will now double." << endl;
				upOxen = oxen;
				upFood = food;
				upAmmo = ammo;
				upSpare = spare;
				upClothing = clothing;
				upMoney = money;
			}
		  else //guess was incorrect
			{	
				cout << "Your guess was incorrect and out of the margin. Everyone you own will now decrement by half." << endl;
				upOxen = (oxen*0.5)*-1;
				upFood = (food*0.5)*-1;
				upAmmo = (ammo*0.5)*-1;
				upSpare = (spare*0.5)*-1;
				upClothing = (clothing*0.5)*-1;
				upMoney = (money*0.5)*-1;

			}
		}
	  else //no
		{
		  cout << "You have decided to forgo this challenge. You will continue on the trail." << endl;
		}	
	  return true;
	}
