//
// Created by efarhan on 9/18/20.
//


#include "gtest/gtest.h"
#include "TestChannel.h"

const float updateDeltaTime = 0.1f;
const float packetDelay = 0.1f;
const float firstRtt = 1.0f;
const int updateToTimeout = int(firstRtt/packetDelay);

TEST(timeout, loss_receiver)
{
    TestChannel channel;
    channel.SetState(TestChannel::LOSS_PKT_RECEIVER);

    channel.Send("Hello");

    channel.SendNewPacket(packetDelay);
    for(int i = 0; i < updateToTimeout; i++)
    {
        channel.Update(updateDeltaTime);
    }
    EXPECT_TRUE(channel.GetSender().HasTimeout());
    EXPECT_FALSE(channel.GetSender().IsMessageSent());
}

TEST(timeout, loss_sender)
{
    TestChannel channel;
    channel.SetState(TestChannel::LOSS_PKT_SENDER);

    channel.Send("Hello");

    channel.SendNewPacket(packetDelay);
    for(int i = 0; i < updateToTimeout; i++)
    {
        channel.Update(updateDeltaTime);
    }
    EXPECT_TRUE(channel.GetSender().HasTimeout());
    EXPECT_FALSE(channel.GetSender().IsMessageSent());
}


TEST(timeout, loss_once_receiver)
{
    TestChannel channel;
    channel.SetState(TestChannel::LOSS_HALF_PKT_RECEIVER);

    channel.Send("Hello");

    channel.SendNewPacket(packetDelay);
    for(int i = 0; i < 2*updateToTimeout; i++)
    {
        channel.Update(updateDeltaTime);
    }
    EXPECT_TRUE(channel.GetSender().HasTimeout());
    EXPECT_TRUE(channel.GetSender().IsMessageSent());
}

TEST(timeout, loss_once_sender)
{
    TestChannel channel;
    channel.SetState(TestChannel::LOSS_HALF_PKT_SENDER);

    channel.Send("Hello");

    channel.SendNewPacket(packetDelay);
    for(int i = 0; i < 2*updateToTimeout; i++)
    {
        channel.Update(updateDeltaTime);
    }
    EXPECT_TRUE(channel.GetSender().HasTimeout());
    EXPECT_TRUE(channel.GetSender().IsMessageSent());
}