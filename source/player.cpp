#include <player.h>
    

Player::Player() {
    x = 0.0f;
    y = 0.0f;
    setFrontPixelMap();
}

Player::Player(float x, float y): x(x), y(y) {
    setFrontPixelMap();
    setLFstDiagPixelMap();
    setLSndDiagPixelMap();
    setLSidePixelMap();
    setRFstDiagPixelMap();
    setRSndDiagPixelMap();
    setRSidePixelMap();

    // RustyAudio::Buffer jumpSound = jumpAudio();
    // jumpAudioPlayer.init(jumpSound);
    // RustyAudio::Buffer crashSound = crashAudio();
    // crashAudioPlayer.init(crashSound);
    // RustyAudio::Buffer speedUpSound = speedUpAudio();
    // speedUpAudioPlayer.init(speedUpSound);
    // RustyAudio::Buffer speedDownSound = speedDownAudio();
    // speedDownAudioPlayer.init(speedDownSound);
}

std::vector<float> Player::getBoundingBox() {
    return std::vector<float>({x-half_bBoxW, y-half_bBoxH, x+half_bBoxW, y+half_bBoxH});
}

std::vector<float> Player::getVelocity() {
    float pi = 3.1415f;
    float conv_factor = 180.0f/pi;
    float angle = -(pi*(1.0f-(float)actual_dir/6.0f));
    return std::vector<float>({cos(angle), sin(angle)});
}

void Player::addToCanvas(Nothofagus::Canvas* canvas) {
    textureIdFront = canvas->addTexture(playerTextureFront);
    bellotaIdFront = canvas->addBellota({ {{x, y}}, textureIdFront});
    textureIdFDR = canvas->addTexture(playerTextureFDR);
    bellotaIdFDR = canvas->addBellota({ {{x, y}}, textureIdFDR});
    textureIdSDR = canvas->addTexture(playerTextureSDR);
    bellotaIdSDR = canvas->addBellota({ {{x, y}}, textureIdSDR});
    textureIdRS = canvas->addTexture(playerTextureRS);
    bellotaIdRS = canvas->addBellota({ {{x, y}}, textureIdRS});
    textureIdFDL = canvas->addTexture(playerTextureFDL);
    bellotaIdFDL = canvas->addBellota({ {{x, y}}, textureIdFDL});
    textureIdSDL = canvas->addTexture(playerTextureSDL);
    bellotaIdSDL = canvas->addBellota({ {{x, y}}, textureIdSDL});
    textureIdLS = canvas->addTexture(playerTextureLS);
    bellotaIdLS = canvas->addBellota({ {{x, y}}, textureIdLS});

    actualBellotaId = bellotaIdFront;
}


// void Player::removeFromCanvas(Nothofagus::Canvas* canvas) {
//     canvas->removeBellota(bellotaId);
//     canvas->removeTexture(textureId);
// }

void Player::draw(Nothofagus::Canvas* canvas) {
    Nothofagus::Bellota& player_objf = canvas->bellota(bellotaIdFront);
    player_objf.transform().location().x = x;
    player_objf.transform().location().y = y;
    player_objf.visible() = frontvisible;

    Nothofagus::Bellota& player_obj_fdr = canvas->bellota(bellotaIdFDR);
    player_obj_fdr.transform().location().x = x;
    player_obj_fdr.transform().location().y = y;
    player_obj_fdr.visible() = fdrvisible;

    Nothofagus::Bellota& player_obj_sdr = canvas->bellota(bellotaIdSDR);
    player_obj_sdr.transform().location().x = x;
    player_obj_sdr.transform().location().y = y;
    player_obj_sdr.visible() = sdrvisible;

    Nothofagus::Bellota& player_obj_rs = canvas->bellota(bellotaIdRS);
    player_obj_rs.transform().location().x = x;
    player_obj_rs.transform().location().y = y;
    player_obj_rs.visible() = srvisible;

    Nothofagus::Bellota& player_obj_fdl = canvas->bellota(bellotaIdFDL);
    player_obj_fdl.transform().location().x = x;
    player_obj_fdl.transform().location().y = y;
    player_obj_fdl.visible() = fdlvisible;

    Nothofagus::Bellota& player_obj_sdl = canvas->bellota(bellotaIdSDL);
    player_obj_sdl.transform().location().x = x;
    player_obj_sdl.transform().location().y = y;
    player_obj_sdl.visible() = sdlvisible;

    Nothofagus::Bellota& player_obj_ls = canvas->bellota(bellotaIdLS);
    player_obj_ls.transform().location().x = x;
    player_obj_ls.transform().location().y = y;
    player_obj_ls.visible() = slvisible;
    
}


