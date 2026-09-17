#pragma once
#include <string>
using namespace std;

class Persona {
protected:
    int id;
    string nombre;
    int edad;

public:
    Persona(int id, string nombre, int edad);
    virtual ~Persona(); //para que borre bien un Paciente aunque lo tenga como Persona*
};