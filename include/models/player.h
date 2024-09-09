
#include "game_objects.h"
#include <nothofagus.h>
    

Player::Player() {
    x = 0.0f;
    y = 0.0f;
    setFrontPixelMap();
}

Player::Player(float x, float y): x(x), y(y) {
    setFrontPixelMap();
}

std::vector<float> Player::getBoundingBox() {
    return std::vector<float>({x-half_bBoxW, y-half_bBoxH, x+half_bBoxW, y+half_bBoxH});
}

std::vector<float> Player::getVelocity() {
    float pi = 3.1415f;
    float conv_factor = 180.0f/pi;
    float angle = -(pi*(1-actual_dir/6));
    return std::vector<float>({cos(angle), sin(angle)});
}

void Player::addToCanvas(Nothofagus::Canvas& canvas) {
    textureId = canvas.addTexture(playerTexture);
    bellotaId = canvas.addBellota({ {{x, y}}, textureId});
}


void Player::removeFromCanvas(Nothofagus::Canvas& canvas) {
    canvas.removeBellota(bellotaId);
    canvas.removeTexture(textureId);
}

void Player::draw(Nothofagus::Canvas& canvas) {
    Nothofagus::Bellota& player_obj = canvas.bellota(bellotaId);
    player_obj.transform().location().x = x;
    player_obj.transform().location().y = y;
}

float Player::getSpeed(const float dt) {
    speed = std::min(speed+dt, 1.0f);
    return speed;
}

float Player::getActualSpeed() {
    return speed;
}

void Player::crashed() {
    has_crashed = true;
    crash_counter = 1.0f;
}

bool Player::hasCrashed() {
    return has_crashed;
}

void Player::checkCrashCounter(const float dt) {
    crash_counter = std::max(0.0f, crash_counter-dt);
    if (crash_counter == 0.0f) has_crashed = false;
    else has_crashed = true;
}

void Player::jumped() {
    is_jumping = true;
    jump_counter = speed;
}

bool Player::isJumping() {
    return is_jumping;
}

void Player::checkJumpCounter(const float dt) {
    jump_counter = std::max(0.0f, jump_counter-dt);
    if (jump_counter == 0.0f) is_jumping = false;
    else is_jumping = true;
}

//void Player::setPixelMap(std::initializer_list<Nothofagus::Pixel::ColorId> pixelMap) {
//    playerTexture.setPixelMap(pixelMap);
//}

void Player::jump(float h) {
    is_jumping = true;
    jump_counter = h;
}

void Player::moveRight() {
    if (!is_jumping) actual_dir = std::min(actual_dir+1, 6);
}
void Player::moveLeft() {
    if (!is_jumping) actual_dir = std::max(actual_dir-1, 0);
}
void Player::moveFront() {
    if (!is_jumping) actual_dir = 3;
}

