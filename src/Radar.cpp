#include "Radar.h"
#include "ISimulation.h"

#include <bitset>
#include <sstream>

std::vector<uint8_t> Radar::scan()
{
    const std::string &state = m_sim.getState();

    std::vector<uint8_t> result;
    std::stringstream ss(state);
    std::string binaryStr;

    while (std::getline(ss, binaryStr, ';')) 
    {
        result.push_back(static_cast<uint8_t>(std::bitset<8>(binaryStr).to_ulong())); 
    }

    return result;
}

