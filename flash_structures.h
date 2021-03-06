// Functions and defines for master's structures stored in FLASH

#ifndef __FLASH_STRUCTURES_H__
#define __FLASH_STRUCTURES_H__

#include <STM32F37x.h>

#define MAX_DEVICES 255
#define MAX_CONN_PER_DEVICE 40
#define MAX_CONN (MAX_DEVICES * MAX_CONN_PER_DEVICE)

typedef struct
{
  uint8_t device_count;
  uint16_t wires_count;
  uint8_t reserved;
} sys_typedef;

typedef struct
{
  uint8_t out_addr;
  uint8_t out_number;
  uint8_t in_addr;
  uint8_t in_number;
} conn_typedef;

typedef struct
{
  uint8_t from;
  uint8_t to;
} net_typedef;

// Tables addresses
uint32_t* get_connections_table_address(void);
const net_typedef* get_topology_table_address(void);
const sys_typedef* get_sys_settings_address(void);

// System settings
uint16_t get_wires_count(void);
uint8_t get_dev_count(void);

// Connections
conn_typedef get_connection(uint32_t index);

void set_topology(net_typedef value, uint32_t index);

#endif
