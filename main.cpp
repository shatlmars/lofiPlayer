#include <iostream>
#include <thread>
#include <atomic>
#include "includes/input.h"
#include "includes/interface.h"
#include "includes/network.h"
#include <filesystem>
#include <chrono>
#include <locale>

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "Error\n";
        return 1;
    }
    // setlocale(LC_ALL, "");
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
    Interface ui;
    std::thread t_player([&](){
        player.PlayPlaylist();
    });
    // std::thread t_input([&](){
    //     input.InputButtons(std::ref(player));
    // });
    std::thread t_interface([&](){
        ui.Run(player);
    });
    // std::thread t_interface([&](){
    //     interface.
    // });
    t_player.join();

    t_interface.join();
    return 0;
}

//clang++ main.cpp input.cpp interface.cpp network.cpp recordPlayer.cpp  -Iincludes -lncurses -lSDL2 -lSDL2_mixer -o build/main