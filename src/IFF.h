#ifndef IFF_H
#define IFF_H

#include <cstdint>
#include <vector>

class IFF 
{
public:
    bool analyze( std::vector<uint8_t> radarData ); 
};

#endif // IFF_H
