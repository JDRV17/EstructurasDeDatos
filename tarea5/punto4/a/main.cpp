#include "lista.h"
#include <iostream>

/*Cálculo de la complejidad: O(n^2)
Debido a la complejidad de longLista y anxLista. Como longLista recorre los n elementos que tenga la lista, su complejidad es O(n), lo
que hace que la variable size equivalga a n, y por tanto el ciclo while se ejecutará n+1 veces, y todo lo que hay dentro, n veces. Dentro
del ciclo, la línea 15 tiene una complejidad de n^2, el primer n por la complejidad misma de la función anxLista(), y la otra n de la
cantidad de veces que se repite el ciclo. El resto de líneas dentro del ciclo se recorren n veces.*/
Lista concatenarListas(Lista l1, Lista l2)
{
    int i = 1;                          //1
    int size = l2.longLista();          //n, por la complejidad de longLista()
    while (i <= size)                   //n + 1
    {
        l1.anxLista(l2.infoLista(i));   //n^2, por la complejidad de longLista() multiplicada por la de anxLista()
        i++;                            //n
    }
    return l1;
}

int main()
{
    int i = 1;
    Lista l1, l2;
    l1.anxLista(5);
    l1.anxLista(10);
    l1.anxLista(12);
    l1.anxLista(13);
    l1.anxLista(15);
    l1.anxLista(20);
    
    l2.anxLista(4);
    l2.anxLista(9);
    l2.anxLista(11);
    l2.anxLista(12);
    l2.anxLista(14);
    l2.anxLista(19);
    Lista newlista = concatenarListas(l1, l2);
    cout << "La dos listas concatenadas serían: ";
    while (i <= newlista.longLista())
    {
        printf("%d ", (int)newlista.infoLista(i));
        i++;
    }
}