#ifndef GRID_MODULE2_H_INCLUDED
#define GRID_MODULE2_H_INCLUDED

#include "sam.h"
#include <stdlib.h>

#include <atmel_start.h>
#include "atmel_start_pins.h"

#include "grid_protocol.h"
#include "grid_led.h"

#include "grid_sys.h"
#include "grid_buf.h"


#include "grid_ui.h"




#define  GRID_MODULE_P16_RevB		0
#define  GRID_MODULE_B16_RevB		128
#define  GRID_MODULE_PBF4_RevA		64
#define  GRID_MODULE_EN16_RevA		0xC0


#include "grid_module_bu16_revb.h"
#include "grid_module_po16_revb.h"
#include "grid_module_en16_reva.h"




//====================== GRID SYNC ===================================//
enum grid_sync_selector { GRID_SYNC_UNDEFINED, GRID_SYNC_1, GRID_SYNC_2};
enum grid_sync_mode { GRID_SYNC_INITIAL, GRID_SYNC_MASTER, GRID_SYNC_SLAVE};



void grid_module_init(void);



#endif