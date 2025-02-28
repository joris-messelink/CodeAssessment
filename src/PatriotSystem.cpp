#include "PatriotSystem.h"
#include "Event.h"
#include "ISimulation.h"

#include <cstdint>
#include <vector>

PatriotSystem::PatriotSystem(ISimulation &sim, std::string name) :
    m_name(name),
    m_sim(sim),
    m_radar(sim)
{}

void PatriotSystem::update(int timeStep)
{
    std::vector<uint8_t> radarData = m_radar.scan();
    bool threat = m_iff.analyze( radarData );
    if ( threat )
    {
	m_sim.post( {EventType::THREAT_DETECTED, timeStep, m_name} );
	//firingUnit fire
	m_sim.post( {EventType::MISSILE_LAUNCH, timeStep, m_name} );
    }
    else
    {
	m_sim.post( {EventType::NO_THREAT, timeStep, m_name} );
    }
}

