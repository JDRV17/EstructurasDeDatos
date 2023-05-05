//Samuel Rueda, Juan Diego Rojas
#ifndef  COLA_H
#define COLA_H

#include "lista.h"

typedef int Elemento;

class colaPrioridad{
   Lista l;

   public:
      colaPrioridad(); // crearCola
      Elemento front();
      void deque();
      void enqueue(Elemento);
      bool vaciaCola();
};

#endif
