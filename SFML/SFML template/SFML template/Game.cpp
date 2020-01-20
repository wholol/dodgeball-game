#include "Game.h"


Game::Game(int screenwidth, int screenheight, const std::string &title, int framerate)

	:createwindow(sf::VideoMode(screenwidth, screenheight), title),	//construct window
	screenwidth(screenwidth),
	screenheight(screenheight),
	goal(screenwidth, screenheight, 10, 10, rd),
	e(screenwidth, screenheight, screenwidth - 21, screenheight - 21, 15, 15)	//construct eater
	
{
	font.loadFromFile("Bebas-Regular.ttf");			//load font
	for (int i = 0; i < number_of_balls; ++i) {		//construct ball vector
		ball.push_back(balls(screenwidth, screenheight, 10, rd));
	}
	createwindow.setFramerateLimit(framerate);			//set framerate

}


void Game::render() {		//rendering

	if (GameOver) {
		game_over();
	}

	if (MainMenu) {
		main_menu();
	}
	
	if (!MainMenu && !GameOver) {			//if no longer in main menu, and game is not over

		
		for (auto &i : ball) {		//render the balls

			if (!i.Collided(e)) {		//if no collision with the ball has occurd yet
				createwindow.draw(i.drawballs());		//draw the balls
			}

			else {
				GameOver = true;
			}
		}

		createwindow.draw(score.drawScore());	//draw the score 
		createwindow.draw(e.drawEater());		//draw eaters
		createwindow.draw(goal.drawGoal());		//draw the goals

		if (goal.ReachedGoal(e)) {			//if goal is reached
			score.updateScore(goal);		//update the score
			goal.respawn(e);				//create new spawn for the goal
			
		}
	}
	
	createwindow.display();
	
}

void Game::main_menu()
{
	text.setFont(font);				//set font of text
	text.setString("welcome to the game. Press Enter to start playing.\nInstructions : Obtain as many goals as possible without touching the red balls.");		//text string

	text.setCharacterSize(25);		//character size	
	
	createwindow.draw(text);		//draw text
}

void Game::game_over()
{
	text.setFont(font);
	text.setString("GAME OVER.YOU LOSE. YOUR SCORE IS : " + score.getScore());
	text.setCharacterSize(25);
	createwindow.draw(text);
}

void Game::update() {		//update game (game logic)

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