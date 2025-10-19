#pragma once
#include "esp_err.h"
#include <stdbool.h>
#include <stdint.h>

void usb_hid_host_init(void (*on_key_event)(uint8_t key, bool pressed));
void usb_hid_host_task(void);
