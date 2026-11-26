#include <iostream>
#include <vector>

#include "CeldaInspeccion.h"
#include "DatosTurno.h"
#include "Pieza.h"
#include "Bascula.h"
#include "CalibradorLaser.h"
#include "CamaraVision.h"
#include "SensorTemperatura.h"

using namespace calidad;

int main() {
    std::cout << "====================================================\n";
    std::cout << "  CELDA ROBOTICA DE INSPECCION DE CALIDAD - PARCIAL 3\n";
    std::cout << "====================================================\n\n";

    // 1. Instanciación de dispositivos con tolerancias según piezasDelTurno()
    Bascula bascula("B-01", 10.0, 16.0, 2.0);          // Desfase inicial = +2.0 kg
    CalibradorLaser laser("L-01", 49.8, 50.8, -1.5);   // Desfase inicial = -1.5 mm
    CamaraVision camara("C-01");
    SensorTemperatura temp("T-01", 30.0);               // Máximo 30.0 °C

    // 2. Configurar Celda (Agregación)
    CeldaInspeccion celda;
    celda.agregarDispositivo(&bascula);
    celda.agregarDispositivo(&laser);
    celda.agregarDispositivo(&camara);
    celda.agregarDispositivo(&temp);

    // 3. Fase Pre-Turno: Calibración vía dynamic_cast
    celda.iniciarTurno();

    // 4. Cargar lote real desde DatosTurno.cpp
    std::vector<Pieza> lote = piezasDelTurno();

    // 5. Procesar inspecciones
    std::cout << "\n=== Procesando Piezas del Turno (" << lote.size() << " piezas) ===\n";
    for (const Pieza& p : lote) {
        bool aceptada = celda.procesar(p);
        std::cout << p 
                  << " | Peso: " << p.peso() << "kg"
                  << " | Largo: " << p.largo() << "mm"
                  << " | Temp: " << p.temperatura() << "C"
                  << " | Defectos: " << p.defectos()
                  << " -> " << (aceptada ? "[ ACEPTADA ]" : "[ RECHAZADA ]") 
                  << '\n';
    }

    // 6. Reporte Final
    const ReporteTurno& reporte = celda.reporte();
    std::cout << "\n====================================================\n";
    std::cout << "               REPORTE FINAL DEL TURNO               \n";
    std::cout << "====================================================\n";
    std::cout << " Total Piezas Inspeccionadas : " << reporte.inspeccionadas() << '\n';
    std::cout << " Total Piezas Aceptadas      : " << reporte.aceptadas() << '\n';
    std::cout << " Total Piezas Rechazadas     : " << reporte.rechazadas() << '\n';
    std::cout << "====================================================\n";

    return 0;
}