#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "logica/Queue.h"
#include "logica/ListaServicios.h"
#include "logica/Stack.h"
#include "dominio/Paciente.h"

using namespace std;

// Función para leer el archivo usando ARITMÉTICA DE PUNTEROS (Sin lógica de duplicados aún)
void cargarPacientesDesdeArchivo(Queue* colaEspera, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'." << endl;
        return;
    }

    string lineaStr;
    int cargados = 0;

    while (getline(archivo, lineaStr)) {
        if (lineaStr.empty()) continue; 

        char buffer[256];
        strcpy(buffer, lineaStr.c_str());

        char* ptr = buffer;    
        char* inicio = buffer; 

        // 1. Extraer ID
        while (*ptr != ';' && *ptr != '\0') ptr++;
        if (*ptr == '\0') continue; 
        *ptr = '\0'; 
        int id = atoi(inicio); 

        // Validación de duplicados usando la Queue
        if (colaEspera->existePaciente(id)) {
            cout << "Aviso: El paciente con ID " << id << " ya existe (Duplicado). Se omitira." << endl;
            continue; 
        }

        // 2. Extraer Nombre
        ptr++; 
        while (*ptr == ' ') ptr++; 
        inicio = ptr; 
        while (*ptr != ';' && *ptr != '\0') ptr++;
        if (*ptr == '\0') continue;
        *ptr = '\0';
        string nombre(inicio);

        // 3. Extraer Edad
        ptr++; 
        while (*ptr == ' ') ptr++; 
        inicio = ptr;
        while (*ptr != ';' && *ptr != '\0') ptr++;
        if (*ptr == '\0') continue;
        *ptr = '\0';
        int edad = atoi(inicio);

        // 4. Extraer Servicio
        ptr++; 
        while (*ptr == ' ') ptr++; 
        inicio = ptr;
        while (*ptr != '\r' && *ptr != '\n' && *ptr != '\0') ptr++; 
        *ptr = '\0';
        string servicio(inicio);

        // --- VALIDACIÓN DE ROBUSTEZ: Comprobar si el servicio es válido ---
        string serviciosValidos[8] = {
            "Urgencias", "Medicina General", "Cardiologia", 
            "Neurologia", "Traumatologia", "Cirugia", 
            "Pediatria", "Hospitalizacion"
        };

        bool servicioValido = false;
        for(int i = 0; i < 8; i++) {
            if(servicio == serviciosValidos[i]) {
                servicioValido = true;
                break;
            }
        }

        if(!servicioValido) {
            cout << "Aviso: El servicio '" << servicio << "' no es valido. Se omitira el paciente ID " << id << "." << endl;
            continue; // Saltamos esta línea si el departamento no existe
        }
        //--------


        Paciente* p = new Paciente(id, nombre, edad, servicio);
        colaEspera->insertar(p);
        cargados++;
    }
    
    archivo.close();
    cout << "Se cargaron " << cargados << " pacientes desde el archivo.\n" << endl;
}

int main() {
    Queue* colaEspera = new Queue();
    ListaServicios* hospital = new ListaServicios();
    Stack* historial = new Stack();
    
    // <-- RUTA CORREGIDA: Apuntamos a la carpeta 'data' que vimos en tu captura
    cargarPacientesDesdeArchivo(colaEspera, "data/pacientes_prueba.txt");

    int opcion;
    do {
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion) {
            case 1: {
                colaEspera->mostrar();
                
                if(!colaEspera->estaVacia()) {
                    int cantidad;
                    cout << "\nIndique la cantidad de pacientes a atender: ";
                    cin >> cantidad;
                    
                    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
                    for(int i = 0; i < cantidad; i++) {
                        if(colaEspera->estaVacia()) {
                            cout << "Ya no hay mas pacientes en la cola." << endl;
                            break; 
                        }
                        
                        Paciente* p = colaEspera->eliminar();
                        
                        cout << "ID: " << p->getId() << "\nNombre: " << p->getNombre() 
                             << "\nEdad: " << p->getEdad() << "\nServicio: " << p->getServicio() << endl;
                        
                        hospital->agregarPaciente(p->getServicio(), p);
                        historial->apilar(p); 
                        
                        cout << "Paciente enviado a " << p->getServicio() << ".\n" << endl;
                    }
                }
                break;
            }
            case 2: {
                hospital->mostrarTodos();
                
                int opcDepto;
                cout << "\nSeleccionar departamento (1-8) o 0 para cancelar: ";
                cin >> opcDepto;
                
                string nombresServicios[] = {"Urgencias", "Medicina General", "Cardiologia", 
                                            "Neurologia", "Traumatologia", "Cirugia", 
                                            "Pediatria", "Hospitalizacion"};
                
                if(opcDepto >= 1 && opcDepto <= 8) {
                    cout << endl;
                    hospital->mostrarServicio(nombresServicios[opcDepto - 1]);
                }
                cout << endl;
                break;
            }
            case 3: {
                historial->mostrar();
                cout << endl;
                break;
            }
            case 4:
                cout << "Hasta luego : D." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl << endl;
        }
    } while (opcion != 4);

    delete colaEspera; 
    delete historial; 
    delete hospital;  
    
    return 0;
}