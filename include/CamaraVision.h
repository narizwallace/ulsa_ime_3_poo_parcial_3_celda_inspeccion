// include/CamaraVision.h
#pragma once
#include "Dispositivo.h"

namespace calidad {

class CamaraVision : public Dispositivo {
public:
    explicit CamaraVision(const std::string& id);

    std::string descripcion() const override;
    bool inspeccionar(const Pieza& pieza) override;
};

}  // namespace calidad