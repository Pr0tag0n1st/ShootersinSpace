#pragma once
#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "Global.h"


class GameObject {
private:
	int ID;
	bool alive;
	bool collidable;




protected:
	//position
	double x;
	double y;
	//speed
	double xVel;
	double yVel;
	//direction
	int xDir;
	int yDir;
	//collision
	int xBound;
	int yBound;
	//animations
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;
	ALLEGRO_BITMAP*image;

public:
	GameObject();
	void virtual Destroy();
	void Init(double x, double y, double xVel, double yVel, int xDir, int yDir, int xBound, int yBound);
	void virtual Update();
	void virtual Render();
	double GetX() { return x; }
	double GetY() { return y; }
	void SetX(double x) { GameObject::x = x; }
	void SetY(double y) { GameObject::y = y; }
	int GetBoundX() { return xBound; }
	int GetBoundY() { return yBound; }
	int GetID() { return ID; }
	void SetID(int ID) { GameObject::ID = ID; }
	bool GetAlive() { return alive; }
	void SetAlive(bool alive) { GameObject::ID = ID; }
	bool GetCollidable() { return collidable; }
	void SetCollidable(bool collidable) { GameObject::collidable = collidable; }
	bool CheckCollision(GameObject *otherObject);
	void virtual Collided(int objectID);
	bool Collidable();


};