#include "Sound.h"
#include <string>
#include <SFML/Audio.hpp>
#include <ctime>

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
    // TODO
    return "";
}

std::time_t Sound::getDateAdded() const
{
    // TODO
    std::time_t now = std::time(nullptr);
    std::time_t timeNow = now;
    return timeNow;
}


// Setters
void Sound::setName(const std::string& name)
{
    // TODO
}


void Sound::setArtist(const std::string& artist)
{
    // TODO
}

// Play

void Sound::playMusic()
{
    // TODO
}

std::string Sound::displayInfo()
{
    // displays various sound properties through text.
    return "";
}