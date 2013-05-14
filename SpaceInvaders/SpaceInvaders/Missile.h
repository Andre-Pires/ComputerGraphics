#pragma once
#include "Char.h"

class Missile : public Char
{
	float x, y;

public:
	Missile(void);
	~Missile(void);
	void draw(float x, float y, int debug);
};

