#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <atomic>
#include <vector>
#include <iostream>

class RecordPlayer{
public:
    RecordPlayer(std::vector<std::string>playlist);
    void PlayPlaylist();
    // void SetInterface(Interface* interface);
    // void changePlaylist(std::vector<std::string>);
    void Notify(std::string name_music);
    void PlayMusic(std::string name_audio);
    void AddVolume();
    void MinusVolume();
    void SetStopStatus(bool status);
    void SetPauseStatus (bool status);
    bool GetStopStatus()const {return stoped;}
    bool GetPauseStatus()const {return paused;}
    int  GetVolume()const {return volume;}
    int  GetPlaylistSize()const {return playlist.size();}
    std::string GetCurrentMusic()const {return current_music;}
    ~RecordPlayer();
private:
    std::string current_music;
protected:
    std::atomic<bool> stoped;
    std::atomic<bool> paused;
    std::vector<std::string> playlist;
    int count_playing;
    int volume;
};