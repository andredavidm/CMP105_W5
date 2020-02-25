#include "Mario.h"


Mario::Mario()
{

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(15*6, 21*6));
	mario.setPosition(200, 500);
	mario.setTexture(&marioTexture);
	
	//Idle mario
	idle.addFrame(sf::IntRect(0, 0, 15, 21));

	
	//walking mario
//	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 11.f);  
	
	
	//ducking mario
	duck.addFrame(sf::IntRect(0, 42, 16, 20));
	
	

	//swimming mario
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 9.f);


	//move speeds
	rmovement = { 200,0 };
	lmovement = { -200,0 };
}
Mario::~Mario()
{

}

void Mario::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::S))
	{
	if (moving_left)
	{
		duck.setFlipped(true);
	}
	else
	{
		duck.setFlipped(false);
	}

	duck.animate(dt);
	mario.setTextureRect(duck.getCurrentFrame());
	}
	
	 else if (input->isKeyDown(sf::Keyboard::D))
	{
		mario.move(rmovement * dt);

		walk.animate(dt);
		moving_left = false;
		mario.setTextureRect(walk.getCurrentFrame());
	}

	else if (input->isKeyDown(sf::Keyboard::A))
	{
		mario.move(lmovement * dt);

		walk.animate(dt);
		moving_left = true;
		mario.setTextureRect(walk.getCurrentFrame());
	}
	//ducking


	else
	{
		if (moving_left)
		{
			idle.setFlipped(true);
		}
		else
		{
			idle.setFlipped(false);
		}
		idle.animate(dt);
		mario.setTextureRect(idle.getCurrentFrame());
	}
	
		
	
	//moving left or right?
	if (moving_left)
	{
		walk.setFlipped(true);
	}
	else
	{
		walk.setFlipped(false);
	}
	
	
	pos = mario.getPosition();

	if (pos.x >= 600)
	{
		if (moving_left)
		{
			swim.setFlipped(true);
		}
		else
		{
			swim.setFlipped(false);
		}
		swim.animate(dt);
		mario.setTextureRect(swim.getCurrentFrame());
	}
	


	

}