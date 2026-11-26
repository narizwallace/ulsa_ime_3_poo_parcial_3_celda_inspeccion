# Documentación de la clase: [CamaraVision]

> Copia este archivo como `docs/<matrícula>/<Clase>.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** Michelle González Barrera
**Matrícula:** 25069
**Integrante:** 4

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

Representa un dispositivo de inspección por visión artificial dentro de la celda robótica de calidad. Se encarga de inspeccionar la superficie visual de cada pieza evaluando la cantidad de defectos registrados (pieza.defectos()). Una pieza se considera aceptada por este sensor únicamente si no presenta ningún defecto visible (defectos == 0).

**¿Quién usa tu clase y para qué?**

Es utilizada por la clase CeldaInspeccion. La celda almacena la cámara mediante agregación como un puntero polimórfico (Dispositivo*) en su lista de dispositivos. Durante la fase de operación del turno, CeldaInspeccion invoca a camara.inspeccionar(pieza) dentro de su bucle de procesamiento para determinar si la pieza aprueba el control de calidad visual.

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** (Si es `ReporteTurno`, explica por qué no hereda de `Dispositivo`.)

Hereda públicamente únicamente de la clase base abstracta Dispositivo (public Dispositivo).
Por qué hereda de Dispositivo: Cumple con la relación "ES-UN" (IS-A), garantizando que la cámara implemente la interfaz común (descripcion() e inspeccionar()) para ser tratada de forma polimórfica por la celda.

**Atributos propios de tu clase y para qué sirve cada uno:**

CamaraVision no requiere atributos privados propios. Solo utiliza el atributo id_ heredado de la clase base Dispositivo, el cual se inicializa pasándole el identificador al constructor base (por ejemplo, "C-01").

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

Se sobrescriben los dos métodos virtuales puros de Dispositivo:
std::string descripcion() const override;: Retorna el texto "Cámara de Visión Artificial".
bool inspeccionar(const Pieza& pieza) override;: Implementa la regla de inspección evaluando si pieza.defectos() == 0. Retorna true si la pieza no tiene defectos y false en caso contrario.

**¿Qué métodos de tu clase son `const` y por qué?**

Ambos métodos (descripcion() e inspeccionar()) están marcados como const. Se declararon así aplicando el principio de const-correctness, ya que consultar la descripción del sensor o inspeccionar los atributos de una pieza son operaciones de solo lectura que no deben modificar el estado interno del objeto CamaraVision.

**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

Para lograrlo, la clase se diseñó respetando el polimorfismo de subtipado:
Se derivó de Dispositivo e implementó sus métodos virtuales puros (descripcion e inspeccionar).
La celda interactúa a través de punteros a la base (Dispositivo*), por lo que invoca los métodos usando enlace dinámico (vtable) sin conocer la clase concreta.
Durante la fase de calibración (celda.iniciarTurno()), el intento de cross-cast dynamic_cast<Calibrable*>(d) devuelve nullptr de forma segura para la cámara, permitiendo que la celda continúe su ejecución sin condicionales rígidos (if/else) sobre el tipo de sensor.

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**

Se comprobó ejecutando la simulación completa del turno en main.cpp con las piezas proporcionadas en DatosTurno.cpp (piezasDelTurno()):
Piezas que sirvieron para comprobar el rechazo:
P-06 (tiene defectos = 2): La cámara retornó false, provocando que la pieza fuera marcada correctamente como [ RECHAZADA ].
P-08 (tiene defectos = 1): La cámara retornó false, rechazando la pieza a pesar de que otros sensores estuvieran dentro de rango.
Piezas que sirvieron para comprobar la aceptación:
Piezas como P-01, P-02, P-04, P-05 y P-10 (todas con defectos = 0): La cámara retornó true, permitiendo su aprobación en el control visual.

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Duda sobre Calibrable: Se tuvo la duda inicial de si CamaraVision debía implementar Calibrable. Al revisar la tabla de requisitos, se confirmó que solo la báscula y el láser tienen desfases de fábrica, por lo que se omitió Calibrable para dejar que dynamic_cast gestionara la distinción.
Duda sobre la interfaz de Pieza: Se revisó Pieza.h para confirmar si el método se llamaba tieneDefectos() o defectos(). Al comprobar que el header define int defectos() const, se ajustó la condición de inspección a pieza.defectos() == 0.

**Errores que encontraste y cómo los corregiste:**

Error de ejecución en PowerShell (CommandNotFoundException): Al intentar correr el ejecutable como celda_inspeccion.exe, PowerShell bloqueó el comando por no especificar la ruta actual. Se corrigió anteponiendo .\celda_inspeccion.exe.
Error de compilación en ReporteTurno.h: Se presentó un error de sintaxis que desalineó la declaración de class ReporteTurno. Se corrigió asegurando la sintaxis limpia del encabezado dentro de namespace calidad.
