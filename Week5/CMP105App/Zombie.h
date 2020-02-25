#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"


class Zombie :	public GameObject 
{

public:
	Zombie();
	~Zombie();

	void update(float dt) override;
	
	sf::Texture zombieTexture;

	GameObject zombie;
	sf::Vector2f lmovement;
	sf::Vector2f rmovement;
protected:
	
	bool moving_left;
	Animation walk;

};

