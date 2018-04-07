/*******************************************************************************File: gamePlay.cpp
Name: Calista Wong 
Description: This is the implementation file for the Game class
****************************************************************************/
#include <iostream>
#include <cstdlib>
#include "gamePlay.hpp"
#include "Missouri.hpp"
#include "Wyoming.hpp"
#include "Idaho.hpp"
#include "Nebraska.hpp"
#include "Nevada.hpp"

using namespace std;

Game::Game() //constructor
	{
	  total = 1000;		//total money to begin with	
	  date = 1;		//start on the 1st of the month
	  distance = 2500;      //total distance to travel
	  won = true;		//assume won	
	  antidote=0;		//antidote for fighting disease and adding points later on
	  distanceTraveled = 0; //distance from the last state
	  spacePtr = NULL;      //this is the pointer that points to the current location
	  pounds = 2000;	//weight of wagon alone
	}

Game::~Game()//destructor
	{
	  //delete locations first	
	  //forDelete pointer is pointing to the head	
	  while (forDelete->right != NULL)
		{
			Space*temp = forDelete->right;
		 	Space*trash = forDelete;
			delete trash;
			trash = NULL;
			forDelete = temp; 
		}
	  //then delete remaining people
	  for (int i=0; i<members.size(); i++)
		{
			delete members[i];
			members[i] = NULL;
		}
	}
	
 
void Game::flow()
	{
	  int start;
	  //overview of the game	
	  cout << "Welcome to Oregon Trail!" << endl;
	  cout << "This game of survival and risktaking will test your limits and luck." << endl;
	  cout << "You will traverse 5 states 30 days or less before you hit your final destination- Portland, Oregon: "<< endl;
	  cout << "Each state will present its own unique challenges, but you must go through ALL of them to win this game." << endl;
	  cout << "Some of you may die on this difficult and arduous journey, but it is a sacrifice you must be willing to make. " << endl;
	  cout << "Press 1 to begin. Press 2 to exit." << endl;
	  cin >> start;
	  while (!cin || start<1 || start>2)
	   {
		cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >>  start;
	   }
	  if (start ==1)
	   {
	     //prep
	     int cont = 2; //variable for continue
	     this->createTrail();  //NEW
	     this->createMembers();
	     this->buySupplies();
	     this->pickMonth();
	     this->intro();
	     do 
	       {
	         //game cycle
	         this->updateDay();
		 if (won == false)
		  {
		    cout << "Game over." << endl;
		    break;	
		  }	

	         this->viewHealth();
	         this->feed();	
		 if (won == false)
		  {
		    cout << "Game over." << endl;
		    break;	
		  }	
	         this->viewInventory();
		 this->viewLocation();
		 this->updateLastLocation();
		 int keepGoing;
		 cout << "Press 1 to continue." << endl;
		 cin >> keepGoing;
		 while (!cin || keepGoing<1 || keepGoing>1)
		   {
			cout << "Bad input, enter another." << endl;
			cin.clear();
			cin.ignore();
			cin >> keepGoing;
		   }	
	         this->randomEvent();
	         if (won == false)
		   {
		    cout << "Game over." << endl;
		    break;
		   }	
   

	         cout << "Press 1 to proceed to next day." << endl;
	         cin >> cont;
	         while (!cin || cont <1 || cont>1)
		   {
		     cout << "Bad input, enter another." << endl;
	  	     cin.clear();
	  	     cin.ignore();
		     cin >> cont;
		   }
	         }
		while (distance >0 && won == true && date<=30);
			
		if (won == true)
			{
			  //calculate player's score based on the number of items that are remaining
			  int score = (members.size()*100)+(oxen*50)+(food*1)+(ammo*10)+(clothing*3)+(spare*5)+(antidote*35);
			  cout << "Congratulations! You have arrived in Portland, Oregon." << endl;
			  cout << "You are now ready to start your new life in the Oregon Territory!" << endl;
			  cout << "Your total score is: " << score << endl;
			}
		else //won == false
			{
			  cout << "You have lost the game." << endl;
			}
		
	    }	

	  else //start ==2
	    {
	    	cout << "You have successfully exited the game." << endl;
	    }
	}


/****************************************************************************
PREPARATION FOR JOURNEY
*****************************************************************************/

