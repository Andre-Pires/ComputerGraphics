#pragma once
#include "Invader.h"

class PurpleInvader: public Invader
{
public:
	PurpleInvader(void);
	~PurpleInvader(void);
	void draw(float x, float y);
private:
	void drawLegs();
	void drawBody();
	void drawHead();
	void drawEyes();
};

