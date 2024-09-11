#ifndef _TREE_
#define _TREE_

#include "obstacle.h"


class Tree : public Obstacle {
    public:
        ~Tree() {}

        Tree(float x, float y) {
            height = 0.6f;
            this->x = x;
            this->y = y;
            exists = true;
            half_bBoxW = 7.0f;
            half_bBoxH = 8.0f;
            TreeTexture.setPallete(TreePallete)
            .setPixels(
                {
                    0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                    0,0,0,0,0,1,2,2,1,0,0,0,0,0,
                    0,0,0,0,0,1,2,2,1,0,0,0,0,0,
                    0,0,0,0,1,2,2,2,2,1,0,0,0,0,
                    0,0,0,0,1,2,2,2,2,1,0,0,0,0,
                    0,0,0,1,2,2,2,2,2,2,1,0,0,0,
                    0,0,0,1,2,2,2,2,2,2,1,0,0,0,
                    0,0,1,2,2,2,2,2,2,2,2,1,0,0,
                    0,0,1,2,2,2,2,2,2,2,2,1,0,0,
                    0,1,2,2,2,2,2,2,2,2,2,2,1,0,
                    0,1,2,2,2,2,2,2,2,2,2,2,1,0,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                    0,0,0,0,0,0,3,3,0,0,0,0,0,0,
                    0,0,0,0,0,3,3,3,3,0,0,0,0,0,
                    0,0,0,0,3,3,3,3,3,3,0,0,0,0,
                });
        }

        
        Nothofagus::ColorPallete TreePallete{
            {0.0, 0.0, 0.0, 0.0}, 
            {0.0, 0.4, 0.0, 1.0}, 
            {0.0, 0.8, 0.0, 1.0}, 
            {0.32, 0.13, 0.06, 1.0}, 
        };

        glm::ivec2 tex_grid = { 14, 16 };
        glm::vec4 tex_back = { 0.5, 0.5, 0.5, 1.0 };
        Nothofagus::Texture TreeTexture = {tex_grid, tex_back};

        
        bool isOutOfBoundaries(float center_y, float threshold);
        bool is_colliding(Player* player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player* player);
        void draw(Nothofagus::Canvas* canvas);
        void addToCanvas(Nothofagus::Canvas* canvas);
        void removeFromCanvas(Nothofagus::Canvas* canvas);


    
}; 

#endif