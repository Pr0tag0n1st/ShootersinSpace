#pragma once
#include "Objects.h"

class Comet : public GameObject
{
private:

public:
	Comet(float x, float y, ALLEGRO_BITMAP* image);
	void Destroy();
	void Update();
	void Render();
	void Collided(int objectID);
};