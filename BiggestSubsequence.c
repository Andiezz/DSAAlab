#include <stdio.h>

#define MAX 100
int F[MAX], a[MAX], ans, n,
    sel_prob, //select the best sub-problem
    start_index[MAX]; //the start of every sub-problem

void input(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter the %dth element: ", i);
        scanf("%d", &a[i]);
    }
}

void solve(){
    F[1] = a[1];
    ans = F[1];
    sel_prob = 1;
    start_index[1] = 1;
    for(int i = 2; i < n; i++){
        if(F[i - 1] > 0){
            F[i] = F[i - 1] + a[i];
            start_index[i] = start_index[i - 1];
        }
        else{
            F[i] = a[i];
            start_index[i] = i;
        }
        if(F[i] > ans){
            ans = F[i];
            sel_prob = i;
        }
    }
    printf("Biggest subsequence value: %d\n", ans);
    printf("Subsequence: ");
    for(int i = start_index[sel_prob]; i <= sel_prob; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("From %dth to %dth element\n", start_index[sel_prob], sel_prob);
}

int main(){
    input();
    solve();
    return  0;
}