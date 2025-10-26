#include <iostream>
#include <thread>
#include <atomic>
#include "includes/input.h"
#include "includes/interface.h"
#include "includes/network.h"
#include <filesystem>



int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "Error\n";
        return 1;
    }
    std::string path_to_folder = argv[1];
    std::vector<std::string>playlist;
    for(const auto& entry : std::filesystem::directory_iterator(path_to_folder))
    {
        if(entry.is_regular_file() && entry.path().extension() == ".mp3"){
            playlist.push_back(entry.path().c_str());
        }
    }
    RecordPlayer player(playlist);
    Input input;
    Interface interface;
    std::thread t_player([&](){
        player.PlayPlaylist();
    });
    std::thread t_input([&](){
        input.InputButtons(std::ref(player));
    });
    std::thread t_interface([&](){
        interface.Draw();
    });
    t_player.join();
    t_input.join();
    t_interface.join();


    endwin();
    return 0;
}

//clang++ main.cpp input.cpp interface.cpp network.cpp recordPlayer.cpp  -Iincludes -lncurses -lSDL2 -lSDL2_mixer -o build/main