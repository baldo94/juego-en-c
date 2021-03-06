#ifndef __ALLEGRO_H__
#define __ALLEGRO_H__

#include <stdlib.h>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

#define SPRITESHEET "bart.png"
const float FPS=60;
extern ALLEGRO_EVENT_QUEUE *cola_eventos;
extern ALLEGRO_DISPLAY *visualizacion;
extern ALLEGRO_TIMER *tiempo;
extern ALLEGRO_BITMAP *bm;
extern bool redibujar;

#ifdef __cplusplus
extern "C"
{
#endif
    void iniciar_allegro ();
    void destriur_allegro ();
#ifdef __cplusplus
}
#endif
#endif

