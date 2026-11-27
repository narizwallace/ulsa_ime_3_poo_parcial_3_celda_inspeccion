# Proyecto Semestral: Celda de Inspección con Prototipos y Delegación

## Sobre este proyecto

### El problema

En el tercer parcial construyeron una celda de inspección que trabaja con cualquier dispositivo sin conocer su tipo concreto, y lo comprobaron en vivo agregando una máquina nueva. Ahora la planta quiere dos cosas más:

1.  **Armar celdas a partir de dispositivos ya configurados.** Configurar una báscula, calibrarla y dejarla lista cuesta trabajo. La planta quiere tener un "modelo" de cada dispositivo y producir copias de él cada vez que arma una celda, sin volver a configurar nada y sin que la celda sepa qué tipo de dispositivo está copiando.
2.  **Cambiar cómo decide un dispositivo sin crear clases nuevas.** Hoy la regla de aceptación está escrita dentro de cada dispositivo. Si mañana cambia un límite o la forma de evaluar, hay que modificar o heredar la clase. La planta quiere que esa decisión pueda vivir en otro objeto.

Su equipo va a evolucionar **su propio proyecto del tercer parcial** para resolver estas dos necesidades con los temas de la **Unidad VI: Prototipos y Delegación**.

### La idea central

> **Un objeto puede crear copias de sí mismo sin que nadie conozca su tipo (prototipo), y puede encargarle parte de su trabajo a otro objeto en lugar de heredarlo (delegación).**

En el tercer parcial la celda dejó de conocer los tipos concretos para **usar** dispositivos. En el semestral, el programa deja de conocer los tipos concretos también para **crearlos**.

| Etapa | ¿Quién conoce los tipos concretos? |
| --- | --- |
| 3er parcial | Solo `main`, para crear cada dispositivo con su clase |
| **Semestral** | Solo el lugar donde se registran los prototipos. La celda se arma con **clones** |

### Qué se practica

| Tema | Dónde aparece en el proyecto |
| --- | --- |
| Prototipos | Cada dispositivo sabe clonarse; un catálogo guarda prototipos y entrega copias |
| Copia superficial y profunda | Al clonar un dispositivo que tiene objetos colaboradores |
| Delegación | Cada dispositivo le encarga al menos una responsabilidad a otro objeto |
| Ventajas y desventajas | Documento de decisiones de diseño y exposición |
| Todo lo anterior (Unidades I–V) | Su proyecto del tercer parcial, que se mantiene funcionando |

### Material de apoyo

**La presentación de la Unidad VI (Prototipos y Delegación)** en Google Classroom:  
`https://classroom.google.com/c/ODc0ODMzMDA4Nzcy/m/OTAwNTk5NDY3Njkx/details`  
Empiecen por aquí: es la base de todo el proyecto.

**Los ejemplos de código de la Unidad VI:**  
`https://github.com/narizwallace/ulsa_ime_3_poo_ejemplos_unidad_6`  
Cada archivo es un programa independiente que corresponde a una diapositiva de la presentación (el número al inicio del nombre es el número de la diapositiva).

| Tema | Archivos |
| --- | --- |
| Prototipos | `06` (slicing) → `08` (clonar) → `09` (notas de C++) → `10` (copia superficial y profunda) → `11_12` (catálogo) |
| Delegación | `16` → `17` (cambiar en ejecución) → `18` → `19` → `21` |
| Integración | `23` (un objeto que se clona y también clona a su delegado) |

> Los ejemplos usan robots, no dispositivos de inspección. **No se copian:** se entienden y se trasladan a su proyecto. Las decisiones de cómo hacerlo son suyas.

**Videos complementarios (opcionales).** Algunos están en inglés o usan otro lenguaje; lo importante es la idea, no la sintaxis.

