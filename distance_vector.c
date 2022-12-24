#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b;
int main()
{
    int i,j,k;
    int a[10][10],n;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the cost matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(k=1;k<=n;k++)
        for(j=1;j<=n;j++)
            for(i=1;i<=n;i++)
                a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
    printf("updated cost matrix is \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}