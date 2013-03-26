#include "stdafx.h"
#include "Game.h"

Game::Game(void)
{
	alienx = -80.0;
	alieny = 90.0;
	objectInit();
	Ship->setX(0);
}

void Game::objectInit(){

	View = new Camera();

	for(int i = 0; i <= 10; i++){
		
		InvRed[i] = new RedInvader();
		InvRed[i]->setX(alienx);
		InvRed[i]->setY(alieny);
		InvGreen[i] = new GreenInvader();
		InvGreen[i]->setX(alienx);
		InvGreen[i]->setY(alieny-15);
		InvBlue[i] = new BlueInvader();
		InvBlue[i]->setX(alienx);
		InvBlue[i]->setY(alieny-30);
		InvPurple[i] = new PurpleInvader();
		InvPurple[i]->setX(alienx);
		InvPurple[i]->setY(alieny-45);
		
		alienx += 16;

		if(i <= 4){
			Shields[i] = new Shield();
		} 
	}

	Ship = new SpaceShip();
}



void Game::moveShip(unsigned char key){

	float xShip = Ship->getX();

	switch (key){
		//Movimenta para a esquerda
	case 'A': 
		{
			if(xShip > -85){
				xShip -= 4;
				Ship->setX(xShip);
			}
			break;
		}
        //Movimenta para a direita
	case 'D':
		{
			if(xShip < 85){
				xShip += 4;
				Ship->setX(xShip);
			}
			break;
		}
	}
	glutPostRedisplay();
}

/*
void Game::moveInvaders(){





	switch (){
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
*/

void Game::drawObjects(){

	float sitiox = -64;
	float sitioy = -60;
	
	for(int i = 0; i <= 10; i++){
		
		InvRed[i]->draw(InvRed[i]->getX(), InvRed[i]->getY()); // fila 1
		InvGreen[i]->draw(InvGreen[i]->getX(), InvGreen[i]->getY()); // fila 2
		InvBlue[i]->draw(InvBlue[i]->getX(), InvBlue[i]->getY()); // fila 3
		InvPurple[i]->draw(InvPurple[i]->getX(), InvPurple[i]->getY()); // fila 4
	}

	Shields[0]->draw(sitiox, sitioy);
	Shields[1]->draw(sitiox + 40, sitioy);
	Shields[2]->draw(sitiox + 88, sitioy);
	Shields[3]->draw(sitiox + 128, sitioy);
	

	Ship->draw(Ship->getX(), -85); // base do ecrã
}

void Game::switchView(float w, float h, int cam){

	View->setCamera(w, h, cam, Ship->getX());
	glutPostRedisplay();

}


Game::~Game(void)
{
}
