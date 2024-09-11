#ifndef _UTILS_
#define _UTILS_

#include <random>

// Declaraciones de las funciones
bool checkCollision(float x1_min, float y1_min, float x1_max, float y1_max,
                    float x2_min, float y2_min, float x2_max, float y2_max);

int getRandomInt(int max);
int getRandomInt(int min, int max);

#endif // _UTILS_
