#include "strutils.hpp"

size_t strlen(const char *str) {
    const char *ptr = str;
    for (; *ptr != '\0' ; ptr++);
    return (size_t)(ptr - str);
}

const char *itoa(uint32_t val, uint32_t base) {
	
	static char buf[32] = {'\0'};
	
	uint32_t i = 30;
	if (val == 0)
        return "0";
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
}
