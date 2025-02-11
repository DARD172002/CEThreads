#ifndef CANAL_H
#define CANAL_H
#include <uncontext.h>

typedef enum {
    DERECHA,
    IZQUIERDA
} Sentido;

typedef  enum{
    EQUIDAD,
    LETRERO,
    TICO
}Control;
typedef struct Canal{
    Sentido sentido;
    Ship *lefthShip;
    ship *rightShip;
    int size;
    int speed;
    Control algorithControl; 

};

#endif 