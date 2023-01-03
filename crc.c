#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[20],b[20],c[20],gp[20],temp[20],rem[20];
    int m,n;
    printf("enter the message to be transmitted:\n");
    scanf("%s",a);
    printf("enter the generator polynomial:\n");
    scanf("%s",gp);
    m = strlen(a);
    n = strlen(gp);
    strcpy(b,a);
    for(int i=0;i<n-1;i++)
        a[m+i] = '0';
    strcpy(c,a);
    for(int i=0;i<m;i++)
    {
        if(a[0] == '0')
            for(int j=0;j<n;j++)
                temp[j] = '0';
        else
            for(int j=0;j<n;j++)
                temp[j] = gp[j];

        for(int j=n-1;j>0;j--)
        {
            if(a[j] == temp[j])
                rem[j-1] = '0';
            else
                rem[j-1] = '1';
        }
        rem[n-1] = c[i+n];
        strcpy(a,rem);
    }
    strcat(b,a);
    printf("message to be transmitted is:\n%s",b);
    //recevier side
    char r[60],rem1[60];
    int ebit = 0,flag = 0;
    printf("enter the received message\n");
    scanf("%s",r);
    if(strlen(b) == strlen(r))
        for(int i=0;i<strlen(r);i++)
            if(b[i] == r[i])
                rem1[i] = '0';
            else
                rem1[i] = '1';
    else
    {
        printf("corrupted data is received\n");
        exit;
    }
    for(int i=0;i<strlen(rem1);i++)
    {
        if(rem1[i]=='0')
            flag=1;
        else
        {
            flag=0;
            ebit=i;
            break;
        }
    }
    if(flag == 1)
        printf("No error in received data: %s\n Remainder is :%s\n",r,rem1);
    else
        printf("Error in received data:%s\n Remainder is:%s\n Error is at r[%d] bit\n",r,rem1,ebit);
    return 0;
}
