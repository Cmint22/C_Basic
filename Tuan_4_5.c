// Ngan xep cai dat bang mang

#include<stdio.h>
using namespace std;

// Cai dat ngan xep
typedef int item;    // Kieu cua ngan xep
#define Max 100      // So phan tu toi da cua Stack
struct Stack{
    int Top;
    item Data[Max];
};
Stack S;  // Khai bao ngan xep S

//Khoi tao ngan xep
void Init (Stack & S){
    S.Top = 0;
}

//Kiem tra ngan xep rong
int Isempty( Stack S){
    return (S.Top==0);
}
 
//Kiem tra ngan xem day
int Isfull(Stack S){
    return (S.Top == Max);
}
 
//Ham Push them phan tu x vao dau ngan xep
void Push(Stack & S, item x){
    if(Isfull(S))
        printf("\nNgan xep day!");
    else{
        S.Top ++;
        S.Data[S.Top]=x;
    }
}
 
// Ham Pop lay phan tu khoi dau ngan xep
item Pop(Stack & S){
    if(Isempty(S))
        printf("\n Ngan xep rong! ");
    else{
        item x = S.Data[S.Top];
        S.Top--;
        return x;
    }
}
 
// Chen phan tu x vao vi tri k
void Insert_k(Stack & S, item x, int k){
    if(k<1 || k>S.Top)
        printf("\nVi tri chen khong hop le! ");
    else{
        Stack Tempt; // Khai bao stack tam thoi
        Init(Tempt);
        while(S.Top>=k){  // Chuyen phan tu tu S sang Tempt
            Push(Tempt, Pop(S));
        }
        Push(S,x); // Them phan tu x vao vi tri k
        while(Tempt.Top>0)    // Lay lai gia tri ve S
            Push(S,Pop(Tempt));
    }
}
// Ham Nhap
void Input(Stack&S){
    printf("\nNhap gia tri cho Stack \nNhap 0 de ket thuc ");
    item x;
    do{
        scanf("%d",&x);
        if(x!=0)
            Push(S,x);
    }
    while(x!=0);
}
 
//Ham xuat
void Output(Stack  S){
    while(S.Top!=0)
        printf("  ")Pop(S);
}
 
int main(){
    Input(S);
    Insert_k(S,13,3); // Chen phan tu 13 vao vi tri 3
    printf("Danh sach sau khi chen 13 vao vi tri thu 3: ");
    Output(S);
    return 0;
}