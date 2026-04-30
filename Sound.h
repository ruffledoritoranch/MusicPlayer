/**
 * Sample API for <sound>
 */

#ifndef SOUND_H
#define SOUND_H

#include <string>

class Sound
{
    public:
        Sound();

        // Getters
        std::string getName() const;
        double getLength() const;
        std::string getType() const;
        std::string getArtist() const;
        double getDateAdded() const;

        // Setters
        void setName(const std::string& name);
        void setArtist(const std::string& artist);

    private:
        std::string name;
        double length;
        std::string type;
        std::string artist;
        double dateAdded;
};

#endif 