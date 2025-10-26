#include "includes/interface.h"


Interface::Interface(){

}

void UpdateInterface(std::string name_music, int volume, int count_music_in_playlist, std::time_t* time){
    std::tm* localtime = std::localtime(time);
    //29 --
    printw("┌─────────────────────────────┐\n|%s\n|%d%%  %02d:%02d:%02d\n└─────────────────────────────┘",
        name_music.c_str() , volume,localtime->tm_hour, localtime->tm_min, localtime->tm_sec);

}

Interface::~Interface(){
    printw("Bye:)\n");
}

/*
    // ┌─────────────────────────────┐
    // │ loading                     │
    // │  [           ] 00:00/00:00  │
    // │ [s]kip    [p]ause    [q]uit │
    // └─────────────────────────────┘
*/