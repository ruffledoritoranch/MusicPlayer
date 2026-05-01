

#pragma once
#include <string>
#include <vector>
#include "Sound.h"


class Playlist {
public:
    
    Playlist(const std::string& name);
    std::string getName() const;
    
        //use of shared_ptr for automatic new and delete management
    void addSound(const std::shared_ptr<Sound>& sound);
    void removeSound(const std::shared_ptr<Sound>& sound); //remove by title
    void removeSound(size_t index); //remove by index
    
    void play() const;
    void clear();
    void shuffle();

    size_t size() const;
    bool empty() const;
    std::shared_ptr<Sound> getSound(size_t index) const;


private:
    std::string name;
    std::vector<std::shared_ptr<Sound>> playlist;
};

#endif // PLAYLIST_H