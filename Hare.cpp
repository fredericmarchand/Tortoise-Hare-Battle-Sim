/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Hare.cpp
 *
 *  This is the Hare class (.cpp) file, it is part of the
 *  model of the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Hare.h"

//this is the default constructor for the hare
Hare::Hare(bool sword, int a, int b, int c){
	hasSword = sword;
	strength = a;
	if(sword == true)
		strength += 3;
	armor = b;
	health = c;
}

//this is the destructor
Hare::~Hare(){

}

//this is the copy constructor for the hare
Hare::Hare(const Hare& h){
	hasSword = h.hasSword;
	strength = h.strength;
	armor = h.armor;
	health = h.health;
}

//this is the get function for the strength of the hare
int Hare::getStrength() const {
	return strength;
}

//this is the get function for the armor of the hare
int Hare::getArmor() const {
	return armor;
}

//this is the get function for the health of the hare
int Hare::getHealth() const {
	return health;
}

//this is the set function for the health of the hare, it cant exceed 30
void Hare::setHealth(int i){
	if(i>30)
		i = 30;
	health = i;
}

//this function returns wether the hare is holding the sword or not
bool Hare::getSword() const {
	return hasSword;
}

//this function is used when the hare gets attacked by a pirate
void Hare::pirateAttack(Pirate *p){
	int i = randomInt(p->getStrength(), p->getStrength()*2);//the damage is a random number between the pirates strength and twice its strength
	i -= armor;//minus the tortoises armor
	if(i <= 0)//if the damage is less than 0
		i = 0;//the damage becomes 0
	health -= i;//reduce the health by the amount of damage
	
	if(health <= 0)//if the health is less than 0
		health = 0;//it becomes 0
}

