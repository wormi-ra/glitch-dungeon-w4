#pragma once

#include <cstdint>

#define mod(a, b) (((a % b) + b) % b)

const char *itoa(uint32_t val, uint32_t base = 10);
