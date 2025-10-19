#include "usb_hid_host.h"
#include "esp_log.h"
#include "usb/usb_host.h"
#include "usb/hid_host.h"

static const char *TAG = "USB_HID_HOST";

void usb_hid_host_init(void (*on_key_event)(uint8_t key, bool pressed)) {
    esp_err_t ret = usb_host_install(NULL);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "USB host install failed: %s", esp_err_to_name(ret));
        return;
    }
    ESP_LOGI(TAG, "USB host installed");

    hid_host_install(NULL);
    ESP_LOGI(TAG, "HID host installed");

    // Setup keyboard listener (simplified)
    ESP_LOGI(TAG, "Waiting for keyboard...");
}

void usb_hid_host_task(void) {
    // You would poll HID events here and call the callback on key events.
}
