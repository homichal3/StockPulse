#include <stockpulse/core/candle.hpp>

namespace stockpulse
{
    bool is_valid(const Candle& candle)
    {
        return candle.low <= candle.open && candle.open <= candle.high &&
               candle.low <= candle.close && candle.close <= candle.high &&
               candle.volume >= 0;
    }
}
