#ifndef _ACCEL_
#define _ACCEL_

#include "obstacle.h"

class Accelerator : public Obstacle {

    public:
        ~Accelerator() {}
        Accelerator(float x, float y) {
            height = 0.2f;
            exists = true;
            this->x = x;
            this->y = y;
            half_bBoxW = 8.0f;
            half_bBoxH = 8.0f;
            
            AcceleratorTexture.setPallete(AcceleratorPallete)
                .setPixels(
                    {
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        2,1,0,0,0,0,0,0,0,0,0,0,0,0,1,2,
                        0,2,1,0,0,0,0,0,0,0,0,0,0,1,2,0,
                        1,0,2,1,0,0,0,0,0,0,0,0,1,2,0,1,
                        2,1,0,2,1,0,0,0,0,0,0,1,2,0,1,2,
                        0,2,1,0,2,1,0,0,0,0,1,2,0,1,2,0,
                        1,0,2,1,0,2,1,0,0,1,2,0,1,2,0,1,
                        2,1,0,2,1,0,2,1,1,2,0,1,2,0,1,2,
                        0,2,1,0,2,1,0,2,2,0,1,2,0,1,2,0,
                        0,0,2,1,0,2,1,0,0,1,2,0,1,2,0,0,
                        0,0,0,2,1,0,2,1,1,2,0,1,2,0,0,0,
                        0,0,0,0,2,1,0,2,2,0,1,2,0,0,0,0,
                        0,0,0,0,0,2,1,0,0,1,2,0,0,0,0,0,
                        0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    }
                    );
                    

        }

        glm::ivec2 tex_grid = { 16, 16 };
        glm::vec4 tex_back = { 0.5, 0.5, 0.5, 1.0 };
        Nothofagus::Texture AcceleratorTexture = {tex_grid, tex_back};

        Nothofagus::ColorPallete AcceleratorPallete{
            {0.0, 0.0, 0.0, 0.0}, // 0 transparente
            {1.0, 0.5, 0.0, 1.0},
            {1.0, 0.0, 0.0, 1.0},
        };
        

        bool isOutOfBoundaries(float center_y, float threshold);
        bool is_colliding(Player* player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player* player);
        void draw(Nothofagus::Canvas* canvas);
        void addToCanvas(Nothofagus::Canvas* canvas);
        void removeFromCanvas(Nothofagus::Canvas* canvas);


}; 

#endif // _ACCEL_