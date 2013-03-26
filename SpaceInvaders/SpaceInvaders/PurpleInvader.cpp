#include "stdafx.h"
#include "PurpleInvader.h"


PurpleInvader::PurpleInvader(void)
{
}


PurpleInvader::~PurpleInvader(void)
{

}


void PurpleInvader::drawHead()
{
	glPushMatrix();
	glTranslated(-5.5,4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5.5,4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4.5,3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.5,3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,2,0);
	glScaled(8, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,1,0);
	glScaled(10, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

}

void PurpleInvader::drawBody()
{
	glPushMatrix();
	glTranslatef(0,-1,0);
	glScaled(12, 3, 2);
	glutSolidCube(1);
	glPopMatrix();
}

void PurpleInvader::drawLegs()
{
	glPushMatrix();
	glTranslated(0,-3,0);
	glScaled(8,1,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4,-4,0);
	glScaled(2,1,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,-4,0);
	glScaled(2,1,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4,-4,0);
	glScaled(2,1,2);
	glutSolidCube(1);
	glPopMatrix();

}

void PurpleInvader::drawEyes()
{
	glPushMatrix();
	glTranslated(-2,0,0);
	glScaled(2,3,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2,0,0);
	glScaled(2,3,2);
	glutSolidCube(1);
	glPopMatrix();
}

void PurpleInvader::draw(float x, float y)
{
	_x = x;
	_y = y;

	glPushMatrix();

	glTranslated(x, y, 0.0f);

	glPushMatrix();

	glColor3f(0.59f, 0.0f, 0.82f);

	drawHead();
	drawBody();
	drawLegs();
	glColor3f(0.0f, 0.0f, 0.0f);
	drawEyes();

	glPopMatrix();
	glPopMatrix();
}