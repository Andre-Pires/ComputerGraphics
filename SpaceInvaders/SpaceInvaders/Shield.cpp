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
glScaled(26, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(0, 2, 0.0f);
glScaled(20, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(0, 4, 0.0f);
glScaled(14, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(10, -2, 0.0f);
glScaled(12, 2, 2);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-10, -2, 0.0f);
glScaled(12, 2, 2);
glutWireCube(1);
glPopMatrix();

glPopMatrix();

glPopMatrix();
}