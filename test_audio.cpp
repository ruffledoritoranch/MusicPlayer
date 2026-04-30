//g++ test_audio.cpp -o test -lsfml-audio -lsfml-system
// I installed SFML through MSYS2 UCRT 64, pacman -S mingw-w64-ucrt-x86_64-sfml
 
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::Music music;

    // Load audio file
    if (!music.openFromFile("SunRoof.mp3"))
    {
        std::cout << "Failed to load audio file\n";
        return -1;
    }

    // Play audio
    music.play();
    std::cout << "Playing audio...\n";
    std::cout << "Press ENTER to stop\n";

    // Keep program alive while music plays
    std::cin.get();

    return 0;
}