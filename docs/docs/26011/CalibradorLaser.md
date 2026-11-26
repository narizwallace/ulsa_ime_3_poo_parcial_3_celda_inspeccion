# Documentación de la clase: CalibradorLaser

> Copia este archivo como `docs/26011/CalibradorLaser.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** [Inserta aquí tu nombre]
**Matrícula:** 26011
**Integrante:** [Inserta aquí tu número de integrante]

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

`CalibradorLaser` es un dispositivo de inspección diseñado para medir la longitud de una pieza y determinar si cumple con los límites de tolerancia (`largoMin_` y `largoMax_`). Su propósito principal es servir como un **dispositivo polimórfico** que, además de medir, posee la capacidad de ser calibrado.

**¿Quién usa tu clase y para qué?**

Es utilizado por la clase `CeldaInspeccion` en el método `iniciarTurno()`. La Celda lo usa para aplicar la calibración y corregir el desfase de fábrica, asegurando que las mediciones posteriores sean precisas.

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?**

Hereda de `Dispositivo`, lo que le permite cumplir el contrato básico de todo dispositivo (tener un ID y poder inspeccionar). También hereda de `Calibrable`, lo cual es fundamental ya que representa una **capacidad** y no un dispositivo en sí, permitiendo que la Celda pueda aplicar la calibración a través de *cross-cast*.

**Atributos propios de tu clase y para qué sirve cada uno:**

*   `largoMin_`: Almacena el límite inferior de longitud permitido para la pieza.
*   `largoMax_`: Almacena el límite superior de longitud permitido para la pieza.
*   `desfase_`: Almacena la desviación de fábrica del dispositivo. Este atributo es mutable; debe ser reseteado a $0.0$ cuando se ejecuta `calibrar()`.

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

*   **`descripcion()`**: Proporciona un nombre legible (`"Calibrador Láser de Longitud"`) para la Celda.
*   **`inspeccionar(const Pieza& pieza)`**: Implementa la lógica de la medición. Primero, calcula el `largoMedido` sumando el `desfase_` al largo real de la pieza. Luego, verifica si este `largoMedido` está dentro del rango $[largoMin\_, largoMax\_]$.
*   **`calibrar()`**: Simplemente establece `desfase_ = 0.0`, indicando que el error de fábrica ha sido corregido.

**¿Qué métodos de tu clase son `const` y por qué?**

Los métodos como `necesitaCalibracion()`, `descripcion()` e `inspeccionar()` son `const` porque consultan el estado de la clase sin modificar sus atributos internos. Esto asegura que el objeto en sí no cambie mientras está siendo evaluado.

**Lo particular de tu clase. Responde solo lo que corresponda a tu clase:**

*   `Bascula` o `CalibradorLaser`: La clase implementa el desfase mediante el atributo `desfase_`. Cuando se instancia, recibe el valor del desfase de fábrica. El método `calibrar()` es el mecanismo que invoca la Celda para forzar este desfase a cero, simulando la corrección en el proceso.

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**

*Verifiqué usando la pieza P-05. Sin calibrar, su longitud medida de 51.0 mm (si el desfase era de 0.3) está fuera de rango y la pieza es rechazada. Al simular la calibración, la medición es 50.7 mm, que está dentro del rango, y la pieza es aceptada.*

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

*Tuve dudas sobre si el desfase debía ser un puntero o un valor directo, pero decidí que un valor directo era suficiente ya que la Calibración solo lo modifica.*

**Errores que encontraste y cómo los corregiste:**

*Inicialmente intenté hacer el desfase una variable estática, pero entendí que debía ser un atributo de la instancia para que cada dispositivo tuviera su propio desfase.*