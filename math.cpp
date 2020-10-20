#include <random>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

int randomInt(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end);
    return distr(gen);
}

void swap(std::vector<int>& vect, int first, int second) {
    int temp = vect[first];
    vect[first] = vect[second];
    vect[second] = temp;
}

void printVector(const std::vector<int>& v) {
    for (const auto& item : v) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& list : matrix) {
        std::cout << '[';
        for (const auto& elem : list) {
            std::cout << elem << ' ';
        }
        std::cout << ']' << '\n';
    }
    
}

long countDistance(
    const std::vector<std::vector<int>>& matrix,
    const std::vector<int>& path) {

    long sum = 0;

    for (int i = 0; i < path.size() - 1; ++i) {
        sum += matrix[path[i]][path[i+1]];
    }
    sum += matrix[path.back()][path.front()];
    return sum;
}

void sortByDistance(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& population) {
    std::sort(population.begin(), population.end(),
    [matrix](std::vector<int> lfs, std::vector<int> rfs) -> bool {
        return countDistance(matrix, lfs) < countDistance(matrix, rfs);
    });
}

