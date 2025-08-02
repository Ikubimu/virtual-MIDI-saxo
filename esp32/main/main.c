#include "Bluetooth/Bluetooth.h"
#include "KeyInputs/KeyInputs.h"

uint8_t MAC_addr[6] = {0x08, 0x33, 0x08, 0x33, 0x08, 0x31};
uint32_t key_msg = 0;
uint32_t volume_msg = 0;


void app_main()
{
    esp_base_mac_addr_set(MAC_addr);
    nvs_flash_init();   
    ble_start();

    init_keyboard();

    for(;;)
    {
        key_msg = update_keyboard();
    }
}