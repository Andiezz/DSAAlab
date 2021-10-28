#include <stdio.h>
#include <stdbool.h>

#define N 100

typedef struct Greedy{
    int head, tail;
} edge;

edge a[N], res[N] = {0};
int n, count = 0, marked[N] = {0};

bool feasible(edge t){
    for(int i = 0; i < n; i++){
        if(t.head > res[i].tail || t.tail < res[i].head){
            return true;
        }
        return false;
    }
}

bool is_Empty(){
    for(int i = 0; i < n; i++){
        if(marked[i] == 0){
            return false;
        }
        return true;
    }
}

void Greedy3(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i].tail > a[j].tail){
                edge tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    while(is_Empty() == false){
        for(int i = 0; i < n; i++){
            marked[i] = true;
            if(feasible(a[i])){
                res[count] = a[i];
                count++;
            }
        }
    }
}

int main(){
    printf("Enter number of egdes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the %dth edge: \n", i + 1);
        printf("Head: ");
        scanf("%d", &a[i].head);
        printf("Tail: ");
        scanf("%d", &a[i].tail);
    }
    Greedy3();
    printf("Result: ");
    for(int i = 0; i < count; i++){
        printf("(%d, %d)  ", res[i].head, res[i].tail);
    }
    printf("\n");
    return 0;
}