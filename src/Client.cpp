//
// Created by efarhan on 9/15/20.
//

#include <cstddef>
#include "Client.h"

bool Client::CheckCorrupt(const Packet &packet)
{
    byte checksum = 0;
    /*******************************
     * Begin Generate the checksum
     */
    checksum += packet.sequenceNmb;
    for(const auto dataByte : packet.data)
    {
        checksum += dataByte;
    }
    /*******************************
     * End Generate the checksum
     */

    /*******************************
     * Compare the checksum in the packet and the generated one
     * and return the result
     */

    return packet.checksum + checksum == 255;
}

Packet Client::GenerateChecksum(const Packet &packet)
{
    Packet generatedPacket = packet;
    byte checksum = 0;
    /*******************************
     * Begin Generate the checksum
     */
    checksum += packet.sequenceNmb;
    for(const auto dataByte : packet.data)
    {
        checksum += dataByte;
    }
    /*******************************
     * End Generate the checksum
     */
    generatedPacket.checksum = ~checksum;
    return generatedPacket;
}

