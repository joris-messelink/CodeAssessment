#ifndef SCENARIO_H
#define SCENARIO_H

#include "ISimulationItem.h"

#include <memory>
#include <string>
#include <vector>

struct Scenario 
{
    std::string name;
    std::string scenarioDataFile;
    double pk_ratio;
    std::vector<std::shared_ptr<ISimulationItem>> simulationItems;

    Scenario()
    {}

    Scenario(std::string name, std::string scenarioDataFile, double pk_ratio) : 
	name(name), 
        scenarioDataFile(scenarioDataFile), 
 	pk_ratio(pk_ratio) 
    {}
};

#endif /* SCENARIO_H */
