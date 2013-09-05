/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Deque.cpp
 *
 *  This is the Deque class (.cpp) file, it is part of the
 *  model of the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Deque.h"

//this is the default constructor for the deque
Deque::Deque() : head(0), tail(0), count(0){
}

//this is the destructor for the deque it deletes all the nodes that have been dynamically allocated into the heap
Deque::~Deque(){
	if(!empty()){
		PirateNode *currNode, *nextNode;
		currNode = head;
		while(currNode != 0){
			nextNode = currNode->getNext();
			delete currNode;
			currNode = nextNode;
		}
	}
}

//this is the copy constructor for the deque
Deque::Deque(const Deque& d){
	PirateNode *currNode = d.head;
	PirateNode *previousNode = 0;
	int i=0;
	while(currNode != 0){
		PirateNode *newNode = new PirateNode(*currNode);
		if(i==0){
			head = newNode;
		}
		if(currNode->getNext() == 0){
			tail = newNode;
		}
		if(previousNode != 0){
			previousNode->setNext(newNode);
			newNode->setPrevious(previousNode);
		}

		previousNode = newNode;
		currNode = currNode->getNext();
		i++;
	}


	/*PirateNode *currNode = d.head;
	PirateNode *previousNode = 0;
	int i=0;
	while(currNode != 0){
		Pirate *newPirate = new Pirate(*(currNode->getPirate()));
		PirateNode *newNode = new PirateNode(newPirate);
		if(i==0){
			head = newNode;
			head->setNext(0);
			head->setNext(0);
		}
		if(currNode->getNext() == 0){
			tail = newNode;
			tail->setNext(0);
		}
		newNode->setNext(0);
		if(previousNode != 0){
			previousNode->setNext(newNode);
			newNode->setPrevious(previousNode);
		}

		previousNode = newNode;
		currNode = currNode->getNext();
		i++;
	}*/

}

//this function pushes a given pirate at the front of the deque
void Deque::pushFront(Pirate* p){

	PirateNode *newNode = new PirateNode(p);
	newNode->setNext(0);
	newNode->setPrevious(0);

	if(count == 0)
		head = tail = newNode;
	else{
		newNode->setNext(head);
		head->setPrevious(newNode);
		head = newNode;
	}
	count++;
}

//this function pushes a given pirate at the back of the deque
void Deque::pushBack(Pirate* p){

	PirateNode *newNode = new PirateNode(p);
	newNode->setNext(0);
	newNode->setPrevious(0);
	if(count==0)
		head = tail = newNode;
	else{
		tail->setNext(newNode);
		newNode->setPrevious(tail);
		tail = newNode;
	}
	count++;
}

//this function pops the pirate at the front of the deque
void Deque::popFront(){
	if(count == 0)
		return;
	PirateNode *currNode = head;
	if(head->getNext() != 0){
		head = head->getNext();
		head->setPrevious(0);
	}
	else
		head = 0;
	delete currNode;
	count--;
}

//this function pops the pirate at the back of the deque
void Deque::popBack(){
	PirateNode *currNode = tail;
	if(tail->getPrevious() != 0){
		tail = tail->getPrevious();
		tail->setNext(0);
	}
	else
		tail = 0;
	delete currNode;
	count--;
}

//this function returns a pointer to the pirate that the back of the deque is pointing to
Pirate* Deque::back() const{
	if(tail == 0)
		return 0;
	return tail->getPirate();
}

//this function returns a pointer to the pirate that the front of the deque is pointing to
Pirate* Deque::front() const{
	if(head == 0)
		return 0;
	return head->getPirate();
}

//this function returns wether the deque is empty or not
bool Deque::empty() const{
	if(count == 0)
		return true;
	return false;
}

//this function prints every pirate contained in the deque
void Deque::printDeque(){
	PirateNode *currNode = head;
	while(currNode != 0){
		currNode->getPirate()->print();
		currNode=currNode->getNext();
	}
}

//this function resets the health of every pirate in the deque
void Deque::resetHealth(){
	PirateNode *currNode = head;
	while(currNode != 0){
		currNode->getPirate()->resetHealth();
		currNode = currNode->getNext();
	}
}


