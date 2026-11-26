#pragma once
#include "Dispositivo.h"

namespace calidad {

class SensorTemperatura final : public Dispositivo {
private:
    double tempMax_;

public:
    SensorTemperatura(const std::string& id, double tempMax);

    std::string descripcion() const override;
    bool inspeccionar(const Pieza& pieza) override;
};

}  // namespace calidad