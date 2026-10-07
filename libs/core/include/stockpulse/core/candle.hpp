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
        double high{};
        double low{};
        double close{};
        double volume{};
        double vwap{};                // volume-weighted average price; sensowna tylko gdy trade_count > 0
        std::int64_t trade_count{};
    };


    bool is_valid(const Candle& candle);
}