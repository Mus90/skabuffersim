#pragma once 
#include <sydevs/systems/simulation.h>
#include <iostream>

#include "building_ska_data_delivery.h"

namespace skabuffer {

using namespace sydevs;
using namespace sydevs::systems;

inline void skabuffersim() {
  std::cout << "Setting up ska buffer sim\n" << std::endl;
  simulation<building_ska_delivery> sim( duration(int64(50000)), 0, std::cout );
  sim.process_remaining_events();
  std::cout << "simuation done\n";
}

}
