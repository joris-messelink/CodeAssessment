#include "PatriotSystem.h"
#include "ProbabilityChecker.h"
#include "Scenario.h"
#include "Simulation.h"

#include <cstdlib> 
#include <iostream>

int main(int argc, char* argv[]) 
{
    std::optional<unsigned int> seed = std::nullopt;

    // Check if a seed is provided as a command-line argument
    if (argc > 1) 
    {
        try 
	{
            seed = std::stoi(argv[1]); // Convert argument to integer
        } 
	catch (const std::exception& e) 
	{
            std::cerr << "Invalid seed provided. Using random seed instead.\n";
        }
    }

    ProbabilityChecker::initialize(seed); // Initialize with provided seed or random seed

    Simulation simulation;
    Scenario scenario("Patriot Defense", "radar_data.csv", 0.8);
    scenario.simulationItems.push_back(std::make_shared<PatriotSystem>(simulation, "Patriot1"));

    simulation.load( scenario );

    simulation.run();
    
    return 0;
}
