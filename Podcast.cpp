#include "Podcast.h"
#include <iostream>

Podcast::Podcast(std::string soundPath, std::string name, std::string artist): Sound(soundPath, name, artist) {}

// Override playMusic
void Podcast::playMusic() {
    sf::Music currentLoadingMusic;

    if (!currentLoadingMusic.openFromFile(this->soundPath)){
        //audio cannot be found
        std::cout << "Failed to load audio file!\n";
    }else{
       currentLoadingMusic.play();
        std::cout << "Playing Podcast " << this->name << "\n";
        std::cout << "Press ENTER to stop\n";

        // Keep program alive while music plays
        std::cin.get();
    }
}

// Override displayInfo
void Podcast::displayInfo() {
    // displays various sound properties through text.
    std::cout << "Name of Podcast: " << this->name << "\n";
    std::cout << "Host: " << this->artist << "\n";
    std::cout << "Time Added " << this->timeAdded << "\n";
    std::cout << "Path " << this->soundPath << "\n";
}

