#include "Bullet.h"

Bullet::Bullet(float x, float y){
	GameObject::Init(x, y, 10, 0, 1, 0, 0, 0);
	SetID(BULLET);
}
void Bullet::Destroy() {
	GameObject::Destroy();
}
void Bullet::Update() {
	GameObject::Update();
	if (x > SCREENW)
		Collided(BORDER);
}
void Bullet::Render() {
	al_draw_filled_circle(x, y, 2, al_map_rgb(255, 255, 255));
}
void Bullet::Collided(int objectID){
	if (objectID == ENEMY || objectID == BORDER)
		SetAlive(false);
};