#include "logica/ListaServicios.h"
#include <iostream>
using namespace std;

ListaServicios::ListaServicios() {
    //crear los 8 nodos fijos de servicios (Urgencias, Medicina General, Cardiologia, Neurologia, Traumatologia, Cirugia, Pediatria, Hospitalizacion) 
    // y encadenarlos entre si, dejando 'inicio' apuntando al primero
}

NodoServicio* ListaServicios::buscarServicio(string nombreServicio) {
    //recorrer la lista desde 'inicio' comparando nombres
    // retornar el nodo si lo encuentra, o nullptr si no existe ese servicio
    return nullptr;
}

void ListaServicios::agregarPaciente(string nombreServicio, Paciente* p) {
    // usar buscarServicio() para ubicar el nodo del servicio
    // crear un NodoPacienteServicio nuevo y agregarlo a su lista de pacientes
}

void ListaServicios::mostrarServicio(string nombreServicio) {
    // usar buscarServicio(), recorrer su lista de pacientes e imprimir cada uno
}

void ListaServicios::mostrarTodos() {
    // recorrer la lista principal de servicios,
    // mostrando el nombre y cuantos pacientes tiene cada uno
}

ListaServicios::~ListaServicios() {
    // liberar TODOS los nodos: primero los pacientes de cada servicio,
    // luego los nodos de servicio en si
}