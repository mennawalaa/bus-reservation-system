#pragma once
#include<map>
#include"bus.h"
class reservation
{
public:
  //map  in clude all buses installed with the bus_no as a key
 std::map<int, bus> buses_in_service;
  /*functions return0 if the process went will ,return 1 if some testcases occur 
      ex choosing a bus not installed */
public:
  bool install_bus(void);
  bool bus_reservation(void);
  bool show(void);
};