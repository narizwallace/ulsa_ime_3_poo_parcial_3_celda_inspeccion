#include "DatosTurno.h"

namespace calidad {

std::vector<Pieza> piezasDelTurno() {
    return {
        //     id      peso  largo  temp  defectos dureza
        Pieza("P-01", 12.0, 50.0, 25.0, 0, 52),
        Pieza("P-02", 15.0, 50.0, 24.0, 0, 50),
        Pieza("P-03", 16.2, 50.1, 25.0, 0, 55),
        Pieza("P-04", 12.5, 50.5, 26.0, 0, 48),
        Pieza("P-05", 11.0, 50.7, 25.0, 0, 53),
        Pieza("P-06", 13.0, 50.2, 23.0, 2, 51),
        Pieza("P-07", 12.2, 49.9, 41.0, 0, 50),
        Pieza("P-08",  9.5, 51.0, 25.0, 1, 56),
        Pieza("P-09", 14.8, 50.0, 35.0, 0, 62),
        Pieza("P-10", 10.5, 49.6, 22.0, 0, 44),
        Pieza("P-11", 13.5, 50.3, 19.5, 0, 58),
        Pieza("P-12", 12.8, 49.9, 27.0, 0, 46),
    };
}

}  // namespace calidad
