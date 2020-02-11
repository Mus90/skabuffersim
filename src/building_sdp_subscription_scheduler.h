#pragma once

#include <sydevs/systems/atomic_node.h>
#include <iostream>

namespace skabuffer {

using namespace sydevs;
using namespace sydevs::systems;

class sdp_subscription_node : public atomic_node {
 public:
  sdp_subscription_node(const std::string& node_name, const node_context& external_context);
  virtual ~sdp_subscription_node() = default;
  
  virtual scale time_precision() const { return micro; }

  port<message, output, int64> _buffer_request_output;

  // note that this should be changed from using int64 to a complex type with needed info.
  port<message, input, int64> _buffer_request_input;

 protected:
    // Event Handlers:
    virtual duration initialization_event();
    virtual duration unplanned_event(duration elapsed_dt);
    virtual duration planned_event(duration elapsed_dt);
    virtual void finalization_event(duration elapsed_dt);  
};

inline sdp_subscription_node::sdp_subscription_node(const std::string& node_name, const node_context& external_context ) :
  atomic_node (node_name, external_context) ,
   _buffer_request_output("subscipt_output", external_interface()),
  _buffer_request_input("subscrtion_input", external_interface()) {

}

 
inline duration sdp_subscription_node::initialization_event()
{
	int64 time_of_first_request;
    std::cout << "sdp_subscription_node::init" << std::endl;
	
	time_of_first_request = 0;
	
    return duration(time_of_first_request);
}


inline duration sdp_subscription_node::unplanned_event(duration elapsed_dt)
{
  // Remove once system is debugged.
  std::cout << "sdp_subscription_node::unplanned_event" << std::endl;
  
  return duration::inf();
}

inline duration sdp_subscription_node::planned_event(duration elapsed_dt)
{
  std::cout << "sdp_subscription_node::planned_event" << std::endl;

  _buffer_request_output.send(3);
  
  return duration::inf();
}


inline void sdp_subscription_node::finalization_event(duration elapsed_dt)
{
  std::cout << "sdp_subscription_node::finalization_event" << std::endl;
}

}
