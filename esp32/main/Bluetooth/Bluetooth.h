#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "../common.h"
#include "esp_nimble_hci.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "host/ble_hs.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"


extern uint32_t key_msg;
extern uint32_t volume_msg;
esp_err_t ble_start();


#endif