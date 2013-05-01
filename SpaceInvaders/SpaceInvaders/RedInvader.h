#pragma once
#include "Invader.h"

class RedInvader : public Invader{
	public:

		RedInvader(void);
		void draw(float x, float y);

	private:

		void drawHead();
		void drawBody();
		void drawLegs();
};

