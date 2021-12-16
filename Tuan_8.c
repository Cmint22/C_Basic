#include <stdio.h>
#include <stdlib.h>
#include <bsttree.h>
#include <time.h>
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
treetype LeftChild(treetype n){ 
    if (n!=NULL) return n->left; 
    else return NULL;
}
treetype RightChild(treetype n){ 
    if (n!=NULL) return n->right;
    else return NULL;
}

node_type *create_node(elmtype NewData){ 
    N=(node_type*)malloc(sizeof(node_type));
    if (N != NULL){ 
        N->left = NULL;
        N->right = NULL;
        N->element = NewData;
    }
    return N;
}

int IsLeaf(treetype n){
    if(n!=NULL) return(LeftChild(n)==NULL)&&(RightChild(n)==NULL); 
    else return -1; 
}

int nb_nodes(treetype T){ 
    if(EmptyTree(T)) return 0; 
    else return 1+nb_nodes(LeftChild(T))+ nb_nodes(RightChild(T)); 
}

treetype createfrom2(elmtype v, treetype l, treetype r){ 
    treetype N; N=(node_type*)malloc(sizeof(node_type));
    N->element=v;
    N->left=l; 
    N->right=r;
    return N;
}

treetype Add_Left(treetype *Tree, elmtype NewData){ 
    node_type *NewNode = Create_Node(NewData);
    if (NewNode == NULL) 
        return (NewNode);
    if (*Tree == NULL)
        *Tree = NewNode;
    else{ 
        node_type *Lnode = *Tree;
        while (Lnode->left != NULL)
            Lnode = Lnode->left;
        Lnode->left = NewNode;
    }
    return (NewNode);
}

treetype Add_Left(treetype *Tree, elmtype NewData){ 
    node_type *NewNode = Create_Node(NewData);
    if (NewNode == NULL) 
        return (NewNode);
    if (*Tree == NULL)
        *Tree = NewNode;
    else{
        node_type *Rnode = *Tree;
        while (Rnode->right != NULL)
            Rnode = Lnode->right;
        Rnode->right = NewNode;
    }
    return (NewNode);
}

TreeType Search(KeyType x,TreeType Root){ 
    if (Root == NULL) 
        return NULL;
    else if (Root->key == x) 
        return Root; 
    else if (Root->key < x)
        return Search(x,Root->right);
    else { 
        return Search(x,Root->left); 
    }
}

void InsertNode(KeyType x,TreeType *Root ){ 
    if (*Root == NULL){ 
        *Root=(NodeType*)malloc(sizeof(NodeType)); 
        (*Root)->key = x; 
        (*Root)->left = NULL; 
        (*Root)->right = NULL; 
    } 
    else if (x < (*Root)->key) 
        InsertNode(x, &(*Root)->left);
    else if (x> Root->key) 
        InsertNode(x, &(*Root)->right); 
} 

void DeleteNode(key X,TreeType *Root){ 
    if (*Root!=NULL) 
        if (x < (*Root)->Key) 
            DeleteNode(x, &(*Root)->left) 
        else if (x > (*Root)->Key)
            DeleteNode(x, &(*Root)->right) 
        else if ((*Root)->left==NULL)&&((*Root)->right==NULL) 
            *Root=NULL; 
        else if ((*Root)->left == NULL)
            *Root = (*Root)->right 
        else if ((*Root)->right==NULL) 
            *Root = (*Root)->left 
        else (*Root)->Key = DeleteMin(&(*Root)->right); 
}

void prettyprint(TreeType tree,char *prefix){
    char *prefixend=prefix+strlen(prefix);
    if (tree!=NULL){
        printf("%04d",tree->key);
        if (tree->left!=NULL) 
            if (tree->right==NULL){
                printf("\304");
                strcat(prefix,"     ");
            }
        else {
            printf("\302");
            strcat(prefix,"\263    ");
        }
        prettyprint(tree->left,prefix);
        *prefixend='\0';
        if (tree->right!=NULL) 
            if (tree->left!=NULL){
                printf("\n%s",prefix);
                printf("\300");
            } 
        else printf("\304");
        strcat(prefix,"     ");
        prettyprint(tree->right,prefix);
    }
}

int main(){
    TreeType p, tree = NULL;
    int i, n = 0;
    srand(time(NULL));
    for ( i = 0; i < 10; i++ ) 
        insert (rand() % 100, tree ); 
    printf("pretty print:\n");
    strcpy(prefix,"    ");
    prettyprint(tree,prefix);
    printf("\n");
    do{
    printf("Enter key to search (-1 to quit):");
    scanf("%d", &n);
    p= Search(n, tree);
    if (p!=NULL) 
    printf("Key %d found on the tree",n);}
    else insert(n, tree);
    while (n!=-1);
    return 0;
}