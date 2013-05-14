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
#include "Background.h"
#include "Particles.h"

class Game
{
private:

	int	columns[11]; // vector para registar a posicao as colunas das pontas
	int Max;
	int Min;
	int Score;
	bool Down;
	bool Right;
	float alienx;
	float alieny;
	GLfloat *blueMat;
	GLfloat * purpleMat;
	GLfloat * redMat;
	GLfloat * greenMat;
	Particles * parts;
	Invader* InvBlue[11];
	Invader* InvGreen[11];
	Invader* InvRed[11];
	Invader* InvPurple[11];
	SpaceShip* Ship;
	Shield* Shields[4];
	Char* MissileShip;
	Char* MissileInv[11];
	Camera* View;
	Background* Box;


public:

	int aliensAlive();
	void resetObjects();
	void restartGame();
	void updateP();
	int getShipLives();
	void updateScore(int alien);
	int getScore();
	void movementShip(unsigned char key);
	void moveInvaders();
	void moveMissile();
	void switchView(float w, float h, int cam);
	void drawObjects(int debug);
	void objectInit();
	void moveInvMissiles();
	void shootInvMissiles();
	void wasHit();
	void newMissile();
	void toggleLight(int light);
	float getShipPos();
	Game(void);
	~Game(void);
};

