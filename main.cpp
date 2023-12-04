// Programa de gestion de empleados
// Marco A. Islas Brito
#include <iostream>
#include <string>
#include "employee.h"
#include "admin.h"
#include "superUsr.h"
using namespace std;

// Creamos el main de nuestro programa
int main()
{
    Admin admin;
    SuperUser superUsr;

    string a;
    int b;
    // Creamos un menu de bienvenida con un sistema sencillo de autenticacion de contrsena
    int failedAttempts = 1;
    cout << "===============================" << endl;
    cout << "BIENVENIDO" << endl;
    cout << "===============================" << endl
         << endl;
    cout << "Por favor introduce la clave de administrador: " << endl;
    cin >> a;

    while (admin.isPasswordCorrect(a) == false && failedAttempts <= 3)
    {
        cout << "Clave incorrecta. Intenta de nuevo: " << endl;
        cin >> a;
        failedAttempts++;
        if (failedAttempts >= 4)
        {
            do
            {
                cout << "Usaste la clave incorrecta demasiadas veces, para desbloquear introduce la clave de super usuario: " << endl;
                cin >> a;
            } while (superUsr.isPasswordCorrect(a) == false);
            a = "adminPass";
        }
    }

    // Definimos el numero maximo de empleados que se van a gestionar y el numero inicial de empleados

    int maxEmployees;
    cout << "Cual es la cantidad maxima de empleados que desea gestionar? \n";
    cin >> maxEmployees;

    int totalEmployees;
    cout << "Con cuantos empleados deseas iniciar el programa? \n";
    cin >> totalEmployees;

    float salarioBase;
    cout << "Introduce el salario base que deseas manejar para tus trabajadores: " << endl;
    cin >> salarioBase;

    cout << endl;

    // Creamos un arreglo de objetos que contiene a nuestros objetos empleado
    Employee employees[maxEmployees];

    // Con un ciclo for hacemos que el usuario introduzca el nombre de todos sus usuarios y sus id
    for (int i = 0; i < totalEmployees; i++)
    {
        cout << "Introduce el nombre del empleado " << i + 1 << endl;
        cin >> a;
        employees[i].setName(a);

        cout << "Introduce la id que deseas asignar al empleado " << i + 1 << endl;
        cin >> a;
        for (int i = 0; i < totalEmployees; i++)
        {
            if (employees[i].getId() == a)
            {
                cout << "Advertencia! Si usas la misma id para 2 o mas empleados las proximas operaciones realizadas con esa id aplicaran para todos los empleados." << endl
                     << "Confirma la Id o introduce una diferente: " << endl;
                cin >> a;
            }
        }
        cout << endl;
        employees[i].setId(a);

        employees[i].setSalary(salarioBase);
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
        cout << "2. Modificar el salario de un empleado" << endl;
        cout << "3. Consultar la informacion de un empleado" << endl;
        cout << "4. Agregar un nuevo empleado" << endl;
        cout << "5. Eliminar un empleado del sistema" << endl;
        cout << "6. Salir" << endl;
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
            for (int i = 0; i < totalEmployees; i++)
            {
                cout << "Empleado " << i + 1 << ".\n";
                cout << "Nombre: " << employees[i].getName() << endl;
                cout << "ID: " << employees[i].getId() << endl;
                cout << "Salario: $" << employees[i].getSalary() << endl
                     << endl;
            }
            break;
        };
        // Modificar salarios
        case 2:
        {
            cout << "===============================" << endl;
            cout << "Asignar o modificar salario." << endl;
            cout << "===============================" << endl
                 << endl;
            cout << "Introduce la id del empleado que desea modificar: " << endl;
            cin >> a;
            for (int i = 0; i < totalEmployees; i++)
            {
                if (employees[i].getId() == a)
                {
                    cout << "Cual quiere que sea el nuevo salario de este empleado? " << endl;
                    cin >> b;
                    employees[i].setSalary(b);
                    cout << "Cambio realizado con exito." << endl;
                }
            }
            break;
        }
        // Consultar datos de empleados puntuales
        case 3:
        {
            cout << "===============================" << endl;
            cout << "Consultar datos de un empleado." << endl;
            cout << "===============================" << endl
                 << endl;
            cout << "Introduce la id del empleado que desea consultar: " << endl;
            cin >> a;
            for (int i = 0; i < totalEmployees; i++)
            {
                if (employees[i].getId() == a)
                {
                    cout << "Empleado " << i + 1 << ".\n";
                    cout << "Nombre: " << employees[i].getName() << endl;
                    cout << "ID: " << employees[i].getId() << endl;
                    cout << "Salario: $" << employees[i].getSalary() << endl
                         << endl;
                }
            }
            break;
        }
        // Agregar empleados nuevos
        case 4:
        {
            cout << "===============================" << endl;
            cout << "Agregar un nuevo empleado." << endl;
            cout << "===============================" << endl
                 << endl;
            totalEmployees++;

            cout << "Introduce el nombre del empleado " << totalEmployees << endl;
            cin >> a;
            employees[totalEmployees - 1].setName(a);

            cout << "Introduce la id que deseas asignar al empleado " << totalEmployees << endl;
            cin >> a;
            for (int i = 0; i < totalEmployees; i++)
            {
                if (employees[i].getId() == a)
                {
                    cout << "Advertencia! Si usas la misma id para 2 o mas empleados las proximas operaciones realizadas con esa id aplicaran para todos los empleados." << endl
                         << "Confirma la Id o introduce una diferente: " << endl;
                    cin >> a;
                }
            }
            cout << endl;
            employees[totalEmployees - 1].setId(a);

            employees[totalEmployees - 1].setSalary(salarioBase);
            break;
        }
        // Eliminar empleados
        case 5:
        {
            cout << "===============================" << endl;
            cout << "Agregar un nuevo empleado." << endl;
            cout << "===============================" << endl
                 << endl;
            cout << "Introduce la Id del empleado que deseas eliminar: " << endl;
            cin >> a;
            for (int i = 0; i < totalEmployees; i++)
            {
                if (employees[i].getId() == a)
                {
                    for (int e = i; e < totalEmployees; e++)
                    {
                        employees[e].setName(employees[e + 1].getName());
                        employees[e].setId(employees[e + 1].getId());
                        employees[e].setSalary(employees[e + 1].getSalary());
                    }
                    totalEmployees--;
                }
            }
            break;
        }
        }
    } while (option != 6);
}