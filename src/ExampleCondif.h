class example_config_node : public composite_node
{
public:
    // Constructor/Destructor:
    two_stage_queueing_node(const std::string& node_name, const node_context& external_context);
    virtual ~two_stage_queueing_node() = default;

	sdp_processor_node processor;
	sdp_buffer_node buffer;
	
two_stage_queueing_node::two_stage_queueing_node(const std::string& node_name, const node_context& external_context)
    : composite_node(node_name, external_context)
buffer ("buffer", internal_interface())
    , processor ("processor", internal_interface())
	{
	inner_link(processor.y_output, buffer.y_input);	
	}
}
