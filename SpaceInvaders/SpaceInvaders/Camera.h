#pragma once

class Camera {

private:
	int current;
	float old_aspect;

public:

	Camera(void);
	~Camera(void);

	void setCamera(float w,	float h, int cam, float xShip);

};
