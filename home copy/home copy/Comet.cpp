#include "Comet.h"

Comet::Comet(float x, float y, ALLEGRO_BITMAP* image) {
	GameObject::Init(x,  y, 5, 0, -1, 0, 35, 35);
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



}
void Comet::Render() {
	GameObject::Render();

}
void Comet::Collided(int objectID) {
	if (objectID == BORDER) {
		//destroy
	}
	if (objectID != ENEMY)
		SetAlive(false);
}