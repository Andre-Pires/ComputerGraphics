#pragma once
#include "Char.h"

#define PARTICLES 100

class Particles: public Char
{

private:

	float	direction; // direc��o da particula
	float	angleVert; // angulo de lan�amento da particula
	float	vel;	   // velocidade da particula
	Particles * part[PARTICLES];
	void drawParticle(float x, float y);


public:

	void draw(float x, float y);
	Particles(void);
	~Particles(void);
};

