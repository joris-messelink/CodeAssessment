#ifndef ISIMULATION_H
#define ISIMULATION_H

#include "Event.h"

#include <string>

class ISimulation 
{
public:
    virtual ~ISimulation() = default;

    virtual void post(Event event) = 0;
    virtual const std::string& getState() const = 0;
};

#endif // ISIMULATION_H
