#pragma once

#include <string>
#include "Pieza.h"

namespace calidad {

class Dispositivo {
private:
    std::string id_;

public:
    explicit Dispositivo(const std::string& id) : id_(id) {}
    virtual ~Dispositivo() = default;

    const std::string& id() const { return id_; }

    virtual std::string descripcion() const = 0;
    virtual bool inspeccionar(const Pieza& pieza) = 0;
};

}  // namespace calidad