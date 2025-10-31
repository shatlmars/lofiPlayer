#include "includes/interface.h"


Interface::Interface(std::vector<std::string>* playlist){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    int height = 10;
    int width  = 50;
    int starty = 0;
    int startx = 0;
    win = newwin(height, width, starty, startx);
    for(const auto& name_music: *playlist){
        this->playlist.push_back(name_music);
    }
}



void Interface::UpdateInterface(bool pause_status, std::string name_music, double music_pos, int volume, int count_music_in_playlist, std::time_t* time){
    //29 --
    // move(0,0);
    werase(win);

    std::tm* localtime = std::localtime(time);
    mvwprintw(win, 0,0, "-------------------------------------------------");
    mvwprintw(win,1, 2, "Status: %s", pause_status ? "Paused" : "Playing");
    float i_volume = ((float)volume/128)*100;
    mvwprintw(win, 2,2, "time: %f", music_pos);
    
    mvwprintw(win,3, 2, "Now playing: %s", name_music.c_str());
    mvwprintw(win,4, 2, "Volume: %.0f", i_volume);
    mvwprintw(win,5, 2, "Playlist count: %-16d", count_music_in_playlist);
    mvwprintw(win, 6,0, "-------------------------------------------------");
    mvwprintw(win,7, 2, "Playlist:");
    int row = 8;

    for(const auto& name: playlist){
        mvwprintw(win, row, 2,"%d: %s", row-7, name.c_str());
        row++;
    }
    wrefresh(win);
}   

void Interface::InputButtons(RecordPlayer* player){
    bool i_paused = player->GetPauseStatus();
    int ch = getch();
        switch (ch)
        {
        case 'p':
            i_paused = !i_paused;
            player->SetPauseStatus(i_paused);
        break;
        case 'q':
            wclear(win);
            mvwprintw(win,1, 2, "");
            player->SetStopStatus(true);  
        break;
        case KEY_UP:
            player->AddVolume();
        break;
        case KEY_DOWN:
            player->MinusVolume();
        break;
        case KEY_LEFT:
        break;
        case KEY_RIGHT:
        break;
        case 'l':
            // ShowPlaylist();
        //show all playlist
        break;
        default:
            break;
        }
}

void Interface::Run(RecordPlayer& player){
    
    while(!player.GetStopStatus()){
        std::time_t time= std::time(nullptr);
        // InputButtons(player);
        bool i_paused = player.GetPauseStatus();
        int ch = getch();
        switch (ch)
        {
        case 'p':
            i_paused = !i_paused;
            player.SetPauseStatus(i_paused);
        break;
        case 'q':
            // std::cout << "q is pressed\n";
            wclear(win);
            mvwprintw(win,1, 2, "Quit is pressed");
            wrefresh(win);
            player.SetStopStatus(true);  
        break;
        case KEY_UP:
            player.AddVolume();
        break;
        case KEY_DOWN:
            player.MinusVolume();
        break;
        default:
            break;
        }
        std::string i_current_music = player.GetCurrentMusic();
        size_t lastSlash = i_current_music.rfind('/');
        if(lastSlash != std::string::npos){
            i_current_music = i_current_music.substr(lastSlash+1);
        }
        UpdateInterface(player.GetPauseStatus(),
            i_current_music,
            player.GetMusicPosition(),
            player.GetVolume(),
            player.GetPlaylistSize(),
            &time);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

Interface::~Interface(){
    wclear(win);
    mvprintw(2, 0, "Bye:)");
    wrefresh(win);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    delwin(win);
    endwin();
}





















/*
    // ┌─────────────────────────────┐
    // │ loading                     │
    // │  [           ] 00:00/00:00  │
    // │ [s]kip    [p]ause    [q]uit │
    // └─────────────────────────────┘
*/