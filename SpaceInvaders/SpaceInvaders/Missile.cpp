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
		GLfloat material[] = {1,1,1};
		GLfloat emission[] = {0,0,0,1};
		GLfloat specular[] = {0,0,0,1};
		GLfloat shininess[] = {0};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	}else glColor3f(1.0f, 1.0f, 1.0f);

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
