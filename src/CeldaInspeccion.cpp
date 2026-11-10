#include "CeldaInspeccion.h"

#include <iostream>

#include "Calibrable.h"

namespace calidad {

void CeldaInspeccion::iniciarTurno() {
    std::cout << "=== Inicio de turno ===\n";
    for (Dispositivo* d : dispositivos_) {
        // ¿Este dispositivo también es Calibrable? (cross-cast con herencia múltiple)
        if (Calibrable* c = dynamic_cast<Calibrable*>(d)) {
            std::cout << "Calibrando " << d->id() << " (" << d->descripcion() << ") ... "
                      << (c->calibrar() ? "OK" : "FALLA") << '\n';
        }
    }
}

// TODO (equipo): implementen agregarDispositivo(), procesar() y reporte().

}  // namespace calidad
