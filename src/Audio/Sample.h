#ifndef _Sample_h_
#define _Sample_h_

#include "Sound.h"

class Sample : public Sound
{
    public:
        Sample();
        Sample(const std::string& filename);
        ~Sample();

        void loadSound(const std::string& filename);
};

#endif
