/*******************************************************************************
File: Space.hpp 
Name: Calista Wong 
Description: This is the header file for the virtual class Space
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
using namespace std;

class Space
	{
	  public:
	  int distance,	
	      pounds, //these are the input values
	      clothing,
	      oxen,
	      food,
	      ammo,
	      spare,
	      money,
	      members,		
	      upOxen, //these are the updater values
	      upFood,
	      upAmmo,
	      upSpare, 		
	      upMoney,
	      upClothing,	
	      upMembers;		
	  string state;
	  Space*up;
	  Space*down;
	  Space*left;
	  Space*right;
	  //functions
	  virtual bool challenge() = 0; //return true if survived, false if died
	  //setters	
	  void setClothing(int);
	  void setPounds(int);
	  void setOxen(int);
	  void setFood(int);
	  void setAmmo(int);
	  void setSpare(int);
	  void setMoney(int);
	  void setMembers(int);
	  //getters
	  string getState();
	  int getDistance();
	  //updaters
	  int updateOxen();
	  int updateFood();
	  int updateAmmo();
	  int updateSpare();
	  int updateMoney();
	  int updateMembers();
	  int updateClothing();
	};

#endif
