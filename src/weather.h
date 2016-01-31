#pragma once
#include <pebble.h>

// persistent storage
#define WEATHERINFO_PERSIST_KEY 2
#define WEATHERFORECAST_PERSIST_KEY 222
#define WEATHERSUN_PERSIST_KEY 333

typedef struct {
  int currentTemp;
  uint32_t currentIconResourceID;
} WeatherInfo;

typedef struct {
  int highTemp;
  int lowTemp;
  uint32_t forecastIconResourceID;
} WeatherForecastInfo;

typedef struct {
  int riseHour;
  int riseMinute;
  int setHour;
  int setMinute;
} WeatherSunTime;

extern WeatherInfo Weather_weatherInfo;
extern WeatherForecastInfo Weather_weatherForecast;
extern WeatherSunTime Weather_sunTimes;


#ifdef PBL_COLOR
  extern GDrawCommandImage* Weather_currentWeatherIcon;
  extern GDrawCommandImage* Weather_forecastWeatherIcon;
#else
  extern GBitmap* Weather_currentWeatherIcon;
  extern GBitmap* Weather_forecastWeatherIcon;
#endif


void Weather_setConditions(int conditionCode, bool isNight, int forecastCondition);
void Weather_saveData();
void Weather_init();
void Weather_deinit();
