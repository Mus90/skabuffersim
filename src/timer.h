#pragma once
#include <chrono>

using namespace std::chrono;

typedef microseconds duration_t;

struct timer {
    steady_clock::time_point start_time;
    steady_clock::time_point end_time;
    bool stopped;
    timer(): start_time(steady_clock::now()), stopped(false), end_time(steady_clock::now()) {}
    void restart();
    void stop();
    duration_t elapsed_duration();
    int elapsed_count();
};

void timer::restart() {
   start_time = steady_clock::now();
   stopped = false;
   end_time =steady_clock::now();
}

void timer::stop() {
    if (!stopped) {
        end_time = steady_clock::now();
        stopped = true;
    }   
}

duration_t timer::elapsed_duration() {
    stop();
    return duration_cast<duration_t>(end_time - start_time);
}

int timer::elapsed_count() {
    stop();
    auto dur = duration_cast<duration_t>(end_time - start_time);
    return dur.count();
}

