#include "stdafx.h"
#include "RedInvader.h"


RedInvader::RedInvader(void)
{
}


void RedInvader::drawHead(){
	int l, y;

	glPushMatrix();
	glTranslated(-2.5,4,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,4,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.5,3,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.5,3,0);
	glutSolidCube(1);
	glPopMatrix();

	l = 8;
	
	for(y=2; y>=1; y--){
		glPushMatrix();
		glTranslated(0,y,0);
		glScaled(l,1,2);
		glutSolidCube(1);
		glPopMatrix();
		l+=2;
	}
}

void RedInvader::drawBody(){
	int y;

	for(y=0; y>=-1; y--){
		glPushMatrix();
		glTranslated(0, y, 0);
		glScaled(12, 1, 2);
		glutSolidCube(1);
		glPopMatrix();
	}
}

void RedInvader::drawLegs(){
	glPushMatrix();
	glTranslated(-5, -2.5, 0);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5, -2.5, 0);
	glutSolidCube(2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0, -2, 0);
	glScaled(6, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-2.5,-3,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,-3,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.5,-4,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.5,-4,0);
	glutSolidCube(1);
	glPopMatrix();
}

void drawEyes(){

	//int y=1;
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f (-3.5,1,1);
	glVertex3f (-3.5,-1,1);
	glVertex3f (-0.5,-1,1);
	glVertex3f (-3.5,1,-1);
	glVertex3f (-3.5,-1,-1);
	glVertex3f (-0.5,-1,-1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f (3.5,1,1);
	glVertex3f (3.5,-1,1);
	glVertex3f (0.5,-1,1);
	glVertex3f (3.5,1,-1);
	glVertex3f (3.5,-1,-1);
	glVertex3f (0.5,-1,-1);
	glEnd();
	glPopMatrix();
}

void RedInvader::draw(float x, float y){
	
	_x = x;
	_y = y;


	glPushMatrix();

	glTranslated(x, y, 0.0f);

	glPushMatrix();

	glColor3f(1.0f, 0.14f, 0.0f);
	drawHead();
	drawBody();
	drawLegs();
	glColor3f(0.0f, 0.0f, 0.0f);
	drawEyes();
	glPopMatrix();

	glPopMatrix();
}