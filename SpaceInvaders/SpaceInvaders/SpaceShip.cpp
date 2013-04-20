#include "stdafx.h"
#include "SpaceShip.h"


SpaceShip::SpaceShip(void)
{
	_coord = 0;
	_rot = 0;
}

void SpaceShip::draw(float x, float y){

	glPushMatrix();
	
	glTranslated(x, y, 0.0f);

	/* Codigo para a rotacao --------- nave mal desenhada ha intercecao errada das rectas
	 * 
	if (_coord != x)
	{
		if(_coord > x && _rot == 0){
			_rot = 20; 
			glRotated(_rot, 0, 1, 0);
		}else if (_coord < x && _rot == 0)
		{
			_rot = -20; 
			glRotated(_rot, 0, 1, 0);
		}
		else if(_coord == x &&_rot == 20)
		{
			_rot = -20;
			glRotated(_rot, 0, 1, 0);
		}else{
			_rot = 20;
			glRotated(_rot, 0, 1, 0);
		}
	}
	*/
	
	//glRotated(60, 0, 1, 0);

	glScalef(0.8f, 0.8f, 1.0f);

	glPushMatrix();

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
		GLfloat material[] = {0.85,0.85,0.85};
		GLfloat emission[] = {0,0,0,1};
		GLfloat specular[] = {1,1,1,1};
		GLfloat shininess[] = {50};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	}else glColor3f(0.85f, 0.85f, 0.85f);

	glPushMatrix();
	glTranslated(0, 9, 0);
	glScaled(2, 2, 2);
	glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
	glTranslated(0, -3.5, 0);
	glScaled(8, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -5, 0);
	glScaled(22, 2, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -6.5, 0);
	glScaled(4, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -7.5, 0);
	glScaled(2, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11.5, -5, 0);
	glScaled(1, 7, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(11.5, -5, 0);
	glScaled(1, 7, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4, -8, 0);
	glScaled(2, 4, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4, -8, 0);
	glScaled(2, 4, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);

	glVertex3f (-1,8,1); // esq - cima - frente
	glVertex3f (1,8,1); // dir - cima - frente
	glVertex3f (-1,8,-1); // esq - cima - tras
	glVertex3f (1,8,-1); // dir - cima - tras
	glVertex3f (3,-3,-1); // dir - baixo - tras
	glVertex3f (-3,-3,-1); // esq - baixo - tras
	glVertex3f (3,-3,1); // dir - baixo - frente
	glVertex3f (-3,-3,1); // esq - baixo - tras
	glEnd();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	_coord = x;
}

SpaceShip::~SpaceShip(void)
{
}
