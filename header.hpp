#pragma once
#include <vector>

std::vector<std::vector<int>> generateWages(int size);

std::vector<std::vector<int>> genPopulation(int populationSize, int vertexSize);

void mutate1(std::vector<int>& vect, int percents);

void mutate2(std::vector<int>& vect, int percents);

template <typename F>
std::vector<std::vector<int>> breedApply(F func, const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<std::vector<int>> res = func(first, second);
    std::vector<std::vector<int>> sec = func(second, first);
    res.insert(res.end(), sec.begin(), sec.end());
    return res;
}

std::vector<std::vector<int>> crossover1(const std::vector<int>& first, const std::vector<int>& second);

std::vector<std::vector<int>> crossover2(const std::vector<int>& first, const std::vector<int>& second);

std::vector<std::vector<int>> crossover3(const std::vector<int>& first, const std::vector<int>& second);

std::pair<std::vector<int>, std::vector<int>> select(
    const std::vector<std::vector<int>>& matrix,
    std::vector<std::vector<int>>& population);

void localImprove1(std::vector<int>& v, const std::vector<std::vector<int>>& matrix);

void localImprove2(std::vector<int>& v, const std::vector<std::vector<int>>& matrix);
