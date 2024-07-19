#include<stdio.h>
#include<stdlib.h>

int gcd(int n, int m)
{
    int r;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}

int main()
{
    int a,b;
    printf("enter the 1st number\n");
    scanf("%d",&a);
    printf("enter the 2nd number\n");
    scanf("%d",&b);
    int res=gcd(a,b);
    printf("result:\n%d ",res);
    return 0;
}
