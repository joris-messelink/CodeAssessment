#ifndef PATRIOTSYSTEM_H
#define PATRIOTSYSTEM_H

#include "ISimulationItem.h"
#include "IFF.h"
#include "Radar.h"

#include <string>

class ISimulation;

class PatriotSystem : public ISimulationItem 
{
public:
    PatriotSystem(ISimulation &sim, std::string name);
    void update(int timeStep) override;

private:
    std::string m_name;
    Radar m_radar;
    IFF m_iff;
    ISimulation &m_sim;
};

#endif // PATRIOTSYSTEM_H

