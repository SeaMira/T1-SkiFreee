#ifndef _PLAYER_
#define _PLAYER_

#include <nothofagus.h>
#include "audio.h"
#include <vector>




class Player {
    public:
        Player();
        Player(float x, float y);
        std::vector<float> getBoundingBox();
        std::vector<float> getVelocity();
        void addToCanvas(Nothofagus::Canvas* canvas);
        void setInvisible();
        void removeFromCanvas(Nothofagus::Canvas* canvas);
        void draw(Nothofagus::Canvas* canvas);

        void crashed();
        bool hasCrashed();
        void checkCrashCounter(const float dt);

        void restoreTopSpeed(float dt);
        void setTopSpeed(float speed);

        void jumped();
        bool isJumping();
        void stopJump();
        void checkJumpCounter(const float dt);

        void jump(float h);
        void moveRight();
        void moveLeft();
        void moveFront();


        void setSpeed(const float speed);
        float getSpeed(const float dt);
        float getActualSpeed();
        void setActualPixelMap(Nothofagus::Canvas* canvas);

        void playJumpSound();
        void playCrashSound();
        void playSpeedUpSound();
        void playSpeedDownSound();

        void addStylePoints(int p);
        void removeStylePoints(int p);
        int getStylePoints();

        // bool setPixelMap(std::initializer_list<Nothofagus::Pixel::ColorId> pixelMap);

    protected:
        Nothofagus::ColorPallete PlayerPallete{
        {0.0, 0.0, 0.0, 0.0}, // 0 transparente
        {0.0, 0.0, 1.0, 1.0}, // 1 puntagorro - traje
        {1.0, 0.0, 0.0, 1.0}, // 2 gorro
        {0.32, 0.13, 0.06, 1.0}, // 3 palitos ski
        {0.94, 0.68, 0.58, 1.0}, // 4 piel
        {0.0, 0.0, 0.0, 1.0}, // 5 lentes - ski
        {0.0, 0.8, 0.0, 1.0} // 6 botas
    };

