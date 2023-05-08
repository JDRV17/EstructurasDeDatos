#include "lista.h"
#include "colaPrioridad.h"
#include <iostream>
/*Samuel Rueda, Juan Diego Rojas*/
int main()
{
    int i = 1;
    colaPrioridad c;
    c.enqueue(0);
    c.enqueue(59);
    c.enqueue(10);
    c.enqueue(46);
    c.enqueue(15);
    c.enqueue(2);
    c.enqueue(12);
    c.enqueue(5);
    c.enqueue(1);
    c.enqueue(28);
    c.enqueue(85);
    c.enqueue(26);
    c.enqueue(12);
    cout << "Los números de la cola de menor a mayor son: \n";
    while (!c.vaciaCola())
    {
        cout << c.front() << " ";
        c.deque();
    }
}
