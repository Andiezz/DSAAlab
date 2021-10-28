#include <stdio.h>

//Longest Common Subsequence...Longest Common Subsequence...Longest Common Subsequence...Longest Common Subsequence...Longest Common Subsequence...
#define MAX 100
int F[MAX][MAX], a[MAX], b[MAX], m, n;
char trace[MAX][MAX];

void solution(){
    for(int i = 0; i <= m; i++) F[i][0] = 0;
    for(int j = 0; j <= n; j++) F[0][j] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j]){
                F[i][j] = F[i - 1][j - 1] + 1;
                trace[i][j] = 'D';
            }
            else{
                if(F[i - 1][j] > F[i][j - 1]){
                    F[i][j] = F[i - 1][j];
                    trace[i][j] = 'U';
                }
                else{
                    F[i][j] = F[i][j - 1];
                    trace[i][j] = 'L';
                }
            }
        }
    }
    printf("The longest common subsequence: %d\n", F[m][n]);
}

void traceSolution(){
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(trace[i][j] == 'D'){
            printf("%d", a[i]);
            i = i - 1;
            j = j - 1;
        }
        else if(trace[i][j] = 'U'){
            i = i - 1;
        }
        else{
            j = j - 1;
        }
    }
    printf("\n");
}

int main(){
    printf("Enter the length of the first array: ");
    scanf("%d", &m);
    printf("Enter the length of the second array: ");
    scanf("%d", &n);
    for(int i = 1; i <= m; i++){
        printf("Enter the %dth element: ", i);
        scanf("%d", &a[i]);
    }
    for(int j = 1; j <= n; j++){
        printf("Enter the %dth element: ", j);
        scanf("%d", &b[j]);
    }
    solution();
    traceSolution();
    return 0;
}