/*******************************************************************************File: Wyoming.cpp
Name: Calista Wong 
Description: This is the implementation file for the Wyoming class.
******************************************************************************/

#include <cstdlib> //to generate a random number
#include "Wyoming.hpp"

Wyoming::Wyoming()
	{
	  up = NULL;
	  down = NULL;
	  left = NULL;
	  right = NULL;
	  distance = 100;
	  state = "Wyoming";
	  upOxen = 0;
	  upFood = 0;
	  upAmmo = 0;
	  upSpare = 0;
	  upMoney = 0;
	  upMembers = 0;
	}

bool Wyoming::challenge()
	{
		cout << "Welcome to Wyoming, the state known for its cattle! " << endl;
		cout << endl;
		cout << "You have met a local farmer, Farmer Bob.  " << endl;
		cout << "Farmer Bob wants to strike a bet. If you guess the correct number he is thinking of, he will give you one of his oxen." << endl;
		cout << "You may use this ox to pull your wagon." << endl;
		cout << "Here's the catch. You must pay him $10 for every guess you make." << endl;

		cout << endl;
		int play;
		cout << "Do you wish to play Farmer Bob's game? Press 1 for yes and 2 for no." << endl;
		cin >> play;
		while (!cin || play<1 || play>2)
			{
			  cout << "Bad input, enter another." << endl;
			  cin.clear();
			  cin.ignore();
			  cin >> play;
			}	
		bool correctGuess = false;// assume false until true
		int spent = 0; //initialize spent to 0
		if (play ==1)
			{
			  int bobsNum = rand()%10+1;
			  while (play ==1)
				{
				  if (spent < money)
					{
					  spent = spent+10; //add to user's bill 
				  	  int userGuess;
				  	  cout << "Enter your guess (must be between 1-10)" << endl;
				  	  cin >> userGuess;
				  	  //input verify
				  	  while (!cin || userGuess<1 || userGuess>10)
					 	{
						  cout << "Bad input, enter another." << endl;
			  			  cin.clear();
			  			  cin.ignore();
			  			  cin >> userGuess; 		
						} 
				  	  if (userGuess == bobsNum)
						{
						  cout << "You have guessed correctly! You have earned an oxen." << endl;
						  upOxen = 1;
						  upMoney = (-1) * spent;
						  break;  
						}
					  else 
						{
						  cout << "You have guessed incorrectly. Do you want to guess again? " << endl;
						  cout << "Press 1 for yes and 2 for no." << endl;
						  cin >> play;
						  while (!cin || play<1 || play>2)
							{
			  					cout << "Bad input, enter another." << endl;
			  					cin.clear();
			  					cin.ignore();
			  					cin >> play;
							}	
						}	
					}
				  else //you have spent all your money
					{
						upMoney = (-1)* money;
						cout << "You have insufficient funds. You may not continue at this time. " << endl;
						break;
					}	
			  
				}
			}
		else
			{
			  cout << "You have decided not to play." << endl;
			}	
		return true;
	}

