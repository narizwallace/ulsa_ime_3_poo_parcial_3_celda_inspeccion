// src/CamaraVision.cpp
#include "CamaraVision.h"

namespace calidad {

CamaraVision::CamaraVision(const std::string& id) : Dispositivo(id) {}

std::string CamaraVision::descripcion() const { return "Cámara de Visión Artificial"; }

bool CamaraVision::inspeccionar(const Pieza& pieza) {
    return (pieza.defectos() == 0);
}

}  // namespace calidad