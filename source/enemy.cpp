#include "enemy.h"
#include <iostream>



void Enemy::addToCanvas(Nothofagus::Canvas* canvas) {
    textureId = canvas->addTexture(enemyTexture);
    bellotaId = canvas->addBellota({ {{x, y}}, textureId});
}

void Enemy::draw(Nothofagus::Canvas* canvas) {
    Nothofagus::Bellota& enemy = canvas->bellota(bellotaId);
    enemy.transform().location().x = x;
    enemy.transform().location().y = y;
}

void Enemy::move(float x, float y, float dx, float dy, float dt) {
    float dir_x = x - this->x;
    float dir_y = y - this->y;
    float dir = sqrt(dir_x*dir_x + dir_y*dir_y);
    // std::cout << "x: " << dir_x << " y: " << y << " dir: " << dir << std::endl;
    if (dir != 0.0f) {
        dir_x /= dir;
        dir_y /= dir;
    }
    this->x += dir_x*speed*dt*0.06f + dx;
    this->y += dir_y*speed*dt*0.06f + dy;
}

bool Enemy::checkExistence(float dt) {
    total_time += dt;
    if (total_time > apparition_time) {
        return true;
    }
    return false;
}

bool Enemy::hasCaughtPlayer(float x, float y) {
    float dir_x = x - this->x;
    float dir_y = y - this->y;
    return dir_x*dir_x + dir_y*dir_y <= 4.0f;
}