#include "stdafx.h"
#include "Game.h"

Game::Game(void)
{
	for (int i = 0; i <= 10; i++)
	{
		columns[i] = 1;
	}
	Down = false;// se desce
	Right = true; // se anda para direita
	Max = 10; //mov invaders
	Min = 0; //mov invaders
	alienx = -80.0; //coord init
	alieny = 90.0; //coord init
	objectInit();
	Ship->setX(0); //coord init
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


void Game::moveInvaders(){
/* alterar o vector columns para ter o numero de aliens que cada coluna tem, quando uma posi�ao chega a zero a coluna est� vazia.
	cada alien quando morre deve decrementar a posi��o correspondente � sua coluna */
	
	float step = 2;
	float MinBondary = -86;
	float MaxBondary = 86;
	float x, y;
						
			if (columns[Max] == 0) --Max;

			if (columns[Min] == 0) ++Min;

			if (Right && (InvRed[Max]->getX() == MaxBondary)){
				Down = true;
				Right = false;
			}else if (!Right && (InvRed[Min]->getX() == MinBondary))
			{
				Down = true;
				Right = true;
			}

			if (Down == true) //s� anda para baixo
			{
				Down = false;

					for(int i = Min; i <= Max; i++){

						y = InvRed[i]->getY(); // fila 1
						InvRed[i]->setY(y-5);
						y = InvGreen[i]->getY(); // fila 2
						InvGreen[i]->setY(y-5);
						y = InvBlue[i]->getY(); // fila 3
						InvBlue[i]->setY(y-5);
						y = InvPurple[i]->getY(); // fila 4
						InvPurple[i]->setY(y-5);
					}
				}else if (Right)
				{
					for(int i = Min; i <= Max; i++){

						x = InvRed[i]->getX(); // fila 1
						InvRed[i]->setX(x+step);
						x = InvGreen[i]->getX(); // fila 2
						InvGreen[i]->setX(x+step);
						x = InvBlue[i]->getX(); // fila 3
						InvBlue[i]->setX(x+step);
						x = InvPurple[i]->getX(); // fila 4
						InvPurple[i]->setX(x+step);
					} 
				}else{
					for(int i = Min; i <= Max; i++){

						x = InvRed[i]->getX(); // fila 1
						InvRed[i]->setX(x-step);
						x = InvGreen[i]->getX(); // fila 2
						InvGreen[i]->setX(x-step);
						x = InvBlue[i]->getX(); // fila 3
						InvBlue[i]->setX(x-step);
						x = InvPurple[i]->getX(); // fila 4
						InvPurple[i]->setX(x-step);
					}
				}

	glutPostRedisplay();
}

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
	

	Ship->draw(Ship->getX(), -85); // base do ecr�
}

void Game::switchView(float w, float h, int cam){

	View->setCamera(w, h, cam, Ship->getX());
	glutPostRedisplay();

}


Game::~Game(void)
{
}
