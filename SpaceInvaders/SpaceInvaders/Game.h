#pragma once
#include "Char.h"
#include "Camera.h"
#include "Invader.h"
#include "BlueInvader.h"
#include "GreenInvader.h"
#include "RedInvader.h"
#include "PurpleInvader.h"
#include "SpaceShip.h"
#include "Shield.h"



class Game
{
private:

	int	  columns[11]; // vector para registar a posicao as colunas das pontas
	int Max;
	int Min;
	bool Down;
	bool Right;
	float alienx;
	float alieny;
	Char* InvBlue[11];
	Char* InvGreen[11];
	Char* InvRed[11];
	Char* InvPurple[11];
	Char* Ship;
	Char* Shields[4];
	Camera* View;


public:

	void moveInvaders();
	void moveShip(unsigned char key);
	void switchView(float w, float h, int cam);
	void drawObjects();
	void objectInit();
	Game(void);
	~Game(void);
};

