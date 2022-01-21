#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct add{
    char name[20];
    char tell[11];
    char mail[25];
}add;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int add[], int low, int high)
{
    int pivot = add[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && add[left] < pivot) left++;
        while(right >= left && add[right] > pivot) right--;
        if (left >= right) break;
        swap(add[left], add[right]);
        left++;
        right--;
    }
    swap(add[left], add[high]);
    return left;
}

void quickSort(int add[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(add, low, high);
        quickSort(add, low, pi - 1);
        quickSort(add, pi + 1, high);
    }
}

void printArray(int add[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("\nTen nguoi lien he: %s\nco dia chi mail: %s\nva co so dien thoai: %s\n",kq->data.name,kq->data.mail,kq->data.tell);
    printf("\n");
}

int main()
{
    int i,n;
    add add[100];
    add x;
    int n = sizeof(add)/sizeof(add[0]);
    quickSort(data.name, 0, n-1);
    printArray(add, n);
    return 0;
}