#pragma once
#include "Char.h"
#include "Particles.h"

class Invader: public Char
{
		
public:
	Particles * part;
	Invader(void);
};
