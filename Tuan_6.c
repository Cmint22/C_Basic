#include<stdio.h>

void nhapn(int* n){
    do{
        printf("Nhap so luong phan tu: ");
        scanf("%d", &*n);
    }while(*n<1);
}

void nhapmang(float arr[], int n){
    int i;
    printf("nhap du lieu cho mang: ");
    for(i=0; i<n; i++){
        printf("arr[%d = ",i);
        scanf("%f", &arr[i]);
    }
}

void sortasc(float arr[], int n){
    int i,j;
    float tg;
    for(i=0; i<n-1; i++){
        for(j=n-1; j>i; j--){
            if(arr[i]>arr[j]){
                tg=arr[i];
                arr[i]=arr[j];
                arr[j]=tg;
            }
        }
    }
}

float binarysearch(float arr[], int n, float x){
    int left=0, right=n-1;
    int index;
    while(left<=right){
        index=(left+right)/2;
        if(arr[index]==x)
            return index;
        if(x>arr[index])
            left=index+1;
        else
            right=index-1;
    }
    return -1;
}

int main(){
    int i,n;
    nhapn(&n);
    float arr[n];
    float x;
    nhapmang(arr, n);
    sortasc(arr, n);
    printf("Ket qua sau sap xep: ");
    for(i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf("nhap so can tim:");
    scanf("%f", &x);
    int index = binarysearch(arr, n, x);
    if(index==-1){
        printf("khong tim thay %f\n", x);
    }
    else{
        printf("tim thay %f tai vi tri %d", x, index);
    }
    return 0;
}