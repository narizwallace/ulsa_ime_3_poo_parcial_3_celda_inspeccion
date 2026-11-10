# Proyecto del Tercer Parcial: Celda Robótica de Inspección de Calidad

**Programación Orientada a Objetos (PO-082103) — Ingeniería en Mecatrónica, 3er semestre**
**La Salle Saltillo**

---

## Sobre este proyecto

### El problema

En una planta de manufactura, las piezas terminadas llegan por una banda a una **celda de inspección de calidad**. En la celda hay varios dispositivos y cada uno revisa una característica distinta de la pieza: su peso, su largo, sus defectos visibles o su temperatura. Si **cualquier** dispositivo rechaza la pieza, la pieza se rechaza. Al terminar el turno, la celda entrega un reporte con cuántas piezas se inspeccionaron, cuántas se aceptaron y cuántos rechazos hizo cada dispositivo.

Antes de empezar el turno hay un detalle importante: algunos dispositivos salen de fábrica **descalibrados** y la celda debe calibrarlos. Si no lo hace, sus mediciones tienen un error y el reporte sale mal.

Su equipo va a construir el programa en C++ que simula un turno completo de esta celda.

### La idea central

> **La celda debe poder trabajar con cualquier dispositivo, incluso con uno que todavía no existe, sin modificar una sola línea de su código.**

La celda no sabe si está hablando con una báscula o con una cámara. Solo sabe que tiene **dispositivos** y que a cada uno le puede pedir que inspeccione una pieza. Cada dispositivo hace su propia inspección, a su manera. Eso es **polimorfismo**, y es lo que hace que el sistema pueda crecer sin romperse.

Comparen con los parciales anteriores:

| Parcial | ¿Cómo se manejaban los tipos? | ¿Qué pasa al agregar un tipo nuevo? |
|---|---|---|
| 1er parcial | Un `enum` de tipo de robot | Hay que modificar cada `if` / `switch` del programa |
| 2º parcial | Jerarquías de máquinas | El controlador seguía conociendo cada máquina concreta |
| **3er parcial** | La celda solo conoce a `Dispositivo` | **Se agrega una clase nueva y dos líneas en `main`. La celda no cambia.** |

