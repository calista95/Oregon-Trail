/*******************************************************************************File: gamePlay.hpp
Name: Calista Wong 
Description: This is the header file for the Game class
*************************************************************************/

#include <iostream>
#include <string>
#include "Person.hpp"
#include "Space.hpp"
#include <string>
#include <vector>
using namespace std;

class Game
	{
	  private:
	  vector<Person*>members;
	  int total, //total money
	      oxen,
	      food,
	      clothing,
	      ammo,
	      spare,
	      date,
	      antidote,		
	      distance,
	      distanceTraveled,
	      pounds;			
	  string month;
	  Space*spacePtr;
	  Space*head;
	  Space*forDelete;
	  bool won;
	  public:
	  Game();
	  ~Game();
	  void flow();
	  //prep
	  void createTrail();	
	  void createMembers();
	  void buySupplies();
	  void pickMonth();
	  void intro();
	  //game cycle 
	  void updateDay();
	  void viewLocation();
	  void updateLastLocation();
	  void feed();
	  void viewHealth();
	  void viewInventory(); 
	  void randomEvent();
	  //random events
	  void goodEvent();
	  void badEvent();
	  void hunt();
	  bool attemptHunt();
	  void sickness();
	}; 
