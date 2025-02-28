#ifndef PROBABILITYCHECKER_H
#define PROBABILITYCHECKER_H

#include <random>
#include <optional>

class ProbabilityChecker 
{
public:
    static void initialize(std::optional<unsigned int> seed = std::nullopt);
    static bool occursWithProbability(double probability = 0.8);

private:
    static inline std::mt19937 generator;
};

#endif // PROBABILITYCHECKER_H
