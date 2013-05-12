#include "stdafx.h"
#include "Particles.h"

Particles::Particles(void)
{
	parts = (Particle **) malloc(sizeof(Particle *)*PARTICLES);

	for (int i = 0; i < PARTICLES; i++)
	{
		parts[i] = (Particle *) malloc(sizeof(Particle));
	}
	_alive = false;
	currentTime = 0;
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

void Particles::drawParticles(GLfloat * mat){

	for (int particle = 0; particle < PARTICLES; particle++)
	{

	glPushMatrix();

	GLfloat *material = mat;
	GLfloat emission[] = {0,0,0,1};
	GLfloat specular[] = {0,0,0,1};
	GLfloat shininess[] = {0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, material);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glColor4fv(material);

	glTranslated(x0, y0, 0);
	glRotated(parts[particle]->angleVert, 0, 0, 1);
	glTranslated(parts[particle]->x, 0, parts[particle]->z);

	glutSolidOctahedron();

	glPopMatrix();

	}
}


void Particles::moveParticles(){
	
	currentTime += 0.050;

	for (int i = 0; i < PARTICLES; i++)
	{

		if(parts[i]->z > -5){
		parts[i]->x = (parts[i]->vel*cos(parts[i]->angleVert)*currentTime);
		parts[i]->z = (0 + parts[i]->vel*sin(parts[i]->angleVert)*currentTime-13*currentTime*currentTime); // z0 igual a 0
		} else particulas--;
	}

	if(particulas == 0) _alive = false;
}

void Particles::randParticles(float x, float y){

	x0 = x;
	y0 = y;
	_alive = true;
	particulas = PARTICLES;
	currentTime = 0;

	for (int i = 0; i < PARTICLES; i++)
	{
		parts[i]->x = 0;
		parts[i]->z = 0;
		parts[i]->vel = rand() % 15 + 10;
		parts[i]->angleVert = rand() % 360;
		parts[i]->direction = rand() % 360;
	}		
}