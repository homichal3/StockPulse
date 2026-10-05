#include <iostream>
#include <stockpulse/core/candle.hpp>
#include <stockpulse/ingest/ingest.hpp>
#include <stockpulse/analysis/analysis.hpp>
#include <stockpulse/strategy/strategy.hpp>
#include <stockpulse/execution/execution.hpp>

int main() {
    std::cout << "StockPulse\n";
    std::cout << "modules: " << stockpulse::ingest::module_name() << " -> "
              << stockpulse::analysis::module_name() << " -> "
              << stockpulse::strategy::module_name() << " -> "
              << stockpulse::execution::module_name() << "\n";
    std::cout << sizeof(stockpulse::Candle) << " " << alignof(stockpulse::Candle) << "\n";

    stockpulse::Candle good{
        .symbol = "AAPL",
        .timestamp = std::chrono::sys_seconds{std::chrono::seconds{1759593600}},
        .open = 187.10,
        .high = 187.45,
        .low = 186.90,
        .close = 187.30,
        .volume = 15230,
    };

    stockpulse::Candle bad = good;
    bad.high = 180.00;  // high ponizej low -> zepsuta swieca

    std::cout << std::boolalpha
              << "good: " << stockpulse::is_valid(good) << "\n"
              << "bad:  " << stockpulse::is_valid(bad) << "\n";
    return 0;
}
