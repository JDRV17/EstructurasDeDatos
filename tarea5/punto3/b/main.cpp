#include "lista.h"
#include <iostream>

int main()
{
    int i = 1;
    Lista l;
    l.insListaOrdenada(5);
    l.insListaOrdenada(4);
    l.insListaOrdenada(10);
    l.insListaOrdenada(12);
    l.insListaOrdenada(13);
    l.insListaOrdenada(15);
    l.insListaOrdenada(12);
    cout << "La lista es: ";
    while (i <= l.longLista())
    {
        printf("%d ", (int)l.infoLista(i));
        i++;
    }
}