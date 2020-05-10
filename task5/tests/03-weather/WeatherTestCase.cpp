//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(WeatherTestCase, InvalidCity) {
    WeatherMock weather;
    cpr::Response answer;
    answer.status_code = 510;
    EXPECT_CALL(weather, Get(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(answer));
    try {
        weather.GetResponseForCity("what");
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Api error. City is bad");
    } catch (...) {
        ASSERT_TRUE(false);
    }
}

TEST(WeatherTestCase, MainCase) {
    WeatherMock weather;

    cpr::Response mos;
    mos.status_code = 200;
    mos.text = "{ \"list\": [ { \"main\": { \"temp\": 289.15 } } ] }";
    cpr::Response spb;
    spb.status_code = 200;
    spb.text = "{ \"list\": [ { \"main\": { \"temp\": 287.92 } } ] }";
    cpr::Response chel;
    chel.status_code = 200;
    chel.text = "{ \"list\": [ { \"main\": { \"temp\": 293.26 } } ] }";
    
    EXPECT_CALL(weather, Get(::testing::_))
        .Times(4)
        .WillOnce(::testing::Return(mos))
        .WillOnce(::testing::Return(spb))
        .WillOnce(::testing::Return(mos))
        .WillOnce(::testing::Return(chel));
    ASSERT_EQ(weather.GetDifferenceString("Moscow", "Petersburg"), "Weather in Moscow is warmer than in Petersburg by 1 degrees");
    weather.SetApiKey("123");
    ASSERT_EQ(weather.GetDifferenceString("Moscow", "Chelyabinsk"), "Weather in Moscow is colder than in Chelyabinsk by 4 degrees");
}