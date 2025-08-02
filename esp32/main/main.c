#include "Bluetooth/Bluetooth.h"

uint8_t MAC_addr[6] = {0x08, 0x33, 0x08, 0x33, 0x08, 0x31};


void app_main()
{
    esp_base_mac_addr_set(MAC_addr);
    nvs_flash_init();   
    ble_start();
}