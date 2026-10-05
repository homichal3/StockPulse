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
