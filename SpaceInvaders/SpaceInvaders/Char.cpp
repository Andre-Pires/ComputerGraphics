#include "stdafx.h"
#include "Char.h"


Char::Char(void)
{
}

float Char::getRadius(){

	return _radius;
}


float Char::getX(){

	return _x;
}

void Char::setX(float x){

	_x = x;
}

float Char::getY(){

	return _y;
}

void Char::setY(float y){

	_y = y;
}

bool Char::getAlive(){
	
	return _alive;
}

void Char::setAlive(bool a){

	_alive = a;
}

void Char::setInv(bool b){
	_inv = b;
}

int Char::getLives(){

	return _lives;
}
void Char::hitChar(){

	_lives--;
}