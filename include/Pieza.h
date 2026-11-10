#pragma once

#include <ostream>
#include <string>

namespace calidad {

class Pieza {
private:
    std::string id_;
    double peso_;         // kg
    double largo_;        // mm
    double temperatura_;  // °C
    int defectos_;        // defectos visibles
    double dureza_;       // HRC

public:
    Pieza(const std::string& id, double peso, double largo,
          double temperatura, int defectos, double dureza);

    const std::string& id() const { return id_; }
    double peso() const { return peso_; }
    double largo() const { return largo_; }
    double temperatura() const { return temperatura_; }
    int defectos() const { return defectos_; }
    double dureza() const { return dureza_; }

    friend std::ostream& operator<<(std::ostream& os, const Pieza& p);
};

}  // namespace calidad
