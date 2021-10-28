#include <stdio.h>
#include <limits.h>

//Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...Max sum...
#define MAX 100
int a[MAX], n;

int maxLeft(int *a, int l, int r){
    int sum = 0, max = INT_MIN;
    for(int i = r; i >= l; i--){
        sum += a[i];
        if(max < sum){
            max = sum;
        }
    }
    return max;
}

int maxRight(int *a, int l, int r){
    int sum = 0, max = INT_MIN;
    for(int i = l; i <= r; i++){
        sum += a[i];
        if(max < sum){
            max = sum;
        }
    }
    return max;
}

int maxSequence(int *a, int l, int r){
    if(l == r){
        return a[l];
    }
    else{
        int max;
        int mid = (l + r) / 2;
        int mL = maxSequence(a, l, mid);
        int mR = maxSequence(a, mid + 1, r);
        int mM = maxLeft(a, l, mid) + maxRight(a, mid + 1, r);
        max = mL > mR ? (mL > mM ? mL : mM) : (mR > mM ? mR : mM);
        return max;   
    }
}

int main(){
    printf("Enter number of the elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Result: %d\n", maxSequence(a, 0, n - 1));
    return 0;
}