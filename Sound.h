/**
 * Sample API for <sound>
 */

#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <SFML/Audio.hpp>
#include <ctime>

class Sound
{
    protected:
        std::string name;
        std::string artist;
        std::time_t timeAdded;
        std::string soundPath;

    public:
        Sound(std::string soundPath, std::string name, std::string artist);

        // Getters
        std::string getName() const;
        std::time_t getDateAdded() const;

        // Setters
        void setName(const std::string name);
        void setArtist(const std::string artist);

        // Play
        virtual void playMusic();
        virtual void displayInfo();

};

#endif 