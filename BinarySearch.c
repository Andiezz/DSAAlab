#include <stdio.h>

#define MAX 100
int x[MAX], n, y;

int binarySearch(int x[], int start, int finish, int y){
    if(start == finish){
        if(x[start] == y){
            return start;
        }
        else return -1;
    }
    else if(x[start] == y){
        return start;
    }
    else if(x[finish] == y){
        return finish;
    }
    else{
        int m = (start + finish) / 2;
        if(x[m] == y){
            return m;
        }
        if(x[m] < y){
            return binarySearch(x, m + 1, finish, y);
        }
        else if(x[m] > y){
            return binarySearch(x, start, m - 1, y);
        }
    }
}

int main(){
    printf("Enter the length of string: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &x[i]);
    }
    printf("Find value: ");
    scanf("%d", &y);
    if(binarySearch(x, 0, n - 1, y) == -1){
        printf("Non-existing value\n");
        return 0;
    }
    printf("The index of value: %d\n", binarySearch(x, 0, n - 1, y) + 1);
    return 0;
}