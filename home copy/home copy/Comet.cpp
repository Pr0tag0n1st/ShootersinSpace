#include "Comet.h"

Comet::Comet(float x, float y, ALLEGRO_BITMAP* image) {
	GameObject::Init(x, y, 5, 0, -1, 0, 35, 35);
	SetID(ENEMY);

	//Animation
	maxFrame = 143;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 96;
	frameHeight = 96;
	animationColumns = 21;

	if (rand() % 2)
		animationDirection = 1;
	else
		animationDirection = -1;
}


void Comet::Destroy() {
	GameObject::Destroy();
}
void Comet::Update() {
	GameObject::Update();

	if (++frameCount = frameDelay) {
		curFrame += animationDirection;
		if (curFrame >= maxFrame)
			curFrame = 0;
		else if (curFrame <= 0)
			curFrame = maxFrame;

		frameCount = 0;
	}
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