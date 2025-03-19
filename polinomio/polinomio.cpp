#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // Funcion principal
    char nombre[20];
    int grado = 0;
    cout << "Ingresa el polinomio: " << endl;
    cin.getline(nombre, 20, '\n');
    for (int i = 0; nombre[i] != '\0'; i++)
    {
        if (nombre[i] == '^')
        {
            int num = nombre[i + 1] - '0';
            if (num > grado)
            {
                grado = num;
            }
        }
    }
    cout << "El grado del polinomio es: " << grado << endl;
    return 0;
}