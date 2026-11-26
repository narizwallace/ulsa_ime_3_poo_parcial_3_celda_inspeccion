#include "ReporteTurno.h"

namespace calidad {

void ReporteTurno::registrarPieza(bool fueAceptada) {
    inspeccionadas_++;
    if (fueAceptada) {
        aceptadas_++;
    } else {
        rechazadas_++;
    }
}

}  // namespace calidad