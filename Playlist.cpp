
#include "Playlist.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Playlist::Playlist(const std::string& name) : name(name) {}

std::string Playlist::getName() const {
    return name;
}

void Playlist:: addSound(const std::shared_ptr<Sound>& sound){
    playlist.push_back(sound);
}

void Playlist::removeSound(size_t index) {
    if(index < 0 || index > playlist.size()){
        throw std::out_of_range("Index out of bounds");
    }
    playlist.erase(playlist.begin() + index);
}

void Playlist:: clear(){
    playlist.clear();
}

void Playlist::shuffle() {  //C++ recommended shuffle 
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(playlist.begin(), playlist.end(), g);
}

size_t Playlist::size() const{
    return playlist.size();
}

bool Playlist::empty() const{
    return playlist.empty();
}

std::shared_ptr<Sound> Playlist::getSound(size_t index) const {
    if(index < 0 || index >= playlist.size()){
        throw std::out_of_range("Index out of bounds");
    }
    return playlist[index];
}

void Playlist::play() const {
    for (const auto& sound : playlist) {
        sound->playMusic();
    }
}