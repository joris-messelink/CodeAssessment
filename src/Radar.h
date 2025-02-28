#ifndef RADAR_H
#define RADAR_H

#include <cstdint>
#include <vector>

class ISimulation;

class Radar 
{
public:
    Radar( ISimulation& sim ) :
	m_sim(sim)
    {}

    std::vector<uint8_t> scan();

private:
    ISimulation& m_sim;
};

#endif // RADAR_H

