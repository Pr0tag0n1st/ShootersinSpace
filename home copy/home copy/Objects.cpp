#include "Objects.h"
GameObject::GameObject() {
	x = 0;
	y = 0;
	xVel = 0;
	yVel = 0;
	xDir = 0;
	yDir = 0;
	xBound = 0;
	yBound = 0;
	maxFrame = 0;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 0;
	frameHeight = 0;
	animationColumns = 0;
	animationDirection = 0;
	image = NULL;
	alive = true;
	collidable = true;
}
void GameObject::Destroy() {
	if (image != NULL)
	al_destroy_bitmap(image);

}
void GameObject::Init(double x, double y, double xVel, double yVel, int xDir, int yDir, int xBound, int yBound) {
	GameObject::x = x;
	GameObject::y = y;
	GameObject::xVel = xVel;
	GameObject::yVel = yVel;
	GameObject::xDir = xDir;
	GameObject::yDir = yDir;
	GameObject::xBound = xBound;
	GameObject::yBound = yBound;
}
void GameObject::Update() {
	x += xVel * xDir;
	y += yVel * yDir;

}


void GameObject::Render() {

}
bool GameObject::CheckCollision(GameObject *otherObject) {
	double oX = otherObject->GetX();
	double oY = otherObject->GetY();
	int obX = otherObject->GetBoundX();
	int obY = otherObject->GetBoundY();
	if (x + xBound > oX - obX &&
		x - xBound < oX + obX &&
		y + yBound > oY - obY &&
		y - yBound < oY + obY)
		return true;
	else
		return false;

}
void GameObject::Collided(int objectID) {

}
bool GameObject::Collidable() {
	return alive && collidable;
}