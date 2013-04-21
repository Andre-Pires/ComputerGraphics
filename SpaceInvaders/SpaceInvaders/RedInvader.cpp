#include "stdafx.h"
#include "RedInvader.h"


RedInvader::RedInvader(void)
{
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
	glVertex3f (-3.5,1,1.0);
	
	glVertex3f (-0.5,-1,1.0);
	glVertex3f (-3.5,-1,1.0);
	/*glVertex3f (-3.5,1,-1);
	glVertex3f (-3.5,-1,-1);
	glVertex3f (-0.5,-1,-1);*/
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f (3.5,1,1.0);
	glVertex3f (3.5,-1,1.0);
	glVertex3f (0.5,-1,1.0);
	/*glVertex3f (3.5,-1,-1);
	glVertex3f (3.5,1,-1);
	glVertex3f (0.5,-1,-1);*/
	glEnd();
	glPopMatrix();
}

void RedInvader::draw(float x, float y){
	
	_x = x;
	_y = y;


	glPushMatrix();

	glTranslated(x, y, 0.0f);

	glPushMatrix();

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
	GLfloat material[] = {1,0.14,0,1};
	GLfloat emission[] = {0,0,0,1};
	GLfloat specular[] = {0,0,0,1};
	GLfloat shininess[] = {0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, material);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	
	}else glColor3f(1.0f, 0.14f, 0.0f);

	drawHead();
	drawBody();
	drawLegs();

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
	GLfloat eye2_ambient[] = {0.03,0.03,0.03,1};
	GLfloat eye2_specular[] = {0,0,0,1};
	GLfloat eye2_emission[] = {0,0,0,1};
	GLfloat eye2_shininess[] = {0};
	glMaterialfv(GL_FRONT, GL_EMISSION, eye2_emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, eye2_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, eye2_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, eye2_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, eye2_shininess);
	}else glColor3f(0.0f, 0.0f, 0.0f); //preto 

	drawEyes();
	glPopMatrix();

	glPopMatrix();
}