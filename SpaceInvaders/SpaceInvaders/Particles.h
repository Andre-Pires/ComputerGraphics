#pragma once
#include "Char.h"

#define PARTICLES 100

class Particles
{

private:

	int particulas[PARTICLES];
	float currentTime;
	bool _alive;
	float	x0;
	float	y0;

	typedef struct
	{
		float	x;
		float	z;
		float	direction; // direcção da particula
		float	angleVert; // angulo de lançamento da particula
		float	vel;	   // velocidade da particula
	}Particle;
	
	Particle ** parts;

public:

	bool getAlive();
	void setAlive(bool state);
	void drawParticles(GLfloat *mat);
	void moveParticles();
	void randParticles(float x, float y);
	Particles(void);
	~Particles(void);
};

