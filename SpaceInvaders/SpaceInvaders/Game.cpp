#include "stdafx.h"
#include "Game.h"

Game::Game(void)
{
	xShip = 0;
	objectInit();
}

void Game::objectInit(){

<<<<<<< HEAD
	View = new Camera();

	for(int i = 0; i <= 16; i++){
=======
	for(int i = 0; i <= 10; i++){
>>>>>>> ola?
	
		InvBlue[i] = new BlueInvader();
		InvGreen[i] = new GreenInvader();
		InvRed[i] = new RedInvader();
		InvPurple[i] = new PurpleInvader();

		if(i <= 4){
			Shields[i] = new Shield();
		} 
	}

	Ship = new SpaceShip();
}


void Game::moveShip(unsigned char key){

	switch (key){
		//Movimenta para a esquerda
	case 'A': 
		{
			if(xShip > -85){
				xShip -= 4;
			}
			break;
		}
        //Movimenta para a direita
	case 'D':
		{
			if(xShip < 85){
				xShip += 4;
			}
			break;
		}
	}
	glutPostRedisplay();
}


void Game::drawObjects(){

	float sitiox = -80.0;
	float sitioy = 90.0;
	
	for(int i = 0; i <= 10; i++){
		
		InvRed[i]->draw(sitiox, sitioy); // fila 1
		InvGreen[i]->draw(sitiox, sitioy - 15); // fila 2
		InvBlue[i]->draw(sitiox, sitioy - 30); // fila 3
		InvPurple[i]->draw(sitiox, sitioy - 45); // fila 4

		sitiox += 16;
	}

	sitiox = -64.0;

	Shields[0]->draw(sitiox, -60);
	Shields[1]->draw(sitiox + 40, -60);
	Shields[2]->draw(sitiox + 88, -60);
	Shields[3]->draw(sitiox + 128, -60);
	

	Ship->draw(xShip, -85); // base do ecrã
}

void Game::switchView(float w, float h, int cam){

	View->setCamera(w, h, cam, xShip);
	glutPostRedisplay();

}


Game::~Game(void)
{
}
