#include <iostream>
#include <vector>

int solveTask(std::vector<int>& array)
{
    int max1 = -1, max2 = -1;
    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > max1)
        {
            max2 = max1;
            idx2 = idx1;
            max1 = array[i];
            idx1 = i;
            continue;
        }
        if (array[i] > max2)
        {
            max2 = array[i];
            idx2 = i;
        }
    }
    return max1 + max2;
}

int main()
{
    std::vector<int> array = {2, 7, 23, 10, 8};
    std::cout << solveTask(array) << std::endl;
}