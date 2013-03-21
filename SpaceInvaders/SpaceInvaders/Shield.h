#pragma once

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

#include "Char.h"

class Shield: public Char
{
public:
	Shield(void);
	~Shield(void);
	void draw(float x, float y);
};
