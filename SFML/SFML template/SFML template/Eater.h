#pragma once
#include <SFML\Graphics.hpp>

class eater {				//eater class

public:
	eater(int screenwdith, int screenheight, int xpos, int ypos, int rectWidth, int rectHeight);		//construct eater

	void eatercontrols();
	sf::RectangleShape drawEater();
	int getxpos();					//getter for xpos
	int getypos();					//getter for ypos
	int getrectwidth();				//getter for rectwidth
	int getrectheight();			//getter for rectheight

private:
	sf::RectangleShape rectangle;				//rectagele object
	int xpos;									//rectangle xpos
	int ypos;									//rectangle ypos

	static constexpr int xvel = 2;				//x velociy of rectangle
	static constexpr int yvel = 2;				//y veloicty of rectangle

	int screenwidth;							//screenwidth
	int screenheight;							//screenwidth
	
	int rectwidth;								//width of rectangle
	int rectheight;								//height of rectangle

};