#include "lista.h"

Lista::Lista(){
  act = NULL;
}

/*Cálculo de la complejidad: O(n)
Debido a la complejidad de longLista. Como casi todo el código está encerrado en un condicional (simple o anidado), todo puede ser
de a peor o mejor caso. En cualquier circunstancia, el mejor caso de lo que esté dentro de un bloque condicional será 0, que implicaría
que no se cumplió esa condición sino otra. De lo contrario, se recorrerá cada línea una vez, hasta que se llegue al ciclo while, que 
se recorre n + 1 veces por la complejidad de longLista(), y todo lo que está dentro de él, se recorrerá n veces.*/
void Lista::insListaOrdenada(Elemento elem){
  Nodo* tmp;                                                //1
  Nodo* nuevo = new Nodo;                                   //1
  nuevo->dato = elem;                                       //1
  nuevo->sig = NULL;                                        //1
  int i = 1;                                                //1

  if(act == NULL)                                           //1
    act = nuevo;                                            //peor caso: 1, mejor caso: 0
  else                                                      //1                                                      
  {                             
    if(infoLista(1) > elem)                                 //peor caso: 1, mejor caso: 0
    {   
      nuevo->sig = act;                                     //peor caso: 1, mejor caso: 0
      act = nuevo;                                          //peor caso: 1, mejor caso: 0
    }
    else                                                    //peor caso: 1, mejor caso: 0
    {
      tmp = act;                                            //peor caso: 1, mejor caso: 0
      while (elem > infoLista(i) && i < longLista())        //peor caso: n + 1, mejor caso: 0
      {
        tmp = tmp->sig;                                     //peor caso: n, mejor caso: 0
        i++;                                                //peor caso: n, mejor caso: 0
      }
      nuevo->sig = tmp->sig;                                //peor caso: 1, mejor caso: 0
      tmp->sig = nuevo;                                     //peor caso: 1, mejor caso: 0
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

