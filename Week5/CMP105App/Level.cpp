#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	// initialise game objects
	
	myMario.setInput(input);
	myZombie.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	myZombie.update(dt);
	myMario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	//window->draw(myZombie.zombie);
	window->draw(myMario.mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear();
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}