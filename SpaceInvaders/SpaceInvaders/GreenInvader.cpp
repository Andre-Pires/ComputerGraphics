#include "stdafx.h"
#include "GreenInvader.h"


GreenInvader::GreenInvader(void)
{
}

void GreenInvader::draw_legs(){

	int i, j = 0;

for(i = 0; i <4; i++) {

	glPushMatrix();
	glTranslated(-5+j, -4+j, 0);
	glScaled(2, 1, 2);
	glutSolidCube(1);
	j = (i + 1);
	glPopMatrix();
}

	j = 0;

for(i = 0; i <4; i++) {

	glPushMatrix();
	glTranslated(5-j, -4+j, 0);
	glScaled(2, 1, 2);
	glutSolidCube(1);
	j = (i + 1);
	glPopMatrix();
}

}

void GreenInvader::draw_body(){
	int i;

	for(i = 0; i <3; i++){
			glPushMatrix();
			glTranslated(0, i, 0);
			glScaled(12, 1, 2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();
	}
}

void GreenInvader::draw_head(){
	int i;
	int	size = 10;

	for(i = 0; i <2; i++){
			glPushMatrix();
			glTranslated(0, 3 + i, 0);
			glScaled(size, 1, 2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();	
			size -= 4;
		}

}

void GreenInvader::draw_eyes(){
	int i;

	
			glPushMatrix();
			glTranslated(-2.5, 1.25, 0.1);
			glScaled(3,1.25,2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();

	for(i = 0; i <2; i++){
			glPushMatrix();
			glTranslated(2.5, 1.25, 0.1);
			glScaled(3,1.25,2);
			glutSolidCube(1);
			glLoadIdentity();
			glPopMatrix();
	}
}

void GreenInvader::draw(float x, float y){

	_x = x;
	_y = y;

	GreenInvader inv;
	
	glPushMatrix();

	glTranslated(x, y, 0.0f);

	glPushMatrix();

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
		GLfloat material[] = {0.5,1.0,0,1};
		GLfloat emission[] = {0,0,0,1};
		GLfloat specular[] = {0,0,0,1};
		GLfloat shininess[] = {0};
		glMaterialfv(GL_FRONT, GL_AMBIENT, material);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	}else glColor3f(0.5f, 1.0f, 0.0f);

	glPushMatrix();
	draw_legs(); // pernas
	glPopMatrix();

	glPushMatrix();
	glScalef(2, 1, 2);
	glTranslated(0,-2,0);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glScalef(6, 1, 2);
	glTranslated(0,-1,0); //base do corpo
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	draw_body();	//corpo
	glPopMatrix();

	glPushMatrix();
	draw_head(); //cabeca
	glPopMatrix();

	if (glIsEnabled(GL_LIGHT0)|| glIsEnabled(GL_LIGHT1))
	{
		GLfloat eye2_ambient[] = {0,0,0,1};
		GLfloat eye2_diffuse[] = {0.03,0.03,0.03,1};
		GLfloat eye2_specular[] = {1,1,1,1};
		GLfloat eye2_emission[] = {0,0,0,1};
		GLfloat eye2_shininess[] = {128};
		glMaterialfv(GL_FRONT, GL_EMISSION, eye2_emission);
		glMaterialfv(GL_FRONT, GL_AMBIENT, eye2_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, eye2_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, eye2_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, eye2_shininess);

	}else glColor3f(0.0f, 0.0f, 0.0f); //preto

	glPushMatrix();
	draw_eyes(); //olhos
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


}