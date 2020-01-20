#pragma once

#include <SFML/Graphics.hpp>
#include "Goal.h"
#include <sstream>

class Score {
public:

	
	void updateScore(Goal &goal);			//update the score	
	sf::Text& drawScore();			//draw the score
	std::string getScore();			//get the score in terms of a string variable

private:
	sf::Font font;					//font object for score
	sf::Text text;					//text object for score
	int score = 0;					//initialize scor to zero
	std::stringstream ss;		
	static constexpr int charactersize = 25;




};