#include "bt_hid_device.h"
#include "esp_hid_gap.h"
#include "esp_log.h"

static const char *TAG = "BT_HID_DEVICE";

void bt_hid_device_init(void) {
    ESP_LOGI(TAG, "Initializing Bluetooth HID device...");
    esp_hid_gap_init();
}
