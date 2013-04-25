#pragma once
#include <stdlib.h>
#include <stdio.h>
#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif



class Background
{
private:

	GLuint _texture;

public:
	void draw();
	Background(void);
	~Background(void);
};

