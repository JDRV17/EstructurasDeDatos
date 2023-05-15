/*Juan Diego Rojas 8983626*/
#include <iostream>
#include <list>

using namespace std;

int main() {
    string input;
    int i, size;
    
    while (cin >> input) 
    {
        list<char> beiju;
        list<char>::iterator it = beiju.begin();  
        size = input.size();
        for (i = 0; i < size; i++) 
        {
            if (input[i] == '[') 
            {
                it = beiju.begin();
            } 
            else
            {
                if (input[i] == ']') 
                {
                    it = beiju.end();
                } 
                else 
                {
                    it = beiju.insert(it, input[i]);
                    it++;
                }
            } 
        }
        
        for (char c : beiju) 
        {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}