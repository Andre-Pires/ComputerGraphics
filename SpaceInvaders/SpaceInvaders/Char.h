#pragma once

class Char
{

public:
	float _x, _y, _step;
	float _radius;
	int _lives;
	bool _alive; // se for morto passa a false para não ser desenhado;
	bool _inv;

	Char(void);
	float getLives();
	void hitChar();
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
	float getRadius();
	bool getAlive();
	void setAlive(bool a);
	void setInv(bool b);
	virtual void draw(float x, float y) = 0;
};