void Game::createTrail()
	{
	  //create and link all 5 states
	  Space*temp;
	  spacePtr = new Missouri; //intial status: spacePtr is holding a mountain object
	  head = spacePtr;
	  forDelete = spacePtr;
	  temp = new Nebraska;
	  spacePtr->right = temp;
	  spacePtr = new Wyoming;
	  temp->right = spacePtr;
	  temp = new Idaho;
	  spacePtr->right = temp;
	  spacePtr = new Nevada;
	  temp->right = spacePtr;	
	}

void Game::createMembers()
	{
	  cout << "You will have 5 members for your wagon. " << endl;
	  cout << "Please enter their names and ages. " << endl;

	  int personNum=1;
	  string name;
	  int age;
	  for (int i=0; i<5; i++)
	   {
	     cout << "Person " << personNum << endl;

	     //enter name	
	     cout << "Name: " ;
	     cin.ignore();
	     getline(cin, name);
	     while (!cin)
	      {
		cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		getline(cin, name);
	      }

	     //enter age 	
	     cout << "Age: ";
	     cin >> age;	
	     while (!cin || age<=0)
	      {
		cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >> age;
	      }
	     if (age <= 12) //if person is less than or equal to 12, add 80 pounds to total pounds of wagon
		{
		  pounds = pounds + 80;
		}	
	     else //anyone else older will be 150 pounds
		{
		  pounds = pounds + 150;
		}	
	
	     //create object and put into vector
	     Person*person = new Person(age, name);
	     members.push_back(person);	
	     personNum++;
	   }

	  //print out summary
	  cout << endl;
	  cout << "Your team members: " << endl;
	  for (int i=0; i<5; i++)
	    {
		cout << members[i]->getName() << " " << members[i]->getAge() << endl;
	    }
	  cout << endl;
	}

void Game::buySupplies()
	{
	  cout << "You have arrived at the convenience store! " << endl;
	  cout << "You have a budget of $1000. Use it wisely!" << endl;

	  cout << "_______" << endl;
	  cout << "Pricing" << endl;
	  cout << "_______" << endl;
	  cout << "a. Oxen: $100/each " << endl;       //oxen weight: 1000 pounds each
	  cout << "b. Food: $2/pound " << endl;        //food weight: 2 pounds each serving 
	  cout << "c. Clothing: $10/bundle " << endl;  //clothing weight: 5 pounds per pack
	  cout << "d. Ammunition: $20/box " << endl;   //ammo weight: 10 pounds per box
	  cout << "e. Spare parts: $50/set " << endl;  //spare parts weight: 25 pounds per set

	  cout << endl;

	  int spent=0; //keep track of total spent
	  bool onBudget = true;
	
	do
	{
	  //Purchase oxen
	  cout << "Oxen are necessary to pull your wagon." << endl;
	  cout << "You must have at least ONE oxen to start your journey. Please enter how many you want." << endl;
	  cin >> oxen;
	  while (!cin || oxen <0)
	    {
	        cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >> oxen;
	    }
	   spent = spent+ oxen*100;
	   cout << "Spent: " << spent << endl;
	   cout << "Left: " <<total-spent << endl;
	   cout << endl; 
	  
	  //Purchase food
	  cout << "Each person goes through 1 serving of food a day. " << endl;
	  cout << "Please enter how many pounds of food you want to purchase. " << endl;
	  cin >> food;
	  while (!cin || food<0)
	    {
	        cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >> food;
	    }
	  
	   spent = spent+ food*2;
	   cout << "Spent: " << spent << endl;
	   cout << "Left: " << total-spent << endl;
	   cout << endl; 

	  //Purchase clothing
	  cout << "Extra clothing comes in handy, especially if you're traversing cold territory. " << endl;
	  cout << "Please enter how many bundles of clothing you want to purchase. " << endl;
	  cin >> clothing;
	  while (!cin || clothing<0)
	    {
	        cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >> clothing;
	    }

	   spent = spent+ clothing*10;
	   cout << "Spent: " << spent << endl;
	   cout << "Left: " << total-spent << endl;
	   cout << endl; 

	  //Purchase ammo
	  cout << "In the case of enemy encounters, you must have protection!" << endl;
	  cout << "Enter how many boxes of ammo you want to purchase. " << endl;
	  cin >> ammo;
	  while (!cin || ammo<0)
	    {
	        cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >> ammo;
	    }

	   spent = spent+ ammo*20;
	   cout << "Spent: " << spent << endl;
	   cout << "Left: " << total-spent << endl;
	   cout << endl; 


	  //Purchase spare parts
	  cout << "You never know if your wagon malfunctions! So spare parts are always a safe bet." << endl;
	  cout << "Please enter how many spare parts you want to purchase." << endl;
	  cin >> spare;
	  while (!cin || spare<0)
	    {
	        cout << "Bad input, enter another." << endl;
	  	cin.clear();
	  	cin.ignore();
		cin >> spare;
	    }

	   spent = spent+ spare*50;
	   cout << "Spent: " << spent << endl;
	   cout << "Left: " << total-spent << endl;
	   cout << endl; 

	  //verify that user has enough
	  if (spent > total)
	    {
		cout << "Oh no! Looks like you have gone over your limit. You need to repurchase your items again." << endl;
		cout << endl;
		spent = 0;
		onBudget = false;
		spent = 0;
	    }
	  else
		onBudget = true;	
	}
	while(onBudget == false);
	  	

	  //Summary
	  cout << "_____________________" << endl;
	  cout << "Your total purchases: " << endl;
	  cout << "_____________________" << endl;
	  cout << "Oxen: " << oxen << " : " << "$" << oxen*100 << endl; 
	  cout << "Food: " << food << " servings : " << "$" << food*2  << endl;
	  cout << "Clothing: " << clothing << " bundles : " << "$" << clothing*10 << endl;
	  cout << "Ammo: " << ammo << " boxes: " << "$" << ammo*20 << endl;
	  cout << "Spare supplies: " << spare << " sets: $" << spare*50 << endl;
	  cout << endl;
	  cout << "You have spent a total of: $" << spent << endl;
	  total = total-spent;
	  cout << "That leaves you with: $" << total << " left over!" << endl;
	  cout << endl;

	  //get total pounds of everything	
	  pounds = pounds + ((oxen*1000)+ (food*2) + (clothing*5) + (ammo*10) + (spare*25)); 

	} 

