// Programa de gestion de empleados: Clase de empleado
// Marco A. Islas Brito
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    string id;
    double salary;

public:
    void setName(string n)
    {
        name = n;
    }
    void setId(string m)
    {
        id = m;
    }
    void setSalary(double s)
    {
        salary = s;
    }

    string getName()
    {
        return name;
    }
    string getId()
    {
        return id;
    }
    double getSalary()
    {
        return salary;
    }
};