#ifndef GRID_MODULE_PO16_REVB_H_INCLUDED
#define GRID_MODULE_PO16_REVB_H_INCLUDED

#include "grid_module.h"


volatile uint8_t grid_module_po16_revb_hardware_transfer_complete;
const uint8_t grid_module_po16_revb_mux_lookup[];
uint8_t grid_module_po16_revb_mux;


void grid_module_po16_revb_hardware_start_transfer(void);
void grid_module_po16_revb_hardware_transfer_complete_cb(void);
void grid_module_po16_revb_hardware_init(void);

void grid_module_po16_revb_init(struct grid_ui_model* mod);



#endif