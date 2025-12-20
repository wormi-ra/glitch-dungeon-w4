#pragma once

#include "wasm4.hpp"
#include <cstdint>
#include <cmath>

template <uint32_t N>
class Bitfield {
    public:
        static constexpr uint32_t CELL_SIZE = sizeof(uintmax_t) * 8;
        static constexpr uint32_t CAPACITY = (N / CELL_SIZE) + 1;
        static constexpr uintmax_t MASK = uintmax_t(0x1u);

        class BitMutator {
            private:
                uintmax_t &ref;
                uint32_t bitPos;

            public:
                constexpr BitMutator(uintmax_t &ref, uint32_t bitPos) : ref(ref), bitPos(bitPos) {}

                constexpr BitMutator &operator=(bool value) {
                    ref &= ~(MASK << bitPos);
                    ref |= ((value & MASK) << bitPos);
                    return *this;
                }

                constexpr bool operator!() {
                    return ref ^ ~(MASK << bitPos);
                }

                constexpr bool operator~() {
                    return !this;
                }

                constexpr operator bool() {
                    return (ref >> bitPos) & MASK;
                }
        };

        constexpr bool set(uint32_t index, bool value) {
            return this[index] = value;
        }

        constexpr bool flip(uint32_t index) {
            return !this[index];
        }

        constexpr bool get(uint32_t index) {
            return this[index];
        }

        constexpr BitMutator operator[](uint32_t index) {
            if (index >= N) {
                w4::tracef("Bitfield operator[%d] >= %d", index, N);
            }
            return BitMutator(m_data[index / CELL_SIZE], index % CELL_SIZE);
        }

        constexpr uint32_t size() const {
            return N;
        }

    private:
        uintmax_t m_data[CAPACITY] {0};
};
