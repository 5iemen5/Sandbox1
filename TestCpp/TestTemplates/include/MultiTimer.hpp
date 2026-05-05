#pragma once
#ifndef MULTITIMER_HPP
#define MULTITIMER_HPP

#include <chrono>
#include <map>
#include <cstdint>
#include <cstdio>

class MultiTimer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<double, std::ratio<1, 1000>>;

    struct TimerData {
        TimePoint start_time;
        Duration total_duration{0};
        bool is_running{false};
    };

    std::map<uint8_t, TimerData> timers;

    // Private constructor for Singleton
    MultiTimer() = default;

public:
    // Delete copy/assign to enforce Singleton
    MultiTimer(const MultiTimer&) = delete;
    MultiTimer& operator=(const MultiTimer&) = delete;

    static MultiTimer& instance() {
        static MultiTimer inst;
        return inst;
    }

    // Method declarations
    void start(uint8_t id);
    double stop(uint8_t id);
    double duration(uint8_t id);
    void reset(uint8_t id);
    void print(uint8_t id);
};

// ==========================================
// COMPACT MACROS
// ==========================================
#define T_START(id) MultiTimer::instance().start(static_cast<uint8_t>(id))
#define T_STOP(id)  MultiTimer::instance().stop(static_cast<uint8_t>(id))
#define T_GET(id)   MultiTimer::instance().duration(static_cast<uint8_t>(id))
#define T_RST(id)   MultiTimer::instance().reset(static_cast<uint8_t>(id))
#define T_PRINT(id) MultiTimer::instance().print(static_cast<uint8_t>(id))

#endif // MULTITIMER_HPP