// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"



int main()
{
	
	Game creategame(800,800,"game",120);

	while (!creategame.quit()) {
		creategame.update();
		creategame.render();
		
	}
}
