#pragma once
#include "Calibrable.h"
#include "Dispositivo.h"

namespace calidad {

class Bascula : public Dispositivo, public Calibrable {
private:
    double pesoMin_;
    double pesoMax_;
    double desfase_;

public:
Bascula(const std::string& id, double pesoMin, double pesoMax, double desfaseFabrica);

    bool necesitaCalibracion() const override;
    bool calibrar() override;

    std::string descripcion() const override;
    bool inspeccionar(const Pieza& pieza) override;
};

} 