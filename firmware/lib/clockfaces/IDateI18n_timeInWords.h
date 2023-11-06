#pragma once

#include <Arduino.h>

class IDateI18n_timeInWords {
  public:    
    virtual const char* formatDate(int day, int month);
    virtual const char* weekDayName(int weekday);
    virtual void timeInWords(int h, int m, char* hWords, char* mWords);
};
