// Programa de gestion de empleados: Clase de super usuario
// Marco A. Islas Brito
#include <iostream>
#include <string>
using namespace std;

class SuperUser
{
private:
    string user;
    string password = "superPass";

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