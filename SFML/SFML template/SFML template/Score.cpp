#include "Score.h"


void Score::updateScore(Goal &goal)		//update score
{
	if (goal.GetReachedGoal()) {
		score += 1;
	}
}

sf::Text& Score::drawScore()	//text object to write down the score
{
	ss << "Score is : " << score;
	font.loadFromFile("Bebas-Regular.ttf");				//load font
	text.setFont(font);
	text.setString(ss.str());
	text.setCharacterSize(charactersize);
	ss.str("");
	ss.clear();
	return text;
}

std::string Score::getScore()
{
	return std::to_string(score);
}
