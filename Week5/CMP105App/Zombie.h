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

protected:
	
	Animation walk;

};

