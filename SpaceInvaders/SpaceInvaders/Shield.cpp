#include "stdafx.h"
#include "Shield.h"


Shield::Shield(void)
{
	_alive = true;
	_radius = 8;
	_lives = 5;
	R = 1;
	G = 1;
	B = 1;
}

Shield::~Shield(void)
{
}

void Shield::resetShields(){

	_alive = true;
	_lives = 5;
	R = 1;
	G = 1;
	B = 1;
}

void Shield::draw(float x, float y, int debug){

	_x = x;
	_y = y;

glPushMatrix();

glTranslated(x, y, 0.0f);

glPushMatrix();

	GLfloat material[] = {R,G,B,1};
	GLfloat emission[] = {0,0,0,1};
	GLfloat specular[] = {0,0,0,1};
	GLfloat shininess[] = {0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, material);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glColor3f(R, G, B);

	glPushMatrix(); // Debug Sphere
	if (debug)
		glutWireSphere(_radius, 13, 5);
	glPopMatrix();

glPushMatrix();
glTranslated(0, 4, 0.0f);
glScaled(10, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(0, 2, 0.0f);
glScaled(14, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
//glTranslated(0, -1, 0.0f);
glScaled(18, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-6.5, -2, 0.0f);
glScaled(9, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(6.5, -2, 0.0f);
glScaled(9, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-7.5, -4, 0.0f);
glScaled(7, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(7.5, -4, 0.0f);
glScaled(7, 2, 2);
glutWireCube(1);
glPopMatrix();

glPopMatrix();

glPopMatrix();

}

void Shield::switchShield(){

	R -= 0.2;
	G -= 0.2;
	B -= 0.2;
}