El día de la exposición se va a **comprobar en vivo** que su diseño cumple esta idea (ver [Exposición y prueba de extensibilidad](#exposición-y-prueba-de-extensibilidad)).

### Qué se practica

| Unidad | Dónde aparece en el proyecto |
|---|---|
| I. Fundamentos de la OO | Objetos que colaboran enviándose mensajes: la celda le pide a cada dispositivo que inspeccione |
| II. Lenguajes OO | Todo el proyecto vive en el `namespace calidad`; paso por referencia (`const&`) frente a puntero |
| III. Herencia | Jerarquía de dispositivos (IS-A); la celda **tiene** un reporte (composición) y **usa** dispositivos que existen fuera de ella (agregación) |
| IV. Diseño de soluciones | Diseñar el contrato de `Dispositivo` antes de programar; organizar las clases como librería en `include/` y `src/`; binding dinámico |
| V. Aspectos avanzados de la herencia | Métodos virtuales puros, overriding, polimorfismo, herencia múltiple, sobrecarga de constructores y operadores, destructor virtual, asignación de espacio bajo herencia |

### Repositorio base

`https://github.com/narizwallace/ulsa_ime_3_poo_parcial_3_celda_inspeccion`

### Entregable

- El **link del fork del equipo** en Google Classroom. El fork debe contener:
  - El código completo del proyecto y los dos experimentos.
  - El **diagrama de clases** `diseno_solucion.png`, con la abstracción, los métodos virtuales y los `override` indicados (ver [Paso 2](#paso-2-dibujen-el-diagrama-de-clases)).
  - El `README.md` lleno, `docs/experimentos.md` y la documentación individual en `docs/<matrícula>/`.
- **Todos los integrantes** deben entregar el link en Classroom. Quien no entregue tendrá una penalización de 10 puntos.
- Quien tenga una o más tareas o prácticas del periodo del tercer parcial sin entregar pierde 5 puntos de la calificación del proyecto (ver [Penalizaciones](#penalizaciones)).
- Fecha límite: **miércoles 25 de noviembre de 2026, 11:59 PM**.
- Exposición: **jueves 26 de noviembre de 2026**.

### Fases

| Fase | Qué se hace | Quién |
|---|---|---|
| 0. Preparar el entorno | Fork, colaboradores y clonar | Equipo |
| 1. Entender el problema | Leer las reglas y calcular el reporte a mano | Equipo |
| 2. Diseñar la solución | Completar los contratos, hacer compilar el repo base y dibujar el diagrama | Equipo |
| 3. Implementar | Cada integrante su clase; el equipo la celda y `main` | Individual y equipo |
| 4. Probar y mejorar | Comparar contra el reporte esperado y corregir | Equipo |
| 5. Experimentos | Memoria, *slicing* y destructores | Equipo |
| 6. Publicar y entregar | Commits, documentación y entrega en Classroom | Individual y equipo |

---

## Fase 0: Preparar el entorno

1. **Un solo integrante** hace el fork del repositorio base a su cuenta de GitHub.
2. Ese integrante invita a los demás como colaboradores: en el fork, **Settings → Collaborators → Add people**.
3. Cada integrante acepta la invitación (llega por correo y aparece en las notificaciones de GitHub).
4. Cada integrante clona **el fork**, no el repositorio base:

   ```bash
   git clone https://github.com/<usuario-del-fork>/ulsa_ime_3_poo_parcial_3_celda_inspeccion.git
   ```

   También pueden clonarlo desde **GitHub Desktop**: *File → Clone repository* y elegir el fork.

> **Nota técnica — Trabajar varios en el mismo repositorio.**
> Antes de empezar a trabajar, siempre hagan `git pull` (o **Fetch / Pull** en GitHub Desktop) para traer los cambios de sus compañeros. Cada integrante trabaja en sus propios archivos, así que los conflictos deberían ser raros. Los archivos del equipo (`Dispositivo.h`, `Calibrable.h`, `CeldaInspeccion.cpp`, `main.cpp`) se modifican de uno en uno y avisando al equipo.

### Estructura del repositorio base

```
ulsa_ime_3_poo_parcial_3_celda_inspeccion/
├── include/
│   ├── Pieza.h                 (completa, no se modifica)
│   ├── DatosTurno.h            (completa, no se modifica)
│   ├── Dispositivo.h           (incompleta: la completa el equipo)
│   ├── Calibrable.h            (incompleta: la completa el equipo)
│   ├── CeldaInspeccion.h       (completa, no se modifica)
│   ├── Bascula.h               (clase vacía)
│   ├── CalibradorLaser.h       (clase vacía)
│   ├── CamaraVision.h          (clase vacía)
│   ├── SensorTemperatura.h     (clase vacía)
│   └── ReporteTurno.h          (clase vacía)
├── src/
│   ├── Pieza.cpp               (completa, no se modifica)
│   ├── DatosTurno.cpp          (completa, no se modifica)
│   ├── CeldaInspeccion.cpp     (iniciarTurno() completo; el resto lo hace el equipo)
│   ├── main.cpp                (main() vacío: lo completa el equipo)
│   ├── Bascula.cpp             (vacío)
│   ├── CalibradorLaser.cpp     (vacío)
│   ├── CamaraVision.cpp        (vacío)
│   ├── SensorTemperatura.cpp   (vacío)
│   └── ReporteTurno.cpp        (vacío)
├── experimentos/
│   ├── memoria.cpp             (vacío, solo un comentario)
│   └── destructores.cpp        (vacío, solo un comentario)
├── docs/
│   ├── PLANTILLA_CLASE.md
│   └── experimentos.md         (vacío, solo un comentario)
├── PROYECTO.md
├── README.md
└── .gitignore
```

El equipo completa `src/main.cpp`. El equipo de 6 integrantes crea además `include/Durometro.h` y `src/Durometro.cpp`.

---

## Fase 1: Entender el problema

> Llenen la **Sección 4 (Cálculo a mano del reporte)** del `README.md`.

### Los dispositivos y sus reglas

| Clase | Id | Descripción (en la salida) | Revisa | Acepta la pieza si | Calibrable | Desfase de fábrica |
|---|---|---|---|---|---|---|
| `Bascula` | `B-01` | `Bascula` | peso | 10.0 ≤ peso ≤ 15.0 kg | Sí | +0.4 kg |
| `CalibradorLaser` | `L-01` | `Calibrador laser` | largo | 49.5 ≤ largo ≤ 50.5 mm | Sí | −0.3 mm |
| `CamaraVision` | `V-01` | `Camara de vision` | defectos | defectos == 0 | No | — |
| `SensorTemperatura` | `T-01` | `Sensor temperatura` | temperatura | 20.0 ≤ temperatura ≤ 35.0 °C | No | — |
| `Durometro` (solo equipo de 6) | `D-01` | `Durometro` | dureza | 45 ≤ dureza ≤ 60 HRC | No | — |

**¿Qué significa el desfase?** Un dispositivo descalibrado mide mal. La báscula, por ejemplo, suma 0.4 kg a todo lo que pesa: una pieza de 12.0 kg la mide como 12.4 kg. La regla de aceptación se aplica **al valor medido**, no al valor real. Cuando el dispositivo se calibra, su desfase queda en 0.0 y mide exacto.

### Las piezas del turno

Las piezas ya vienen definidas en `src/DatosTurno.cpp` mediante la función `calidad::piezasDelTurno()`. **No se modifican.**

| Pieza | Peso (kg) | Largo (mm) | Temperatura (°C) | Defectos | Dureza (HRC) |
|---|---|---|---|---|---|
| P-01 | 12.0 | 50.0 | 25.0 | 0 | 52 |
| P-02 | 15.0 | 50.0 | 24.0 | 0 | 50 |
| P-03 | 16.2 | 50.1 | 25.0 | 0 | 55 |
| P-04 | 12.5 | 50.5 | 26.0 | 0 | 48 |
| P-05 | 11.0 | 50.7 | 25.0 | 0 | 53 |
| P-06 | 13.0 | 50.2 | 23.0 | 2 | 51 |
| P-07 | 12.2 | 49.9 | 41.0 | 0 | 50 |
| P-08 | 9.5 | 51.0 | 25.0 | 1 | 56 |
| P-09 | 14.8 | 50.0 | 35.0 | 0 | 62 |
| P-10 | 10.5 | 49.6 | 22.0 | 0 | 44 |
| P-11 | 13.5 | 50.3 | 19.5 | 0 | 58 |
| P-12 | 12.8 | 49.9 | 27.0 | 0 | 46 |

### Cálculo a mano

Antes de escribir código, el equipo calcula a mano el resultado de **cada pieza** con la celda **ya calibrada** y llena la tabla de la Sección 4 del `README.md`. Así sabrán qué debe imprimir su programa antes de programarlo.

**Ejemplo resuelto 1: P-02 (un caso límite).**

| Dispositivo | Valor medido | Regla | Resultado |
|---|---|---|---|
| B-01 | 15.0 kg | 10.0 ≤ 15.0 ≤ 15.0 | ACEPTA (el límite está incluido) |
| L-01 | 50.0 mm | 49.5 ≤ 50.0 ≤ 50.5 | ACEPTA |
| V-01 | 0 defectos | 0 == 0 | ACEPTA |
| T-01 | 24.0 °C | 20.0 ≤ 24.0 ≤ 35.0 | ACEPTA |

Resultado: **P-02 ACEPTADA**.

**Ejemplo resuelto 2: P-08 (falla en varios dispositivos).**

| Dispositivo | Valor medido | Regla | Resultado |
|---|---|---|---|
| B-01 | 9.5 kg | 9.5 < 10.0 | RECHAZA |
| L-01 | 51.0 mm | 51.0 > 50.5 | RECHAZA |
| V-01 | 1 defecto | 1 ≠ 0 | RECHAZA |
| T-01 | 25.0 °C | 20.0 ≤ 25.0 ≤ 35.0 | ACEPTA |

Resultado: **P-08 RECHAZADA**. Esta pieza cuenta como **una** pieza rechazada, pero suma **tres** rechazos: uno para B-01, uno para L-01 y uno para V-01.

### El reporte esperado

Con la celda calibrada, el reporte del turno debe ser:

| Concepto | Equipo de 5 | Equipo de 6 |
|---|---|---|
| Inspeccionadas | 12 | 12 |
| Aceptadas | 6 | 4 |
| Rechazadas | 6 | 8 |
| Rechazos B-01 | 2 | 2 |
| Rechazos D-01 | — | 2 |
| Rechazos L-01 | 2 | 2 |
| Rechazos T-01 | 2 | 2 |
| Rechazos V-01 | 2 | 2 |

Si su cálculo a mano no da este reporte, revísenlo antes de pasar a la Fase 2.

---

## Fase 2: Diseñar la solución

> Llenen la **Sección 3 (Contrato de `Dispositivo` y `Calibrable`)** y la **Sección 5 (Diagrama de clases)** del `README.md`.

Esta fase se hace **en equipo y antes de repartirse las clases**. Todos los dispositivos dependen del contrato que definan aquí; si el contrato cambia después, todos tienen que cambiar su clase.

### Paso 1: Hagan compilar el repositorio base

Compilen el proyecto tal como viene:

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o celda
```

**El repositorio base no compila, a propósito.** `CeldaInspeccion::iniciarTurno()` ya está implementado y usa `Dispositivo` y `Calibrable`, pero esas dos clases están incompletas. Su primera tarea es leer los errores del compilador, entender qué falta y completar las dos clases.

Lean con atención los comentarios `TODO` de `Dispositivo.h` y `Calibrable.h`, y el código de `iniciarTurno()` en `CeldaInspeccion.cpp`. El contrato que diseñen debe cumplir esto:

**`Dispositivo`**
- La celda debe poder pedirle a **cualquier** dispositivo que inspeccione una pieza (`inspeccionar`) y que diga qué tipo de dispositivo es (`descripcion`).
- No debe poder crearse un `Dispositivo` genérico: solo dispositivos concretos.
- Debe ser seguro destruir un dispositivo concreto a través de un `Dispositivo*`.

**`Calibrable`**
- Representa una **capacidad** (poder calibrarse), no un dispositivo.
- `iniciarTurno()` ya la usa: la forma en que la llama les dice qué deben declarar.

Las firmas exactas (tipos de parámetros, tipo de retorno, `const`) son **decisión del equipo** y deben justificarlas en la Sección 3 del README.

> **Nota técnica — `dynamic_cast` y herencia múltiple.**
> `iniciarTurno()` recorre todos los dispositivos y calibra solo los que también son `Calibrable`:
>
> ```cpp
> for (Dispositivo* d : dispositivos_) {
>     if (Calibrable* c = dynamic_cast<Calibrable*>(d)) {
>         // este dispositivo también es Calibrable
>     }
> }
> ```
>
> `dynamic_cast` revisa **en tiempo de ejecución** el tipo real del objeto. Si el objeto es, por ejemplo, una `Bascula` que hereda de `Dispositivo` **y** de `Calibrable`, devuelve un puntero a su parte `Calibrable`. Si el objeto no es `Calibrable`, devuelve `nullptr` y el `if` lo salta. A esta conversión entre las dos bases de un mismo objeto se le llama *cross-cast*, y solo es posible con herencia múltiple.
>
> `dynamic_cast` solo funciona si la clase de origen es **polimórfica**, es decir, si tiene al menos un método virtual. Si `Dispositivo` no tiene ninguno, el compilador lo rechaza.
>
> Con referencias (`dynamic_cast<Calibrable&>(*d)`) no hay `nullptr` posible: si falla, lanza la excepción `std::bad_cast`. Por eso aquí se usa la versión con punteros.

> **Nota conceptual — ¿Esto no es "preguntar por el tipo"?**
> Todo el proyecto evita preguntar "¿eres una báscula o una cámara?". `dynamic_cast` aquí no pregunta **qué dispositivo eres**, sino **qué capacidad tienes**: ¿te puedes calibrar? Si mañana llega un dispositivo nuevo que también es calibrable, la celda lo calibra sin cambiar nada. La idea central del proyecto se mantiene.

> **Nota técnica — Errores que el compilador no detecta.**
> Que el proyecto compile no significa que el contrato esté bien. Si `inspeccionar` o `calibrar` no son virtuales, el programa compila pero la celda ejecuta la versión equivocada y el reporte sale mal. Si el destructor no es virtual, en este proyecto no verán ningún síntoma, y precisamente por eso existe el Experimento 2.

### Paso 2: Dibujen el diagrama de clases

Dibujen el diagrama de clases de **toda la solución** y guárdenlo en la raíz del repositorio como `diseno_solucion.png`. Les recomendamos usar **draw.io** ([app.diagrams.net](https://app.diagrams.net)), que es gratuito y funciona en el navegador.

El diagrama es **parte de la entrega** y debe mostrar:

- **Todas las clases**, con sus atributos y métodos, y su visibilidad: `-` privado, `#` protegido, `+` público.
- **Abstracción:**
  - `Dispositivo` marcada como clase abstracta, con el estereotipo `«abstract»` sobre su nombre.
  - `Calibrable` marcada como interfaz, con el estereotipo `«interface»`.
- **Métodos virtuales:**
  - Los virtuales puros, marcados con `{abstract}` o con `= 0` al final. Por ejemplo: `+ inspeccionar(pieza: const Pieza&) : bool = 0`.
  - El destructor virtual, marcado con `{virtual}`. Por ejemplo: `+ ~Dispositivo() {virtual}`.
- **Overriding:** en cada clase derivada, los métodos que sobrescriben marcados con `{override}`. Por ejemplo: `+ inspeccionar(pieza: const Pieza&) : bool {override}`.
- **`final`:** `SensorTemperatura` marcada con `{final}` junto a su nombre.
- **Relaciones:**
  - **Herencia** (flecha con triángulo vacío hacia la clase base), incluyendo las **dos** flechas de herencia múltiple de `Bascula` y `CalibradorLaser`. La implementación de `Calibrable` puede dibujarse con línea punteada.
  - **Composición** entre `CeldaInspeccion` y `ReporteTurno` (rombo relleno del lado de la celda).
  - **Agregación** entre `CeldaInspeccion` y `Dispositivo` (rombo vacío del lado de la celda), con su multiplicidad (`0..*`).
  - **Dependencia** de los dispositivos hacia `Pieza` (línea punteada con flecha), porque la reciben en `inspeccionar`.

> **Nota técnica — Notación en draw.io.**
> En draw.io usen las figuras de la sección **UML**: *Class* para las clases y las flechas *Inheritance*, *Implementation*, *Composition*, *Aggregation* y *Dependency*. Los estereotipos (`«abstract»`, `«interface»`) se escriben en el nombre de la clase, arriba del nombre. Si no encuentran los símbolos `«` `»`, pueden escribir `<<abstract>>`.

> **Nota conceptual — Composición y agregación en la misma clase.**
> `CeldaInspeccion` tiene las dos relaciones de la Unidad III:
> - Los dispositivos se crean en `main` y la celda solo los **usa**. Si la celda desaparece, los dispositivos siguen existiendo. Es **agregación**, por eso la celda guarda punteros (`std::vector<Dispositivo*>`) y **no** los destruye.
> - El reporte **pertenece** a la celda: nace y muere con ella. Es **composición**, por eso es un atributo por valor (`ReporteTurno reporte_`).

---

## Fase 3: Implementar

> Cada integrante llena su documento de clase (ver [Documentación individual](#documentación-individual)). El equipo llena la **Sección 1 (Equipo)** y la **Sección 2 (Cómo compilar y ejecutar)** del `README.md`.

### Reparto de clases

Cada integrante es responsable de **definir, codificar, documentar y exponer** una clase. El equipo es dueño de la solución completa.

| Integrante | Clase | Archivos |
|---|---|---|
| 1 | `Bascula` | `include/Bascula.h`, `src/Bascula.cpp` |
| 2 | `CalibradorLaser` | `include/CalibradorLaser.h`, `src/CalibradorLaser.cpp` |
| 3 | `CamaraVision` | `include/CamaraVision.h`, `src/CamaraVision.cpp` |
| 4 | `SensorTemperatura` | `include/SensorTemperatura.h`, `src/SensorTemperatura.cpp` |
| 5 | `ReporteTurno` | `include/ReporteTurno.h`, `src/ReporteTurno.cpp` |
| 6 (solo equipo de 6) | `Durometro` | Los crea el integrante: `include/Durometro.h`, `src/Durometro.cpp` |
| Equipo | `Dispositivo`, `Calibrable`, `CeldaInspeccion`, `main.cpp`, experimentos | — |

Las clases de los archivos vacíos **no heredan de nada**: decidir de quién heredan y cómo es parte del trabajo.

### Requisitos de los dispositivos

- Todas las clases viven dentro del `namespace calidad`.
- Cada dispositivo hereda de `Dispositivo` e implementa su propia inspección según la tabla de reglas.
- El id del dispositivo se recibe en el constructor (`B-01`, `L-01`, etc.).
- `Bascula` y `CalibradorLaser` heredan **también** de `Calibrable`:
  - El desfase de fábrica es un atributo que empieza con el valor de la tabla.
  - `calibrar()` deja el desfase en 0.0 e indica que la calibración fue exitosa.
  - La inspección se hace sobre el **valor medido**: valor real + desfase.
- `SensorTemperatura` se declara `final`. En su documentación, el integrante explica qué significa y por qué tiene sentido en esta clase.
- Todo método que sobrescribe uno de la base se marca con `override`.

> **Nota de C++ — `override` y `final`.**
> `override` le pide al compilador que verifique que de verdad están sobrescribiendo un método virtual de la base. Si se equivocan en una letra o en un `const`, sin `override` el compilador crea un método nuevo en silencio; con `override`, marca el error.
> `final` en una clase (`class SensorTemperatura final : public Dispositivo`) impide que alguien herede de ella.

> **Nota técnica — Comparaciones con punto flotante.**
> Con `double`, operaciones que en papel son exactas pueden no serlo en la computadora: `0.1 + 0.2` da `0.30000000000000004`, no `0.3`. Los datos del turno se revisaron para que ninguna medición caiga en esa situación junto a un límite, así que pueden usar `<=` y `>=` directamente. En proyectos reales, las comparaciones contra un límite se hacen con una pequeña tolerancia.

### `ReporteTurno`: interfaz obligatoria

Como la celda y `main` usan esta clase, su interfaz pública **está fijada** para que el equipo pueda trabajar en paralelo. El integrante decide los atributos privados y la implementación.

| Miembro público | Qué hace |
|---|---|
| `ReporteTurno()` | Crea un reporte vacío (lo usa la celda) |
| `ReporteTurno(int inspeccionadas, int aceptadas, const std::map<std::string, int>& rechazos)` | Crea un reporte con valores conocidos (lo usa `main` para el reporte esperado) |
| `void registrarPieza(bool aceptada)` | Cuenta una pieza inspeccionada y si fue aceptada |
| `void registrarRechazo(const std::string& idDispositivo)` | Suma un rechazo al dispositivo indicado |
| `int inspeccionadas() const`, `int aceptadas() const`, `int rechazadas() const` | Consultas |
| `bool operator==(const ReporteTurno& otro) const` | Dos reportes son iguales si coinciden todos sus conteos |
| `friend std::ostream& operator<<(std::ostream& os, const ReporteTurno& r)` | Imprime el reporte con el formato exacto de la salida: desde `=== Reporte de turno ===` hasta el último rechazo por dispositivo. La línea `Reporte correcto` **no** la imprime este operador, la imprime `main` |

> **Nota de C++ — `std::map`.**
> `std::map<std::string, int>` guarda pares clave → valor, ordenados por la clave. Con `rechazos["B-01"]++` se suma uno al contador de `B-01`; si la clave no existía, se crea con valor 0 antes de sumar. Al recorrer un `map`, las claves salen en orden alfabético. Por eso el reporte lista los dispositivos como B-01, D-01, L-01, T-01, V-01.

> **Nota de C++ — Sobrecarga.**
> `ReporteTurno` tiene dos constructores con el mismo nombre y distintos parámetros (**sobrecarga de constructores**), y dos operadores redefinidos para la clase (**sobrecarga de operadores**). `Pieza` trae su propio `operator<<` como ejemplo: revísenlo en `src/Pieza.cpp`.

### `CeldaInspeccion`: lo que implementa el equipo

`include/CeldaInspeccion.h` ya está completo. El equipo implementa en `src/CeldaInspeccion.cpp`:

- `agregarDispositivo(Dispositivo* d)`: agrega el dispositivo a la celda.
- `procesar(const Pieza& pieza)`:
  1. Imprime una línea en blanco y el encabezado de la pieza. `Pieza` ya trae su `operator<<`, que imprime `Pieza P-01`: basta con `std::cout << pieza`.
  2. Pasa la pieza por **todos** los dispositivos, en el orden en que se agregaron, **aunque ya haya sido rechazada por alguno**.
  3. Imprime una línea por dispositivo con su resultado y registra en el reporte cada rechazo.
  4. La pieza se acepta solo si **ningún** dispositivo la rechazó.
  5. Imprime el resultado final, lo registra en el reporte y lo devuelve.
- `reporte()`: devuelve el reporte del turno.

**La celda nunca pregunta qué tipo de dispositivo es.** No se permite ningún `if`, `switch` ni `dynamic_cast` por tipo concreto en `procesar()`.

### `main.cpp`

El repositorio base trae `src/main.cpp` con un `main()` vacío, para que el proyecto compile mientras el equipo avanza. El equipo lo completa en este orden:

1. **Incluir** los encabezados de las clases que usa: los dispositivos, `CeldaInspeccion`, `ReporteTurno` y `DatosTurno.h`.
2. **Crear los dispositivos** en `main`, como objetos locales (no con `new`), con los ids de la tabla de reglas. Por ejemplo: `calidad::Bascula bascula("B-01");`.
3. **Crear la celda** y agregarle los dispositivos **por dirección** (`celda.agregarDispositivo(&bascula);`), en este orden: B-01, L-01, V-01, T-01 (y D-01 al final, en el equipo de 6).
4. **Iniciar el turno** con `celda.iniciarTurno();`.
5. **Procesar todas las piezas** que devuelve `calidad::piezasDelTurno()`, una por una, con `celda.procesar(pieza);`.
6. **Imprimir** una línea en blanco y después el reporte con `std::cout << celda.reporte();`.
7. **Construir el reporte esperado** con el segundo constructor de `ReporteTurno`, usando los valores de la tabla [El reporte esperado](#el-reporte-esperado) que corresponde a su equipo.
8. **Comparar** el reporte de la celda con el esperado usando `==` e imprimir en la última línea `Reporte correcto` o `Reporte con diferencias`.

`main` no inspecciona piezas, no cuenta rechazos ni imprime resultados de dispositivos: todo eso lo hace la celda. `main` solo arma la celda, la pone a trabajar y verifica el resultado.

> **Nota conceptual — ¿Por qué los dispositivos se crean en `main`?**
> Porque la celda **usa** los dispositivos pero no es su dueña (agregación). Los dispositivos viven en `main` y la celda solo guarda su dirección. Cuando `main` termina, los dispositivos se destruyen solos; la celda nunca hace `delete`.

> **Nota de C++ — Inicializar un `std::map` en una sola línea.**
> El tercer parámetro del segundo constructor de `ReporteTurno` es un `std::map<std::string, int>`. Se puede escribir directamente con llaves, un par `{clave, valor}` por dispositivo:
>
> ```cpp
> calidad::ReporteTurno esperado(10, 7, {{"A-01", 1}, {"Z-01", 2}});
> ```
>
> Los valores de este ejemplo **no** son los de su turno: usen los de la tabla del reporte esperado.

### Salida exacta

El programa debe imprimir **exactamente** este formato. En la salida no se usan acentos, para evitar problemas de codificación en la terminal.

```
=== Inicio de turno ===
Calibrando B-01 (Bascula) ... OK
Calibrando L-01 (Calibrador laser) ... OK

Pieza P-01
  B-01 (Bascula): ACEPTA
  L-01 (Calibrador laser): ACEPTA
  V-01 (Camara de vision): ACEPTA
  T-01 (Sensor temperatura): ACEPTA
  -> ACEPTADA

Pieza P-02
  ...

Pieza P-08
  B-01 (Bascula): RECHAZA
  L-01 (Calibrador laser): RECHAZA
  V-01 (Camara de vision): RECHAZA
  T-01 (Sensor temperatura): ACEPTA
  -> RECHAZADA

  ...

=== Reporte de turno ===
Inspeccionadas: 12
Aceptadas: 6
Rechazadas: 6
Rechazos por dispositivo:
  B-01: 2
  L-01: 2
  T-01: 2
  V-01: 2
Reporte correcto
```

Las líneas `=== Inicio de turno ===` y `Calibrando ...` ya las imprime `iniciarTurno()`.

---

## Fase 4: Probar y mejorar

> Respondan en la **Sección 4 (Cálculo a mano del reporte)** del `README.md` si el reporte coincidió y qué corrigieron.

1. El proyecto debe compilar **sin errores y sin warnings** con:

   ```bash
   g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o celda
   ```

2. Ejecuten el programa y comparen la salida, pieza por pieza, contra su cálculo a mano de la Fase 1.
3. La última línea debe ser `Reporte correcto`.
4. Si dice `Reporte con diferencias`, encuentren en qué pieza difiere su programa de su cálculo a mano, corrijan y registren en el README qué estaba mal y cómo lo corrigieron.

> **Pista de diagnóstico — ¿Se está aplicando la calibración?**
> Si la celda **no** calibra (o la calibración no tiene efecto), estas piezas cambian de resultado:
>
> | Pieza | Calibrada | Sin calibrar | Por qué |
> |---|---|---|---|
> | P-02 | ACEPTADA | RECHAZADA | 15.0 + 0.4 = 15.4 kg |
> | P-05 | RECHAZADA | ACEPTADA | 50.7 − 0.3 = 50.4 mm |
> | P-09 | ACEPTADA | RECHAZADA | 14.8 + 0.4 = 15.2 kg |
> | P-10 | ACEPTADA | RECHAZADA | 49.6 − 0.3 = 49.3 mm |
>
> Si **P-05 sale ACEPTADA** o **B-01 tiene 4 rechazos**, revisen su calibración: ¿se llama a `calibrar()`? ¿Es virtual? ¿Corrige el desfase que realmente usa la inspección?
>
> Fíjense en P-05: una celda sin calibrar no solo rechaza piezas buenas, **también deja pasar una pieza defectuosa**.

---

## Fase 5: Experimentos

> Llenen el archivo `docs/experimentos.md`.

Los experimentos son **dos programas independientes**, en la carpeta `experimentos/`. **No usan las clases del proyecto**: cada uno define sus propias clases sencillas (por ejemplo, `Base` y `Derivada`) y tiene su propio `main`. Son responsabilidad del equipo.

> **Nota técnica — Compilar los experimentos.**
> Cada experimento se compila por separado y **no** se mezcla con `src/*.cpp`, porque cada uno tiene su propio `main` y el enlazador encontraría dos:
>
> ```bash
> g++ -Wall -Wextra -std=c++17 experimentos/memoria.cpp -o memoria
> g++ -Wall -Wextra -std=c++17 experimentos/destructores.cpp -o destructores
> ```

### Experimento 1: Memoria y *object slicing* (`experimentos/memoria.cpp`)

**Objetivo:** entender qué ocupa un objeto en memoria bajo herencia y qué se pierde al copiar un objeto derivado en uno base.

El programa debe:
1. Imprimir `sizeof` de una clase base y de una derivada que agrega atributos.
2. Imprimir `sizeof` de las mismas clases después de agregar un método virtual a la base.
3. Pasar un objeto `Derivada` **por valor** a una función que recibe `Base`, llamar desde ahí a un método sobrescrito y mostrar qué versión se ejecuta.

En `docs/experimentos.md` peguen la salida y respondan:
1. ¿Por qué `sizeof(Derivada)` es mayor o igual que `sizeof(Base)`?
2. ¿Cuánto cambió el tamaño al agregar un método virtual y a qué se debe?
3. ¿Qué se perdió al pasar el objeto por valor?
4. ¿Por qué esto no puede pasar con `Dispositivo` en su proyecto? ¿Cómo se evita en general?

### Experimento 2: Destructor virtual (`experimentos/destructores.cpp`)

**Objetivo:** ver por qué existe la regla del curso: *una clase con métodos virtuales debe declarar un destructor virtual*.

El programa debe:
1. Definir una `Base` y una `Derivada`, cada una con un destructor que imprima un mensaje.
2. Crear una `Derivada` con `new`, guardarla en un `Base*` y destruirla con `delete` a través de ese puntero.
3. Ejecutarse dos veces: con el destructor de `Base` **sin** `virtual` y **con** `virtual`.

> **Nota técnica — El warning es parte del experimento.**
> En la versión **sin** `virtual`, si `Base` tiene algún otro método virtual, el compilador avisa: `deleting object of polymorphic class type 'Base' which has non-virtual destructor might cause undefined behavior`. No lo ignoren: es el compilador advirtiendo exactamente el error que están provocando. Copien ese warning en `docs/experimentos.md` y explíquenlo.
> En esa misma versión, el destructor de `Derivada` **no** puede llevar `override`, porque no hay un destructor virtual que sobrescribir; el compilador lo marcaría como error.

En `docs/experimentos.md` peguen las dos salidas y respondan:
1. ¿Qué diferencia hay entre las dos salidas?
2. ¿Qué problema real causaría eso si `Derivada` tuviera recursos que liberar (memoria, un archivo, una conexión)?
3. En su proyecto los dispositivos viven en `main` y nadie hace `delete` por un `Dispositivo*`. ¿En qué cambio del diseño este error sí causaría un problema?

---

## Fase 6: Publicar y entregar

> Llenen las **Secciones 6 (Documentación individual)**, **7 (Prueba de extensibilidad)** y **8 (Reflexión del equipo)** del `README.md`.

### Commits

- Cada integrante hace **commits propios** con su trabajo. La participación se revisará en el historial del repositorio.
- Hagan commits pequeños y frecuentes, con mensajes que digan qué cambió: `Bascula: agrega calibracion`, no `cambios`.
- El trabajo de equipo (contratos, celda, `main`, experimentos) también debe tener commits de distintos integrantes.

### Documentación individual

Cada integrante documenta **su clase** en una carpeta con su número de matrícula:

1. Creen la carpeta `docs/<matrícula>/`. Por ejemplo: `docs/0123456/`.
2. Copien `docs/PLANTILLA_CLASE.md` a esa carpeta con el nombre de su clase. Por ejemplo: `docs/0123456/Bascula.md`.
3. Llenen la plantilla y escriban su nombre después de la etiqueta **"Documentación elaborada por: "**.

La documentación de la clase debe explicar:
- La responsabilidad de la clase.
- Sus relaciones: de quién hereda y quién la usa.
- Sus decisiones de diseño: qué métodos sobrescribe, cuáles son `const` y por qué, y (si aplica) por qué es `final` o `Calibrable`.
- Cómo probaron que funciona.
- Qué dificultades tuvieron y cómo las resolvieron.

### Entrega

- Verifiquen que todo está en el fork: código, `diseno_solucion.png`, `README.md`, `docs/experimentos.md` y la documentación individual.
- **Cada integrante** entrega el link del fork en Google Classroom antes del **miércoles 25 de noviembre, 11:59 PM**.

---

## Exposición y prueba de extensibilidad

La exposición es el **jueves 26 de noviembre**. Cada equipo:

1. Ejecuta su programa y muestra que imprime `Reporte correcto`.
2. Muestra su diagrama y explica el contrato de `Dispositivo` y `Calibrable`.
3. Cada integrante explica **su clase** y sus decisiones de diseño.
4. Explica los resultados de los dos experimentos.

### Prueba de extensibilidad

**Al final de la exposición se hará una prueba en vivo.** El profesor le entregará al equipo una regla de inspección **nueva**, de una sola línea. Por ejemplo: *"Rechaza las piezas de más de 14.0 kg"*. El profesor elegirá **al azar** al integrante que la implementará en ese momento como un dispositivo nuevo, en una clase nueva.

La prueba evalúa una sola cosa: **¿pudieron agregar el dispositivo sin modificar `CeldaInspeccion`?**

- Si el diseño cumple la idea central del proyecto, la prueba es corta: una clase nueva que hereda de `Dispositivo`, sus métodos sobrescritos y dos líneas en `main`: una para crear el dispositivo y otra para agregarlo a la celda.
- Como el integrante se elige al azar, **todo el equipo** debe entender el contrato de `Dispositivo`, no solo quien lo escribió.

Al agregar el dispositivo nuevo, el programa imprimirá `Reporte con diferencias`, porque el reporte esperado no lo incluye. **Es normal y no cuenta en contra**: no hay que actualizar el reporte esperado durante la prueba.

Prepárense: practiquen agregar un dispositivo de prueba y, después, quítenlo antes de entregar.

---

## Rúbrica

| Criterio | Qué se evalúa | Puntos | Tipo |
|---|---|---|---|
| Diseño del contrato | `Dispositivo` abstracta con virtuales puros y destructor virtual; `Calibrable` como interfaz; herencia múltiple correcta; firmas y `const` justificados | 20 | Equipo |
| Diseño de la solución | Diagrama completo y correcto: abstracción, virtuales puros, destructor virtual, `override`, `final` y relaciones (herencia múltiple, composición, agregación, dependencia) indicados; la celda no pregunta por tipos concretos | 10 | Equipo |
| Funcionamiento | Compila sin errores ni warnings; salida con el formato exacto; `Reporte correcto` | 15 | Equipo |
| Clase individual | Implementación correcta según la tabla de reglas o la interfaz de `ReporteTurno`; uso de `override`, `final`, sobrecarga según corresponda | 20 | Individual |
| Documentación individual | Documento completo en `docs/<matrícula>/` | 5 | Individual |
| Experimentos | Programas correctos y respuestas que demuestran comprensión | 10 | Equipo |
| Calidad del código | `namespace calidad`; `const&` donde corresponde; atributos privados primero; nombres claros | 5 | Equipo |
| Colaboración | Commits propios de cada integrante, en su clase y en el trabajo de equipo | 5 | Individual |
| Exposición y prueba de extensibilidad | Explicación de la propia clase; dispositivo agregado sin modificar la celda | 10 | Individual y equipo |
| **Total** | | **100** | |
| Reto opcional (extra) | Reto resuelto en la rama `<matrícula>`, documentado en `docs/<matrícula>/RETO.md`, sin integrarse a `main` | +5 | Individual |

**La calificación máxima del proyecto es 100.** Los puntos extra del reto solo se suman si hay espacio para llegar a 100. Por ejemplo, con 97 puntos el reto deja la calificación en 100, no en 102.

### Penalizaciones

Las penalizaciones son **individuales** y se restan de la calificación del proyecto de cada integrante:

| Falta | Penalización |
|---|---|
| No entregar el link del fork en Classroom | −10 puntos |
| Una o más tareas o prácticas del periodo del tercer parcial sin entregar en Classroom | −5 puntos (una sola vez, sin importar cuántas falten) |

---

## Retos opcionales (insatisfacción positiva)

Si su proyecto ya imprime `Reporte correcto` y quieren ir más allá, pueden resolver un reto opcional. **Los retos son individuales** y valen hasta **5 puntos extra** sobre la calificación del proyecto, sin pasar del máximo de 100.

### Los retos

Elijan **uno**:

1. **Modo aleatorio.** Agreguen un modo que genere un turno de piezas aleatorias con `<random>` y una semilla fija, además del turno fijo. Respondan: ¿por qué `rand()` no sirve para comparar resultados entre computadoras distintas?
2. **Motivo del rechazo.** Que cada dispositivo diga *por qué* rechazó la pieza. Por ejemplo: `RECHAZA (15.4 kg > 15.0)`. Respondan: ¿qué tuvieron que cambiar en el contrato de `Dispositivo` y por qué `bool inspeccionar()` ya no alcanzaba?
3. **Calibración que puede fallar.** Un dispositivo cuya calibración puede fallar y, si falla, queda fuera de servicio durante el turno. Respondan: ¿cómo reacciona la celda? ¿Qué cambiaron en `Calibrable` y en `CeldaInspeccion`?

### Reglas

- El reto se hace en una **rama propia**, cuyo nombre es **su número de matrícula**. Por ejemplo: `0123456`.
- La rama sale de `main` del fork del equipo, **cuando `main` ya imprime `Reporte correcto`**.
- El reto **nunca** se integra a `main`. `main` es lo que se evalúa como proyecto y debe seguir cumpliendo la salida exacta.
- Documenten el reto, **dentro de su rama**, en `docs/<matrícula>/RETO.md`: qué reto eligieron, qué cambiaron, por qué y la respuesta a la pregunta del reto.
- La rama debe estar publicada en GitHub antes de la fecha límite del proyecto.

### Crear la rama

**Con la terminal:**

```bash
git checkout main
git pull
git checkout -b 0123456          # su número de matrícula
git push -u origin 0123456       # publica la rama en GitHub
```

**Con GitHub Desktop:**

1. En **Current Branch**, seleccionen `main` y hagan **Fetch origin** / **Pull origin**.
2. En **Current Branch**, elijan **New Branch**, escriban su número de matrícula y confirmen que se crea a partir de `main`.
3. Hagan clic en **Publish branch**.

Para trabajar en el reto, asegúrense de estar en su rama (`git checkout 0123456`, o selecciónenla en **Current Branch**). Para volver al proyecto del equipo, cámbiense a `main`.

### Mantener la rama sincronizada con `main`

Mientras ustedes trabajan en su reto, el equipo puede seguir corrigiendo `main`. Para traer esos cambios a su rama:

**Con la terminal:**

```bash
git checkout main
git pull                         # trae lo último de main
git checkout 0123456
git merge main                   # lleva los cambios de main a su rama
git push
```

**Con GitHub Desktop:**

1. Seleccionen `main` y hagan **Pull origin**.
2. Cámbiense a su rama.
3. En el menú **Branch**, elijan **Update from main** (o **Merge into current branch…** y seleccionen `main`).
4. Hagan clic en **Push origin**.

> **Nota técnica — Los merges van solo de `main` a su rama, nunca al revés.**
> Los cambios siempre fluyen en una sola dirección: `main` → `0123456`. **Nunca** hagan `git merge 0123456` estando en `main`, ni abran un *pull request* de su rama hacia `main`. Si lo hicieran, su reto cambiaría la salida del proyecto de todo el equipo y `main` dejaría de imprimir `Reporte correcto`.
>
> Mantener una sola dirección también reduce mucho las posibilidades de un conflicto, porque `main` nunca recibe cambios de las ramas de reto. Sincronicen seguido: entre menos cambios acumule `main` sin traerlos a su rama, más fácil es el merge.

> **Nota técnica — Si aparece un conflicto.**
> Un conflicto ocurre cuando `main` y su rama cambiaron las mismas líneas. Git marca el archivo con `<<<<<<<`, `=======` y `>>>>>>>`. Abran el archivo, decidan qué versión se queda (normalmente su cambio del reto sobre la corrección de `main`), borren las marcas, compilen y verifiquen que funciona, y después:
>
> ```bash
> git add <archivo>
> git commit
> git push
> ```
>
> Si no saben cómo resolverlo, no fuercen nada: pregunten antes.

## Lista de verificación

- ☐ El fork tiene a todos los integrantes como colaboradores.
- ☐ El cálculo a mano está en la Sección 4 del README y coincide con el reporte esperado.
- ☐ `Dispositivo` y `Calibrable` están completas y su diseño está justificado en el README.
- ☐ `diseno_solucion.png` está en la raíz del repositorio e indica `«abstract»`, `«interface»`, virtuales puros, destructor virtual, `{override}`, `{final}` y todas las relaciones.
- ☐ Cada dispositivo hereda correctamente y usa `override`.
- ☐ `Bascula` y `CalibradorLaser` son también `Calibrable`.
- ☐ `SensorTemperatura` es `final`.
- ☐ `ReporteTurno` cumple la interfaz obligatoria.
- ☐ `procesar()` no pregunta por el tipo concreto de ningún dispositivo.
- ☐ Compila sin errores ni warnings con `-Wall -Wextra -std=c++17`.
- ☐ La salida tiene el formato exacto y termina en `Reporte correcto`.
- ☐ Los dos experimentos compilan por separado y `docs/experimentos.md` está completo.
- ☐ Cada integrante tiene su documentación en `docs/<matrícula>/`.
- ☐ Cada integrante tiene commits propios.
- ☐ Cada integrante entregó el link del fork en Classroom.
- ☐ Practicamos agregar un dispositivo nuevo sin modificar la celda.
- ☐ (Opcional) Quien hizo un reto lo tiene en su rama `<matrícula>`, publicada en GitHub y sin integrarla a `main`.
