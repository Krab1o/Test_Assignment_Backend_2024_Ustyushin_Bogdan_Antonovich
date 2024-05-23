#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void solveTask(const std::vector<int>& array1, const std::vector<int>& array2)
{
    std::map<int, int> keys;
    std::vector<int> notAppeared;

    for (auto el : array2) {
        keys[el] = 0;
    }

    for (auto el : array1) {
        if (keys.find(el) != keys.end())
            keys[el]++;
        else
            notAppeared.push_back(el);
    }

    size_t count;
    std::vector<int> result;
    for (auto el : array2)
    {
        count = keys[el];
        for (int i = 0; i < count; i++)
            result.push_back(el);
    }

    std::sort(notAppeared.begin(), notAppeared.end(), std::greater<>());

    for (auto el : notAppeared) {
        result.push_back(el);
    }

    printArray(result);
} 

int main()
{
    std::vector<int> A = {2, 4, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    std::vector<int> B = {2, 1, 4, 3, 6, 9};
    
    solveTask(A, B);
}