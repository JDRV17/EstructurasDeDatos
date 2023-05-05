//Samuel Rueda, Juan Diego Rojas
#include "colaPrioridad.h"

colaPrioridad::colaPrioridad(){
}

Elemento colaPrioridad::front(){
   int i = 0;
   Elemento menor = l.infoLista(1);
   for (i; i < l.longLista() - 2; i++)
   {
      if (l.infoLista(i+2) < menor)
      {
         menor = l.infoLista(i+2);
      }
   }
   return menor;
}

void colaPrioridad::enqueue(Elemento e){
   l.anxLista(e);
}

void colaPrioridad::deque(){
   int i = 1;
   int pos = 1;
   Elemento menor = l.infoLista(1);
   for (i; i <= l.longLista(); i++)
   {
      if (l.infoLista(i) < menor)
      {
         pos = i;
         menor = l.infoLista(i);
      }
   }
   l.elimLista(pos);
}

bool colaPrioridad::vaciaCola(){
  bool ans;
  if(l.vaciaLista())
     ans = true;
  else
     ans = false;
  return ans;
}
