#pragma once
#include <string_view>
#include <vector>
#include "Client.h"

class Channel;
class Sender : public Client
{
public:
    explicit Sender(Channel& channel) : channel_(channel){}
    virtual void Send (std::string_view msg);

    void ReceivePacket(const Packet &packet) override;

    void SendPacket(const Packet &packet) override;
    /*
     * \brief THis function will send the next packet in the queue
     */
    virtual void Update();
    [[nodiscard]] byte GetLastSendSeqNmb() const;
protected:
    Channel& channel_;
    std::vector<Packet> sentPackets_;
    byte lastSendSeqNmb_ = 0;

};