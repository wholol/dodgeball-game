#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "balls.h"
#include "Eater.h"
#include "Goal.h"
#include "Score.h"

class Game {			//game class. should have render, update/events, quit and initialize.

public:
	Game(int screenwidth, int screenheight,const std::string &title,int framerate);	//game constructor
	Game &operator=(Game &other) = delete;				//prevent assigning game object
	Game(const Game& other) = delete;					//no deep copying a game object
	Game(Game &&other) = delete;						//no moving game object
	~Game();
	
	void main_menu();				//main menu function
	void game_over();				//game over function
	void update();					//update logic
	void render();					//render
	bool quit();					//quit the window
 
	
private:
	
	sf::RenderWindow createwindow;	//window object
	sf::Event event;				//create an event handler
	sf::Font font;					//font object for man menu and gameover.
	sf::Text text;					//text object for main menu and gamover	
	std::random_device rd;			//generate rng for balls

	int screenwidth;				//screenwidth
	int screenheight;				//screenheight

	bool quitgame = false;			//quit game
	bool MainMenu = true;
	
	/*game objects*/
	eater e;					//an eater object for the player
	std::vector <balls> ball;	//construct ball objects
	Goal goal;				//the goal for the game
	Score score;			//score for the game
	bool GameOver = false;
	
	static constexpr int number_of_balls = 15;	//number of ball objects;
};