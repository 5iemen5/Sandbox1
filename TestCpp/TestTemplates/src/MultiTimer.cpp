#include "MultiTimer.hpp"

void MultiTimer::start(uint8_t id) {
    timers[id].start_time = Clock::now();
    timers[id].is_running = true;
}

double MultiTimer::stop(uint8_t id) {
    auto end_time = Clock::now();
    auto& timer = timers[id];
    if (timer.is_running) {
        timer.total_duration += (end_time - timer.start_time);
        timer.is_running = false;
    }
    return timer.total_duration.count();
}

double MultiTimer::duration(uint8_t id) {
    return timers[id].total_duration.count();
}

void MultiTimer::reset(uint8_t id) {
    timers.erase(id);
}

void MultiTimer::print(uint8_t id) {
    printf("TIM_%d = %.6f ms\n", id, duration(id));
}