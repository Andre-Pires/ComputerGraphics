#include "stdafx.h"
#include "BlueInvader.h"


BlueInvader::BlueInvader()
{
}

void BlueInvader::draw_legs(){

glPushMatrix();

glScaled(1, 1, 2);
glutSolidCube(1);

glPushMatrix();
glTranslated(1,1,0);
glutSolidCube(1);
glPopMatrix();

glTranslated(2,0,0);
glutSolidCube(1);

glPopMatrix();

}

void BlueInvader::draw_body(){
	int i;

	for(i = -2; i <2; i++){
			glPushMatrix();
			glTranslated(0, i, 0);
			glScaled(10, 1, 2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();
	}
}

void BlueInvader::draw_head(){
	int i;
	int	size = 10;

	for(i = 0; i <5; i++){
			glPushMatrix();
			glTranslated(0, 1 + i, 0);
			glScaled(size, 1, 2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();	
			size -= 2;
		}

}

void BlueInvader::draw_eyes(){
	int i;

	for(i = 0; i <2; i++){
			glPushMatrix();
			glTranslated(-2, -1 + i, 0);
			glScaled(2,1,2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();
	}

	for(i = 0; i <2; i++){
			glPushMatrix();
			glTranslated(2, -1 + i, 0);
			glScaled(2,1,2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();
	}
}

void BlueInvader::draw(float x, float y){

	
	_x = x;
	_y = y;

glPushMatrix();

glTranslated(x, y, 0.0f);

glPushMatrix();

glColor3f(0.0f, 0.75f, 1.0f);

glPushMatrix();
glTranslated(-4.5, -5, 0);
draw_legs(); // perna esquerda
glPopMatrix();

glPushMatrix();
glTranslated(2.5, -5, 0);
draw_legs();	//perna direita
glPopMatrix();


glPushMatrix();
glScalef(6, 1, 2);
glTranslated(0,-3,0); //base do corpo
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
draw_body();	//corpo
glPopMatrix();

glPushMatrix();
draw_head(); //cabeca
glPopMatrix();

glColor3f(0.0f, 0.0f, 0.0f); //preto

glPushMatrix();
draw_eyes(); //olhos
glPopMatrix();

glPopMatrix();

glPopMatrix();
}