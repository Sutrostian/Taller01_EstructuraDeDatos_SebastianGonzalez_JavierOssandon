#include "logica/Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    //inicializar start en nullptr
}

void Queue::insertar(Paciente* p) {
    // crear un NodoQueue nuevo
    // si start es nullptr, el nuevo nodo pasa a ser start
    // si no, recorrer desde start hasta encontrar el ultimo nodo (next == nullptr)
    // y conectar ese ultimo nodo con el nuevo
}

Paciente* Queue::eliminar() {
    //sacar el nodo del frente, retornar su paciente y liberar el nodo
    return nullptr;
}

bool Queue::estaVacia() {
    //retornar true si start es nullptr
    return true;
}

void Queue::mostrar() {
    //recorrer la cola desde start e imprimir cada paciente
}

Queue::~Queue() {
    //liberar todos los nodos restantes para evitar fugas de memoria
}