#ifndef SIMULATION_H
#define SIMULATION_H

#include "ISimulation.h"
#include "Scenario.h"

#include <queue>
#include <string>
#include <vector>

class Event;

class Simulation : public ISimulation
{
public:
    Simulation()
    {}

    void load(Scenario &scenario);
    void run();


    void post(Event event) override;
    const std::string& getState() const override;
protected:
    void processEvents();
    bool missleHit();

private:
    int m_timeStep = 0;
    Scenario m_scenario;
    std::vector<std::string> m_scenarioData;
    std::queue<Event> m_eventQueue;
};

#endif /* SIMULATION_H */
