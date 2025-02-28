#include "ProbabilityChecker.h"

#include <iostream>

void ProbabilityChecker::initialize(std::optional<unsigned int> seed) 
{
    if (seed) 
    {
        generator.seed(*seed);
        std::cout << "Random generator initialized with seed: " << *seed << std::endl;
    } 
    else 
    {
        std::random_device rd;
        unsigned int randomSeed = rd();
        generator.seed(randomSeed);
        std::cout << "Random generator initialized with random seed: " << randomSeed << std::endl;
    }
}

bool ProbabilityChecker::occursWithProbability(double probability) 
{
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(generator) < probability;
}
