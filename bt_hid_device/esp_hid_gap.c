#include "esp_hid_gap.h"
#include "esp_log.h"
#include "esp_bt.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"

static const char *TAG = "ESP_HID_GAP";

void esp_hid_gap_init(void) {
    esp_err_t ret = esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT);
    if (ret) ESP_LOGW(TAG, "BT classic mem release failed: %s", esp_err_to_name(ret));

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    esp_bt_controller_init(&bt_cfg);
    esp_bt_controller_enable(ESP_BT_MODE_BLE);

    esp_bluedroid_init();
    esp_bluedroid_enable();

    ESP_LOGI(TAG, "BLE HID GAP initialized.");
}
