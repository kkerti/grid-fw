#ifndef GRID_BUF_H_INCLUDED
#define GRID_BUF_H_INCLUDED

#include "grid_module.h"

#define GRID_BUFFER_TX_SIZE	4000 //1000
#define GRID_BUFFER_RX_SIZE	4000 //1000

#define GRID_DOUBLE_BUFFER_TX_SIZE	2000 //600
#define GRID_DOUBLE_BUFFER_RX_SIZE	2000 //600

struct grid_buffer{
	
	uint16_t buffer_length;
	uint8_t* buffer_storage;
	
	uint16_t read_start;
	uint16_t read_stop;
	uint16_t read_active;
	
	uint16_t read_length;
	
	uint16_t write_start;
	uint16_t write_stop;
	uint16_t write_active;
	
};


#define GRID_PORT_TYPE_UNDEFINED	0
#define GRID_PORT_TYPE_USART		1
#define GRID_PORT_TYPE_USB			2
#define GRID_PORT_TYPE_UI			3
#define GRID_PORT_TYPE_TELEMETRY	4

struct grid_port{
	
	uint32_t cooldown;

	struct grid_ui_report* ping_report;
	struct usart_async_descriptor*    usart;	
	uint8_t type;     // 0 undefined, 1 usart, 2 usb, 3 ui, 4 telemetry
	uint8_t direction;
	
	uint8_t dma_channel;
	
	uint16_t tx_double_buffer_status;
	
	uint32_t tx_double_buffer_ack_fingerprint;
	uint32_t tx_double_buffer_ack_timeout;
	
	uint8_t usart_error_flag;
	
	uint32_t rx_double_buffer_timeout; // is packet ready for verification
	
	uint32_t rx_double_buffer_status; // is packet ready for verification
	uint32_t rx_double_buffer_seek_start_index; // offset of next received byte in buffer
	uint32_t rx_double_buffer_read_start_index;
	
	uint8_t tx_double_buffer[GRID_DOUBLE_BUFFER_TX_SIZE];
	uint8_t rx_double_buffer[GRID_DOUBLE_BUFFER_RX_SIZE];
	
	
	
	
	
	
	struct grid_buffer tx_buffer;
	struct grid_buffer rx_buffer;
	
	uint32_t partner_hwcfg;
	uint8_t partner_fi;
	
	int8_t dx;
	int8_t dy;
	
	uint8_t partner_status;
	
};


volatile struct grid_port GRID_PORT_N;
volatile struct grid_port GRID_PORT_E;
volatile struct grid_port GRID_PORT_S;
volatile struct grid_port GRID_PORT_W;

volatile struct grid_port GRID_PORT_U;
volatile struct grid_port GRID_PORT_H;


uint8_t grid_port_packet_length(struct grid_buffer* por);

uint8_t grid_port_packet_start(struct grid_buffer* por);



uint8_t grid_buffer_init(struct grid_buffer*  buf, uint16_t length);


uint16_t grid_buffer_read_next_length();
uint8_t grid_buffer_read_character(struct grid_buffer* buf);
uint8_t grid_buffer_read_acknowledge();		// OK, delete
uint8_t grid_buffer_read_nacknowledge();	// Restart packet
uint8_t grid_buffer_read_cancel();			// Discard packet



uint16_t grid_buffer_write_init(struct grid_buffer* buf, uint16_t length);
uint8_t  grid_buffer_write_character(struct grid_buffer* buf, uint8_t character);

uint8_t grid_buffer_write_acknowledge(struct grid_buffer* buf);
uint8_t grid_buffer_write_cancel(struct grid_buffer* buf);


void grid_port_init_all(void);

void grid_port_init(volatile struct grid_port* por, uint16_t tx_buf_size, uint16_t rx_buf_size, struct usart_async_descriptor*  usart, uint8_t type, uint8_t dir, uint8_t dma, struct grid_ui_report* p_report);

#endif