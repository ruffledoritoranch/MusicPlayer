#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <filesystem>

#include "Sound.h"
#include "Podcast.h"
#include "Playlist.h"

#include <memory>

using namespace std;

int main()
{   
    std::string input;
    bool programEnded = false;
    Playlist currentPlaylist("SamplePlaylist");
    
    while (!programEnded){
        std::cout << "Enter file name, enter 'p' to manage Playlist, enter 'EXIT' to quit.\n";

        std::getline(std::cin, input);
        
        if (input == "EXIT"){
            //player exit
            programEnded = true;
        }else if (input == "p"){
            std::cout << "Enter 'p' to play, enter 'r' to remove by index, enter 'c' to clear playlist, enter 's' to shuffle.\n";
            std::getline(std::cin, input);
            if (input == "p"){
                currentPlaylist.play();
            }else if (input == "r"){
                std::cout << "Enter index to remove. \n";
                std::getline(std::cin, input);
                size_t index = std::stoul(input);
                currentPlaylist.removeSound(index);
            }else if (input == "c"){
                currentPlaylist.clear();
            }else if (input == "s"){
                currentPlaylist.shuffle();
            }


        }else{
            sf::Music currentLoadingMusic;
            if (!currentLoadingMusic.openFromFile("SoundLibrary/" + input)){
                //audio cannot be found
                std::cout << "Failed to load audio file\n";
            }else{
                //audio found; make new audio object
                std::filesystem::path p("SoundLibrary/" + input);
                
                std::cout << "Type in artist. \n";
                std::string artistInput = "";

                while (artistInput == ""){
                    std::getline(std::cin, artistInput);

                    if (artistInput == ""){
                        std::cout << "Invalid. Enter another name. \n";
                    }
                }
                

                std::cout << "Is it podcast? Type in 'Y' if so. \n";
                std::getline(std::cin, input);

                

                std::shared_ptr<Sound> currentSound;

                if (input == "Y"){
                    currentSound = std::make_shared<Podcast>(p.string(), p.stem().string(), artistInput);
                }else{
                    currentSound = std::make_shared<Sound>(p.string(), p.stem().string(), artistInput);
                }

                //add here function to add song to certain playlist
                
                std::cout << "Next Step: 'P' to play song, 'I' for displaying song info, 'A' to add to your playlist. Type anything else to move on. \n";
                std::getline(std::cin, input);
                
                if (input == "P" || input == "p"){
                    currentSound->playMusic();
                }else if (input == "I" || input == "i"){
                    currentSound->displayInfo();
                }else if (input == "A" || input == "a"){
                    currentPlaylist.addSound(currentSound);
                    std::cout << "Will add here. \n";
                }

            }


        }

    }
}