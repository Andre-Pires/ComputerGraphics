#pragma once
#include "Char.h"

class Invader: public Char
{
	private:

		Char * missile;


public:
	Invader(void);
	void drawInvMissile();
	void setInvMissile(bool val);
	void newInvMissile();
	void moveInvMissile();
};
