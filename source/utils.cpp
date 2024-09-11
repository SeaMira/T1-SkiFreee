#include "utils.h"

std::random_device rd;
std::mt19937 gen(rd());


bool checkCollision(float x1_min, float y1_min, float x1_max, float y1_max,
                    float x2_min, float y2_min, float x2_max, float y2_max) {
    // Verificar si NO están colisionando
    if (x1_max < x2_min || x1_min > x2_max || 
        y1_max < y2_min || y1_min > y2_max) {
        return false;
    }

    // Si ninguna de las condiciones se cumple, están colisionando
    return true;
}

int getRandomInt(int max) {
    std::uniform_int_distribution<int> distrib(0, max);
    return distrib(gen);
}

int getRandomInt(int min, int max) {
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}