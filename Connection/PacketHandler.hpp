#pragma once
#include "../Modules/Utils.hpp"
#include "../Modules/Buffer.hpp"

// As of protocol 16
enum struct OpCode : unsigned char {
    SPAWN = 0x0,
    SPECTATE,
    FACEBOOK_DATA = 0x05,
    SET_TARGET = 0x10,
    SPLIT,
    QKEY_PRESSED,
    QKEY_RELEASED,
    EJECT = 0x15,
    CAPTCHA_RESPONSE = 0x56,
    MOBILE_DATA = 0x66,
    PONG = 0xe3,
    ESTABLISH_CONNECTION = 0xfe,
    CONNECTION_KEY
};

class Player; // forward declaration
class Packet; // forward declaration
class PacketHandler {
public:
    Player *player = nullptr;
    PacketHandler(Player *owner);

    // Packet sending
    void sendPacket(Buffer&) const;

    // Packet recieving
    void onPacket(std::vector<unsigned char>&);
    void onSpectate() const noexcept;
    void onTarget(const Vec2 &mouse) const noexcept;
    void onSplit() const noexcept;
    void onQKey() const noexcept;
    void onEject() const noexcept;
    void onEstablishedConnection(unsigned protocol) const noexcept;
    void onConnectionKey() const noexcept;

    ~PacketHandler();
};