// Experimento 2: destructor virtual vs. no virtual al destruir por puntero base.
// Programa independiente: no usa las clases del proyecto.


#include <iostream>
#include "Bascula.h"
#include "Dispositivo.h"

using namespace calidad;

int main() {
    std::cout << "=== Experimento 1: Memoria y vptr ===\n";
    std::cout << "sizeof(std::string): " << sizeof(std::string) << " bytes\n";
    std::cout << "sizeof(Dispositivo): " << sizeof(Dispositivo) << " bytes (contiene id_ + vptr oculto)\n";
    std::cout << "sizeof(Bascula):     " << sizeof(Bascula)     << " bytes (base + atributos propios)\n";
    return 0;
}