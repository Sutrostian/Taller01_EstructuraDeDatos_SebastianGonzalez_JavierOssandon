#include "logica/Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {

    //inicializar start en nullptr
    start = nullptr;
}

void Queue::insertar(Paciente* p) {
    // crear un NodoQueue nuevo
    // si start es nullptr, el nuevo nodo pasa a ser start
    // si no, recorrer desde start hasta encontrar el ultimo nodo (next == nullptr)
    // y conectar ese ultimo nodo con el nuevo
    //aqui implementare para insertar un paciente en la cola:

    // 1. Creamos el nuevo nodo queue y le asignamos el paciente
    NodoQueue* nuevo = new NodoQueue();
    nuevo->paciente = p;
    nuevo->next = nullptr;

    // 2. Si la cola está vacía, el nuevo nodo es el inicio
    if (estaVacia()) {
        start = nuevo;
    } else {
        // 3. Si no, recorremos hasta el final para agregarlo al último (FIFO)
        NodoQueue* aux = start;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = nuevo;
    }
}


Paciente* Queue::eliminar() {
    //sacar el nodo del frente, retornar su paciente y liberar el nodo
    //debe retornar nullptr si la cola está vacía
    if(estaVacia()) {
        return nullptr;
    } else {
        NodoQueue* aux = start;
        Paciente* pacienteEliminado = aux->paciente;
        start = start->next; // mover el inicio al siguiente nodo
        delete aux; // liberar memoria del nodo eliminado
        return pacienteEliminado; // retornar el paciente eliminado
    }
}

bool Queue::estaVacia() {
    //retornar true si start es nullptr
    if (start == nullptr) {
        return true;
    }
    return false;
}

void Queue::mostrar() {
    //recorrer la cola desde start e imprimir cada paciente

    if (estaVacia()) {
        cout << "La cola de espera esta vacia." << endl;
        return;
    }

    NodoQueue* aux = start;
    int posicion = 1;
    cout << "PACIENTES EN ESPERA" << endl;
    while (aux != nullptr) {
        cout << posicion << ". " << aux->paciente->getId() << " - " 
             << aux->paciente->getNombre() << endl;
        
        aux = aux->next;
        posicion++;
    }

}

bool Queue::existePaciente(int idBuscado) {
    NodoQueue* actual = start; // Usamos 'start' que es el puntero de tu clase
    while (actual != nullptr) {
        // Accedemos directo a 'paciente' y 'next' tal como lo haces en tu método mostrar()
        if (actual->paciente->getId() == idBuscado) {
            return true; // ¡Ya está en la cola! Es duplicado.
        }
        actual = actual->next;
    }
    return false; // No está duplicado
}

Queue::~Queue() {
    //liberar todos los nodos restantes para evitar fugas de memoria
 
    while (!estaVacia()) {
        NodoQueue* aux = start;
        delete aux->paciente;
        start = start->next;
        delete aux;
    }

}

Paciente* Queue::buscarPorId(int idBuscado) {
    NodoQueue* actual = start;
    while (actual != nullptr) {
        if (actual->paciente->getId() == idBuscado) {
            return actual->paciente;
        }
        actual = actual->next;
    }
    return nullptr; // no se encontro
}

