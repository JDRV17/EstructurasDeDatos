/*Juan Diego Rojas 8983626*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n, i, a;
    string stationstr;
    stack<int> start, station, end, endback;
    while (cin >> n && n != 0)
    {
        for(i = 1; i <= n; i++)
        {
            start.push(i);
        }

        while (cin >> a) 
        { 
            end.push(a);
        }
    
        for(i = 0; i < n; i++)
        {
            cout << start.top();
            endback.push(end.top());
            start.pop();
            end.pop();
        }

        for(i = 0; i < n; i++)
        {
            cout << endback.top();
            endback.pop();
        }
    }
    return 0;
}

