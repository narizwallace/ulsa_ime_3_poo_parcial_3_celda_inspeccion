#include "Pieza.h"

namespace calidad {

Pieza::Pieza(const std::string& id, double peso, double largo,
             double temperatura, int defectos, double dureza)
    : id_(id), peso_(peso), largo_(largo), temperatura_(temperatura),
      defectos_(defectos), dureza_(dureza) {}

std::ostream& operator<<(std::ostream& os, const Pieza& p) {
    os << "Pieza " << p.id_;
    return os;
}

}  // namespace calidad
