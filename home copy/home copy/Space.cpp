#include <iostream>
using namespace std;
#include <fstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <list>

#include "Global.h"
#include "Objects.h"
#include "Spaceship.h"
bool keys[5]{ false, false, false, false, false };
enum KEYS { UP, DOWN, LEFT, RIGHT, Z };

//Globals
SpaceShip *ship;

list<GameObject *>objects;
list<GameObject *>::iterator iter;
list<GameObject *>::iterator iter2;

int main() {
	//Shell variables
	bool done = false;
	bool render = false;
	double gametime = 0;
	int frames = 0;
	int FPS = 60;
	//Project variables

	ship = new SpaceShip();

	//al_inits

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_install_keyboard();
	//al variables

	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;
	ALLEGRO_TIMER*timer = NULL;
	ALLEGRO_FONT*font = NULL;
	ALLEGRO_BITMAP*shipimage = NULL;


	//project inits
	font = al_load_font("slkscr.ttf", 15, 0);
	al_reserve_samples(15);
	shipimage = al_load_bitmap("spaceship.png");
	al_convert_mask_to_alpha(shipimage, al_map_rgb(255, 255, 255));
	display = al_create_display(SCREENW, SCREENH);
	ship->Init(shipimage);

	objects.push_back(ship);
	//init samples


	//Timer inits
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);
	gametime = al_current_time();
	
	//Start of game loop
	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//input algorithm
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_Z:
				keys[Z] = true;
				break;
			}
			
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_Z:
				keys[Z] = false;
				break;
			}
		}
		//TIMER SECTION
		//Update section
		else if (ev.type == ALLEGRO_EVENT_TIMER) {
			render = true;
			frames++;
			if (al_current_time() - gametime >= 1) {
				gametime = al_current_time();
				FPS = frames;
				frames = 0;
			}
			if (keys[UP])
				ship->MoveUp();
			else if (keys[DOWN])
				ship->MoveDown();
			else
				ship->ResetAnimation(1);
			if (keys[LEFT])
				ship->MoveLeft();
			else if (keys[RIGHT])
				ship->MoveRight();
			else
				ship->ResetAnimation(0);
			//movement
			for (iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();
			

			//collision
			for (iter = objects.begin(); iter != objects.end(); ++iter) {
				//skip if not collidable
				if (!(*iter)->Collidable()) continue;
				for (iter2 = iter; iter2 !=objects.end(); ++iter2) {
					//skip if not collidable
					if (!(*iter2)->Collidable()) continue;
					//Skip if same id
					if ((*iter)->GetID() == (*iter2)->GetID()) continue;
					if ( (*iter)->CheckCollision(*iter2)) {
						//Call collided functions
						(*iter)->Collided((*iter2)->GetID());
						(*iter2)->Collided((*iter)->GetID());
					}
				}
			}
			//Remove dead
			for(iter = objects.begin(); iter !=objects.end(); )
				if (!(*iter)->GetAlive()) {
					delete (*iter);
					iter = objects.erase(iter);
				}
				else 
					iter++;
		}
	



		//Visual update (Render section)
		if (render&&al_is_event_queue_empty(event_queue)) {
			render = false;

			//project specific render
			for (iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Render();

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}



	}//end of gameloop
	//destroy objects
	for(iter = objects.begin(); iter != objects.end();) {
		(*iter)->Destroy();
		delete (*iter);
		iter = objects.erase(iter);

	}
	//Shell objects
	return 0;
}//end of main
//function defs