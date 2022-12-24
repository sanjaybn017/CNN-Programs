#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int i=1,j=1,noframes=10,x,x1;
    printf("Number of frames to be sent is %d",noframes);
    while(noframes>0)
    {
        printf("Sending frame %d",i);
        x = rand()%10;
        if(x%10==0)
        {
            for(x1=1;x1<2;x1++)
            {
                printf("\n waiting for %d seconds\n",x1);
                sleep(x1);
            }
            printf("\n resending frame %d \n",i);
            x= rand()%10;
        }
        printf("\n Acknowledge for frame %d \n",j);
        noframes=noframes-1;
        i++;
        j++;
    }
    printf("\n End of stop and wait protocol");
}