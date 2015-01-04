#include <iostream>
#include <limits>

int main()
{
    using uint = unsigned int;
    const uint firstNumber  = 1;
    const uint defaultTurns = 100;
    const uint fizzDiv = 3;
    const uint buzzDiv = 5;

    std::cout << "Enter a number of turns (range ["
              << firstNumber
              << ".."
              << std::numeric_limits<uint>::max()
              << "])\n> "
              << std::flush;

    uint turns(0);
    try {
        std::cin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
        std::cin >> turns;
    } catch (...) {
        std::cerr << "Bad input\nTurns count is " << defaultTurns << "." << std::endl;
    }

    if (turns < firstNumber) {
        std::cout << "So small! Done." << std::endl;
        return 0;
    }

    bool isFizz(false);
    bool isBuzz(false);
    for (uint currentNumber = firstNumber; currentNumber <= turns; ++currentNumber) {
        isFizz = !(currentNumber % fizzDiv);
        isBuzz = !(currentNumber % buzzDiv);

        if (!isFizz && !isBuzz) {
            std::cout << currentNumber << std::endl;
            continue;
        }

        if (isFizz)
            std::cout << "fizz";

        if (isBuzz)
            std::cout << "buzz";

        std::cout << std::endl;
    }

    return 0;
}

