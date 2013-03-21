#pragma once
#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

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

