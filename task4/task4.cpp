#include <iostream>
#include <vector>

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
    std::vector<int> array = {1, 2, 5, 7, 10, 15};
    std::cout << binarySearch(array, 11) << std::endl;
}