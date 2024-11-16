#include <iostream>
#include <ctime>  // Import the ctime library
using namespace std;
 
int main () {
  struct tm datetime;
  time_t timestamp;

  datetime.tm_year = 2024 - 1900; // Number of years since 1900
  datetime.tm_mon = 10; // Number of months since January
  datetime.tm_mday = 16;
  datetime.tm_hour = 13;
  datetime.tm_min = 5;
  datetime.tm_sec = 30;
  // Daylight Savings must be specified
  // -1 uses the computer's timezone setting
  datetime.tm_isdst = -1;

  timestamp = mktime(&datetime);

  cout << ctime(&timestamp);
  return 0;
}