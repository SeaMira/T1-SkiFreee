#ifndef _ROCK_
#define _ROCK_

#include "obstacle.h"

class Rock : public Obstacle {
    public:
        ~Rock() {}

        Rock(float x, float y) {
            height = 0.3f;
            exists = true;
            this->x = x;
            this->y = y;
            half_bBoxW = 8.0f;
            half_bBoxH = 6.5f;
            RockTexture.setPallete(RockPallete)
            .setPixels(
                {
                    0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,1,2,2,2,0,0,0,0,0,0,
                    0,0,0,1,1,1,2,3,3,2,2,2,0,0,0,0,
                    0,0,1,2,2,2,3,3,3,3,2,2,2,0,0,0,
                    0,0,1,2,2,3,3,4,4,4,3,2,2,2,0,0,
                    0,0,2,2,3,3,4,4,2,3,4,3,2,3,0,0,
                    0,0,1,2,2,3,4,2,2,2,3,4,3,4,0,0,
                    0,0,0,1,2,2,3,2,2,3,3,3,4,2,2,2,
                    0,1,2,2,1,2,2,2,2,3,3,4,2,2,2,2,
                    1,2,2,2,2,1,2,2,2,3,3,4,2,2,2,2,
                    2,2,2,2,3,2,2,2,2,2,2,3,2,2,2,2,
                    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
                    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
                });
        }
        

        Nothofagus::ColorPallete RockPallete{
            {0.0, 0.0, 0.0, 0.0},
            {0.8, 0.8, 0.8, 1.0},
            {0.6, 0.6, 0.6, 1.0},
            {0.4, 0.4, 0.4, 1.0},
            {0.2, 0.2, 0.2, 1.0}, 
        };

        glm::ivec2 tex_grid = { 16, 13 };
        glm::vec4 tex_back = { 0.5, 0.5, 0.5, 1.0 };
        Nothofagus::Texture RockTexture = { tex_grid , tex_back };

        
        bool isOutOfBoundaries(float center_y, float threshold);
        bool is_colliding(Player* player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player* player);
        void draw(Nothofagus::Canvas* canvas);
        void addToCanvas(Nothofagus::Canvas* canvas);
        void removeFromCanvas(Nothofagus::Canvas* canvas);


    
}; 

#endif // _ROCK_