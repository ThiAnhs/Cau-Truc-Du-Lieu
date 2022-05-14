#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;

struct Node
{
	ElementType Element;
	struct Node* Next;
};

typedef struct Node *Position;

typedef Position List;

//Khoitaodanhsach
void makenullList(List *pL){
    (*pL) = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

//chen sau
void append(ElementType X, List *pL){
    Position P = (*pL);
    while (P->Next != NULL)
        P = P->Next;
    Node *t = (struct Node*)malloc(sizeof(struct Node));
	t->Element = X;
	t->Next = P->Next;
	P->Next = t;      
}

void readList(List *pL){

    int n;
    ElementType X;
    scanf("%d", &n);
    makenullList(pL);
    for(int i = 1; i <= n; i++){
        scanf("%d", &X);
        append(X,pL);
    }
}

void printList(List L){
	Position p = L;
	for(p = L; p != NULL; p = p ->Next){
        printf("%d ", p->Next->Element);
	}
	printf("\n");
}
 
int main(){
	List L;
	readList(&L);
	printList(L);
	return 0;
}