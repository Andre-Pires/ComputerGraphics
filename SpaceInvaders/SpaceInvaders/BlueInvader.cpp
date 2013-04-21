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
			glTranslated(-2, -1 + i, 0.1);
			glScaled(2,1,2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();
	}

	for(i = 0; i <2; i++){
			glPushMatrix();
			glTranslated(2, -1 + i, 0.1);
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

if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
{
GLfloat material[] = {0,0.75,1,1};
GLfloat emission[] = {0,0,0,1};
GLfloat specular[] = {0,0,0,0};
GLfloat shininess[] = {0};
glMaterialfv(GL_FRONT, GL_AMBIENT, material);
glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
glMaterialfv(GL_FRONT, GL_EMISSION, emission);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shininess);


}else glColor3f(0.0f, 0.75f, 1.0f);


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

glPushMatrix();

if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
{
GLfloat eye2_ambient[] = {0,0,0,1};
GLfloat eye2_diffuse[] = {0.03,0.03,0.03,1};
GLfloat eye2_specular[] = {0,0,0,1};
GLfloat eye2_emission[] = {0,0,0,1};
GLfloat eye2_shininess[] = {0};
glMaterialfv(GL_FRONT, GL_EMISSION, eye2_emission);
glMaterialfv(GL_FRONT, GL_AMBIENT, eye2_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, eye2_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, eye2_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, eye2_shininess);

}else glColor3f(0.0f, 0.0f, 0.0f);

draw_eyes(); //olhos
glPopMatrix();

glPopMatrix();

glPopMatrix();
}