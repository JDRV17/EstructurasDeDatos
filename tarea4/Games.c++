/*Juan Diego Rojas
8983626

Complejidad del programa: O(nlog(n)), debido a que el programa implementa la función sort de la libería STL. Primero hay un ciclo
que se encarga de corroborar que el programa se ejecute siempre que el usuario no le asigne 0 como valor a la variable number.
Dentro hay un ciclo for que se encarga de llenar los valores del vector people con lo que ingrese el usuario, y este for se recorre
number veces. Luego ordenamos los datos del vector people, lo que lleva a la complejidad O(nlog(n)), y luego tenemos un condicional
que solo revisa que los datos del centro del vector people no sean iguales. Luego hay un ciclo for que revisa carácter a carácter
las strings de result y comparison (los valores medianos del vector people), y revisa hasta qué punto son iguales. Cuando sean 
diferentes, le sumará 1 al valor del ASCII del carácter en esa posición de la string result, lo que hará que aumente en 1 la letra
(por ejemplo, si era A, queda B). Desafortunadamente ese programa tampoco me dejó subirlo la plataforma, y no entiendo por qué.
Revisando los casos de prueba, todos daban (al menos hasta los que alcancé a revisar), y por más de hacerle pequeñas modificaciones
e intentar subrilo 7 veces a la plataforma, nunca me dejó :(*/ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    string result;
    string comparison;
    cin >> number;
    while (number != 0)
    {
        vector<string> people(number);
        for (int i = 0; i < number; i++)
        {
            cin >> people[i];
        }
        std::sort(people.begin(), people.end());
        
        if (people[(number/2)-1] != people[number/2])
        {
            result = people[(number/2)-1];
            comparison = people [number/2];

            for (int i = 0; i < int(max(result.length(),comparison.length())); i++)
            {
                if (result[i] != comparison[i])
                {

                    result[i]=result[i]+1;
                    if (i < int(result.length()))
                    {
                        result.erase(i+1, (result.length()-(i-1)));
                    }
                }
            }
        }
        else
        {
            result = people[(number/2)-1];
        }

        cout << result << " \n";
        cin >> number;
    }
    return 0;
}