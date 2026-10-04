#pragma once

#include <string>
#include <chrono>
#include <cstdint>

namespace stockpulse 
{
    struct Candle
    {
        std::string symbol;
        std::chrono::sys_seconds timestamp;
        double open{};
        double close{};
        double high{};
        double low{};
        std::int64_t volume{};

    };


    bool is_valid(const Candle& candle);
}