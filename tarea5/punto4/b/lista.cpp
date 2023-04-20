#include "lista.h"
/*Información adicional obtenida de: https://learn.microsoft.com/es-es/cpp/cpp/this-pointer?view=msvc-170 (utilizada para entender el 
puntero this, que se utiliza para que en la sobrecarga de '+', pueda haber un solo parámetro; siendo el puntero this, equivalente
al valor actual, o al primer sumando, y el parámetro l2 que se ingresa, al segundo sumando. Lo tuve que hacer así para solucionar
un error que aparecía al intentar meter dos parámetros en el archivo .h)*/

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;                
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}

/*Cálculo de la complejidad: O(n^2)
Gran parte del código está en ciclos condicionales, por lo que todo se define en mejores o peores casos. En cualquier circunstancia, el
mejor caso será 0, que ocurrirá si se cumple la condición opuesta. En casi todo el resto, el peor caso será 1 vez, a excepción de los 
ciclos while. El primero se recorre n veces, y todo lo de su interior, n - 1 veces, debido a que no se recorre la lista completa sino
que se detiene un elemento antes de acabar (antes de que el puntero apunte a NULL). El segundo sí se recorre n + 1 veces, ya que sí 
llega hasta el puntero que apunta a NULL*/
Lista Lista::operator+(Lista l2)
{
  if (act == NULL)                //1
  {                               
    return l2;                    //peor caso: 1, mejor caso: 0
  } 
  else                            //1
  {        
    Lista l3 = *this;             //peor caso: 1, mejor caso: 0
    Nodo* tmp = l3.act;           //peor caso: 1, mejor caso: 0
    while (tmp->sig != NULL)      //peor caso: n, mejor caso: 0
    {
      tmp = tmp->sig;             //peor caso: n - 1, mejor caso: 0
    }

    Nodo* tmp2 = l2.act;          //peor caso: 1, mejor caso: 0
    while (tmp2 != NULL)          //peor caso: n + 1, mejor caso: 0
    {
      Nodo* nuevo = new Nodo;     //peor caso: n, mejor caso: 0
      nuevo->dato = tmp2->dato;   //peor caso: n, mejor caso: 0
      nuevo->sig = NULL;          //peor caso: n, mejor caso: 0
      tmp->sig = nuevo;           //peor caso: n, mejor caso: 0
      tmp = tmp->sig;             //peor caso: n, mejor caso: 0
      tmp2 = tmp2->sig;           //peor caso: n, mejor caso: 0
    }
    return l3;
  }
}

