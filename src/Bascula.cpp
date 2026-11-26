#include "Bascula.h"

namespace calidad {

Bascula::Bascula(const std::string& id, double pesoMin, double pesoMax, double desfaseFabrica)
    : Dispositivo(id), pesoMin_(pesoMin), pesoMax_(pesoMax), desfase_(desfaseFabrica) {}

bool Bascula::necesitaCalibracion() const { return desfase_ != 0.0; }

bool Bascula::calibrar() {
    desfase_ = 0.0;
    return true;
}
std::string Bascula::descripcion() const { return "Báscula de Inspección de Peso"; }

bool Bascula::inspeccionar(const Pieza& pieza) {
    double pesoMedido = pieza.peso() + desfase_;
    return (pesoMedido >= pesoMin_ && pesoMedido <= pesoMax_);
}

}  