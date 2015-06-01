#include <stdlib.h>
#include "personaje.h"

Personaje::Personaje()
{
    static int i=0;
    this ->x=0+5*i++;
    this ->y=10;
    this ->vx=rand() % 3 - 1;
    this ->vy=rand() % 3 - 1;
    this ->dibujo =NULL;
}

Personaje::Personaje (double x, double y=0) : x(x), y(y)
{
    this ->vx=rand() % 3 - 1;
    this ->vy=rand() % 3 - 1;
    this ->dibujo=NULL;
}

double
Personaje::get_x()
{
    return this->x;
}
double 
Personaje::get_y ()
{
    return this -> y;
}
ALLEGRO_BITMAP *Personaje::get_dibujo ()
{
    return this->dibujo;
}

void
Personaje::set_dibujo(ALLEGRO_BITMAP *cola){
    this->dibujo=cola;
}

void 
Personaje::actualiza()
{
    this->x += this ->vx;
    this->y += this ->vy;
}

