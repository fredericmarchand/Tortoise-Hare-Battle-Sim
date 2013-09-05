/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Tortoise.cpp
 *
 *  This is the Tortoise class (.cpp) file it is part of the 
 *  model for the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Tortoise.h"

//this is the default constructor for the tortoise class
Tortoise::Tortoise(bool sword, int a, int b, int c){
	hasSword = sword;
	strength = a;
	if(sword == true)
		strength += 3;
	armor = b;
	health = c;
}

//this is the destructor
Tortoise::~Tortoise(){

}

//this is the copy constructor for the tortoise
Tortoise::Tortoise(const Tortoise& t){
	hasSword = t.hasSword;
	strength = t.strength;
	armor = t.armor;
	health = t.health;
}

//this is the get function for the strength of the tortoise
int Tortoise::getStrength() const {
	return strength;
}

//this is the get function for the armor of the tortoise
int Tortoise::getArmor() const {
	return armor;
}

//this is the get function for the health of the tortoise
int Tortoise::getHealth() const { 
	return health;
}

//this is the set function for the health of the tortoise
void Tortoise::setHealth(int i){
	if(i>30)
		i=30;
	health = i;
}

//this is the get function to determine if the Tortoise is wielding the sword or not
bool Tortoise::getSword() const {
	return hasSword;
}

//this function is used when the tortoise is being attacked by a pirate,
void Tortoise::pirateAttack(Pirate *p){
	int i = randomInt(p->getStrength(), p->getStrength()*2);//the damage is a random number between the pirates strength and twice its strength
	i -= armor;//minus the tortoises armor
	if(i <= 0)//if the damage is less than 0
		i = 0;//the damage becomes 0
	health -= i;//reduce the health by the amount of damage
	
	if(health <= 0)//if the health is less than 0
		health = 0;//it becomes 0
}



