#pragma once

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

#include "Invader.h"
class RedInvader : public Invader{
	public:

		RedInvader(void);
		void draw(float x, float y);

	private:

		void drawHead();
		void drawBody();
		void drawLegs();
};

