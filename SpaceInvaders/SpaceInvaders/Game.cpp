#include "stdafx.h"
#include "Game.h"

Game::Game(void)
{

	srand(time(NULL));

	for (int i = 0; i <= 10; i++)
	{
			columns[i] = 4;
	}

	inv[0] = InvPurple;
	inv[1] = InvBlue;
	inv[2] = InvGreen;
	inv[3] = InvRed;

	Score = 0;
	Down = false;// se desce
	Right = true; // se anda para direita
	Max = 10; //mov invaders
	Min = 0; //mov invaders
	alienx = -80.0; //coord init
	alieny = 90.0; //coord init
	objectInit();
	Ship->setX(0); //coord init
}

void Game::resetObjects(){

	for(int i = 0; i <= 10; i++){

		
		InvRed[i]->setX(alienx);
		InvRed[i]->setY(alieny);
		InvRed[i]->setAlive(true);
		
		InvGreen[i]->setX(alienx);
		InvGreen[i]->setY(alieny-15);
		InvGreen[i]->setAlive(true);
		
		InvBlue[i]->setX(alienx);
		InvBlue[i]->setY(alieny-30);
		InvBlue[i]->setAlive(true);
		
		InvPurple[i]->setX(alienx);
		InvPurple[i]->setY(alieny-45);
		InvPurple[i]->setAlive(true);

		
		MissileInv[i]->setInv(true);
		MissileInv[i]->setAlive(false);

		alienx += 16; 

		if(i <= 4){
			Shields[i]->resetShields();
		} 
	}


	MissileShip->setAlive(false);

	Ship->setAlive(true);
	Ship->resetShip();

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
		MissileInv[i]->setInv(true);
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

int Game::aliensAlive(){

	for (int i = 0; i <= 10; i++)
	{
		if(columns[i] != 0) return 1;
	}

	return 0;
}

void Game::restartGame(){

	for (int i = 0; i <= 10; i++)
	{
		columns[i] = 4;
	}

	Score = 0;
	Down = false;// se desce
	Right = true; // se anda para direita
	Max = 10; //mov invaders
	Min = 0; //mov invaders
	alienx = -80.0; //coord init
	alieny = 90.0; //coord init
	resetObjects();
	Ship->setX(0); //coord init
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


void Game::moveInvMissiles(){ // move os dos aliens
	float step = 2;

	for(int i = 0; i <= 10; i++){

		if (MissileInv[i]->getAlive()){

			if(MissileInv[i]->getY() < -95) 
				MissileInv[i]->setAlive(false);
			else {
				int y = MissileInv[i]->getY();
				MissileInv[i]->setY(y - step);
			}		
		}
	}
}

void Game::shootInvMissiles(){

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
		PlaySound(TEXT("sounds/laserinvader.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
		
	}else if(InvBlue[inv_num]->getAlive())
	{
		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvBlue[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvBlue[inv_num]->getY()-10);
		PlaySound(TEXT("sounds/laserinvader.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
		
	}else if (InvGreen[inv_num]->getAlive())
	{
		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvGreen[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvGreen[inv_num]->getY()-10);
		PlaySound(TEXT("sounds/laserinvader.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);

	}else if (InvRed[inv_num]->getAlive())
	{
		MissileInv[inv_num]->setAlive(true); 
		MissileInv[inv_num]->setX(InvRed[inv_num]->getX()); 
		MissileInv[inv_num]->setY(InvRed[inv_num]->getY()-10);
		PlaySound(TEXT("sounds/laserinvader.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
	}

	
}

void Game::updateScore(int alien){

	switch (alien)
	{
	case 0:
		Score += 10;
		break;
	case 1:
		Score += 20;
		break;
	case 2:
		Score += 30;
		break;
	case 3:
		Score += 40;
		break;
	default:
		break;
	}
}

int Game::getScore(){
	return Score;
}
int Game::getShipLives(){

	return Ship->getLives();
}

void Game::colisionMissileInv(){


	for (int a = 0; a <= 10; a++)// Para os misseis dos Invaders e Shields
	{
		if (MissileInv[a]->getAlive())
		{
			float radius2, invx, invy;

			radius2 = MissileInv[a]->getRadius();
			invx = MissileInv[a]->getX();
			invy = MissileInv[a]->getY();

			for (int b = 0; b < 4; b++) // ciclo para percorrer cada escudo e ver se os aliens lhe acertam
			{
				if (Shields[b]->getAlive())
				{
					float radius1, shldx, shldy, distance;
					radius1 = Shields[b]->getRadius();	
					shldx = Shields[b]->getX();
					shldy = Shields[b]->getY();

					distance = sqrt((shldx - invx)*(shldx - invx) + (shldy - invy)*(shldy - invy));

					if (distance <= (radius1+radius2))
					{
						Shields[b]->hitChar();
						Shields[b]->switchShield();

						if (Shields[b]->getLives() == 0) // só destroi quando não houverem mais vidas
							Shields[b]->setAlive(false);

						MissileInv[a]->setAlive(false);
					}
				}
			}

			if (MissileInv[a]->getAlive() && Ship->getAlive()) // ciclo para ver se os aliens acertam na nave
			{
				float radius3, shipx, shipy, distance;
				radius3 = Ship->getRadius();	
				shipx = Ship->getX();
				shipy = Ship->getY();

				distance = sqrt((shipx - invx)*(shipx - invx) + (shipy - invy)*(shipy - invy));

				if (distance <= (radius3+radius2))
				{
					Ship->part->randParticles(Ship->getX(), Ship->getY());

					Ship->hitChar();

					PlaySound(TEXT("sounds/explosion.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);


					if (Ship->getLives() == 0) // só mata quando não houverem mais vidas
						Ship->setAlive(false);

					MissileInv[a]->setAlive(false);
				}
			}
		}
	}
}

void Game::colisionMissileShip(){


	if (MissileShip->getAlive())
	{
		float radius1, msx, msy, distance;
		radius1 = MissileShip->getRadius();	
		msx = MissileShip->getX();
		msy = MissileShip->getY();

		for (int b = 0; b <= 3; b++) // Para o missil da SpaceShip e Invaders
		{
			for (int a = 0; a <= 10; a++)
			{
				if (inv[b][a]->getAlive())
				{
					float radius2, invx, invy;

					radius2 = inv[b][a]->getRadius();
					invx = inv[b][a]->getX();
					invy = inv[b][a]->getY();

					distance = sqrt((msx - invx)*(msx - invx) + (msy - invy)*(msy - invy));

					if (distance <= (radius1+radius2))
					{
						inv[b][a]->part->randParticles(inv[b][a]->getX(), inv[b][a]->getY());
						updateScore(b);
						MissileShip->setAlive(false);
						columns[a]--;
						inv[b][a]->setAlive(false);
						PlaySound(TEXT("sounds/invaderkilled.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
						break;
					}

				}
			}
		}

		if (MissileShip->getAlive()) // Para o missil da SpaceShip e Shields
		{

			for (int b = 0; b < 4; b++) // ciclo para percorrer cada escudo e ve se a nave lhe acerta
			{
				if (Shields[b]->getAlive())
				{
					float radius2, shldx, shldy, distance;
					radius2 = Shields[b]->getRadius();	
					shldx = Shields[b]->getX();
					shldy = Shields[b]->getY();

					distance = sqrt((shldx - msx)*(shldx - msx) + (shldy - msy)*(shldy - msy));

					if (distance <= (radius1+radius2))
					{
						Shields[b]->hitChar();
						Shields[b]->switchShield();

						if (Shields[b]->getLives() == 0) // só mata quando não houverem mais vidas
							Shields[b]->setAlive(false);

						MissileShip->setAlive(false);
					}
				}
			}
		}
	}
}

void Game::colisionInvaders(){

	for (int b = 0; b <= 3; b++) // Para a colisão dos Invaders com os Shields
	{
		for (int a = 0; a <= 10; a++)
		{
			if (inv[b][a]->getAlive())
			{
				float radius2, invx, invy;

				radius2 = inv[b][a]->getRadius();
				invx = inv[b][a]->getX();
				invy = inv[b][a]->getY();

				for (int c = 0; c < 4; c++) // ciclo para percorrer cada escudo e ve se o invader lhe acerta
				{
					if (Shields[c]->getAlive())
					{
						float radius1, shldx, shldy, distance;
						radius1 = Shields[c]->getRadius();	
						shldx = Shields[c]->getX();
						shldy = Shields[c]->getY();

						distance = sqrt((shldx - invx)*(shldx - invx) + (shldy - invy)*(shldy - invy));

						if (distance <= (radius1+radius2))
							Shields[c]->setAlive(false);
					}
				}

				if (inv[b][a]->getAlive())
				{
					float radius4, shipx, shipy, distance;
					radius4 = Ship->getRadius();	
					shipx = Ship->getX();
					shipy = Ship->getY();

					distance = sqrt((shipx - invx)*(shipx - invx) + (shipy - invy)*(shipy - invy));

					if (distance <= (radius4+radius2))
						while (Ship->getLives())
							Ship->hitChar(); 

				}

				if(inv[b][a]->getY() <= -85) 
					while (Ship->getLives())
						Ship->hitChar();     // Game Over caso os aliens cheguem à base do ecrã
			}
		}
	}

}

void Game::wasHit(){

	// Respeitante às colisões dos misseis dos Invaders
	colisionMissileInv();

	// Respeitante às colisões do missil da SpaceShip
	colisionMissileShip();
	
	// Respeitante às colisões dos Invaders
	colisionInvaders();

}

void Game::newMissile(){

	if (MissileShip->getAlive() == false && Ship->getAlive()){

		MissileShip->setAlive(true);
		MissileShip->setX(Ship->getX());
		MissileShip->setY(-75);
		PlaySound(TEXT("sounds/laser.wav"), NULL, SND_FILENAME|SND_NODEFAULT|SND_ASYNC);
	}
}


void Game::drawObjects(int debug){
	float sitiox = -64;
	float sitioy = -60;
	GLfloat blue[] = {0,0.75,1,1};
	GLfloat red[] = {1,0.14,0,1};
	GLfloat purple[] = {0.59,0.0,0.82,1};
	GLfloat green[] = {0.5,1.0,0,1};
	GLfloat ship[] = {.25,.25,.25,1};


	for(int i = 0; i <= 10; i++){
		
		if(InvRed[i]->getAlive())
			InvRed[i]->draw(InvRed[i]->getX(), InvRed[i]->getY(), debug); // fila 1
		else if (InvRed[i]->part->getAlive())
			InvRed[i]->part->drawParticles(red); // fila 1

		if(InvGreen[i]->getAlive())
			InvGreen[i]->draw(InvGreen[i]->getX(), InvGreen[i]->getY(), debug); // fila 2
		else if (InvGreen[i]->part->getAlive())
				InvGreen[i]->part->drawParticles(green); // fila 2

		if(InvBlue[i]->getAlive())
			InvBlue[i]->draw(InvBlue[i]->getX(), InvBlue[i]->getY(), debug); // fila 3
		else if (InvBlue[i]->part->getAlive())
			InvBlue[i]->part->drawParticles(blue); // fila 3
		
		if(InvPurple[i]->getAlive())
			InvPurple[i]->draw(InvPurple[i]->getX(), InvPurple[i]->getY(), debug); // fila 4
		else if (InvPurple[i]->part->getAlive())
			InvPurple[i]->part->drawParticles(purple); // fila 4

		if(MissileInv[i]->getAlive()) 
			MissileInv[i]->draw(MissileInv[i]->getX(), MissileInv[i]->getY(), debug);
	}

	
		if(Shields[0]->getAlive()) Shields[0]->draw(sitiox, sitioy, debug);
		if(Shields[1]->getAlive()) Shields[1]->draw(sitiox + 40, sitioy, debug);
		if(Shields[2]->getAlive()) Shields[2]->draw(sitiox + 88, sitioy, debug);
		if(Shields[3]->getAlive()) Shields[3]->draw(sitiox + 128, sitioy, debug);


	if(Ship->getAlive()) Ship->draw(Ship->getX(), -85, debug); // nave - na base do ecrã
	if (Ship->part->getAlive())
			Ship->part->drawParticles(ship); // particulas da nave

	if(MissileShip->getAlive() != false) 
		MissileShip->draw(MissileShip->getX(), MissileShip->getY(), debug); // missil da nave 

	Box->draw(); // desenho da textura
}

float Game::getShipPos(){
	return Ship->getX();
}

void Game::switchView(float w, float h, int cam){

	View->setCamera(w, h, cam, Ship->getX());

}

void Game::updateP(){


	for(int i = 0; i <= 10; i++){

		if (InvRed[i]->part->getAlive())
			InvRed[i]->part->moveParticles(); // fila 1

		if (InvGreen[i]->part->getAlive())
			InvGreen[i]->part->moveParticles(); // fila 2

		if (InvBlue[i]->part->getAlive())
			InvBlue[i]->part->moveParticles(); // fila 3

		if (InvPurple[i]->part->getAlive())
			InvPurple[i]->part->moveParticles(); // fila 4
	}

	if (Ship->part->getAlive())
			Ship->part->moveParticles(); // fila 1

}

void Game::toggleLight(int light){
	
	GLfloat pos[] = {0.0, 0.0, 1.0, 0};
	GLfloat amb_white[] = {.5, .5, .5, 1.0}; //Fully white
	GLfloat dif_white[] = {0.8, 0.8, 0.8, 1.0}; //Fully white
	GLfloat shine[] = {1, 1, 1, 1.0}; //Bright - para testar brilho da nave

	GLfloat amb_spot[] = {.5, .5, .5, 1.0};
	GLfloat dif_spot[] = {.8, .8, .8, 1.0};
	GLfloat shine2[] = {1, 1, 1, 1.0}; 


	if (View->getView())
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);

	}else if(light == 1) {

		glEnable(GL_LIGHTING); 
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);

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

		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.25);
		

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

		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.25);

		glLightfv(GL_LIGHT2, GL_AMBIENT, amb_spot);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, dif_spot);
		glLightfv(GL_LIGHT2, GL_SPECULAR, shine2);

	}else{
		glEnable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
	}


	glutPostRedisplay();
}



Game::~Game(void)
{
}
