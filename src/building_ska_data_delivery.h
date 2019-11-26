#pragma once

#include <sydevs/systems/composite_node.h>
#include "building_sdp_subscription_scheduler.h"
#include "building_sdp_processor.h"
#include "building_sdp_buffer.h"



namespace skabuffer {

using namespace sydevs;
using namespace sydevs::systems;

class building_ska_delivery : public composite_node {

 public:
  building_ska_delivery(const std::string& node_name, const node_context& external_context);
  virtual ~building_ska_delivery();

 protected:
  sdp_processor_node _processor;
  sdp_buffer_node _buffer;
  sdp_subscription_node _subscription_sched;
};

 
inline building_ska_delivery::building_ska_delivery(const std::string& node_name, const node_context& external_context) : composite_node(node_name, external_context),
  _processor("processor", internal_context()),
  _buffer("buffer", internal_context()),
  _subscription_sched("subscription_scheduler", internal_context()) {

  inner_link(_processor._buffer_rate_change_output,
	     _buffer._processor_rate_change_input);
  inner_link(_subscription_sched._buffer_request_output,
	     _buffer._data_request_input );
  
}


building_ska_delivery::~building_ska_delivery() {


}
 
 
}
