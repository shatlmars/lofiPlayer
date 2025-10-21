#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <atomic>
#include <vector>
#include <iostream>


class Player{
public:
    Player(std::vector<std::string>playlist): playlist{playlist}{
        stoped = false;
        paused = false;
    }
    void PlayPlaylist();
    void changePlaylist(std::vector<std::string>);
    void PlayMusic(std::string name_audio, int count_playing);
    void SetStopStatus(bool status);
    void SetPauseStatus(bool status);
    bool GetStopStatus(){return stoped;}
    bool GetPauseStatus() {return paused;}
    ~Player();
private:
    std::atomic<bool> stoped;
    std::atomic<bool> paused;
    std::vector<std::string> playlist;
    int count_playing;
protected:
    
};