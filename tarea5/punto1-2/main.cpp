#include "lista.h"
#include <iostream>
/*Cálculo de la complejidad: O(n)
Debido a la complejidad de longLista. Como longLista recorre los n elementos que tenga la lista, su complejidad es O(n), lo que hace
que la variable size equivalga a n, y por tanto el ciclo while se ejecutará n+1 veces, y todo lo que hay dentro, n veces. En cada ciclo,
lo que está dentro del bloque if se ejecuta un máximo de una vez, sumando un total de n posibles veces, en el peor de los casos, siendo
que el elemento de la lista en la posición i es menor que v, de lo contrario no se ejecuta.*/
Lista obtenerMenores(Lista l, int v)
{
    int i, size;
    Lista menores;                                  //1
    i = 1;                                          //1
    size = l.longLista();                           //n, por la complejidad de longLista()
    while(i <= size)                                //n + 1
    {
        if (l.infoLista(i) < v)                     //n
        {
            menores.anxLista(l.infoLista(i));       //peor caso: n, mejor caso: 0
        } 
        ++i;                                        //n
    }
    return menores;
}

/*Cálculo de la complejidad: O(n)
Debido a la complejidad de longLista. Como longLista recorre los n elementos que tenga la lista, su complejidad es O(n), lo que hace
que la variable size equivalga a n, y por tanto el ciclo while se ejecutará n+1 veces, y todo lo que hay dentro, n veces. En cada ciclo,
lo que está dentro del bloque if se ejecuta un máximo de una vez, siendo que el todos los elementos de la lista son iguales, y son 
iguales a v, de lo contrario, se ejecutará el número de veces que esté v en la lista l.*/
int contarOcurrencias(Lista l, int v)
{
    int i, cont, size;              //1
    cont = 0;                       //1
    i = 1;                          //1
    size = l.longLista();           //n, por la complejidad de longLista()
    while(i <= size)                //n + 1
    {
        if (l.infoLista(i) == v)    //n
        {
            cont++;                 //peor caso: n, mejor caso: 0
        } 
        ++i;                        //n
    }
    return cont;
}

int main()
{
    int i = 1;
    Lista l, menores;
    l.anxLista(5);
    l.anxLista(10);
    l.anxLista(12);
    l.anxLista(15);
    l.anxLista(20);
    l.anxLista(12);
    int v = 12;
    cout << "El número " << v << " se encuentra " << contarOcurrencias(l, v) << " veces en la lista l.\n";
    menores = obtenerMenores(l, v);
    cout << "La lista de números menores que " << v << " presentes en l es: ";
    while (i <= menores.longLista())
    {
        printf("%d ", (int)menores.infoLista(i));
        i++;
    }
}