#include<stdio.h>
#include<unistd.h>
int i=0,pak[100];
int receiver();
int main()
{
    int n,time;
    printf("Enter the number of packets to be transmitted \n");
    scanf("%d",&n);
    printf("Enter the data contained in packets \n");
    for(int j=0;j<n;j++)
        scanf("%d",&pak[j]);
    printf("Enter the waiting time for receiving ACK \n");
    scanf("%d",&time);
    while(i<n)
    {
        printf("Sender sent packet:%d = %d\n",i+1,pak[i]);
        printf("sender waiting for ACK and timer on\n");
        sleep(time);
        if(!receiver())
            printf("Correct ACK received and packet transmission is successfull \n\n ");
        else
        {
            printf("timeout occurred\n correct Ack not received and packet transmisssion  failed\n retransmit the packet\n\n");
            continue;
        }
        i++;    
    }
    printf("\n data transmission is completed\n");
}
int receiver()
{
    int rpak;
    printf("Enter the packet received \n");
    scanf("%d",&rpak);
    if(rpak == pak[i])
    {
        printf("packet received correctly\n");
        return 0;
    }
    else
    {
        printf("packet received id corupted\n");
        return 1;
    }
}
