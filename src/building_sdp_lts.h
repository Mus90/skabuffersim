#pragma once

#include <sydevs/systems/atomic_node.h>
#include <iostream>

using namespace sydevs;
using namespace sydevs::systems;

class sdp_lts_node : public atomic_node {
 public:
	sdp_lts_node(const std::string& node_name, const node_context& external_context);
	virtual scale time_precision() const { return micro; }
	port<message, input, int64> _data_input;
	 protected:
	// Event Handlers:
    virtual duration initialization_event();
    virtual duration unplanned_event(duration elapsed_dt);
    virtual duration planned_event(duration elapsed_dt);
    virtual void finalization_event(duration elapsed_dt);

 private:
	int64 _utilization;
};

inline sdp_lts_node::sdp_lts_node(const std::string& node_name, const node_context& external_context) :  atomic_node (node_name, external_context),
	_data_input("Data input from buffer", external_interface()) {
	_utilization = 0;
}


inline duration sdp_lts_node::initialization_event() {
	return duration::inf();
}

inline duration sdp_lts_node::unplanned_event(duration elapsed_dt) {
		if( _data_input.received() ) {
			_utilization += _data_input.value();
		}
		return duration::inf();
}

inline duration sdp_lts_node::planned_event(duration elapsed_dt) {

}

inline void sdp_lts_node::finalization_event(duration elapsed_dt) {
	std::cout << "LTS(" << this << ") Final untilization = " << _utilization << std::endl;
}
