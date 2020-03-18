#include <cmath>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>

int GetBit(int number, size_t position) {
    assert(position < 32);
    return (number >> position) & 0b111;
    // 0b000110010 -> 0b00000110
}

int main() {
    int a = 0b000110010;
    int b = 0xFAC0;
    std::bitset<32> bit_b = b;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << GetBit(a, i) << ' ';
    }
    std::cout << '\n';
    std::cout << ((b & 0b111100000) >> 5) << '\n';
    std::cout << bit_b << '\n';
}
