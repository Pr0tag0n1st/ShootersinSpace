#include "Comet.h"

Comet::Comet(float x, float y, ALLEGRO_BITMAP* image) {
	GameObject::Init(x, y, rand()%5, rand()%5, -1,  (rand()%5)-3, 35, 35);
	SetID(ENEMY);

	//Animation
	maxFrame = 1;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 35;
	frameHeight = 35;
	animationColumns = 1;

	
}


void Comet::Destroy() {
	GameObject::Destroy();
}
void Comet::Update() {
	GameObject::Update();



	if (x + frameWidth < 0)
		Collided(BORDER);
}
void Comet::Render() {
	GameObject::Render();
	int fx = (curFrame % animationColumns) *frameWidth;
	int fy = (curFrame / animationColumns) *frameHeight;
}
void Comet::Collided(int objectID) {
	if (objectID == BORDER) {
		//destroy
	}
	if (objectID != ENEMY)
		SetAlive(false);
}