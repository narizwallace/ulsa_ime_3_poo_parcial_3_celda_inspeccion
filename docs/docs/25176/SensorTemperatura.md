# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<matrícula>/<Clase>.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** [Dannia Ximena Plata Palos]
**Matrícula:** [25176]
**Integrante:** [3]

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

[Esta clase representa el sensor de temperatura de la celda de inspección (su id es T-01). De cada pieza revisa solamente una cosa, su temperatura. La pieza pasa si su temperatura está dentro del rango permitido, fuera de ese rango el sensor la rechaza.]

**¿Quién usa tu clase y para qué?**

[La usa la celda de inspección, que trabaja con dispositivos de forma general. La celda llama a inspeccionar() con cada pieza del turno para saber si cumple el límite de temperatura y a descripcion() para identificar al sensor en reportes o mensajes.]

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** (Si es `ReporteTurno`, explica por qué no hereda de `Dispositivo`.)

[Hereda solo de Dispositivo,lo hice así porque un sensor de temperatura es un tipo de dispositivo de la celda, y así la celda lo puede usar igual que a los demás (báscula, cámara, etc.). No hereda de Calibrable porque este sensor no necesita calibrarse ya que mide bien desde el principio. En el constructor, el id se manda a la clase base con Dispositivo(id), porque ahí es donde se guarda.]

**Atributos propios de tu clase y para qué sirve cada uno:**

[- tempMin_: la temperatura más baja que se acepta (20 °C), si la pieza está más fría que esto se rechaza.

- tempMax_: la temperatura más alta que se acepta (35 °C), si la pieza está más caliente que esto se rechaza.

Los dos son privados para que nadie de afuera pueda cambiar la regla del sensor.]

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

[- descripcion(): devuelve el texto "Sensor temperatura", la celda usa este texto para mostrar qué dispositivo dio cada resultado.

- inspeccionar(const Pieza& pieza): aquí está la regla, devuelve true si la temperatura de la pieza es mayor o igual a tempMin_ y menor o igual a tempMax_, y false si no. Usé "mayor o igual" y "menor o igual" porque los límites sí cuentan como aceptados, por ejemplo, una pieza de exactamente 35 °C pasa.

Puse override en los dos para que el compilador me avise si me equivoco en el nombre o en la forma del método, sin override un error así crearía un método nuevo sin avisar y la celda seguiría usando el de la clase base.]

**¿Qué métodos de tu clase son `const` y por qué?**

[ descripcion() es const porque solo devuelve un texto y no cambia nada del sensor. Eso permite llamarlo incluso si el sensor es un objeto const. En inspeccionar(), la pieza se recibe como const Pieza&: es referencia para no copiarla y const porque el sensor solo la lee.]

**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `Bascula` o `CalibradorLaser`: ¿cómo modelaste el desfase y qué hace `calibrar()`?
- `SensorTemperatura`: ¿qué significa `final` y por qué tiene sentido en esta clase?
- `ReporteTurno`: ¿qué sobrecargas implementaste (constructores y operadores) y cómo decide `operator==` que dos reportes son iguales?
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

[final quiere decir que nadie puede crear otra clase que herede de SensorTemperatura, tiene sentido aquí porque la clase ya está completa, su única tarea es revisar que la temperatura esté en el rango, y no hay nada más que alguien necesite agregarle o cambiarle. Así evitamos que otra persona herede de ella y cambie la regla sin querer.]

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**

[Creé el sensor con los límites 20 y 35 y probé piezas del turno que cubren cada caso:
• P-01 (25 °C): está dentro del rango, el sensor la acepta.
• P-09 (35 °C): está justo en el límite superior, el sensor la acepta. Sirve para comprobar que el límite sí cuenta.
• P-07 (41 °C): está por encima del máximo, el sensor la rechaza.
• P-11 (19.5 °C): está por debajo del mínimo, el sensor la rechaza.

El sensor rechazó 2 piezas en todo el turno (P-07 y P-11), que es lo que dice el reporte esperado para T-01. También revisé que descripcion() imprima "Sensor temperatura" como pide la salida del proyecto.]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[- Para qué sirve final. No entendía bien qué hacía final, lo resolví leyendo la nota del proyecto y viendo que solo impide que otra clase herede de la mía.

- Si inspeccionar debía ser const. No sabía si debía poner const al final de inspeccionar, lo resolví revisando Dispositivo.h porque el override tiene que coincidir exactamente con ese método.]

**Errores que encontraste y cómo los corregiste:**

[Al principio solo revisaba la temperatura máxima y pasaba cuando debía rechazarse. El sensor daba 1 rechazo en lugar de 2. Me di cuenta al comparar contra el reporte esperado. Lo corregí agregando el atributo tempMin_ y la comparación de que la temperatura sea mayor o igual a ese mínimo.]
