#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void eliminarPosicionPila(list<int>& l, stack<int>& pil)
{
    int pos, cont, i = 0;
    stack<int> newpil;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) 
    {
        cont = pil.size();
        pos = *it;
        while (cont > pos - i)
        {
            newpil.push(pil.top());
            pil.pop();
            cont--;
        }
        pil.pop();
        while (!newpil.empty())
        {
            pil.push(newpil.top());
            newpil.pop();
        }
        i++;
    }
}

void ordenarConMonticulo(vector<int>& vec)
{
    make_heap(vec.begin(), vec.end());
}

int verificarOrdenadoCola(queue<int> que)
{
    /*Esta función retorna 1 si la cola está ordenada de menor a mayor, 0 si está ordenada de mayor a menor y -1 si no está en orden.
    Originalmente lo había hacer con booleanos, pero necesitaba retornar -1 en caso de que no estuviera ordenada la cola, y por eso
    lo hice así*/
    int size = que.size();
    int i = 0, pos1, pos2;
    int cont = 0;
    while(i < size-1)
    {
        pos1 = que.front();
        que.pop();
        pos2 = que.front();
        if(pos1 < pos2)
        {
            cont++;
        }
        else if(pos1 > pos2)
        {
            cont--;
        }
        i++;
    }
    if(cont == size-1)
    {
        return 1;
    }
    else if(cont == (size*(-1))+1)
    {
        return 0;
    }
    else{
        return -1;
    }
}

int obtenerMenorCosto(list<int> l)
{
    vector<int> sumas;
    int suma = 0, sumamax = 0, i;
    l.sort();
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) 
    {
        suma = suma + *it;
        sumas.push_back(suma);
    }
    for (i = 0; i < sumas.size(); i++)
    {
        sumamax = sumamax + sumas[i];
    }
    sumamax = sumamax - sumas[0];
    return sumamax;
}

int evaluarExpresion(list<char> l)
{
    //Punto incompleto
    int op = 0;
    std::list<char>::iterator it2;
    vector<int> numbers;
    for (std::list<char>::iterator it = l.begin(); it != l.end(); ++it) 
    {
        if(*it == '(')
        {
            it2 = it;
            while (*it2 != ')')
            {
                if(*it2 == '+')
                {
                    op = op + ((*prev(it2))-48 + (*next(it2))-48);
                }
                if(*it2 == '-')
                {
                    op = op + ((*prev(it2))-48 - ((*next(it2))-48));
                }
                if(*it2 == '*')
                {
                    op = op + (((*prev(it2))-48) * ((*next(it2))-48));
                }
                ++it2;
            }
        }
    }
    return op;
}

int verificarRepetidos(queue<int> col)
{
    vector<int> colvec;
    int i, j, cont = 0, size;
    size = col.size();
    for (i = 0; i < size; i++)
    {
        colvec.push_back(col.front());
        col.pop();
    }
    
    for (i = 0; i < colvec.size(); i++)
    {
        for (j = i + 1; j < colvec.size(); j++)
        {
            if(colvec[i] == colvec[j])
            {
                cont++;
                j = colvec.size();
            }
        }
    }
    return cont;
}

int main()
{
    list<int> l, l1;
    stack<int> pil;
    l.push_back(1);
    l.push_back(3);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    pil.push(1);
    pil.push(2);
    pil.push(3);
    pil.push(4);
    pil.push(5);
    pil.push(6);
    pil.push(7);
    pil.push(8);
    pil.push(9);
    pil.push(10);
    eliminarPosicionPila(l, pil);
    cout << "La pila quedó así: ";
    while(!pil.empty())
    {
        cout << pil.top() << " ";
        pil.pop();
    }
    cout << "\n";
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //ordenarConMonticulo(vec);
    queue<int> que, que1;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    cout << verificarOrdenadoCola(que) << "\n";
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(4);
    l1.push_back(2);
    cout << obtenerMenorCosto(l1) << "\n";
    list<char> l2;
    l2.push_back('(');
    l2.push_back('1');
    l2.push_back('*');
    l2.push_back('2');
    l2.push_back(')');
    cout << evaluarExpresion(l2) << "\n";
    que1.push(1);
    que1.push(2);
    que1.push(3);
    que1.push(2);
    que1.push(5);
    cout << verificarRepetidos(que1) << "\n";
    return 0;
}