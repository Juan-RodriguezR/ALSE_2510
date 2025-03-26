#include <iostream>
#include "estudiante.h"
#include "persona.h"
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "Uso: " << argv[0] << " <archivo de datos>" << endl;
        return 1;
    }
    list<Estudiante> estudiantes;
    double promedio_curso = 0.0;

    // Se leeerá de un archivo en donde en cada línea se tiene el nombre, apellido, documento de identidad y código del estudiante
    // Se leerán las notas de cada estudiante y se calculará el promedio del curso
    ifstream archivo(argv[1]);
    string nombre, apellido;
    int docid, codigo;
    double nota[5];
    while (archivo >> codigo >> nombre >> apellido >> docid >> nota[0] >> nota[1] >> nota[2] >> nota[3] >> nota[4])
    {
<<<<<<< HEAD
        // Poner aquí el código para crear un objeto de la clase Estudiante y agregarlo al vector estudiantes
        Persona p(nombre, apellido, docid);
        Estudiante e(nombre, apellido, docid, codigo);
        for (int i = 0; i < sizeof(nota) / sizeof(nota[0]); i++)
        {
            e.agregarNota(nota[i]);
        }
=======
      // Poner aquí el código para crear un objeto de la clase Estudiante y agregarlo al vector estudiantes
        Estudiante e(nombre, apellido, docid, codigo);
        for(int i=0; i< 5; i++)
        {
            e.agregarNota(nota[i]);
            //cout << nota[i] << " ";
        }
        //e.Promedio();
        
>>>>>>> 92913224fcc1aa6374b924a940d89c821358a582
        estudiantes.push_back(e);
    }
    archivo.close();

    cout << "No. de estudiantes cargados: " << estudiantes.size() << endl;
<<<<<<< HEAD

    vector<Estudiante>::iterator it;
    for (it = estudiantes.begin(); it != estudiantes.end(); it++)
=======
    
    
    
    estudiantes.sort();

    cout << "El estudiante con menor promedio es: " << (*estudiantes.begin()) << endl;
    cout << "El estudiante con mayor promedio es: " << estudiantes.back() << endl;
    
    list<Estudiante>::iterator it;
    for(it = estudiantes.begin(); it != estudiantes.end(); it++)
>>>>>>> 92913224fcc1aa6374b924a940d89c821358a582
    {
        promedio_curso += it->Promedio();
        cout << (*it) << endl;
    }
<<<<<<< HEAD
    cout << "Promedio del curso: " << promedio_curso / estudiantes.size() << endl;

=======
    cout << "Promedio del curso: " << promedio_curso / estudiantes.size() << endl;  
    
>>>>>>> 92913224fcc1aa6374b924a940d89c821358a582
    return 0;
}