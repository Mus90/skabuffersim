#pragma once

#include <sydevs/systems/atomic_node.h>

namespace skabuffer {
           
using namespace sydevs;
using namespace sydevs::systems;


class sdp_processor_node : public atomic_node {
 public:

  sdp_processor_node(const std::string& node_name, const node_context& external_context);
  virtual ~sdp_processor_node() = default;

  virtual scale time_precision() const { return micro; }
  
  port<message, output, int64> _buffer_rate_change_output;

 protected:
    // Event Handlers:
    virtual duration initialization_event();
    virtual duration unplanned_event(duration elapsed_dt);
    virtual duration planned_event(duration elapsed_dt);
    virtual void finalization_event(duration elapsed_dt);  
};

inline sdp_processor_node::sdp_processor_node(const std::string& node_name, const node_context& external_context) : atomic_node (node_name, external_context) ,
   _buffer_rate_change_output("buffer_stream", external_interface()){ 

}


// Only called once.
inline duration sdp_processor_node::initialization_event()
{
  std::cout << "sdp_processor_node::initialization_event()" << std::endl;
  // Call planned event straight away...
  return duration(int64(0));
}


inline duration sdp_processor_node::unplanned_event(duration elapsed_dt)
{
  std::cout << "sdp_processor_node::unplanned_event" << std::endl;
  return duration(int64(1)); 
}

 
inline duration sdp_processor_node::planned_event(duration elapsed_dt)
{
  // Remove this once things are debugged.
  std::cout << "sdp_processor_node::planned_event" << std::endl;

  // Send message to buffer with rate change value
  // Just using drand48 for how, but should use a distribution
  // appropriate for the simulation.
  _buffer_rate_change_output.send(drand48()*100);

  // Should now return the time that tne next rate change will be made.
  // Just putting this node to sleep for now.

  return elapsed_dt + duration(int64(1000), time_precision());
}


inline void sdp_processor_node::finalization_event(duration elapsed_dt)
{
  std::cout << "sdp_processor_node::finalization_event" << std::endl;
}
 
} // namespace
