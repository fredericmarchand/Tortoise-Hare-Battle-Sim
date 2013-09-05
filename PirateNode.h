/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  PirateNode.h
 *
 *  This is the PirateNode class (.h) file, it is the header of the
 *  PirateNode.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PIRATENODE_H
#define PIRATENODE_H

#include "Pirate.h"

class PirateNode{

public:

	PirateNode();//default constructor
	PirateNode(Pirate*);
	~PirateNode();//default destructor
	PirateNode(const PirateNode&);

	Pirate* getPirate();
	PirateNode* getNext();
	PirateNode* getPrevious();
	void setNext(PirateNode*);
	void setPrevious(PirateNode*);

private:
	Pirate *data;
	PirateNode *next;
	PirateNode *previous;
};

#endif
