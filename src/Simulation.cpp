#include "Simulation.h"

#include "ProbabilityChecker.h"
#include "Scenario.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>

void Simulation::load(Scenario &scenario) 
{
    std::ifstream file(scenario.scenarioDataFile);
    m_scenario = scenario;
    m_scenarioData.clear();

    if (!file) 
    {
        std::cerr << "Error: Unable to open file " << scenario.scenarioDataFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        m_scenarioData.push_back(line);
    }
}

void Simulation::run() 
{
    std::cout << "Starting Simulation: " << m_scenario.name << std::endl;

    for (m_timeStep = 0; m_timeStep < m_scenarioData.size(); ++m_timeStep) 
    {
	for (auto& item : m_scenario.simulationItems) 
	{
	    item->update(m_timeStep);
	}
	processEvents();

	std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Simulation complete." << std::endl;
}

void Simulation::post(Event event)
{
    m_eventQueue.push(event);
}

const std::string& Simulation::getState() const
{
    return m_scenarioData.at(m_timeStep);
}

void Simulation::processEvents() 
{
    while (!m_eventQueue.empty()) 
    {
	Event event = m_eventQueue.front();
	m_eventQueue.pop();
    
	std::cout << "Processing event from " << event.sender << " at Time " << event.timeStep + 1 << "s: ";
	switch (event.type) 
	{
	case EventType::MISSILE_LAUNCH:
	    std::cout << "Missile launched.";
	    if ( missleHit() ) 
	    {
		post({EventType::TARGET_NEUTRALIZED, event.timeStep, "Simulation"});
	    } 
	    else 
	    {
		post({EventType::TARGET_MISSED, event.timeStep, "Simulation"});
	    }
	    break;
	case EventType::TARGET_NEUTRALIZED:
	    std::cout << "Target neutralized!";
	    break;
	case EventType::TARGET_MISSED:
	    std::cout << "Missile missed.";
	    break;
	case EventType::THREAT_DETECTED:
	    std::cout << "Thread detected.";
	    break;
	case EventType::NO_THREAT:
	    std::cout << "No thread detected.";
	    break;
	default:
	    std::cout << "Unknown Event.";
	}
	std::cout << std::endl;
    }
}

bool Simulation::missleHit()
{
    return ProbabilityChecker::occursWithProbability(m_scenario.pk_ratio);
}

