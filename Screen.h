/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 2
 *  Screen.h
 *
 *  This is the Screen class (.h) file it contains all the 
 *  function prototypes for Screen.cpp
 *  
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
using namespace std;


class Screen{

public:
	Screen(int=0, int=0);//Default constructor

	void startScreen();
	void showResults(float tSuccess, float tPartSuccess, float tFail, float hSuccess, float hPartSuccess, float hFail, float runs);
	
	
private:
	int xSize, ySize;
};

#endif
