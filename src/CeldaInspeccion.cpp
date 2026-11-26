#include "CeldaInspeccion.h"
#include <iostream>
#include "Calibrable.h"

namespace calidad {

void CeldaInspeccion::iniciarTurno() {
    std::cout << "=== Inicio de turno ===\n";
    for (Dispositivo* d : dispositivos_) {
        // Cross-cast en tiempo de ejecucion: verifica si d hereda de Calibrable
        if (Calibrable* c = dynamic_cast<Calibrable*>(d)) {
            std::cout << "Calibrando " << d->id() << " (" << d->descripcion() << ") ... "
                      << (c->calibrar() ? "OK" : "FALLA") << '\n';
        }
    }
}

void CeldaInspeccion::agregarDispositivo(Dispositivo* d) {
    if (d != nullptr) {
        dispositivos_.push_back(d);
    }
}

bool CeldaInspeccion::procesar(const Pieza& pieza) {
    bool aceptada = true;

    for (Dispositivo* d : dispositivos_) {
        if (!d->inspeccionar(pieza)) {
            aceptada = false;
        }
    }

    reporte_.registrarPieza(aceptada);
    return aceptada;
}

const ReporteTurno& CeldaInspeccion::reporte() const {
    return reporte_;
}

}  // namespace calidad