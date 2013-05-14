#pragma once
#include "Char.h"

class Shield: public Char
{
private:

	float R;
	float G;
	float B;

public:
	Shield(void);
	~Shield(void);
	void resetShields();
	void switchShield();
	void draw(float x, float y, int debug);
};
