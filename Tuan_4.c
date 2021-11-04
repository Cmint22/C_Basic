#include<stdio.h>
#define MAX 100
int top=-1;
int isfull(int capacity){
    if (top == capacity -1){
        return 1;
    }
    else return 0;
}
int isempty(){
    if (top== -1){
        return 1;
    }
    else return 0;
}
void Push(int s[],int x,int capacity){
    if (isfull(capacity)==1){
        printf("Stack overflow");
    } else {
        ++top;
        s[top] = x;
    }
}
void Pop(int s[]){
    if (isempty()==1){
        printf("Stack is empty");
    } else{
        --top;
    }
}
int Top(int s[]){
    return s[top];
}
int Size(int s[]){
    return top+1;
}
int main(){
    int capacity;
    int s[MAX];
    printf("Nhap so phan tu:");
    scanf("%d",&capacity);
    Push(s,10,capacity);
    printf("size of stack is: %d\n",Size(s));
    Push(s,123,capacity);
    Push(s,918,capacity);
    printf("size of stack is: %d\n",Size(s));
    printf("top of stack is: %d\n",Top(s));
    if (isfull(capacity)==1){
        printf("Stack is full\n");
    } else printf("stack is not full\n");
    for (int i=0;i<=top;i++){
        printf("%d ",s[i]);
    }
    printf("\n");
    Pop(s);
    for (int i=0;i<=top;i++){
        printf("%d ",s[i]);
    }
    return 0;
}