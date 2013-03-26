// SpaceInvaders.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Char.h"
#include "Camera.h"
#include "Invader.h"
#include "BlueInvader.h"
#include "GreenInvader.h"
#include "RedInvader.h"
#include "SpaceShip.h"
#include "Shield.h"
#include "Game.h"


#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

#define window_height 600
#define window_width 800


float global_width;
float global_height;
int camera_mode = 1;
Game * theGame;


void myKeyboard(unsigned char key, int x, int y){

	switch (key){
        case 'a':   //Movimenta para a esquerda
        case 'A':
        case 'd':   //Movimenta para a direita
        case 'D':
            if (key > 96) key -= 32;   //Torna todas as teclas primidas maiusculas
			theGame->moveShip(key);
            break;
<<<<<<< HEAD
		case '1': 
			camera_mode = 1;
			theGame->switchView(global_width, global_height, 1);	//Troca para a camera top view
			break;
		case '2': 
			camera_mode = 2;
			theGame->switchView(global_width, global_height, 2);	//Troca para a camera third person
			break;
		case '3': 
			camera_mode = 3;
			theGame->switchView(global_width, global_height, 3);	//Troca para a camera third person
			break;
=======
>>>>>>> ola?
		
	}
}

void mySpecialKeyboard(int key, int x, int y){

	switch (key){
	case GLUT_KEY_LEFT:{
			myKeyboard('A', x, y); //Movimenta para a esquerda
            break;}   
    case GLUT_KEY_RIGHT:{
			myKeyboard('D', x, y); //Movimenta para a direita
            break;}
	}
}

<<<<<<< HEAD
/*
void myTimer(int value){
=======
/*void myTimer(int value){
>>>>>>> ola?



	myTimer(value);
<<<<<<< HEAD
}
*/
=======
}*/
>>>>>>> ola?

void myReshape(GLsizei w, GLsizei h) {

	global_height = h;
	global_width = w;

}

void proj(float w, float h){

<<<<<<< HEAD
	theGame->switchView(w, h, camera_mode);
=======
float aspect_ratio = w/h;

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

/*  ----- para o jogo - sem desformatacao--- */
if(aspect_ratio >= 1)
glOrtho(-100.0f*aspect_ratio, 100.0f*aspect_ratio, -100.0f, 100.0f, -100.0f, 100.0f);
else
glOrtho(-100.0f, 100.0f, -100.0f/aspect_ratio, 100.0f/aspect_ratio, -100.0f, 100.0f);


/* ------------- original
if(aspect_ratio >= 1)
glOrtho(-100.0f*aspect_ratio, 100.0f*aspect_ratio, -100.0f, 100.0f, -100.0f, 100.0f);
else
glOrtho(-100.0f, 100.0f, -100.0f/aspect_ratio, 100.0f/aspect_ratio, -100.0f, 100.0f);
*/
glMatrixMode(GL_MODELVIEW);

glLoadIdentity();

>>>>>>> ola?

}



void myDisplay() {


glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT);

glViewport(0, 0, global_width, global_height);
proj(global_width, global_height);

theGame->drawObjects();

glFlush();

}

int main(int argc, char** argv){

int  janela;

theGame = new Game();

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

glutInitWindowPosition(-1, -1);

glutInitWindowSize(window_width, window_height);

janela = glutCreateWindow("SpaceInvaders");

glutDisplayFunc(myDisplay);

glutReshapeFunc(myReshape);

glutKeyboardFunc(myKeyboard);

glutSpecialFunc(mySpecialKeyboard);

//glutTimerFunc(40, myTimer, 0);

glutMainLoop();

return 0;
}