void Player::setIsAccellerating() {
    is_accellerating = true;
}
void Player::setIsSlowing(){ 
    is_slowing = true;
}
bool Player::getIsAccellerating() {
    return is_accellerating;
}
bool Player::getIsSlowing() {
    return is_slowing;
}

void Player::restoreTopSpeed(float dt) {
    if (top_speed> DEFAULT_TOP_SPEED) top_speed = std::max(top_speed-dt*0.001f, DEFAULT_TOP_SPEED);
    if (top_speed < DEFAULT_TOP_SPEED) top_speed = std::min(top_speed+dt*0.001f, DEFAULT_TOP_SPEED);
    if (speed == DEFAULT_TOP_SPEED) {
        is_accellerating = false;
        is_slowing = false;
    }
}

void Player::setTopSpeed(float speed) {
    top_speed = speed;
}

float Player::getTopSpeed() {
    return top_speed;
}

float Player::getDefaultTopSpeed() {
    return default_top_speed;
}

void Player::setSpeed(const float speed) {
    this->speed = speed;
}

float Player::getSpeed(const float dt) {
    if (actual_dir != 0 && actual_dir != 6)
        speed = std::min(speed+dt*0.06f, top_speed);
    else speed = std::max(speed-dt*0.01f, 0.0f);
    return speed;
}

float Player::getActualSpeed() {
    return speed;
}

void Player::crashed() {
    has_crashed = true;
    crash_counter = 1.0f;
}

bool Player::hasCrashed() {
    return has_crashed;
}

void Player::checkCrashCounter(const float dt) {
    crash_counter = std::max(0.0f, crash_counter-dt);
    if (crash_counter == 0.0f) has_crashed = false;
    else has_crashed = true;
}

void Player::jumped() {
    is_jumping = true;
    jump_counter = speed;
}

bool Player::isJumping() {
    return is_jumping;
}

void Player::stopJump() {
    is_jumping = false;
    jump_counter = 0.0f;
}

void Player::checkJumpCounter(const float dt) {
    jump_counter = std::max(0.0f, jump_counter-dt);
    if (jump_counter == 0.0f) is_jumping = false;
    else is_jumping = true;
}

//void Player::setPixelMap(std::initializer_list<Nothofagus::Pixel::ColorId> pixelMap) {
//    playerTexture.setPixelMap(pixelMap);
//}

void Player::jump(float h) {
    is_jumping = true;
    jump_counter = h;
}

void Player::moveRight() {
    if (!is_jumping) actual_dir = std::min(actual_dir+1, 6);
}
void Player::moveLeft() {
    if (!is_jumping) actual_dir = std::max(actual_dir-1, 0);
}
void Player::moveFront() {
    actual_dir = 3;
}

void Player::setInvisible() {
    frontvisible = false;
    fdrvisible = false;
    sdrvisible = false;
    srvisible = false;
    fdlvisible = false;
    sdlvisible = false;
    slvisible = false;
}

void Player::setActualPixelMap(Nothofagus::Canvas* canvas) {
    setInvisible();
    switch (actual_dir) {
        case 0:
            slvisible = true;
            break;
        case 1:
            sdlvisible = true;
            break;
        case 2:
            fdlvisible = true;
            break;
        case 3:
            frontvisible = true;
            break;
        case 4:
            fdrvisible = true;
            break;
        case 5:
            sdrvisible = true;
            break;
        case 6:
            srvisible = true;
            break;
        default:
            frontvisible = true;
    }
    
}


// void Player::playJumpSound() {
//     jumpAudio();
// }
// void Player::playCrashSound() {
//     crashAudio();
// }
// void Player::playSpeedUpSound() {
//     speedUpAudio();
// }
// void Player::playSpeedDownSound() {
//     speedDownAudio();
// }

void Player::addStylePoints(int p) {
    stylePoints+= p;
}

void Player::removeStylePoints(int p) {
    stylePoints-= p;
}

int Player::getStylePoints() {
    return stylePoints;
}