void Game::pickMonth()
	{
	  int choice;
	  cout << "Pick the month that you want to begin your travels." << endl;
	  cout << "1. March " << endl;
	  cout << "2. April " << endl;
	  cout << "3. May " << endl;
	  cout << "4. June " << endl;
	  cin >> choice;
	  while (!cin || choice<1 || choice>4)
	  	{
		 cout << "Bad input, enter another." << endl;
	  	 cin.clear();
	  	 cin.ignore();
		 cin >> choice;
		}
	  switch (choice)
	  	{
		 case 1:
		   month = "March";
		   break;	
		 case 2:
		   month = "April";
		   break;	
		 case 3:
		   month = "May";
		   break;	
		 case 4:
		   month = "June";
		   break;	
	 	}
	}

void Game::intro()
	{
	  cout << "______________________________________________________________________________" << endl; 
	  cout << "The year is 1836. You are about to begin on a once in a lifetime adventure!" << endl;
	  cout << "You will begin in Independence, Missouri and end your journey in Salem, Oregon." << endl;
	  cout << "You have a limit of 30 days to complete your journey." << endl;
	  cout << "Total expected miles: 2500" << endl;	
          cout << "______________________________________________________________________________" << endl; 
	  cout << endl;
	  int start;
	  cout << "Press 1 to get started!" << endl;
	  cin >> start;
	  while (!cin || start <1 || start>1)
		{
			cout << "Bad input, enter another." << endl;
	  	 	cin.clear();
	  	 	cin.ignore();
		 	cin >> start; 
		} 
	}

/*******************************************************************************
GAME CYCLE
******************************************************************************/


void Game::updateDay()
	{
	  cout << "________________________________________________" << endl;
	  cout << "Today: " << month << " " << date << " 1836." << endl;
	  cout << "Miles left: " << distance << endl;
	  cout << "Miles from last state: " << distanceTraveled << endl; 
	  cout << "________________________________________________" << endl;

	  if (date <30)
	    {	
		date++;
		distance = distance - head->getDistance();  //distance traveled depends on the current terrain
		if (distanceTraveled == 500) //for every 500 miles, location will change 
		  {
			distanceTraveled = 0; //reset distance traveled since last terrain
			head = head->right;
		  }
	    }	
	  else //date =0 
	 	{
		  cout << "You have run out of days." << endl;
		  won = false;
		}	

	  cout << endl;
	} 


