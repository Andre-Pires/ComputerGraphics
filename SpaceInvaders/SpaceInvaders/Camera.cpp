#include "stdafx.h"
#include "Camera.h"


Camera::Camera(void)
{
}


void Camera::setCamera(float w,	float h, unsigned char camera){

	float aspect_ratio = w/h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	switch (camera)
	{
	case 0: { 	
		
		if(aspect_ratio >= 1)
				glOrtho(-100.0f*aspect_ratio, 100.0f*aspect_ratio, -100.0f, 100.0f, -100.0f, 100.0f);
			else
				glOrtho(-100.0f, 100.0f, -100.0f/aspect_ratio, 100.0f/aspect_ratio, -100.0f, 100.0f);
		
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			break;
	}
	case 1: {

		gluPerspective(45, aspect_ratio, 0.1, 100);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, -95, 60, 0, 0, 0, 0, 0, 1); //De onde, para onde e vector normal

		break;
			}
	default:
		break;
	}

}

Camera::~Camera(void)
{
}
