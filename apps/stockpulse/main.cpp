#include <iostream>
#include <stockpulse/core/candle.hpp>

int main() {
    std::cout << "StockPulse\n";
    std::cout << sizeof(stockpulse::Candle) << " " << alignof(stockpulse::Candle) << "\n";
    return 0;
}