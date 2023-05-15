/*Juan Diego Rojas 8983626*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int p, c, i, adv, j, k;
    char proc;
    cin >> p;
    cin >> c;
    k = 1;
    while(p!=0 && c!=0)
    {
        queue<int> cola, coladv;
        cout << "Case " << k << ":\n";
        for(i = 1; i <= p; i++)
        {
            cola.push(i);
        }

        for(i = 0; i < c; i++)
        {
            cin >> proc;
            if(proc == 'N')
            {
                cout << cola.front() << "\n";
                cola.push(cola.front());
                cola.pop();
            }
            else
            {
                if(proc == 'E')
                {
                    cin >> adv;
                    coladv.push(adv);
                    for(j = 0; j < p; j++)
                    {
                        if(cola.front()==adv)
                        {
                            cola.pop();
                        }
                        else
                        {
                            coladv.push(cola.front());
                            cola.pop();
                        }
                    }
                    for(j = 0; j < p; j++)
                    {
                        cola.push(coladv.front());
                        coladv.pop();
                    }
                
                }
            }
        }
        k++;
        cin >> p;
        cin >> c;
    }
    return 0;
}