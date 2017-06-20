/* Given a sorted array of n integers that has been rotated an unknown number of
times, give an O(log n) algorithm that finds an element in the array You may assume
that the array was originally sorted in increasing order
EXAMPLE:
Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
Output: 8 (the index of 5 in the array) */

#include <iostream>

using namespace std;

// Вопросы:
// 1. Есть ли в массиве дубликаты? Если есть, то указанный поиск может не сработать

int findInBounds( int *arr, int left, int right, int val)
{
    while ( left < right )
    {
        int middle = (left + right) / 2; // здесь может быть overflow
                                         // лучше написать: left + (right - left) / 2

        if ( arr[left] < arr[middle] )
        {
            if ( val >= arr[left] && val <= arr[middle] )
                right = middle;
            else
                left = middle + 1;
        } else
        {
            /* Внимание! Использование условия val > arr[middle]
               (вместо val >= arr[middle]) гарантирует, что диапазон
               будет постоянно сужаться. Диапазон перестает сужаться,
               если где-то появляется присваивание left = middle */
            if ( val > arr[middle] && val <= arr[right] )
                left = middle + 1;
            else
                right = middle;
        }
    }

    if ( arr[left] == val )
        return left;
    else
        return -1;
}

int findIndex( int *arr, int sz, int val)
{
    if ( !arr )
        return -1;

    return findInBounds( arr, 0, sz - 1, val);
}

int main()
{
    int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

    cout << "Index: " << findIndex( arr, 12, 1);
}
