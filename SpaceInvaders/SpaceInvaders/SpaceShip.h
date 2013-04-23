#pragma once
#include "Char.h"

class SpaceShip : public Char 
{
	float _coord;
	float _rot;

public:
	SpaceShip(void);
	~SpaceShip(void);
	void moveShip(unsigned char key);
	void draw(float x, float y);
};

