#include "includes/interface.h"
#include <chrono>

Interface::Interface(){

}

void Interface::Draw(){
    /*
    ┌─────────────────────────────┐
    │ loading                     │
    │  [           ] 00:00/00:00  │
    │ [s]kip    [p]ause    [q]uit │
    └─────────────────────────────┘
    */

    /*
        необходимо выставить ползунок прогресса аудио. Также громкость.
        Текущий трек. Менять кнопки при "пауза\воспроизведение. "
    */
    int status_y = 0;
    int status_x = 0;
    std::cout << "┌─────────────────────────────┐\n";
    std::cout << "|\n";
}

Interface::~Interface(){
    std::cout << "Bye! :)\n";

}