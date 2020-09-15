#pragma once

#include "Packet.h"
#include "Client.h"

class Receiver : public Client
{
public:
    void ReceivePacket(const Packet &packet) override;
    void SendPacket(const Packet &packet) override;
    void SendACK(byte sequenceNmb);
    void SendNAK(byte sequenceNmb);

};