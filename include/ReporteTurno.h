#pragma once

namespace calidad {

class ReporteTurno {
private:
    int inspeccionadas_ = 0;
    int aceptadas_ = 0;
    int rechazadas_ = 0;

public:
    void registrarPieza(bool fueAceptada);

    int inspeccionadas() const { return inspeccionadas_; }
    int aceptadas() const { return aceptadas_; }
    int rechazadas() const { return rechazadas_; }
};

}  // namespace calidad