/*******************************************************************************File: Person.hpp
Name: Calista Wong 
Description: This is the header file for the Person class.
**************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
using namespace std;

class Person
	{
	  private:
	  int health,
	      hunger,
	      warmth,
	      age;
	  string name;
	  public:
	  Person(int, string);
	  //getters
	  int getAge();
	  int getHealth();
	  int getWarmth();
	  int getHunger();
	  string getName();
	  //setters
	  void setHealth(int);
	  void setWarmth(int);
	  void setHunger(int);
	}; 
#endif
