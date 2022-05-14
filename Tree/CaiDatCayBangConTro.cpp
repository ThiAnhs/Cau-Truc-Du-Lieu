#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int tdata;
typedef struct Tnode
{
    tdata data;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

typedef struct Tnode *TTree;

void makenull_tree(TTree *T)
{
    (*T)=NULL;
}

int emptytree(TTree T)
{
    return (T==NULL);
}

TTree leftchild(TTree n)
{
    if(n!=NULL)
        return n->left;
    else
        return NULL;
}

TTree rightchild(TTree n)
{
    if(n!=NULL)
        return n->right;
    else
        return NULL;
}

int isleaf(TTree n)
{
    //if(n!=NULL)
    return (leftchild(n)==NULL && rightchild(n)==NULL);
    //else
    //    return NULL;
}

TTree create2(tdata v, TTree left, TTree right)
{
    TTree N;
    N=(Tnode*)malloc(sizeof(struct Tnode));
    N->data=v;
    N->left=left;
    N->right=right;
    return N;
}

void tientu(TTree T)
{
    if(!emptytree(T))
    {
        printf("%d ",T->data);
        tientu(leftchild(T));
        tientu(rightchild(T));
    }
}

void trungtu(TTree T)
{
    if(!emptytree(T))
    {

        trungtu(leftchild(T));
        printf("%d ",T->data);
        trungtu(rightchild(T));
    }
}

void hautu(TTree T)
{
    if(!emptytree(T))
    {

        hautu(leftchild(T));
        hautu(rightchild(T));
        printf("%d ",T->data);
    }
}

int countLeafNode(TTree T)
{
	if (T == NULL) return 0;
	if (isleaf(T)) return 1;
	return countLeafNode(T->left) + countLeafNode(T->right);
}

int countNode(TTree T){
	if (T == NULL) return 0;
	if (isleaf(T)) return 1;
	return 1 + countNode(T->left) + countNode(T->right);
}

int sumNode(TTree T)
{
	if (T != NULL){
		int a = sumNode(T->left);
        int b = sumNode(T->right);
        return T->data + a + b;
	}
	return 0;
}

int countNode1(TTree T){
	if (T != NULL) 
	{
		if (!isleaf(T)){

			if(countNode(T->left) == countNode(T->right))
				printf("\nNut: %d", T->data);
			
			//printf("data: %d", t->data);
			countNode1(T->left);	
			countNode1(T->right);
		}
	}
}

int sumNode1(TTree T){
	if (T != NULL) 
	{
		if (!isleaf(T)){

			if(sumNode(T->left) == sumNode(T->right))
				printf("\nSum: %d", T->data);
			
			//printf("data: %d", t->data);
			sumNode1(T->left);	
			sumNode1(T->right);
		}
	}
}

TTree search(tdata k, TTree T)
{
    tdata tam;
    //tam = T->data;
    /*if(T != NULL)
    {
        if(tam == k)
            return T;
        else if(k < tam)
            return search(k, T->left); //return search(k, leftchild(T));
        else
            return search(k, T->right); //return search(k, rightchild(T));
    }
    else
        return NULL;*/
        
    if(T== NULL)
    	return NULL;
    if(T->data == k)
    	return T;
    else if(k < T->data)
    	return search(k, T->left);
    else if(k > T->data)
    	return search(k, T->right);
}

//To tien chung gan nhat
tdata NearRoot(TTree T,tdata p, tdata q)
{
   if((T->data >=p && T->data <= q) || (T->data >=q && T->data <= p))
      return T->data;
   else
      if(T->data < p && T->data < q)
         return NearRoot(T->right,p,q);
      else
         return NearRoot(T->left,p,q);
}

int totien(TTree T,tdata p, tdata q)
{
    if((T->data==p) && ((T->data <q)||(T->data >q)))
       return 1;
    else if((T->data >q && T->data <p)||(T->data >p && T->data <q))
        return 0;
    else if(T->data<q && T->data<p) totien(T->right,p,q);
    else totien(T->left,p,q);
}
void insertnode(tdata k, TTree *T)
{
    if((*T)==NULL)
    {
        (*T)=(Tnode*)malloc(sizeof(struct Tnode));
        (*T)->data=k;
        (*T)->left=NULL;
        (*T)->right=NULL;
    }
    else
    {
        if((*T)->data == k)
            printf("Da ton tai khoa x");
        else if((*T)->data > k)
            insertnode(k,&(*T)->left);
        else
            insertnode(k,&(*T)->right);
    }
}

tdata DeleteMin (TTree *Root ){
    tdata k;
	if ((*Root)->left == NULL){
		k=(*Root)->data;
		(*Root) = (*Root)->right;
		return k;
    }
    else DeleteMin(&(*Root)->left);
}

void DeleteNode(tdata x, TTree *Root){
 if ((*Root)!=NULL)
	if(x < (*Root)->data)
		DeleteNode(x,&(*Root)->left);
	else if(x > (*Root)->data)
		DeleteNode(x,&(*Root)->right);
	else if((*Root)->left==NULL && (*Root)->right==NULL)
		(*Root)=NULL;
    else if((*Root)->left == NULL)
		(*Root) = (*Root)->right;
	else if ((*Root)->right==NULL)
		(*Root) = (*Root)->left;
    else (*Root)->data=DeleteMin(&(*Root)->right);
}

int main()
{
    TTree T,n;
    tdata x;
    makenull_tree(&T);
    //T1=create2('B',create2('D',NULL,NULL),create2('E',create2('H',NULL,NULL),NULL));
    //T2=create2('C',create2('F',NULL,create2('I',NULL,NULL)),create2('G',NULL,NULL));
    //T=create2('A',T1,T2);
    
	/*insertnode(50,&T);
    insertnode(20,&T);
    insertnode(30,&T);
    insertnode(60,&T);
    insertnode(55,&T);
    insertnode(16,&T);
    insertnode(70,&T);*/
    
    insertnode(10,&T);
    insertnode(6,&T);
    insertnode(15,&T);
    insertnode(2,&T);
    insertnode(7,&T);
    insertnode(12,&T);
    insertnode(29,&T);
    insertnode(14,&T); 
    insertnode(34,&T);
    
    printf("\nDuyet tien tu:\n");
    tientu(T);
    printf("\nDuyet trung tu:\n");
    trungtu(T);
    printf("\nDuyet hau tu:\n");
    hautu(T);
    //printf("\nNhap vao khoa can xoa:");
    //scanf("%d",&x);
    //DeleteNode(x,&T);
    //printf("\nDuyet trung tu:\n");
    //trungtu(T);
    
    printf("%d", countNode1(T));

    // printf("\nSo nut la: %d", countLeafNode(T));
    // countNode1(T);
    // sumNode1(T);
    
    /*printf("\nNhap vao khoa can tim:");
    scanf("%d",&x);
    n=search(x,T);
    if(n != NULL)
        printf("\nKhoa can tim ton tai tren cay");
    else
        printf("\nKhoa can tim khong ton tai");*/
    /*printf("\nTo tien chung gan nhat la %d",NearRoot(T,16,55));
    printf("\nTo tien la %d",totien(T,15,55));
    printf("\nTong so nut tren cay la %d",sonut(T));
    printf("\nChieu cao cua cay la %d",chieucao(T));
    printf("\nSo nut la tren cay %d",sonutla(T));*/
    return 0;
}