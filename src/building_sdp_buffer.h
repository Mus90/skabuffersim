#pragma once

#include <sydevs/systems/atomic_node.h>
#include <iostream>

namespace skabuffer {

using namespace sydevs;
using namespace sydevs::systems;

class sdp_buffer_node : public atomic_node {
 public:
  sdp_buffer_node(const std::string& node_name, const node_context& external_context);
  virtual ~sdp_buffer_node() = default;
  
  virtual scale time_precision() const { return micro; }
  
  port<message, input, int64> _processor_rate_change_input;
  port<message, input, int64> _data_request_input;
  
 protected:
    // Event Handlers:
    virtual duration initialization_event();
    virtual duration unplanned_event(duration elapsed_dt);
    virtual duration planned_event(duration elapsed_dt);
    virtual void finalization_event(duration elapsed_dt);  
};


inline sdp_buffer_node::sdp_buffer_node(const std::string& node_name, const node_context& external_context) : atomic_node (node_name, external_context) ,
  _processor_rate_change_input("processor_stream", external_interface()),
  _data_request_input("request_input", external_interface()) {

}

inline duration sdp_buffer_node::initialization_event()
{
    std::cout << "sdp_buffer_node::init" << std::endl;
    return duration::inf();
}


inline duration sdp_buffer_node::unplanned_event(duration elapsed_dt)
{
  // Remove once system is debugged.
  std::cout << "sdp_buffer_node::unplanned_event" << std::endl;

  if( _processor_rate_change_input.received() ) {
    // In this case have received a message from the processor.
    int64 rate_change = _processor_rate_change_input.value();

    std::cout << "  recieved rate change : " << rate_change << std::endl;

    // Should now adjust internal state and perform any actions to do with LTS.
  }
  if( _data_request_input.received() ) {
    // Got request from data scheduler.
    int64 requst_val =  _data_request_input.value();

    std::cout << " received request " << requst_val << std::endl;
  }
  
  
  return duration::inf();
}

inline duration sdp_buffer_node::planned_event(duration elapsed_dt)
{
  
  std::cout << "sdp_buffer_node::planned_event" << std::endl;
  return duration::inf();
}


inline void sdp_buffer_node::finalization_event(duration elapsed_dt)
{
  std::cout << "sdp_buffer_node::finalization_event" << std::endl;
}

}
