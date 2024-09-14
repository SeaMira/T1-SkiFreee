#include "obstacles/tree.h"

//// Tree
bool Tree::isOutOfBoundaries(float center_y, float threshold) {
    if (center_y - y < -threshold)  return true;
    return false;
}


bool Tree::is_colliding(Player* player) {
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

bool Tree::is_colliding(float x1_min, float y1_min, float x2_max, float y2_max) {
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

void Tree::interact(Player* player) {
    if (player->isJumping()) {
        if (player->getActualSpeed() <= height) {
            player->removeStylePoints(REMOVED_POINTS);
            player->crashed();
            player->setSpeed(0.0f);
            this->setExists(false);
        } else player->addStylePoints(1);
    } else {
        player->removeStylePoints(REMOVED_POINTS);
        player->crashed();
        this->setExists(false);
    }
}

void Tree::draw(Nothofagus::Canvas* canvas) {
    Nothofagus::Bellota& tree = canvas->bellota(bellotaId);
    tree.transform().location().x = x;
    tree.transform().location().y = y;
}

void Tree::addToCanvas(Nothofagus::Canvas* canvas) {
    textureId = canvas->addTexture(TreeTexture);
    bellotaId = canvas->addBellota({ {{x, y}}, textureId});
}

void Tree::removeFromCanvas(Nothofagus::Canvas* canvas) {
    canvas->removeBellota(bellotaId);
    canvas->removeTexture(textureId);
}
