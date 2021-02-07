
#pragma once
#include <string>
#include <map>
#define number_of_seats 2
class bus
{
public:
  std::string driver_name;
  std::string arrival_time;
  std::string depart_time;
  std::string from;
  std::string to;
  int no_seats;
  std::map<int, std::string> seats;
  bus();
};