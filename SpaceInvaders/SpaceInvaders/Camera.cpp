#include "stdafx.h"
#include "Camera.h"


Camera::Camera(void)
{
	current = 0;
	ortho = 1;
}


int Camera::getView(){

	return ortho;
}

void Camera::setCamera(float w,	float h, int cam, float xShip){

	float aspect_ratio = w/h;
	
	switch (cam)
	{
	case 1:
		// ---- top down view --------
		if (current != 1 || old_aspect != aspect_ratio)
		{
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

		if(aspect_ratio >= 1)
				glOrtho(-100.0f*aspect_ratio, 100.0f*aspect_ratio, -100.0f, 100.0f, -100.0f, 100.0f);
			else
				glOrtho(-100.0f, 100.0f, -100.0f/aspect_ratio, 100.0f/aspect_ratio, -100.0f, 100.0f);
			
			ortho = 1;
			current = cam;
			old_aspect = aspect_ratio;
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
			break;
	case 2:
		// ---- third person view ---------
		if (current == 1 || old_aspect != aspect_ratio)
		{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, aspect_ratio, 0.1, 400);
		glMatrixMode(GL_MODELVIEW);
		old_aspect = aspect_ratio;
		current = cam;
		}
		ortho = 0;
		glLoadIdentity();
		gluLookAt(xShip, -120, 160, xShip, -20, 0, 0, 0, 1); //Eye, LookAt e UP vector
		break;
	case 3:
		// ---- first person view --------
		if (current == 1 || old_aspect != aspect_ratio)
		{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, aspect_ratio, 0.1, 400);
		glMatrixMode(GL_MODELVIEW);
		current = cam;
		old_aspect = aspect_ratio;
		}
		ortho = 0;
		glLoadIdentity();
		gluLookAt(xShip,-75, 0, xShip, -30, 0, 0, 0, 1); //Eye, LookAt e UP vector
		break;
	}

}

Camera::~Camera(void)
{
}
