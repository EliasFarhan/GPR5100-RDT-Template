#pragma once

#include <string_view>
#include "Packet.h"
class Channel
{
public:
    virtual void SendToReceiver(const Packet& packet) = 0;
    virtual void SendToSender(const Packet& packet) = 0;
    virtual void Update() = 0;
    virtual void Send(const std::string_view txt) = 0;
};