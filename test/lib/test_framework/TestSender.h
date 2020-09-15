#pragma once

#include "Sender.h"

class TestSender : public Sender
{
public:
    using Sender::Sender;
    const Packet &getLastPacketReceived() const
    {
        return lastPacketReceived_;
    }


    void ReceivePacket(const Packet &packet) override
    {
        lastPacketReceived_ = packet;
        Sender::ReceivePacket(packet);
    }

private:
    Packet lastPacketReceived_;
};