#include <iostream>
#include <map>
#include "bus.h"
#include "reservation.h"

int main()
{
  int x;
  bool exit_request{false};
  bool check;
  reservation a;
  do
  {
    std::cout << "welcome in bus reservation system choose the number crossponds to the service" << std::endl;
    std::cout << "1-install bus" << std::endl;
    std::cout << "2-reservation" << std::endl;
    std::cout << "3-show" << std::endl;
    std::cout << "4-exit" << std::endl;
    std::cout << "enter the number for your service"
              << " ";
    std::cin >> x;

    switch (x)
    {
    case (1):
    {
      check = a.install_bus();
      break;
    }
    case (2):
    {
      check = a.bus_reservation();
      if (check)
      {
        std::cout << "reservation failed try again" << std::endl;
      }
      else
      {
        std::cout << "reservation complete" << std::endl;
      }
      break;
    }
    case (3):
      check = a.show();
      break;
    case (4):
      std::cout << "exit" << std::endl;
      exit_request = true;
      break;
    }
    std::cin.clear();
    std::cin.ignore(INT16_MAX, '\n');
  } while (!exit_request);

  return 0;
}