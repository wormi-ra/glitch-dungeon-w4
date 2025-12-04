#pragma once

#include <cstddef>
#include <cstdint>

size_t strlen(const char *str);

const char *itoa(uint32_t val, uint32_t base = 10);
