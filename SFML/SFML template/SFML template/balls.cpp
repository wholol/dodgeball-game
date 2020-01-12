#include "balls.h"

balls::balls(int screenwidth,int screenheight,int circle_radius,std::random_device& rd)			//construct ball position and coordinates
	:drawcircle(circle_radius),			//construct circle radius
	xDist(0, screenwidth - 20),			//construct xdist
	yDist(0, screenheight - 20),		//consturct ydist
	yVel(-2, 2),						//velocity rng. ensure it is between -2 and 2
	xVel(-2,2),							//velocity rng. ensure it is between -2 and 2
	screenwidth(screenwidth),			//store parameter in class
	screenheight(screenheight),			//store paramter in class
	ball_radius(circle_radius),			//store parameter in class
	rng (rd ())							//construct rng
	
{
	
	xpos = xDist(rng);					//construct xpos			
	ypos = yDist(rng);					//contruct ypos
	xvel = xVel(rng);					//construct xvel
	yvel = yVel(rng);					//construct yvel

	while ( xvel == 0) {
		xvel = xVel(rng);
	}
	
	while (yvel == 0) {
		yvel = yVel(rng);
	}
	
	drawcircle.setFillColor(sf::Color(255, 0, 0));	//fill ball color
}

void balls::moveballs() {

	drawcircle.setPosition(xpos, ypos);
	
	xpos += xvel;				//move xpositino of ball
	ypos += yvel;				//move yposition of ball

	if (xpos + (ball_radius * 2) >= screenwidth) {		//if the ball reaches the screen edge
		xpos = screenwidth - (ball_radius * 2) - 1;
		xvel = -xvel;
	}

	if (xpos <= 0) {		//if the ball reaches edge of screen
		xpos = 0;
		xvel = -xvel;
	}

	if (ypos + (ball_radius * 2) >= screenheight) {
		ypos = screenheight - (ball_radius * 2) - 1;
		yvel = -yvel;
	}

	if (ypos <= 0) {
		ypos = 0;
		yvel = -yvel;
	}
}

sf::CircleShape balls::drawballs()		//pass the circle shape object to draw 
{
	return drawcircle;
}

bool balls::isEaten(eater& eat)			//chcks if it is eaten
{
	if (eat.getxpos() + eat.getrectwidth() > xpos  && eat.getxpos() < (xpos + ball_radius * 2) && eat.getypos() + eat.getrectheight() > ypos && eat.getypos() < ypos + (ball_radius * 2)) {
		Eaten = true;
		return Eaten;
	}
	return Eaten;
	
}

