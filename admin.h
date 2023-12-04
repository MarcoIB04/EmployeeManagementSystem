// Programa de gestion de empleados: Clase de administrador
// Marco A. Islas Brito
#include <iostream>
#include <string>
using namespace std;

class Admin
{
private:
    string user = "Administrador";
    string password = "adminPass";

public:
    bool isPasswordCorrect(string p)
    {
        if (p == password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};