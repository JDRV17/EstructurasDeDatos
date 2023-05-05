//Samuel Rueda, Juan Diego Rojas
#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;

typedef int Elemento;

class Nodo{
   public:
     Elemento dato;
     Nodo* sig;
     Nodo* ant;

     ~Nodo();
};

class Lista{
  private:
    Nodo* act;

  public:
    Lista();

    void anxLista(Elemento elem);
    void insLista(Elemento elem, int pos);
    void elimLista(int pos);

    Elemento infoLista(int pos);
    int longLista();
    bool vaciaLista();
};

#endif
