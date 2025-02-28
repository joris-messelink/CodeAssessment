#include "IFF.h"

#include <algorithm>
#include <ranges>

bool IFF::analyze( std::vector<uint8_t> radarData ) 
{
    int oddCount = std::ranges::count_if(radarData, [](uint8_t num) { return num % 2 != 0; });
    int evenCount = radarData.size() - oddCount;
    
    return oddCount > evenCount;
}
