#include "includes/recordPlayer.h"


void Player::PlayPlaylist(){
    for(const std::string name : playlist){
        PlayMusic(name, count_playing);
    }
}

void Player::PlayMusic(std::string name_audio, int count_playing){
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)){
        std::cerr << "Error MixOpenAudio. Pls, insert another audio\n";
        return;
    }
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
    Mix_CloseAudio();
}

void Player::SetStopStatus(bool status){
    this->stoped = status;
}

void Player::SetPauseStatus(bool status){
    this->paused = status;
}

Player::~Player(){
    Mix_CloseAudio();
    SDL_Quit();
}

/*
void PlayingMusic(const std::string& name){
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        std::cerr << "Error MixOpenAudio: " << Mix_GetError() << "\n";
        return;
    }

    Mix_Music* music = Mix_LoadMUS(name.c_str());
    if(music == nullptr){
        std::cerr << "Error create mix music: " << Mix_GetError() << "\n";
        return;
    }
    Mix_PlayMusic(music, 0);
    while(!stoped){
        if(paused){
            Mix_PauseMusic();
        }else{
            Mix_ResumeMusic();
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
*/