| Tema | Video | Idioma / lenguaje |
| --- | --- | --- |
| Prototipos | [Patrón Prototype](https://www.youtube.com/watch?v=JIpvXy3mUWQ) | Español |
| Prototipos | [Prototype Pattern in C++ (clone)](https://www.youtube.com/watch?v=x2DaAhZn20Y) | Inglés / C++ |
| Prototipos | [Virtual Constructor – Clone() Function](https://www.youtube.com/watch?v=UHP-DKrxgBs) | Inglés / C++ |
| Copia profunda y registro de prototipos | [The Prototype Pattern Explained and Implemented](https://www.youtube.com/watch?v=DcFhITC9v0E) | Inglés / Java |
| Delegación | [Herencia vs Composición](https://www.youtube.com/watch?v=WRnZuu2PIr4) | Español |
| Delegación | [Patrón Strategy](https://www.youtube.com/watch?v=j0I_hzEhfTE) | Español |
| Delegación | [The Flaws of Inheritance](https://www.youtube.com/watch?v=hxGOiiR9ZKg) | Inglés |

### Entregable

*   El **link de la rama** `semestral` de su fork en Google Classroom. Todos los integrantes lo entregan.
*   La rama debe contener:
    *   El proyecto completo con prototipos y delegación, compilando y con el reporte correcto, incluida la máquina de su prueba de extensibilidad.
    *   La documentación de cada clase actualizada, el `README.md` actualizado y el documento `docs/DECISIONES_SEMESTRAL.md`.
    *   Un diagrama `diseno_prototipo.png` con un fragmento que muestre cómo implementaron el patrón Prototipo (no hace falta el diagrama completo).

### Fechas

| Fecha | Qué pasa |
| --- | --- |
| **Viernes 4 de diciembre, 2:00 PM**, salón de clases | Revisión: proyecto completo, compilando, con prototipos y delegación. Se revisan el repo y la presentación, y se dan sugerencias |
| **Sábado 5 de diciembre** | Ajustes a partir de la revisión. Habrá un canal (Google Meet u otro) para dudas; se avisa en Classroom. Entrega en Classroom antes de las **11:59 PM** |
| **Lunes 7 de diciembre, 1:30–3:30 PM** | Presentación ante un panel de autoridades de la universidad, 10 minutos por equipo |

### Fases

| Fase | Qué se hace | Quién |
| --- | --- | --- |
| 0\. Preparar el entorno | Sincronizar el fork y crear la rama `semestral` | Dueño del fork y equipo |
| 1\. Verificar el punto de partida | Confirmar que su proyecto del tercer parcial funciona | Equipo |
| 2\. Diseñar | Responder las preguntas guía y dibujar el fragmento del diagrama | Equipo |
| 3\. Implementar | Cada integrante su máquina; el equipo los componentes generales | Individual y equipo |
| 4\. Probar | Verificar que los clones producen el mismo reporte | Equipo |
| 5\. Documentar y publicar | Documentación, `README.md`, commits y entrega | Individual y equipo |
| 6\. Preparar la presentación | Tema académico y demo | Equipo |

---

## Fase 0: Preparar el entorno

Van a trabajar **en el mismo fork del tercer parcial**, en una rama nueva llamada `semestral`. La rama `main` se queda como está: es la versión que se calificó en el tercer parcial.

### Paso 1: Sincronizar el fork (solo el dueño del fork)

1.  Abran su fork en GitHub.
2.  Presionen **Sync fork → Update branch**. Así llega este archivo, `SEMESTRAL.md`, a su `main`.

> **Importante.** Si GitHub muestra la opción **Discard commits**, **no la elijan**: borraría su trabajo. Cierren el diálogo y avisen al profesor.

### Paso 2: Traer el cambio a su computadora (todos)

En GitHub Desktop, con la rama `main` seleccionada: **Fetch origin** y después **Pull origin**.

Antes de seguir, verifiquen que la clase de su prueba de extensibilidad (la máquina que crearon en vivo) está en `main`. Si no está, súbanla a `main` antes de crear la rama.

### Paso 3: Crear la rama `semestral` (solo un integrante)

1.  En GitHub Desktop, con `main` seleccionada: **Branch → New branch**.
2.  Nombre: `semestral`. Base: `main`.
3.  **Publish branch**.

En terminal:

```
git checkout main
git pull
git checkout -b semestral
git push -u origin semestral
```

### Paso 4: Cambiarse a la rama (los demás integrantes)

En GitHub Desktop: **Fetch origin**, después **Current branch** y eligen `semestral`.

En terminal:

```
git fetch
git checkout semestral
```

> **Nota técnica — Trabajen siempre en** `semestral`**.** Antes de cada sesión de trabajo revisen en GitHub Desktop que la rama actual sea `semestral`. Un commit en `main` no cuenta para el semestral.

---

## Fase 1: Verificar el punto de partida

Antes de cambiar nada, confirmen que su proyecto del tercer parcial funciona en la rama `semestral`:

☐ Compila sin errores ni advertencias:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o celda
```

☐ El reporte del turno es el esperado del tercer parcial.  
☐ La máquina de su prueba de extensibilidad está integrada, lee los atributos de `Pieza` que le corresponden según su reto, y el reporte muestra qué piezas aceptó y cuáles rechazó.

Si algo de esto falla, corregirlo es parte del trabajo del semestral. Hagan el **cálculo a mano** de la máquina nueva, pieza por pieza, como en la Fase 1 del tercer parcial, para saber qué debe imprimir.

---

## Fase 2: Diseñar

En esta fase **no se escribe código**. Respondan las preguntas en equipo y anoten sus respuestas en `docs/DECISIONES_SEMESTRAL.md`. No hay una única respuesta correcta: lo que se evalúa es que su decisión tenga una razón.

### Lo que su proyecto debe lograr

Lo **qué** es obligatorio; el **cómo** lo deciden ustedes:

1.  **Todos los dispositivos se pueden clonar**, incluida la máquina de su prueba de extensibilidad, a través de un puntero o referencia a `Dispositivo`.
2.  **Existe un catálogo o registro de prototipos**, y **la celda se arma con clones** que entrega ese catálogo, no creando cada dispositivo directamente.
3.  **Cada dispositivo delega al menos una responsabilidad** en otro objeto colaborador.
4.  **El reporte sigue funcionando** con lo que producen los clones.

### Preguntas guía: prototipos

*   ¿Por qué no pueden copiar un dispositivo usando el constructor de copia a través de un `Dispositivo*`? (Recuerden su experimento de _slicing_ y el ejemplo `06`.)
*   ¿Qué debe regresar `clonar()`? ¿Quién es el dueño de la copia y quién la libera? ¿Puntero crudo o `std::unique_ptr`?
*   ¿Un clon debe tener la **misma identidad** (id) que su prototipo, o una nueva? ¿Qué pasaría en el reporte si dos dispositivos de la celda tuvieran el mismo id? Antes de decidir, revisen **cómo el reporte identifica a cada dispositivo** y **cómo** `main` **verifica que el reporte es correcto**. Con base en esto, decidan si `clonar()` recibe o no un parámetro.
*   Si clonan una báscula **ya calibrada**, ¿el clon sale calibrado? ¿Eso es lo que quieren?
*   Con herencia múltiple: ¿`clonar()` se declara en `Dispositivo`, en `Calibrable` o en ambas? ¿Qué tipo regresa en cada caso?
*   ¿Quién es el dueño de los prototipos del catálogo? ¿Qué debe pasar si se pide una clave que no existe?
*   ¿Quién es el dueño de los **clones** que entrega el catálogo? ¿Cuánto tiempo vive cada clon y cuánto tiempo los necesita la celda? Recuerden que en el tercer parcial la celda **usa** dispositivos que no le pertenecen (agregación). ¿Mantienen esa decisión o la celda pasa a ser dueña de sus dispositivos?
*   Si mañana llega un dispositivo nuevo, ¿hay que modificar el catálogo?

> **Nota técnica — Punteros colgantes.** Si la celda guarda el puntero de un `std::unique_ptr` temporal (por ejemplo, con `.get()` sobre el resultado de una función, en la misma línea), el objeto se destruye al terminar esa línea y la celda queda apuntando a memoria liberada. **El compilador no lo detecta**: el programa puede parecer que funciona en una computadora y fallar en otra, o el día de la presentación. Alguien debe ser dueño de cada clon mientras la celda lo use.

### Preguntas guía: delegación

*   Revisen las inspecciones de todos sus dispositivos. ¿Qué parte **cambia** de un dispositivo a otro y qué parte **se repite**?
*   ¿Esa parte podría ser responsabilidad de otro objeto? ¿Qué le preguntaría el dispositivo a ese objeto?
*   ¿Les sirve poder **cambiar** al colaborador mientras el programa corre? Si es así, ¿cómo evitan que alguien les pase un colaborador nulo? (Ejemplo `17`.)
*   Cuando se clona un dispositivo que tiene un colaborador, ¿el clon **comparte** al colaborador o tiene **su propia copia**? ¿Qué problema aparece en cada caso? (Ejemplos `10` y `23`.)
*   ¿Qué tendrían que hacer para lograr lo mismo **solo con herencia**? ¿Cuántas clases saldrían? Esta respuesta es su análisis de ventajas y desventajas.

### Fragmento del diagrama

Dibujen en **draw.io** un fragmento del diagrama de clases que muestre cómo implementaron el patrón Prototipo: `Dispositivo`, al menos dos dispositivos concretos, el método de clonación y el catálogo. Si su delegación forma parte del mismo dibujo, inclúyanla. Guárdenlo como `diseno_prototipo.png` en la raíz del repositorio.

---

## Fase 3: Implementar

### Reparto

Cada integrante sigue siendo responsable de **la máquina que desarrolló en el tercer parcial**: la hace clonable, aplica la delegación del equipo y actualiza su documentación. La máquina de la prueba de extensibilidad la mantiene el integrante que la programó en vivo.

En conjunto, el equipo trabaja en los componentes generales:

| Componente | Qué cambia |
| --- | --- |
| `Dispositivo` | El contrato de clonación y lo que el equipo decida sobre la delegación |
| `Calibrable` | Lo que implique la clonación en dispositivos con herencia múltiple |
| Catálogo de prototipos | Clase nueva |
| `CeldaInspeccion` | Lo que implique su decisión sobre quién es dueño de los clones |
| `ReporteTurno` | Debe seguir funcionando con los resultados de los clones. Si en el tercer parcial el reporte tuvo un responsable, esa persona se asegura de que siga funcionando después de los cambios |
| `main.cpp` | Registra los prototipos y arma la celda con clones |

### Qué se puede modificar

| Archivo | ¿Se modifica en el semestral? |
| --- | --- |
| `Pieza`, `DatosTurno` | **No.** Las piezas del turno son las mismas |
| `Dispositivo`, `Calibrable`, `CeldaInspeccion`, `main.cpp` | Sí, según sus decisiones de diseño |
| Sus máquinas, incluida la de la prueba de extensibilidad | Sí |
| `ReporteTurno` | Solo si lo necesitan; debe seguir dando el mismo reporte |
| Experimentos (`experimentos/`) | No |

> **Nota técnica — Cambios en archivos compartidos.** `Dispositivo.h` cambia primero y lo cambia una sola persona a la vez. Si el contrato de clonación es virtual puro, ninguna máquina compila hasta que todas lo implementen. Pónganse de acuerdo sobre quién hace cada cambio y avisen cuando esté listo.

> **Nota de C++ —** `override` **sigue siendo obligatorio.** Si se equivocan en el tipo de retorno o en un `const` de `clonar()`, `override` hace que el compilador se los diga.

> **Nota de C++ — Retorno covariante.** Una clase derivada puede sobrescribir un método virtual que regresa `Base*` con uno que regresa `Derivada*`. Esto no funciona con `std::unique_ptr<Base>` y `std::unique_ptr<Derivada>`. Revisen el ejemplo `09` antes de decidir.

> **Nota de C++ —** `clonar()` **necesita el constructor de copia.** La forma habitual de clonar es construir una copia de `*this`. Si en el tercer parcial eliminaron u ocultaron el constructor de copia de `Dispositivo` (por ejemplo, para evitar el _slicing_), `clonar()` no va a compilar. El ejemplo `09` muestra cómo dejar el constructor de copia `protected`: las derivadas lo pueden usar dentro de `clonar()`, pero nadie puede copiar un `Dispositivo` desde fuera.

---

## Fase 4: Probar

☐ La celda armada con clones produce **exactamente** el mismo reporte que su versión del tercer parcial.  
☐ Cambiar algo en un clon no modifica a su prototipo en el catálogo.  
☐ Pedir al catálogo una clave inexistente no rompe el programa.  
☐ Si su delegación se puede cambiar en ejecución: cambiar el colaborador de un dispositivo cambia sus resultados como lo esperan según su cálculo a mano.  
☐ Compila sin advertencias.

> **Pista — ¿Cómo probar que un clon no modifica a su prototipo?** Calibren un clon de la báscula y después pidan al catálogo **otra** báscula nueva, sin calibrar. Inspeccionen con las dos la pieza **P-02** (15.0 kg): la báscula calibrada debe **aceptarla** y la nueva, que todavía trae el desfase de fábrica de +0.4 kg, debe **rechazarla**. Si las dos dan el mismo resultado, algo se está compartiendo entre el clon y el prototipo.

---

## Fase 5: Documentar y publicar

### Commits

*   Todo el trabajo va en la rama `semestral`, con **commits propios** de cada integrante. La participación se revisará en el historial con la diferencia entre `main` y `semestral`.
*   Commits pequeños y con mensajes claros: `Bascula: implementa clonar`, no `cambios`.

### Documentación

*   **Cada integrante** actualiza el documento de su máquina en `docs/<matrícula>/` con la nueva versión: cómo se clona, qué delega y por qué.
*   **El equipo** actualiza la documentación de los componentes generales.
*   **El equipo** escribe `docs/DECISIONES_SEMESTRAL.md` con las respuestas a las preguntas guía de la Fase 2.
*   **El equipo** actualiza el `README.md` y agrega al final una sección **"9. Semestral: prototipos y delegación"** con:
    *   Qué dispositivos se registran como prototipos.
    *   Qué responsabilidad delegaron y en qué objeto.
    *   Cómo compilar y ejecutar la versión del semestral, si cambió.

### Entrega

*   Verifiquen que todo está en la rama `semestral` de su fork.
*   **Cada integrante** entrega en Google Classroom el link de la rama `semestral` antes del **sábado 5 de diciembre a las 11:59 PM**.

---

## Revisión del viernes 4 de diciembre

**Viernes 4 de diciembre, 2:00 PM, salón de clases.** Traigan:

☐ El proyecto **completo** en la rama `semestral`: compila, tiene prototipos y delegación, y el reporte es correcto.  
☐ Un avance de su presentación.

Se revisarán rápidamente el repo y la presentación de cada equipo y se darán sugerencias para presentar ante el panel. El sábado es para **ajustes** a partir de esa revisión, no para terminar el proyecto.

---

## Presentación ante el panel

**Lunes 7 de diciembre, 1:30–3:30 PM.** El panel está formado por autoridades de la universidad. Cada equipo tiene **10 minutos**.

*   Se sugiere que **uno o dos integrantes** presenten. El resto del equipo debe estar listo para responder cualquier pregunta del panel.
*   **No se escribe código** durante la presentación. Todo se muestra ejecutando el programa ya terminado y navegando el código.
*   La dinámica, el material de apoyo y si usan o no el diagrama los decide cada equipo.

### Estructura

Cada presentación tiene dos partes:

1.  **Tema académico (3 minutos):** explicar el concepto asignado como tema de POO.
2.  **El concepto en su proyecto (resto del tiempo):** mostrar dónde está ese concepto en su código, cómo se refleja al ejecutar el programa y qué beneficio les dio aplicarlo.

Los temas siguen un orden: cada equipo prepara el terreno para el siguiente, y el equipo 4 cierra con los temas de la Unidad VI.

| Equipo | Tema académico | Qué muestran en su proyecto |
| --- | --- | --- |
| 1 — Equipo de Diego Simental | Qué es la programación orientada a objetos: clase, atributo y método | Esos conceptos en sus clases, y la máquina de su prueba de extensibilidad: cómo extendieron la solución con una clase nueva |
| 2 — Equipo de Michelle González | Herencia y abstracción | Sus clases base y derivadas y cómo se relacionan, y la máquina de su prueba de extensibilidad dentro de esa jerarquía |
| 3 — Equipo de Néstor López | Polimorfismo y encapsulamiento | Cómo implementaron ambos conceptos, y su demostración en la máquina de su prueba de extensibilidad |
| 4 — Equipo de Luis Samano | Prototipos y delegación | Su implementación de prototipos y delegación, aplicada también a la máquina de su prueba de extensibilidad |

**Todos los equipos** muestran en su demo que la máquina de su prueba de extensibilidad funciona: lee los atributos de `Pieza` que le corresponden y el reporte muestra qué piezas aceptó y cuáles rechazó. Aunque solo el equipo 4 expone prototipos y delegación, **todos** los tienen implementados y el panel puede preguntar sobre ellos a cualquier equipo.

---

## Rúbrica

| Criterio | Peso | Qué se revisa |
| --- | --- | --- |
| Prototipos y delegación | 40% | Revisión del código en la rama `semestral`: los cuatro puntos de [Lo que su proyecto debe lograr](#lo-que-su-proyecto-debe-lograr) |
| Funcionamiento | 15% | Compila, el reporte es correcto e incluye la máquina de la prueba de extensibilidad |
| Presentación | 25% | Claridad del tema académico y de la demostración en su proyecto, dentro de los 10 minutos |
| Respuestas al panel | 10% | Cualquier integrante puede responder sobre cualquier parte del proyecto |
| Colaboración y diagrama | 10% | Commits de todos los integrantes en `semestral` y el fragmento del diagrama |

La calificación máxima es **100**.

---

## Lista de verificación

☐ El fork está sincronizado y `SEMESTRAL.md` está en `main`.  
☐ La rama `semestral` existe y todo el trabajo está ahí.  
☐ El proyecto del tercer parcial, incluida la máquina de la prueba de extensibilidad, funciona.  
☐ Todos los dispositivos se pueden clonar.  
☐ Hay un catálogo de prototipos y la celda se arma con clones.  
☐ Cada clon tiene un dueño mientras la celda lo usa (no hay punteros colgantes).  
☐ Cada dispositivo delega al menos una responsabilidad.  
☐ El reporte es correcto con los clones.  
☐ Compila sin advertencias.  
☐ `diseno_prototipo.png` está en el repositorio.  
☐ `docs/DECISIONES_SEMESTRAL.md` tiene las respuestas a las preguntas guía.  
☐ La documentación de cada máquina y de los componentes generales está actualizada.  
☐ El `README.md` tiene la sección 9.  
☐ Cada integrante tiene commits en `semestral`.  
☐ La presentación está preparada, con el tema asignado.  
☐ Viernes 4: revisión. Sábado 5: entrega en Classroom.