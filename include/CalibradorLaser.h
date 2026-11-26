#pragma once
#include "Calibrable.h"
#include "Dispositivo.h"

namespace calidad {

class CalibradorLaser : public Dispositivo, public Calibrable {
private:
    double largoMin_;
    double largoMax_;
    double desfase_;

public:
    CalibradorLaser(const std::string& id, double largoMin, double largoMax, double desfaseFabrica);

    bool necesitaCalibracion() const override;
    bool calibrar() override;

    std::string descripcion() const override;
    bool inspeccionar(const Pieza& pieza) override;
};

}