void Game::viewLocation()
	{
	  cout << "Your current location: " << head->getState() << endl;
	  if (distanceTraveled == 0 || distanceTraveled == 500) //first day at the new location
	   {
		//set clothing and pounds
		head->setClothing(clothing);
		head->setPounds(pounds);
		head->setOxen(oxen);
	   	head->setFood(food);
		head->setAmmo(ammo);
		head->setSpare(spare);
		head->setMoney(total);
		head->setMembers(members.size());
		if (head->challenge() == false)
			{
			  won = false;
			}
		else //update supply
			{
			  oxen = oxen + head->updateOxen();
			  food = food + head->updateFood();
			  ammo = ammo + head->updateAmmo();
			  spare = spare + head->updateSpare();	
			  total = total + head->updateMoney();
			  int deleteMembers = head->updateMembers();
				{
				  if (deleteMembers >0)
					{
						for (int i=0; i<deleteMembers; i++)
							{
							  int deletePerson = rand()%members.size();
							  delete members[deletePerson];
						 	  members[deletePerson]= NULL;
							  members.erase(members.begin()+(deletePerson)); 
	  						  
							}
					}
				}
			}
	   }  
	   cout << endl;
        }

void Game::updateLastLocation() //this updates the distance from the last state 
	{
		distanceTraveled = distanceTraveled + head->getDistance();

	}

void Game::viewHealth() //displays health of members
	{
	  cout << "Health status of remaining members:" << endl;
	  for (int i=0; i<members.size() ; i++)
		{
		  cout << members[i]->getName()<< ": " << members[i]->getHealth() << endl;
		}
	}

void Game::viewInventory() //displays inventory available at the moment 
	{
	  cout << "__________________" << endl;
	  cout << "Inventory Update:" << endl;	
	  cout << "__________________" << endl;
	  cout << "Oxen: " << oxen << endl;
	  cout << "Food: " << food << " servings" << endl;
	  cout << "Ammo: " << ammo << " boxes" << endl;
	  cout << "Clothing: " << clothing << " bundles" << endl;
	  cout << "Spare supplies: " << spare << " sets" << endl;
	  cout << endl;
	}

void Game::feed() 
	{

		if (food >= members.size())
		 {
		   food = food-(members.size()); //every person consumes 
		   cout << "Everyone in your wagon has been fed." << endl;
		   pounds = pounds-((members.size())*2);
		 }
		else //food not enough for everyone 	
		 {
		  cout << "You do not have enough to feed all members of your wagon. Since everyone had to share, nobody ate a full serving. Everyone will lose their health points by 2." << endl;
		  pounds = pounds-(food*2);
		  food = 0;
		  for (int i=0; i<members.size(); i++)
			{
				members[i]->setHealth(-2);
				if (members[i]->getHealth() <= 0)
					{
					  cout << members[i]->getName() << " has starved to death." << endl;
					  delete members[i];
					  members[i]= NULL;
					  members.erase(members.begin()+(i)); 
					  if (members.size()==0)
						   {
							won = false;
							break;
						   }
					}

			}
		 }
	}


void Game::randomEvent()
	{
	  //50% chance of generating a good event, 50% chance of generating a bad event
	  int random = rand()%2+1;
	  switch (random)
	   {
	  	case 1:
		this->goodEvent();
		break;
		case 2:
		this->badEvent();
	   }	
	}
/**************************************************************************************
RANDOM EVENTS
************************************************************************************/

void Game::goodEvent()
	{
	   int money; 
	   int random = rand()%4+1;
	   switch (random)
	    {
		case 1: //hunting nearby
			cout << "Hunting opportunity!" << endl;
			this->hunt();
			break;
		case 2: //arrived at a convenience store
			int visitStore;
			cout << "You have arrived at a convenience store." << endl;
			cout << "Do you want to make any purchases? Press 1 for yes and 2 for no." << endl;
			cin >> visitStore;
			while (!cin || visitStore<1 || visitStore>2)
				{
				  cout << "Bad input, enter another." << endl;
	  	 		  cin.clear();
	  	 		  cin.ignore();
		 		  cin >> visitStore;		
				}
			if (visitStore == 1)
				{
				  this->buySupplies();
				}
			break;
		case 3: //find money on the ground
			money = rand()%100+1; //number between 1-100
			cout << "It's your lucky day! You found $" << money << " on the ground." << endl;
			cout << endl;
			total = total+money;
			break;
	  	case 4: //antidote
			cout << "You have met a healer along the way who has decided to grant you an antidote that can heal ANY ailment!" << endl;
			cout << endl;
		   	antidote++;
	
	    }	
	
	}

