#include "Sound.h"
#include <string>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

using namespace std;

// Constructor & 
Sound::Sound(std::string soundPath, std::string name, std::string artist)
{
    this->soundPath = soundPath;
    this->name = name;
    std::time_t now = std::time(nullptr);
    this->timeAdded = now;
    this->artist = artist;
}

// Getters
std::string Sound::getName() const
{
    return (this->name);
}

std::time_t Sound::getDateAdded() const
{
    return (this->timeAdded);
}


// Setters
void Sound::setName(const std::string name)
{
    this->name = name;
    // TODO
}


void Sound::setArtist(const std::string artist)
{
    this->artist = artist;
}

// Play

void Sound::playMusic()
{
    // Play audio

    sf::Music currentLoadingMusic;

    if (!currentLoadingMusic.openFromFile(this->soundPath)){
        //audio cannot be found
        std::cout << "Failed to load audio file!\n";
    }else{
       currentLoadingMusic.play();
        std::cout << "Playing audio " << this->name << "\n";
        std::cout << "Press ENTER to stop\n";

        // Keep program alive while music plays
        std::cin.get();
    }
}

void Sound::displayInfo()
{
    // displays various sound properties through text.
    std::cout << "Name of Song: " << this->name << "\n";
    std::cout << "Artist: " << this->artist << "\n";
    std::cout << "Time Added " << this->timeAdded << "\n";
    std::cout << "Path " << this->soundPath << "\n";
}