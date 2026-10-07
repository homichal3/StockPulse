#include <gtest/gtest.h>

#include <limits>
#include <stockpulse/core/candle.hpp>


class CandleValidationTest : public ::testing::Test
{
protected:
    stockpulse::Candle candle{
        .symbol = "AAPL",
        .timestamp = std::chrono::sys_seconds{std::chrono::seconds{1759593600}},
        .open = 187.10,
        .high = 187.45,
        .low = 186.90,
        .close = 187.30,
        .volume = 15230,
        .vwap = 187.20,
        .trade_count = 42,
    };
};

TEST_F(CandleValidationTest, AcceptsValidCandle)
{
    EXPECT_TRUE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, AcceptsFlatCandle)
{
    candle.open = candle.close = candle.high = candle.low = 187.00;
    candle.volume = 0;
    candle.trade_count = 0;
    candle.vwap = 187.00;
    EXPECT_TRUE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsHighBelowLow)
{
    candle.high = 180.00;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsOpenOutsideRange)
{
    candle.open = 190.00;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsCloseOutsideRange)
{
    candle.close = 186.00;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsNegativeVolume)
{
    candle.volume = -1;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsNaNPrice)
{
    candle.close = std::numeric_limits<double>::quiet_NaN();
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, AcceptsFractionalVolume)
{
    candle.volume = 0.000149046; // np. ulamek BTC
    EXPECT_TRUE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsNegativeTradeCount)
{
    candle.trade_count = -1;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsVwapAboveHigh)
{
    candle.vwap = 190.00;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsVwapBelowLow)
{
    candle.vwap = 180.00;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, IgnoresVwapWhenNoTrades)
{
    // Bez transakcji VWAP pochodzi z ofert, wiec nie wymagamy, by miescil sie w [low, high].
    candle.trade_count = 0;
    candle.volume = 0;
    candle.vwap = 190.00;
    EXPECT_TRUE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsZeroVolumeWithTrades)
{
    candle.volume = 0;
    candle.trade_count = 42;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}

TEST_F(CandleValidationTest, RejectsVolumeWithoutTrades)
{
    candle.volume = 15230;
    candle.trade_count = 0;
    EXPECT_FALSE(stockpulse::is_valid(candle));
}
