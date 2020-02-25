#include "Zombie.h"

Zombie::Zombie()
{
	
	zombieTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombieTexture);	
	
	
	
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
	

	rmovement = { 100,0 };
	lmovement = { -100,0 };
}
Zombie::~Zombie()
{

}

void Zombie::update(float dt)
{

	if (input->isKeyDown(sf::Keyboard::D))
	{
		zombie.move(rmovement * dt);
		
		walk.animate(dt);
		moving_left = false;
	}

	else if (input->isKeyDown(sf::Keyboard::A))
	{
		zombie.move(lmovement * dt);
		
		walk.animate(dt);
		moving_left = true;
	}

	if (moving_left)
	{
		walk.setFlipped(true);
	}
	else
	{
		walk.setFlipped(false);
	}
	
	zombie.setTextureRect(walk.getCurrentFrame());
	

}