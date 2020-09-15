#pragma once
#include <cstdint>
#include <array>

using byte = std::uint8_t;
const byte INVALID_SEQ_NMB = 255;
struct Packet
{
    byte checksum = 0;
    byte sequenceNmb = 0;
    std::array<byte, 30> data{};

};