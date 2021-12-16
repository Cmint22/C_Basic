#include <stdio.h>
#include <stdlib.h>

typedef ... elmType;
typedef struct nodeType{
    elmType element;
    struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

void MakeNullTree(treetype *T){ 
    (*T)=NULL; 
} 
int EmptyTree(treetype T){ 
    return T==NULL; 
}

void inorderprint(TreeType tree){
    if (tree!=NULL){
        inorderprint(tree->left);
        printf("%4d\n",tree->Key);
        inorderprint(tree->right);
    }
}

void postorderprint(TreeType tree){
    if (tree!=NULL){
        postorderprint(tree->left);
        postorderprint(tree->right);
        printf("%4d\n",tree->Key);
    }
}

void preorderprint(TreeType tree){
    if (tree!=NULL){
        printf("%4d\n",tree->Key);
        preorderprint(tree->left);
        preorderprint(tree->right);
    }
}

void iter_inorder(TreeType node){
    int top= -1; 
    TreeType stack[MAX_STACK_SIZE];
    for (;;){
        for (; node; node=node->left)
            add(&top, node);
        node= delete(&top);
        if (node==NULL) break;
        printf(“%d”, node->key);
        node = node->right;
    }
}

void breadth_first(TreeType node){
    QueueType queue; 
    if (node!=NULL) {
        enq(node,queue);
        while (!empty(queue)){
            node=deq(queue);
            printf(node->key);
            if (node->left !=NULL)
                enq(node->left,queue);
            if (node->right !=NULL)
                enq(node->right,queue);
        }
    }
}

