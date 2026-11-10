#pragma once

#include <vector>

#include "Dispositivo.h"
#include "Pieza.h"
#include "ReporteTurno.h"

namespace calidad {

class CeldaInspeccion {
private:
    std::vector<Dispositivo*> dispositivos_;  // agregación: la celda no es dueña
    ReporteTurno reporte_;                    // composición: vive y muere con la celda

public:
    void agregarDispositivo(Dispositivo* d);
    void iniciarTurno();
    bool procesar(const Pieza& pieza);
    const ReporteTurno& reporte() const;
};

}  // namespace calidad
