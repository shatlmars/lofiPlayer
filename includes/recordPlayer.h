#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <atomic>
#include <vector>
#include <iostream>
#include <chrono>



class RecordPlayer{
public:
    RecordPlayer(std::vector<std::string>playlist);
    void PlayPlaylist();
    void changePlaylist(std::vector<std::string>);
    void PlayMusic(std::string name_audio);
    void AddVolume();
    void SetStopStatus(bool status);
    void SetPauseStatus(bool status);
    bool GetStopStatus(){return stoped;}
    bool GetPauseStatus() {return paused;}
    int  GetVolume(){return volume;}
    ~RecordPlayer();
private:
protected:
    std::atomic<bool> stoped;
    std::atomic<bool> paused;
    std::vector<std::string> playlist;
    int count_playing;
    int volume;
};