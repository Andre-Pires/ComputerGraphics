#pragma once
#include "Invader.h"

class GreenInvader: public Invader
{
private:

	void draw_legs();
	void draw_body();
	void draw_head();
	void draw_eyes();

public:
	GreenInvader(void);
	void draw(float x, float y, int debug);
};