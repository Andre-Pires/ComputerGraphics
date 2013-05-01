#include "stdafx.h"
#include "SpaceShip.h"


SpaceShip::SpaceShip(void)
{
	_coord = _x;
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
		
		glPushMatrix();

		// Strobes
		glPushMatrix();

		GLfloat ambient1[] = {0.35,0.35,0.35,0};
		GLfloat emission_on[] = {1,1,1,0};
		GLfloat emission_off[] = {0.3,0.3,0.3,0};

		if (glIsEnabled(GL_LIGHT2))
		{
		glMaterialfv(GL_FRONT, GL_EMISSION, emission_on);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient1);

		}else if (glIsEnabled(GL_LIGHT0))
		{
			glMaterialfv(GL_FRONT, GL_EMISSION, emission_off);
			glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient1);

		} else glColor3f(0.35f, 0.35f, 0.35f);

		glPushMatrix();
		glTranslated(-11.5, -1.0, 2);
		glScaled(1, 1, 2);
		glutSolidCube(1);
		glPopMatrix();
		// strobe esq

		glPushMatrix();
		glTranslated(11.5, -1.0, 2);
		glScaled(1, 1, 2);
		glutSolidCube(1);
		glPopMatrix();
		// strobe dir
		glPopMatrix();


		if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
		{
			GLfloat ambient[] = {.25,.25,.25,1};
			GLfloat diffuse[] = {.4,.4,.4,1};
			GLfloat specular[] = {0.774597,0.774597,0.774597,1.0};
			GLfloat emission[] = {0,0,0,0};
			GLfloat shininess[] = {128};
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
			glMaterialfv(GL_FRONT, GL_EMISSION, emission);
			glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

		}else glColor3f(0.30f, 0.30f, 0.30f);

		glTranslated(0, 0 , -1.5);

		//Asa esquerda - cima 
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-4,-3,4);
		glNormal3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-7.5,-3.5,3.5);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-11,-4,3);
		glNormal3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-11,-5,3);
		glNormal3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-11,-6,3);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-7.5,-6.5,3.5);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-4,-7,4);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(-4,-6,4);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(-4,-5,4);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(-4,-4,4);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-7.5,-5,3.5);
		glEnd();
		glPopMatrix();

		
		// Asa direita - cima
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(4,-3,4);
		glNormal3f(0.0f, 1.0f, 1.0f);
		glVertex3f(7.5,-3.5,3.5);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(11,-4,3);
		glNormal3f(1.0f, 1.0f, 0.0f);
		glVertex3f(11,-5,3);
		glNormal3f(1.0f, 1.0f, 0.0f);
		glVertex3f(11,-6,3);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(7.5,-6.5,3.5);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(4,-7,4);
		glNormal3f(1.0f, 0.0f, 1.0f);
		glVertex3f(4,-6,4);
		glNormal3f(1.0f, 0.0f, 1.0f);
		glVertex3f(4,-5,4);
		glNormal3f(1.0f, 0.0f, 1.0f);
		glVertex3f(4,-4,4);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(7.5,-5,3.5);
		glEnd();
		glPopMatrix();
		 
		//Asa esquerda - baixo

		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(-1.0f, 0.0f, -1.0f);
		glVertex3f(-4,-3,0);
		glVertex3f(-7.5,-3.5,0.5);
		glVertex3f(-11,-4,1);
		glVertex3f(-11,-5,1);
		glVertex3f(-11,-6,1);
		glVertex3f(-7.5,-6.5,0.5);
		glVertex3f(-4,-7,0);
		glVertex3f(-4,-6,0);
		glVertex3f(-4,-5,0);
		glVertex3f(-4,-4,0);
		glVertex3f(-7.5,-5,0.5);
		glEnd();
		glPopMatrix();

		// Asa direita - baixo
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(1.0f, 0.0f, -1.0f);
		glVertex3f(4,-3,0);
		glVertex3f(7.5,-3.5,0.5);
		glVertex3f(11,-4,1);
		glVertex3f(11,-5,1);
		glVertex3f(11,-6,1);
		glVertex3f(7.5,-6.5,0.5);
		glVertex3f(4,-7,0);
		glVertex3f(4,-6,0);
		glVertex3f(4,-5,0);
		glVertex3f(4,-4,0);
		glVertex3f(7.5,-5,0.5);
		glEnd();
		glPopMatrix();
		
		//Asa esquerda - lado - frente

		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-4,-3,4);
		glVertex3f(-4,-3,0);
		glVertex3f(-11,-4,1);
		glVertex3f(-11,-4,3);
		glEnd();
		glPopMatrix();

		// Asa direita - lado - frente
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(1.0f, 1.0f, 0.0f);
		glVertex3f(4,-3,4);
		glVertex3f(4,-3,0);
		glVertex3f(11,-4,1);
		glVertex3f(11,-4,3);
		glEnd();
		glPopMatrix();
	
		
		// Asa direita - lado - trás
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(1.0f, -1.0f, 0.0f);
		glVertex3f(4,-7,4);
		glVertex3f(4,-7,0);
		glVertex3f(11,-6,1);
		glVertex3f(11,-6,3);
		glEnd();
		glPopMatrix();

		//Asa esquerda - lado - trás

		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(-4,-7,4);
		glVertex3f(-4,-7,0);
		glVertex3f(-11,-6,1);
		glVertex3f(-11,-6,3);
		glEnd();
		glPopMatrix();


		glPushMatrix();
		glTranslated(-11.5, -5, 2);
		glScaled(1, 7, 2);
		glutSolidCube(1);
		glPopMatrix();
		// missil esq

		glPushMatrix();
		glTranslated(11.5, -5, 2);
		glScaled(1, 7, 2);
		glutSolidCube(1);
		glPopMatrix();
		// missil dir

		
		glPopMatrix();
		//-------- misseis e asas foram descidos com um translate-------------------------------
		
		
	glPushMatrix();
	glTranslated(-.5, 9.5, 0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(.5, 9.5, 0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-.5, 8.5, 0);
	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(.5, 8.5, 0);

	glScaled(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	// nariz 
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-4,-3,4);

	//glNormal3f(1.0f, 0.0f, 0.0f);
	//glVertex3f(-4,-5,4);
	glNormal3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-4,-7,4);
	//glNormal3f(0.0f, 0.0f, 0.0f);
	//glVertex3f(0,-7,4);
	glNormal3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(4,-7,4);
	//glNormal3f(-1.0f, 0.0f, 0.0f);
	//glVertex3f(4,-5,4);
	glNormal3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(4,-3,4);
	glNormal3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0,-3,4);
	//glNormal3f(1.0f,0.0f, 1.0f);
	//glVertex3f(0,-5,4);
	glEnd();
	glPopMatrix();
	//cubo central cima

	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-4,-3,-2);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-4,-7,-2);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(4,-7,-2);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(4,-3,-2);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0,-3,-2);
	glEnd();
	glPopMatrix();
	//cubo central baixo

	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4,-3,-2);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4,-7,-2);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4,-7,4);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4,-3,4);
	glEnd();
	glPopMatrix();
	//cubo central esq

	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(4,-3,-2);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(4,-7,-2);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(4,-7,4);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(4,-3,4);
	glEnd();
	glPopMatrix();
	//cubo central dir

	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4,-3,-2);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(4,-3,-2);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(4,-3,4);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4,-3,4);
	glEnd();
	glPopMatrix();
	//cubo central frente

	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-4,-7,-2);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(4,-7,-2);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(4,-7,4);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-4,-7,4);
	glEnd();
	glPopMatrix();
	//cubo central trás



