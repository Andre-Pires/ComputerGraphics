#pragma once

class Camera {

private:
	int ortho;
	int current;
	float old_aspect;

public:

	Camera(void);
	~Camera(void);
	int getView();
	void setCamera(float w,	float h, int cam, float xShip);

};