    void setFrontPixelMap() {
        playerTextureFront.setPallete(PlayerPallete)
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

    void setRFstDiagPixelMap() {
        playerTextureFDR.setPallete(PlayerPallete)
            .setPixels({
            1,1,2,2,2,2,0,0,0,0,
            1,1,0,2,2,2,2,0,0,0,
            0,0,0,2,2,4,4,0,0,3,
            0,0,0,4,5,5,5,0,0,3,
            0,0,0,0,4,4,5,0,0,3,
            0,0,0,1,4,4,4,3,0,3,
            0,0,0,1,1,1,3,0,0,3,
            0,0,1,1,1,3,1,1,0,3,
            0,0,1,1,4,1,1,1,4,4,
            0,0,0,4,4,1,1,0,4,4,
            0,0,3,1,1,1,1,1,0,3,
            5,3,0,1,1,6,1,1,3,3,
            3,5,6,6,0,5,6,6,0,3,
            0,3,5,6,0,0,5,5,0,0,
            0,0,0,5,0,0,0,0,5,0,
            0,0,0,0,5,0,0,0,0,5,
                });
    }


    void setRSndDiagPixelMap() {
        playerTextureSDR.setPallete(PlayerPallete)
            .setPixels({
                0,0,2,2,0,0,0,0,0,0,
                1,1,0,2,2,2,0,0,0,0,
                1,1,0,2,2,2,2,0,0,0,
                0,0,0,2,2,4,4,0,0,3,
                0,0,0,4,5,5,5,0,0,3,
                0,0,0,0,4,4,5,0,0,3,
                0,0,0,3,4,4,4,0,0,3,
                0,0,0,3,1,1,1,0,0,3,
                0,0,1,3,1,1,1,1,0,3,
                0,0,1,3,4,1,1,1,4,4,
                0,0,0,4,4,1,1,0,4,4,
                0,0,0,3,1,1,1,1,0,3,
                0,0,0,3,1,6,1,1,3,3,
                5,0,3,3,3,5,6,6,0,3,
                5,5,5,6,0,0,5,5,5,0,
                0,0,5,5,5,5,0,0,5,5,
                });
    }


    void setRSidePixelMap() {
        playerTextureRS.setPallete(PlayerPallete)
            .setPixels({
                0,0,2,2,0,0,0,0,0,0,
                1,1,0,2,2,2,0,0,0,0,
                1,1,0,2,2,2,2,0,0,0,
                0,0,0,2,2,4,4,0,0,3,
                0,0,0,4,5,5,5,0,0,3,
                0,0,0,0,4,4,4,0,0,3,
                0,0,0,3,4,4,4,0,0,3,
                0,0,0,3,1,1,1,0,0,3,
                0,0,1,3,1,1,1,1,0,3,
                0,0,1,3,4,1,1,1,4,4,
                0,0,0,4,4,1,1,0,4,4,
                0,0,0,3,1,1,1,1,0,3,
                0,0,0,3,1,6,1,1,3,3,
                0,0,3,3,3,5,6,6,0,3,
                5,5,6,3,6,5,5,5,5,5,
                5,5,5,5,5,5,5,5,5,0,
                });
    }
    

    void setLFstDiagPixelMap() {
        playerTextureFDL.setPallete(PlayerPallete)
            .setPixels({
            0,0,0,0,2,2,2,2,1,1,
            0,0,0,2,2,2,2,0,1,1,
            3,0,0,4,4,2,2,0,0,0,
            3,0,0,5,5,5,4,0,0,0,
            3,0,0,5,4,4,0,0,0,0,
            3,0,3,4,4,4,1,0,0,0,
            3,0,0,3,1,1,1,1,0,0,
            3,0,1,1,3,1,1,1,0,0,
            4,4,1,1,1,4,1,1,0,0,
            4,4,0,1,1,1,4,4,0,0,
            3,0,1,1,1,1,1,1,3,0,
            3,3,1,1,6,1,1,0,3,5,
            3,0,6,6,5,0,6,6,5,3,
            0,0,5,5,0,0,6,5,3,0,
            0,5,0,0,0,0,5,0,0,0,
            5,0,0,0,0,0,5,0,0,0,

                });
    }


    void setLSndDiagPixelMap() {
        playerTextureSDL.setPallete(PlayerPallete)
            .setPixels({
                0,0,0,0,0,0,2,2,0,0,
                0,0,0,0,2,2,2,0,1,1,
                0,0,0,2,2,2,2,0,1,1,
                3,0,0,4,4,2,2,0,0,0,
                3,0,0,5,5,5,4,0,0,0,
                3,0,0,5,4,4,0,0,0,0,
                3,0,0,4,4,4,3,0,0,0,
                3,0,0,1,1,1,3,0,0,0,
                3,0,1,1,1,1,3,1,0,0,
                4,4,1,1,1,4,3,1,0,0,
                4,4,0,1,1,4,4,0,0,0,
                3,0,1,1,1,1,1,3,0,0,
                3,3,1,1,6,1,1,3,0,0,
                3,0,6,6,5,3,3,3,0,5,
                0,5,5,5,0,0,6,5,5,5,
                5,5,0,0,5,5,5,5,5,0,

                });
    }




    void setLSidePixelMap() {
        playerTextureLS.setPallete(PlayerPallete)
            .setPixels({
                0,0,0,0,0,0,0,2,2,0,
                0,0,0,0,2,2,2,0,1,1,
                0,0,0,2,2,2,2,0,1,1,
                3,0,0,4,4,2,2,0,0,0,
                3,0,0,5,5,5,4,0,0,0,
                3,0,0,4,4,4,0,0,0,0,
                3,0,0,4,4,4,3,0,0,0,
                3,0,0,1,1,1,3,0,0,0,
                3,0,1,1,1,1,3,1,0,0,
                4,4,1,1,1,4,3,1,0,0,
                4,4,0,1,1,4,4,0,0,0,
                3,0,1,1,1,1,1,3,0,0,
                3,3,1,1,6,1,1,3,0,0,
                3,0,6,6,5,3,3,3,0,0,
                5,5,5,5,5,5,6,3,6,5,
                0,5,5,5,5,5,5,5,5,5,

                });
    }


    // 0 is left
    // 1 left diag
    // 2 left semidiag
    // 3 front  
    // 4 right semidiag
    // 5 right diag
    // 6 is right
    int actual_dir = 3;
    float speed = 0.0f;
    float top_speed = 1.0f;

    // choque
    float crash_counter = 1.0f;
    bool has_crashed = false;

    // salto
    float jump_counter = 1.0f;
    bool is_jumping = false;
    float half_bBoxW = 5.0f, half_bBoxH = 8.0f;
    float x, y;

    glm::ivec2 tex_grid = { 10, 16 };
    glm::vec4 tex_back = { 0.5, 0.5, 0.5, 1.0 };
    Nothofagus::Texture playerTextureFront = { tex_grid, tex_back };
    Nothofagus::Texture playerTextureFDR = { tex_grid, tex_back };
    Nothofagus::Texture playerTextureSDR = { tex_grid, tex_back };
    Nothofagus::Texture playerTextureRS = { tex_grid, tex_back };
    Nothofagus::Texture playerTextureFDL = { tex_grid, tex_back };
    Nothofagus::Texture playerTextureSDL = { tex_grid, tex_back };
    Nothofagus::Texture playerTextureLS = { tex_grid, tex_back };

    Nothofagus::TextureId textureIdFront;
    Nothofagus::BellotaId bellotaIdFront;
    bool frontvisible = true;
    Nothofagus::TextureId textureIdFDR;
    Nothofagus::BellotaId bellotaIdFDR;
    bool fdrvisible = false;
    Nothofagus::TextureId textureIdSDR;
    Nothofagus::BellotaId bellotaIdSDR;
    bool sdrvisible = false;
    Nothofagus::TextureId textureIdRS;
    Nothofagus::BellotaId bellotaIdRS;
    bool srvisible = false;
    Nothofagus::TextureId textureIdFDL;
    Nothofagus::BellotaId bellotaIdFDL;
    bool fdlvisible = false;
    Nothofagus::TextureId textureIdSDL;
    Nothofagus::BellotaId bellotaIdSDL;
    bool sdlvisible = false;
    Nothofagus::TextureId textureIdLS;
    Nothofagus::BellotaId bellotaIdLS;
    bool slvisible = false;

    Nothofagus::BellotaId actualBellotaId;


    RustyAudio::Player jumpAudioPlayer;
    RustyAudio::Player crashAudioPlayer;
    RustyAudio::Player speedUpAudioPlayer;
    RustyAudio::Player speedDownAudioPlayer;
        
    int stylePoints = 0;
};

#endif // _PLAYER_