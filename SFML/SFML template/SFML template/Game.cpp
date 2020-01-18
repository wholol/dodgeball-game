#include "Game.h"


Game::Game(int screenwidth, int screenheight, std::string title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),	//construct window
	goal(screenwidth, screenheight, 10, 10, rd),
	e(screenwidth, screenheight, screenwidth - 21, screenheight - 21, 20, 20)	//construct eater
	
{
	font.loadFromFile("Bebas-Regular.ttf");				//load font
	for (int i = 0; i < number_of_balls; ++i) {		//construct ball vector
		ball.push_back(balls(screenwidth, screenheight, number_of_balls, rd));
	}
	
	createwindow.setFramerateLimit(framerate);			//set framerate

}


void Game::render() {		//rendering

	if (MainMenu) {
		main_menu();
	}
	

	if (!MainMenu && !GameOver) {			//if no longer in main menu
		for (auto &i : ball) {		//render the balls
			if (!i.Collided(e)) {		//if no collision with the ball has occurd yet
				createwindow.draw(i.drawballs());		//draw the balls
			}
			else {
				GameOver = true;
			}
		}
		createwindow.draw(e.drawEater());
		createwindow.draw(goal.drawGoal());

		if (goal.ReachedGoal(e)) {		//if goal is reached
			goal.respawn(e);				//create new spawn for the goal
		}
	}
	
	
	createwindow.display();
	

}

void Game::main_menu()
{
	text.setFont(font);				//set font of text
	text.setString("welcome to the game. Press Enter to start playing.");		//text string
	text.setCharacterSize(20);		//character size	
	
	createwindow.draw(text);		//draw text
}

void Game::update() {		//update game 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {			//trigger main menu bool to main game
		MainMenu = false;
	}

	for (auto& i : ball) {
		i.moveballs();
	}

	e.eatercontrols();

	createwindow.clear();

}


bool Game::quit()			//call quit game
{
	while (createwindow.pollEvent(event)) {		//NON BLOCKING FUNCTION, WILL NOT GET STUCK IN WHILE LOOP.
		if (event.type == sf::Event::Closed) {
			createwindow.close();
			quitgame = true;
		}
	}
	return quitgame;
}

Game::~Game()	{}