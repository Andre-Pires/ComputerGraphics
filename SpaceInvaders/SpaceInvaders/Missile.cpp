#include "stdafx.h"
#include "Missile.h"


Missile::Missile(void)
{
}

void Missile::draw(float x, float y)
{
	_x = x;
	_y = y;

	glPushMatrix();



	glPopMatrix();
}

Missile::~Missile(void)
{
}
