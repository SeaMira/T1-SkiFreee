#include "audio.h"

constexpr unsigned int sampleRate = 48000;
constexpr unsigned int channels = 2;


void jumpAudio() {
    RustyAudio::Builder jumpSoundBuilder;
    int duration_per_hz = 10;
    for (int i = 0 ; i < 30; i++)
        jumpSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(duration_per_hz, 0.2,  i*50));
    RustyAudio::Buffer jumpSoundBuffer = jumpSoundBuilder.generate(48000, 2);
    RustyAudio::Player soundPlayer;
    soundPlayer.init(jumpSoundBuffer);
    soundPlayer.play();
}

void crashAudio() {
    RustyAudio::Builder crashSoundBuilder;
    crashSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(50, 0.1, 200));
    crashSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(10, 0.1, 0));
    crashSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(200, 0.1, 200));
    RustyAudio::Buffer crashSoundBuffer = crashSoundBuilder.generate(100000, channels);
    RustyAudio::Player soundPlayer;
    soundPlayer.init(crashSoundBuffer);
    soundPlayer.play();
}

void speedUpAudio() {
    RustyAudio::Builder soundBuilder;
    int duration_per_hz = 20;
    for (int i = 0 ; i < 30; i++)
        soundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(duration_per_hz, 0.1,  500*sin((float)i*2.0f*3.1415f/30.0f)));
    RustyAudio::Buffer soundBuffer = soundBuilder.generate(sampleRate, channels);
    RustyAudio::Player soundPlayer;
    soundPlayer.init(soundBuffer);
    soundPlayer.play();
}

void speedDownAudio() {
    RustyAudio::Builder soundBuilder;
    int duration_per_hz = 20;
    for (int i = 0 ; i < 15; i++)
        soundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(duration_per_hz, 0.1,  500*sin(3.1415f/2.0f + (float)i*2.0f*3.1415f/30.0f)));
    RustyAudio::Buffer soundBuffer = soundBuilder.generate(sampleRate, channels);
    RustyAudio::Player soundPlayer;
    soundPlayer.init(soundBuffer);
    soundPlayer.play();

}