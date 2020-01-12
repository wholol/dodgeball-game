#include "Eater.h"

eater::eater(int screenwidth, int screenheight, int xpos, int ypos,int rectHeight,int rectWidth)
	:xpos(xpos),			//construct xpos
	ypos(ypos),	
	screenwidth(screenwidth),	//contruct ypos
	screenheight(screenheight),				//construct screenheight
	rectheight(rectHeight),				//constuct rectangle height
	rectwidth(rectWidth),				//construct rectangle width
	rectangle(sf::Vector2f(rectWidth,rectHeight))			//construct rectangle width and height

{
	
	rectangle.setFillColor(sf::Color(255, 43, 100));	//fill ball color
}

void eater::eatercontrols()
{
	rectangle.setPosition(xpos, ypos);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {		//move left
		if (xpos <= 0) {
			xpos = 0;
		}

		else {
			xpos = xpos - xvel;
		}
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {		//mvoe right
		if (xpos + rectwidth >= screenwidth) {
			xpos = screenwidth - rectwidth;
		}

		else {
			xpos = xpos + xvel;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {			//move up
		if (ypos <= 0) {
			ypos = 0;
		}

		else {
			ypos = ypos - yvel;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {	//move down
		if (ypos + rectheight >= screenheight) {			
			ypos = screenheight - rectheight;
		}

		else {
			ypos = ypos + yvel;
		}
	}

}

sf::RectangleShape eater::drawEater()
{
	return rectangle;
}

int eater::getypos()
{
	return ypos;
}

int eater::getrectwidth()
{
	return rectwidth;
}

int eater::getrectheight()
{
	return rectheight;
}

int eater::getxpos()
{
	return xpos;
}
