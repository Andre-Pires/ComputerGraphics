#include "stdafx.h"
#include "PurpleInvader.h"


PurpleInvader::PurpleInvader(void)
{
}


PurpleInvader::~PurpleInvader(void)
{

}


void PurpleInvader::drawHead()
{
	glPushMatrix();
	glTranslated(-5.5,4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5.5,4,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4.5,3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.5,3,0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,2,0);
	glScaled(8, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,1,0);
	glScaled(10, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

}

void PurpleInvader::drawBody()
{
	glPushMatrix();
	glTranslatef(0,-1,0);
	glScaled(12, 3, 2);
	glutSolidCube(1);
	glPopMatrix();
}

void PurpleInvader::drawLegs()
{
	glPushMatrix();
	glTranslated(0,-3,0);
	glScaled(8,1,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4,-4,0);
	glScaled(2,1,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,-4,0);
	glScaled(2,1,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4,-4,0);
	glScaled(2,1,2);
	glutSolidCube(1);
	glPopMatrix();

}

void PurpleInvader::drawEyes()
{
	glPushMatrix();
	glTranslated(-2,0,0.1);
	glScaled(2,3,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2,0,0.1);
	glScaled(2,3,2);
	glutSolidCube(1);
	glPopMatrix();
}

void PurpleInvader::draw(float x, float y)
{
	_x = x;
	_y = y;

	glPushMatrix();

	glTranslated(x, y, 0.0f);

	glPushMatrix();

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
		GLfloat material[] = {0.59,0.0,0.82};
		GLfloat emission[] = {0,0,0,1};
		GLfloat specular[] = {0,0,0,0};
		GLfloat shininess[] = {0};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	}else glColor3f(0.59f, 0.0f, 0.82f);

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