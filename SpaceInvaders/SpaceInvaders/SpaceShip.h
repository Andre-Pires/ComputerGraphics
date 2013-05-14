#pragma once
#include "Char.h"
#include "Particles.h"

class SpaceShip : public Char 
{
	float _coord;
	float _rot;

public:
	SpaceShip(void);
	~SpaceShip(void);
	Particles * part;
	void resetShip(void);
	void moveShip(unsigned char key);
	void draw(float x, float y, int debug);
};

