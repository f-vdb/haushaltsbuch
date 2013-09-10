
#include <string>
#include "timeStamp.h"

std::string getCurrentYear() {
    time_t raw;
    struct tm *timeinfo;
    time(&raw);
    timeinfo = localtime(&raw);
    std::string year;
    size_t i = 1900 + timeinfo->tm_year;
    return std::to_string(i);
}

std::string getTimeStamp() {
    time_t raw;
    struct tm *timeinfo;
    time(&raw);
    timeinfo = localtime(&raw);
    std::string stamp;
    
    unsigned long long i = ((((1900 + timeinfo->tm_year) * 100) + 1 + timeinfo->tm_mon) * 100) + timeinfo->tm_mday;
    i = i * 100 + timeinfo->tm_hour;
    i = i * 100 + timeinfo->tm_min;
    i = i * 100 + timeinfo->tm_sec;
    stamp = stamp + std::to_string(i);
    return stamp;
}



