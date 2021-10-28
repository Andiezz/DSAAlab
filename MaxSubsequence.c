#include <stdio.h>

#define MAX 100
int a[MAX], S[MAX], n,
    sel_prob, //select the subproblem to track
    start_index[MAX]; //the start point of every subproblem

int solve(){
    S[0] = 1;
    int rs = S[0];
    start_index[0] = 0;
    for(int i = 1; i < n; i++){
        S[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(a[i] > a[j]){
                if(S[j] + 1 > S[i]){
                    S[i] = S[j] + 1;
                    start_index[i] = start_index[i - 1];
                }
            }
            else start_index[i] = i;
        }
        if(S[i] > rs){
            rs = S[i];
            sel_prob = i;
        }
    }
    return rs;
}

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Max quantity: %d\n", solve());
    printf("from %dth to %dth\n", start_index[sel_prob] + 1, sel_prob + 1);
    return 0;
}