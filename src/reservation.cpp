#include "reservation.h"
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include "bus.h"

bool reservation::install_bus()
{
  bus new_bus;
  int bus_no;
  std::cout << "enter bus number: " << std::setw(16) << " ";
  std::cin >> bus_no;
  std::cin.clear();
  std::cin.ignore(INT16_MAX, '\n');
  std::cout << "enter bus driver name: " << std::setw(10) << " ";
  std::cin >> new_bus.driver_name;
  std::cout << "enter bus arrival time: " << std::setw(10) << " ";
  std::cin >> new_bus.arrival_time;
  std::cout << "enter bus departer time: " << std::setw(9) << " ";
  std::cin >> new_bus.depart_time;
  std::cout << "from" << std::setw(30) << " ";
  std::cin >> new_bus.from;
  std::cout << "to" << std::setw(32) << " ";
  std::cin >> new_bus.to;
  // insert the new installed bus

  buses_in_service.insert(std::pair<int, bus>(bus_no, new_bus));

  return 0;
}

bool reservation::show()
{
  std::cout << " those are the buses available" << std::endl;

  for (auto element = buses_in_service.begin(); element != buses_in_service.end(); ++element)
  {
    std::cout << " bus number" << std::setw(25) << element->first << std::endl;
    std::cout << " bus driver name" << std::setw(20) << element->second.driver_name << std::endl;
    std::cout << " bus arrival time " << std::setw(15) << element->second.arrival_time << std::setw(10) << " ";
    std::cout << " bus dapart time" << std::setw(10) << element->second.depart_time << std::endl;
    std::cout << " from:" << std::setw(10) << element->second.from << std::setw(20) << " "
              << "to:" << std::setw(20) << element->second.to << std::endl;
    if (element->second.no_seats == number_of_seats)
      std::cout << " empty" << std::endl;
    else
    {
      std::cout << "no of avaible seats " << std::setw(10) << element->second.no_seats << std::endl;
      for (int i = 0; i <= number_of_seats; ++i)
      {
        std::cout << i << "." << element->second.seats[i] << std::setw(4) << " ";
      }
    }
    std::cout << " " << std::endl;
  }
  return 0;
}

bool reservation::bus_reservation()
{
  std::cout << " welcome at bus reservation" << std::endl;
  int bus_number;
  int no;
  std::string name;
  show();
  std::cout << "choose the bus" << std::endl;
  std::cin >> bus_number;
  std::cin.clear();
  std::cin.ignore(INT16_MAX, '\n');
  std::cout << "enter seat no" << std::endl;
  std::cin >> no;
  std::cin.clear();
  std::cin.ignore(INT16_MAX, '\n');
  std::cout << "your name please" << std::endl;
  std::cin >> name;

  // assigning the user name to the choosen seat in the choosen bus map

  //first check if the bus number is a key in the map of installed buses

  if (buses_in_service.count(bus_number))
  {

    auto bus_found = buses_in_service.find(bus_number); //use find function to acess the choosen object
    if (bus_found->second.seats[no] == "availble")
    {                                     //if the seat is available
      bus_found->second.seats[no] = name; // assigning the user name to the choosen seat in the choosen bus map
      std::cout << "seat " << no << " name " << bus_found->second.seats[no] << std::endl;
      bus_found->second.no_seats--;
      return 0;
    }
  }
  else
  { // the bus number doesnt exict in the map
    std::cout << "reservation failed" << std::endl;
    return 1;
  }
}
