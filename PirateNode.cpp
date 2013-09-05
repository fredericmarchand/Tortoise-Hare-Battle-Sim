/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  PirateNode.cpp
 *
 *  This is the PirateNode class (.cpp) file, it is part of the
 *  model of the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "PirateNode.h"

//this is the default constructor for the piratenode class
PirateNode::PirateNode(): data(0), next(0), previous(0){
}

//this is a secondary constructor for the piratenode class which takes a pirate pointer as a parameter
PirateNode::PirateNode(Pirate* p): data(p), next(0), previous(0){
}

//this is the piratenode destructor, it frees any pirate stored in the data that has been allocated dynamically into memory
PirateNode::~PirateNode(){
	if(data != 0)
		delete data;	
}

//this is the copy constructor for the pirate node class
PirateNode::PirateNode(const PirateNode& p){
	Pirate *newPirate = new Pirate(*(p.data));
	data = newPirate;
	next = 0;
	previous = 0;

	/*data = p.data;
	next = p.next;
	previous = p.previous;*/
}

//this is the get function which returns a pointer to the pirate that the node is pointing to
Pirate* PirateNode::getPirate(){
	return data;
}

//this is the get function which returns the 'next' pirate node which this node is pointing to at
PirateNode* PirateNode::getNext(){
	return next;
}

//this is the get function which returns the 'previous' pirate node which this node is pointing to at
PirateNode* PirateNode::getPrevious(){
	return previous;
}

//this is the setter function which sets the next node that this node is pointing to
void PirateNode::setNext(PirateNode* p){
	next = p;
}

//this is the setter function which sets the previous node that this node is pointing to
void PirateNode::setPrevious(PirateNode* p){
	previous = p;
}




