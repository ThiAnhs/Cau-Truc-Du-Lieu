#include <stdio.h>
#include <string.h>

#define SoPhanTu 100

typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
}NganXep;

void khoitao(NganXep *pS){
    pS->Dinh = SoPhanTu;
}

int ktRong(NganXep S){
    return S.Dinh == SoPhanTu;
}

int ktDay(NganXep S){
    return S.Dinh ==0;
    
}

int giatriDinh(NganXep S){
    if(!ktRong(S))
        return S.DuLieu[S.Dinh];
    else printf("Loi");
    
}

void xoaDinh(NganXep *pS){
    if (!ktRong(*pS))
        pS->Dinh++;
    else printf("Loi");
}

void them(char X, NganXep *pS){
    if(!ktDay(*pS)){
        pS->Dinh--;
        pS->DuLieu[pS->Dinh] = X;
    }
}

void read(NganXep *ps){
    khoitao(ps);
    int n;
    int x;
    printf("Nhap n: "); scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &x);
        them(x, ps);
    }
}

void hienthi(NganXep *pS){
    while(!ktRong(*pS)){
        printf("%d ",giatriDinh(*pS));
        xoaDinh(pS);
    }
    printf("\n");
}

void ktngoac(char st[]){
    int count = 0;
    int count2 = 0;

    for(int i = 0; i < strlen(st); i ++){
        if(st[i] == '('){
            count ++;
        }

        if(st[i] == ')'){
            count2 ++;    
        }     
    }

    if(count == count2){
        printf("Hop Le"); 
    }
    else {
        printf("Du dau ngoac!");
    
    }  
}

int main(){
    NganXep pS;
    // read(&pS);
    // hienthi(&pS);
    char st[] = "((a+b))";
    ktngoac(st);

}



