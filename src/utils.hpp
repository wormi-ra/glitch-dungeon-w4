#pragma once

#include <cstdint>

#define mod(a, b) (((a % b) + b) % b)

template <typename T>
const char *itoa(T val, uint8_t base = 10, uint8_t padding = 1) {
    static char buf[32] = {'\0'};
    T i = 30;
	
    for(; (val && i) || padding ; --i, val /= base) {
        buf[i] = "0123456789abcdef"[val % base];
        padding -= bool(padding);
    }
    return &buf[i+1];
}
