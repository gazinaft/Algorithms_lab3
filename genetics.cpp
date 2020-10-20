#include <vector>
#include <algorithm>
#include "math.hpp"
#include <typeinfo>
#include <iostream>

// swaps 2 random things
void mutate1(std::vector<int>& vect, int percents) {
    if (randomInt(1, 100) > percents) return;
    int first = randomInt(0, vect.size() - 1);
    int second = randomInt(0, vect.size() - 1);
    swap(vect, first, second);
}
// swaps a whole range inside a vector
void mutate2(std::vector<int>& vect, int percents) {
    if (randomInt(1, 100) > percents) return;
    int first = randomInt(3, vect.size() - 1);
    int second = first - 3;
    inRevert(vect, second, first);
}

// standart 1 point crossover
std::vector<std::vector<int>> crossover1(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> part = slice(first, 0, first.size() / 2 - 1);
    for (const auto& item : second) {
        if (std::count(part.begin(), part.end(), item) < 1) {
            part.push_back(item);
        }
    }
    return {part};
}

// chess order crossover
std::vector<std::vector<int>> crossover2(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> res(first.size());
    int limit = (res.size() / 2) * 2;
    for (int i = 0; i <= limit; i+=2) {
        res[i] = first[i];
    }
    int k = 1;
    for (int item : second) {
        if (std::count(res.begin(), res.end(), item) < 1) {
            res[k] = item;
            k+=2;
        }
        
    }
    std::vector<int> res2(first.size());
    for (int i = 1; i <= limit; i+=2) {
        res2[i] = first[i];
    }
    int j = 0;
    for (const int& item : second) {
        if (std::count(res2.begin(), res2.end(), item) < 1) {
            res2[j] = item;
            j+=2;
        }
        
    }

    return {res, res2};
}

// 2 point crossover
std::vector<std::vector<int>> crossover3(const std::vector<int>& first, const std::vector<int>& second) {
    int size = first.size();
    std::vector<int> steps = {0, size / 3, 2 * size / 3, size};
    std::vector<std::vector<int>> children;
    for (int i = 0; i <= 2; ++i) {
        std::vector<int> res(size, -1);
        for (int j = steps.at(i); j < steps.at(i + 1) - 1; ++j) {
            res.at(j) = first.at(j);
        }
        int k = 0;
        for(int& item : res) {
            if(item == -1) {
                while (std::count(res.begin(), res.end(), second.at(k)) > 0) {
                    k++;
                }
                item = second.at(k);
                k++;
            }
        }
        children.push_back(res);
    }
    return children;
}

// selection with the best and second worst 
std::pair<std::vector<int>, std::vector<int>> select(
    const std::vector<std::vector<int>>& matrix,
    std::vector<std::vector<int>>& population) {
    //sortByDistance(matrix, population);
    return {population[0], population[population.size() - 2]};
}


void localImprove1(std::vector<int>& v, const std::vector<std::vector<int>>& matrix) {
    std::vector<int> cop(v.size());
    std::reverse_copy(v.begin(), v.end(), cop.begin());
    v = countDistance(matrix, v) > countDistance(matrix, cop) ? cop : v;
}

void localImprove2(std::vector<int>& v, const std::vector<std::vector<int>>& matrix) {
    std::vector<int> copy = v;
    for (int i = 0; i < 2; i++) {
        if (i + 1 == v.size()) {
            return;
        }
        
        swap(copy, i, randomInt(i + 1, copy.size() - 1));
        if (countDistance(matrix, copy) < countDistance(matrix, v)) {
            v = copy;
            return;
        }
    }
}

// int main() {
//     std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//     std::vector<int> b(a.size());
//     std::reverse_copy(a.begin(), a.end(), b.begin());
//     std::vector<int> c = {1, 3, 5, 7, 2, 4, 6, 8};
    
//     // std::cout << typeid(crossover1).name() << std::endl;


//     std::vector<std::vector<int>> matr = {{0, 20, 10}, {50, 0, 100}, {10, 10, 0}};
    
//     std::vector<int> path = {0, 1, 2};
//     std::vector<int> path2 = {0, 2, 1};
//     std::vector<int> path3 = {2, 1, 0};

//     // std::vector<std::vector<int>> vec = {path, path2, path3};
//     // printMatrix(crossover1(a, b));

//     printMatrix(breedApply(crossover3, a, b));

//     // sortByDistance(matr, vec);

//     // printMatrix(vec);
//     // localImprove2(path, matr);
//     // printVector(path);
    
// }


