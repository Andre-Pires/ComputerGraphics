#pragma once
#include "Char.h"

#define PARTICLES 100

class Particles
{

private:

	int particulas;
	float currentTime;
	bool _alive;
	float	x0;
	float	y0;

	typedef struct
	{
		float	x;
		float	z;
		float	direction; // direc��o da particula
		float	angleVert; // angulo de lan�amento da particula
		float	vel;	   // velocidade da particula
	}Particle;
	
	Particle ** parts;

public:

	bool getAlive();
	void setAlive(bool state);
	void drawParticle(int particle, GLfloat *mat);
	void moveParticles(GLfloat *mat);
	void randParticles(float x, float y);
	Particles(void);
	~Particles(void);
};

