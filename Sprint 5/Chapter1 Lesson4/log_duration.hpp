#pragma once

#include <iostream>
#include <chrono>
#include <string>

class LogDuration{
public:
    using Clock = std::chrono::steady_clock;

    LogDuration(const std::string& guard) : guard_(guard)
    {
    }

    ~LogDuration(){
        using namespace std::chrono;
        using namespace std::literals;

        const auto end_time = Clock::now();
        const auto dur = end_time - start_time_;
        std::cerr << guard_ << ": "s << duration_cast<milliseconds>(dur).count() << "ms"s << std::endl;

    }
private:
    const Clock::time_point start_time_ = Clock::now();
    const std::string guard_;
};