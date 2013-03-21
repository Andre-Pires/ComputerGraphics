#pragma once

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

#include "Invader.h"

class GreenInvader: public Invader
{
	
	void draw_legs();
	void draw_body();
	void draw_head();
	void draw_eyes();

public:
	GreenInvader(void);
	void draw(float x, float y);
};