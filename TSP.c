#include <stdio.h>
#include <limits.h>

//Travelling Salesman Problem...Travelling Salesman Problem...Travelling Salesman Problem...Travelling Salesman Problem...Travelling Salesman Problem...Travelling Salesman Problem...
#define MAX 6120
int c[MAX][MAX], n, 
    a[MAX], //save progress till the end
    x[MAX], //update the best path
    f_min = INT_MAX, f = 0, c_min = INT_MAX, m[MAX] = {0}; 

void relax(){ //update result
    if(f + c[a[n]][a[1]] < f_min){
        f_min = f + c[a[n]][a[1]];
        for(int i = 1; i <= n; i++){
            x[i] = a[i];
        }
    }
}

void try(int k){
    for(int v = 1; v <= n; v++){
        if(!m[v]){
            a[k] = v;
            m[v] = 1;
            f = f + c[a[k - 1]][a[k]];
            if(k == n){
                relax();
            }
            else{
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        if(c_min > c[i][j] && m[v] == 0){
                            c_min = c[i][j];
                        }
                    }
                }
                if(f_min > f + c_min * (n - k + 1)){
                    try(k + 1);
                }   
            }
            m[v] = 0;
            f = f - c[a[k - 1]][a[k]];
        }
    }
}

int main(int argc, char *argv[]){
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    FILE *input = fopen(argv[1], "r");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fscanf(input, "%d", &c[i][j]);
        }
    }
    a[1] = 1;
    m[1] = 1;
    try(2);
    printf("Route: ");
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    printf("Minimum distance: %d\n", f_min);
    fclose(input);
    return 0;
}