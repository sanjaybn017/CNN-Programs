#include<stdio.h>
#include<stdlib.h>
#define RTT 5
void main()
{
    int window_size,i,f,frames[50];
    printf("enter window size:");
    scanf("%d",&window_size);
    printf("\n enter no of frames to be transmitted\n");
    scanf("%d",&f);
    printf("\nEnter %d frames :",f);
    for (i=1;i<=f;i++)
        scanf("%d", &frames[i]);
    printf("\n After sending %d frames at each stages sender waits dor ACK",window_size);
    printf("\n Sending in the following manner\n");
    for (i=1;i<=f;i++)
    {
        if(i%window_size!=0)
            printf("%d",frames[i]);
        else
        {
            printf("%d\n",frames[i]);
            printf("sender : waiting for ACK \n");
            sleep(RTT/2);
            printf("Reciever : Frames recieved ,AcK sent\n");
            sleep(RTT/2);
            printf("sender :ACK recieved ,sending next frames \n");
        }
    }
    if(f%window_size!=0)
    {
        printf("\nsender : waiting for ACK \n");
        sleep(RTT/2);
        printf("\nReciever : Frames recieved ,AcK sent\n");
        sleep(RTT/2);
        printf("sender :ACK recieved\n");
    }
    
}