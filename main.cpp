// Programa de gestion de empleados
// Marco A. Islas Brito
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

// Creamos el main de nuestro programa
int main()
{
    // Definimos el numero maximo de empleados que se van a gestionar y el numero inicial de empleados
    string a;
    int b;
    int maxEmployees;
    cout << "Cual es la cantidad maxima de empleados que desea gestionar? \n";
    cin >> maxEmployees;

    int totalEmployees;
    cout << "Con cuantos empleados deseas iniciar el programa? \n";
    cin >> totalEmployees;

    // Creamos un arreglo de objetos que contiene a nuestros objetos empleado
    Employee employees[maxEmployees];

    // Con un ciclo for hacemos que el usuario introduzca el nombre de todos sus usuarios y sus id
    for (int i = 1; i <= totalEmployees; i++)
    {
        cout << "Introduce el nombre del empleado " << i << endl;
        cin >> a;
        employees[i].setName(a);

        cout << "Introduce la id que deseas asignar al empleado " << i << endl;
        cin >> a;
        employees[i].setId(a);

        employees[i].setSalary(0);
    }
    // Creamos un do while para nuestro menu
    int option;
    do
    {
        // Menu
        cout << "===============================" << endl;
        cout << " MENU" << endl;
        cout << "===============================" << endl
             << endl;
        cout << "1. Consultar empleados" << endl;
        cout << "2. Salir" << endl;
        cin >> option;

        // Con un witch accedemos a la opcion del menu que desea el usuario
        switch (option)
        {
        // Consultar empleados
        case 1:
        {
            cout << "===============================" << endl;
            cout << "EMPLEADOS" << endl;
            cout << "===============================" << endl;
            for (int i = 1; i <= totalEmployees; i++)
            {
                cout << "Empleado " << i << ".\n";
                cout << "Nombre: " << employees[i].getName() << endl;
                cout << "ID: " << employees[i].getId() << endl;
                cout << "Salario: $" << employees[i].getSalary() << endl
                     << endl;
            }
            break;
        };
        };
    } while (option != 2);
}