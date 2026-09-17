#pragma once
#include "dominio/Paciente.h"

struct NodoQueue {
    Paciente* paciente;
    NodoQueue* next;
};