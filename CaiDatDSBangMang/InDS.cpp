#include<stdio.h>

#define Maxlen 100
typedef int  ElementType;
typedef int Position; 

typedef struct {
	ElementType Elements[Maxlen];
	Position    Last;
} List; 

void makenullList(List *L) {
	L->Last = 0;
}


void insertList(ElementType X,Position P, List *L) {
	if (L -> Last == Maxlen)
		printf("Danh sach day");	
	else if ((P < 1) || (P > L -> Last +1 ))
	    printf("Vi tri khong hop le");
	else {
			Position Q;
            L -> Last++;
			for(Q = L -> Last; Q > P - 1; Q --){
				L -> Elements[Q] = L -> Elements[Q-1];
            }
			L -> Elements [P-1] = X;
			
		}
} 


void DeleteList(Position P,List *L) { 
	if ((P < 1) || (P > L -> Last ))
		printf("Vi tri khong hop le");
	else if (L -> Last == 0)
	    printf("Danh sach rong!");
	else {
			Position Q;
			for(Q = P; Q <= L -> Last - 1; Q++)
				L->Elements[Q - 1] = L -> Elements[Q];
			L -> Last--;
		}
} 


void readList(List &L) {	
	int  N;
    printf("Nhap N vao: ");
	ElementType X;
	makenullList(&L);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
        printf("Phan tu thu [%d] = ", i);
		scanf("%d", &X);
		insertList(X, L.Last + 1 , &L);
	}
}


void printList(List L) {
	Position P;
	P = 1;
	while (P != L.Last + 1) {
		printf("%d ", L.Elements[P-1]);
		P = P + 1;
	}
	printf("\n");
}


// void Print(List L){
//     Position P;
//     for(P = 0; P < L.Last; P ++){
//         printf("%d ", L.Elements[P]);
//     }
//     printf("\n");
// }

int main(){
    List L;
    readList(L);
	printf("Danh sach gom: ");
    printList(L);
    
}