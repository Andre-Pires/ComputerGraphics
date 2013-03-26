#include "stdafx.h"
#include "Shield.h"


Shield::Shield(void)
{
}

Shield::~Shield(void)
{
}

void Shield::draw(float x, float y){

glPushMatrix();

glTranslated(x, y, 0.0f);

glPushMatrix();

glColor3f(1.0f, 1.0f, 1.0f);

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