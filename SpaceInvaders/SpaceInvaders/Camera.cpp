#include "stdafx.h"
#include "Camera.h"


Camera::Camera(void)
{
}


void Camera::setCamera(float w,	float h, int cam, float xShip){

	float aspect_ratio = w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	switch (cam)
	{
	case 1:
		printf("top down view\n");
		if(aspect_ratio >= 1)
				glOrtho(-100.0f*aspect_ratio, 100.0f*aspect_ratio, -100.0f, 100.0f, -100.0f, 100.0f);
			else
				glOrtho(-100.0f, 100.0f, -100.0f/aspect_ratio, 100.0f/aspect_ratio, -100.0f, 100.0f);
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			break;
	case 2:
		printf("third person view\n");
		gluPerspective(60, aspect_ratio, 0, 200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xShip, -100, 160, xShip, -20, 0, 0, 0, 1); //Eye, LookAt e UP vector
		break;
	case 3:
		printf("first person view\n");
		gluPerspective(60, aspect_ratio, 0, 200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xShip,-100, 45, xShip, -30, 5, 0, 0, 1); //Eye, LookAt e UP vector
		break;
	}

}

Camera::~Camera(void)
{
}
