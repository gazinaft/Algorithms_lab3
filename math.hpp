#pragma once
#include <vector>
#include <algorithm>

int randomInt(int start, int end);

void swap(std::vector<int>& vect, int first, int second);

template<typename T>
std::vector<T> slice(const std::vector<T>& v, int m, int n) {
	std::vector<T> res;
    for (int i = m; i <= n; ++i) {
        res.push_back(v.at(i));
    }
    return res;
}

template<typename T>
void inRevert(std::vector<T>& v, int m, int n) {
    std::vector<int> subvertor = slice(v, m, n);
    std::reverse(std::begin(subvertor), std::end(subvertor));
    int i = m;
    for (const auto& item : subvertor) {
        v[i] = item;
        ++i;
    }
    
}

void printVector(const std::vector<int>& v);

void printMatrix(const std::vector<std::vector<int>>& matrix);

long countDistance(
    const std::vector<std::vector<int>>& matrix,
    const std::vector<int>& path);

void sortByDistance(
    const std::vector<std::vector<int>>& matrix,
    std::vector<std::vector<int>>& population);
