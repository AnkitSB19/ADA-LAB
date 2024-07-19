#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void swap(int *p, int *i) {
    int temp = *p;
    *p = *i;
    *i = temp;
}

int Lomuto_p(int a[], int l, int r) {
    int p = a[l];
    int s = l, i;
    for(i = l + 1; i < r; i++) {
        if(a[i] < p) {
            s += 1;
            swap(&a[s], &a[i]);
        }
    }
    swap(&a[s], &a[l]);
    return s;
}

int Quick_s(int a[], int l, int r, int k) {
    int s = Lomuto_p(a, l, r);
    if(s == k)
        return a[s];
    else if(s < k)
        return Quick_s(a, s + 1, r, k);
    else
        return Quick_s(a, l, s - 1, k);
}

int main() {
    int a[MAX];
    int i, n, k;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the value of k: \n");
    scanf("%d", &k);
    int result = Quick_s(a, 0, n, k);
    printf("The %dth smallest element is: %d\n", k, result);
    return 0;
}
