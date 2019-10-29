#ifndef GRID_UI_H_INCLUDED
#define GRID_UI_H_INCLUDED

#include "grid_module.h"




struct grid_ui_report
{
	uint8_t changed;
	
	uint8_t payload_length;
	uint8_t* payload;
	
	uint8_t helper_length;
	uint8_t* helper;
};

struct grid_ui_model
{
	uint8_t report_length;
	struct grid_ui_report* report_array;
	
};

volatile struct grid_ui_model grid_ui_state;


void grid_port_process_ui(struct grid_port* por);


uint8_t grid_ui_report_init(struct grid_ui_model* mod, uint8_t index, uint8_t* p, uint8_t p_len, uint8_t* h, uint8_t h_len);

uint8_t grid_ui_report_render(struct grid_ui_model* mod, uint8_t index, uint8_t* target);

uint8_t grid_ui_report_get_changed_flag(struct grid_ui_model* mod, uint8_t index);

void grid_ui_report_set_changed_flag(struct grid_ui_model* mod, uint8_t index);

void grid_ui_report_clear_changed_flag(struct grid_ui_model* mod, uint8_t index);


#endif