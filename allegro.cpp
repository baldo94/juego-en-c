#include "allegro.h"

ALLEGRO_EVENT_QUEUE *cola_eventos;
ALLEGRO_DISPLAY *visualizacion;
ALLEGRO_TIMER *tiempo;
ALLEGRO_BITMAP *bm;
bool redibujar;

void iniciar_allegro ()
{
    cola_eventos = NULL;
    visualizacion = NULL;
    tiempo =NULL;
    bm = NULL;
    redibujar =true;


    if(!al_init())
    {
	al_show_native_message_box(visualizacion, "Error", "Error", "No tengo allegro", NULL, ALLEGRO_MESSAGEBOX_ERROR
		);
	exit(EXIT_FAILURE);
    }
    if(!al_init_image_addon())
    {
	al_show_native_message_box (visualizacion, "Error", "Error", "No de ha añadido  la imagen", NULL, ALLEGRO_MESSAGEBOX_ERROR
		);
	exit(EXIT_FAILURE);
    }
    tiempo= al_create_timer(1.0/FPS);
    if(!tiempo)
    {
	al_show_native_message_box(visualizacion,"Error", "Error", "No se ha podido crear un temporizador",
		NULL, ALLEGRO_MESSAGEBOX_ERROR
		);
	exit(EXIT_FAILURE);
    }
    visualizacion = al_create_display (1024, 768);
    if(!visualizacion)
    {
	al_destroy_timer (tiempo);
	al_show_native_message_box(visualizacion, "Error", "Error", "Me he quedados sin visualizacion.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	exit(EXIT_FAILURE);
    }

    bm = al_load_bitmap(SPRITESHEET);
    if(!bm){
	al_show_native_message_box (visualizacion, "Error", "Error", "No se ha creado el bitmap.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer(tiempo);
	al_destroy_display(visualizacion);
	exit(EXIT_FAILURE);
    }

    cola_eventos =al_create_event_queue();
    if(!cola_eventos)
    {al_destroy_timer(tiempo);
	al_destroy_bitmap(bm);
	al_destroy_display(visualizacion);
	al_show_native_message_box(visualizacion, "Error", "Error","No se ha creado la cola de eventos.", NULL, ALLEGRO_MESSAGEBOX_ERROR
		);
	exit(EXIT_FAILURE);
    }
    al_register_event_source (cola_eventos, al_get_timer_event_source(tiempo));
    al_register_event_source (cola_eventos, al_get_display_event_source(visualizacion));

    al_clear_to_color (al_map_rgb (0, 0, 0));
    al_flip_display();
    al_start_timer (tiempo);
}
    void 
destruir_allegro()
{
    al_destroy_bitmap (bm);
    al_destroy_timer(tiempo);
    al_destroy_display(visualizacion),
	al_destroy_event_queue(cola_eventos);
}