void Game::badEvent()
	{
	   int random = rand()%5+1;
	   int rot;	
	   int stole;
	   int temp;
	   switch (random)
	    {
		case 1: //sickness
			this->sickness();
		break;
		case 2: //one of oxen has died
			cout << "One of your oxen has died." << endl;
			pounds = pounds - 1000;
			oxen = oxen-1;
			if (oxen >0)
				{
				  cout << "You are now left with " << oxen << " oxen." << endl;
				  cout << "Remember that you must have at least ONE oxen to pull your wagon and proceed with your travels." << endl;
				}
			else //oxen>0
				{
				  cout << "You are now left with " << oxen << " oxen." << endl;
				  cout << "Your wagon is stuck! " << endl;
			    	  won = false; //lost game
				} 
		break;
		case 3: //wheels have broken
			cout << "A wheel on your wagon has broken!" << endl;
			if (spare >0)
				{
				  cout << "Good thing you have a spare wheel!" << endl;
				  cout << "One spare set will be applied to fix this problem so that you may continue." << endl;
				  spare = spare--;
				  pounds = pounds - 25; 
				} 
			else //no spare sets 
				{
				  cout << "You have no spare sets left. " << endl;
				  won = false;
				}
		break;
		case 4: //food turned rotten
			if (food>0)
			  {
			   temp = food/2;
			   rot = rand()%temp+1;	
			   cout << rot << " lbs of your food has rotted!" << endl;
			   pounds = pounds - rot;
			   food = food-rot;
			  }
		break;
		case 5: //robbed
			if (total>0)
			  {
			   cout << "A robber has mugged your wagon! " << endl;
			   temp = total/2;
		 	   stole = rand()%temp;
			   cout << "$" << stole << " has been deleted from your money stash." << endl;	
			   total = total-stole;
			   cout << "That leaves you with $" << total << " left." << endl;
			  }
	    }	
	    cout << endl;	
	}

void Game::hunt()
	{
	   int random = rand()%3+1;
	   int hunt;
	   switch (random)
	    {
		case 1: //bison
		cout << "A wild bison has appeared!" << endl;
		cout << "Do you want to try and hunt it? Succeeding will provide you with 1000 lb of food." << endl;
		cout << "Attempting to will cost you one box of ammo." << endl;
		cout << "Press 1 for yes and 2 for no." << endl; 
		cin >> hunt;
		while (!cin || hunt <1 || hunt>2)
		  {
			cout << "Bad input, enter another." << endl;
	  	 	cin.clear();
	  	        cin.ignore();
		 	cin >> hunt;
		  }
		if (hunt ==1 )
		  {
			if (ammo>=1)
			  {
		            ammo = ammo-1;
			    pounds = pounds - 10; 
		            if (this->attemptHunt() == true)
			     {
			  	food = food + 1000;
				pounds = pounds + 1000; 
			     }
			  }
			else //ammo=0
		  	  {
				cout << "You do not have enough ammo to proceed." << endl;
			  }
		  }

		cout << endl;
		break;

		case 2: //deer
		cout << "A wild deer has appeared!" << endl;
		cout << "Do you want to try and hunt it? Succeeding will provide you with 300 lb of food." << endl;
		cout << "Attempting to will cost you one box of ammo." << endl;
		cout << "Press 1 for yes and 2 for no." << endl; 
		cin >> hunt;
		while (!cin || hunt <1 || hunt>2)
		  {
			cout << "Bad input, enter another." << endl;
	  	 	cin.clear();
	  	        cin.ignore();
		 	cin >> hunt;
		  }
		if (hunt ==1)
		  { 
		     if (ammo>=1)
		       {	
		        ammo = ammo-1;
			pounds = pounds - 10;
		        if (this->attemptHunt() == true)
			  {
			  	food = food + 300;
				pounds = pounds + 300;
			  }
		       }
		     else //ammo=0
		       {
				cout << "You do not have enough ammo to proceed." << endl;
		       }
		   }
		cout << endl;
		break;

		case 3: //squirrel
		cout << "A wild squirrel has appeared!" << endl;
		cout << "Do you want to try and hunt it? Succeeding will provide you with 10 lb of food." << endl;
		cout << "Attempting to will cost you one box of ammo." << endl;
		cout << "Press 1 for yes and 2 for no." << endl; 
		cin >> hunt;
		while (!cin || hunt <1 || hunt>2)
		  {
			cout << "Bad input, enter another." << endl;
	  	 	cin.clear();
	  	        cin.ignore();
		 	cin >> hunt;
		  }
		if (hunt ==1)
		  {
		    if (ammo>=1)
		      {	
		        ammo = ammo-1;
			pounds = pounds - 10;
		        if (this->attemptHunt() == true)
			  {
			  	food = food + 10;
				pounds = pounds + 10;
			  }
		      }
		    else //ammo=0
		      {
				cout << "You do not have enough ammo to proceed." << endl;
		       }

	          }
		cout << endl;
	   }
	}
