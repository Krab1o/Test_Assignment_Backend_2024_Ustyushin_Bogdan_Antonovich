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

int main()
{
    std::vector<int> A = {2, 4, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    std::vector<int> B = {2, 1, 4, 3, 6, 9};
    std::map<int, int> keys;
    std::vector<int> notAppeared;

    for (auto el : B) {
        keys[el] = 0;
    }

    for (auto el : A) {
        if (keys.find(el) != keys.end())
            keys[el]++;
        else
            notAppeared.push_back(el);
    }

    std::vector<int> result;
    for (auto el : keys)
    {
        for (int i = 0; i < el.second; i++)
            result.push_back(el.first);
    }

    std::sort(notAppeared.begin(), notAppeared.end(), std::greater<>());

    for (auto el : notAppeared) {
        result.push_back(el);
    }

    printArray(result);
}