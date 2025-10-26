#include "includes/recordPlayer.h"

RecordPlayer::RecordPlayer(std::vector<std::string> playlist){
        this->playlist = playlist;
        stoped = false;
        paused = false;
        volume = 0;
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)){
            std::cerr << "Error MixOpenAudio. Pls, insert another audio\n";
        }
}

void RecordPlayer::PlayPlaylist(){
    while(!playlist.empty() && !stoped){
        std::string name_music = playlist.front();  
        playlist.erase(playlist.begin());  
        PlayMusic(name_music);
    }
}

void RecordPlayer::PlayMusic(std::string name_audio){
    
    Mix_Music* music = Mix_LoadMUS(name_audio.c_str());
    if(music == nullptr){
        std::cerr << "Error open music\n";
        return;
    }
    Mix_PlayMusic(music, count_playing);//добавить зацикливание. 0 - проигрывание 1 раз
    while(!this->stoped){
        if(this->paused){
            Mix_PauseMusic();
        }else{
            Mix_ResumeMusic();
        }
    }
    Mix_HaltMusic();
    Mix_FreeMusic(music);
}

void RecordPlayer::SetStopStatus(bool status){
    this->stoped = status;
}

void RecordPlayer::SetPauseStatus(bool status){
    this->paused = status;
}

RecordPlayer::~RecordPlayer(){
    Mix_CloseAudio();
    SDL_Quit();
}

void RecordPlayer::AddVolume(){
    if(volume < MIX_MAX_VOLUME)
        this->volume+= 8;
}