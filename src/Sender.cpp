//
// Created by efarhan on 9/15/20.
//
#include <iostream>
#include "Packet.h"
#include "Sender.h"
#include "Channel.h"

void Sender::ReceivePacket(const Packet &packet)
{
    //TODO check if received packet is corrupted

    if(!Client::CheckCorrupt(packet))
    {
        return;
    }
    bool isAck = packet.data[0];
    byte seqNmb = packet.sequenceNmb;

    if(isAck)
    {
        //TODO manage internal state when receiving ack
        if(seqNmb == lastSendSeqNmb_)
        {
            lastSendSeqNmb_++;
        }
    }
    else
    {
        //TODO managee internal state when receiving nak
    }
}

void Sender::SendPacket(const Packet &packet)
{
    channel_.SendToReceiver(packet);
}

void Sender::Send(std::string_view msg)
{
    size_t pktNumber = msg.size()/Packet::packetSize;
    if(pktNumber*Packet::packetSize != msg.size())
    {
        pktNumber++;
    }
    for(size_t i = 0; i < pktNumber;i++)
    {
        Packet p;
        for(size_t j = 0; j < Packet::packetSize; j++)
        {
            const auto index = i * Packet::packetSize + j;
            if(index == msg.size())
                break;
            const char c = msg[index];
            if(c == 0)
                break;
            p.data[j] = c;
        }
        p.sequenceNmb = i+1;
        p = Client::GenerateChecksum(p);
        sentPackets_.push_back(p);
    }
    lastSendSeqNmb_ = 1;
}

void Sender::Update()
{
    SendPacket(sentPackets_[lastSendSeqNmb_-1]);
}

byte Sender::GetLastSendSeqNmb() const
{
    return lastSendSeqNmb_;
}
