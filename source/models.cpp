#include <models/models.h>
#include <vector>

//// Tree
bool Tree::isOutOfBoundaries(float center_y, float threshold) {
    if (center_y - y < -threshold)  return true;
    return false;
}


bool Tree::is_colliding(Player& player) {
    if (exists) {
        std::vector<float> p_bbox = player.getBoundingBox();
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

void Tree::interact(Player& player) {
    if (player.isJumping()) {
        if (player.getActualSpeed() <= height) {
            player.crashed();
            this->setExists(false);
        }
    } else {
        player.crashed();
        this->setExists(false);
    }
}

void Tree::addToCanvas(Nothofagus::Canvas& canvas) {
    textureId = canvas.addTexture(TreeTexture);
    bellotaId = canvas.addBellota({ {{x, y}}, textureId});
}

void Tree::removeFromCanvas(Nothofagus::Canvas& canvas) {
    canvas.removeBellota(bellotaId);
    canvas.removeTexture(textureId);
}





//// Flag
bool Flag::isOutOfBoundaries(float center_y, float threshold) {
    if (center_y - y < -threshold)  return true;
    return false;
}

bool Flag::is_colliding(Player& player) {
    if (exists) {
        std::vector<float> p_bbox = player.getBoundingBox();
        float left_c_x = x - half_bBoxW;
        float left_c_y = y - half_bBoxH;
        float right_c_x = x + half_bBoxW;
        float right_c_y = y + half_bBoxH;
        return checkCollision(p_bbox[0], p_bbox[1], p_bbox[2], p_bbox[3],
            left_c_x, left_c_y, right_c_x, right_c_y);
        
    }
    return false;
}

bool Flag::is_colliding(float x1_min, float y1_min, float x2_max, float y2_max) {
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


void Flag::interact(Player& player) {
    if (player.isJumping()) {
        if (player.getActualSpeed() <= height) {
            player.crashed();
            this->setExists(false);
        }
    } else {
        player.crashed();
        this->setExists(false);
    }
}

void Flag::addToCanvas(Nothofagus::Canvas& canvas) {
    textureId = canvas.addTexture(FlagTexture);
    bellotaId = canvas.addBellota({ {{x, y}}, textureId});
}

void Flag::removeFromCanvas(Nothofagus::Canvas& canvas) {
    canvas.removeBellota(bellotaId);
    canvas.removeTexture(textureId);
}





//// Rock
bool Rock::isOutOfBoundaries(float center_y, float threshold) {
    if (center_y - y < -threshold)  return true;
    return false;
}

bool Rock::is_colliding(Player& player) {
    if (exists) {
        std::vector<float> p_bbox = player.getBoundingBox();
        float left_c_x = x - half_bBoxW;
        float left_c_y = y - half_bBoxH;
        float right_c_x = x + half_bBoxW;
        float right_c_y = y + half_bBoxH;
        return checkCollision(p_bbox[0], p_bbox[1], p_bbox[2], p_bbox[3],
            left_c_x, left_c_y, right_c_x, right_c_y);
        
    }
    return false;
}

bool Rock::is_colliding(float x1_min, float y1_min, float x2_max, float y2_max) {
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

void Rock::interact(Player& player) {
    if (player.isJumping()) {
        if (player.getActualSpeed() <= height) {
            player.crashed();
            this->setExists(false);
        }
    } else {
        player.crashed();
        this->setExists(false);
    }
}

void Rock::addToCanvas(Nothofagus::Canvas& canvas) {
    textureId = canvas.addTexture(RockTexture);
    bellotaId = canvas.addBellota({ {{x, y}}, textureId});
}

void Rock::removeFromCanvas(Nothofagus::Canvas& canvas) {
    canvas.removeBellota(bellotaId);
    canvas.removeTexture(textureId);
}