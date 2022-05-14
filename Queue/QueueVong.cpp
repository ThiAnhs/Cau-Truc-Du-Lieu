#include <stdio.h>

#define maxlenth 100

struct Queue{
    int data[maxlenth];
    int front, rear;
};

void khoitao(Queue *p){
    p->front = -1;
    p->rear = -1;
}

int ktRong(Queue p){
    return p.front == -1;
}

int ktDay(Queue p){
    return (p.rear - p.front + 1) % maxlenth == 0; 
}

int giatri(Queue p){
    if(!ktRong(p)){
        return p.data[p.front];
    }
}

void them(int x, Queue *p) {
    if(!ktDay(*p)){
        if(ktRong(*p))
            p->front = 0;
        // p->rear = (p->rear + 1) % maxlenth;
        p->rear ++;
        p->data[p->rear] = x;
    }
}

void xoa(Queue *p){
    if(!ktRong(*p)){
        if(p->front == p->rear){
            khoitao(p);
        }
        else
            p->front = (p->front + 1) % maxlenth;
    }
}

void read(Queue *p){
    khoitao(p);
    int n, x;
    printf("Nhap n vao: "); scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &x);
        them(x, p);
    }
}

void print(Queue p){
    while(!ktRong(p)){
        printf("%d ", giatri(p));
        xoa(&p);
    }
}

int main(){
    Queue p;
    read(&p);
    printf("Danh Sach la; ");
    print(p);
}
