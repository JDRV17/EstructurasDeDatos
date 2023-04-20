#include "lista.h"
#include <iostream>

/*Cálculo de la complejidad: O(n)
Debido a la complejidad de longLista y anxLista. Como longLista recorre los n elementos que tenga la lista, su complejidad es O(n), lo
que hace que la variable size equivalga a n, y por tanto el ciclo while se ejecutará n+1 veces, y todo lo que hay dentro, n veces. En 
cada ciclo,lo que está dentro del bloque if se ejecuta un máximo de una vez, siendo que vel sea menor que el elemento de l en la 
posición i. La línea 21 funciona como un break, y hace que termine el ciclo, pero no ingrese más a él. Si v no es menor que ningún 
elemento de l, el tamaño de l no habrá cambiado y será igual a size, y por ello se anexará a la lista l, (es decir, insertar al final)
el elemento vel, esta vez dependiendo de la complejidad de anxLista, que también recorre toda la lista.*/
Lista insertarEnListaOrdenada(Lista l, int v)
{
    Elemento vel = v;               //1
    int i = 1;                      //1
    int size = l.longLista();       //n, por la complejidad de longLista()
    while (i <= size)               //n + 1
    {
        if (vel < l.infoLista(i))   //n
        {
            l.insLista(vel, i);     //peor caso: 1, mejor caso: 0 
            i = l.longLista()+1;    //peor caso: 1, mejor caso: 0 (esta línea funciona como un break, pero como están prohibidos en clase, toca hacer esto. Es gracias a ella que esta y la línea anterior solo se pueden repetir máximo una vez)
        }
        i++;                        //peor caso: n, mejor caso: 1
    }
    if (size == l.longLista())      //n, por la complejidad de longLista()
    {
        l.anxLista(vel);            //n, por la complejidad de anxLista()
    }
    return l;       
}

int main()
{
    int i = 1;
    Lista l;
    l.anxLista(5);
    l.anxLista(10);
    l.anxLista(12);
    l.anxLista(13);
    l.anxLista(15);
    l.anxLista(20);
    int v = 25;
    Lista newlista = insertarEnListaOrdenada(l, v);
    cout << "La lista con el nuevo elemento insertado es: ";
    while (i <= newlista.longLista())
    {
        printf("%d ", (int)newlista.infoLista(i));
        i++;
    }
}