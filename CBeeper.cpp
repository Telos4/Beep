/**
  *	@author: Simon Pirkelmann
  */
#include "CBeeper.h"

CBeeper::CBeeper ( const std::string & sheet , int max_len)
{
    //ctor
    max_length = max_len;

    // Creating a dictionary of notes and their corresponding frequencies (should better be done globally)
    freqs["C3"] = 130.813f;
    freqs["C#3"] = freqs["Db3"] = 138.591f;
    freqs["D3"] = 146.832f;
    freqs["D#3"] = freqs["Eb3"] = 155.563f;
    freqs["E3"] = 164.814f;
    freqs["F3"] = 174.614f;
    freqs["F#3"] = freqs["Gb3"] = 184.997f;
    freqs["G3"] = 195.998f;
    freqs["G#3"] = freqs["Ab3"] = 207.652f;
    freqs["A3"] = 220.000f;
    freqs["A#3"] = freqs["Bb3"] = 233.082f;
    freqs["B3"] = 246.942f;

    freqs["C4"] = 261.626f;
    freqs["C#4"] = freqs["Db4"] = 277.183f;
    freqs["D4"] = 293.665f;
    freqs["D#4"] = freqs["Eb4"] = 311.127f;
    freqs["E4"] = 329.628f;
    freqs["F4"] = 349.228f;
    freqs["F#4"] = freqs["Gb4"] = 369.994f;
    freqs["G4"] = 391.995f;
    freqs["G#4"] = freqs["Ab4"] = 415.305f;
    freqs["A4"] = 440.000f;
    freqs["A#4"] = freqs["Bb4"] = 466.164f;
    freqs["B4"] = 493.883f;

    freqs["C"] = 261.626f;
    freqs["C#"] = freqs["Db"] = 277.183f;
    freqs["D"] = 293.665f;
    freqs["D#"] = freqs["Eb"] = 311.127f;
    freqs["E"] = 329.628f;
    freqs["F"] = 349.228f;
    freqs["F#"] = freqs["Gb"] = 369.994f;
    freqs["G"] = 391.995f;
    freqs["G#"] = freqs["Ab"] = 415.305f;
    freqs["A"] = 440.000f;
    freqs["A#"] = freqs["Bb"] = 466.164f;
    freqs["B"] = 493.883f;

    freqs["C5"] = 523.251f;
    freqs["C#5"] = freqs["Db5"] = 554.365f;
    freqs["D5"] = 587.330f;
    freqs["D#5"] = freqs["Eb5"] = 622.254f;
    freqs["E5"] = 659.255f;
    freqs["F5"] = 698.456f;
    freqs["F#5"] = freqs["Gb5"] = 739.989f;
    freqs["G5"] = 783.991f;
    freqs["G#5"] = freqs["Ab5"] = 830.609f;
    freqs["A5"] = 880.000f;
    freqs["A#5"] = freqs["Bb5"] = 932.328f;
    freqs["B5"] = 987.767f;

    freqs["C6"] = 1046.50f;
    freqs["C#6"] = freqs["Db6"] = 1108.73f;
    freqs["D6"] = 1174.66f;
    freqs["D#6"] = freqs["Eb6"] = 1244.51f;
    freqs["E6"] = 1318.51f;
    freqs["F6"] = 1396.91f;
    freqs["F#6"] = freqs["Gb6"] = 1479.98f;
    freqs["G6"] = 1567.98f;
    freqs["G#6"] = freqs["Ab6"] = 1661.22f;
    freqs["A6"] = 1760.00f;
    freqs["A#6"] = freqs["Bb6"] = 1864.66f;
    freqs["B6"] = 1975.53f;

    freqs["P"] = 0.0f;

    std::string temp, time;
    int i = 0;

    while ( i < sheet.size() )
    {
        char c = sheet[i];
        std::cout << c << std::endl;

        if ( c != ' ' && c != '-' )
        {
            temp += c;
            i++;
        }
        else if ( c == '-' )
        {
            do
            {
                i++;
                c = sheet[i];
                time += c;
            }
            while ( c != ' ' && i < sheet.size() );
        }

        if (c == ' ' || i == sheet.size())
        {
            // lookUp temp
            std::cout << "looking up: " << temp << std::endl;
            int freq = lookUp ( temp );
            int timing;

            // setting time
            if ( time.size() > 0 )
            {
                timing = atoi ( time.c_str() );    // besser mit stringstreams
            }
            else
            {
                timing = 4; // Default timing = 1/4 Note
            }

            std::cout << "freq: " << freq << std::endl;
            std::cout << "time: " << timing << std::endl;

            mysheet.push_back ( std::make_pair ( freq, timing ) );

            // raising counter
            i++;

            // clear temp, time
            temp = time = "";
        }
    }
}

void CBeeper::play()
{
    SDL_Beeper b;

    for (int i = 0; i < mysheet.size(); i++)
    {
        b.beep(mysheet[i].first, DEF_TIME*1.0/mysheet[i].second);
        b.wait();
    }
}

int CBeeper::lookUp ( const std::string & note )
{
    return round ( freqs[note] );
}
