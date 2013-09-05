/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Hare.h
 *
 *  This is the Hare class (.h) file, it is the header of the
 *  hare.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HARE_H
#define HARE_H

#include <iostream>
using namespace std;

#include "random.h"
#include "Pirate.h"

class Hare{
friend class Pirate;

public:
        Hare(bool sword, int=8, int=5, int=30);//default constructor
	~Hare();//destructor
	Hare(const Hare&);//copy constructor

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

