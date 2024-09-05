#ifndef _MODELS_
#define _MODELS_


#include "game_objects.h"



class Tree : public Obstacle {
    public:
        ~Tree() {}

        Tree() {
            height = 0.6f;
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

        Nothofagus::Texture TreeTexture({ 14, 16 }, { 0.5, 0.5, 0.5, 1.0 });

        
        bool isOutOfBoundaries(float center_y, float threshold);
        bool is_colliding(Player& player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player& player);
        void addToCanvas(Nothofagus::Canvas& canvas);
        void removeFromCanvas(Nothofagus::Canvas& canvas);


    
}; 


class Flag : public Obstacle {

    public:
        ~Flag() {}
        Flag() {
            height = 0.5f;
            exists = true;
            half_bBoxW = 4.0f;
            half_bBoxH = 8.0f;
            int color_pallete = getRandomInt(1);
            Nothofagus::ColorPallete pallete;
            switch (color_pallete) {
                case 0:
                    pallete = BlueFlagPallete;
                    break;
                case 1:
                    pallete = OrangeFlagPallete;
                    break;
                case 2:
                    pallete = BlueFlagPallete;
            }

            FlagTexture.setPallete(pallete)
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


        Nothofagus::Texture FlagTexture({ 8, 16 }, { 0.5, 0.5, 0.5, 1.0 });

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
        bool is_colliding(Player& player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player& player);
        void addToCanvas(Nothofagus::Canvas& canvas);
        void removeFromCanvas(Nothofagus::Canvas& canvas);


}; 



class Rock : public Obstacle {
    public:
        ~Rock() {}

        Rock() {
            height = 0.3f;
            exists = true;
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

        Nothofagus::Texture RockTexture({ 16, 13 }, { 0.5, 0.5, 0.5, 1.0 });

        
        bool isOutOfBoundaries(float center_y, float threshold);
        bool is_colliding(Player& player);
        bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max);
        void interact(Player& player);
        void addToCanvas(Nothofagus::Canvas& canvas);
        void removeFromCanvas(Nothofagus::Canvas& canvas);


    
}; 

#endif // _MODELS_