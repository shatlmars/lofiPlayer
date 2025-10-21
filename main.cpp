#include <iostream>
#include <thread>
#include <atomic>
#include "includes/input.h"
#include "includes/interface.h"
#include "includes/recordPlayer.h"
#include "includes/network.h"


int main(int argc, char* argv[])
{
    if(argc < 2){
        return 1;
    }
    std::string path_to_folder;

    std::vector<std::string>paths_to_audio;

    Input input;
    Player player(paths_to_audio);

    std::thread t_player([&](){
        player.PlayPlaylist();
    });
    std::thread t_input([&](){
        input.InputButtons(std::ref(player));
    });


    t_player.join();
    t_input.join();
    // std::thread t_playlist(Player::PlayPlaylist, &player, std::ref(running), std::ref(pause));
    
    // if(SDL_Init(SDL_INIT_AUDIO) < 0){
    //     std::cout << SDL_GetError() << "\n";
    //     return 1;
    // }    
    // std::cout << "init is normn\n";
    // std::thread music_thread(PlayingMusic, "song.mp3");
    // std::thread inputThread(inputLoop);
    // // std::cin.get();

    // // stoped = true;`
    
    // music_thread.join();
    // inputThread.join();
    
    // SDL_Quit();


    // Mix_CloseAudio();
    return 0;
}