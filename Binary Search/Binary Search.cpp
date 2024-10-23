// Binary Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int binarySearch(int myNum[], int size, int target)
{
    int high = size;
    int low = 0;

    while (low <= high)
    {
        int middle = ((high + low) / 2); 

        if (myNum[middle] == target)
        {
            return middle; 
        }

        if (myNum[middle] < target)
        {
            low = middle + 1; 
        }
        else
        {
            high = middle - 1; 
        }
    }
    return -1; 
}

int main()
{
    int num[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //error doing it in function
    int size = sizeof(num) / sizeof(num[0]);

    int result = binarySearch(num, size, 4);
    std::cout << result << std::endl;
}

