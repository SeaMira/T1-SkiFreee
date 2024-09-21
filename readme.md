# SkiFree

Este proyecto es una réplica del clásico juego de SkiFree, donde el jugador controla un esquiador que debe esquivar obstáculos y enemigos mientras se desliza cuesta abajo en un entorno nevado. El juego se desarrolla en C++ utilizando varias bibliotecas personalizadas para gráficos y audio, así como una estructura modular que facilita la creación y manejo de personajes, enemigos, obstáculos, y sonidos.

## Descripción del Juego

En SkiFree Replica, controlas a un esquiador que se desliza por una pendiente nevada. Tu objetivo es esquivar obstáculos y enemigos mientras avanzas. A medida que el jugador se desplaza, puede acelerar, desacelerar, y realizar saltos para evitar choques.

El juego está basado en un sistema de coordenadas donde se actualiza el estado del jugador y del enemigo con cada fotograma. Hay un sistema de puntuación basado en la distancia recorrida y un contador de estilo que refleja las maniobras realizadas.

## Controles del juego

- W, A, S, D: Control del movimiento del esquiador.
- SPACE: Saltar.
- ENTER: Pausar el juego.
- ESCAPE: Salir del juego.

## Características Principales

- Gráficos y animación: Uso de la biblioteca Nothofagus para manejar el lienzo de juego y los elementos gráficos.
- Manejo de sonido: Generación y reproducción de sonidos mediante la librería RustyAudio, con efectos de sonido dinámicos para saltos, choques y cambios de velocidad.
- Enemigos y obstáculos: Se generan enemigos y obstáculos que el jugador debe esquivar. Los enemigos tienen comportamientos de aparición aleatoria, aumentando la dificultad del juego a medida que el jugador avanza.
- Sistema de puntuación: Se mide el tiempo jugado, la velocidad del esquiador, la distancia recorrida, y se asignan puntos por estilo.

## Tecnologías Utilizadas

- C++: Lenguaje de programación principal.
- Nothofagus: Biblioteca personalizada para gráficos y control de entrada.
- RustyAudio: Biblioteca utilizada para la generación y reproducción de sonidos.
- ImGui: Utilizada para la interfaz gráfica de usuario (mostrar tiempo, velocidad, y otros elementos de la HUD).

## Instalación y Uso

### Requisitos previos

- CMake 3.20 o superior.
- Compilador C++17 o superior (p.ej. g++, clang, o MSVC).

### Instrucciones de instalación

Clona este repositorio:

```bash
git clone https://github.com/tu-usuario/T1-SkiFreee.git
cd T1-SkiFreee
```

Asegúrate de tener configurado un entorno de desarrollo con soporte para C++17 o superior.
Compila el proyecto utilizando tu compilador preferido. Para generar los archivos se puede hacer en modo release con Ninja.

```bash
cmake --preset ninja-release
```

Esto generará una carpeta llamada skifree_build_cmake con una carpeta llamada ninja-release con los archivos generados dentro de ella. Para compilar y ejecutar:

```bash
cd ../skifree_build_cmake/ninja-release
ninja
./skifree.exe
```

O en modo debug para Visual Studio:

```bash
cmake --preset vs-debug
```

Generando los archivos en skifree_build_cmake/vs-debug.

## Author

Sebastián Mira Pacheco
