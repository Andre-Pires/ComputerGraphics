#pragma once
#include "Char.h"

class SpaceShip : public Char 
{
	float _coord;
	float _rot;

public:
	SpaceShip(void);
	~SpaceShip(void);
	void draw(float x, float y);
};

