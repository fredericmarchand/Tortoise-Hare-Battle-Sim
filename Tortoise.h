/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Tortoise.h
 *
 *  This is the Tortoise class (.h) file it contains all the 
 *  function prototypes and attributes for Tortoise.cpp
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TORTOISE_H
#define TORTOISE_H

#include <iostream>
using namespace std;

#include "random.h"
#include "Pirate.h"

class Tortoise{
friend class Pirate;

public:
	Tortoise(bool sword, int=5, int=8, int=30);//default constructor
	~Tortoise();//destructor
	Tortoise(const Tortoise&);//copy constructor
	
	int getStrength() const;
	int getArmor() const;
	int getHealth() const;
	void setHealth(int i);
	bool getSword() const;
	void pirateAttack(class Pirate*);


private:
	int strength, armor, health;
	bool hasSword;
};


#endif
