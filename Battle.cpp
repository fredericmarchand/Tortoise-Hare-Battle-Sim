/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Battle.cpp
 *
 *  This is the Battle class (.cpp) file, it is the
 *  controller of the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Battle.h"

//this is the default constuctor for the battle class
Battle::Battle(float a, float b, float c, float d, float e, float f, float g){
	tortSuccess = a;
	tortPartSuccess = b;
	tortFail = c;
	hareSuccess = d;
	harePartSuccess = e;
	hareFail = f;
	totalRuns = g;
}

//this is the destructor
Battle::~Battle(){

}

//this function sets up the battle
void Battle::setupBattle(){
	Screen newScreen(0,0);
	newScreen.startScreen();
	for(int j=0; j<200; j++){
		Deque *newDeque = new Deque();//create the deque

		//create the heros
		Hare swordHare(true);
		Hare regHare(false);
		Tortoise swordTort(true);
		Tortoise regTort(false);

		//store pirates in the deque
		for(int i=0; i<10; i++){
			Pirate *newPirate = new Pirate();
			if(i%2 == 0){
				newDeque->pushFront(newPirate);
			}
			else{
				newDeque->pushBack(newPirate);
			}
		}
	
		//Deque *newDeque2;//this copies the deque into another one using the copy constructor from the deque class
		if(j%2 ==0)
			simulate(newDeque, &swordHare, &regTort);
		else
			simulate(newDeque, &regHare, &swordTort);

		delete newDeque;
	}
		results(newScreen);//output the results
}

//this function performs simulations of the fights
void Battle::simulate(class Deque* deque, class Hare* hare, class Tortoise* tort){
	//FIGHT
	while((!deque->empty()) && (hare->getHealth() != 0) || (tort->getHealth() != 0)){
		while(true){
			if((deque->empty())||((hare->getHealth() == 0) && (tort->getHealth() == 0))||(tort->getHealth() == 0))
				break;

			Pirate *pirate = deque->front();//the tortoise fights the pirate at the front of the deque
			if(pirate->getHealth() != 0){
				pirate->tortAttack(tort);
			}
			if((tort->getHealth() != 0)&&(pirate->getHealth() != 0))
				tort->pirateAttack(pirate);
			if(pirate->getHealth() == 0){
				deque->popFront();
				break;
			}
			if((deque->empty())||((hare->getHealth() == 0) && (tort->getHealth() == 0))||(tort->getHealth() == 0))
				break;
		}
		if(deque->empty())
			break;
		if((hare->getHealth() == 0) && (tort->getHealth() == 0))
			break;
	
		while(true){
			if((deque->empty())||((hare->getHealth() == 0) && (tort->getHealth() == 0))||(hare->getHealth() == 0))
				break;

			Pirate *pirate = deque->back();
			if(pirate->getHealth() != 0){
				pirate->hareAttack(hare);//the hare fights the pirate at the back of the deque
			}
			if((hare->getHealth() != 0)&&(pirate->getHealth() != 0))
				hare->pirateAttack(pirate);
			if(pirate->getHealth() == 0){
				deque->popBack();
				break;
			}
			if((deque->empty())||((hare->getHealth() == 0) && (tort->getHealth() == 0))||(hare->getHealth() == 0))
				break;
		}
		
	}

	//compute the statistics
	totalRuns++;

	if(!deque->empty()){
		if(hare->getSword())
			hareFail++;
		else if(tort->getSword())
		tortFail++;
	}
	else if(deque->empty()){
	
		if((tort->getHealth()==0) && (hare->getHealth() != 0) && (hare->getSword()))
			harePartSuccess++;
		else if((hare->getHealth()==0) && (tort->getHealth() != 0) && (hare->getSword()))
			harePartSuccess++;
		else if((hare->getHealth()==0) && (tort->getHealth() != 0) && (tort->getSword()))
			tortPartSuccess++;
		else if((tort->getHealth()==0) && (hare->getHealth() != 0)  && (tort->getSword()))
			tortPartSuccess++;
		else if((hare->getSword()) && (hare->getHealth() != 0) && (tort->getHealth() != 0))
			hareSuccess++;
		else if((tort->getSword()) && (hare->getHealth() != 0) && (tort->getHealth() != 0))
			tortSuccess++;	
	}


}

//this function calls the show results function in the view and outputs the final statistics
void Battle::results(Screen& s){
	s.showResults((tortSuccess/totalRuns*2*100), (tortPartSuccess/totalRuns*2*100), (tortFail/totalRuns*2*100), (hareSuccess/totalRuns*2*100), 
			(harePartSuccess/totalRuns*2*100), (hareFail/totalRuns*2*100), totalRuns/2);
}	





