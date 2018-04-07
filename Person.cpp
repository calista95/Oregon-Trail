/*******************************************************************************File: Person.cpp
Name: Calista Wong
Description: This is the implementation for the Person class.
*************************************************************************/

//#include <iostream>
//#include <string>
#include "Person.hpp"
//using namespace std;

Person::Person(int i, string n)
	{
	  age = i;
	  health = 10;
	  hunger = 10;
	  warmth = 10;
	  name = n;
	}

//getters
int Person::getAge()
	{
	  return age;
	}

int Person::getHealth()
	{
	  return health;
	}

int Person::getWarmth()
	{
	  return warmth;
	}

int Person::getHunger()
	{
	  return hunger;
	}

string Person::getName()
	{
	  return name;
	}

//setters
void Person::setHealth(int i)
	{
	  health = health+i;
	}

void Person::setWarmth(int i)
	{
	  warmth = warmth+i;
	}

void Person::setHunger(int i)
	{
	  hunger = hunger+i; 
	}
