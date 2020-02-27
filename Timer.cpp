//
// Created by STAS on 27.02.2020.
//

#include "Timer.h"

void Timer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

unsigned long int Timer::stop_and_get_result() {
    end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
}
