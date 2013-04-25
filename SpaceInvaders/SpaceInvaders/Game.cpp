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

		MissileInv[i] = new Missile();
		MissileInv[i]->setAlive(false);

		alienx += 16; 

		if(i <= 4){
			Shields[i] = new Shield();
		} 
	}
	
	MissileShip = new Missile();
	MissileShip->setAlive(false);

	Ship = new SpaceShip();

	Box = new Background();

}



void Game::movementShip(unsigned char key){

	Ship->moveShip(key);
}


void Game::moveInvaders(){
/* alterar o vector columns para ter o numero de aliens que cada coluna tem, quando uma posiçao chega a zero a coluna está vazia.
	cada alien quando morre deve decrementar a posição correspondente à sua coluna */
	
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

			if (Down == true) //só anda para baixo
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

void Game::moveMissile(){
	float step = 2;
	if(MissileShip->getAlive() != false){
		if(MissileShip->getY() > 97) 
			MissileShip->setAlive(false);
		int y = MissileShip->getY();
		MissileShip->setY(y+step);
	}
}


void Game::moveInvMissiles(){ // move os dos aliens ----
	float step = 2;

	for(int i = 0; i <= 10; i++){

		if (MissileInv[i]->getAlive()){

			if(MissileInv[i]->getY() < -85) 
				MissileInv[i]->setAlive(false);
			else {
				int y = MissileInv[i]->getY();
				MissileInv[i]->setY(y - step);
				printf("%d\n", y);
			}		
		}
	}
}

void Game::shootInvMissiles(){
	
	srand(time(NULL));

	int inv_num = rand() % 10; // num da coluna do invader q pode disparar

	for (int i = 0; i < 11; i++)
	{
		if (MissileInv[inv_num]->getAlive())
		{
				inv_num = rand() % 10;

		}else break;
	}
	
	if (InvPurple[inv_num]->getAlive())	{

		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvPurple[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvPurple[inv_num]->getY()-10);
		
	}else if(InvBlue[inv_num]->getAlive())
	{
		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvBlue[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvBlue[inv_num]->getY()-10);
		
	}else if (InvGreen[inv_num]->getAlive())
	{
		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvGreen[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvGreen[inv_num]->getY()-10);

	}else if (InvRed[inv_num]->getAlive())
	{
		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvRed[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvRed[inv_num]->getY()-10);
		
	}
}


void Game::newMissile(){

	if (MissileShip->getAlive() == false){

		MissileShip->setAlive(true);
		MissileShip->setX(Ship->getX());
		MissileShip->setY(-75);
	}
}

void Game::drawObjects(){
	float sitiox = -64;
	float sitioy = -60;
	

	for(int i = 0; i <= 10; i++){
		
		InvRed[i]->draw(InvRed[i]->getX(), InvRed[i]->getY()); // fila 1
		InvGreen[i]->draw(InvGreen[i]->getX(), InvGreen[i]->getY()); // fila 2
		InvBlue[i]->draw(InvBlue[i]->getX(), InvBlue[i]->getY()); // fila 3
		InvPurple[i]->draw(InvPurple[i]->getX(), InvPurple[i]->getY()); // fila 4
		
		if(MissileInv[i]->getAlive()) 
			MissileInv[i]->draw(MissileInv[i]->getX(), MissileInv[i]->getY());
	}

	Shields[0]->draw(sitiox, sitioy);
	Shields[1]->draw(sitiox + 40, sitioy);
	Shields[2]->draw(sitiox + 88, sitioy);
	Shields[3]->draw(sitiox + 128, sitioy);
	

	Ship->draw(Ship->getX(), -85); // base do ecrã

	if(MissileShip->getAlive() != false) 
		MissileShip->draw(MissileShip->getX(), MissileShip->getY());

	printf("ola\n");
	Box->draw();

}

void Game::switchView(float w, float h, int cam){

	View->setCamera(w, h, cam, Ship->getX());

}

void Game::toggleLight(int light){
	
	GLfloat pos[] = {0.0, 0.0, 1.0, 0};
	GLfloat amb_white[] = {.5, .5, .5, 1.0}; //Fully white
	GLfloat dif_white[] = {0.8, 0.8, 0.8, 1.0}; //Fully white
	GLfloat shine[] = {1, 1, 1, 1.0}; //Bright - para testar brilho da nave

	GLfloat amb_spot[] = {.5, .5, .5, 1.0};
	GLfloat dif_spot[] = {.8, .8, .8, 1.0};
	GLfloat shine2[] = {1, 1, 1, 1.0}; 

	if(light == 1) {
		glEnable(GL_LIGHTING); 
		glEnable(GL_LIGHT0);

		glLightfv(GL_LIGHT0,GL_POSITION,pos);

		glLightfv(GL_LIGHT0, GL_AMBIENT, amb_white);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif_white);
		glLightfv(GL_LIGHT0, GL_SPECULAR, shine);

	}else if(light == 2){
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);


		// luz esq
		GLfloat spotPosition1[] = {Ship->getX()-16.5, -95.0f, 5.0f, 1.0f};
		glLightfv(GL_LIGHT1,GL_POSITION,spotPosition1);

		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10); 

		GLfloat spotDirection1[] = {0.0f, 1.0f, 0.0f};
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection1);

		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0f);
		

		glLightfv(GL_LIGHT1, GL_AMBIENT, amb_spot);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, dif_spot);
		glLightfv(GL_LIGHT1, GL_SPECULAR, shine2);

		// luz - dir
		GLfloat spotPosition2[] = {Ship->getX()+16.5, -95.0f, 5.0f, 1.0f};
		glLightfv(GL_LIGHT2,GL_POSITION,spotPosition2);

		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 10); 

		GLfloat spotDirection2[] = {0.0f, 1.0f, 0.0f};
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDirection2);

		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 5.0f);

		glLightfv(GL_LIGHT2, GL_AMBIENT, amb_spot);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, dif_spot);
		glLightfv(GL_LIGHT2, GL_SPECULAR, shine2);

	}else{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
	}


	glutPostRedisplay();
}



Game::~Game(void)
{
}
