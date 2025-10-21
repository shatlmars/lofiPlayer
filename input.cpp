
#include "includes/input.h"

Input::Input(){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void Input::InputButtons(Player& player){
    bool i_paused = player.GetPauseStatus();

    while(player.GetStopStatus()){
        int ch = getch();
        if(ch == 'p'){
            i_paused = !i_paused;
             player.SetPauseStatus(i_paused);
        }else if(ch == 'q'){
            player.SetStopStatus(true);            
        }
    }

}

/*     
void inputLoop(){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    int status_y = 0;
    int status_x = 0;
    
    

    while(!stoped){
        int ch = getch();
        if(ch == 'p'){
            // printw("⏸ Pause/Resume\n");
            paused = !paused;
            move(status_y, 0);
            clrtoeol();
            if (paused) {
                printw("⏸ Paused");
            } else {
                printw("▶️ Playing");
            }
            refresh();
        }
        else if(ch == KEY_UP){
            int volume = Mix_VolumeMusic(-1);
            if(volume < MIX_MAX_VOLUME){
                Mix_VolumeMusic(volume + 8);
            }
            move(1, 1);
            clrtoeol();
            printw("Volume:%d%", (Mix_VolumeMusic(-1)* 100) /MIX_MAX_VOLUME);
            refresh();
        }
        else if(ch == KEY_DOWN){
            int volume = Mix_VolumeMusic(-1);
            if(volume >= 0){
                Mix_VolumeMusic(volume - 8);
            }
            move(1,1);
            clrtoeol();
            printw("Volume:%d%", (Mix_VolumeMusic(-1) * 100)/ MIX_MAX_VOLUME);
            refresh();
        }
        else if(ch == 'q'){
            stoped = true;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    move(status_y + 1, 0);
    printw("👋 Exiting...\n");
    refresh();
    endwin();
}
*/