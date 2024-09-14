#ifndef _ENEMY_
#define _ENEMY_

#include <nothofagus.h>
#include <vector>


class Enemy {
    public:
        Enemy();
        Enemy(float x, float y, float apparition_time): x(x), y(y), apparition_time(apparition_time) {
        enemyTexture.setPallete(EnemyPallete)
            .setPixels({
                0,0,0,0,0,1,1,0,0,0,
                0,3,0,0,0,1,1,0,3,0,
                3,3,3,0,2,2,0,3,3,3,
                0,3,0,2,2,2,2,0,3,0,
                0,3,0,4,4,4,4,0,3,0,
                0,3,0,5,5,5,5,0,3,0,
                0,3,1,4,4,4,4,0,3,0,
                1,1,1,1,4,4,1,1,1,1,
                0,1,1,1,1,1,1,1,1,0,
                0,4,4,1,1,1,1,4,4,0,
                5,4,4,1,1,1,1,4,4,5,
                5,1,1,1,1,1,1,1,1,5,
                6,1,1,1,0,0,1,1,1,6,
                6,6,0,0,0,0,0,0,6,6,
                5,5,0,0,0,0,0,0,5,5,
                5,5,0,0,0,0,0,0,5,5,
                });
    }
        std::vector<float> getVelocity();
        void addToCanvas(Nothofagus::Canvas* canvas);
        void draw(Nothofagus::Canvas* canvas);
        void move(float x, float y, float dx, float dy, float dt);
        bool checkExistence(float dt);
        bool hasCaughtPlayer(float x, float y);

        float getX() {return x;}
        float getY() {return y;}


        // bool setPixelMap(std::initializer_list<Nothofagus::Pixel::ColorId> pixelMap);

    private:
        Nothofagus::ColorPallete EnemyPallete{
        {0.0, 0.0, 0.0, 0.0}, // 0 transparente
        {0.0, 0.0, 1.0, 1.0}, // 1 puntagorro - traje
        {1.0, 0.0, 0.0, 1.0}, // 2 gorro
        {0.32, 0.13, 0.06, 1.0}, // 3 palitos ski
        {0.94, 0.68, 0.58, 1.0}, // 4 piel
        {0.0, 0.0, 0.0, 1.0}, // 5 lentes - ski
        {0.0, 0.8, 0.0, 1.0} // 6 botas
    };

    float x, y;
    float speed = 0.9f;
    
    float total_time = 0.0f, apparition_time = 0.0f;

    glm::ivec2 tex_grid = { 10, 16 };
    glm::vec4 tex_back = { 0.5, 0.5, 0.5, 1.0 };
    Nothofagus::Texture enemyTexture = { tex_grid, tex_back };
    
    Nothofagus::TextureId textureId;
    Nothofagus::BellotaId bellotaId;
};

#endif // _PLAYER_