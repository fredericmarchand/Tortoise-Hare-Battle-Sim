/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Screen.cpp
 *
 *  This is the Screen class (.cpp) file it contains all the 
 *  functions having something to do with the view of the
 *  program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Screen.h"
#include <stdlib.h>

//this is the constructor for the screen
Screen::Screen(int a, int b){
	xSize = a;
	ySize = b;
}

//this is the function which initializes the programs screen
void Screen::startScreen(){
	system("clear");
	cout<<"The simulation is about to start.."<<endl;
	sleep(1);
	system("clear");
	cout<<"The simulation is about to start..."<<endl;
	sleep(1);
	system("clear");
	cout<<"The simulation is about to start...."<<endl;
	cout<<endl;
}

//this is the function that is used at the end to tabulate the results of the simulation
void Screen::showResults(float tSuccess, float tPartSuccess, float tFail, float hSuccess, float hPartSuccess, float hFail, float runs){
	
	cout<<"+---------------------------------------------------------------------------------------------+"<<endl;
	cout<<"|      Swordsman      |     Success perc.    |    Part. Success perc.     |     Fail perc.    |"<<endl;
	cout<<"+---------------------------------------------------------------------------------------------+"<<endl;
	cout<<"|      Tortoise       |         "<<tSuccess<<"           |            "<<tPartSuccess<<"              |         "<<tFail<<"         |"<<endl;
	cout<<"+---------------------------------------------------------------------------------------------+"<<endl;
	cout<<"|        Hare         |         "<<hSuccess<<"           |            "<<hPartSuccess<<"              |        "<<hFail<<"         |"<<endl;
	cout<<"+---------------------------------------------------------------------------------------------+"<<endl<<endl;
	cout<<"Total runs: "<<runs<<endl;
		
}
	




