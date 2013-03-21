#pragma once

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif



class Char
{

public:
	float _x, _y, _step;
	bool _alive; // se for morto passa a false para não ser desenhado;

	Char(void);
	virtual void draw(float x, float y) = 0;
};