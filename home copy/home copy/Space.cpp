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

bool keys[5]{ false, false, false, false, false };
enum KEYS { UP, DOWN, LEFT, RIGHT, Z };

int main() {
	//Shell variables
	bool done = false;
	bool render = false;
	double gametime = 0;
	int frames = 0;
	int FPS = 0;
	//Project variables
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;
	ALLEGRO_TIMER*timer = NULL;
	ALLEGRO_FONT*font = NULL;

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
	display = al_create_display(SCREENW, SCREENH);

	//project inits
	//init font
	//init samples


	//Timer inits
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
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
		//Update section
		else if (ev.type == ALLEGRO_EVENT_TIMER) {
			render = true;
			frames++;
			if (al_current_time() - gametime >= 1) {
				gametime = al_current_time();
				FPS = frames;
				frames = 0;
			}
		}
		//Render section



		//Visual update
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

	}//end of gameloop
	//destroy objects
	return 0;
}//end of main
//function defs