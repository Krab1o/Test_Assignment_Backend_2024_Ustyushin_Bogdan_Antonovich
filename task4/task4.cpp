#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(std::vector<int>& array, int element)
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == element)
            return mid;

        if (array[mid] < element)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    std::vector<int> array = {7, 2, 3, 1, 52, 15};
    std::sort(array.begin(), array.end());
    std::cout << binarySearch(array, 3) << std::endl;
}