#include "stdafx.h"
#include "RedInvader.h"


RedInvader::RedInvader(void)
{
	_radius = 5.5;
	_lives = 1;
}


void RedInvader::drawHead(){
	int l, y;

	glPushMatrix();
	glTranslated(-2.5,4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.5,3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.5,3,0);
	glScaled(1, 1, 2);
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
	glScaled(2,2,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5, -2.5, 0);
	glScaled(2,2,2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0, -2, 0);
	glScaled(6, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-2.5,-3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,-3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.5,-4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.5,-4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
}

void drawEyes(){
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f (-3.5,1,1.1);	
	glVertex3f (-0.5,-1,1.1);
	glVertex3f (-3.5,-1,1.1);
	glVertex3f (-3.5,1,-1);
	glVertex3f (-3.5,-1,-1);
	glVertex3f (-0.5,-1,-1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f (3.5,1,1.1);
	glVertex3f (3.5,-1,1.1);
	glVertex3f (0.5,-1,1.1);
	glVertex3f (3.5,-1,-1);
	glVertex3f (3.5,1,-1);
	glVertex3f (0.5,-1,-1);
	glEnd();
	glPopMatrix();
}

void RedInvader::draw(float x, float y, int debug){
	
	_x = x;
	_y = y;


	glPushMatrix();

	glTranslated(x, y, 0.0f);

	glPushMatrix();

		GLfloat material[] = {1,0.14,0,1};
		GLfloat specular[] = {0,0,0,0};
		GLfloat emission[] = {0,0,0,0};
		GLfloat shininess[] = {0};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glColor3f(1.0f, 0.14f, 0.0f);

	glPushMatrix();
	if (debug)
		glutWireSphere(_radius, 13, 5);
	glPopMatrix();

	drawHead();
	drawBody();
	drawLegs();

		GLfloat eye_ambient[] = {0,0,0,1};
		GLfloat eye_diffuse[] = {0,0,0,1};
		GLfloat eye_specular[] = {0,0,0,0};
		GLfloat eye_emission[] = {0,0,0,0};
		GLfloat eye_shininess[] = {0};
		glMaterialfv(GL_FRONT, GL_AMBIENT, eye_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, eye_ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, eye_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, eye_emission);
		glMaterialfv(GL_FRONT, GL_SHININESS, eye_shininess);
		glColor3f(0.0f, 0.0f, 0.0f); //preto 

	drawEyes();
	glPopMatrix();

	glPopMatrix();
}