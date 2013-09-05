/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Pirate.h
 *
 *  This is the Pirate class (.h) file, it is the header of the
 *  Pirate.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
using namespace std;

#include "Tortoise.h"
#include "Hare.h"
#include "random.h"


class Pirate{

public:
	Pirate(int=20);//default constructor
	~Pirate();//destructor
	Pirate(const Pirate&);//copy constructor

	int getStrength() const;
	int getArmor() const;
	int getHealth() const;
	void hareAttack(class Hare*);
	void tortAttack(class Tortoise*);
	void print();
	void resetHealth();

private:
	int strength, armor, health;

};

#endif
