#include "stdafx.h"
#include "PurpleInvader.h"


PurpleInvader::PurpleInvader(void)
{
	_radius = 5.5;
	_lives = 1;
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

		GLfloat material[] = {0.59,0.0,0.82, 1};
		GLfloat specular[] = {0,0,0,0};
		GLfloat emission[] = {0,0,0,0};
		GLfloat shininess[] = {0};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		glColor3f(0.59f, 0.0f, 0.82f);

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