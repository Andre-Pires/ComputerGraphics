#include "stdafx.h"
#include "Background.h"

#define SIZE 768*768*3
#define SIDE 1
#define STEP 0.003

Background::~Background(void)
{
	glDeleteTextures(1,&_texture);
}


Background::Background(){
	
	FILE *file;
	GLubyte * data;

	data = (GLubyte *) malloc(SIZE);

	GLuint BackgTexture = 0;
	file=fopen("star_texture.raw","rb");
	if(file != NULL){
		fread(data,SIZE,1,file);
		fclose(file);
		glGenTextures(1,&BackgTexture);
		glBindTexture(GL_TEXTURE_2D,BackgTexture);
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		glTexImage2D(GL_TEXTURE_2D,0,3,768,768,0,GL_RGB,GL_UNSIGNED_BYTE,data);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 768, 768, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	free(data);
	_texture = BackgTexture;
}

void Background::draw(){

	int y = 0, x = 0;
	float xt = 0, yt = 0;



	//Material
	GLfloat ambient[] = {1,1,1,1};
	GLfloat diffuse[] = {0.5,0.5,0.5,1};
	GLfloat specular[] = {0.8,0.8,0.8,1};
	GLfloat emission[] = {0.2,0.2,0.2,1};
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
 	glNormal3f(0, 0, 1);

	for (y = -150, yt = 0; y < 150; y += 1, yt += STEP)
	{
		for (x = -150, xt = 0; x < 150; x += 1, xt += STEP)
		{
			glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(xt,yt);
			glVertex3f(x, y, -2);
			glTexCoord2f(xt,yt+STEP);
			glVertex3f(x, y+SIDE, -2);
			glTexCoord2f(xt+STEP,yt+STEP);
			glVertex3f(x+SIDE, y+SIDE, -2);
			glTexCoord2f(xt+STEP,yt);
			glVertex3f(x+SIDE, y, -2);
			glEnd();
		}
	}

	glEnd();

	glDisable(GL_TEXTURE_2D);
}
