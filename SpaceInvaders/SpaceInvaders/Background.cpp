#include "stdafx.h"
#include "Background.h"

#define SIZE 1024*768*3

Background::~Background(void)
{
	glDeleteTextures(1,&_texture);
}


Background::Background(){
	
	FILE *file;
	unsigned char * data;

	data = (unsigned char *) malloc(SIZE);

	GLuint BackgTexture = 0;
	file=fopen("2.raw","rb");
	if(file != NULL){
		fread(data,SIZE,1,file);
		fclose(file);
		glGenTextures(1,&BackgTexture);
		glBindTexture(GL_TEXTURE_2D,BackgTexture);
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D,0,4,1024,768,0,GL_RGB,GL_UNSIGNED_BYTE,data);
		gluBuild2DMipmaps( GL_TEXTURE_2D, 3, 1024, 768, GL_RGB, GL_UNSIGNED_BYTE, data );
	}
	free(data);
	_texture = BackgTexture;
}

void Background::draw(){

	//Material
	GLfloat ambient[] = {1,1,1,1};
	GLfloat diffuse[] = {0.5,0.5,0.5,0.5};
	GLfloat specular[] = {0,0,0,0.5};
	GLfloat emission[] = {1,1,1,1};
	GLfloat shininess[] = {60};
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glColor3f(1, 1, 1);
	
	//Textura
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,_texture);
	


	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);


	glTexCoord2f(0,0);
	glVertex3f(-150, -150, -5);
	glTexCoord2f(1,0);
	glVertex3f(150, -150, -5);
	glTexCoord2f(1,1);
	glVertex3f(150, 150, -5);
	glTexCoord2f(0,1);
	glVertex3f(-150, 150, -5);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}
