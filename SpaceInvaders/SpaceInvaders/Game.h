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
#include "Missile.h"

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif


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
	SpaceShip* Ship;
	Char* Shields[4];
	Char* MissileShip;
	Camera* View;


public:

	void movementShip(unsigned char key);
	void moveInvaders();
	void moveMissiles();
	void switchView(float w, float h, int cam);
	void drawObjects();
	void objectInit();
	void newMissile();
	void toggleLight(int light);
	Game(void);
	~Game(void);
};

