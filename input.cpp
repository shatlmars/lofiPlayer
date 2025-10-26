
#include "includes/input.h"

Input::Input(){

}

void Input::InputButtons(RecordPlayer& player){
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    bool i_paused = player.GetPauseStatus();

    while(!player.GetStopStatus()){
        int ch = getch();
        if(ch == 'p'){
            i_paused = !i_paused;
            player.SetPauseStatus(i_paused);
        }else if(ch == 'q'){
            std::cout << "q is pressed\n";
            player.SetStopStatus(true);            
        }else if(ch == KEY_UP){
            
        }
    }
}