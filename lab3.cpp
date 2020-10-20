#include "header.hpp"
#include "math.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

using unit_t = std::chrono::nanoseconds;

const int vertQuantity = 300;
const int populationSize = 100;
long currentBest = 0;

std::vector<std::vector<int>> MATRIX = generateWages(vertQuantity);

long filterpopulation(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& population, int populationSize) {
    sortByDistance(matrix, population);
    population.resize(populationSize);
    return countDistance(matrix, population.front());
}

std::ofstream output("Res2.txt");
std::ofstream output2("Res.txt");




int main() {
    std::vector<std::vector<int>> startValue = genPopulation(populationSize, vertQuantity);
    sortByDistance(MATRIX, startValue);
    std::vector<std::vector<int>> population = startValue;
    long distance = 0;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover1, lfs, rfs);
        for (auto& item : kids) {
            mutate1(item, 10);
            localImprove1(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<unit_t>(end - start).count();
    
    output2 << "сrossover1 mutate1 localImprove1" << '\n';
    output << "сrossover1 mutate1 localImprove1" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';
    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover2, lfs, rfs);
        for (auto& item : kids) {
            mutate1(item, 10);
            localImprove1(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover2 mutate1 localImprove1" << '\n';
    output << "сrossover2 mutate1 localImprove1" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover3, lfs, rfs);
        for (auto& item : kids) {
            mutate1(item, 10);
            localImprove1(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover3 mutate1 localImprove1" << '\n';
    output << "сrossover3 mutate1 localImprove1" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover1, lfs, rfs);
        for (auto& item : kids) {
            mutate2(item, 10);
            localImprove1(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover1 mutate2 localImprove1" << '\n';
    output << "сrossover1 mutate2 localImprove1" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover2, lfs, rfs);
        for (auto& item : kids) {
            mutate2(item, 10);
            localImprove1(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover2 mutate2 localImprove1" << '\n';
    output << "сrossover2 mutate2 localImprove1" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover3, lfs, rfs);
        for (auto& item : kids) {
            mutate2(item, 10);
            localImprove1(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover3 mutate2 localImprove1" << '\n';
    output << "сrossover3 mutate2 localImprove1" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover1, lfs, rfs);
        for (auto& item : kids) {
            mutate1(item, 10);
            localImprove2(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover1 mutate1 localImprove2" << '\n';
    output << "сrossover1 mutate1 localImprove2" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover2, lfs, rfs);
        for (auto& item : kids) {
            mutate1(item, 10);
            localImprove2(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover2 mutate1 localImprove2" << '\n';
    output << "сrossover2 mutate1 localImprove2" << '\n';
output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';


    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover3, lfs, rfs);
        for (auto& item : kids) {
            mutate1(item, 10);
            localImprove2(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover3 mutate1 localImprove2" << '\n';
    output << "сrossover3 mutate1 localImprove2" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover1, lfs, rfs);
        for (auto& item : kids) {
            mutate2(item, 10);
            localImprove2(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover1 mutate2 localImprove2" << '\n';
    output << "сrossover1 mutate2 localImprove2" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover2, lfs, rfs);
        for (auto& item : kids) {
            mutate2(item, 10);
            localImprove2(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover2 mutate2 localImprove2" << '\n';
    output << "сrossover2 mutate2 localImprove2" << '\n';
    output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';

    population = startValue;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        auto [lfs, rfs] = select(MATRIX, population);
        auto kids = breedApply(crossover3, lfs, rfs);
        for (auto& item : kids) {
            mutate2(item, 10);
            localImprove2(item, MATRIX);
        }
        population.insert(population.end(), kids.begin(), kids.end());
        distance = filterpopulation(MATRIX, population, populationSize);
        if(i % 20 == 0) {
            output2 << distance << '\n';
        }
    }
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<unit_t>(end - start).count();
    output2 << "сrossover3 mutate2 localImprove2" << '\n';
    output << "сrossover3 mutate2 localImprove2" << '\n';
output << duration << " nanoseconds "<< '\n';
    output << distance << '\n';
    }

