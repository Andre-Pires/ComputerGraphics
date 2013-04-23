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

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
		GLfloat material[] = {.30,.30,.30,1};
		GLfloat specular[] = {0,0,0,0};
		GLfloat emission[] = {0,0,0,0};
		GLfloat shininess[] = {20};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	}else glColor3f(0.30f, 0.30f, 0.30f);

	glPushMatrix();
	glTranslated(x, y, 0);
	glScalef(1.5, 5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

Missile::~Missile(void)
{
}
