# cpp-problem-solving

Implementación de diversos problemas algorítmicos en C++, abordando estructuras de datos avanzadas y técnicas de optimización. Soluciones basadas en grafos, backtracking, heurísticas y poda alfa-beta, aplicadas a distintos escenarios como rutas, asignación de recursos y cobertura óptima.

# Carpeta 1 - 📚 Sistema de Gestión de Libros con TDA en C++

Este proyecto implementa un sistema de gestión de libros utilizando **Tipos de Datos Abstractos (TDA)** en **C++**, permitiendo almacenar, buscar y filtrar libros basados en diferentes criterios.

## 📌 Descripción

El sistema gestiona una colección de libros, cada uno con atributos como **ISBN, título, autor, año de publicación, país de origen, precio e idiomas disponibles**. Utiliza tres TDA principales para organizar la información:

- **TDA Libro**: Representa un libro con sus atributos y funcionalidades asociadas.
- **TDA Lista**: Estructura parametrizada utilizada para almacenar tanto los libros como los idiomas en los que están disponibles.
- **TDA Colección de Libros**: Permite administrar la lista de libros y realizar operaciones como búsqueda y filtrado.

## 🔍 Funcionalidades Implementadas

1. **Cargar libros desde un archivo CSV** 📂
2. **Buscar un libro por título** 🔎
3. **Listar libros dentro de un rango de fechas** 📅
4. **Obtener los N libros más económicos en un idioma específico** 💰
5. **Mostrar todos los libros disponibles** 📖

## 🛠 Estructura del Código

El sistema se organiza en los siguientes archivos:

- **Libro.h / Libro.cpp**: Definen el TDA **Libro** y sus métodos.
- **Lista.h / Lista.cpp**: Implementan el TDA **Lista**, utilizado como contenedor de libros e idiomas.
- **ColeccionLibros.h / ColeccionLibros.cpp**: Contienen las operaciones sobre la colección de libros.
- **main.cpp**: Punto de entrada de la aplicación.

## 📊 Complejidad de las Funciones

| Función                                                    | Complejidad |
| ---------------------------------------------------------- | ----------- |
| `crearLibro`                                               | O(1)        |
| `recuperarISBN`, `recuperarTitulo`, `recuperarAutor`, etc. | O(1)        |
| `agregarIdioma`                                            | O(1)        |
| `estaIdioma`                                               | O(n)        |
| `mostrarPorFecha`                                          | O(n)        |
| `obtenerEconomico`                                         | O(n \* m)   |
| `verificarLibro`                                           | O(n, k)     |

Donde **n** es la cantidad de libros y **m** la cantidad de idiomas.

# Carpeta 2 - Grafos

Este repositorio contiene la implementación en C++ de la resolución del ejercicio entregable sobre grafos, basado en la consigna proporcionada en la cátedra.

## 📌 Objetivo

Se implementa la clase `Grafo`, junto con los métodos necesarios para resolver dos problemas específicos de rutas en la provincia de Buenos Aires. Además, en cada método se incluye la complejidad temporal del algoritmo utilizado.

## 🚀 Descripción de la Implementación

La solución se divide en dos partes principales:

### 🔹 Parte A: Recorrido Euleriano

Se implementa un algoritmo para encontrar un camino que pase por todas las ciudades cuantas veces sea necesario y que pase por todas las rutas una sola vez. Este problema es abordado mediante la búsqueda de un **camino Euleriano** en un grafo no orientado.

🔹 **Algoritmo utilizado:** Hierholzer para encontrar un camino Euleriano.
🔹 **Complejidad:** O(E), donde E es el número de aristas.

### 🔹 Parte B: Caminos Alternativos

Se implementa un algoritmo que encuentra todos los caminos alternativos posibles entre la ciudad de Buenos Aires y la ciudad de Tandil, considerando que el tramo **Las Flores - Rauch** está cortado.

🔹 **Algoritmo utilizado:** Búsqueda en profundidad (DFS) y búsqueda en anchura (BFS) para encontrar rutas alternativas.
🔹 **Complejidad:** O(V + E), donde V es el número de nodos y E el número de aristas.

## 📂 Estructura del Código

```
📁 cpp-problem-solving
 ├── 📁 2
 │   ├── grafo.h        # Definición de la clase Grafo
 │   ├── grafo.cpp      # Implementación de la clase Grafo
 │   ├── main.cpp       # Archivo principal con la ejecución del programa
 │   ├── utils.h        # Funciones auxiliares
 │   ├── utils.cpp      # Implementación de funciones auxiliares
 │   └── README.md      # (Este archivo)
```

## 📝 Notas

- Se asume que la entrada del grafo se carga desde un archivo o se ingresa manualmente en `main.cpp`.
- Los resultados se imprimen en la consola con suficiente detalle para interpretar la salida.

