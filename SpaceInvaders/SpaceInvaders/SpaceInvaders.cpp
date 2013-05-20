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
int debug = 0 ;
int gameover = 0;
int victory = 0;
int played_sound = 0;

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
			if (pause == 1 && !gameover)
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
		case 'l':						//Teclas para a iluminação
		case 'L': 
			if (!gameover && pause == 1)
			{
			if (light != 2)
				light++;
			else light = 0;					//Ligar/Desligar Luz
			}
			break;
		case 'y':							//Tecla para a pausa
		case 'Y':
			debug ? debug = 0 : debug = 1;
			break;
		case 'p':							//Tecla para a pausa
		case 'P':
			pause == 1 ? pause = 2 : pause = 1;
			break;
		case 'R':							//Tecla para a pausa
		case 'r':
			theGame->restartGame();
			gameover = 0;
			victory = 0;
			played_sound = 0;
			pause = 2;
			break;
		case 27:							// Escape key -- Exit game
			glutDestroyWindow (window);
			exit (0);
			break;
		case ' ':							//Disparar a nave				
			if (pause == 1 && gameover == 0)
			theGame->newMissile();
			break;
		
	}
}

void mySpecialKeyboard(int key, int x, int y){

	if (pause == 1 && gameover == 0){	
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


void printStatus(){

	theGame->switchView(global_width, global_height, 1); // activar camara ortogonal

	glDisable(GL_LIGHTING);

	if(pause == 2 && !gameover){


		glColor3f(1,1,1);
		string paused = "GAME PAUSED";
		string start = "Press 'P' key to play";

		glRasterPos2f(-21, 0);


		for(int i = 0; i < (int)paused.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, paused[i]);   //Desenha estado de jogo - pausa

		glRasterPos2f(-26, -10);

		for(int i = 0; i < (int)start.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[i]);   //Desenha o tecla a pressionar

	}else if (gameover && !victory)
	{

		glColor3f(1,1,1);
		string end = "GAME OVER";
		string restart = "Press 'R' key to restart";
		glRasterPos2f(-17, 0);


		for(int i = 0; i < (int)end.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, end[i]);   //Desenha estado do jogo - Game Over

		glRasterPos2f(-30, -10);

		for(int i = 0; i < (int)restart.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, restart[i]);   //Desenha a tecla a pressionar

		if (!played_sound)
		{
			PlaySound(TEXT("sounds/Death.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
			played_sound = 1;
		}

	}else{

		glColor3f(1,1,1);
		string end = "YOU WIN!";
		string restart = "Press 'R' key to restart";
		glRasterPos2f(-17, 0);

		for(int i = 0; i < (int)end.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, end[i]);   //Desenha estado do jogo - Game Over

		glRasterPos2f(-30, -10);

		for(int i = 0; i < (int)restart.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, restart[i]);   //Desenha a tecla a pressionar

		if (!played_sound)
		{
			PlaySound(TEXT("sounds/fanfare.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
			played_sound = 1;
		}
	}

	glEnable(GL_LIGHTING);

	theGame->switchView(global_width, global_height, camera_mode);
}


void myTimer(int value){

	int inv_dispara = rand() % 10 + 7;
	inv_dispara *= 100;

	if (theGame->getShipLives() != 0)
	{

		if (theGame->aliensAlive())
		{
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

			if (elapsedTime >= inv_dispara){
				previousTime3 = currentTime;	
				theGame->shootInvMissiles();
				}
			}
		}else{
			gameover = 1;
			victory = 1;
		}

	}else  gameover = 1;



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

void printHUD(){

	theGame->switchView(global_width, global_height, 1); // activar camara ortogonal

	glDisable(GL_LIGHTING);

	glColor3f(1,1,1);
	string result = "LIVES:";
	string lives = "lll ";

	glRasterPos2f(95, 89.75);


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

	glRasterPos2f(95, 80.75);

	for(int i = 0; i < (int)score.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);   //Desenha a string no HUD

	for(int i = 0; i < (int)points.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, points[i]);
	}

	glEnable(GL_LIGHTING);

	theGame->switchView(global_width, global_height, camera_mode);

};


void myDisplay() {

glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glViewport(0, 0, global_width, global_height);

printHUD();

if(gameover || pause == 2)
printStatus();

proj(global_width, global_height);


theGame->toggleLight(light);


theGame->drawObjects(debug);

glutSwapBuffers();

} 

void printMenu(){

	printf("\n\n");
	printf("        SPACE INVADERS            \n\n\n");
	printf("CONTROLS: \n\n");
	printf("Movement: A and D / Left and Right keys\n");
	printf("Shoot: Spacebar\n\n");
	printf("Settings:\n");
	printf("Pause game: P\n");
	printf("Restart game: R\n");
	printf("Exit game: Esc key\n");
	printf("Lighting Toggle: L\n");
	printf("Top View Camera: 1\n");
	printf("3rd Person Camera: 2\n");
	printf("1st Person Camera: 3\n");
	printf("Debug mode(Wireframe): Y\n");
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