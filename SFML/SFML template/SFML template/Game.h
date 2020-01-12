#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "balls.h"
#include "Eater.h"

class Game {			//game class. should have render, update/events, quit and initialize.

public:
	Game(int screenwidth, int screenheight,std::string title,int framerate);	//game constructor
	Game &operator=(Game &other) = delete;				//prevent assigning game object
	Game(const Game& other) = delete;					//no deep copying a game object
	Game(Game &&other) = delete;						//no moving game object
	~Game();
	
	void main_menu();
	void update();					//update logic
	void render();					//render
	bool quit();					//quit the window
 
	
private:
	
	sf::RenderWindow createwindow;		//window object
	sf::Event event;				//create an event handler
	sf::Font font;					//font object for man menu and gameover.
	sf::Text text;				
	std::random_device rd;

	bool quitgame = false;			//quit game
	bool MainMenu = true;
	
	/*game objects*/
	eater e;
	std::vector <balls> ball;	//construct ball objects
	
	
	static constexpr int number_of_balls = 10;	//10 ball objects;
};