/*	for (float cx = -3.5; cx <= 3.5; cx++)
	{
		for (float cy = -3.5; cy >= -6.5 ; cy--)
		{
			glPushMatrix();
			glTranslated(cx, cy, 1);
			glScaled(1, 1, 6);
			glutSolidCube(1);
			glPopMatrix();
		}
	}*/

	//corpo

		for (float cx = -1.5; cx <= 1.5 ;cx++)
		{
			glPushMatrix();
			glTranslated(cx, -7.5, 1);
			glScaled(1, 1, 4);
			glutSolidCube(1);
			glPopMatrix();
		}

		glPushMatrix();
		glTranslated(0, -8.5, 1);
		glScaled(2, 1, 2);
		glutSolidCube(1);
		glPopMatrix();
		//traseira

		for (float cy = -7.5; cy >= -9.5; cy--)
		{
			glPushMatrix();
			glTranslated(-3.5, cy, 2);
			glScaled(1, 1, 2);
			glutSolidCube(1);
			glPopMatrix();
		}
		// motor esq

		for (float cy = -7.5; cy >= -9.5; cy--)
		{
			glPushMatrix();
			glTranslated(3.5, cy, 2);
			glScaled(1, 1, 2);
			glutSolidCube(1);
			glPopMatrix();
		}
		// motor dir

	//-----------------------------------
	glPushMatrix();

	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 1.0f, 1.0f);
	glVertex3f (-3,-3,4); // esq - baixo - frente
	glNormal3f(0.0f, 1.0f, 1.0f);
	glVertex3f (0,-3,4); // esq - baixo - frente
	glNormal3f(-1.0f, 1.0f, 1.0f);
	glVertex3f (3,-3,4); // dir - baixo - frente
	glNormal3f(1.0f, 1.0f, 0.0f);
	glVertex3f (1,8,1); // dir - cima - frente
	glNormal3f(-1.0f, 1.0f, 0.0f);
	glVertex3f (-1,8,1); // esq - cima - frente

	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(.0f, 0.0f, -1.0f);
	glVertex3f (-1,8,-1); // esq - cima - tras
	glVertex3f (1,8,-1); // dir - cima - tras
	glVertex3f (3,-3,-2); // dir - baixo - tras
	glVertex3f (-3,-3,-2); // esq - baixo - tras
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f (-1,8,-1); // esq - cima - tras
	glVertex3f (-1,8,1); // esq - cima - frente
	glVertex3f (-3,-3,4); // esq - baixo - frente
	glVertex3f (-3,-3,-2); // esq - baixo - tras
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f (1,8,-1); // dir - cima - tras
	glVertex3f (3,-3,-2); // dir - baixo - tras
	glVertex3f (1,8,1); // dir - cima - frente
	glVertex3f (3,-3,4); // dir - baixo - frente
	glEnd();
	glPopMatrix();
	// ponta da nave




	glPopMatrix();
	glPopMatrix();

	_coord = x;
}


void SpaceShip::moveShip(unsigned char key){


	switch (key){
		//Movimenta para a esquerda
	case 'A': 
		{
			if(_x > -85){
				_x -= 4;
			}
			break;
		}
		//Movimenta para a direita
	case 'D':
		{
			if(_x < 85){
				_x += 4;
			}
			break;
		}
	}
	glutPostRedisplay();
}


SpaceShip::~SpaceShip(void)
{
}
