#include "Goal.h"

Goal::Goal(int screenwidth, int screenheight,int RectHeight, int RectWidth, std::random_device& rd)
	:screenheight(screenheight),
	screenwidth(screenwidth),
	goalrectheight(RectHeight),
	goalrectwidth(RectWidth),
	GoalXPos(0, screenwidth - 20),
	GoalYPos(0, screenheight - 20),
	rng( rd() ),
	GoalRect(sf::Vector2f(RectWidth, RectHeight))			//construct rectangle width and height
{
	xpos = GoalXPos(rng);
	ypos = GoalYPos(rng);

}

sf::RectangleShape Goal::drawGoal() {			//draws the goal

	GoalRect.setPosition(xpos, ypos);
	return GoalRect;
}

bool Goal::ReachedGoal(eater & eat)
{
	if (eat.getxpos() <= xpos + goalrectwidth && eat.getxpos() + eat.getrectwidth() >= xpos && eat.getypos() + goalrectheight >= ypos && eat.getypos() <= ypos + goalrectheight) {
		reachedGoal = true;
	}
	return reachedGoal;
}

void Goal::respawn(eater& eat)
{
	reachedGoal = false;			//reset reachedcoal status
	xpos = GoalXPos(rng);			//redo the rng for goal x pos
	ypos = GoalYPos(rng);			//redo the rng for roal y pos


	/* prevents rng from putting it under the eater*/
	for (int i = eat.getxpos(); i <= eat.getxpos() + goalrectwidth; ++i) {
		for (int j = eat.getypos(); j <= eat.getypos() + goalrectheight; ++j) {
			if (xpos == i || ypos == j) {
				xpos = GoalXPos(rng);			//redo the rng for goal x pos
				ypos = GoalYPos(rng);			//redo the rng for roal y pos
			}
		}
	}
	/* prevents rng from putting it under the eater*/
	

}
