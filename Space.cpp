/*******************************************************************************File: Space.cpp
Name: Calista Wong 
Description: This is the implementation for the Space class.
****************************************************************************/

#include "Space.hpp"


bool Space::challenge()
	{
	}

//setters

void Space::setPounds(int p)
	{
	  pounds = p;
	}

void Space::setClothing(int c)
	{
	  clothing = c;
	}

void Space::setOxen(int o)
	{
	  oxen = o;
	}

void Space::setFood(int f)
	{
	  food = f;
	}

void Space::setAmmo(int a)
	{
	  ammo = a;
	}

void Space::setSpare(int s)
	{
	  spare = s;
	}

void Space::setMoney(int m)
	{
	  money = m;
	}

void Space::setMembers(int m)
	{
	  members = m;	
	}	

//getters

string Space::getState()
	{
	  return state;
	}

int Space::getDistance()
	{
	  return distance;
	}

//updaters
int Space::updateOxen()
	{
	  return upOxen;	
	}

int Space::updateFood()
	{
	  return upFood;
	}

int Space::updateAmmo()
	{
	  return upAmmo;
	}

int Space::updateSpare()
	{
	  return upSpare;	
	}

int Space::updateMoney()
	{
	  return upMoney;
	}

int Space::updateMembers()
	{
	  return upMembers;	
	}

int Space::updateClothing()
	{
   	  return upClothing;
	}

