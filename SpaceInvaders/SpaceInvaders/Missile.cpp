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

	glColor3f(0.85f, 0.85f, 0.85f);

	glPushMatrix();
	glTranslated(x, y, 0);
	glScaled(1, 4, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

Missile::~Missile(void)
{
}
