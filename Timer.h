//
// Created by STAS on 27.02.2020.
//

#ifndef SPELLER_TIMER_H
#define SPELLER_TIMER_H

#include <chrono>

class Timer {
public:
    void start();
    unsigned long int stop_and_get_result();
private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
};


#endif //SPELLER_TIMER_H
