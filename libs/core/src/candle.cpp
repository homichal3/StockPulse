#include <stockpulse/core/candle.hpp>

namespace stockpulse
{
    bool is_valid(const Candle& candle)
    {
        const bool prices_ok = candle.low <= candle.open && candle.open <= candle.high &&
                               candle.low <= candle.close && candle.close <= candle.high;

        const bool counts_ok = candle.volume >= 0 && candle.trade_count >= 0;

        // Zerowy wolumen <=> zero transakcji. Wolumen to suma akcji z transakcji,
        // wiec nie moze byc jednego bez drugiego.
        const bool activity_consistent = (candle.volume == 0) == (candle.trade_count == 0);

        // VWAP to srednia z cen transakcji, a kazda transakcja miesci sie w [low, high],
        // wiec VWAP tez musi. Sprawdzamy tylko gdy byly transakcje: przy trade_count == 0
        // dostawca (np. Alpaca) podaje VWAP liczony z ofert, a nie z transakcji.
        const bool vwap_ok = candle.trade_count == 0 ||
                             (candle.low <= candle.vwap && candle.vwap <= candle.high);

        return prices_ok && counts_ok && activity_consistent && vwap_ok;
    }
}
