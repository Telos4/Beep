#ifndef CBEEPER_H
#define CBEEPER_H

#include <vector>
#include <utility>
#include <string>
#include <map>
#include <cmath>
#include <iostream>

#include "SDL_Beeper.h"

#define DEF_TIME 1000

class CBeeper
{
    public:
        CBeeper(const std::string & sheet, int max_len);

        void play();

        std::vector<int> extract()
        {
            std::vector<int> notes;
            for (int i = 0; i < mysheet.size(); i++)
            {
                notes.push_back(mysheet[i].first);
            }

            return notes;
        }

    private:
        // Vector of notes
        // Each notes consists of a pair of the frequency of the note and the length
        std::vector<std::pair<int, int> > mysheet;

        // Map, that contains the matching frequency for each note
        std::map<std::string, float> freqs;

        // maximum length of a note in milliseconds == duration of a whole note
        int max_length;

        int lookUp(const std::string & note);
};

#endif // CBEEPER_H
