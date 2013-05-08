#include "stdafx.h"
#include "Particles.h"

Particles::Particles(void)
{
	parts = (Particle **) malloc(sizeof(Particle)*PARTICLES);

	for (int i = 0; i < PARTICLES; i++)
	{
		parts[i] = (Particle *) malloc(sizeof(Particle));
	}
	_alive = false;
	currentTime = 0;
	particulas = PARTICLES;
}


Particles::~Particles(void)
{
}

bool Particles::getAlive(){

	return _alive;
}

void Particles::setAlive(bool state){

	_alive = state;
}

void Particles::drawParticle(int particle){

	glPushMatrix();

	GLfloat material[] = {1,1,1,1};
	GLfloat emission[] = {0,0,0,1};
	GLfloat specular[] = {0,0,0,1};
	GLfloat shininess[] = {0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, material);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glTranslated(x0, y0, 0);
	glRotated(parts[particle]->angleVert, 0, 0, 1);
	glTranslated(parts[particle]->x, 0, parts[particle]->z);

	glutSolidCube(1);

	glPopMatrix();
}


void Particles::moveParticles(){

	currentTime += 0.050;

	for (int i = 0; i < PARTICLES; i++)
	{

		if(parts[i]->z > -5){
		parts[i]->x = (parts[i]->vel*cos(parts[i]->angleVert)*currentTime);
		parts[i]->z = (0 + parts[i]->vel*sin(parts[i]->angleVert)*currentTime-9.8*currentTime*currentTime); // z0 igual a 0
		drawParticle(i);
		} else particulas--;
	}

	if(particulas == 0) _alive = false;
}

void Particles::randParticles(float x, float y){

	x0 = x;
	y0 = y;
	_alive = true;

	for (int i = 0; i < PARTICLES; i++)
	{
		parts[i]->x = 0;
		parts[i]->z = 0;
		parts[i]->vel = rand() % 15 + 5;
		parts[i]->angleVert = rand() % 360;
		parts[i]->direction = rand() % 360;
	}		
}