
#include <iostream>
#include "CBeeper.h"

int main(int argc, char* argv[])
{


    int duration = 100;
    double Hz = 440;

//    Beeper b;
//    b.beep(Hz, duration);
//    b.wait();

//      Nightwish - Nemo
//    b.beep(587,duration);   b.wait();
//    b.beep(587,duration);   b.wait();
//    b.beep(523,duration);   b.wait();
//    b.beep(587,duration);   b.wait();
//    b.beep(440,duration);   b.wait();
//
//    b.beep(587,duration);   b.wait();
//    b.beep(587,duration);   b.wait();
//    b.beep(523,duration);   b.wait();
//    b.beep(587,duration);   b.wait();
//    b.beep(349,duration);   b.wait();
//
//    b.beep(523,duration);   b.wait();
//    b.beep(523,duration);   b.wait();
//    b.beep(587,duration);   b.wait();
//    b.beep(440,duration);   b.wait();
//    b.beep(392,duration);   b.wait();
//
//    b.beep(349,duration);   b.wait();
//    b.beep(330,duration);   b.wait();
//    b.beep(262,duration);   b.wait();
//    b.beep(294,duration);   b.wait();

//    int sheet_array[] = {587, 587, 523, 587, 440, 587, 523, 587, 349, 523, 523, 587, 440, 392, 349, 330, 262, 294};
    std::vector<int> nemo = {587, 587, 523, 587, 440, 587, 587, 523, 587, 349, 523, 523, 587, 440, 392, 349, 330, 262, 294};

    std::vector<int> starwars = {392, 392, 392, 311, 466, 392, 311, 466, 392, 587, 587, 587, 622, 466, 370, 311, 466, 392,
                                784, 392, 392, 784, 740, 698, 659, 622, 659, 415, 554, 523, 494, 466, 440, 466, 311, 370, 311, 370};

    std::vector<int> got = {392, 262, 262, 349, 392, 262, 262, 311, 294, 349, 233, 233, 311, 349, 233, 311, 294, 262, 392, 262, 262, 349, 392, 262, 262, 311, 294, 349, 233, 294, 311, 294, 233, 262};

//    beepSheet(starwars);

    std::string game_of_thrones = "G4 C4 C4 F4 G4 C4 C4 D#4 D4 F4 A#3 A#3 D#4 F4 A#3 D#4 D4 C4 F4 A#3 D4 D#4 D4 A#3 C4";

    std::string all = "C3 D3 E3 F3 G3 A3 B3 C4 D4 E4 F4 G4 A4 B4 C5 D5 E5 F5 G5 A5 B5 C6 D6 E6 F6 G6 A6 B6";

//    std::string game = "A-4 D-4 F-8 G-8 A-4 D-4 F-8 G-8 A-4 D-4 F#-8 G#-8 A-4 D-4 F#-8 G#-8 A-6 D-6 F-8 G-8 A-2 D-2 F-8 G-8 E-2 E-2 G-2 C-2 F-8 E-8 G-2 C-2 F-8 E-8 D-2 D-2";

    std::string sheet = "";

    CBeeper beeper(all, 1000);

    beeper.play();

    return 0;
}
