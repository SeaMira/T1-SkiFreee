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
                1,1,1,1,1,1,1,1,1,1,
                1,2,1,1,1,1,1,1,2,1,
                1,1,2,1,1,1,1,2,1,1,
                1,1,1,2,1,1,2,1,1,1,
                1,1,2,2,2,2,2,2,1,1,
                1,1,2,2,1,1,2,2,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,2,2,1,1,1,1,
                1,1,1,2,2,2,2,1,1,1,
                1,1,2,2,1,1,2,2,1,1,
                1,1,2,1,1,1,1,2,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
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
        {1.0, 0.0, 0.0, 1.0}, // 1 puntagorro - traje
        {1.0, 1.0, 1.0, 1.0}, // 2 gorro
        
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