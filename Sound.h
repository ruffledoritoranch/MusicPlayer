/**
 * Sample API for <sound>
 */

#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <SFML/Audio.hpp>

class Sound
{
    public:
        Sound(std::string name);

        // Getters
        std::string getName() const;
        double getLength() const;
        std::string getType() const;
        std::string getArtist() const;
        double getDateAdded() const;
        sf::Music getMusic() const;

        // Setters
        void setName(const std::string& name);
        void setArtist(const std::string& artist);

        // Play
        void playMusic();

    private:
        std::string name;
        double length;
        std::string type;
        std::string artist;
        double dateAdded;
        sf::Music sound;

};

#endif 