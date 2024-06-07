#include <iostream>
#include <random>
#include <ctime>

class RandomNumberGenerator {
private:
    std::mt19937 generator; // Mersenne Twister random number engine
    std::uniform_int_distribution<int> distribution; // Uniform distribution

public:
    RandomNumberGenerator(int min, int max) : distribution(min, max) {
        std::random_device rd;
        generator.seed(rd()); // Seed the generator with a random device
    }

    int generateRandomNumber() {
        return distribution(generator);
    }
};

int main() {
    std::cout << "Random Number Generation using OOP\n";

    int minRange, maxRange;
    std::cout << "Enter the minimum range: ";
    std::cin >> minRange;
    std::cout << "Enter the maximum range: ";
    std::cin >> maxRange;

    RandomNumberGenerator rng(minRange, maxRange);

    int numRandoms;
    std::cout << "How many random numbers do you want to generate? ";
    std::cin >> numRandoms;

    std::cout << "Generated random numbers: ";
    for (int i = 0; i < numRandoms; ++i) {
        std::cout << rng.generateRandomNumber() << " ";
    }
    std::cout << std::endl;

    return 0;
}
