#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count){
    int i;
	
    for(i = 0;i <count-1;i++){
        printf("=");
    }
	
    printf("=\n");
}

void display(){
    int i;
    printf("[");
	
   // duyet qua tat ca phan tu
    for(i = 0;i<MAX;i++){
        printf("%d ",intArray[i]);
    }
	
    printf("]\n");
}

void insertionSort(){

    int valueToInsert;
    int holePosition;
    int i;

   // lap qua tat ca cac so
    for(i = 1; i < MAX; i++){ 
	
      // chon mot gia tri de chen
        valueToInsert = intArray[i];
		
      // lua chon vi tri de chen
        holePosition = i;
		
      // kiem tra xem so lien truoc co lon hon gia tri duoc chen khong
        while (holePosition > 0 && intArray[holePosition-1] > valueToInsert){
            intArray[holePosition] = intArray[holePosition-1];
            holePosition--;
            printf(" Di chuyen phan tu : %d\n" , intArray[holePosition]);
        }

        if(holePosition != i){
            printf(" Chen phan tu : %d, tai vi tri : %d\n" , valueToInsert,holePosition);
         // chen phan tu tai vi tri chen 
            intArray[holePosition] = valueToInsert;   
        }

        printf("Vong lap thu %d#:",i);
        display();
		
    }  
}

main(){
    printf("Mang du lieu dau vao: ");
    display();
    printline(50);
    insertionSort();
    printf("Mang sau khi da sap xep: ");
    display();
    printline(50);
}