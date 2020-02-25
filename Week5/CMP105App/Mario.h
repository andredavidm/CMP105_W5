#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Mario :	public GameObject
{
		
public:
	Mario();
	~Mario();

	void update (float dt) override;

	sf::Texture marioTexture;

	GameObject mario;
	
	sf::Vector2f lmovement;
	sf::Vector2f rmovement;

	bool moving_left;
	sf::Vector2f pos;

protected:
	
	Animation walk;
	Animation duck;
	Animation swim;
	Animation idle;
};

