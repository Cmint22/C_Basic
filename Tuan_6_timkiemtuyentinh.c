#include <stdio.h>

int LinearSearch(int arr[], int numberOfElements, int key)
{
    for (int i = 0; i < numberOfElements; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int main()
{
    int i;
    int arr[] = { 10, 8, 1, 21, 7, 32, 5, 11, 0, 4, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = LinearSearch(arr, size, 9);

    if (index == -1)
        for(i = 0; i < (sizeof(arr) - 1); i++)
            printf("%d ", arr[i]);
    else
        printf(" 0 ");

    return 0;
}