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
#include "Missile.h"


#define window_height 600
#define window_width 800

using namespace std;


float global_width;
float global_height;
float currentTime;
float previousTime;
float elapsedTime;
float previousTime2;
float previousTime3;
int old_camera_mode = 1;
int camera_mode = 1;
int light = 0; 
int prev_light = 0;

static int window;
static int menu_id;
static int submenu_id;

int pause = 2; 



Game * theGame;

void myKeyboard(unsigned char key, int x, int y){

	switch (key){
        case 'a':   //Movimenta para a esquerda
        case 'A':
        case 'd':   //Movimenta para a direita
        case 'D':
            if (key > 96) key -= 32;   //Torna todas as teclas premidas maiusculas
			theGame->movementShip(key);
            break;
		case '1': 
			camera_mode = 1;
			glutPostRedisplay();		//Troca para a camera top view
			break;
		case '2': 
			camera_mode = 2;
			glutPostRedisplay();		//Troca para a camera third person
			break;
		case '3': 
			camera_mode = 3;
			glutPostRedisplay();		//Troca para a camera third person
			break;
		case 'l': 
		case 'L': 
			if (key > 96) key -= 32;   //Torna todas as teclas premidas maiusculas
			if (light != 2)
				light++;
			else light = 0;		//Ligar/Desligar Luz
			break;
		case 'p':
		case 'P':
			pause == 1 ? pause = 2 : pause = 1;
			break;
		case 27: // Escape key
			glutDestroyWindow (window);
			exit (0);
			break;
		case ' ':
			if (pause == 1)	
			theGame->newMissile();
			break;
		
	}
}

void mySpecialKeyboard(int key, int x, int y){

	if (pause == 1){	
		switch (key){
		case GLUT_KEY_LEFT:{
				myKeyboard('A', x, y); //Movimenta para a esquerda
				break;}   
		case GLUT_KEY_RIGHT:{
				myKeyboard('D', x, y); //Movimenta para a direita
				break;}
		}
	}
}

void menu(int num){

  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else
	num == 2 ? pause = 2 : pause = 1;
} 

void createMenu(void){
	submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Resume", 1);   
    glutAddMenuEntry("Pause", 2);    
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void myTimer(int value){

	int inv_dispara = rand() % 10 + 7;
	inv_dispara *= 100;

	if (pause == 1){	

	currentTime = glutGet(GLUT_ELAPSED_TIME);
	elapsedTime = currentTime - previousTime;

	theGame->moveMissile();
	theGame->updateP();
	

	if (elapsedTime >= 50)
	{
		previousTime = currentTime;	
		theGame->moveInvMissiles();
		theGame->wasHit();
	}

	elapsedTime = currentTime - previousTime2;

	if (elapsedTime >= 400)
	{
		previousTime2 = currentTime;	
		theGame->moveInvaders();
	}

	elapsedTime = currentTime - previousTime3;

	if (elapsedTime >= inv_dispara)
	{
		previousTime3 = currentTime;	
		theGame->shootInvMissiles();
	}

	}
	glutTimerFunc(10, myTimer, 0);

}



void myReshape(GLsizei w, GLsizei h) {

	global_height = h;
	global_width = w;

}

void proj(float w, float h){

	theGame->switchView(w, h, camera_mode);

	if (old_camera_mode != camera_mode) {
		light = 1;
		old_camera_mode = camera_mode;
	}
}



void myDisplay() {

glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glViewport(0, 0, global_width, global_height);
proj(global_width, global_height);


theGame->toggleLight(light);


theGame->drawObjects();

	glColor3f(1,1,1);
	string result = "LIVES:";
	string lives = "lll ";
	if(camera_mode == 1)
		glRasterPos2f(95, 89.75);
	else if(camera_mode == 2) 
		glRasterPos3f(theGame->getShipPos()+124, 100, 30);
	else glRasterPos3f(theGame->getShipPos()+46, 9, 43.60);



	for(int i = 0; i < (int)result.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, result[i]);   //Desenha a string no HUD

	for(int i = 0; i < (int)theGame->getShipLives(); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lives[i]);
	}

	glColor3f(1,1,1);
	string score = "SCORE:";
	stringstream ss;
	ss << theGame->getScore();
	string points = ss.str();
	if(camera_mode == 1)
		glRasterPos2f(95, 80.75);
	else if(camera_mode == 2) 
		glRasterPos3f(theGame->getShipPos()+125, 91, 23);
	else glRasterPos3f(theGame->getShipPos()+46, 9, 39.25);


	for(int i = 0; i < (int)score.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);   //Desenha a string no HUD

	for(int i = 0; i < (int)points.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, points[i]);
	}

glutSwapBuffers();

} 

void printMenu(){

	printf("\n\n");
	printf("        SPACE INVADERS            \n\n\n");
	printf("CONTROLS: \n\n");
	printf("Movement: A and D / Left and Right keys\n");
	printf("Shoot: Spacebar\n\n");
	printf("Settings:\n");
	printf("Pause: P\n");
	printf("Lighting Toggle: L\n");
	printf("Top View Camera: 1\n");
	printf("3rd Person Camera: 2\n");
	printf("1st Person Camera: 3\n");
	printf("\n\n\n");
	printf(" Andre Pires N:68593            \n");
	printf(" Joana Condeco N:68624            \n");
	

}

int main(int argc, char** argv){

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);

glutInitWindowPosition(-1, -1);

glutInitWindowSize(window_width, window_height);

window = glutCreateWindow("SpaceInvaders");

glEnable( GL_DEPTH_TEST );

createMenu();

theGame = new Game();

printMenu();

glutDisplayFunc(myDisplay);

glutReshapeFunc(myReshape);

glutKeyboardFunc(myKeyboard);

glutSpecialFunc(mySpecialKeyboard);
	
glutTimerFunc(0, myTimer, 0);

glutMainLoop();

return 0;
}