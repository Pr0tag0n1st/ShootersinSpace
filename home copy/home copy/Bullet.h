#pragma once
#include "Objects.h"

class Bullet : public GameObject
{
private:

public:
	Bullet(float x, float y);
	void Destroy();
	void Update();
	void Render();
	void Collided(int objectID);
};