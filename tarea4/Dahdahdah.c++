#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int number, i;
    cin >> number;
    cin.ignore();
    i = 0;
    char* substrings;
    char mensaje[1000];
    char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','.',',','?','\'','!','/','(',')','&',':',';','=','+','-','_','"','@',' '};
    string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."," "};
    
    while (i < number)
    {
        cin.getline(mensaje,1000);
        substrings = strtok(mensaje, " ");
        cout << "Message #" << i+1 << "\n";
        
        
        while (substrings != NULL)
        {
            for (int j = 0; j < 54; j++)
            {
                if (strcmp(substrings, morse[j].c_str()) == 0)
                {
                    cout << letters[j];
                    j=54;
                }
                if (strcmp(substrings, " ") == 0)
                {
                    cout << " ";
                    j=54;
                }
            }
            substrings = strtok(NULL, " ");
        }
        ++i;
        cout << "\n";
    }
    return 0;
}