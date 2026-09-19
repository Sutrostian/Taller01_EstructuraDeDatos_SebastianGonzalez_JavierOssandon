#include "logica/Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    //inicializar  en nullptr
}

void Stack::apilar(Paciente* p) {
    // crear un NodoHistorial nuevo
    // el nuevo nodo apunta al top actual (siguiente = top)
    // luego el top pasa a ser el nuevo nodo
}

Paciente* Stack::desapilar() {
    // guardar el paciente del top actual
    // mover la cima al siguiente nodo
    // liberar el nodo viejo y retornar el paciente guardado
    return nullptr;
}

bool Stack::estaVacia() {
    // retornar true si top es nullptr
    return true;
}

void Stack::mostrar() {
    // recorrer desde top hasta el final, imprimiendo cada paciente
    // (naturalmente queda en orden LIFO: el ultimo atendido se muestra primero)
}

Stack::~Stack() {
    // liberar todos los nodos restantes para evitar fugas de memoria
}