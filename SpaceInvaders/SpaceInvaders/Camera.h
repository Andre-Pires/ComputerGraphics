#pragma once

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif


class Camera {
public:

	Camera(void);
	~Camera(void);
	void setCamera(float w,	float h, int cam, float xShip);

};
