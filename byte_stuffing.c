#include<stdio.h>
#include<string.h>
int main()
{
    char a[30],b[60],sd,ed;
    int i=0,j=1;
    printf("Enter the frame string \n");
    scanf("%s",a);
    getchar();
    printf("Enter starting delimeter \n");
    scanf("%c",&sd);
    getchar();
    printf("Enter ending delimeter \n");
    scanf("%c",&ed);
    getchar();
    b[0]=sd;
    for(i=0;i<strlen(a);i++)
    {
        b[j]=a[i];
        j++;
        if(a[i]==sd)
        {
            b[j]=sd;
            j++;
        }
        else if(a[i]==ed)
        {
            b[j]=ed;
            j++;
        }
    }
    b[j]=ed;
    b[j+1]='\0';
    printf("After stuffing: \n %s",b);
    return 0;
}
