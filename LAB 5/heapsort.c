#include<stdlib.h>
#include<stdio.h>
#define MAX 100
void heapify(int a[], int n){
    for(int k=1;k<n;k++){
        int key=a[k];
        int c = k;
        int p = (c-1)/2;
        while(c>0 && key>a[p]){
            a[c]=a[p];
            c=p;
            p=(c-1)/2;
        }
        a[c]=key;
    }
}

int main(){
    int arr[MAX],n;
    printf("Enter the size of the binary tree \n");
    scanf("%d",&n);
    printf("Enter the elements of the binary tree \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapify(arr,n);
    printf("Heap sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d->",arr[i]);
    }
    printf("END");
    return 0;

}
