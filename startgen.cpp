#include <vector>
#include <random>
#include <iostream>
#include <set>
#include <algorithm>
#include "math.hpp"

std::vector<std::vector<int>> generateWages(int size) {
    std::vector<std::vector<int>> res(size);
    for (auto& row : res) {
        row.resize(size);
    }
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                res[i][j] = 0;
            } else if (j < i) {
                res[i][j] = randomInt(5, 150);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j < i && randomInt(0, 1) == 1) {
                res[j][i] = res[i][j];
            } else if (i != j) {
                res[j][i] = randomInt(5, 150);
            }
            
        }
    }
    return res;
}



std::vector<std::vector<int>> genPopulation(int populationSize, int vertexSize) {
    std::vector<std::vector<int>> res(populationSize);
    std::vector<int> start(vertexSize);
    for (int i = 0; i < vertexSize; ++i) {
        start[i] = i;
    }

    for (auto& item : res) {
        std::random_shuffle(std::begin(start), std::end(start));
        item = start;
    }
    return res;
} 
