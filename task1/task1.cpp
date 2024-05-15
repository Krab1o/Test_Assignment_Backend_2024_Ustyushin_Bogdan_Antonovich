#include <iostream>
#include <vector>

void merge(std::vector<int>& array, int left, int mid, int right) 
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> L(leftSize);
    std::vector<int> R(rightSize);

    for (int i = 0; i < leftSize; i++) 
    {
        L[i] = array[left + i];
    }
    for (int j = 0; j < rightSize; j++) 
    {
        R[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int currentPosition = left;

    while (i < leftSize && j < rightSize) 
    {
        if (L[i] <= R[j]) 
        {
            array[currentPosition] = L[i];
            i++;
        } 
        else 
        {
            array[currentPosition] = R[j];
            j++;
        }
        currentPosition++;
    }

    while (i < leftSize) 
    {
        array[currentPosition] = L[i];
        i++;
        currentPosition++;
    }

    while (j < rightSize) 
    {
        array[currentPosition] = R[j];
        j++;
        currentPosition++;
    }
}

void mergeSort(std::vector<int>& array, const int begin, const int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void solveTask(std::vector<int>& array)
{
    const int begin = 0;
    const int end = array.size() - 1;
    mergeSort(array, begin, end);
}

void printArray(const std::vector<int>& array) 
{
    for (int i = 0; i < array.size(); i++) 
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> array = {1, -1, 3, 42, 5};

    std::cout << "Array before sorting:" << std::endl;
    printArray(array);

    solveTask(array);

    std::cout << "Array after sorting:" << std::endl;
    printArray(array);

    return 0;
}
