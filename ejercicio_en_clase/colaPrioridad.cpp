//Samuel Rueda, Juan Diego Rojas
#include "colaPrioridad.h"

colaPrioridad::colaPrioridad(){
}

/*Complejidad: O(n)
1 + 1 + n + n + n - 1 + n - 1 = 4n*/
Elemento colaPrioridad::front(){
   int i = 1;                                //1
   Elemento menor = l.infoLista(1);          //1
   int size = l.longLista();                 //n (complejidad de longLista en listas circulares dobles)
   for (i; i <= size - 1; i++)               //n
   {
      if (l.infoLista(i+1) < menor)          //n-1
      {
         menor = l.infoLista(i+1);           //mejor caso: 0; peor caso: n-1
      }
   }
   return menor;
}

/*Complejidad: O(1)
1 = 1*/
void colaPrioridad::enqueue(Elemento e){
   l.anxLista(e);                            //1 (complejidad de anxLista en listas circulares dobles)
}

/*Complejidad: O(n)
1 + 1 + 1 + n + n + 1 + n + n + n - 1 + n - 1 + 1 = 6n + 3*/
void colaPrioridad::deque(){
   int i = 1;                                //1
   int pos = 1;                              //1
   Elemento menor = l.infoLista(1);          //1
   int size = l.longLista();                 //n (complejidad de longLista en listas circulares dobles)
   for (i; i <= size; i++)                   //n + 1
   {        
      if (l.infoLista(i) < menor)            //n
      {
         pos = i;                            //mejor caso: 0; peor caso: n-1 
         menor = l.infoLista(i);             //mejor caso: 0, peor caso: n-1
      }
   }
   l.elimLista(pos);                         //1
}

/*Complejidad: O(1)
1 + 1 + 1 + 1 = 4*/
bool colaPrioridad::vaciaCola(){
  bool ans;                                  //1 
  if(l.vaciaLista())                         //1
     ans = true;                             //mejor caso: 0; peor caso: 1
  else                                       //1
     ans = false;                            //mejor caso: 0; peor caso: 1
  return ans;
}
