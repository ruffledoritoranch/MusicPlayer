#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <filesystem>

#include "Sound.h"

using namespace std;

int main()
{   
    std::string input;
    bool programEnded = false;
    while (!programEnded){
        std::cout << "Enter file name, enter 'EXIT' to quit.\n";

        std::getline(std::cin, input);
        if (input == "EXIT"){
            //player exit
            programEnded = true;
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
                
                Sound currentSound(p.string(), (p.stem().string()), artistInput);


                // Play audio
                currentLoadingMusic.play();
                std::cout << "Playing audio " << input << "\n";
                std::cout << "Press ENTER to stop\n";

                // Keep program alive while music plays
                std::cin.get();
            }


        }

    }
}