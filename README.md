# Taller 1 Estructura de Datos Hospital Marmaja 

## Descripción
Sistema básico de gestión de pacientes de un hospital, desarrollado utilizando punteros,
aritmética de punteros, programación orientada a objetos, herencia y estructuras de datos. El sistema recibe los pacientes desde un archivo de texto, los procesa
respetando su orden de llegada y los almacena en el servicio correspondiente.

## Integrantes
- Sebastián González - 21.186.016-2 - [Sutrostian](https://github.com/Sutrostian) - Ingeniería Civil Industrial
- Javier Ossandón - 21.979.689-7 - [itsvoiiid](https://github.com/itsvoiiid) - Ingeniería Civil Industrial

## Requisitos previos
- Compilador de C++ compatible con C++17 (g++, recomendado vía MSYS2 en Windows)

## Compilación

```bash
g++ -std=c++17 -Iinclude src/dominio/*.cpp src/main.cpp -o Taller.exe
```

## Ejecución

```bash
./Taller.exe
```

## Estructura del proyecto
```
├── include/
│   ├── dominio/     → archivos de cabecera (.h): Persona.h, Paciente.h
│   └── logica/      → archivos de cabecera (.h): NodoQueue.h, Queue.h
├── src/
│   ├── dominio/     → implementación (.cpp): Persona.cpp, Paciente.cpp
│   ├── logica/      → implementación (.cpp): Queue.cpp
│   └── main.cpp     → punto de entrada del programa
├── data/            → archivo de texto de prueba (pacientes_prueba.txt)
├── .gitignore
└── README.md
```

## Jerarquía de clases (POO)
- **Persona** (clase padre): atributos `id`, `nombre`, `edad`
- **Paciente** (clase hija): agrega el atributo `servicio`

## Funcionalidades
- [x] Jerarquía de clases Persona/Paciente
- Muchas Más Funcionalidades Pronto...

## Formato del archivo de entrada
```
ID;Nombre;Edad;Servicio
```

Ejemplo:
```
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
```

## Servicios disponibles
Urgencias, Medicina General, Cardiología, Neurología, Traumatología, Cirugía, Pediatría, Hospitalización
