#pragma once

namespace calidad {

class Calibrable {
public:
    virtual ~Calibrable() = default;
    virtual bool necesitaCalibracion() const = 0;
    virtual bool calibrar() = 0;
};

}  // namespace calidad