# Carpeta 3 - Asignación Óptima de Árbitros usando Backtracking

Este proyecto implementa un algoritmo de **Backtracking** para la asignación óptima de árbitros a partidos de fútbol, maximizando la preferencia de los equipos y asegurando que cada árbitro sea asignado a un único partido.

## 📌 Descripción

El problema consiste en asignar árbitros a partidos de fútbol de forma óptima según una matriz de preferencias. Cada equipo tiene una valoración sobre cada árbitro, y el objetivo es encontrar la mejor combinación que maximice el puntaje total de asignación.

## 🔍 Algoritmo Implementado

1. **Entrada de datos**:

   - Lista de equipos y árbitros.
   - Matriz de valoraciones de cada equipo hacia cada árbitro.
   - Jornada definida por el usuario con los enfrentamientos.

2. **Estructuras de datos**:

   - `Equipo`: almacena el nombre y los puntajes de valoración.
   - `Partido`: representa un partido con los equipos y sus valoraciones hacia cada árbitro.
   - `SolucionOptima`: guarda las asignaciones de árbitros y el puntaje total.

3. **Backtracking**:

   - Explora todas las asignaciones posibles de árbitros a partidos.
   - Usa poda para evitar asignaciones inválidas (un árbitro no puede ser asignado a más de un partido).
   - Encuentra la solución factible con el máximo puntaje.

4. **Complejidad**:  
   \( O(\text{#Árbitros}^{\text{#Partidos}} \times \text{#Partidos}) \), donde el número de árbitros es el factor de ramificación y el número de partidos es la profundidad del árbol de búsqueda.

## 📊 Resultados

El algoritmo fue probado con múltiples jornadas, obteniendo los siguientes puntajes máximos:

| Jornada | Partidos Seleccionados           | Puntaje Máximo |
| ------- | -------------------------------- | -------------- |
| 1       | Boca/River, Ind/SL, Racing/Colon | **28.5**       |
| 2       | Boca/River, Colon/SL, Ind/Racing | **27.5**       |
| 3       | Boca/River, SL/Racing, Colon/Ind | **27.5**       |
| 4       | Boca/Colon, SL/Ind, Racing/River | **25**         |
| ...     | ...                              | ...            |

La mejor jornada encontrada fue la **Jornada 1**, con un puntaje de **28.5**.

## 🛠 Instalación y Uso

1. Clona este repositorio:
   ```bash
   git clone https://github.com/tu-usuario/asignacion-arbitros.git
   cd asignacion-arbitros
   ```

# Carpeta 4 - Algoritmo de Aproximación para el Problema de Seguridad Urbana

Este proyecto implementa un algoritmo heurístico de aproximación basado en **Vertex-Cover** para optimizar la colocación de cámaras de seguridad en una ciudad, minimizando la cantidad de esquinas a cubrir mientras se mantiene la vigilancia total.

## 📌 Descripción

El problema consiste en encontrar el menor número de ubicaciones estratégicas para instalar cámaras de seguridad, garantizando que todas las calles estén monitoreadas. Dado que la resolución exacta mediante técnicas como **Backtracking** tiene una complejidad exponencial, se optó por un enfoque de **aproximación** con un factor 2 utilizando **Vertex-Cover**.

## 🔍 Algoritmo Implementado

1. **Modelado del problema como un grafo no dirigido**:

   - Los vértices representan esquinas.
   - Las aristas representan calles conectadas.

2. **Ejecución del algoritmo Vertex-Cover**:

   - Se selecciona una arista arbitraria \((u, v)\).
   - Se agregan ambos vértices al conjunto solución.
   - Se eliminan todas las aristas incidentes en \(u\) y \(v\).
   - Se repite el proceso hasta cubrir todas las aristas.

3. **Complejidad temporal**: \(O(e^2)\), donde \(e\) es el número de aristas.

## 📊 Resultados

El algoritmo fue probado con distintas instancias:

| Instancia  | Vértices | Aristas | Solución Aproximada            | Solución Óptima       |
| ---------- | -------- | ------- | ------------------------------ | --------------------- |
| Pequeña    | 6        | 8       | {a, b, c, d, e, f} (6 cámaras) | {a, d, e} (3 cámaras) |
| Tandil (1) | 66       | 114     | 64 cámaras                     | 33 cámaras            |
| Tandil (2) | 110      | 197     | 110 cámaras                    | 55 cámaras            |
| Tandil (3) | 117      | 206     | 116 cámaras                    | 58 cámaras            |

El error relativo del algoritmo fue **1** en la mayoría de los casos.

## 🛠 Instalación y Uso

1. Clona este repositorio:
   ```bash
   git clone https://github.com/tu-usuario/seguridad-urbana.git
   cd seguridad-urbana
   ```
