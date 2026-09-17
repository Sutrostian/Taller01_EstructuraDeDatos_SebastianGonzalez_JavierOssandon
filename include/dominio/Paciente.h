#pragma once
#include <string>
#include "Persona.h"
using namespace std;

class Paciente : public Persona {
private:
    string servicio;

public:
    Paciente(int id, string nombre, int edad, string servicio);
    ~Paciente();
};