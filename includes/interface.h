#pragma once

#include "ncurses.h"
#include <string>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
#include "recordPlayer.h"
// class RecordPlayer;

class Interface{
public:
    Interface();
    void InputButtons(RecordPlayer* player);
    void UpdateInterface(bool pause_status, std::string name_music, int volume, int count_music_in_playlist, std::time_t* time);
    void Run(RecordPlayer& player);
    ~Interface();
private:
    WINDOW* win;
protected:

};

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include "ncurses.h"


class Observer{
public:
    virtual void update(float temperature,float humidity, float pressure) =0;
    virtual ~Observer() {};
};

class Subject{
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* Observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject(){};
};

class WeatherStation: public Subject{
private:
    std::vector<Observer*> observers;
    float temp, humi, press;
public:

    void registerObserver(Observer* observer) override{
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override{
        observers.erase(std::remove(observers.begin(), observers.end(), observer));
    }

    void notifyObservers() override{
        for(Observer* Observer : observers){
            Observer->update(temp, humi, press);
        }
        
    }

    void setMeasurand(float temp, float humi, float press){
        this->temp = temp;
        this->humi = humi;
        this->press = press;
        notifyObservers();
    }
};

class Display : public Observer{
public:
    void update(float temp, float humi, float press)override{
        printw("\nDisplay: Temp: %f°C Humi: %f%% Press: %fhPa", temp, humi, press);
    }
};
[shatl@shatllinux observer]$ 
*/