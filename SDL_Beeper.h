#ifndef SDL_BEEPER_H
#define SDL_BEEPER_H

#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <queue>
#include <cmath>

const int AMPLITUDE = 14000;
const int FREQUENCY = 24100;

struct BeepObject
{
    double freq;
    int samplesLeft;
};

void audio_callback(void*, Uint8*, int);

class SDL_Beeper
{
private:
    double v;
    std::queue<BeepObject> beeps;
public:
    SDL_Beeper();
    ~SDL_Beeper();
    void Beep(double freq, int duration)
    {
        beep(freq, duration);
        wait();
    }
    void beep(double freq, int duration);
    void generateSamples(Sint16 *stream, int length);
    void wait();
};

#endif // SDL_BEEPER_H
