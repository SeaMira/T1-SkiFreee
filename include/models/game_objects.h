
#include <nothofagus.h>
#include <random>
#include <vector>


bool checkCollision(
    float x1_min, float y1_min, float x1_max, float y1_max,
    float x2_min, float y2_min, float x2_max, float y2_max) {
    
    // Verificar si NO están colisionando
    if (x1_max < x2_min || x1_min > x2_max || 
        y1_max < y2_min || y1_min > y2_max) {
        return false;
    }

    // Si ninguna de las condiciones se cumple, están colisionando
    return true;
}

int getRandomInt(int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, max);

    // Generate random number in the range [min, max]
    return distrib(gen);
}

class Player {
    public:
        Player(float x, float y);
        std::vector<float> getBoundingBox();
        std::vector<float> getVelocity();
        void addToCanvas(Nothofagus::Canvas& canvas);
        void removeFromCanvas(Nothofagus::Canvas& canvas);
        void draw(Nothofagus::Canvas& canvas);

        void crashed();
        void checkCrashCounter(const float dt);

        void jumped();
        void checkJumpCounter(const float dt);

        void jump(float h);
        void moveRight();
        void moveLeft();
        void moveFront();


        float getSpeed(const float dt);
        bool setPixelMap(std::initializer_list<Nothofagus::Pixel::ColorId> pixelMap);

    private:
        Nothofagus::ColorPallete PlayerPallete{
        {0.0, 0.0, 0.0, 0.0}, // 0 transparente
        {0.0, 0.0, 1.0, 1.0}, // 1 puntagorro - traje
        {1.0, 0.0, 0.0, 1.0}, // 2 gorro
        {0.32, 0.13, 0.06, 1.0}, // 3 palitos ski
        {0.94, 0.68, 0.58, 1.0}, // 4 piel
        {0.0, 0.0, 0.0, 1.0}, // 5 lentes - ski
        {0.0, 0.8, 0.0, 1.0} // 6 botas
    };

    std::initializer_list<Nothofagus::Pixel::ColorId> frontPixelMap{
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
            };

    std::initializer_list<Nothofagus::Pixel::ColorId> fstDiagPixelMap{
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
            };
            // 0,0,0,0,0,0,0,0,0,0,

    std::initializer_list<Nothofagus::Pixel::ColorId> sndDiagPixelMap{
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
            };
            // 0,0,0,0,0,0,0,0,0,0,

    std::initializer_list<Nothofagus::Pixel::ColorId> sidePixelMap{
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
            };
            // 0,0,0,0,0,0,0,0,0,0,

    // 0 is left
    // 1 left diag
    // 2 left semidiag
    // 3 front  
    // 4 right semidiag
    // 5 right diag
    // 6 is right
    int actual_dir = 3;
    float speed = 0.0f;

    // choque
    float crash_counter = 1.0f;
    bool has_crashed = false;

    // salto
    float jump_counter = 1.0f;
    bool is_jumping = false;

    Nothofagus::Texture playerTexture({ 10, 16 }, { 0.5, 0.5, 0.5, 1.0 });
    float half_bBoxW = 5.0f, half_bBoxH = 8.0f;
    float x, y;
    Nothofagus::TextureId textureId;
    Nothofagus::BellotaId bellotaId;
}

class Obstacle {
    public:
        virtual bool isOutOfBoundaries(std::vector<float> center) = 0;
        virtual bool is_colliding(Player& player) = 0;
        virtual bool is_colliding(float x1_min, float y1_min, float x2_max, float y2_max) = 0;
        virtual void interact(Player& player) = 0;
        virtual void addToCanvas(Nothofagus::Canvas& canvas) = 0;
        virtual void removeFromCanvas(Nothofagus::Canvas& canvas) = 0;
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

    private:

        float half_bBoxW, half_bBoxH;
        float x, y;
        bool exists = false;
        float height;
        Nothofagus::TextureId textureId;
        Nothofagus::BellotaId bellotaId;
};