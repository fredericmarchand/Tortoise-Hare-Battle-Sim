/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Pirate.cpp
 *
 *  This is the Pirate class (.cpp) file, it is part of the
 *  model of the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Pirate.h"

//this is the default constructor for the pirate class
Pirate::Pirate(int h){
	strength = randomInt(4, 7);
	armor = randomInt(2, 4);
	health = h;
}

//this is the destructor
Pirate::~Pirate(){

}

//this is the copy constructor for the pirate class
Pirate::Pirate(const Pirate& p){
	strength = p.strength;
	armor = p.armor;
	health = p.health;
}

//this is the get function which returns the strength of the pirate
int Pirate::getStrength() const {
	return strength;
}

//this is the get function which returns the armor of the pirate
int Pirate::getArmor() const {
	return armor;
}

//this is the get function which returns the health of the pirate
int Pirate::getHealth() const {
	return health;
}

//this function resets the health of a given pirate to its initial value of 20
void Pirate::resetHealth(){
	health = 20;
}

//this function is used when a hare attacks the pirate
void Pirate::hareAttack(Hare* h){
	int i = h->getStrength()-armor;
	health -= i;

	if(health <= 0){
		health = 0;
		h->setHealth(h->getHealth()+3);//if the pirate dies the hero gains 3 health points
	}
}

//this function is used when a tortoise is attacking the current pirate
void Pirate::tortAttack(Tortoise* t){
	int i = t->getStrength()-armor;
	health -= i;
	
	if(health <= 0){
		health = 0;
		t->setHealth(t->getHealth()+3);//if the pirate dies the hero gains 3 health points
	}
}

//this function prints the health strength and armor of a given pirate
void Pirate::print(){
	cout<<"i am a pirate with health "<<health<<", strength: "<<strength<<" and armor: "<<armor<<endl;
}


