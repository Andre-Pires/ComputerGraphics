#pragma once

class Char
{

public:
	float _x, _y, _step;
	bool _alive; // se for morto passa a false para não ser desenhado;

	Char(void);
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
	bool getAlive();
	void setAlive(bool a);
	
	virtual void draw(float x, float y) = 0;
};