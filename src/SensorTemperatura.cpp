#include "SensorTemperatura.h"

namespace calidad {

SensorTemperatura::SensorTemperatura(const std::string& id, double tempMax)
    : Dispositivo(id), tempMax_(tempMax) {}

std::string SensorTemperatura::descripcion() const { return "Sensor Térmico Infrarrojo"; }

bool SensorTemperatura::inspeccionar(const Pieza& pieza) {
    return (pieza.temperatura() <= tempMax_);
}

}  // namespace calidad