bool Game::attemptHunt()
	{
		
		int random = rand()%2+1;
		if (random == 1)
			{
				cout << "Your hunting attempt has succeeded." << endl;
				cout << endl;
				return true;
			}
		else
			{
				cout << "Your hunting attempt has failed." << endl;
				cout << endl;
				return false;
			}
	}

void Game::sickness()
	{
		int useAnti;
		int random = rand()%(members.size()); //random number between 0 and (number of members-1)
		int illness = rand()%4+1; //random number between 1 and 4
		switch (illness)
			{
				case 1: //common cold, reduce everyone's health
				cout << "All of your wagon members have come down with the common cold. Luckily, they have all recovered!" << endl;
				cout << "However, each person's health has gone down by 3 points. " << endl;
				for (int i = 0; i<members.size(); i++)
				   {
					members[i]->setHealth(-3); 
					if (members[i]->getHealth() <= 0)
					   {
					     cout << members[i]->getName() << " has died." << endl;
					     delete members[i];
	  			             members[i]= NULL;
					     members.erase(members.begin()+(i)); 
					   }
   				   }	
		
				break;
				case 2: //dysentery, death
				cout << members[random]->getName() << " has contracted dysentery and died." << endl;
				if (members[random]->getAge() <=12) //dead member is a child
					{
						pounds = pounds -80;
					}
				else	//dead member is an adult 
					{
						pounds = pounds - 150;
					}
				delete members[random];
	  			members[random]= NULL;
				members.erase(members.begin()+(random));
				break;
				case 3: //cholera, death
				cout << members[random]->getName() << " has contracted cholera and died." << endl;
				if (members[random]->getAge() <=12) //dead member is a child
					{
						pounds = pounds -80;
					}
				else	//dead member is an adult
					{
						pounds = pounds - 150;
					}
				delete members[random];
	  			members[random]= NULL;
				members.erase(members.begin()+(random)); 
				break;
				case 4: //diphteria, recovered
				cout << members[random]->getName() << " has contracted diphteria." << endl;
				if (antidote >0)
					{
					  cout << "Luckily, you have " << antidote << " left." << endl;
					  cout <<  "Using an antidote will prevent " << members[random]->getName() << "'s health from being brought down 5 points. Do you want to use it?" << endl;				  
					  cout << "Press 1 for yes and 2 for no." << endl;
					  cin >> useAnti;
					  while (!cin || useAnti <1 || useAnti>2)
						{
						  cout << "Bad input, enter another." << endl;
	  	 		  	          cin.clear();
	  	 		  	          cin.ignore();
		 		  	          cin >> useAnti;	  
						} 	   
					  if  (useAnti ==1)
						{
						  cout << "Your antidote has been applied." << endl;
						  antidote--;	    
						}
					  else
						{
						  cout << "You have elected not to use your antidote. " << members[random]->getName() << "'s health will now decline by 5 points." << endl; 
						  if (members[random]->getHealth() <= 0)
						   {
						     cout << members[random]->getName() << " has died." << endl;
						     if (members[random]->getAge() <=12) //dead member is a child
							{
								pounds = pounds -80;
							}
						     else //dead member is an adult
							{
								pounds = pounds - 150;
							}
						      delete members[random];
	  				 	      members[random]= NULL;
						      members.erase(members.begin()+(random)); 
						   }
	
						}				
					}
				else
					{
					  cout << "You have no antidotes available at the moment. " << members[random]->getName() << "'s health will now decline by 5 points." << endl;
					  members[random]->setHealth(-5);
					  if (members[random]->getHealth() <= 0)
						{
						  cout << members[random]->getName() << " has died." << endl;
						  if (members[random]->getAge() <=12) //dead member is a child
							{
								pounds = pounds -80;
							}
						     else //dead member is an adult
							{
								pounds = pounds - 150;
							}
						  delete members[random];
	  				 	  members[random]= NULL;
						  members.erase(members.begin()+(random)); 
						}
					}
				}
		
		//if no members remain, game is over
		if (members.size() == 0)
			{
				won = false;
			}
	}


