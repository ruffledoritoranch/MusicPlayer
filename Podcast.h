#include "Sound.h"

class Podcast : public Sound {

public:
    Podcast(std::string soundPath, std::string name, std::string artist);

    void playMusic() override;
    void displayInfo() override;
};