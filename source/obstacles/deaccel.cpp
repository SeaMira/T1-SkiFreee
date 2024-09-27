#include "obstacles/deaccel.h"

//// Deaccelerator
bool Deaccelerator::isOutOfBoundaries(float center_y, float threshold) {
    if (center_y - y < -threshold)  return true;
    return false;
}

bool Deaccelerator::is_colliding(Player* player) {
    if (exists) {
        std::vector<float> p_bbox = player->getBoundingBox();
        float left_c_x = x - half_bBoxW;
        float left_c_y = y - half_bBoxH;
        float right_c_x = x + half_bBoxW;
        float right_c_y = y + half_bBoxH;
        return checkCollision(p_bbox[0], p_bbox[1], p_bbox[2], p_bbox[3],
            left_c_x, left_c_y, right_c_x, right_c_y);
        
    }
    return false;
}

bool Deaccelerator::is_colliding(float x1_min, float y1_min, float x2_max, float y2_max) {
    if (exists) {
        float left_c_x = x - half_bBoxW;
        float left_c_y = y - half_bBoxH;
        float right_c_x = x + half_bBoxW;
        float right_c_y = y + half_bBoxH;
        return checkCollision(x1_min, y1_min, x2_max, y2_max,
            left_c_x, left_c_y, right_c_x, right_c_y);
        
    }
    return false;
}

void Deaccelerator::interact(Player* player) {
    if (!player->isJumping()) {
        player->setTopSpeed(0.75f*player->getDefaultTopSpeed());
        player->removeStylePoints(1);  
        player->setIsSlowing();    
    } 
}

void Deaccelerator::draw(Nothofagus::Canvas* canvas) {
    Nothofagus::Bellota& deaccelerator = canvas->bellota(bellotaId);
    deaccelerator.transform().location().x = x;
    deaccelerator.transform().location().y = y;
}

void Deaccelerator::addToCanvas(Nothofagus::Canvas* canvas) {
    textureId = canvas->addTexture(DeacceleratorTexture);
    bellotaId = canvas->addBellota({ {{x, y}}, textureId});
}

void Deaccelerator::removeFromCanvas(Nothofagus::Canvas* canvas) {
    canvas->removeBellota(bellotaId);
    canvas->removeTexture(textureId);
}
