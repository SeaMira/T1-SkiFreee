#ifndef _OBSTACLE_
#define _OBSTACLE_

#include "player.h"
#include "utils.h"

#define REMOVED_POINTS 1000

class Obstacle {
    public:
        virtual bool isOutOfBoundaries(float center_y, float threshold) = 0;
        virtual bool is_colliding(Player* player) = 0;
        virtual bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max) = 0;
        virtual void interact(Player* player) = 0;
        virtual void addToCanvas(Nothofagus::Canvas* canvas) = 0;
        virtual void draw(Nothofagus::Canvas* canvas) = 0;
        virtual void removeFromCanvas(Nothofagus::Canvas* canvas) = 0;

        void setPos(const float x, const float y) {
            this->x = x;
            this->y = y;
        }

        std::vector<float> getPos() const {
            return std::vector<float>({x ,y});
        }

        void move(const float x, const float y) {
            this->x += x;
            this->y += y;
        }

        void setExists(bool exists) {
            this->exists = exists;
        }

        bool getExists() {
            return exists;
        }

        float getX() const { return x; }
        float getY() const { return y; }

    protected:

        float half_bBoxW, half_bBoxH;
        float x, y;
        bool exists = false;
        float height;
        Nothofagus::TextureId textureId;
        Nothofagus::BellotaId bellotaId;
};

#endif // _OBSTACLE_