#ifndef __PERSONAJE_H__
#define __PERSONAJE_H__

#include <allegro5/allegro.h>

class Personaje
{
private:
    double x;
    double y;
    double vx;
    double vy;


    ALLEGRO_BITMAP *dibujo;

public:
    Personaje();
    Personaje (double x, double y);
    void actualiza();
    double get_x();
    double get_y();
    ALLEGRO_BITMAP *get_dibujo();
    void set_dibujo (ALLEGRO_BITMAP *cola);
};

#endif

