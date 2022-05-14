#include<stdio.h>
#define Maxlength 50
typedef int ElementType;
typedef int Position; 

typedef struct {
	ElementType Elements[Maxlength];
	Position    Last;
} List; 

void makenullList(List *L) {
	L->Last = 0;
}

//kiem tra phan tu co ton tai hay khong (1: la ton tai, 0: khong ton tai)
int member(ElementType X, List L){
    Position P = 1;
    int Found = 0;
    while (P != L.Last+1 && !Found)
        if(L.Elements[P-1] == X)
            Found = 1;
        else P = P + 1;   
    return Found;
}

void insertSet(ElementType X, List *L) {
     if (L->Last == Maxlength)
 		printf("Danh sach day\n");
 	else {
	    L->Elements[L->Last] = X;
	    L->Last = L->Last + 1;
 	}
} 

void readSet(List *L) {	
	int i, N;
	ElementType X;
	makenullList(L);
    printf("Nhap n: ");
	scanf("%d", &N);
	for(i = 1; i <= N; i++) { 
		scanf("%d", &X);
		if (!member(X, *L))
		    insertSet(X, L);
	}
}

//Ham giao giua cac phan tu cua DS1 va DS2
void unionSet(List L1, List L2, List *L){
    makenullList(L);
    Position P;
    P = 1;
    while (P != L1.Last + 1){
        insertSet(L1.Elements[P-1], L);
        P++;
    }
    P = 1;
    while (P != L2.Last+1){
        if (!member(L2.Elements[P-1], *L))
            insertSet(L2.Elements[P-1], L);
        P ++;
    }
}

void printList(List L) {
	Position P;
	P = 1;
	while (P != L.Last+1) {
		printf("%d ", L.Elements[P-1]);
		P = P+1;
	}
	printf("\n");
}
int main(){
    List L1, L2, L3;    
    readSet(&L1);
    readSet(&L2);

    printf("Danh sach 1: ");
    printList(L1);

    printf("Danh sach 2: ");
    printList(L2);

    unionSet(L1,L2,&L3);
    printf("Danh sach 3: ");
    printList(L3);

    return 0;
}