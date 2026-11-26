#include "CalibradorLaser.h"

namespace calidad {

CalibradorLaser::CalibradorLaser(const std::string& id, double largoMin, double largoMax, double desfaseFabrica)
    : Dispositivo(id), largoMin_(largoMin), largoMax_(largoMax), desfase_(desfaseFabrica) {}

bool CalibradorLaser::necesitaCalibracion() const { return desfase_ != 0.0; }

bool CalibradorLaser::calibrar() {
    desfase_ = 0.0;
    return true;
}

std::string CalibradorLaser::descripcion() const { return "Calibrador Láser de Longitud"; }

bool CalibradorLaser::inspeccionar(const Pieza& pieza) {
    double largoMedido = pieza.largo() + desfase_;
    return (largoMedido >= largoMin_ && largoMedido <= largoMax_);
}

}