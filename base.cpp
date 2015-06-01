#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "allegro.h"
#include "personaje.h"

#define N 120

enum
{KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

    int
main (int argc, char **argv)
{
    ALLEGRO_BITMAP *hoja_de_dibujos=NULL;
    bool tecla[4]={false, false, false, false};
    Personaje personaje[N];
    srand(time(NULL)); 
    iniciar_allegro();
    hoja_de_dibujos =al_load_bitmap_ (SPRITESHEET); 
    al_convert_mask_to_alpha(hoja_de_dibujos, al_map_rgb(255,0,255);

	    if(!hoja_de_dibujos){

	    al_show_native_message_box(visualizacion,"Error","Error","No se puede crear el bitmap", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	    al_destroy_timer(tiempo);
	    al_destroy_display(visualizacion);
	    exit(EXIT_FAILURE);
	    }

	    for(int i=0; i<N; i++)
	    personaje[i].set_dibujo(bm);

	    while(1){
	    ALLEGRO_EVENT evento;
	    ALLEGRO_TIMEOUT tiempo_de_salida;
	    al_init_timeout(&tiempo_de_salida, 0.06);

	    bool get_event = al_wait_for_event_until (cola_eventos, &evento, &tiempo_de_salida);

	    if(get_event)
	    {
	    if(evento.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
	    break;
	    if(evento.type==ALLEGRO_EVENT_TIMER)
		redibujar= true;
	    if(evento.type==ALLEGRO_EVENT_KEY_DOWN)
	    {
		switch (evento.keyboard.keycode)
		{case ALLEGRO_EVENT_KEY_UP:
		    tecla[KEY_UP]=true;
		    break;
		    case ALLEGRO_KEY_DOWN:
		    tecla[KEY_DOWN]=true;
		    case ALLEGRO_KEY_RIGHT:
		    tecla[KEY_RIGHT]=true;
		    case ALLEGRO_KEY_LEFT:
		    tecla[KEY_LEFT]=true;
		}
	    }
	    if (tecla[KEY_UP])

		for(int i=0; i<N; i++)
		    personaje[i].actualizate ();
	    if(redibujar && al_is_event_queue_empty (cola_eventos))
	    {
		al_clear_to_color (al_map_rgb(0,0,0));
		for(int i00; i<N; i++)
		    al_draw_bitmap(personaje[i].get_dibujo(), personaje[i].get_x (), al flip_display();
			    redibujar=false;
			    }
			    }
			    destroy_allegro();
			    return 0;

	    }}
