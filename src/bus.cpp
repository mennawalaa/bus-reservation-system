#include "bus.h"
#include <iostream>
#include <string>

bus::bus(void)
{
  {
    std::cout << "intilize empty bus" << std::endl;
    //intilazing the bus as empty
    for (int i = 0; i <= number_of_seats; ++i)
    {
      seats.insert(std::pair<int, std::string>(i, "availble"));
    }
    no_seats = number_of_seats;
  }
}