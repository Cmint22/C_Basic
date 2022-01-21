#include <stdio.h>
#define MAX 10

int arr[MAX] = {6, 7, 0, 2, 8, 1, 3, 9, 4, 5};
int b[10];

void merging(int low, int mid, int high) {
    int l1, l2, i;
    l1 = low;
    l2 = mid + 1;
    for(i = low; l1 <= mid && l2 <= high; i++) {
        if(arr[l1] <= arr[l2]) {
            b[i] = arr[l1++];
        } else {
            b[i] = arr[l2++];
        }
    }

    while(l1 <= mid) {
        b[i++] = arr[l1++];
    }
    while(l2 <= high) {
        b[i++] = arr[l2++];
    }
    for(i = low; i <= high; i++) {
        arr[i] = b[i];
    }
}

void sort(int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging(low, mid, high);
    } else {
        return;
    }
}

void display() {
    int i;
    printf("[");

     // Duyet qua tat ca phan tu
    for(i = 0; i < MAX; i++){
        printf("%d ", arr[i]);
    }

    printf("]\n");
}

int main() {
    printf("Mang du lieu dau vao: ");
    display();
    printf("-----------------------------\n");
    sort(0, MAX);
    printf("Mang sau khi da sap xep: ");
    display();
}
