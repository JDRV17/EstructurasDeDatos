#include "lista.h"
#include <iostream>

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
    l2.anxLista(110);
    l2.anxLista(12);
    l2.anxLista(14);
    l2.anxLista(19);
    Lista newlista = l1 + l2;
    cout << "La dos listas concatenadas serían: ";
    while (i <= newlista.longLista())
    {
        printf("%d ", (int)newlista.infoLista(i));
        i++;
    }
}