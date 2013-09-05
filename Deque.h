/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Deque.h
 *
 *  This is the Deque class (.h) file, it is the header of the
 *  Deque.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef DEQUE_H
#define DEQUE_H

#include "Pirate.h"
#include "PirateNode.h"
using namespace std;
#include <iostream>

class Deque{

public:
	Deque();//default constructor
	~Deque();//destructor
	Deque(const Deque& d);//copy constructor

	void pushFront(Pirate*);
	void pushBack(Pirate*);
	void popFront();
	void popBack();
	Pirate* back() const;
	Pirate* front() const;
	bool empty() const;
	void printDeque();
	void resetHealth();

private:
	PirateNode *head, *tail;
	int count;
};

#endif
