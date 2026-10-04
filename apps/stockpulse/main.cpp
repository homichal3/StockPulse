#include <iostream>
#include <stockpulse/core/candle.hpp>

int main() {
    std::cout << "StockPulse\n";
    std::cout << sizeof(stockpulse::Candle) << " " << alignof(stockpulse::Candle) << "\n";

    stockpulse::Candle good{
        .symbol = "AAPL",
        .timestamp = std::chrono::sys_seconds{std::chrono::seconds{1759593600}},
        .open = 187.10,
        .close = 187.30,
        .high = 187.45,
        .low = 186.90,
        .volume = 15230,
    };

    stockpulse::Candle bad = good;
    bad.high = 180.00;  // high ponizej low -> zepsuta swieca

    std::cout << std::boolalpha
              << "good: " << stockpulse::is_valid(good) << "\n"
              << "bad:  " << stockpulse::is_valid(bad) << "\n";
    return 0;
}
