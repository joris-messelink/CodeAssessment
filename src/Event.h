#ifndef EVENT_H
#define EVENT_H

#include <string>

enum class EventType 
{
    MISSILE_LAUNCH,
    TARGET_NEUTRALIZED,
    TARGET_MISSED,
    THREAT_DETECTED,
    NO_THREAT
};

struct Event 
{
    EventType type;
    int timeStep;
    std::string sender;
};

#endif // EVENT_H
