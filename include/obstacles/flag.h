#ifndef _FLAG_
#define _FLAG_

#include "obstacle.h"

class Flag : public Obstacle {

    public:
        ~Flag() {}
        Flag(float x, float y) {
            height = 0.5f;
            exists = true;
            this->x = x;
            this->y = y;
            half_bBoxW = 4.0f;
            half_bBoxH = 8.0f;
            int color_pallete = getRandomInt(1);
            //Nothofagus::ColorPallete pallete;
            switch (color_pallete) {
                case 0:
                    //pallete = BlueFlagPallete;
                    FlagTexture.setPallete(BlueFlagPallete)
                        .setPixels(
                            {
                                0,0,0,0,0,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,1,1,1,1,0,
                                0,0,1,1,1,1,1,0,
                                0,1,1,1,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,2,2,2,2,2,
                            });
                    break;
                case 1:
                    //pallete = OrangeFlagPallete;
                    FlagTexture.setPallete(OrangeFlagPallete)
                        .setPixels(
                            {
                                0,0,0,0,0,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,1,1,1,1,0,
                                0,0,1,1,1,1,1,0,
                                0,1,1,1,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,2,2,2,2,2,
                            });

                    break;
                case 2:
                    //pallete = BlueFlagPallete;
                    FlagTexture.setPallete(BlueFlagPallete)
                        .setPixels(
                            {
                                0,0,0,0,0,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,1,1,1,1,0,
                                0,0,1,1,1,1,1,0,
                                0,1,1,1,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,0,1,1,1,0,
                                0,0,0,2,2,2,2,2,
                            });
            }

        }

        glm::ivec2 tex_grid = { 8, 16 };
        glm::vec4 tex_back = { 0.5, 0.5, 0.5, 1.0 };
        Nothofagus::Texture FlagTexture = {tex_grid, tex_back};

        Nothofagus::ColorPallete BlueFlagPallete{
            {0.0, 0.0, 0.0, 0.0}, 
            {0.4, 0.4, 1.0, 1.0}, 
            {0.2, 0.2, 0.8, 1.0}, 
        };
        Nothofagus::ColorPallete OrangeFlagPallete{
            {0.0, 0.0, 0.0, 0.0}, 
            {1.0, 0.5, 0.0, 1.0}, 
            {0.8, 0.4, 0.0, 1.0}, 
        };

        bool isOutOfBoundaries(float center_y, float threshold);
        bool is_colliding(Player* player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player* player);
        void draw(Nothofagus::Canvas* canvas);
        void addToCanvas(Nothofagus::Canvas* canvas);
        void removeFromCanvas(Nothofagus::Canvas* canvas);


}; 

#endif // _FLAG_