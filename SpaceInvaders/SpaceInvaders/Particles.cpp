#include "stdafx.h"
#include "Particles.h"

Particles::Particles(void)
{
	for (int i = 0; i < PARTICLES; i++)
	{
		part[i]->getX();
		part[i]->getY();
		part[i]->getY();
	}		
}


Particles::~Particles(void)
{
}

void Particles::draw(float x, float y){

	_x = x;
	_y = y;

	for (int i = 0; i < PARTICLES; i++)
	{
		part[i]->drawParticle(part[i]->getX(), part[i]->getY());
	
	}

}

void Particles::drawParticle(float x, float y){

	x = x;
	_y = y;

	glPushMatrix();

	glTranslated(x, y, 0.0f);

	GLfloat material[] = {1,1,1,1};
	GLfloat emission[] = {0,0,0,1};
	GLfloat specular[] = {0,0,0,1};
	GLfloat shininess[] = {0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, material);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glColor3i(1, 1, 1);

	glutSolidCube(1);

	glPopMatrix();
}
