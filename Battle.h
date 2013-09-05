/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Battle.h
 *
 *  This is the Battle class (.h) file, it is the header of the
 *  Battle.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BATTLE_H
#define BATTLE_H

#include "Deque.h"
#include "PirateNode.h"
#include "Pirate.h"
#include "Tortoise.h"
#include "Hare.h"
#include "Screen.h"

class Battle{

public:

	Battle(float=0, float=0, float=0, float=0, float=0, float=0, float=0);//default constructor
	~Battle();//default destructor

	void setupBattle();
	void simulate(class Deque*, class Hare*, class Tortoise*);
	void results(Screen&);

private:
	float tortSuccess, tortPartSuccess, tortFail, hareSuccess, harePartSuccess, hareFail, totalRuns;
};

#endif
